__int64 __fastcall tmc_get_rwp_offset(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x19
  __int64 v3; // x20
  _DWORD *v4; // x8
  unsigned int v5; // w0
  __int64 v6; // x8
  __int64 v7; // x19
  __int64 v8; // x0
  __int64 v9; // x10
  unsigned __int64 v10; // x8
  unsigned __int64 *v11; // x9
  __int64 v12; // x10
  __int64 v13; // x11
  unsigned __int64 v14; // x12
  unsigned __int64 v15; // t1
  __int64 v17; // x19
  __int64 v18; // x20
  _DWORD *v19; // x8
  unsigned int v20; // w0
  __int64 v21; // x8
  __int64 v22; // x19
  __int64 v23; // x0
  __int64 v24; // x0
  _DWORD *v25; // x8
  __int64 v26; // x0
  _DWORD *v27; // x8

  v1 = *(_QWORD *)(a1 + 288);
  if ( !v1 )
  {
    dev_err(*(_QWORD *)(a1 + 16) + 56LL, "sysfs_buf is NULL, unable to get rwp offset\n");
    return -22;
  }
  if ( !*(_DWORD *)(v1 + 4) )
  {
    v17 = *(_QWORD *)(a1 + 16);
    v18 = *(_QWORD *)(v1 + 24);
    v19 = *(_DWORD **)(v17 + 40);
    if ( *(_BYTE *)(v17 + 32) == 1 )
    {
      v20 = readl_relaxed_1(v19 + 6);
      v21 = *(_QWORD *)(v17 + 40);
      v22 = v20;
      v23 = (unsigned int)readl_relaxed_1(v21 + 60);
    }
    else
    {
      if ( *(v19 - 1) != -340433967 )
        __break(0x8228u);
      v26 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v19)(24, 1, 0);
      v27 = *(_DWORD **)(v17 + 40);
      v22 = v26;
      if ( *(v27 - 1) != -340433967 )
        __break(0x8228u);
      v23 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v27)(60, 1, 0);
    }
    return (v22 | (v23 << 32)) - v18;
  }
  v2 = *(_QWORD *)(a1 + 16);
  v3 = **(_QWORD **)(v1 + 56);
  v4 = *(_DWORD **)(v2 + 40);
  if ( *(_BYTE *)(v2 + 32) == 1 )
  {
    v5 = readl_relaxed_1(v4 + 6);
    v6 = *(_QWORD *)(v2 + 40);
    v7 = v5;
    v8 = (unsigned int)readl_relaxed_1(v6 + 60);
  }
  else
  {
    if ( *(v4 - 1) != -340433967 )
      __break(0x8228u);
    v24 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v4)(24, 1, 0);
    v25 = *(_DWORD **)(v2 + 40);
    v7 = v24;
    if ( *(v25 - 1) != -340433967 )
      __break(0x8228u);
    v8 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v25)(60, 1, 0);
  }
  v9 = *(unsigned int *)(v3 + 64);
  if ( (int)v9 < 1 )
    return -22;
  v10 = v7 | (v8 << 32);
  v11 = *(unsigned __int64 **)(v3 + 72);
  v12 = v9 << 12;
  v13 = 0;
  while ( 1 )
  {
    v15 = *v11++;
    v14 = v15;
    if ( v15 <= v10 && v14 + 4096 > v10 )
      break;
    v13 += 4096;
    if ( v12 == v13 )
      return -22;
  }
  return v10 - v14 + v13;
}
