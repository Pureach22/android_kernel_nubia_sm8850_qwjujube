bool __fastcall rpmh_rsc_ctrlr_is_busy(__int64 a1)
{
  int v2; // w8
  __int64 v3; // x0
  bool v4; // zf
  __int64 v5; // x8
  __int64 v6; // x8
  __int64 v7; // x2
  unsigned __int64 v8; // x20
  int *v9; // x9
  int v10; // w12
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 v13; // x2
  unsigned __int64 v14; // x20
  int *v16; // x9
  int v17; // w12

  if ( *(_BYTE *)(a1 + 768) == 1 )
  {
    v2 = *(_DWORD *)(a1 + 588);
    v3 = a1 + 1112;
    v4 = v2 == 0;
    v5 = 128;
    if ( v4 )
      v5 = 64;
    v6 = a1 + v5;
    v7 = *(unsigned int *)(v6 + 456);
    v8 = (unsigned int)(*(_DWORD *)(v6 + 460) + v7);
    if ( find_next_bit(v3, v8, v7) < v8 )
      return 1;
    if ( *(_DWORD *)(a1 + 716) )
    {
      v9 = *(int **)(a1 + 1664);
      v10 = *(_DWORD *)(a1 + 40);
      if ( !v10 )
        v10 = *v9;
      if ( !(unsigned int)readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 32)
                                                       + v9[9]
                                                       + (unsigned int)(v10 * *(_DWORD *)(a1 + 712)))) )
        return 1;
    }
  }
  if ( *(_BYTE *)(a1 + 1104) != 1 )
    return 0;
  v11 = 128;
  if ( !*(_DWORD *)(a1 + 924) )
    v11 = 64;
  v12 = a1 + v11;
  v13 = *(unsigned int *)(v12 + 792);
  v14 = (unsigned int)(*(_DWORD *)(v12 + 796) + v13);
  if ( find_next_bit(a1 + 1112, v14, v13) < v14 )
    return 1;
  if ( !*(_DWORD *)(a1 + 1052) )
    return 0;
  v16 = *(int **)(a1 + 1664);
  v17 = *(_DWORD *)(a1 + 40);
  if ( !v17 )
    v17 = *v16;
  return !(unsigned int)readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 32)
                                                     + v16[9]
                                                     + (unsigned int)(v17 * *(_DWORD *)(a1 + 1048))));
}
