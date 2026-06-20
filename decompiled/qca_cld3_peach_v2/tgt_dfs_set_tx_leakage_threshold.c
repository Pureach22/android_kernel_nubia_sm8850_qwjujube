__int64 __fastcall tgt_dfs_set_tx_leakage_threshold(
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
  __int64 v9; // x19
  __int64 dfs_obj; // x0
  __int64 v11; // x20
  __int64 v12; // x4
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  const char *v22; // x2
  int v23; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 80);
  v23 = 0;
  if ( !v9 )
  {
    v22 = "WLAN_DEBUG_DFS_ALWAYS : %s: psoc is null";
LABEL_6:
    qdf_trace_msg(0x27u, 2u, v22, a2, a3, a4, a5, a6, a7, a8, a9, "tgt_dfs_set_tx_leakage_threshold");
    result = 16;
    goto LABEL_7;
  }
  dfs_obj = wlan_pdev_get_dfs_obj(a1);
  if ( !dfs_obj )
  {
    v22 = "WLAN_DEBUG_DFS_ALWAYS : %s: dfs is NULL";
    goto LABEL_6;
  }
  v11 = dfs_obj;
  ucfg_mlme_get_sap_tx_leakage_threshold(v9, &v23);
  v12 = (unsigned __int16)v23;
  *(_WORD *)(v11 + 14984) = v23;
  qdf_trace_msg(
    0x27u,
    8u,
    "WLAN_DEBUG_DFS_ALWAYS : %s: dfs tx_leakage_threshold = %d",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "tgt_dfs_set_tx_leakage_threshold",
    v12);
  result = 0;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
