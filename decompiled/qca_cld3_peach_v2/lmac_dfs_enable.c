__int64 __fastcall lmac_dfs_enable(
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
             "lmac_dfs_enable");
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
             "lmac_dfs_enable");
  v11 = *(__int64 (**)(void))(v10 + 1128);
  if ( v11 )
  {
    if ( *((_DWORD *)v11 - 1) != 935634628 )
      __break(0x8228u);
    return v11();
  }
  return result;
}
