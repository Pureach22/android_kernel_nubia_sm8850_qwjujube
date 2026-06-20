__int64 __fastcall wma_close(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8)
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
  __int64 v25; // x20
  __int64 *v26; // x19
  int v28; // w21
  unsigned __int64 v29; // x23
  __int64 *v30; // x22
  __int64 v31; // x0
  _BOOL4 v33; // w8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x1
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x1
  __int64 v52; // x1
  __int64 v53; // x1
  __int64 v54; // x1
  __int64 v55; // x0
  unsigned int *v56; // x8
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int64 v65; // x0
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  __int64 v74; // x0
  __int64 v75; // x1
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7

  qdf_trace_msg(0x36u, 8u, "%s: Enter", a1, a2, a3, a4, a5, a6, a7, a8, "wma_close");
  context = _cds_get_context(54, (__int64)"wma_close", v8, v9, v10, v11, v12, v13, v14, v15);
  if ( !context )
    return 4;
  v25 = *context;
  v26 = context;
  if ( (unsigned int)_wmi_validate_handle(*context, (__int64)"wma_close", v17, v18, v19, v20, v21, v22, v23, v24) )
    return 4;
  if ( (wlan_pmo_no_op_on_page_fault(v26[3]) & 1) == 0 )
  {
    v28 = wlan_pmo_enable_ssr_on_page_fault(v26[3]);
    v29 = 0;
    v30 = v26 + 550;
    do
    {
      v31 = *v30;
      *((_DWORD *)v30 - 2) = 0;
      *((_BYTE *)v30 - 4) = 0;
      _qdf_mem_free(v31);
      v33 = v29++ < 0x31;
      *v30 = 0;
      v30 += 2;
    }
    while ( (v33 & ~v28 & 1) != 0 );
    if ( (v28 & 1) == 0 )
    {
      _qdf_mem_free(v26[649]);
      v26[649] = 0;
      *((_DWORD *)v26 + 1300) = 0;
    }
  }
  *((_DWORD *)v26 + 994) = 0;
  *((_DWORD *)v26 + 995) = 0;
  if ( (unsigned int)cds_get_conparam() != 5 )
  {
    _qdf_wake_lock_destroy((__int64)(v26 + 523));
    _qdf_wake_lock_destroy((__int64)(v26 + 498));
    _qdf_wake_lock_destroy((__int64)(v26 + 87));
    _qdf_wake_lock_destroy((__int64)(v26 + 112));
    _qdf_wake_lock_destroy((__int64)(v26 + 137));
    _qdf_wake_lock_destroy((__int64)(v26 + 162));
    _qdf_wake_lock_destroy((__int64)(v26 + 187));
    _qdf_wake_lock_destroy((__int64)(v26 + 212));
    _qdf_wake_lock_destroy((__int64)(v26 + 237));
    _qdf_wake_lock_destroy((__int64)(v26 + 262));
    _qdf_wake_lock_destroy((__int64)(v26 + 287));
    _qdf_wake_lock_destroy((__int64)(v26 + 312));
  }
  if ( (unsigned int)dbglog_deinit(v25) )
    qdf_trace_msg(0x36u, 2u, "%s: dbglog_deinit failed", v34, v35, v36, v37, v38, v39, v40, v41, "wma_close");
  if ( (unsigned int)qdf_mc_timer_destroy((__int64)(v26 + 366)) )
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to destroy service ready ext event timer",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      "wma_close");
  qdf_event_destroy((__int64)(v26 + 5), v42);
  qdf_event_destroy((__int64)(v26 + 10), v51);
  qdf_event_destroy((__int64)(v26 + 15), v52);
  qdf_event_destroy((__int64)(v26 + 43), v53);
  qdf_event_destroy((__int64)(v26 + 48), v54);
  wma_cleanup_hold_req(v26);
  _qdf_wake_lock_destroy((__int64)(v26 + 391));
  qdf_runtime_lock_deinit(v26 + 418);
  qdf_runtime_lock_deinit(v26 + 417);
  qdf_runtime_lock_deinit(v26 + 416);
  v55 = v26[79];
  if ( v55 )
  {
    _qdf_mem_free(v55);
    v26[79] = 0;
  }
  wma_unified_radio_tx_mem_free(v26);
  if ( (unsigned int)qdf_mutex_destroy((__int64)(v26 + 477)) )
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to destroy radio stats mutex",
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      "wma_close");
  v65 = v26[4];
  if ( v65 )
  {
    wlan_objmgr_pdev_release_ref(v65, 8u, v56, v57, v58, v59, v60, v61, v62, v63, v64);
    v26[4] = 0;
  }
  pmo_unregister_get_beacon_interval_callback(v26[3]);
  pmo_unregister_get_dtim_period_callback(v26[3]);
  pmo_unregister_is_device_in_low_pwr_mode(v26[3]);
  pmo_unregister_get_pause_bitmap(v26[3]);
  pmo_unregister_pause_bitmap_notifier(v26[3]);
  v74 = v26[3];
  if ( v74 )
    v75 = *(_QWORD *)(v74 + 2800);
  else
    v75 = 0;
  init_deinit_free_num_units(v74, v75, v66, v67, v68, v69, v70, v71, v72, v73);
  target_if_free_psoc_tgt_info(v26[3], v76, v77, v78, v79, v80, v81, v82, v83);
  wlan_objmgr_psoc_release_ref(v26[3], 8u, v84, v85, v86, v87, v88, v89, v90, v91);
  v26[3] = 0;
  qdf_trace_msg(0x36u, 8u, "%s: Exit", v92, v93, v94, v95, v96, v97, v98, v99, "wma_close");
  return 0;
}
