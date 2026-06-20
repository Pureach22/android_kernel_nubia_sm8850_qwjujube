__int64 __fastcall a6xx_snapshot_mvc(_QWORD *a1, unsigned int *a2, unsigned __int64 a3, __int64 *a4)
{
  __int64 v4; // x21
  unsigned int *v6; // x22
  unsigned int v8; // w9
  bool v9; // zf
  __int64 v10; // x9
  __int64 v11; // x20
  unsigned int v12; // w8
  unsigned int *v13; // x9
  unsigned __int64 v14; // x10
  unsigned int *v15; // x11
  unsigned int v16; // w13
  unsigned int v17; // w14
  unsigned __int64 v18; // x11
  bool v19; // cf
  unsigned int *i; // x12
  unsigned int v21; // t1
  unsigned int v22; // w8
  __int64 v24; // x8
  unsigned __int64 v25; // x25
  unsigned int v26; // w11
  unsigned __int64 v27; // x26
  __int64 v28; // x9
  __int64 v29; // x23
  unsigned int v30; // w20
  unsigned int v31; // w21
  unsigned __int64 v32; // x27
  unsigned int *v33; // x28
  unsigned int v35; // w20
  unsigned int v37; // [xsp+Ch] [xbp-4h]

  v4 = *a4;
  v6 = a2 + 2;
  if ( (crash_dump_valid & 1) != 0 )
  {
    if ( a3 <= 7 )
    {
      if ( (unsigned int)__ratelimit(&a6xx_snapshot_mvc__rs, "a6xx_snapshot_mvc") )
      {
LABEL_4:
        dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "MVC REGISTERS");
        return 0;
      }
      return 0;
    }
    v8 = *((_DWORD *)a4 + 2);
    *a2 = v8;
    a2[1] = *(_DWORD *)v4;
    if ( *(_DWORD *)(v4 + 16) )
    {
      v9 = v8 == 0;
      v10 = 36;
      v11 = 0;
      if ( v9 )
        v10 = 32;
      v12 = 0;
      v13 = (unsigned int *)(*(_QWORD *)(a6xx_crashdump_registers + 8) + *(unsigned int *)(v4 + v10));
      v14 = a3 - 8;
      while ( 1 )
      {
        v15 = (unsigned int *)(*(_QWORD *)(v4 + 8) + 4LL * (int)(2 * v12));
        v16 = *v15;
        v17 = v15[1];
        v18 = 4 * (v17 - *v15) + 12;
        v19 = v14 >= v18;
        v14 -= v18;
        if ( !v19 )
          break;
        *v6 = v16 | 0x80000000;
        v6[1] = v17;
        for ( i = v6 + 2; v16 <= v17; ++i )
        {
          v21 = *v13++;
          ++v16;
          *i = v21;
        }
        ++v12;
        v11 += v18;
        v6 = i;
        if ( v12 >= *(_DWORD *)(v4 + 16) )
          return v11 + 8;
      }
      if ( (unsigned int)__ratelimit(&a6xx_snapshot_mvc__rs_13, "a6xx_snapshot_mvc") )
        dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "MVC REGISTERS");
    }
    else
    {
      v11 = 0;
    }
    return v11 + 8;
  }
  else
  {
    if ( a3 <= 7 )
    {
      if ( (unsigned int)__ratelimit(&a6xx_legacy_snapshot_mvc__rs, "a6xx_legacy_snapshot_mvc") )
        goto LABEL_4;
      return 0;
    }
    v22 = *((_DWORD *)a4 + 2);
    *a2 = v22;
    a2[1] = *(_DWORD *)v4;
    kgsl_regmap_write(a1 + 1650, ((*(_DWORD *)v4 & 7) << 8) | (16 * v22) | v22);
    v24 = *(_QWORD *)(v4 + 24);
    if ( v24 )
      kgsl_regmap_write(a1 + 1650, *(unsigned int *)(v24 + 8));
    if ( *(_DWORD *)(v4 + 16) )
    {
      v25 = 0;
      v26 = 0;
      v27 = a3 - 8;
      while ( 1 )
      {
        v28 = *(_QWORD *)(v4 + 8);
        v29 = v4;
        v30 = *(_DWORD *)(v28 + 4LL * (unsigned int)(2 * v25));
        v31 = *(_DWORD *)(v28 + 4LL * ((2 * (_DWORD)v25) | 1u));
        v32 = 4 * (v31 - v30) + 12;
        v19 = v27 >= v32;
        v27 -= v32;
        if ( !v19 )
          break;
        v33 = v6 + 2;
        v37 = v26;
        *v6 = v30 | 0x80000000;
        for ( v6[1] = v31; v30 <= v31; ++v33 )
        {
          ++v30;
          *v33 = kgsl_regmap_read(a1 + 1650);
        }
        ++v25;
        v4 = v29;
        v6 = v33;
        v26 = v32 + v37;
        if ( v25 >= *(unsigned int *)(v29 + 16) )
          return v26 + 8LL;
      }
      v35 = v26;
      if ( (unsigned int)__ratelimit(&a6xx_legacy_snapshot_mvc__rs_14, "a6xx_legacy_snapshot_mvc") )
        dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "MVC REGISTERS");
      v26 = v35;
    }
    else
    {
      v26 = 0;
    }
    return v26 + 8LL;
  }
}
