__int64 __fastcall dfs_is_freq_in_nol(
        __int64 a1,
        int a2,
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

  if ( !a1 )
  {
    qdf_trace_msg(
      0x27u,
      2u,
      "WLAN_DEBUG_DFS_RANDOM_CHAN : %s: null dfs",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "dfs_is_freq_in_nol");
    return 0;
  }
  v10 = *(_QWORD *)(a1 + 64);
  if ( !v10 )
    return 0;
  while ( *(_DWORD *)(v10 + 24) != a2 )
  {
    v10 = *(_QWORD *)(v10 + 136);
    if ( !v10 )
      return 0;
  }
  if ( (*(_BYTE *)(a1 + 2) & 0x20) != 0 )
    qdf_trace_msg(
      0x27u,
      8u,
      "WLAN_DEBUG_DFS_RANDOM_CHAN : %s: %d is in nol",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "dfs_is_freq_in_nol");
  return 1;
}
