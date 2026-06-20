__int64 __fastcall tgt_dfs_radar_enable(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  __int64 dfs_obj; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x8
  __int64 v16; // x8
  _DWORD *v17; // x8
  __int64 result; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x4
  unsigned int v28; // w19
  const char *v29; // x2
  unsigned int v30; // w1

  dfs_obj = wlan_pdev_get_dfs_obj(a1);
  if ( !dfs_obj )
  {
    v29 = "WLAN_DEBUG_DFS_ALWAYS : %s: dfs is NULL";
LABEL_15:
    v30 = 2;
LABEL_16:
    qdf_trace_msg(0x27u, v30, v29, v7, v8, v9, v10, v11, v12, v13, v14, "tgt_dfs_radar_enable");
    return 16;
  }
  if ( (*(_BYTE *)(dfs_obj + 14954) & 1) == 0 )
  {
    if ( (a4 & 1) != 0 )
      return 0;
    v29 = "WLAN_DEBUG_DFS_ALWAYS : %s: Disabling dfs not allowed for non-offload chips";
    v30 = 8;
    goto LABEL_16;
  }
  v15 = *(_QWORD *)(a1 + 80);
  if ( !v15 )
  {
    v29 = "WLAN_DEBUG_DFS_ALWAYS : %s: psoc is null";
    goto LABEL_15;
  }
  v16 = *(_QWORD *)(v15 + 2128);
  if ( !v16 )
  {
    qdf_trace_msg(
      0x27u,
      2u,
      "WLAN_DEBUG_DFS_ALWAYS : %s: tx_ops is null",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "wlan_psoc_get_dfs_txops");
    v29 = "WLAN_DEBUG_DFS_ALWAYS : %s: dfs_tx_ops is null";
    goto LABEL_15;
  }
  v17 = *(_DWORD **)(v16 + 1280);
  if ( *(v17 - 1) != 1845289881 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, _QWORD))v17)(a1, a4 & 1);
  if ( (_DWORD)result )
  {
    v27 = *(unsigned __int8 *)(a1 + 40);
    v28 = result;
    qdf_trace_msg(
      0x27u,
      2u,
      "WLAN_DEBUG_DFS_ALWAYS : %s: Failed to enable dfs offload, pdev_id: %d",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "tgt_dfs_radar_enable",
      v27);
    return v28;
  }
  return result;
}
