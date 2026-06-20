__int64 __fastcall should_help_min_cap(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  char v5; // w12
  unsigned __int64 v6; // x12
  unsigned __int64 v7; // x12
  bool v8; // cc

  if ( !sysctl_sched_force_lb_enable )
    return 0;
  if ( (unsigned int)a1 < 0x20 )
  {
    if ( *(_DWORD *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + (unsigned int)a1) + 8] + 32LL) != min_possible_cluster_id )
    {
      v5 = 0;
      while ( 1 )
      {
        v6 = (unsigned int)(-1LL << v5) & (unsigned int)**(_QWORD **)cpu_array;
        if ( !(_DWORD)v6 )
          break;
        v7 = __clz(__rbit64(v6));
        if ( *(_DWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v7) + 24] )
          return 1;
        v8 = v7 > 0x1E;
        v5 = v7 + 1;
        if ( v8 )
          return 0;
      }
    }
    return 0;
  }
  __break(0x5512u);
  return walt_lb_find_busiest_cpu(a1, a2, a3, a4);
}
