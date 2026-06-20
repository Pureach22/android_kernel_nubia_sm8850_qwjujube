__int64 __fastcall hdd_hostapd_channel_allow_suspend(
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

  v10 = *(_QWORD *)(a1 + 52832);
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
             "hdd_hostapd_channel_allow_suspend");
  v12 = *(_QWORD *)(a1 + 24);
  result = qdf_trace_msg(
             0x33u,
             8u,
             "%s: bss_state: %d, chan_freq: %d, dfs_ref_cnt: %d, is_dfs_wakelock_held %d",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "hdd_hostapd_channel_allow_suspend",
             *(unsigned int *)(v10 + 80),
             a2,
             *(unsigned int *)(v12 + 1120),
             *(unsigned __int8 *)(v11 + 1764));
  if ( *(_DWORD *)(v10 + 80) )
  {
    result = qdf_trace_msg(
               0x33u,
               8u,
               "%s: is_dfs_wakelock_held: %d",
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               "hdd_hostapd_channel_allow_suspend",
               *(unsigned __int8 *)(v11 + 1764));
    if ( *(_BYTE *)(v11 + 1764) == 1 )
    {
      _X9 = (unsigned int *)(v12 + 1120);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v37 = __ldxr(_X9);
        v38 = v37 - 1;
      }
      while ( __stlxr(v38, _X9) );
      __dmb(0xBu);
      if ( !v38 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: DFS: allowing suspend (chan_freq: %d)",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "hdd_hostapd_channel_allow_suspend",
          a2);
        qdf_wake_lock_release(v12 + 920, 0xFu);
        result = qdf_runtime_pm_allow_suspend((__int64 *)(v12 + 1656));
      }
      *(_BYTE *)(v11 + 1764) = 0;
    }
  }
  return result;
}
