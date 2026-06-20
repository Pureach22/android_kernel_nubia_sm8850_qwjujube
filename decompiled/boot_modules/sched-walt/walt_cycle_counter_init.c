__int64 walt_cycle_counter_init()
{
  char v0; // w8
  unsigned __int64 v1; // x8
  unsigned __int64 v2; // x19
  char *v3; // x25
  int v4; // w0

  v0 = 0;
  do
  {
    v1 = (unsigned int)(-1LL << v0) & _cpu_possible_mask;
    if ( !(_DWORD)v1 )
      break;
    v2 = __clz(__rbit64(v1));
    v3 = (char *)&walt_cc + *((_QWORD *)&_per_cpu_offset + v2);
    *(_QWORD *)v3 = 0;
    v4 = cpufreq_quick_get((unsigned int)v2);
    *((_QWORD *)v3 + 1) = 0;
    *((_QWORD *)v3 + 2) = 0;
    *((_DWORD *)v3 + 6) = v4;
    *((_DWORD *)v3 + 7) = ((16 * ((274877907 * (unsigned __int64)(unsigned int)(v4 << 10)) >> 32)) & 0xFFFFFC00) / 0x3E8;
    v0 = v2 + 1;
  }
  while ( v2 < 0x1F );
  walt_get_cycle_counts_cb = &walt_cpu_cycle_counter;
  use_cycle_counter = 1;
  complete(&walt_get_cycle_counts_cb_completion);
  return android_rvh_probe_register(&_tracepoint_android_rvh_cpufreq_transition, walt_cpufreq_transition, 0);
}
