__int64 __fastcall wlan_hdd_pld_runtime_resume(
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
  __int64 *context; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 *v25; // x19
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned __int64 StatusReg; // kr00_8
  __int64 v43; // x8
  unsigned __int64 v44; // x9
  unsigned int v45; // w0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned int driver_state; // w0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  const char *v63; // x2

  qdf_trace_msg(0x33u, 8u, "%s: Starting runtime resume", a1, a2, a3, a4, a5, a6, a7, a8, "wlan_hdd_runtime_resume");
  context = _cds_get_context(51, (__int64)"wlan_hdd_runtime_resume", v8, v9, v10, v11, v12, v13, v14, v15);
  if ( context )
  {
    v25 = context;
    if ( (cds_get_driver_state(v17, v18, v19, v20, v21, v22, v23, v24) & 8) != 0 )
    {
      driver_state = cds_get_driver_state(v26, v27, v28, v29, v30, v31, v32, v33);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Recovery in progress, state:0x%x",
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        "wlan_hdd_runtime_resume",
        driver_state);
    }
    else
    {
      if ( *((_DWORD *)v25 + 366) != 1 )
      {
        v63 = "%s: Driver module closed skipping runtime resume";
LABEL_14:
        qdf_trace_msg(0x33u, 8u, v63, v26, v27, v28, v29, v30, v31, v32, v33, "wlan_hdd_runtime_resume");
        return 0;
      }
      if ( (hdd_is_runtime_pm_enabled(v25) & 1) != 0 )
      {
        __isb(0xFu);
        StatusReg = _ReadStatusReg(CNTVCT_EL0);
        v43 = v25[525];
        v44 = 10 * StatusReg / 0xC0;
        if ( 10 * StatusReg < StatusReg )
          v44 = 10 * (StatusReg / 0xC0);
        v25[524] = v44;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Starting runtime resume total cxpc down time %lu microseconds",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "wlan_hdd_runtime_resume",
          v44 - v43);
        v45 = ucfg_pmo_psoc_bus_runtime_resume(*v25, hdd_pld_runtime_resume_cb);
        if ( v45 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: PMO Runtime resume failed: %d",
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            "wlan_hdd_runtime_resume",
            v45);
        }
        else if ( (unsigned int)policy_mgr_get_connection_count(*v25) )
        {
          ucfg_dp_bus_bw_compute_timer_try_start(*v25);
        }
        v63 = "%s: Runtime resume done";
        goto LABEL_14;
      }
    }
  }
  return 0;
}
