
//LXI REG DWORD(8bit x 2)
inline void LXI_RP_DW(CPUState * state, ui8 * RH, ui8 * RL, byte * opcode){
    *RH = opcode[2];
    *RL = opcode[1];
    state->PC += 2; //NOTE(fran): only advance 2 bc it has already advanced 1
}

//LXI SP DWORD
inline void LXI_SP_DW(CPUState * state, byte * opcode){
    state->SP = (opcode[2] << 8) | opcode[1];
    state->PC += 2;
}

//MVI REG WORD(8bit)
inline void MVI_R_DW(CPUState * state, ui8 * R, byte * opcode){
    *R = opcode[1];
    ++state->PC;
}

//MOV REG <- REG
inline void MOV_REG_REG(ui8 * Rto, ui8 * Rfrom){
    *Rto = *Rfrom;
}

//JMP ADDR
inline void JMP_ADDR(ui16 * pc, byte *opcode){
    *pc = (opcode[2] << 8) | opcode[1];
}

//NOTE(fran): test this to know if it is okay, I think it is, but im unsure.
//INX REGISTER PAIR 
inline void INX_RP(ui8 * RH, ui8 * RL){
    ui16 val = (*RH << 8) | *RL;
    ++val;
    *RH = (ui8)(val >> 8);
    *RL = (ui8)val;
}

//INX SP
inline void INX_SP(ui16 * SP){
    ++*SP;
}

//XCHG exchange HL with DE
inline void XCHG(CPUState * state){
    Swap(state->H, state->D);
    Swap(state->L, state->E);
}

ui8 parity(ui8 num, ui8 size){
    ui8 ones = 0;
    for (int i = 0; i < size; i++)
    {
        ones += ((num >> i) & 1);
    }
    return !((ones & 0x01) & 0x01);
}

//TODO(fran): Check this out
ui8 CalculateAuxiliaryCarryFlagSubstraction(ui8 num, ui8 substract){
    return (f_auxcarry & (((num & 0xF0) - (substract & 0xF0)) > 0x0F) << v_af);
}

ui8 CalculateAuxiliaryCarryFlagAddition(ui8 num, ui8 addition){
    return (f_auxcarry & (((num & 0x0F) + (addition & 0x0F)) > 0x0F) << v_af);
}

ui8 CalculateZeroFlag(ui16 res){
    return (f_zero & (res == 0) << v_zf);
}

ui8 CalculateSignFlag(ui16 res){
    return (f_sign & (res >> (sign_bit - v_sf)));
}

ui8 CalculateParityFlag(ui16 res){
    return (f_parity & (parity(res, 8) << v_pf));
}

ui8 CalculateCarryFlag(ui16 res){
    return (f_carry & (((res >> 8) & 0x01) << v_cf));
}

// INR R, Z,S,P,AC flags affected. (Zero, Sign, PAIR, AuxCarry)
inline void INR_R(CPUState * state, ui8 * R){
    ui16 result = (0 << 8) | *R;
    ++result;
    
    //aux carry flag // adjust/borrow flag
    ui8 AC = CalculateAuxiliaryCarryFlagAddition(*R, 0x01);
    //zero flag
    ui8 Z = CalculateZeroFlag(result); 
    //sign flag
    ui8 S = CalculateSignFlag(result);
    //parity flag
    ui8 P = CalculateParityFlag(result);
    
    // load carry flag from state (this flag isn't affected by this operation)
    ui8 C = state->FLAGS & f_carry;

    ui8 flags = AC | Z | S | P | C;
    state->FLAGS = flags;

    *R = (ui8)result;
}

//ADD R, All flags affected.
inline void ADD_R(CPUState * state, ui8 * R){
    ui16 result = (0 << 8) | state->A;
    result += *R;

    //AUX CARRY
    ui8 AC = CalculateAuxiliaryCarryFlagAddition(state->A, *R);
    //ZERO
    ui8 Z = CalculateZeroFlag(result); 
    //SIGN
    ui8 S = CalculateSignFlag(result);
    //PARITY
    ui8 P = CalculateParityFlag(result);
    //CARRY
    ui8 C = CalculateCarryFlag(result);
    //COMPUTE FLAGS
    ui8 flags = AC | Z | S | P | C;
    state->FLAGS = flags;

    state->A = (ui8)result;
}

//SUB R, all flags affected.
inline void SUB_R(CPUState * state, ui8 * R){
    ui16 result = (0 << 8) | state->A;
    result -= *R;

    //AUX CARRY
    ui8 AC = CalculateAuxiliaryCarryFlagSubstraction(state->A, *R);
    //ZERO
    ui8 Z = CalculateZeroFlag(result); 
    //SIGN
    ui8 S = CalculateSignFlag(result);
    //PARITY
    ui8 P = CalculateParityFlag(result);
    //CARRY
    ui8 C = CalculateCarryFlag(result);
    //COMPUTE FLAGS
    ui8 flags = AC | Z | S | P | C;
    state->FLAGS = flags;

    state->A = (ui8)result;
}