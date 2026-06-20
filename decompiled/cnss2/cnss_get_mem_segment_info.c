__int64 __fastcall cnss_get_mem_segment_info(int a1, __int64 a2, unsigned int a3)
{
  unsigned int v3; // w9
  __int64 v4; // x8
  __int64 *v5; // x10
  __int64 v6; // x9
  _QWORD *v7; // x12
  __int64 v8; // t1
  unsigned int v10; // w9
  __int64 v11; // x8
  __int64 v12; // x9
  __int64 *v13; // x10
  _QWORD *v14; // x12
  __int64 v15; // t1
  __int64 v16; // x0

  if ( !plat_env )
    return 4294967277LL;
  if ( a1 == 1 )
  {
    if ( *(_DWORD *)(plat_env + 4144) >= a3 )
      v10 = a3;
    else
      v10 = *(_DWORD *)(plat_env + 4144);
    if ( v10 )
    {
      v11 = 0;
      v12 = 24LL * v10;
      v13 = (__int64 *)(plat_env + 4168);
      while ( v11 != 1248 )
      {
        v14 = (_QWORD *)(a2 + v11);
        v11 += 24;
        *v14 = *(v13 - 2);
        v14[1] = *(v13 - 1);
        v15 = *v13;
        v13 += 5;
        v14[2] = v15;
        if ( v12 == v11 )
          return 0;
      }
      goto LABEL_22;
    }
    return 0;
  }
  if ( a1 )
    return 4294967274LL;
  if ( *(_DWORD *)(plat_env + 1720) >= a3 )
    v3 = a3;
  else
    v3 = *(_DWORD *)(plat_env + 1720);
  if ( !v3 )
    return 0;
  v4 = 0;
  v5 = (__int64 *)(plat_env + 1744);
  v6 = 24LL * v3;
  while ( v4 != 1248 )
  {
    v7 = (_QWORD *)(a2 + v4);
    v4 += 24;
    *v7 = *(v5 - 2);
    v7[1] = *(v5 - 1);
    v8 = *v5;
    v5 += 5;
    v7[2] = v8;
    if ( v6 == v4 )
      return 0;
  }
LABEL_22:
  __break(0x5512u);
  v16 = MEMORY[0x4F2BC48]();
  return cnss_get_audio_shared_iommu_group_cap(v16);
}
