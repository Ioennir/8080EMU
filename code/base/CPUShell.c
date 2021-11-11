#include <stdio.h>
#include <stdlib.h>
#include "typeConfig.h"
#include "./operations/CPUOps.c"
//todo(fran): import the dissasembler differently from the Extra folder.
#include "dissasembleOp.c"

inline void NotImplemented(CPUState * state)
{
    --state->PC;
    printf("Instruction not implemented yet.\n");
    exit(1);
}

// Todo(fran): print it properly
inline void PRINTCPUSTATE(CPUState * state){
    printf("A $%02x FLAGS $%02x B $%02x C $%02x D $%02x E $%02x H $%02x L $%02x SP %04x PC %04x\n", 
            state->A, state->FLAGS, state->B, state->C, state->C, state->E, state->H, state->L, state->SP, state->PC);
}

// https://pastraiser.com/cpu/i8080/i8080_opcodes.html OPCODE Table

int Run8080cpuOperations(CPUState * state){
    byte * opcode = &state->MEMORY[state->PC];
    DisassembleCPUOperations(state->MEMORY, state->PC);
    ++state->PC;
    switch(*opcode){
        case 0x00: break; //NOP (NO OPERATION) 
        case 0x01: LXI_REG_DW(state, &state->B, &state->C, opcode);break; // LXI B,DW
        case 0x02: NotImplemented(state); break; // STAX B
        case 0x03: NotImplemented(state); break; 
        case 0x04: NotImplemented(state); break; 
        case 0x05: NotImplemented(state); break; 
        case 0x06: MVI_REG_DW(state, &state->B, opcode); break; 
        case 0x07: NotImplemented(state); break; 
        case 0x08: NotImplemented(state); break; 
        case 0x09: NotImplemented(state); break; 
        case 0x0A: NotImplemented(state); break; 
        case 0x0B: NotImplemented(state); break; 
        case 0x0C: NotImplemented(state); break; 
        case 0x0D: NotImplemented(state); break; 
        case 0x0E: MVI_REG_DW(state, &state->C, opcode); break; 
        case 0x0F: NotImplemented(state); break; 
        case 0x10: NotImplemented(state); break; 
        case 0x11: LXI_REG_DW(state, &state->D, &state->E, opcode); break; 
        case 0x12: NotImplemented(state); break; 
        case 0x13: NotImplemented(state); break;
        case 0x14: NotImplemented(state); break;
        case 0x15: NotImplemented(state); break;
        case 0x16: MVI_REG_DW(state, &state->D, opcode); break;
        case 0x17: NotImplemented(state); break;
        case 0x18: NotImplemented(state); break;
        case 0x19: NotImplemented(state); break;
        case 0x1A: NotImplemented(state); break;
        case 0x1B: NotImplemented(state); break;
        case 0x1C: NotImplemented(state); break;
        case 0x1D: NotImplemented(state); break;
        case 0x1E: MVI_REG_DW(state, &state->E, opcode); break;
        case 0x1F: NotImplemented(state); break;
        case 0x20: NotImplemented(state); break; 
        case 0x21: LXI_REG_DW(state, &state->H, &state->L, opcode); break; 
        case 0x22: NotImplemented(state); break; 
        case 0x23: NotImplemented(state); break;
        case 0x24: NotImplemented(state); break;
        case 0x25: NotImplemented(state); break;
        case 0x26: MVI_REG_DW(state, &state->H, opcode); break;
        case 0x27: NotImplemented(state); break;
        case 0x28: NotImplemented(state); break;
        case 0x29: NotImplemented(state); break;
        case 0x2A: NotImplemented(state); break;
        case 0x2B: NotImplemented(state); break;
        case 0x2C: NotImplemented(state); break;
        case 0x2D: NotImplemented(state); break;
        case 0x2E: MVI_REG_DW(state, &state->L, opcode); break;
        case 0x2F: NotImplemented(state); break;
        case 0x30: NotImplemented(state); break; 
        case 0x31: LXI_SP_DW(state, opcode); break; 
        case 0x32: NotImplemented(state); break; 
        case 0x33: NotImplemented(state); break;
        case 0x34: NotImplemented(state); break;
        case 0x35: NotImplemented(state); break;
        case 0x36: NotImplemented(state); break;
        case 0x37: NotImplemented(state); break;
        case 0x38: NotImplemented(state); break;
        case 0x39: NotImplemented(state); break;
        case 0x3A: NotImplemented(state); break;
        case 0x3B: NotImplemented(state); break;
        case 0x3C: NotImplemented(state); break;
        case 0x3D: NotImplemented(state); break;
        case 0x3E: MVI_REG_DW(state, &state->A, opcode); break;
        case 0x3F: NotImplemented(state); break;
        case 0x40: MOV_REG_REG(&state->B , &state->B); break; 
        case 0x41: MOV_REG_REG(&state->B , &state->C); break; 
        case 0x42: MOV_REG_REG(&state->B , &state->D); break; 
        case 0x43: MOV_REG_REG(&state->B , &state->E); break;
        case 0x44: MOV_REG_REG(&state->B , &state->H); break;
        case 0x45: MOV_REG_REG(&state->B , &state->L); break;
        case 0x46: NotImplemented(state); break;
        case 0x47: MOV_REG_REG(&state->B , &state->A); break;
        case 0x48: MOV_REG_REG(&state->C , &state->B); break;
        case 0x49: MOV_REG_REG(&state->C , &state->C); break;
        case 0x4A: MOV_REG_REG(&state->C , &state->D); break;
        case 0x4B: MOV_REG_REG(&state->C , &state->E); break;
        case 0x4C: MOV_REG_REG(&state->C , &state->H); break;
        case 0x4D: MOV_REG_REG(&state->C , &state->L); break;
        case 0x4E: NotImplemented(state); break;
        case 0x4F: MOV_REG_REG(&state->C , &state->A); break;
        case 0x50: MOV_REG_REG(&state->D , &state->B); break;
        case 0x51: MOV_REG_REG(&state->D , &state->C); break;
        case 0x52: MOV_REG_REG(&state->D , &state->D); break;
        case 0x53: MOV_REG_REG(&state->D , &state->E); break;
        case 0x54: MOV_REG_REG(&state->D , &state->H); break;
        case 0x55: MOV_REG_REG(&state->D , &state->L); break;
        case 0x56: NotImplemented(state); break;
        case 0x57: MOV_REG_REG(&state->D , &state->A); break;
        case 0x58: MOV_REG_REG(&state->E , &state->B); break;
        case 0x59: MOV_REG_REG(&state->E , &state->C); break;
        case 0x5A: MOV_REG_REG(&state->E , &state->D); break;
        case 0x5B: MOV_REG_REG(&state->E , &state->E); break;
        case 0x5C: MOV_REG_REG(&state->E , &state->H); break;
        case 0x5D: MOV_REG_REG(&state->E , &state->L); break;
        case 0x5E: NotImplemented(state); break;
        case 0x5F: MOV_REG_REG(&state->E , &state->A); break;
        case 0x60: MOV_REG_REG(&state->H , &state->B); break;
        case 0x61: MOV_REG_REG(&state->H , &state->C); break;
        case 0x62: MOV_REG_REG(&state->H , &state->D); break;
        case 0x63: MOV_REG_REG(&state->H , &state->E); break;
        case 0x64: MOV_REG_REG(&state->H , &state->H); break;
        case 0x65: MOV_REG_REG(&state->H , &state->L); break;
        case 0x66: NotImplemented(state); break;
        case 0x67: MOV_REG_REG(&state->H , &state->A); break;
        case 0x68: MOV_REG_REG(&state->L , &state->B); break;
        case 0x69: MOV_REG_REG(&state->L , &state->C); break;
        case 0x6A: MOV_REG_REG(&state->L , &state->D); break;
        case 0x6B: MOV_REG_REG(&state->L , &state->E); break;
        case 0x6C: MOV_REG_REG(&state->L , &state->H); break;
        case 0x6D: MOV_REG_REG(&state->L , &state->L); break;
        case 0x6E: NotImplemented(state); break;
        case 0x6F: MOV_REG_REG(&state->L , &state->A); break;
        case 0x70: NotImplemented(state); break; 
        case 0x71: NotImplemented(state); break; 
        case 0x72: NotImplemented(state); break; 
        case 0x73: NotImplemented(state); break;
        case 0x74: NotImplemented(state); break;
        case 0x75: NotImplemented(state); break;
        case 0x76: NotImplemented(state); break;
        case 0x77: NotImplemented(state); break;
        case 0x78: MOV_REG_REG(&state->A , &state->B); break;
        case 0x79: MOV_REG_REG(&state->A , &state->C); break;
        case 0x7A: MOV_REG_REG(&state->A , &state->D); break;
        case 0x7B: MOV_REG_REG(&state->A , &state->E); break;
        case 0x7C: MOV_REG_REG(&state->A , &state->H); break;
        case 0x7D: MOV_REG_REG(&state->A , &state->L); break;
        case 0x7E: NotImplemented(state); break;
        case 0x7F: MOV_REG_REG(&state->A , &state->A); break;
        case 0x80: NotImplemented(state); break; 
        case 0x81: NotImplemented(state); break; 
        case 0x82: NotImplemented(state); break; 
        case 0x83: NotImplemented(state); break;
        case 0x84: NotImplemented(state); break;
        case 0x85: NotImplemented(state); break;
        case 0x86: NotImplemented(state); break;
        case 0x87: NotImplemented(state); break;
        case 0x88: NotImplemented(state); break;
        case 0x89: NotImplemented(state); break;
        case 0x8A: NotImplemented(state); break;
        case 0x8B: NotImplemented(state); break;
        case 0x8C: NotImplemented(state); break;
        case 0x8D: NotImplemented(state); break;
        case 0x8E: NotImplemented(state); break;
        case 0x8F: NotImplemented(state); break;
        case 0x90: NotImplemented(state); break; 
        case 0x91: NotImplemented(state); break; 
        case 0x92: NotImplemented(state); break; 
        case 0x93: NotImplemented(state); break;
        case 0x94: NotImplemented(state); break;
        case 0x95: NotImplemented(state); break;
        case 0x96: NotImplemented(state); break;
        case 0x97: NotImplemented(state); break;
        case 0x98: NotImplemented(state); break;
        case 0x99: NotImplemented(state); break;
        case 0x9A: NotImplemented(state); break;
        case 0x9B: NotImplemented(state); break;
        case 0x9C: NotImplemented(state); break;
        case 0x9D: NotImplemented(state); break;
        case 0x9E: NotImplemented(state); break;
        case 0x9F: NotImplemented(state); break;
        case 0xA0: NotImplemented(state); break; 
        case 0xA1: NotImplemented(state); break; 
        case 0xA2: NotImplemented(state); break; 
        case 0xA3: NotImplemented(state); break;
        case 0xA4: NotImplemented(state); break;
        case 0xA5: NotImplemented(state); break;
        case 0xA6: NotImplemented(state); break;
        case 0xA7: NotImplemented(state); break;
        case 0xA8: NotImplemented(state); break;
        case 0xA9: NotImplemented(state); break;
        case 0xAA: NotImplemented(state); break;
        case 0xAB: NotImplemented(state); break;
        case 0xAC: NotImplemented(state); break;
        case 0xAD: NotImplemented(state); break;
        case 0xAE: NotImplemented(state); break;
        case 0xAF: NotImplemented(state); break;
        case 0xB0: NotImplemented(state); break; 
        case 0xB1: NotImplemented(state); break; 
        case 0xB2: NotImplemented(state); break; 
        case 0xB3: NotImplemented(state); break;
        case 0xB4: NotImplemented(state); break;
        case 0xB5: NotImplemented(state); break;
        case 0xB6: NotImplemented(state); break;
        case 0xB7: NotImplemented(state); break;
        case 0xB8: NotImplemented(state); break;
        case 0xB9: NotImplemented(state); break;
        case 0xBA: NotImplemented(state); break;
        case 0xBB: NotImplemented(state); break;
        case 0xBC: NotImplemented(state); break;
        case 0xBD: NotImplemented(state); break;
        case 0xBE: NotImplemented(state); break;
        case 0xBF: NotImplemented(state); break;
        case 0xC0: NotImplemented(state); break; 
        case 0xC1: NotImplemented(state); break; 
        case 0xC2: NotImplemented(state); break; 
        case 0xC3: JMP_ADDR(&state->PC, opcode); break; //JMP DW
        case 0xC4: NotImplemented(state); break;
        case 0xC5: NotImplemented(state); break;
        case 0xC6: NotImplemented(state); break;
        case 0xC7: NotImplemented(state); break;
        case 0xC8: NotImplemented(state); break;
        case 0xC9: NotImplemented(state); break;
        case 0xCA: NotImplemented(state); break;
        case 0xCB: NotImplemented(state); break;
        case 0xCC: NotImplemented(state); break;
        case 0xCD: NotImplemented(state); break;
        case 0xCE: NotImplemented(state); break;
        case 0xCF: NotImplemented(state); break;
        case 0xD0: NotImplemented(state); break; 
        case 0xD1: NotImplemented(state); break; 
        case 0xD2: NotImplemented(state); break; 
        case 0xD3: NotImplemented(state); break;
        case 0xD4: NotImplemented(state); break;
        case 0xD5: NotImplemented(state); break;
        case 0xD6: NotImplemented(state); break;
        case 0xD7: NotImplemented(state); break;
        case 0xD8: NotImplemented(state); break;
        case 0xD9: NotImplemented(state); break;
        case 0xDA: NotImplemented(state); break;
        case 0xDB: NotImplemented(state); break;
        case 0xDC: NotImplemented(state); break;
        case 0xDD: NotImplemented(state); break;
        case 0xDE: NotImplemented(state); break;
        case 0xDF: NotImplemented(state); break;
        case 0xE0: NotImplemented(state); break; 
        case 0xE1: NotImplemented(state); break; 
        case 0xE2: NotImplemented(state); break; 
        case 0xE3: NotImplemented(state); break;
        case 0xE4: NotImplemented(state); break;
        case 0xE5: NotImplemented(state); break;
        case 0xE6: NotImplemented(state); break;
        case 0xE7: NotImplemented(state); break;
        case 0xE8: NotImplemented(state); break;
        case 0xE9: NotImplemented(state); break;
        case 0xEA: NotImplemented(state); break;
        case 0xEB: NotImplemented(state); break;
        case 0xEC: NotImplemented(state); break;
        case 0xED: NotImplemented(state); break;
        case 0xEE: NotImplemented(state); break;
        case 0xEF: NotImplemented(state); break;
        case 0xF0: NotImplemented(state); break; 
        case 0xF1: NotImplemented(state); break; 
        case 0xF2: NotImplemented(state); break; 
        case 0xF3: NotImplemented(state); break;
        case 0xF4: NotImplemented(state); break;
        case 0xF5: NotImplemented(state); break;
        case 0xF6: NotImplemented(state); break;
        case 0xF7: NotImplemented(state); break;
        case 0xF8: NotImplemented(state); break;
        case 0xF9: NotImplemented(state); break;
        case 0xFA: NotImplemented(state); break;
        case 0xFB: NotImplemented(state); break;
        case 0xFC: NotImplemented(state); break;
        case 0xFD: NotImplemented(state); break;
        case 0xFE: NotImplemented(state); break;
        case 0xFF: NotImplemented(state); break; 
    }
    PRINTCPUSTATE(state);
    return 0;
}



// NOTE(Fran): it is messy for now, i'm testing things
int main(int argc, char **argv){
    FILE * f = fopen(argv[1], "rb");
    if(!f){
        printf("Error: couldn't open %s.", argv[1]);
        exit(1);
    }
    CPUState * state = malloc(sizeof(CPUState));
    state->PC = 0;
    //64KB ->  0x10000 B , 16KB -> 0x4000 B
    state->MEMORY = malloc(0x4000);

    fseek(f, 0L, SEEK_END);
    int size = ftell(f);
    fseek(f, 0L, SEEK_SET);
    fread(state->MEMORY, size, 1, f);
    fclose(f);

    while(1){
        Run8080cpuOperations(state);
    }
    return 0;


}