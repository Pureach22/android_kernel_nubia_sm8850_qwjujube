__int64 __fastcall wlan_mlo_t2lm_timer_stop(__int64 a1)
{
  __int64 v1; // x19

  if ( !a1 )
    return 29;
  v1 = *(_QWORD *)(a1 + 1360);
  if ( !v1 )
    return 29;
  if ( *(_BYTE *)(v1 + 2448) == 1 )
  {
    hrtimer_cancel(v1 + 2352);
    *(_QWORD *)(v1 + 2440) = 0;
    *(_BYTE *)(v1 + 2448) = 0;
  }
  return 0;
}
