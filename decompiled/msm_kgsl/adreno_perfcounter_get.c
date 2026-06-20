__int64 __fastcall adreno_perfcounter_get(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        _DWORD *a4,
        _DWORD *a5,
        char a6)
{
  __int64 v6; // x8
  __int64 v7; // x19
  __int64 v8; // x8
  __int64 v9; // x10
  unsigned int v10; // w11
  __int64 v11; // x9
  __int64 v12; // x12
  int v13; // w13
  __int64 v14; // x9
  __int64 v15; // x20
  __int64 v16; // x10
  int v17; // w8
  __int64 result; // x0
  __int64 v19; // x8
  __int64 v20; // x8
  __int64 v21; // x9
  __int64 v22; // x1
  __int64 (*v23)(void); // x9

  v6 = *(_QWORD *)(*(_QWORD *)(a1 + 14264) + 48LL);
  if ( a4 )
    *a4 = 0;
  if ( a5 )
    *a5 = 0;
  if ( !v6 || *(_DWORD *)(v6 + 8) <= a2 )
    return 4294967274LL;
  v7 = *(_QWORD *)v6 + 56LL * a2;
  v8 = *(unsigned int *)(v7 + 8);
  if ( (*(_BYTE *)(v7 + 24) & 1) == 0 )
  {
    if ( !(_DWORD)v8 )
      return 4294967280LL;
    v9 = *(_QWORD *)v7;
    v10 = 0;
    v11 = 0;
    v12 = 48 * v8;
    LODWORD(v8) = -1;
    while ( 1 )
    {
      v13 = *(_DWORD *)(v9 + v11);
      if ( v13 == a3 )
        break;
      v11 += 48;
      if ( v13 == -1 )
        v8 = v10;
      else
        v8 = (unsigned int)v8;
      ++v10;
      if ( v12 == v11 )
      {
        if ( (_DWORD)v8 == -1 )
          return 4294967280LL;
        v14 = *(_QWORD *)v7;
        v15 = v8;
        goto LABEL_39;
      }
    }
    v19 = v9 + v11;
    if ( (a6 & 1) != 0 )
      ++*(_DWORD *)(v19 + 4);
    else
      ++*(_DWORD *)(v19 + 8);
    if ( a4 )
      *a4 = *(_DWORD *)(*(_QWORD *)v7 + v11 + 12);
    result = 0;
    if ( a5 )
    {
      v20 = *(_QWORD *)v7 + v11;
      goto LABEL_37;
    }
    return result;
  }
  if ( (unsigned int)v8 <= a3 )
    return 4294967274LL;
  v14 = *(_QWORD *)v7;
  v15 = a3;
  v16 = *(_QWORD *)v7 + 48LL * a3;
  v17 = *(_DWORD *)(v16 + 4);
  if ( v17 || *(_DWORD *)(v16 + 8) )
  {
    if ( (a6 & 1) != 0 )
      *(_DWORD *)(v14 + 48LL * a3 + 4) = v17 + 1;
    else
      ++*(_DWORD *)(v14 + 48LL * a3 + 8);
    if ( a4 )
      *a4 = *(_DWORD *)(*(_QWORD *)v7 + 48LL * a3 + 12);
    result = 0;
    if ( a5 )
    {
      v20 = *(_QWORD *)v7 + 48LL * a3;
LABEL_37:
      *a5 = *(_DWORD *)(v20 + 16);
    }
  }
  else
  {
    LODWORD(v8) = a3;
LABEL_39:
    *(_DWORD *)(v14 + 48LL * (unsigned int)v15) = a3;
    v21 = *(_QWORD *)(*(_QWORD *)(a1 + 14264) + 48LL);
    if ( v21 && *(_DWORD *)(v21 + 8) > a2 && (v22 = *(_QWORD *)v21 + 56LL * a2, *(_DWORD *)(v22 + 8) > (unsigned int)v8) )
    {
      v23 = *(__int64 (**)(void))(v22 + 32);
      if ( *((_DWORD *)v23 - 1) != 339051004 )
        __break(0x8229u);
      result = v23();
      if ( !(_DWORD)result )
      {
        if ( (*(_BYTE *)(v7 + 24) & 2) == 0 )
          ++*(_DWORD *)(a1 + 24044);
        *(_DWORD *)(*(_QWORD *)v7 + 48 * v15 + 4) = a6 & 1;
        *(_DWORD *)(*(_QWORD *)v7 + 48 * v15 + 8) = !(a6 & 1);
        if ( a4 )
          *a4 = *(_DWORD *)(*(_QWORD *)v7 + 48LL * (unsigned int)v15 + 12);
        result = 0;
        if ( a5 )
          *a5 = *(_DWORD *)(*(_QWORD *)v7 + 48LL * (unsigned int)v15 + 16);
        return result;
      }
    }
    else
    {
      result = 4294967274LL;
    }
    if ( (*(_BYTE *)(v7 + 24) & 1) == 0 )
      *(_DWORD *)(*(_QWORD *)v7 + 48LL * (unsigned int)v15) = -1;
  }
  return result;
}
