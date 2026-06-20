bool __fastcall policy_mgr_get_nan_sap_scc_on_lte_coex_chnl(__int64 a1)
{
  __int64 context; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  context = policy_mgr_get_context(a1);
  if ( context )
    return *(_BYTE *)(context + 2215) != 0;
  qdf_trace_msg(
    0x4Fu,
    2u,
    "%s: pm_ctx is NULL",
    v2,
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    "policy_mgr_get_nan_sap_scc_on_lte_coex_chnl");
  return 0;
}
