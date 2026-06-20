__int64 __fastcall policy_mgr_psoc_open(__int64 a1)
{
  __int64 *context; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  unsigned int v12; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w19
  const char *v23; // x2
  const char *v24; // x3
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  _QWORD *v33; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7

  context = (__int64 *)policy_mgr_get_context(a1);
  if ( !context )
  {
    v23 = "%s: Invalid Context";
    v24 = "policy_mgr_psoc_open";
    goto LABEL_11;
  }
  v11 = (__int64)context;
  v12 = qdf_mc_timer_init((__int64)(context + 339), 0, (__int64)pm_emlsr_opportunistic_timer_handler, *context);
  if ( v12 )
  {
    v21 = v12;
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Failed to init emlsr opportunistic timer",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "policy_mgr_init_emlsr_timer");
    return v21;
  }
  if ( (unsigned int)qdf_mutex_create(v11 + 56) )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Failed to init qdf_conc_list_lock",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "policy_mgr_psoc_open");
LABEL_7:
    if ( (unsigned int)qdf_mc_timer_get_current_state(v11 + 2712) == 21 )
      qdf_mc_timer_stop(v11 + 2712);
    if ( !(unsigned int)qdf_mc_timer_destroy(v11 + 2712) )
      return 16;
    v23 = "%s: Cannot deallocate emlsr opportunistic timer";
    v24 = "policy_mgr_deinit_emlsr_timer";
LABEL_11:
    qdf_trace_msg(0x4Fu, 2u, v23, v3, v4, v5, v6, v7, v8, v9, v10, v24);
    return 16;
  }
  v33 = (_QWORD *)_qdf_mem_malloc(0x38u, "policy_mgr_psoc_open", 523);
  *(_QWORD *)(v11 + 2096) = v33;
  if ( !v33 )
  {
    qdf_mutex_destroy(v11 + 56);
    goto LABEL_7;
  }
  *v33 = a1;
  *(_BYTE *)(*(_QWORD *)(v11 + 2096) + 32LL) = -1;
  *(_DWORD *)(*(_QWORD *)(v11 + 2096) + 44LL) = 0;
  if ( (unsigned int)_qdf_delayed_work_create(
                       (_QWORD *)(v11 + 1008),
                       (__int64)policy_mgr_check_sta_ap_concurrent_ch_intf,
                       v11) )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Failed to create dealyed work queue",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "policy_mgr_psoc_open");
    qdf_mutex_destroy(v11 + 56);
    _qdf_mem_free(*(_QWORD *)(v11 + 2096));
    goto LABEL_7;
  }
  if ( !g_trace_set_link_cmd )
    g_trace_set_link_cmd = _qdf_mem_malloc(0x440u, "pm_init_trace_set_link_mem", 171);
  g_trace_set_link_cmd_index = 0;
  if ( !g_trace_set_link_evt )
    g_trace_set_link_evt = _qdf_mem_malloc(0x200u, "pm_init_trace_set_link_mem", 176);
  g_trace_set_link_evt_index = 0;
  return 0;
}
