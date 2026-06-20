__int64 __fastcall gsihal_read_ch_reg(unsigned int a1, unsigned int a2)
{
  return gsihal_read_reg_nk(a1, a2 >> 5, 0);
}
