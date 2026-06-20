__int64 __fastcall get_cpu_min_freq(__int64 a1, __int64 a2, __int64 a3)
{
  char v4; // w8
  int v5; // w22
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x21

  v4 = 0;
  v5 = 0;
  do
  {
    v6 = (unsigned int)(-1LL << v4) & _cpu_present_mask;
    if ( !(_DWORD)v6 )
      break;
    v7 = __clz(__rbit64(v6));
    v5 += scnprintf(a3 + v5, 4096LL - v5, "%d:%u ", v7, *(_DWORD *)((char *)&msm_perf_cpu_stats + _per_cpu_offset[v7]));
    v4 = v7 + 1;
  }
  while ( v7 < 0x1F );
  return (int)(scnprintf(a3 + v5, 4096LL - v5, "\n") + v5);
}
