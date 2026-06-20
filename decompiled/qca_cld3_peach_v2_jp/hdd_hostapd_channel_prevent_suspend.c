__int64 __fastcall hdd_hostapd_channel_prevent_suspend(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x22
  __int64 v11; // x20
  __int64 v12; // x21
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v37; // w8
  unsigned int v38; // w8

  v10 = *(_QWORD *)(a1 + 52824);
  v11 = *(_QWORD *)(v10 + 272);
  if ( !v11 )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: sap ctx null",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "hdd_hostapd_channel_prevent_suspend");
  v12 = *(_QWORD *)(a1 + 24);
  result = qdf_trace_msg(
             0x33u,
             8u,
             "%s: bss_state: %d, chan_freq: %d, dfs_ref_cnt: %d, is_dfs_wakelock_held: %d",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "hdd_hostapd_channel_prevent_suspend",
             *(unsigned int *)(v10 + 80),
             a2,
             *(unsigned int *)(v12 + 1120),
             *(unsigned __int8 *)(v11 + 1740));
  if ( *(_DWORD *)(v10 + 80) != 1 || *(int *)(v12 + 1120) <= 0 )
  {
    result = wlan_mlme_check_chan_param_has_dfs(
               *(_QWORD *)(v12 + 8),
               (unsigned int *)(v11 + 1500),
               a2,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22);
    if ( (result & 1) != 0 )
    {
      _X9 = (unsigned int *)(v12 + 1120);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v37 = __ldxr(_X9);
        v38 = v37 + 1;
      }
      while ( __stlxr(v38, _X9) );
      __dmb(0xBu);
      if ( v38 == 1 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: DFS: preventing suspend (chan_freq: %d)",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "hdd_hostapd_channel_prevent_suspend",
          a2);
        qdf_runtime_pm_prevent_suspend((__int64 *)(v12 + 1656));
        result = qdf_wake_lock_acquire(v12 + 920, 0xFu);
      }
      *(_BYTE *)(v11 + 1740) = 1;
    }
  }
  return result;
}
