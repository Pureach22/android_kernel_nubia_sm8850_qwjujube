__int64 __fastcall adreno_cp_parse_ibn(
        __int64 a1,
        __int64 a2,
        unsigned __int64 a3,
        unsigned __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7)
{
  unsigned __int64 v8; // x22
  __int64 v9; // x19
  __int64 v10; // x20
  unsigned __int64 v11; // x21
  __int64 v12; // x23
  int v13; // w24
  __int64 v14; // x8
  __int64 i; // x10
  unsigned __int64 v16; // x11

  if ( a7 > 2 )
    return 4294967274LL;
  if ( a5 == a3 )
  {
    v8 = a3;
    v9 = a1;
    v10 = a2;
    v11 = a4;
    v12 = a6;
    v13 = a7;
    kgsl_snapshot_push_object(a1, a2, a5);
    a1 = v9;
    a2 = v10;
    a3 = v8;
    a7 = v13;
    a4 = v11;
    a6 = v12;
  }
  v14 = *(unsigned int *)(a6 + 8);
  if ( (int)v14 < 1 )
    return adreno_ib_find_objs(a1, a2, a3, a4, 2u, a6, a7 + 1);
  for ( i = *(_QWORD *)a6 + 8LL; ; i += 32 )
  {
    if ( *(_DWORD *)(i + 8) == 2 )
    {
      v16 = *(_QWORD *)(i - 8);
      if ( v16 <= a3 && a3 + 4 * a4 <= *(_QWORD *)i + v16 )
        break;
    }
    if ( !--v14 )
      return adreno_ib_find_objs(a1, a2, a3, a4, 2u, a6, a7 + 1);
  }
  return 0;
}
