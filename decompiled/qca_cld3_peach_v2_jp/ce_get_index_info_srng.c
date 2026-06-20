__int64 __fastcall ce_get_index_info_srng(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x8
  int v5; // w10
  int v6; // w11
  int v7; // w9
  __int16 v8; // w8
  __int64 v10; // x8
  __int64 v11; // x8
  int *v12; // x9
  int v13; // w8
  int v14; // w10
  int v15; // w9
  bool v16; // zf
  __int16 v17; // w10

  *(_BYTE *)a3 = *(_DWORD *)(a2 + 8);
  v3 = *(_QWORD *)(a2 + 136);
  if ( !v3 )
  {
    if ( !*(_QWORD *)(a2 + 144) )
      return 0;
    v10 = *(_QWORD *)(a2 + 152);
    if ( !v10 )
      return 0;
    v11 = *(_QWORD *)(v10 + 80);
    v12 = *(int **)(v11 + 128);
    v14 = *(_DWORD *)(v11 + 116);
    v13 = *(_DWORD *)(v11 + 120);
    v15 = *v12;
    v16 = v14 == 0;
    if ( v14 )
      v17 = v13;
    else
      v17 = v15;
    if ( !v16 )
      LOWORD(v13) = v15;
    *(_WORD *)(a3 + 7) = v17;
    *(_WORD *)(a3 + 5) = v13;
    v3 = *(_QWORD *)(a2 + 144);
  }
  v4 = *(_QWORD *)(v3 + 80);
  v5 = *(_DWORD *)(v4 + 116);
  v6 = *(_DWORD *)(v4 + 120);
  v7 = **(_DWORD **)(v4 + 128);
  if ( v5 )
    v8 = *(_DWORD *)(v4 + 120);
  else
    v8 = **(_DWORD **)(v4 + 128);
  if ( !v5 )
    LOWORD(v7) = v6;
  *(_WORD *)(a3 + 3) = v8;
  *(_WORD *)(a3 + 1) = v7;
  return 0;
}
