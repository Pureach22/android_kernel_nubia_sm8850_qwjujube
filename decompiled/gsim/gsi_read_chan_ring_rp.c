__int64 __fastcall gsi_read_chan_ring_rp(unsigned int a1, __int64 a2)
{
  unsigned int v3; // w19
  __int64 reg_nk; // x21

  v3 = a2;
  reg_nk = (unsigned int)gsihal_read_reg_nk(66, a2, a1);
  return reg_nk | (gsihal_read_reg_nk(67, v3, a1) << 32);
}
