bool __fastcall ipa_is_tx_pending(
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
  __int64 v11; // x19
  __int64 comp_private_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  if ( g_ipa_config && (*(_BYTE *)g_ipa_config & 1) != 0 )
  {
    v11 = *(_QWORD *)(a1 + 80);
    if ( (ipa_cb_is_ready() & 1) != 0 )
    {
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v11, 0x1Au);
      return wlan_ipa_is_tx_pending(comp_private_obj, v13, v14, v15, v16, v17, v18, v19, v20);
    }
  }
  else
  {
    qdf_trace_msg(0x61u, 8u, "%s: ipa is disabled", a2, a3, a4, a5, a6, a7, a8, a9, "ipa_is_tx_pending");
  }
  return 0;
}
