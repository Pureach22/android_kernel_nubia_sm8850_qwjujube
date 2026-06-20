unsigned __int64 __fastcall a6xx_snapshot_non_ctx_dbgahb(_QWORD *a1, int *a2, unsigned __int64 a3, __int64 a4)
{
  unsigned int *v6; // x22
  unsigned int v7; // w9
  __int64 v8; // x8
  int v9; // w10
  int v10; // w11
  int v11; // w12
  int v12; // w13
  int v13; // w11
  int v14; // w14
  int v15; // w15
  int v16; // w16
  int v17; // w17
  int v18; // w0
  unsigned __int64 v19; // x11
  __int64 v20; // x8
  int v21; // w23
  int *v22; // x9
  unsigned __int64 v23; // x10
  __int64 v24; // x14
  unsigned int v25; // w12
  unsigned int v26; // w13
  unsigned __int64 v27; // x14
  bool v28; // cf
  unsigned int v29; // t1
  int *v30; // x20
  unsigned __int64 v32; // x21
  int v33; // w12
  unsigned int v34; // w9
  int v35; // w10
  int v36; // w13
  unsigned int v38; // w8
  unsigned int i; // w24
  unsigned int *v40; // x9
  unsigned int v41; // w26
  unsigned int v42; // w27
  unsigned int *v43; // x28
  unsigned int v44; // w0

  v6 = (unsigned int *)(a2 + 1);
  if ( (crash_dump_valid & 1) != 0 )
  {
    if ( a3 <= 3 )
    {
      if ( (unsigned int)__ratelimit(&a6xx_snapshot_non_ctx_dbgahb__rs, "a6xx_snapshot_non_ctx_dbgahb") )
        goto LABEL_40;
      return 0;
    }
    v19 = *(unsigned int *)(a4 + 16);
    if ( (_DWORD)v19 )
    {
      v20 = 0;
      v21 = 0;
      v22 = (int *)(*(_QWORD *)(a6xx_crashdump_registers + 8) + *(unsigned int *)(a4 + 20));
      v23 = a3 - 4;
      while ( 1 )
      {
        v24 = *(_QWORD *)(a4 + 8);
        v25 = *(_DWORD *)(v24 + 4LL * (unsigned int)(2 * v20));
        v26 = *(_DWORD *)(v24 + 4LL * ((2 * (_DWORD)v20) | 1u));
        v27 = 8 * (v26 - v25) + 8;
        v28 = v23 >= v27;
        v23 -= v27;
        if ( !v28 )
          break;
        if ( v26 >= v25 )
        {
          do
          {
            *v6 = v25++;
            ++v21;
            v29 = *v22++;
            v6[1] = v29;
            v6 += 2;
          }
          while ( v25 <= v26 );
          v19 = *(unsigned int *)(a4 + 16);
        }
        if ( ++v20 >= v19 )
          goto LABEL_26;
      }
      v30 = a2;
      if ( (unsigned int)__ratelimit(&a6xx_snapshot_non_ctx_dbgahb__rs_17, "a6xx_snapshot_non_ctx_dbgahb") )
        dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "REGISTERS");
      a2 = v30;
    }
    else
    {
      v21 = 0;
    }
LABEL_26:
    *a2 = v21;
    return (8 * v21) | 4u;
  }
  if ( *((_BYTE *)a1 + 11306) != 1 )
    return 0;
  v7 = *(_DWORD *)(a4 + 16);
  if ( v7 )
  {
    v8 = *(_QWORD *)(a4 + 8);
    v9 = 0;
    if ( v7 == 1 )
    {
      v10 = 0;
    }
    else
    {
      v10 = 0;
      if ( v7 <= 0x40000000 )
      {
        v9 = v7 & 0x7FFFFFFE;
        v11 = 0;
        v12 = 0;
        v13 = 3;
        v14 = v7 & 0x7FFFFFFE;
        do
        {
          v15 = *(_DWORD *)(v8 + 4LL * (v13 - 3));
          v16 = *(_DWORD *)(v8 + 4LL * (v13 - 1));
          v17 = *(_DWORD *)(v8 + 4LL * (v13 - 2));
          v18 = *(_DWORD *)(v8 + 4LL * v13);
          v14 -= 2;
          v13 += 4;
          v11 = v11 - v15 + v17 + 1;
          v12 = v12 - v16 + v18 + 1;
        }
        while ( v14 );
        v10 = v12 + v11;
        if ( v7 == v9 )
          goto LABEL_30;
      }
    }
    v33 = 2 * v9;
    v34 = v7 - v9;
    do
    {
      v35 = *(_DWORD *)(v8 + 4LL * v33);
      --v34;
      v36 = *(_DWORD *)(v8 + 4LL * (v33 + 1));
      v33 += 2;
      v10 = v10 - v35 + v36 + 1;
    }
    while ( v34 );
  }
  else
  {
    v10 = 0;
  }
LABEL_30:
  v32 = (8 * v10) | 4;
  if ( v32 > a3 )
  {
    if ( (unsigned int)__ratelimit(&a6xx_legacy_snapshot_non_ctx_dbgahb__rs, "a6xx_legacy_snapshot_non_ctx_dbgahb") )
LABEL_40:
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "REGISTERS");
    return 0;
  }
  *a2 = v10;
  kgsl_regmap_write(a1 + 1650, (unsigned __int8)*(_DWORD *)(a4 + 4) << 8);
  v38 = *(_DWORD *)(a4 + 16);
  if ( v38 )
  {
    for ( i = 0; i < v38; ++i )
    {
      v40 = (unsigned int *)(*(_QWORD *)(a4 + 8) + 4LL * (int)(2 * i));
      v41 = *v40;
      v42 = v40[1];
      if ( *v40 <= v42 )
      {
        do
        {
          v43 = v6;
          v44 = kgsl_regmap_read(a1 + 1650);
          *v6 = v41;
          v6 += 2;
          ++v41;
          v43[1] = v44;
        }
        while ( v41 <= v42 );
        v38 = *(_DWORD *)(a4 + 16);
      }
    }
  }
  return v32;
}
