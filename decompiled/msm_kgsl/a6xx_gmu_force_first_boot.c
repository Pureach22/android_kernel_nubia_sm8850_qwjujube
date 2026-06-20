__int64 __fastcall a6xx_gmu_force_first_boot(__int64 result)
{
  __int64 v1; // x19
  int v2; // w20
  unsigned __int64 v9; // x10
  unsigned __int64 v11; // x10

  v1 = result;
  if ( !*(_QWORD *)(result - 224) )
  {
LABEL_11:
    _X8 = (unsigned __int64 *)(v1 - 352);
    __asm { PRFM            #0x11, [X8] }
    do
      v9 = __ldxr(_X8);
    while ( __stxr(v9 & 0xFFFFFFFFFFFFFFF7LL, _X8) );
    __asm { PRFM            #0x11, [X8] }
    do
      v11 = __ldxr(_X8);
    while ( __stxr(v11 & 0xFFFFFFFFFFFFFFDFLL, _X8) );
    return result;
  }
  ((void (__fastcall *)(__int64))kgsl_pwrctrl_enable_cx_gdsc)(result);
  gmu_core_enable_clks(v1, 0);
  v2 = *(_DWORD *)(*(_QWORD *)(v1 - 224) + 17664LL);
  __dsb(0xDu);
  gmu_core_disable_clks(v1);
  if ( *(_QWORD *)(v1 + 9024) && (*(_BYTE *)(v1 + 20657) & 2) != 0 )
  {
    __break(0x800u);
    if ( !*(_QWORD *)(v1 + 9000) )
      goto LABEL_7;
  }
  else if ( !*(_QWORD *)(v1 + 9000) )
  {
    goto LABEL_7;
  }
  if ( (*(_BYTE *)(v1 + 20657) & 2) != 0 )
    regulator_set_mode();
LABEL_7:
  kgsl_pwrctrl_disable_cx_gdsc(v1);
  if ( *(_QWORD *)(v1 + 9000) && (*(_BYTE *)(v1 + 20657) & 2) != 0 )
    regulator_set_mode();
  result = gmu_core_rdpm_cx_freq_update(v1, 0);
  if ( v2 != -2147483647 )
    goto LABEL_11;
  return result;
}
