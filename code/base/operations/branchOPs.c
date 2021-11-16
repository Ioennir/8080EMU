//JMP ADDR
inline void JMP_ADDR(ui16 * pc, byte *opcode){
    *pc = (opcode[2] << 8) | opcode[1];
}

inline void JCONDITION_ADDR(){}

inline void CALL_ADDR(){}

inline void CCONDITION_ADDR(){}

inline void RET(){}

inline void RST_N(){}

inline void PCHL(){}