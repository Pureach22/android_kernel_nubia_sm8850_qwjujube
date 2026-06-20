__int64 __fastcall cds_close(__int64 a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x0
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  _QWORD *v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 **v39; // x0
  __int64 updated; // x0
  __int64 v41; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x0

  v2 = qdf_hang_event_unregister_notifier(&cds_hang_event_notifier);
  if ( (unsigned int)cds_sched_close(v2) )
    qdf_trace_msg(0x38u, 2u, "%s: Failed to close CDS Scheduler", v3, v4, v5, v6, v7, v8, v9, v10, "cds_close");
  dispatcher_psoc_close(a1);
  v11 = flush_work(gp_cds_context + 240);
  v12 = cds_shutdown_notifier_purge(v11);
  if ( (unsigned int)wma_wmi_work_close(v12) )
    qdf_trace_msg(0x38u, 2u, "%s: Failed to close wma_wmi_work", v13, v14, v15, v16, v17, v18, v19, v20, "cds_close");
  v21 = gp_cds_context;
  v22 = *(_QWORD **)(gp_cds_context + 40);
  if ( v22 )
  {
    htc_destroy(v22);
    ucfg_pmo_psoc_update_htc_handle(a1, 0);
    v21 = gp_cds_context;
    *(_QWORD *)(gp_cds_context + 40) = 0;
  }
  if ( (unsigned int)sme_close(*(_QWORD *)(v21 + 8)) )
    qdf_trace_msg(0x38u, 2u, "%s: Failed to close SME", v23, v24, v25, v26, v27, v28, v29, v30, "cds_close");
  if ( (unsigned int)mac_close(*(_QWORD *)(gp_cds_context + 8)) )
    qdf_trace_msg(0x38u, 2u, "%s: Failed to close MAC", v31, v32, v33, v34, v35, v36, v37, v38, "cds_close");
  v39 = *(__int64 ***)(gp_cds_context + 64);
  *(_QWORD *)(gp_cds_context + 8) = 0;
  ucfg_dp_txrx_soc_detach(v39);
  *(_QWORD *)(gp_cds_context + 64) = 0;
  updated = ucfg_pmo_psoc_update_dp_handle(a1, 0);
  if ( a1 )
    *(_QWORD *)(a1 + 2808) = 0;
  v41 = wma_close(updated);
  if ( (_DWORD)v41 )
    v41 = qdf_trace_msg(0x38u, 2u, "%s: Failed to close wma", v42, v43, v44, v45, v46, v47, v48, v49, "cds_close");
  if ( (unsigned int)wma_wmi_service_close(v41) )
    qdf_trace_msg(0x38u, 2u, "%s: Failed to close wma_wmi_service", v50, v51, v52, v53, v54, v55, v56, v57, "cds_close");
  if ( gp_cds_context )
  {
    v58 = *(_QWORD *)(gp_cds_context + 152);
    *(_QWORD *)(gp_cds_context + 152) = 0;
    if ( v58 )
      _qdf_mem_free(v58);
  }
  else
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: cds context pointer is null (via %s)",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "__cds_get_context",
      "cds_deinit_ini_config");
  }
  v59 = qdf_timer_module_deinit();
  v60 = scheduler_deregister_wma_legacy_handler(v59);
  scheduler_deregister_sys_legacy_handler(v60);
  ((void (__fastcall *)(__int64))scheduler_deregister_module)(21);
  ((void (__fastcall *)(__int64))scheduler_deregister_module)(55);
  ((void (__fastcall *)(__int64))scheduler_deregister_module)(73);
  ((void (__fastcall *)(__int64))scheduler_deregister_module)(53);
  ((void (__fastcall *)(__int64))scheduler_deregister_module)(52);
  ((void (__fastcall *)(__int64))scheduler_deregister_module)(72);
  return 0;
}
