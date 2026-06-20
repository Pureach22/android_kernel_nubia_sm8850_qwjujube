__int64 __fastcall cpu_mpam_monitor_data_show(__int64 a1, __int64 a2)
{
  __int64 v2; // x22
  __int64 v4; // x20
  __int64 v5; // x24
  int v6; // w23
  __int64 v7; // x9
  int v8; // w10
  int v10; // w0

  v2 = *(int *)(a1 + 140);
  if ( (_DWORD)v2 == 0x7FFFFFFF )
    return (int)scnprintf(a2, 4096, "monitor not enabled\n");
  if ( mpam_msc_cnt < 1 )
    return 0;
  v5 = 0;
  v4 = 0;
  v6 = 0;
  do
  {
    v7 = mpam_mon_base + 336LL * *(unsigned int *)(mpam_mscs + 16 * v5);
    do
    {
      v8 = v6 + 1;
      if ( (*(_DWORD *)v7 & 1) == 0 )
        break;
    }
    while ( v6++ < 5000 );
    if ( (unsigned int)v2 >= 0x10 )
    {
      __break(0x5512u);
      JUMPOUT(0x7988);
    }
    v6 = v8 - 1;
    v10 = scnprintf(
            a2 + v4,
            4096 - v4,
            "%s:timestamp=%llu,csu=%u,mbwu=%llu\n",
            *(const char **)(mpam_mscs + 16 * v5++ + 8),
            *(_QWORD *)(v7 + 328),
            *(_DWORD *)(v7 + 4 * v2 + 72),
            *(_QWORD *)(v7 + 8 * v2 + 200));
    v4 += v10;
  }
  while ( v5 < mpam_msc_cnt );
  return v4;
}
