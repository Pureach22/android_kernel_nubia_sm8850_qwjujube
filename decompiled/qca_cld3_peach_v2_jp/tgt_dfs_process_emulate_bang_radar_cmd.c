__int64 __fastcall tgt_dfs_process_emulate_bang_radar_cmd(
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
  __int64 v10; // x8
  __int64 (*v11)(void); // x9
  __int64 v13; // x4

  v9 = *(_QWORD *)(a1 + 80);
  if ( !v9 )
  {
    qdf_trace_msg(
      0x27u,
      2u,
      "WLAN_DEBUG_DFS_ALWAYS : %s: psoc is null",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "tgt_dfs_process_emulate_bang_radar_cmd");
    return 16;
  }
  v10 = *(_QWORD *)(v9 + 2128);
  if ( !v10 )
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
    v13 = 0;
LABEL_10:
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
      "tgt_dfs_process_emulate_bang_radar_cmd",
      v13);
    return 16;
  }
  v11 = *(__int64 (**)(void))(v10 + 1216);
  if ( !v11 )
  {
    v13 = v10 + 1128;
    goto LABEL_10;
  }
  if ( *((_DWORD *)v11 - 1) != -1413706777 )
    __break(0x8229u);
  return v11();
}
