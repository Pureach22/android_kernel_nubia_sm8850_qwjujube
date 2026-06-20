__int64 __fastcall qdf_wait_single_event(__int64 a1, unsigned int a2)
{
  int v2; // w9
  unsigned int v3; // w8
  __int64 multiplier; // x21
  __int64 v7; // x0

  v2 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 16);
  v3 = 5;
  if ( a1 && (v2 & 0xFFFF00) == 0 )
  {
    if ( *(_DWORD *)(a1 + 32) != 305402420 )
      return 4;
    if ( a2 )
    {
      multiplier = (unsigned int)qdf_timer_get_multiplier(a1);
      v7 = _msecs_to_jiffies(a2);
      if ( wait_for_completion_timeout(a1, v7 * multiplier) <= 0 )
        return 15;
    }
    else
    {
      wait_for_completion();
    }
    return 0;
  }
  return v3;
}
