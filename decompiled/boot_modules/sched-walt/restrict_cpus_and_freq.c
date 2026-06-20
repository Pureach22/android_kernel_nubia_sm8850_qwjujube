__int64 __fastcall restrict_cpus_and_freq(_DWORD *a1)
{
  __int64 v1; // x8
  char v2; // w13
  unsigned __int64 v3; // x13
  unsigned __int64 v4; // x13
  __int64 v5; // x14
  bool v6; // cf
  _DWORD *v8; // x22
  int v9; // w8
  char v10; // w13
  int v11; // w9
  unsigned __int64 v12; // x13
  unsigned __int64 v13; // x13
  __int64 v14; // x14
  bool v15; // cc

  v1 = (unsigned int)*a1;
  if ( (v1 & _cpu_partial_halt_mask) == 0
    || (v1 & _cpu_halt_mask) != 0
    || (v8 = a1, v9 = _sw_hweight64((unsigned int)part_haltable_cpus), a1 = v8, !v9)
    || (~((unsigned int)_cpu_halt_mask | (unsigned int)_cpu_partial_halt_mask) & (unsigned int)part_haltable_cpus) != 0 )
  {
    v2 = 0;
    do
    {
      v3 = (unsigned int)(-1LL << v2) & *a1;
      if ( !(_DWORD)v3 )
        break;
      v4 = __clz(__rbit64(v3));
      v5 = *(unsigned int *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v4) + 8] + 32LL);
      if ( (unsigned int)v5 > 3 )
      {
LABEL_17:
        __break(0x5512u);
        return walt_pause_cpus();
      }
      v6 = v4 >= 0x1F;
      v2 = v4 + 1;
      *((_DWORD *)&freq_cap + v5) = 0x7FFFFFFF;
    }
    while ( !v6 );
  }
  else
  {
    v10 = 0;
    v11 = sysctl_max_freq_partial_halt;
    do
    {
      v12 = (unsigned int)(-1LL << v10) & *v8;
      if ( !(_DWORD)v12 )
        break;
      v13 = __clz(__rbit64(v12));
      v14 = *(unsigned int *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v13) + 8] + 32LL);
      if ( (unsigned int)v14 >= 4 )
        goto LABEL_17;
      v15 = v13 > 0x1E;
      v10 = v13 + 1;
      *((_DWORD *)&freq_cap + v14) = v11;
    }
    while ( !v15 );
  }
  return update_smart_freq_capacities();
}
