__int64 __fastcall tgt_dfs_reg_ev_handler(
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
  __int64 v9; // x8
  __int64 (*v10)(void); // x8
  const char *v12; // x2

  if ( !a1 )
  {
    v12 = "WLAN_DEBUG_DFS_ALWAYS : %s: null psoc";
LABEL_9:
    qdf_trace_msg(0x27u, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "tgt_dfs_reg_ev_handler");
    return 16;
  }
  v9 = *(_QWORD *)(a1 + 2128);
  if ( !v9 )
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
    v12 = "WLAN_DEBUG_DFS_ALWAYS : %s: null dfs_tx_ops";
    goto LABEL_9;
  }
  v10 = *(__int64 (**)(void))(v9 + 1208);
  if ( !v10 )
    return 16;
  if ( *((_DWORD *)v10 - 1) != -770124015 )
    __break(0x8228u);
  return v10();
}
