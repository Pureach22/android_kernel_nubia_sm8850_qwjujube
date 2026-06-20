__int64 __fastcall wlan_hdd_pld_remove(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  _QWORD *context; // x0
  __int64 v19; // x3
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  _QWORD *v29; // x19
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
  __int64 v46; // x0
  __int64 v47; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int64 v72; // x2
  __int64 v73; // x3

  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_hdd_pld_remove");
  context = _cds_get_context(51, (__int64)"__hdd_soc_remove", v10, v11, v12, v13, v14, v15, v16, v17);
  if ( context )
  {
    v29 = context;
    printk(&unk_A18E99, aQcaCld3PeachV2, "5.2.1.137C", v19);
    qdf_rtpm_sync_resume();
    cds_clear_driver_state(1, v30, v31, v32, v33, v34, v35, v36, v37);
    v46 = cds_set_driver_state(4, v38, v39, v40, v41, v42, v43, v44, v45);
    v47 = hdd_wait_for_debugfs_threads_completion(v46);
    if ( (v47 & 1) == 0 )
      v47 = qdf_trace_msg(
              0x33u,
              3u,
              "%s: Debugfs threads are still active attempting driver unload anyway",
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              v55,
              "__hdd_soc_remove");
    if ( (unsigned int)hdd_get_conparam(v47) == 8 )
    {
      hdd_wlan_stop_modules(v29, 0);
      _qdf_nbuf_deinit_replenish_timer();
    }
    else
    {
      hdd_thermal_mitigation_unregister(v29, a1);
      hdd_ddr_bw_mitigation_unregister(v29, a1);
      hdd_wlan_exit(v29);
    }
    hdd_context_destroy(v29);
    cds_clear_driver_state(16, v56, v57, v58, v59, v60, v61, v62, v63);
    cds_clear_driver_state(4, v64, v65, v66, v67, v68, v69, v70, v71);
    ucfg_dp_prealloc_deinit();
    printk(&unk_A6FDDF, aQcaCld3PeachV2, v72, v73);
  }
  qdf_ssr_driver_dump_unregister_region("hang_event_data");
  return qdf_trace_msg(0x33u, 8u, "%s: exit", v20, v21, v22, v23, v24, v25, v26, v27, "wlan_hdd_pld_remove");
}
