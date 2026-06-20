__int64 __fastcall gsi_read_chan_ring_re_fetch_wp(unsigned int a1, __int64 a2)
{
  return (unsigned int)gsihal_read_reg_nk(121, a2, a1);
}
