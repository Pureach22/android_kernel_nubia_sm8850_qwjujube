__int64 __fastcall cpu_mpam_schemata_show(__int64 a1, __int64 a2)
{
  __int64 v4; // x25
  __int64 v5; // x26
  int v6; // w24
  int v7; // w0
  __int64 v8; // x0
  const char *v9; // x3
  _DWORD *v10; // x8

  if ( mpam_msc_cnt < 1 )
    return 0;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  do
  {
    v8 = a2 + v6;
    v9 = *(const char **)(mpam_mscs + v4 + 8);
    v10 = (_DWORD *)(*(_QWORD *)(a1 + 144) + 16LL * *(unsigned int *)(mpam_mscs + v4));
    if ( can_monitor == 1 )
      v7 = scnprintf(v8, 4096, "%s:cmax=%d,cpbm=0x%x,prio=%d,slc_partid=%d\n", v9, v10[1], *v10, v10[2], v10[3]);
    else
      v7 = scnprintf(v8, 4096, "%s:cpbm=0x%x,slc_partid=%d\n", v9, *v10, v10[3]);
    ++v5;
    v6 += v7;
    v4 += 16;
  }
  while ( v5 < mpam_msc_cnt );
  return v6;
}
