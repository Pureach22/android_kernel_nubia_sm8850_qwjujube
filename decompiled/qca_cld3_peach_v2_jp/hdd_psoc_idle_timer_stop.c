__int64 hdd_psoc_idle_timer_stop()
{
  double v0; // d0
  double v1; // d1
  double v2; // d2
  double v3; // d3
  double v4; // d4
  double v5; // d5
  double v6; // d6
  double v7; // d7

  _qdf_delayed_work_stop_sync();
  qdf_wake_lock_release((__int64)&wlan_wake_lock, 0x15u);
  return qdf_trace_msg(
           0x33u,
           8u,
           "%s: Stopped psoc idle timer",
           v0,
           v1,
           v2,
           v3,
           v4,
           v5,
           v6,
           v7,
           "hdd_psoc_idle_timer_stop");
}
