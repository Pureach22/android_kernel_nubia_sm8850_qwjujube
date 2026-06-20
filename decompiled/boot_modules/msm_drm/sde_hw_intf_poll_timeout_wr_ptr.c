__int64 __fastcall sde_hw_intf_poll_timeout_wr_ptr(__int64 a1, int a2)
{
  int v4; // w21

  if ( !a1 )
    return 4294967274LL;
  if ( (*(_QWORD *)(*(_QWORD *)(a1 + 40) + 32LL) & 0x10LL) != 0 )
    v4 = -1;
  else
    v4 = 0xFFFF;
  ktime_get(a1);
  if ( a2 )
    usleep_range_state(3, 10, 2);
  while ( ((unsigned int)sde_reg_read(a1, 688) & v4) == 0 )
  {
    usleep_range_state(3, 10, 2);
    __yield();
  }
  return 0;
}
