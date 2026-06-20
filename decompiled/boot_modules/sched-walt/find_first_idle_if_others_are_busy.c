__int64 find_first_idle_if_others_are_busy()
{
  __int64 v0; // x21
  __int64 v1; // x10
  __int64 v2; // x12
  char v3; // w8
  unsigned int v4; // w19
  unsigned __int64 v5; // x8
  unsigned __int64 v6; // x20
  int v7; // w0
  __int64 v8; // x8
  unsigned __int64 v9; // x9

  if ( num_sched_clusters > 1 )
  {
    v1 = 0;
    v2 = 1;
    do
    {
      if ( num_sched_clusters - 1 != v2 )
        v1 |= *(_QWORD *)(*(_QWORD *)cpu_array + 8 * v2);
      ++v2;
    }
    while ( num_sched_clusters != v2 );
    v0 = (unsigned int)v1;
  }
  else
  {
    v0 = 0;
  }
  v3 = 0;
  v4 = -1;
  do
  {
    v5 = v0 & (-1LL << v3);
    if ( !v5 )
      break;
    v6 = __clz(__rbit64(v5));
    if ( (_cpu_active_mask & (1LL << v6)) != 0 && (_cpu_halt_mask[0] & (1LL << v6)) == 0 )
    {
      v7 = available_idle_cpu((unsigned int)v6);
      v8 = *((_QWORD *)&_per_cpu_offset + v6);
      if ( v7 )
        v4 = v6;
      v9 = *(_QWORD *)&walt_rq[v8 + 632];
      if ( *(_QWORD *)&walt_rq[v8 + 40] < v9 )
        v9 = *(_QWORD *)&walt_rq[v8 + 40];
      if ( v9 <= 0x65 && *(_DWORD *)((char *)&runqueues + v8 + 4) == 1 )
        return (unsigned int)-1;
    }
    v3 = v6 + 1;
  }
  while ( v6 < 0x1F );
  return v4;
}
