__int64 __fastcall dfs_print_nol(
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
  __int64 v9; // x22
  unsigned int v10; // w21
  __int64 v11; // x9
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w10
  unsigned __int64 v21; // x9
  bool v22; // cf
  unsigned int v23; // w9
  __int64 v24; // [xsp+0h] [xbp-10h]

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
             "dfs_print_nol");
  v9 = *(_QWORD *)(result + 64);
  if ( (*(_BYTE *)(result + 1) & 0x20) != 0 )
    result = qdf_trace_msg(0x27u, 8u, "WLAN_DEBUG_DFS_NOL : %s: NOL", a2, a3, a4, a5, a6, a7, a8, a9, "dfs_print_nol");
  if ( v9 )
  {
    v10 = 0;
    do
    {
      v11 = (unsigned __int128)(ktime_get_with_offset(1) * (__int128)0x20C49BA5E353F7CFLL) >> 64;
      v20 = *(_DWORD *)(v9 + 40);
      v24 = *(_QWORD *)(v9 + 32);
      v21 = ((v11 >> 7) + ((unsigned __int64)v11 >> 63) - v24) / 0x3E8;
      v22 = v20 >= (unsigned int)v21;
      v23 = v20 - v21;
      if ( !v22 )
        v23 = 0;
      result = qdf_trace_msg(
                 0x27u,
                 4u,
                 "WLAN_DEBUG_DFS_ALWAYS : %s: nol:%d channel=%d MHz width=%d MHz time left=%u seconds nol start_us=%llu",
                 v12,
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 "dfs_print_nol",
                 v10,
                 *(unsigned int *)(v9 + 24),
                 *(unsigned int *)(v9 + 28),
                 v23 / 0x3E8uLL,
                 v24);
      v9 = *(_QWORD *)(v9 + 136);
      ++v10;
    }
    while ( v9 );
  }
  return result;
}
