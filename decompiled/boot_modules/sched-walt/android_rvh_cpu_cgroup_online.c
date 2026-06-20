__int64 __fastcall android_rvh_cpu_cgroup_online(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  if ( (walt_disabled & 1) == 0 )
    return walt_update_tg_pointer(a2);
  return result;
}
