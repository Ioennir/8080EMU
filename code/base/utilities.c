ui8 parity(ui8 num, ui8 size){
    ui8 ones = 0;
    for (int i = 0; i < size; i++)
    {
        ones += ((num >> i) & 1);
    }
    return !((ones & 0x01) & 0x01);
}

ui8 CalculateAuxiliaryCarryFlag(ui8 num, ui8 addition){
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