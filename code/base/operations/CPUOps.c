
//LXI REG DWORD(8bit x 2)
inline void LXI_REG_DW(CPUState * state, ui8 * RH, ui8 * RL, byte * opcode){
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
inline void MVI_REG_DW(CPUState * state, ui8 * R, byte * opcode){
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