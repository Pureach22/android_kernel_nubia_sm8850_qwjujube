__int64 __fastcall regmap_swr_read(__int64 a1, _DWORD *a2, __int64 a3, __int64 a4, unsigned int a5)
{
  __int64 v10; // x24
  unsigned int v11; // w0
  unsigned int v12; // w20
  __int64 result; // x0
  unsigned __int16 v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
    v10 = a1 - 72;
  else
    v10 = 0;
  v14 = 0;
  if ( !dev_get_regmap(a1, 0) )
  {
    if ( (unsigned int)__ratelimit(&regmap_swr_read__rs, "regmap_swr_read") )
    {
      dev_err(a1, "%s: regmap is NULL\n", "regmap_swr_read");
LABEL_16:
      result = 4294967274LL;
      goto LABEL_22;
    }
LABEL_18:
    result = 4294967274LL;
    goto LABEL_22;
  }
  if ( !v10 )
  {
    if ( (unsigned int)__ratelimit(&regmap_swr_read__rs_19, "regmap_swr_read") )
    {
      dev_err(a1, "%s: swr is NULL\n", "regmap_swr_read");
      goto LABEL_16;
    }
    goto LABEL_18;
  }
  if ( a3 != 2 && a3 != 4 )
  {
    if ( (unsigned int)__ratelimit(&regmap_swr_read__rs_20, "regmap_swr_read") )
    {
      dev_err(a1, "%s: reg size %zd bytes not supported\n", "regmap_swr_read", a3);
      result = 4294967274LL;
      goto LABEL_22;
    }
    goto LABEL_18;
  }
  mutex_lock(&swr_rw_lock);
  v11 = regmap_swr_reg_address_get(v10, &v14, a2, a3);
  if ( (v11 & 0x80000000) != 0 )
  {
    v12 = v11;
    if ( (unsigned int)__ratelimit(&regmap_swr_read__rs_21, "regmap_swr_read") )
      dev_err(a1, "%s: regmap_swr_reg_address_get failed, reg: 0x%x\n", "regmap_swr_read", *a2);
  }
  else
  {
    v12 = swr_read(v10, *(unsigned __int8 *)(v10 + 64), v14, a4, a5);
    if ( (v12 & 0x80000000) != 0 && (unsigned int)__ratelimit(&regmap_swr_read__rs_23, "regmap_swr_read") )
      dev_err(a1, "%s: codec reg 0x%x read failed %d\n", "regmap_swr_read", v14, v12);
  }
  mutex_unlock(&swr_rw_lock);
  result = v12;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
