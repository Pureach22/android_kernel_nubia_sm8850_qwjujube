__int64 trailblazer_on_prime()
{
  char v0; // w12
  unsigned __int64 v1; // x12
  unsigned __int64 v2; // x12
  bool v3; // cc

  v0 = 0;
  while ( 1 )
  {
    v1 = (unsigned int)(-1LL << v0) & (unsigned int)*(_QWORD *)(*(_QWORD *)cpu_array + 8LL * (num_sched_clusters - 1));
    if ( !(_DWORD)v1 )
      return 0;
    v2 = __clz(__rbit64(v1));
    if ( *(_DWORD *)((char *)&walt_rq + *((_QWORD *)&_per_cpu_offset + v2) + 28) )
      break;
    v3 = v2 > 0x1E;
    v0 = v2 + 1;
    if ( v3 )
      return 0;
  }
  return 1;
}
