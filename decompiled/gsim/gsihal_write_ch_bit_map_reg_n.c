void __fastcall gsihal_write_ch_bit_map_reg_n(unsigned int a1, int a2, unsigned int a3, unsigned int a4)
{
  gsihal_write_reg_nk(a1, a2, a3 >> 5, a4);
}
