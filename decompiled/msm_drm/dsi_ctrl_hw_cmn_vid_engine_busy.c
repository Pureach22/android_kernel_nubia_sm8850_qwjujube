__int64 __fastcall dsi_ctrl_hw_cmn_vid_engine_busy(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  __int64 v4; // x20

  v2 = ktime_get(a1);
  v3 = readl_13((unsigned int *)(*(_QWORD *)a1 + 8LL));
  if ( (v3 & 8) == 0 )
    return 0;
  v4 = v2 + 50000000;
  while ( ktime_get(v3) <= v4 )
  {
    usleep_range_state(251, 1000, 2);
    __yield();
    v3 = readl_13((unsigned int *)(*(_QWORD *)a1 + 8LL));
    if ( (v3 & 8) == 0 )
      return 0;
  }
  return ((unsigned int)readl_13((unsigned int *)(*(_QWORD *)a1 + 8LL)) >> 3) & 1;
}
