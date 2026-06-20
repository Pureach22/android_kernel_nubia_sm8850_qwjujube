__int64 __fastcall kgsl_regulator_disable_wait(__int64 a1, unsigned int a2)
{
  __int64 v4; // x21
  __int64 result; // x0
  __int64 v6; // x20

  v4 = ktime_get(a1);
  result = regulator_disable(a1);
  if ( !(_DWORD)result )
  {
    result = regulator_is_enabled(a1);
    if ( (_DWORD)result )
    {
      v6 = v4 + 1000000LL * a2;
      while ( ktime_get(result) <= v6 )
      {
        usleep_range_state(26, 100, 2);
        result = regulator_is_enabled(a1);
        if ( !(_DWORD)result )
          return result;
      }
      if ( (unsigned int)regulator_is_enabled(a1) )
        return 4294967186LL;
      else
        return 0;
    }
  }
  return result;
}
