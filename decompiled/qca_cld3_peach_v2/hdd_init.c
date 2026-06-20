__int64 hdd_init()
{
  double v0; // d0
  double v1; // d1
  double v2; // d2
  double v3; // d3
  double v4; // d4
  double v5; // d5
  double v6; // d6
  double v7; // d7
  void *v9; // x0
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x3
  __int64 global_context; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x0
  __int64 v31; // x1
  __int64 v32; // x2
  __int64 v33; // x3
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7

  if ( (unsigned int)cds_init() )
  {
    qdf_trace_msg(0x33u, 2u, "%s: Failed to allocate CDS context", v0, v1, v2, v3, v4, v5, v6, v7, "hdd_init");
    return 4294967284LL;
  }
  v9 = qdf_op_callbacks_register(_hdd_op_protect_cb, _hdd_op_unprotect_cb);
  global_context = cds_get_global_context((__int64)v9, v10, v11, v12);
  if ( !global_context )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: cds context is NULL",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wlan_init_bug_report_lock");
    if ( (unsigned int)wlan_logging_sock_init_svc() )
      goto LABEL_5;
LABEL_9:
    hdd_trace_init();
    ((void (__fastcall *)(__int64, __int64 (__fastcall *)()))qdf_register_debug_callback)(51, hdd_state_info_dump);
    return 0;
  }
  *(_DWORD *)(global_context + 128) = 0;
  *(_QWORD *)(global_context + 136) = 0;
  if ( !(unsigned int)wlan_logging_sock_init_svc() )
    goto LABEL_9;
LABEL_5:
  v30 = qdf_trace_msg(0x33u, 2u, "%s: logging sock init failed.", v22, v23, v24, v25, v26, v27, v28, v29, "hdd_init");
  if ( !cds_get_global_context(v30, v31, v32, v33) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: cds context is NULL",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "wlan_destroy_bug_report_lock");
  qdf_op_callbacks_register(nullptr, nullptr);
  cds_deinit();
  return 4294967284LL;
}
