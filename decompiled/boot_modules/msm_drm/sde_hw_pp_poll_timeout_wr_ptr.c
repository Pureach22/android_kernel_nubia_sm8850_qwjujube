__int64 __fastcall sde_hw_pp_poll_timeout_wr_ptr(__int64 a1, int a2)
{
  if ( !a1 )
    return 4294967274LL;
  ktime_get(a1);
  if ( a2 )
    usleep_range_state(3, 10, 2);
  while ( !(unsigned __int16)sde_reg_read(a1, 0x2Cu) )
  {
    usleep_range_state(3, 10, 2);
    __yield();
  }
  return 0;
}
