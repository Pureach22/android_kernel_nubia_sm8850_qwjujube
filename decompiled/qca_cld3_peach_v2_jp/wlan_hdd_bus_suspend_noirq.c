__int64 __fastcall wlan_hdd_bus_suspend_noirq(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  _QWORD *context; // x19
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 result; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  _QWORD *v34; // x0
  __int64 v35; // x20
  unsigned int v36; // w21
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  int is_target_wake_up_received; // w0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  const char *v54; // x2
  unsigned int v55; // w0

  context = _cds_get_context(51, (__int64)"wlan_hdd_bus_suspend_noirq", a1, a2, a3, a4, a5, a6, a7, a8);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: start bus_suspend_noirq",
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    "wlan_hdd_bus_suspend_noirq");
  if ( !context )
    return 4294967277LL;
  if ( *((_DWORD *)context + 366) == 1 )
  {
    result = _wlan_hdd_validate_context(context, "wlan_hdd_bus_suspend_noirq");
    if ( (_DWORD)result )
      return result;
    v34 = _cds_get_context(61, (__int64)"wlan_hdd_bus_suspend_noirq", v26, v27, v28, v29, v30, v31, v32, v33);
    if ( !v34 )
      return 4294967274LL;
    v35 = (__int64)v34;
    v36 = hif_bus_suspend_noirq((__int64)v34);
    if ( v36 )
      goto LABEL_18;
    is_target_wake_up_received = ucfg_pmo_psoc_is_target_wake_up_received(*context);
    if ( is_target_wake_up_received )
    {
      if ( is_target_wake_up_received != -11 )
      {
LABEL_17:
        v36 = is_target_wake_up_received;
        hif_bus_resume_noirq(v35);
LABEL_18:
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: suspend_noirq failed, status: %d",
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          "wlan_hdd_bus_suspend_noirq",
          v36);
        return v36;
      }
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Firmware attempting wakeup, try again",
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        "wlan_hdd_bus_suspend_noirq");
      wlan_hdd_inc_suspend_stats(context, 4);
LABEL_16:
      is_target_wake_up_received = -11;
      goto LABEL_17;
    }
    v55 = wma_critical_events_in_flight();
    if ( v55 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: %d critical event(s) in flight; try again",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "wlan_hdd_bus_suspend_noirq",
        v55);
      goto LABEL_16;
    }
    v54 = "%s: bus_suspend_noirq done";
    ++*((_DWORD *)context + 407);
  }
  else
  {
    v54 = "%s: Driver module closed; skip bus-noirq suspend";
  }
  qdf_trace_msg(0x33u, 8u, v54, v17, v18, v19, v20, v21, v22, v23, v24, "wlan_hdd_bus_suspend_noirq");
  return 0;
}
