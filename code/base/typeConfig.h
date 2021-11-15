#include <stdint.h>

#define ui8 uint8_t
#define ui16 uint16_t
#define byte uint8_t

#define Kilobytes(Value) ((Value)*1024LL)
#define Swap(A, B) \
{   A += B; \
    B = A - B;\
    A -= B; }

/*
    Flags position within the register
    A REG (8BITS) | FLAGS (8 BITS)
    ............. | x x x S Z A P C

    FLAGS WORK THIS WAY UNLESS INSTRUCTION SPECIFIES DIFFERENTLY
    
    zero:
    If the result of an instruction has the value 0, this flag is set; 
    otherwise it is reset.
    
    sign:
    If the most significant bit of the result of the operation has the value 1,
    this flag is set; otherwise it is reset.
    
    parity:
    If the modulo 2 sum of the bits of the result of the operation is 0, 
    (Le., if the result has even parity), this flag is set; otherwise 
    it is reset (Le., if the result has odd parity).
    
    carry:
    If the instruction resulted in a carry (from addition), or a borrow 
    (from subtraction or a comparison) out of the highorder bit, 
    this flag is set; otherwise it is reset.
    
    auxiliary carry:
    If the instruction caused a carry out of bit 3 and into bit 4 of the resulting
    value, the auxiliary carry is set; otherwise it is reset. This flag is affected
    by single precision additions, subtractions, increments, decrements, comparisons,
    and logical operations, but is principally used with additions and increments 
    preceding a DAA (Decimal Adjust Accumulator) instruction.

*/

#define sign_bit 7

#define v_sf 4
#define v_zf 3
#define v_af 2
#define v_pf 1
#define v_cf 0

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
    ui8 * MEMORY;           // 16K or 64K
    ui8 int_enable;

} CPUState;