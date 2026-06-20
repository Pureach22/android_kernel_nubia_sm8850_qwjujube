__int64 __fastcall smmu_pmu_offline_cpu(unsigned int a1, __int64 a2)
{
  char v3; // w10
  unsigned __int64 v4; // x10
  unsigned __int64 v5; // x20
  int v6; // w8
  char *v7; // x20
  unsigned int v8; // w21

  if ( *(_DWORD *)(a2 + 2144) == a1 )
  {
    v3 = 0;
    do
    {
      v4 = (unsigned int)(-1LL << v3) & _cpu_online_mask;
      if ( !(_DWORD)v4 )
        break;
      v5 = __clz(__rbit64(v4));
      if ( (_DWORD)v5 != a1 )
        goto LABEL_7;
      v3 = v5 + 1;
    }
    while ( v5 <= 0x1E );
    LODWORD(v5) = 32;
LABEL_7:
    if ( (unsigned int)v5 < nr_cpu_ids )
    {
      perf_pmu_migrate_context(a2 + 2152, a1, (unsigned int)v5);
      v6 = *(_DWORD *)(a2 + 2128);
      *(_DWORD *)(a2 + 2144) = v5;
      if ( v6 )
      {
        v7 = (char *)&cpu_bit_bitmap + 8 * (unsigned int)(v5 + 1);
        v8 = 0;
        do
        {
          if ( (unsigned int)_irq_apply_affinity_hint(*(unsigned int *)(*(_QWORD *)(a2 + 2136) + 4LL * (int)v8), v7, 1) )
            __break(0x800u);
          ++v8;
        }
        while ( v8 < *(_DWORD *)(a2 + 2128) );
      }
    }
  }
  return 0;
}
