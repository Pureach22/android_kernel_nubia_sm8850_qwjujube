unsigned __int64 __fastcall a6xx_snapshot_rscc_registers(_QWORD *a1, int *a2, unsigned __int64 a3, __int64 *a4)
{
  __int64 v8; // x0
  unsigned int v9; // w9
  __int64 v10; // x8
  int v11; // w10
  int v12; // w11
  int v13; // w12
  int v14; // w13
  int v15; // w10
  int v16; // w14
  int v17; // w15
  int v18; // w16
  int v19; // w17
  int v20; // w1
  unsigned __int64 v21; // x8
  int v22; // w12
  unsigned int v23; // w11
  int v24; // w13
  int v25; // w14
  unsigned int v26; // w11
  unsigned int *v27; // x12
  unsigned int *v28; // x14
  unsigned int v29; // w13
  unsigned int v30; // w14
  int v31; // w9
  _DWORD *v32; // x15

  v8 = to_a6xx_gmu((__int64)a1);
  v9 = *((_DWORD *)a4 + 2);
  if ( v9 )
  {
    v10 = *a4;
    v11 = 0;
    if ( v9 == 1 )
    {
      v12 = 0;
    }
    else
    {
      v12 = 0;
      if ( v9 <= 0x40000000 )
      {
        v12 = v9 & 0x7FFFFFFE;
        v13 = 0;
        v14 = 0;
        v15 = 3;
        v16 = v9 & 0x7FFFFFFE;
        do
        {
          v17 = *(_DWORD *)(v10 + 4LL * (v15 - 3));
          v18 = *(_DWORD *)(v10 + 4LL * (v15 - 1));
          v19 = *(_DWORD *)(v10 + 4LL * (v15 - 2));
          v20 = *(_DWORD *)(v10 + 4LL * v15);
          v16 -= 2;
          v15 += 4;
          v13 = v13 - v17 + v19 + 1;
          v14 = v14 - v18 + v20 + 1;
        }
        while ( v16 );
        v11 = v14 + v13;
        if ( v9 == v12 )
          goto LABEL_13;
      }
    }
    v22 = 2 * v12;
    v23 = v9 - v12;
    do
    {
      v24 = *(_DWORD *)(v10 + 4LL * v22);
      --v23;
      v25 = *(_DWORD *)(v10 + 4LL * (v22 + 1));
      v22 += 2;
      v11 = v11 - v24 + v25 + 1;
    }
    while ( v23 );
LABEL_13:
    v21 = (8 * v11) | 4;
    if ( v21 > a3 )
      goto LABEL_14;
    v26 = 0;
    v27 = (unsigned int *)(a2 + 1);
    do
    {
      v28 = (unsigned int *)(*a4 + 4LL * (int)(2 * v26));
      v29 = *v28;
      v30 = v28[1];
      if ( v29 <= v30 )
      {
        v31 = 4 * v29 - 917504;
        do
        {
          v32 = (_DWORD *)(*(_QWORD *)(v8 + 1304) + v31);
          v31 += 4;
          LODWORD(v32) = *v32;
          *v27 = v29;
          v27[1] = (unsigned int)v32;
          v27 += 2;
          ++v29;
        }
        while ( v29 <= v30 );
        v9 = *((_DWORD *)a4 + 2);
      }
      ++v26;
    }
    while ( v26 < v9 );
LABEL_23:
    *a2 = v11;
    return v21;
  }
  if ( a3 >= 4 )
  {
    v11 = 0;
    v21 = 4;
    goto LABEL_23;
  }
LABEL_14:
  if ( (unsigned int)__ratelimit(&a6xx_snapshot_rscc_registers__rs, "a6xx_snapshot_rscc_registers") )
    dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "RSCC REGISTERS");
  return 0;
}
