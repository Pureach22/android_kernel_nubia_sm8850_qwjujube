__int64 __fastcall ipa_send_mcc_scc_msg(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  if ( g_ipa_config && (*(_BYTE *)g_ipa_config & 1) != 0 )
  {
    v10 = *(_QWORD *)(a1 + 80);
    if ( (ipa_cb_is_ready(a1) & 1) != 0 && !wlan_objmgr_psoc_get_comp_private_obj(v10, 0x1Au) )
    {
      qdf_trace_msg(0x61u, 2u, "%s: IPA object is NULL", v11, v12, v13, v14, v15, v16, v17, v18, "ipa_send_mcc_scc_msg");
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(0x61u, 8u, "%s: ipa is disabled", a2, a3, a4, a5, a6, a7, a8, a9, "ipa_send_mcc_scc_msg");
  }
  return 0;
}
