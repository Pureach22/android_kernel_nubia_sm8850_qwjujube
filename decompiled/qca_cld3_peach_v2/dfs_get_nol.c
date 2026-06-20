__int64 __fastcall dfs_get_nol(
        __int64 result,
        __int64 a2,
        int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  int v12; // w10

  *a3 = 0;
  if ( !result )
    return qdf_trace_msg(
             0x27u,
             2u,
             "WLAN_DEBUG_DFS_ALWAYS : %s: dfs is NULL",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "dfs_get_nol");
  v11 = *(_QWORD *)(result + 64);
  if ( v11 )
  {
    v12 = 0;
    do
    {
      *(_WORD *)(a2 + 24LL * v12) = *(_DWORD *)(v11 + 24);
      *(_WORD *)(a2 + 24LL * *a3 + 2) = *(_DWORD *)(v11 + 28);
      *(_QWORD *)(a2 + 24LL * *a3 + 8) = *(_QWORD *)(v11 + 32);
      *(_DWORD *)(a2 + 24LL * *a3 + 16) = *(_DWORD *)(v11 + 40);
      v12 = *a3 + 1;
      *a3 = v12;
      v11 = *(_QWORD *)(v11 + 136);
    }
    while ( v11 );
  }
  return result;
}
