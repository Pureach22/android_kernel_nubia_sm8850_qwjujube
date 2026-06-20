__int64 __fastcall adreno_snapshot_dump_all_ibs(__int64 result, __int64 a2, __int64 a3)
{
  _QWORD *v5; // x21
  int v6; // w22
  int v7; // w8
  int v8; // w10
  int v9; // w11
  bool v10; // nf
  int v11; // w9
  int v12; // w8
  int v13; // w9
  int v14; // w9
  int v15; // w10
  int v16; // w9
  __int64 v17; // x12
  int v18; // w8
  __int64 v19; // x10
  int v20; // w9
  unsigned __int64 v21; // x8
  unsigned __int64 v22; // x3
  unsigned __int64 v23; // x4
  __int64 v24; // x9
  unsigned __int64 v25; // x10
  unsigned __int64 v26; // x8
  __int64 v27; // x9
  unsigned __int64 v28; // x10

  v5 = (_QWORD *)result;
  v6 = 0;
  do
  {
    v7 = *(_DWORD *)(a2 + 4LL * v6);
    if ( v7 > 1891270658 )
    {
      if ( v7 != 1891598339 && v7 != 1891270659 )
      {
LABEL_34:
        ++v6;
        continue;
      }
    }
    else if ( v7 != 1882357763 && v7 != 1882685443 )
    {
      goto LABEL_34;
    }
    v8 = v6 + 1;
    v9 = v6 + 3;
    v11 = -(v6 + 2);
    v10 = v11 < 0;
    v12 = (v6 + 2) & 0x1FFF;
    v6 += 4;
    v13 = v11 & 0x1FFF;
    if ( !v10 )
      v12 = -v13;
    v14 = -v8;
    v10 = -v8 < 0;
    v15 = v8 & 0x1FFF;
    v16 = v14 & 0x1FFF;
    v17 = *(unsigned int *)(a2 + 4LL * v12);
    if ( v10 )
      v18 = v15;
    else
      v18 = -v16;
    v19 = *(unsigned int *)(a2 + 4LL * v18);
    v20 = v9 & 0x1FFF;
    if ( v9 <= 0 )
      v20 = -(-v9 & 0x1FFF);
    v21 = v5[121];
    v22 = v19 | (v17 << 32);
    v23 = *(unsigned int *)(a2 + 4LL * v20);
    if ( v21 && v21 <= 0xFFFFFFFFFFFFF000LL )
    {
      v24 = v23 <= 1 ? 1LL : *(unsigned int *)(a2 + 4LL * v20);
      if ( !__CFADD__(v22, v24) )
      {
        v25 = *(_QWORD *)(v21 + 24);
        if ( v25 <= v22 && v24 + v22 <= *(_QWORD *)(v21 + 40) + v25 )
          continue;
      }
    }
    v26 = v5[2536];
    if ( v26 && v26 <= 0xFFFFFFFFFFFFF000LL )
    {
      v27 = v23 <= 1 ? 1LL : v23;
      if ( !__CFADD__(v22, v27) )
      {
        v28 = *(_QWORD *)(v26 + 24);
        if ( v28 <= v22 && v27 + v22 <= *(_QWORD *)(v26 + 40) + v28 )
          continue;
      }
    }
    result = adreno_parse_ib(v5, a3, *(_QWORD *)(a3 + 224), v22, v23);
  }
  while ( v6 < 0x2000 );
  return result;
}
