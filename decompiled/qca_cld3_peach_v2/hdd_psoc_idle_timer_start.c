__int64 __fastcall hdd_psoc_idle_timer_start(
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
  unsigned int v9; // w19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x1
  __int64 v20; // x2
  __int64 v21; // x3
  const char *v22; // x0

  v9 = *(_DWORD *)(*(_QWORD *)(a1 + 104) + 24LL);
  if ( !v9 )
    return qdf_trace_msg(
             0x33u,
             4u,
             "%s: psoc idle timer is disabled",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "hdd_psoc_idle_timer_start");
  qdf_trace_msg(0x33u, 8u, "%s: Starting psoc idle timer", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_psoc_idle_timer_start");
  if ( *(_DWORD *)(a1 + 6856) )
  {
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: pcie gen speed change requested",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "hdd_psoc_idle_timer_start");
    v9 = 100;
  }
  _qdf_delayed_work_start(a1 + 1472, v9);
  cds_get_ring_log_level(0, v19, v20, v21);
  v22 = qdf_wake_lock_name((__int64)&wlan_wake_lock);
  ((void (__fastcall *)(__int64, const char *, _QWORD, _QWORD))host_diag_log_wlock)(21, v22, v9 + 1000, 0);
  return qdf_wake_lock_timeout_acquire((__int64)&wlan_wake_lock, v9 + 1000);
}
