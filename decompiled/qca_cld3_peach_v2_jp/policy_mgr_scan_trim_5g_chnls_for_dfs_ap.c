__int64 __fastcall policy_mgr_scan_trim_5g_chnls_for_dfs_ap(__int64 a1, unsigned int *a2)
{
  unsigned int v4; // w19
  __int64 context; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  int v14; // w21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 result; // x0
  const char *v34; // x3
  unsigned int v35; // [xsp+4h] [xbp-1Ch] BYREF
  unsigned int v36; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v37[4]; // [xsp+Ch] [xbp-14h] BYREF
  unsigned int v38; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v39; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v40; // [xsp+18h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v39 = 0;
  v38 = 0;
  v36 = 0;
  policy_mgr_is_any_dfs_beaconing_session_present(a1, &v39, &v36);
  v4 = v39;
  if ( !v39 )
    goto LABEL_17;
  *a2 = v39;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: pm_ctx is NULL",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "policy_mgr_get_sta_sap_scc_on_dfs_chnl");
    goto LABEL_17;
  }
  v14 = *(unsigned __int8 *)(context + 2212);
  v37[0] = 0;
  v35 = 0;
  if ( (policy_mgr_is_sta_present_on_dfs_channel(a1, v37, &v38, &v35) & 1) == 0
    || (policy_mgr_is_hw_dbs_capable(a1) & 1) != 0
    || !v14 )
  {
    if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) == 0
      || (policy_mgr_is_current_hwmode_dbs(a1) & 1) != 0
      || policy_mgr_is_dual_mac_disabled_in_ini(a1) )
    {
      goto LABEL_20;
    }
    v31 = policy_mgr_get_context(a1);
    if ( v31 )
    {
      if ( (*(_BYTE *)(v31 + 1515) & 0x40) == 0 || policy_mgr_is_dual_mac_disabled_in_ini(a1) )
        goto LABEL_20;
      v32 = policy_mgr_get_context(a1);
      if ( v32 )
      {
        if ( (*(_BYTE *)(v32 + 1515) & 0x20) != 0 )
          goto LABEL_17;
LABEL_20:
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: scan skip 5g chan due to dfs ap(ch %d / ch_width %d) present",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "policy_mgr_scan_trim_5g_chnls_for_dfs_ap",
          v4,
          v36);
        result = 1;
        goto LABEL_21;
      }
      v34 = "policy_mgr_get_single_mac_scan_with_dfs_config";
    }
    else
    {
      v34 = "policy_mgr_get_dbs_plus_agile_scan_config";
    }
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v23, v24, v25, v26, v27, v28, v29, v30, v34);
    goto LABEL_20;
  }
  qdf_trace_msg(
    0x4Fu,
    2u,
    "DFS STA present vdev_id %d ch_feq %d ch_width %d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v37[0],
    v38,
    v35);
LABEL_17:
  result = 0;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
