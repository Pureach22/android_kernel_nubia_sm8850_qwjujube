__int64 __fastcall ipa_uc_ol_init(
        __int64 a1,
        __int64 a2,
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
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  if ( !g_ipa_config || (*(_BYTE *)g_ipa_config & 1) == 0 )
  {
    qdf_trace_msg(0x61u, 8u, "%s: ipa is disabled", a3, a4, a5, a6, a7, a8, a9, a10, "ipa_uc_ol_init");
    return 0;
  }
  if ( (ipa_cb_is_ready() & 1) == 0 )
    return 0;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Au);
  if ( comp_private_obj )
    return wlan_ipa_uc_ol_init(comp_private_obj, a2, v14, v15, v16, v17, v18, v19, v20, v21);
  qdf_trace_msg(0x61u, 2u, "%s: IPA object is NULL", v14, v15, v16, v17, v18, v19, v20, v21, "ipa_uc_ol_init");
  return 16;
}
