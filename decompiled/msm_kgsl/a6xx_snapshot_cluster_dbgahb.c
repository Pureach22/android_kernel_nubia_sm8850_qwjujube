__int64 __fastcall a6xx_snapshot_cluster_dbgahb(_QWORD *a1, _DWORD *a2, unsigned __int64 a3, __int64 *a4)
{
  __int64 v4; // x20
  unsigned int *v5; // x19
  int v7; // w9
  bool v8; // zf
  __int64 v9; // x9
  unsigned int v10; // w8
  unsigned int v11; // w22
  unsigned int *v12; // x9
  unsigned __int64 v13; // x10
  unsigned int *v14; // x11
  unsigned int v15; // w13
  unsigned int v16; // w14
  unsigned __int64 v17; // x11
  bool v18; // cf
  unsigned int *i; // x12
  unsigned int v20; // t1
  unsigned int v22; // w24
  unsigned int v23; // w10
  unsigned __int64 v24; // x25
  unsigned int *v25; // x8
  unsigned int v26; // w22
  unsigned int v27; // w28
  unsigned __int64 v28; // x27
  unsigned int *v29; // x21
  __int64 v31; // x8
  unsigned int v32; // w19
  unsigned int v35; // [xsp+Ch] [xbp-4h]

  v4 = *a4;
  v5 = a2 + 2;
  if ( (crash_dump_valid & 1) != 0 )
  {
    if ( a3 <= 7 )
    {
      if ( (unsigned int)__ratelimit(&a6xx_snapshot_cluster_dbgahb__rs, "a6xx_snapshot_cluster_dbgahb") )
        goto LABEL_37;
      return 0;
    }
    v7 = *((_DWORD *)a4 + 2);
    *a2 = v7;
    a2[1] = *(_DWORD *)v4;
    if ( *(_DWORD *)(v4 + 24) )
    {
      v8 = v7 == 0;
      v9 = 32;
      v10 = 0;
      if ( v8 )
        v9 = 28;
      v11 = 0;
      v12 = (unsigned int *)(*(_QWORD *)(a6xx_crashdump_registers + 8) + *(unsigned int *)(v4 + v9));
      v13 = a3 - 8;
      while ( 1 )
      {
        v14 = (unsigned int *)(*(_QWORD *)(v4 + 16) + 4LL * (int)(2 * v10));
        v15 = *v14;
        v16 = v14[1];
        v17 = 4 * (v16 - *v14) + 12;
        v18 = v13 >= v17;
        v13 -= v17;
        if ( !v18 )
          break;
        *v5 = v15 | 0x80000000;
        v5[1] = v16;
        for ( i = v5 + 2; v15 <= v16; ++i )
        {
          v20 = *v12++;
          ++v15;
          *i = v20;
        }
        ++v10;
        v11 += v17;
        v5 = i;
        if ( v10 >= *(_DWORD *)(v4 + 24) )
          goto LABEL_30;
      }
      if ( (unsigned int)__ratelimit(&a6xx_snapshot_cluster_dbgahb__rs_15, "a6xx_snapshot_cluster_dbgahb") )
        dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "MVC REGISTERS");
    }
    else
    {
      v11 = 0;
    }
LABEL_30:
    v31 = v11;
    return v31 + 8;
  }
  if ( *((_BYTE *)a1 + 11306) != 1 )
    return 0;
  if ( a3 > 7 )
  {
    *a2 = *((_DWORD *)a4 + 2);
    a2[1] = *(_DWORD *)v4;
    kgsl_regmap_write(a1 + 1650, ((*((_DWORD *)a4 + 2) << 9) + (*(_DWORD *)(v4 + 8) << 8)) & 0xFF00);
    __dsb(0xFu);
    if ( *(_DWORD *)(v4 + 24) )
    {
      v22 = 0;
      v23 = 0;
      v24 = a3 - 8;
      while ( 1 )
      {
        v25 = (unsigned int *)(*(_QWORD *)(v4 + 16) + 4LL * (int)(2 * v22));
        v27 = *v25;
        v26 = v25[1];
        v28 = 4 * (v26 - *v25) + 12;
        v18 = v24 >= v28;
        v24 -= v28;
        if ( !v18 )
          break;
        v29 = v5 + 2;
        v35 = v23;
        *v5 = v27 | 0x80000000;
        for ( v5[1] = v26; v27 <= v26; ++v29 )
        {
          ++v27;
          *v29 = kgsl_regmap_read(a1 + 1650);
        }
        ++v22;
        v5 = v29;
        v23 = v28 + v35;
        if ( v22 >= *(_DWORD *)(v4 + 24) )
        {
          v31 = v23;
          return v31 + 8;
        }
      }
      v32 = v23;
      if ( (unsigned int)__ratelimit(&a6xx_legacy_snapshot_cluster_dbgahb__rs_16, "a6xx_legacy_snapshot_cluster_dbgahb") )
        dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "MVC REGISTERS");
      v31 = v32;
    }
    else
    {
      v31 = 0;
    }
    return v31 + 8;
  }
  if ( !(unsigned int)__ratelimit(&a6xx_legacy_snapshot_cluster_dbgahb__rs, "a6xx_legacy_snapshot_cluster_dbgahb") )
    return 0;
LABEL_37:
  dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "REGISTERS");
  return 0;
}
