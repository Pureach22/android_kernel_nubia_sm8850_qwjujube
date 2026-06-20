__int64 __fastcall policy_mgr_dfs_master_cfg_changed(__int64 a1, char a2)
{
  __int64 context; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x20
  unsigned __int8 v14; // w8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  context = policy_mgr_get_context(a1);
  if ( !context )
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: pm_ctx is NULL",
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             "policy_mgr_dfs_master_cfg_changed");
  v13 = context;
  v14 = *(_BYTE *)(cfg_psoc_get_values(a1) + 2736);
  if ( (a2 & 1) == 0 )
    v14 = 0;
  *(_BYTE *)(v13 + 2212) = v14;
  return qdf_trace_msg(
           0x4Fu,
           8u,
           "%s: sta_sap_scc_on_dfs_chnl %d, dfs_master_capable %d",
           v15,
           v16,
           v17,
           v18,
           v19,
           v20,
           v21,
           v22,
           "policy_mgr_dfs_master_cfg_changed",
           v14,
           a2 & 1);
}
