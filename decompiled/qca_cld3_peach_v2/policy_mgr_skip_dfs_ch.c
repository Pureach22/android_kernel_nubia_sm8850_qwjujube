__int64 __fastcall policy_mgr_skip_dfs_ch(__int64 a1, _BYTE *a2)
{
  unsigned int dfs_master_capability; // w19
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  char v13; // w8
  bool is_sta_sap_scc_allowed_on_dfs_chan; // w22
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  const char *v23; // x2
  _BYTE v25[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+8h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25[0] = 0;
  dfs_master_capability = ucfg_mlme_get_dfs_master_capability(a1, v25);
  if ( !dfs_master_capability )
  {
    v13 = v25[0];
    *a2 = 0;
    if ( (v13 & 1) != 0 )
    {
      is_sta_sap_scc_allowed_on_dfs_chan = policy_mgr_is_sta_sap_scc_allowed_on_dfs_chan(a1);
      if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) != 0 )
      {
        if ( (policy_mgr_is_special_mode_active_5g(a1, 2) & 1) != 0 )
        {
          if ( is_sta_sap_scc_allowed_on_dfs_chan )
            goto LABEL_15;
        }
        else if ( is_sta_sap_scc_allowed_on_dfs_chan | ((policy_mgr_is_special_mode_active_5g(a1, 0) & 1) == 0) )
        {
          goto LABEL_15;
        }
        v23 = "%s: skip DFS ch from pcl for DBS SAP/Go";
      }
      else
      {
        if ( (unsigned int)policy_mgr_mode_specific_connection_count(a1, 0, nullptr) == 0
          || is_sta_sap_scc_allowed_on_dfs_chan )
        {
          goto LABEL_15;
        }
        v23 = "%s: skip DFS ch from pcl for non-DBS SAP/Go";
      }
      qdf_trace_msg(0x4Fu, 8u, v23, v15, v16, v17, v18, v19, v20, v21, v22, "policy_mgr_skip_dfs_ch");
    }
    else
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: skip DFS ch for SAP/Go dfs master cap %d",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "policy_mgr_skip_dfs_ch",
        0);
    }
    *a2 = 1;
    goto LABEL_15;
  }
  qdf_trace_msg(
    0x4Fu,
    2u,
    "%s: failed to get dfs master capable",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "policy_mgr_skip_dfs_ch");
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return dfs_master_capability;
}
