__int64 __fastcall dfs_testtimer_task(
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
  __int64 v9; // x4

  v9 = *(unsigned __int8 *)(a1 + 153);
  *(_BYTE *)(a1 + 152) &= ~4u;
  qdf_trace_msg(
    0x27u,
    8u,
    "WLAN_DEBUG_DFS_ALWAYS : %s: go back to channel %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "dfs_testtimer_task",
    v9);
  return dfs_mlme_start_csa_for_freq(
           *(_QWORD *)(a1 + 14936),
           *(unsigned __int8 *)(a1 + 153),
           **(unsigned __int16 **)(a1 + 14888),
           *(unsigned __int16 *)(*(_QWORD *)(a1 + 14888) + 24LL),
           *(_QWORD *)(*(_QWORD *)(a1 + 14888) + 8LL));
}
