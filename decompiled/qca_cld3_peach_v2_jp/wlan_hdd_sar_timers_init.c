__int64 __fastcall wlan_hdd_sar_timers_init(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  if ( (*(_BYTE *)(*(_QWORD *)(result + 104) + 172LL) & 1) != 0 )
  {
    v9 = result;
    qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_hdd_sar_timers_init");
    qdf_mc_timer_init(v9 + 3856, 0, (__int64)hdd_sar_safety_timer_cb, v9);
    if ( (unsigned int)_qdf_delayed_work_create((_QWORD *)(v9 + 4024), (__int64)hdd_sar_unsolicited_work_cb, v9) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: failed to create sar safety unsolicited work",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "wlan_hdd_sar_timers_init");
    }
    else
    {
      *(_DWORD *)(v9 + 4184) = 0;
      qdf_event_create((_DWORD *)(v9 + 4144));
    }
    return qdf_trace_msg(0x33u, 8u, "%s: exit", v18, v19, v20, v21, v22, v23, v24, v25, "wlan_hdd_sar_timers_init");
  }
  return result;
}
