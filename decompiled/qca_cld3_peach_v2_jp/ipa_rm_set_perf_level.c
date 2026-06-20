__int64 __fastcall ipa_rm_set_perf_level(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x21
  __int64 comp_private_obj; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  if ( !g_ipa_config || (*(_BYTE *)g_ipa_config & 1) == 0 )
  {
    qdf_trace_msg(0x61u, 8u, "%s: ipa is disabled", a4, a5, a6, a7, a8, a9, a10, a11, "ipa_rm_set_perf_level");
    return 0;
  }
  v12 = *(_QWORD *)(a1 + 80);
  if ( (ipa_cb_is_ready() & 1) == 0 )
    return 0;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v12, 0x1Au);
  if ( comp_private_obj )
    return wlan_ipa_set_perf_level(comp_private_obj, a2, a3);
  qdf_trace_msg(0x61u, 2u, "%s: IPA object is NULL", v16, v17, v18, v19, v20, v21, v22, v23, "ipa_rm_set_perf_level");
  return 16;
}
