__int64 __fastcall tgt_cfr_aoa_for_rcc_support_set(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  const char *v12; // x4
  const char *v14; // x2

  if ( !a1 )
  {
    v14 = "%s: CFR: NULL PSOC!!";
LABEL_9:
    qdf_trace_msg(0x6Au, 2u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "tgt_cfr_aoa_for_rcc_support_set");
    return 4;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Eu);
  if ( !comp_private_obj )
  {
    v14 = "%s: Failed to get CFR component priv obj!!";
    goto LABEL_9;
  }
  *(_BYTE *)(comp_private_obj + 12) = a2 != 0;
  if ( a2 )
    v12 = "enabled";
  else
    v12 = "disabled";
  qdf_trace_msg(
    0x6Au,
    8u,
    "%s: CFR: aoa_for_rcc_support is %s\n",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "tgt_cfr_aoa_for_rcc_support_set",
    v12);
  return 0;
}
