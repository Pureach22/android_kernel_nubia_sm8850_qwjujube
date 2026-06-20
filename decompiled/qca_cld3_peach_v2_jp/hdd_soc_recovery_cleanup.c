__int64 __fastcall hdd_soc_recovery_cleanup(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 result; // x0
  __int64 v17; // x19
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  const char *v34; // x2
  unsigned int v35; // w1
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  int v44; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v45; // [xsp+8h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x33u, 8u, "%s: enter", a1, a2, a3, a4, a5, a6, a7, a8, "hdd_soc_recovery_cleanup");
  result = (__int64)_cds_get_context(51, (__int64)"hdd_soc_recovery_cleanup", v8, v9, v10, v11, v12, v13, v14, v15);
  if ( result )
  {
    v17 = result;
    hdd_psoc_idle_timer_stop(result);
    ucfg_dp_bus_bw_compute_timer_stop(*(_QWORD *)v17, v18, v19, v20, v21, v22, v23, v24, v25);
    if ( *(_DWORD *)(v17 + 1464) == 2 )
    {
      v34 = "%s: Driver modules are already closed";
      v35 = 4;
    }
    else
    {
      qdf_trace_msg(0x33u, 8u, "%s: enter", v26, v27, v28, v29, v30, v31, v32, v33, "hdd_psoc_shutdown_notify");
      cds_shutdown_notifier_call();
      cds_shutdown_notifier_purge();
      v44 = 0;
      qdf_mem_set(&v44, 4u, 0);
      v44 = 1;
      host_diag_event_report_payload(2877, 4, &v44);
      qdf_trace_msg(0x33u, 8u, "%s: exit", v36, v37, v38, v39, v40, v41, v42, v43, "hdd_psoc_shutdown_notify");
      v35 = 8;
      v34 = "%s: exit";
    }
    result = qdf_trace_msg(0x33u, v35, v34, v26, v27, v28, v29, v30, v31, v32, v33, "hdd_soc_recovery_cleanup");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
