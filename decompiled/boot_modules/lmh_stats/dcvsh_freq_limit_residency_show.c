__int64 __fastcall dcvsh_freq_limit_residency_show(__int64 a1, __int64 a2, __int64 a3)
{
  int v5; // w21
  unsigned int v6; // w24
  unsigned int v7; // w25
  __int64 v8; // x23

  v5 = scnprintf(a3, 4096, "%-8s\t %-10s\t %-10s\n", "Freq(KHz)");
  if ( *(_DWORD *)(a1 + 152) )
  {
    v6 = 0;
    do
    {
      v8 = *(_QWORD *)(*(_QWORD *)(a1 + 128) + 8LL * (int)v6);
      if ( v6 == *(_DWORD *)(a1 + 156) )
        v8 = sched_clock() + v8 - *(_QWORD *)(a1 + 168);
      v7 = *(_DWORD *)(*(_QWORD *)(a1 + 136) + 4LL * (int)v6);
      nsec_to_clock_t(v8);
      ++v6;
      v5 += scnprintf(a3 + v5, 4096, "%-8u\t %-10llu\t %-10u\n", v7);
    }
    while ( v6 < *(_DWORD *)(a1 + 152) );
  }
  return v5;
}
