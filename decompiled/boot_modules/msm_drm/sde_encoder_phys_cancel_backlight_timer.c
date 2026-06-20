__int64 __fastcall sde_encoder_phys_cancel_backlight_timer(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20

  if ( result )
  {
    v1 = *(_QWORD *)(result + 328);
    if ( v1 )
    {
      v2 = *(_QWORD *)(v1 + 2640);
      result = ktime_get(result);
      if ( v2 > result )
        return hrtimer_cancel(v1 + 2616);
    }
  }
  return result;
}
