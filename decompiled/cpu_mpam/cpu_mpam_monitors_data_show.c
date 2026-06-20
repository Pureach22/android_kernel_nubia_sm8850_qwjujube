__int64 __fastcall cpu_mpam_monitors_data_show(__int64 a1, __int64 a2)
{
  __int64 v3; // x9
  __int64 v4; // x23
  int v5; // w21
  unsigned int *v6; // x8
  __int64 v7; // x25
  int v8; // w0
  int v9; // w24
  bool v10; // zf
  int v11; // w28
  __int64 v13; // x21
  int v14; // w28
  int v15; // w3
  __int64 v17; // [xsp+8h] [xbp-18h]
  __int64 v18; // [xsp+18h] [xbp-8h]

  if ( mpam_msc_cnt < 1 )
    return 0;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  do
  {
    v17 = v3;
    v6 = (unsigned int *)(mpam_mscs + 16 * v3);
    v7 = mpam_mon_base + 336LL * *v6;
    v8 = scnprintf(a2 + v4, 4096 - v4, "%s:\n", *((const char **)v6 + 1));
    v9 = *(_DWORD *)v7;
    v18 = v4 + v8;
    do
    {
      do
      {
        v11 = v5 + 1;
        if ( (v9 & 1) == 0 )
          break;
      }
      while ( v5++ < 5000 );
      v4 = v18 + (int)scnprintf(a2 + v18, 4096 - v18, "timestamp=%llu\n", *(_QWORD *)(v7 + 328));
      v13 = 0;
      v14 = v11 - 1;
      do
      {
        v15 = *((_DWORD *)&monitor_enabled + v13);
        if ( v15 != 0x7FFFFFFF )
          v4 += (int)scnprintf(
                       a2 + v4,
                       4096 - v4,
                       "%d:csu=%u,mbwu=%llu\n",
                       v15,
                       *(_DWORD *)(v7 + 4 * v13 + 72),
                       *(_QWORD *)(v7 + 8 * v13 + 200));
        ++v13;
      }
      while ( v13 != 12 );
      v5 = v14;
      v10 = v9 == *(_DWORD *)v7;
      v9 = *(_DWORD *)v7;
    }
    while ( !v10 );
    v3 = v17 + 1;
  }
  while ( v17 + 1 < mpam_msc_cnt );
  return v4;
}
