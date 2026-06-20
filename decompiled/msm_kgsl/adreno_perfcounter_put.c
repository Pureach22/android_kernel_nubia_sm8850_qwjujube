__int64 __fastcall adreno_perfcounter_put(__int64 a1, unsigned int a2, int a3, char a4)
{
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x19
  __int64 v7; // x9
  __int64 v8; // x10
  __int64 v9; // x8
  __int64 v10; // x9
  __int64 v11; // x20
  __int64 v12; // x10
  int v13; // w11
  __int64 v14; // x9
  int v15; // w10
  __int64 v16; // x9
  __int64 v17; // x10
  __int64 result; // x0
  __int64 (*v19)(void); // x8

  v4 = *(_QWORD *)(a1 + 14264);
  v5 = *(_QWORD *)(v4 + 48);
  if ( !v5 )
    return 4294967274LL;
  if ( *(_DWORD *)(v5 + 8) <= a2 )
    return 4294967274LL;
  v6 = *(_QWORD *)v5 + 56LL * a2;
  v7 = *(unsigned int *)(v6 + 8);
  if ( !(_DWORD)v7 )
    return 4294967274LL;
  v8 = 3 * v7;
  v9 = *(_QWORD *)(v4 + 40);
  v10 = *(_QWORD *)v6;
  v11 = 0;
  v12 = 16 * v8;
  while ( *(_DWORD *)(v10 + v11) != a3 )
  {
    v11 += 48;
    if ( v12 == v11 )
      return 4294967274LL;
  }
  if ( (a4 & 1) != 0 )
  {
    v13 = *(_DWORD *)(v10 + v11 + 4);
    if ( v13 )
    {
      *(_DWORD *)(v10 + v11 + 4) = v13 - 1;
      goto LABEL_13;
    }
  }
  v14 = v10 + v11;
  v15 = *(_DWORD *)(v14 + 8);
  if ( !v15 )
    return 4294967274LL;
  *(_DWORD *)(v14 + 8) = v15 - 1;
LABEL_13:
  v16 = *(_QWORD *)v6;
  v17 = *(_QWORD *)v6 + v11;
  if ( *(_DWORD *)(v17 + 4) || *(_DWORD *)(v17 + 8) )
    return 0;
  if ( (*(_BYTE *)(v6 + 24) & 2) == 0 )
  {
    --*(_DWORD *)(a1 + 24044);
    v16 = *(_QWORD *)v6;
  }
  v19 = *(__int64 (**)(void))(v9 + 232);
  if ( !v19 )
    goto LABEL_25;
  if ( *((_DWORD *)v19 - 1) != 1161532077 )
    __break(0x8228u);
  result = v19();
  if ( !(_DWORD)result )
  {
    v16 = *(_QWORD *)v6;
LABEL_25:
    *(_DWORD *)(v16 + v11) = -1;
    return 0;
  }
  return result;
}
