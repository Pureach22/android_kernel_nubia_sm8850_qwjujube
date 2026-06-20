__int64 __fastcall dfs_reset(
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
  __int64 v9; // x19

  if ( !result )
    return qdf_trace_msg(
             0x27u,
             2u,
             "WLAN_DEBUG_DFS_ALWAYS : %s: dfs is NULL",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "dfs_reset");
  if ( (*(_BYTE *)(result + 152) & 4) != 0 )
  {
    v9 = result;
    result = timer_delete_sync(result + 168);
    *(_BYTE *)(v9 + 152) &= ~4u;
  }
  return result;
}
