__int64 __fastcall get_cpus_qos(_DWORD *a1)
{
  char v2; // w8
  __int64 v3; // x19
  unsigned __int64 v4; // x8
  unsigned __int64 v5; // x21
  __int64 v6; // x0

  v2 = 0;
  v3 = 2000000000000LL;
  do
  {
    v4 = (unsigned int)(-1LL << v2) & *a1;
    if ( !(_DWORD)v4 )
      break;
    v5 = __clz(__rbit64(v4));
    if ( ((_cpu_active_mask >> v5) & 1) != 0 )
    {
      v6 = cpuidle_governor_latency_req((unsigned int)v5);
      if ( v6 < v3 )
        v3 = v6;
    }
    v2 = v5 + 1;
  }
  while ( v5 < 0x1F );
  return v3;
}
