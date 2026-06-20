__int64 __fastcall android_rvh_sched_cpu_dying(__int64 a1, unsigned int a2)
{
  __int64 result; // x0

  if ( (walt_disabled & 1) == 0 )
    return clear_walt_request(a2);
  return result;
}
