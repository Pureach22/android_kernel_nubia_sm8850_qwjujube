__int64 __fastcall wlan_t2lm_timer_stop(__int64 result)
{
  __int64 v1; // x19

  if ( *(_BYTE *)(result + 96) == 1 )
  {
    v1 = result;
    result = hrtimer_cancel(result);
    *(_QWORD *)(v1 + 88) = 0;
    *(_BYTE *)(v1 + 96) = 0;
  }
  return result;
}
