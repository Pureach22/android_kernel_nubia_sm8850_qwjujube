__int64 __fastcall wcd939x_resume(__int64 a1)
{
  unsigned __int64 *v1; // x20
  __int64 v3; // x21
  unsigned __int64 v11; // x10

  if ( !a1 )
    return 4294967277LL;
  v1 = *(unsigned __int64 **)(a1 + 152);
  if ( !v1 )
    return 4294967274LL;
  v3 = *(_QWORD *)(*v1 + 144);
  if ( !v3 )
  {
    if ( (unsigned int)__ratelimit(&wcd939x_resume__rs, "wcd939x_resume") )
      dev_err(a1, "%s: pdata is NULL\n", "wcd939x_resume");
    return 4294967274LL;
  }
  if ( (msm_cdc_is_ondemand_supply(*v1, v1[389], *(_QWORD *)(v3 + 280), *(unsigned int *)(v3 + 288), "cdc-vdd-px") & 1) != 0
    && (msm_cdc_supply_supports_retention_mode(
          *v1,
          v1[389],
          *(_QWORD *)(v3 + 280),
          *(unsigned int *)(v3 + 288),
          "cdc-vdd-px")
      & 1) != 0
    && (msm_cdc_check_supply_vote(*v1, v1[389], *(_QWORD *)(v3 + 280), *(unsigned int *)(v3 + 288), "cdc-vdd-px") & 1) == 0 )
  {
    msm_cdc_enable_ondemand_supply(*v1, v1[389], *(_QWORD *)(v3 + 280), *(unsigned int *)(v3 + 288), "cdc-vdd-px");
  }
  if ( (v1[47] & 0x100) != 0 )
  {
    msm_cdc_set_supplies_lpm_mode(*v1, v1[389], *(_QWORD *)(v3 + 280), *(unsigned int *)(v3 + 288), 0);
    _X8 = v1 + 47;
    __asm { PRFM            #0x11, [X8] }
    do
      v11 = __ldxr(_X8);
    while ( __stxr(v11 & 0xFFFFFFFFFFFFFEFFLL, _X8) );
  }
  return 0;
}
