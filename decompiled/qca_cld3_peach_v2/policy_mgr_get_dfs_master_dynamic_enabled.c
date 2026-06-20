__int64 __fastcall policy_mgr_get_dfs_master_dynamic_enabled(__int64 a1)
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
  __int64 v10; // x19
  char v11; // w8

  context = policy_mgr_get_context(a1);
  if ( !context )
  {
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
      "policy_mgr_get_dfs_master_dynamic_enabled");
    goto LABEL_5;
  }
  if ( *(_BYTE *)(context + 2661) != 1 )
  {
LABEL_5:
    v11 = 1;
    return v11 & 1;
  }
  v10 = context;
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: sta_sap_scc_on_dfs_chnl %d enable %d",
    v2,
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    "policy_mgr_get_dfs_master_dynamic_enabled",
    *(unsigned __int8 *)(context + 2212),
    0);
  v11 = *(_BYTE *)(v10 + 2661) ^ 1;
  return v11 & 1;
}
