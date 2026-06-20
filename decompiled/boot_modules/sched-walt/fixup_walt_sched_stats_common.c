__int64 __fastcall fixup_walt_sched_stats_common(__int64 result, __int64 a2, unsigned __int16 a3)
{
  unsigned __int16 v3; // w19
  char *v4; // x22
  _QWORD *v5; // x23
  char *v6; // x24
  unsigned __int64 v7; // x9
  __int64 v8; // x10
  __int64 v9; // x8
  _DWORD *v10; // x21
  int v12; // w8

  v7 = (unsigned __int64)&init_task;
  LODWORD(v8) = a2 + 5184;
  v9 = *(unsigned int *)(result + 3632);
  if ( (_UNKNOWN *)a2 == &init_task )
    v10 = &vendor_data_pad;
  else
    v10 = (_DWORD *)(a2 + 5184);
  if ( (unsigned int)v9 >= 0x20 )
    goto LABEL_19;
  v5 = &_per_cpu_offset;
  v3 = a3;
  v6 = (char *)&walt_rq;
  v4 = (char *)&walt_rq + *((_QWORD *)&_per_cpu_offset + v9);
  result = fixup_cumulative_runnable_avg();
  if ( *(int *)(a2 + 148) < 100 )
    return result;
  LODWORD(v9) = *v10;
  if ( (*v10 & 4) != 0 )
    return result;
  LODWORD(v8) = num_sched_clusters;
  v7 = *(_QWORD *)cpu_array;
  if ( num_sched_clusters < 2 )
    goto LABEL_10;
  v7 = *(unsigned int *)(v7 + 8LL * (unsigned int)num_sched_clusters - 16);
  if ( !v7 )
  {
LABEL_19:
    do
    {
      __break(0x5512u);
LABEL_10:
      v8 = 8LL * ((int)v8 - 1);
      v7 = *(unsigned int *)(v7 + v8);
    }
    while ( !v7 );
  }
  if ( (700 * *(_DWORD *)&v6[v5[__clz(__rbit64(v7))] + 632]) >> 10 >= v3 )
  {
    if ( (v9 & 0x10) == 0 )
      return result;
    *v10 = v9 & 0xFFFFFFEB;
    v12 = (*((_DWORD *)v4 + 8) - 1) & ~((*((_DWORD *)v4 + 8) - 1) >> 31);
  }
  else
  {
    if ( (v9 & 0x10) != 0 )
      return result;
    *v10 = v9 | 0x10;
    v12 = *((_DWORD *)v4 + 8) + 1;
  }
  *((_DWORD *)v4 + 8) = v12;
  return result;
}
