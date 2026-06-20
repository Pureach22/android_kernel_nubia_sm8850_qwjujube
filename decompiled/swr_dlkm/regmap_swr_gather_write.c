__int64 __fastcall regmap_swr_gather_write(__int64 a1, __int64 a2, __int64 a3, __int64 a4, unsigned __int64 a5)
{
  __int64 v10; // x22
  int v11; // w0
  __int64 v12; // x8
  int v13; // w23
  __int64 result; // x0
  int v15; // w20
  unsigned int v16; // w19
  unsigned __int16 v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
    v10 = a1 - 72;
  else
    v10 = 0;
  v17 = 0;
  if ( !dev_get_regmap(a1, 0) )
  {
    if ( (unsigned int)__ratelimit(&regmap_swr_gather_write__rs, "regmap_swr_gather_write") )
    {
      dev_err(a1, "%s: regmap is NULL\n", "regmap_swr_gather_write");
LABEL_18:
      result = 4294967274LL;
      goto LABEL_25;
    }
LABEL_20:
    result = 4294967274LL;
    goto LABEL_25;
  }
  if ( !v10 )
  {
    if ( (unsigned int)__ratelimit(&regmap_swr_gather_write__rs_12, "regmap_swr_gather_write") )
    {
      dev_err(a1, "%s: swr device is NULL\n", "regmap_swr_gather_write");
      goto LABEL_18;
    }
    goto LABEL_20;
  }
  if ( a3 != 2 && a3 != 4 )
  {
    if ( (unsigned int)__ratelimit(&regmap_swr_gather_write__rs_13, "regmap_swr_gather_write") )
    {
      dev_err(a1, "%s: reg size %zd bytes not supported\n", "regmap_swr_gather_write", a3);
      result = 4294967274LL;
      goto LABEL_25;
    }
    goto LABEL_20;
  }
  mutex_lock(&swr_rw_lock);
  v11 = regmap_swr_reg_address_get(v10, &v17, a2, a3);
  if ( (v11 & 0x80000000) == 0 && a5 )
  {
    v12 = 0;
    v13 = 0;
    while ( 1 )
    {
      v11 = swr_write(v10, *(unsigned __int8 *)(v10 + 64), (unsigned int)v17 + v13, a4 + v12);
      if ( v11 < 0 )
        break;
      v12 = ++v13;
      if ( v13 >= a5 )
        goto LABEL_24;
    }
    v15 = v11;
    if ( (unsigned int)__ratelimit(&regmap_swr_gather_write__rs_15, "regmap_swr_gather_write") )
      dev_err(a1, "%s: write reg 0x%x failed, err %d\n", "regmap_swr_gather_write", v17 + v13, v15);
    v11 = v15;
  }
LABEL_24:
  v16 = v11;
  mutex_unlock(&swr_rw_lock);
  result = v16;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
