__int64 __fastcall regmap_swr_write(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v4; // x21
  __int64 v7; // x23
  unsigned __int64 v8; // x2
  __int64 regmap; // x0
  unsigned __int64 v10; // x23
  unsigned __int64 v11; // x24
  __int64 v12; // x22
  __int64 v13; // x0
  __int64 v14; // x25
  unsigned __int64 v15; // x9
  int v16; // w8
  char v17; // w10
  unsigned int v18; // w20
  const char *v19; // x1
  const char *v20; // x2
  unsigned __int64 StatusReg; // x25
  __int64 v23; // x26

  v4 = a1 - 72;
  if ( a1 )
    v7 = a1 - 72;
  else
    v7 = 0;
  if ( !((__int64 (*)(void))dev_get_regmap)() )
  {
    if ( !(unsigned int)__ratelimit(&regmap_swr_write__rs, "regmap_swr_write") )
      return 4294967274LL;
    v19 = "%s: regmap is NULL\n";
LABEL_30:
    v20 = "regmap_swr_write";
LABEL_31:
    dev_err(a1, v19, v20);
    return 4294967274LL;
  }
  if ( !v7 )
  {
    if ( !(unsigned int)__ratelimit(&regmap_swr_write__rs_2, "regmap_swr_write") )
      return 4294967274LL;
    v19 = "%s: swr is NULL\n";
    goto LABEL_30;
  }
  if ( *(_BYTE *)(v7 + 993) )
    v8 = 4;
  else
    v8 = 2;
  if ( a3 < v8 )
    __break(0x800u);
  if ( ((unsigned int)v8 | 1) >= a3 )
    return regmap_swr_gather_write(a1, a2, v8, a2 + v8);
  regmap = dev_get_regmap(a1, 0);
  if ( !a1 || !v4 )
  {
    if ( (unsigned int)__ratelimit(&regmap_swr_raw_multi_reg_write__rs, "regmap_swr_raw_multi_reg_write") )
    {
      v19 = "%s: swr device is NULL\n";
LABEL_38:
      v20 = "regmap_swr_raw_multi_reg_write";
      goto LABEL_31;
    }
    return 4294967274LL;
  }
  if ( !regmap )
  {
    if ( !(unsigned int)__ratelimit(&regmap_swr_raw_multi_reg_write__rs_5, "regmap_swr_raw_multi_reg_write") )
      return 4294967274LL;
    v19 = "%s: regmap is NULL\n";
    goto LABEL_38;
  }
  v10 = a3 / 3;
  v11 = 2 * (a3 / 3);
  v12 = _kmalloc_noprof(v11, 3520);
  if ( !v12 )
    return 4294967284LL;
  while ( 2 )
  {
    v13 = _kmalloc_noprof(v10, 3520);
    v14 = v13;
    if ( v13 )
    {
      v15 = 0;
      v16 = 1;
      while ( (v15 & 0x8000000000000000LL) == 0 )
      {
        if ( v11 <= 2 * v15 )
          break;
        *(_WORD *)(v12 + 2 * v15) = *(_WORD *)a2;
        if ( v10 <= v15 )
          break;
        v17 = *(_BYTE *)(a2 + 2);
        a2 += 3;
        *(_BYTE *)(v13 + v15) = v17;
        v15 = v16++;
        if ( v10 <= v15 )
        {
          v18 = swr_bulk_write(v4, *(unsigned __int8 *)(a1 - 8), v12, v13, v10);
          if ( v18 )
          {
            if ( (unsigned int)__ratelimit(&regmap_swr_raw_multi_reg_write__rs_10, "regmap_swr_raw_multi_reg_write") )
              dev_err(a1, "%s: multi reg write failed\n", "regmap_swr_raw_multi_reg_write");
          }
          kfree(v14);
          goto LABEL_42;
        }
      }
      __break(1u);
      v11 = 2 * v10;
      StatusReg = _ReadStatusReg(SP_EL0);
      v23 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
      v12 = _kmalloc_noprof(2 * v10, 3520);
      *(_QWORD *)(StatusReg + 80) = v23;
      if ( v12 )
        continue;
      return 4294967284LL;
    }
    break;
  }
  v18 = -12;
LABEL_42:
  kfree(v12);
  return v18;
}
