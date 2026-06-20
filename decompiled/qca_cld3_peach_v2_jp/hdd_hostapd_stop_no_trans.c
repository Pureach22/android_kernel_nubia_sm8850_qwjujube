__int64 __fastcall hdd_hostapd_stop_no_trans(
        _QWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x19
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned __int64 v34; // x10

  v10 = a1[339];
  qdf_trace_msg(0x33u, 8u, "%s: enter(%s)", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_hostapd_stop_no_trans", a1 + 37);
  qdf_mtrace(51, 51, 0x10u, 0xFFu, 0);
  result = _wlan_hdd_validate_context(v10, "hdd_hostapd_stop_no_trans");
  if ( !(_DWORD)result )
  {
    hdd_stop_adapter(v10, a1 + 336);
    hdd_deinit_adapter(v10, a1 + 336, 1);
    _X8 = a1 + 539;
    __asm { PRFM            #0x11, [X8] }
    do
      v34 = __ldxr(_X8);
    while ( __stxr(v34 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: vdev %d Disabling queues",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "hdd_hostapd_stop_no_trans",
      *(unsigned __int8 *)(a1[6939] + 8LL));
    wlan_hdd_netif_queue_control(a1 + 336, 4, 1);
    if ( (hdd_is_any_interface_open(v10) & 1) == 0 )
      hdd_psoc_idle_timer_start(v10);
    qdf_trace_msg(0x33u, 8u, "%s: exit", v20, v21, v22, v23, v24, v25, v26, v27, "hdd_hostapd_stop_no_trans");
    return 0;
  }
  return result;
}
