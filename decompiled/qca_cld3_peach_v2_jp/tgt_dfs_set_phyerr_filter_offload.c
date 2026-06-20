__int64 __fastcall tgt_dfs_set_phyerr_filter_offload(
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
  __int64 v9; // x20
  __int64 comp_private_obj; // x0
  __int64 v12; // x9
  __int64 (__fastcall *v13)(__int64, __int64); // x8
  __int64 v14; // x1
  const char *v16; // x2
  __int64 v17; // x4

  v9 = *(_QWORD *)(a1 + 80);
  if ( !v9 )
  {
    v16 = "WLAN_DEBUG_DFS_ALWAYS : %s: psoc is null";
LABEL_10:
    qdf_trace_msg(0x27u, 2u, v16, a2, a3, a4, a5, a6, a7, a8, a9, "tgt_dfs_set_phyerr_filter_offload");
    return 16;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(a1 + 80), 0x10u);
  if ( !comp_private_obj )
  {
    v16 = "WLAN_DEBUG_DFS_ALWAYS : %s: Failed to get dfs psoc component";
    goto LABEL_10;
  }
  v12 = *(_QWORD *)(v9 + 2128);
  if ( !v12 )
  {
    qdf_trace_msg(
      0x27u,
      2u,
      "WLAN_DEBUG_DFS_ALWAYS : %s: tx_ops is null",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_psoc_get_dfs_txops");
    v17 = 0;
LABEL_13:
    qdf_trace_msg(
      0x27u,
      2u,
      "WLAN_DEBUG_DFS_ALWAYS : %s: dfs_tx_ops=%pK",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "tgt_dfs_set_phyerr_filter_offload",
      v17);
    return 16;
  }
  v13 = *(__int64 (__fastcall **)(__int64, __int64))(v12 + 1248);
  if ( !v13 )
  {
    v17 = v12 + 1128;
    goto LABEL_13;
  }
  v14 = *(unsigned __int8 *)(comp_private_obj + 16);
  if ( *((_DWORD *)v13 - 1) != 1845289881 )
    __break(0x8228u);
  return v13(a1, v14);
}
