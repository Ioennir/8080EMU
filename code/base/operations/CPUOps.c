
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

// INR R, Z,S,P,AC flags affected. (Zero, Sign, PAIR, AuxCarry)
inline void INR_R(CPUState * state, ui8 * R){
    ui16 result = (0 << 8) | *R;
    ++result;
    //aux carry flag
    //state->FLAGS |= (state->FLAGS | f_auxcarry) & ((result >> 8) & 1);
    //state->FLAGS |= (state->FLAGS | f_auxcarry) & ();
    //zero flag
    //state->FLAGS |= (state->FLAGS | f_zero) & ();
    //sign flag
    //state->FLAGS |= (state->FLAGS | f_sign) & ();
    //parity flag
    //state->FLAGS |= (state->FLAGS | f_parity) & ();

    state->A = (ui8)result;
}

//ADD R, All flags affected.
inline void ADD_R(CPUState * state, ui8 * R){

}