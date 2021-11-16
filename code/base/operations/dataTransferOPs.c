//MOV REG <- REG
inline void MOV_R_R(ui8 * Rto, ui8 * Rfrom){
    *Rto = *Rfrom;
}

inline void MOV_R_M(){}

inline void MOV_M_R(){}

//MVI REG WORD(8bit)
inline void MVI_R_W(CPUState * state, ui8 * R, byte * opcode){
    *R = opcode[1];
    ++state->PC;
}

inline void MVI_M_W(){}

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

inline void LDA_ADDR(){}

inline void STA_ADDR(){}

inline void LHLD_ADDR(){}

inline void SHLD_ADDR(){}

inline void LDAX_RP(){}

inline void STAX_RP(){}

//XCHG exchange HL with DE
inline void XCHG(CPUState * state){
    Swap(state->H, state->D);
    Swap(state->L, state->E);
}