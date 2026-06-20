__int64 __fastcall android_rvh_update_thermal_stats(__int64 a1, unsigned int a2)
{
  __int64 result; // x0

  if ( (walt_disabled & 1) == 0 )
    return update_cpu_capacity_helper(a2);
  return result;
}
