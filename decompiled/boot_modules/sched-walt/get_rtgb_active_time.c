__int64 __fastcall get_rtgb_active_time(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  __int64 v3; // x8

  if ( walt_clock_suspended == 1 )
    v2 = sched_clock_last;
  else
    v2 = sched_clock(a1, a2);
  if ( !qword_67BA0 || *(_BYTE *)(qword_67BA0 + 40) != 1 )
    return 0;
  v3 = *(_QWORD *)(qword_67BA0 + 80);
  if ( v3 )
    return v2 - v3;
  else
    return 0;
}
