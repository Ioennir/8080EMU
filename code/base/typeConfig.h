#include <stdint.h>

#define ui8 uint8_t
#define ui16 uint16_t
#define byte uint8_t

/*
    Flags position within the register
    A REG (8BITS) | FLAGS (8 BITS)
    ............. | x x x S Z A P C

*/

#define f_sign          1<<4
#define f_zero          1<<3
#define f_auxcarry      1<<2
#define f_parity        1<<1
#define f_carry         1<<0

/*
General registers
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|       A       |     Flags     |  S Z A P C
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|       B       |       C       | BC
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|       D       |       E       | DE
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|       H       |       L       | HL
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

Stack Pointer & Program Counter
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|               SP              |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|               PC              |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

*/

typedef struct CPUState {
    ui8 A;
    ui8 FLAGS;
    ui8 B;
    ui8 C;
    ui8 D;
    ui8 E;
    ui8 H;
    ui8 L;
    ui16 SP;
    ui16 PC;
    ui8 * MEMORY;
    ui8 int_enable;

} CPUState;