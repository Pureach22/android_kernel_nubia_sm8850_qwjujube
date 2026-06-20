__int64 __fastcall wcd9378_resume(__int64 a1)
{
  unsigned __int64 *v1; // x19
  __int64 v2; // x9
  unsigned __int64 v10; // x10

  if ( !a1 )
    return 4294967277LL;
  v1 = *(unsigned __int64 **)(a1 + 152);
  if ( !v1 )
    return 4294967274LL;
  v2 = *(_QWORD *)(*v1 + 144);
  if ( !v2 )
  {
    dev_err(a1, "%s: pdata is NULL\n", "wcd9378_resume");
    return 4294967274LL;
  }
  if ( (v1[57] & 0x80) != 0 )
  {
    msm_cdc_set_supplies_lpm_mode(*v1, v1[399], *(_QWORD *)(v2 + 64), *(unsigned int *)(v2 + 72), 0);
    _X8 = v1 + 57;
    __asm { PRFM            #0x11, [X8] }
    do
      v10 = __ldxr(_X8);
    while ( __stxr(v10 & 0xFFFFFFFFFFFFFF7FLL, _X8) );
  }
  return 0;
}
