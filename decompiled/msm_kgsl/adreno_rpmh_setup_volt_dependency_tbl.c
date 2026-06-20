__int64 __fastcall adreno_rpmh_setup_volt_dependency_tbl(__int64 a1, __int64 a2, int *a3, __int64 a4, int a5)
{
  int v5; // w8
  int v6; // w9
  unsigned int v7; // w10
  int v8; // w11
  int v9; // w13
  int v10; // w14
  int v12; // w12
  int v13; // w11

  if ( !a5 )
    return 0;
  v5 = 0;
  while ( *(_DWORD *)a2 )
  {
    v6 = 0;
    while ( 1 )
    {
      v7 = *(unsigned __int16 *)(*(_QWORD *)(a2 + 8) + 2LL * v6);
      if ( v7 >= *(unsigned __int16 *)(a4 + 2LL * v5) )
        break;
      if ( *(_DWORD *)a2 == ++v6 )
        return 4294967274LL;
    }
    v8 = *a3;
    v9 = 0;
    while ( v8 != v9 )
    {
      v10 = v9 + 1;
      if ( *a3 - 1 != v9 && *(unsigned __int16 *)(*((_QWORD *)a3 + 1) + 2LL * v9++) < v7 )
        continue;
      v12 = v10 - 1;
      goto LABEL_15;
    }
    v12 = *a3;
LABEL_15:
    if ( v12 == v8 )
      v13 = 0;
    else
      v13 = (unsigned __int8)v12 << 8;
    *(_DWORD *)(a1 + 4LL * v5++) = v13 & 0xFFFFFF00 | (v7 << 16) | (unsigned __int8)v6;
    if ( v5 == a5 )
      return 0;
  }
  return 4294967274LL;
}
