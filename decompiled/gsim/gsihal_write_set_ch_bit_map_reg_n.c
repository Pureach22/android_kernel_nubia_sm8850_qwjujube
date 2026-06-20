void __fastcall gsihal_write_set_ch_bit_map_reg_n(unsigned int a1, int a2, unsigned int a3)
{
  gsihal_write_reg_nk(a1, a2, a3 >> 5, 1 << a3);
}
