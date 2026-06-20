__int64 __fastcall wlan_hdd_sar_timers_deinit(
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
  __int64 v10; // x1
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  if ( (*(_BYTE *)(*(_QWORD *)(result + 104) + 172LL) & 1) != 0 )
  {
    v9 = result;
    qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_hdd_sar_timers_deinit");
    if ( (unsigned int)qdf_mc_timer_get_current_state(v9 + 3880) == 21 )
      qdf_mc_timer_stop(v9 + 3880);
    qdf_mc_timer_destroy(v9 + 3880);
    _qdf_delayed_work_destroy();
    qdf_event_destroy(v9 + 4168, v10);
    return qdf_trace_msg(0x33u, 8u, "%s: exit", v11, v12, v13, v14, v15, v16, v17, v18, "wlan_hdd_sar_timers_deinit");
  }
  return result;
}
