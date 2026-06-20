__int64 __fastcall get_cluster_sleep_time(__int64 a1)
{
  char v1; // w13
  __int64 v2; // x8
  unsigned __int64 v3; // x13
  unsigned __int64 v4; // x13
  __int64 v5; // x15
  bool v6; // cf

  v1 = 0;
  v2 = 0x7FFFFFFFFFFFFFFFLL;
  do
  {
    v3 = (unsigned int)(-1LL << v1) & (unsigned int)*(_QWORD *)(*(_QWORD *)(a1 + 160) + 1328LL) & _cpu_online_mask;
    if ( !v3 )
      break;
    v4 = __clz(__rbit64(v3));
    v5 = _per_cpu_offset[v4];
    if ( *(_QWORD *)(v5 + *(_QWORD *)(a1 + 344)) < v2 )
      v2 = *(_QWORD *)(v5 + *(_QWORD *)(a1 + 344));
    v6 = v4 >= 0x1F;
    v1 = v4 + 1;
  }
  while ( !v6 );
  return v2;
}
