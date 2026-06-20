__int64 __fastcall lmac_dfs_get_thresholds(
        __int64 result,
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
  __int64 (*v11)(void); // x8

  v9 = *(_QWORD *)(result + 80);
  if ( !v9 )
    return qdf_trace_msg(
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
             "lmac_dfs_get_thresholds");
  v10 = *(_QWORD *)(v9 + 2128);
  if ( !v10 )
    return qdf_trace_msg(
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
             "lmac_dfs_get_thresholds");
  v11 = *(__int64 (**)(void))(v10 + 1168);
  if ( v11 )
  {
    if ( *((_DWORD *)v11 - 1) != 1267204425 )
      __break(0x8228u);
    return v11();
  }
  return result;
}
