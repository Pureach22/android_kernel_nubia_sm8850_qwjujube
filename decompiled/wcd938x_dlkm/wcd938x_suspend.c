__int64 __fastcall wcd938x_suspend(__int64 a1)
{
  unsigned __int64 *v1; // x20
  __int64 v2; // x21
  __int64 result; // x0
  unsigned __int64 v8; // x9
  unsigned __int64 v15; // x10
  unsigned __int64 v16; // x8

  if ( !a1 )
    return 4294967277LL;
  v1 = *(unsigned __int64 **)(a1 + 152);
  if ( !v1 )
    return 4294967274LL;
  v2 = *(_QWORD *)(*v1 + 144);
  if ( !v2 )
  {
    if ( (unsigned int)__ratelimit(&wcd938x_suspend__rs, "wcd938x_suspend") )
    {
      dev_err(a1, "%s: pdata is NULL\n", "wcd938x_suspend");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  if ( (v1[44] & 0x10) != 0 )
  {
    if ( (unsigned int)msm_cdc_disable_ondemand_supply(
                         *v1,
                         v1[386],
                         *(_QWORD *)(v2 + 56),
                         *(unsigned int *)(v2 + 64),
                         "cdc-vdd-buck") == -22 )
    {
      result = __ratelimit(&wcd938x_suspend__rs_424, "wcd938x_suspend");
      if ( !(_DWORD)result )
        return result;
      dev_err(a1, "%s: vdd buck is not disabled\n", "wcd938x_suspend");
      return 0;
    }
    _X8 = v1 + 44;
    __asm { PRFM            #0x11, [X8] }
    do
      v15 = __ldxr(_X8);
    while ( __stxr(v15 & 0xFFFFFFFFFFFFFFEFLL, _X8) );
    if ( (*((_BYTE *)v1 + 292) & 1) == 0 )
    {
LABEL_19:
      v16 = v1[2];
      if ( !v16 || *(_DWORD *)(v16 + 208) )
        return 0;
    }
  }
  else if ( (*((_BYTE *)v1 + 292) & 1) == 0 )
  {
    goto LABEL_19;
  }
  msm_cdc_set_supplies_lpm_mode(*v1, v1[386], *(_QWORD *)(v2 + 56), *(unsigned int *)(v2 + 64), 1);
  _X8 = v1 + 44;
  __asm { PRFM            #0x11, [X8] }
  do
    v8 = __ldxr(_X8);
  while ( __stxr(v8 | 0x100, _X8) );
  return 0;
}
