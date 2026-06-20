__int64 __fastcall hdd_disable_wifi(
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
  __int64 v9; // x20
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
  _QWORD *context; // x21
  unsigned int i; // w22
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x20

  if ( *(_BYTE *)(a1 + 7099) == 1 )
  {
    v9 = jiffies;
    if ( hdd_disable_wifi___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x33u, 2u, "%s: Wifi is already disabled", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_disable_wifi");
      hdd_disable_wifi___last_ticks = v9;
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(0x33u, 8u, "%s: Initiating WLAN idle shutdown", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_disable_wifi");
    if ( (hdd_is_any_interface_open(a1, v12, v13, v14, v15, v16, v17, v18, v19) & 1) != 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Interfaces still open, cannot process wifi disable",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "hdd_disable_wifi");
      return 4294967285LL;
    }
    *(_BYTE *)(a1 + 7099) = 1;
    context = _cds_get_context(61, (__int64)"hdd_wlan_idle_shutdown", v20, v21, v22, v23, v24, v25, v26, v27);
    qdf_wake_lock_acquire((__int64)wlan_wake_lock, 0x18u);
    for ( i = 0; i != 10; ++i )
    {
      if ( context )
        qdf_rtpm_sync_resume();
      if ( (unsigned int)pld_idle_shutdown(*(_QWORD *)(a1 + 96), hdd_psoc_idle_shutdown) != -11
        && *(_BYTE *)(a1 + 488) != 1 )
      {
        break;
      }
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: System suspend in progress.Retries done:%d",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "hdd_wlan_idle_shutdown",
        i);
      msleep(10);
    }
    qdf_wake_lock_release((__int64)wlan_wake_lock, 0x18u);
    v46 = jiffies;
    if ( hdd_wlan_idle_shutdown___last_ticks_883 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x33u, 8u, "%s: WiFi is disabled", v38, v39, v40, v41, v42, v43, v44, v45, "hdd_wlan_idle_shutdown");
      hdd_wlan_idle_shutdown___last_ticks_883 = v46;
      return 0;
    }
  }
  return 0;
}
