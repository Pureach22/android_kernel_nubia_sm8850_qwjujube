__int64 __fastcall clusttimer_cancel(__int64 a1)
{
  __int64 result; // x0

  result = _hrtimer_get_remaining(a1 + 264, 0);
  if ( result >= 1000 )
    return hrtimer_try_to_cancel(a1 + 264);
  return result;
}
