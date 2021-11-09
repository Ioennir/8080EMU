
//test this
inline void LXI(ui8 * LR, ui8 * HR, byte * opcode, ui8 * pc){
    *LR = opcode[1];
    *HR = opcode[2];
    *pc += 2;
}