bool __fastcall policy_mgr_is_sta_sap_scc_allowed_on_dfs_chan(__int64 a1)
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
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _BOOL4 v19; // w20
  const char *v20; // x3
  __int64 v21; // x0

  if ( !policy_mgr_get_context(a1) )
  {
    v20 = "policy_mgr_is_sta_sap_scc_allowed_on_dfs_chan";
LABEL_11:
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v2, v3, v4, v5, v6, v7, v8, v9, v20);
    return 0;
  }
  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v19 = *(_BYTE *)(context + 2212) != 0;
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: pm_ctx is NULL",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "policy_mgr_get_sta_sap_scc_on_dfs_chnl");
    v19 = 0;
  }
  v21 = policy_mgr_get_context(a1);
  if ( !v21 )
  {
    v20 = "policy_mgr_is_force_scc";
    goto LABEL_11;
  }
  return (unsigned int)*(unsigned __int8 *)(v21 + 2200) - 3 < 4 && v19;
}
