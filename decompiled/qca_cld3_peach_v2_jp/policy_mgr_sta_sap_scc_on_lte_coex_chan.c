bool __fastcall policy_mgr_sta_sap_scc_on_lte_coex_chan(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 context; // x0
  const char *v12; // x2
  const char *v13; // x3

  if ( policy_mgr_get_context(a1) )
  {
    context = policy_mgr_get_context(a1);
    if ( context )
      return *(_BYTE *)(context + 2213) != 0;
    v12 = "%s: pm_ctx is NULL";
    v13 = "policy_mgr_get_sta_sap_scc_lte_coex_chnl";
  }
  else
  {
    v12 = "%s: Invalid Context";
    v13 = "policy_mgr_sta_sap_scc_on_lte_coex_chan";
  }
  qdf_trace_msg(0x4Fu, 2u, v12, v2, v3, v4, v5, v6, v7, v8, v9, v13);
  return 0;
}
