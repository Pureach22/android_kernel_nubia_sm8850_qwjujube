__int64 __fastcall iopgtbl_unmap(_QWORD *a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v5; // x22
  unsigned __int64 v7; // x23
  unsigned __int64 v8; // x8
  __int64 v9; // x10
  unsigned __int64 v10; // x9
  unsigned __int64 v11; // x11
  unsigned __int64 v12; // x9
  char v13; // w9
  unsigned __int64 v14; // x10
  unsigned __int64 v15; // x10
  __int64 v16; // x0
  _QWORD *v17; // x19
  void (*v18)(void); // x8
  __int64 v19; // x0
  void (*v20)(void); // x8
  __int64 result; // x0
  void (*v22)(void); // x8

  if ( a3 )
  {
    v5 = a1[25];
    v7 = 0;
    do
    {
      v8 = a3 - v7;
      v9 = a1[28];
      v10 = 0xFFFFFFFFFFFFFFFFLL >> ((unsigned __int8)__clz(__rbit64(a2)) ^ 0x3Fu);
      v11 = (0xFFFFFFFFFFFFFFFFLL >> __clz(a3 - v7)) & v9;
      if ( !a2 )
        v10 = -1;
      v12 = v11 & v10;
      if ( !v12 )
        break;
      v13 = __clz(v12);
      v14 = v9 & ~(0xFFFFFFFFFFFFFFFFLL >> v13);
      if ( v14 )
      {
        v15 = v14 & -(__int64)v14;
        if ( v15 - ((v15 - 1) & a2) + v15 <= v8 )
          v8 = v15 - ((v15 - 1) & a2);
      }
      v16 = qcom_arm_lpae_unmap_pages(v5, a2, 1LL << (v13 ^ 0x3Fu), v8 >> (v13 ^ 0x3Fu), 0);
      if ( !v16 )
        break;
      v7 += v16;
      a2 += v16;
    }
    while ( v7 < a3 );
    if ( v7 != a3 )
      return 4294967274LL;
  }
  v17 = (_QWORD *)a1[14];
  v18 = *(void (**)(void))(*(_QWORD *)(v17[17] + 8LL) + 32LL);
  if ( v18 )
  {
    if ( *((_DWORD *)v18 - 1) != -1056074712 )
      __break(0x8228u);
    v18();
  }
  v19 = v17[87];
  if ( v19 )
  {
    v20 = *(void (**)(void))(*(_QWORD *)(v19 + 8) + 32LL);
    if ( v20 )
    {
      if ( *((_DWORD *)v20 - 1) != -1056074712 )
        __break(0x8228u);
      v20();
    }
  }
  result = v17[187];
  if ( result )
  {
    v22 = *(void (**)(void))(*(_QWORD *)(result + 8) + 32LL);
    if ( v22 )
    {
      if ( *((_DWORD *)v22 - 1) != -1056074712 )
        __break(0x8228u);
      v22();
    }
    return 0;
  }
  return result;
}
