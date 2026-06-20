__int64 __fastcall wcd9378_suspend(__int64 a1)
{
  _QWORD *v1; // x20
  __int64 v2; // x21
  unsigned __int64 v7; // x9
  unsigned __int64 v14; // x10
  __int64 v15; // x8

  if ( !a1 )
    return 4294967277LL;
  v1 = *(_QWORD **)(a1 + 152);
  if ( !v1 )
    return 4294967274LL;
  v2 = *(_QWORD *)(*v1 + 144LL);
  if ( !v2 )
  {
    dev_err(a1, "%s: pdata is NULL\n", "wcd9378_suspend");
    return 4294967274LL;
  }
  if ( (v1[57] & 8) == 0 )
  {
    if ( (*((_BYTE *)v1 + 396) & 1) == 0 )
      goto LABEL_17;
    goto LABEL_8;
  }
  if ( (unsigned int)msm_cdc_disable_ondemand_supply(
                       *v1,
                       v1[399],
                       *(_QWORD *)(v2 + 64),
                       *(unsigned int *)(v2 + 72),
                       "cdc-vdd-buck") != -22 )
  {
    _X8 = v1 + 57;
    __asm { PRFM            #0x11, [X8] }
    do
      v14 = __ldxr(_X8);
    while ( __stxr(v14 & 0xFFFFFFFFFFFFFFF7LL, _X8) );
    if ( (*((_BYTE *)v1 + 396) & 1) == 0 )
    {
LABEL_17:
      v15 = v1[4];
      if ( !v15 || *(_DWORD *)(v15 + 208) )
        return 0;
    }
LABEL_8:
    msm_cdc_set_supplies_lpm_mode(*v1, v1[399], *(_QWORD *)(v2 + 64), *(unsigned int *)(v2 + 72), 1);
    _X8 = v1 + 57;
    __asm { PRFM            #0x11, [X8] }
    do
      v7 = __ldxr(_X8);
    while ( __stxr(v7 | 0x80, _X8) );
    return 0;
  }
  dev_err(a1, "%s: vdd buck is not disabled\n", "wcd9378_suspend");
  return 0;
}
