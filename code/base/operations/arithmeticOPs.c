//ADD R, All flags affected.
inline void ADD_R(CPUState * state, ui8 * R){
    ui16 result = (0 << 8) | state->A;
    result += *R;

    //AUX CARRY
    ui8 AC = CalculateAuxiliaryCarryFlag(state->A, *R);
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

inline void ADD_M(){}

inline void ADI_W(CPUState * state, byte * opcode){
    ui16 result = (0 << 8) | state->A;
    result += opcode[1];

    ui8 AC = CalculateAuxiliaryCarryFlag(state->A, opcode[1]);
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

//ADC R, all flags affected
inline void ADC_R(CPUState * state, ui8 * R, ui8 carry){
    ui16 result = (0<<8) | state->A;
    ui16 add = (0<<8) | *R;
    add += carry;
    result += add;

    ui8 AC = CalculateAuxiliaryCarryFlag(state->A, add);
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

inline void ADC_M(){}

//TODO(fran): reuse functions to avoid duplicated code.
//not urgent tho.
inline void ACI_W(CPUState * state, byte * opcode, ui8 carry){
    ui16 result = (0<<8) | state->A;
    ui16 add = (0<<8) | opcode[1];
    add += carry;
    result += add;

    ui8 AC = CalculateAuxiliaryCarryFlag(state->A, add);
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

    //AUX CARRY: to calculate this, we must take into account
    //how binary substraction works.
    // substrahend CA2 = CA1 of substrahend + 1
    // this is equal to ~substrahend + 1
    ui8 subs = ~*R + 0x01;
    ui8 AC = CalculateAuxiliaryCarryFlag(state->A, subs);
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

inline void SUB_M(){}

inline void SUI_W(){}

inline void SBB_R(){}

inline void SBB_M(){}

inline void SBI_W(){}

// INR R
inline void INR_R(CPUState * state, ui8 * R){
    ui16 result = (0 << 8) | *R;
    ++result;
    
    //aux carry flag // adjust/borrow flag
    ui8 AC = CalculateAuxiliaryCarryFlag(*R, 0x01);
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

inline void INR_M(){}

inline void DCR_R(){}

inline void DCR_M(){}

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

inline void DCX_RP(){}

inline void DCX_SP(){}

inline void DAD_RP(){}

inline void DAA(){}



