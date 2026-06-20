__int64 __fastcall gsi_get_chan_stop_stm(unsigned int a1, __int64 a2)
{
  return ((unsigned int)gsihal_read_reg_nk(60, a2, a1) >> 24) & 0xF0;
}
