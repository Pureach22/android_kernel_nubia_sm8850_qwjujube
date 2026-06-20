__int64 __fastcall dfs_get_radar_status(
        __int64 result,
        _BYTE *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  int v11; // w9

  *a2 = 0;
  if ( !result )
    return qdf_trace_msg(
             0x27u,
             2u,
             "WLAN_DEBUG_DFS_ALWAYS : %s: dfs is NULL",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "dfs_get_radar_status");
  v10 = *(_QWORD *)(result + 64);
  if ( v10 )
  {
    v11 = 0;
    do
    {
      *a2 = ++v11;
      v10 = *(_QWORD *)(v10 + 136);
    }
    while ( v10 );
  }
  return result;
}
