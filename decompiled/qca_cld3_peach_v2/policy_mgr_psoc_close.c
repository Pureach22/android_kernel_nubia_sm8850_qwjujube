__int64 __fastcall policy_mgr_psoc_close(__int64 a1)
{
  __int64 context; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  const char *v12; // x2
  __int64 result; // x0
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7

  if ( g_trace_set_link_cmd )
  {
    _qdf_mem_free(g_trace_set_link_cmd);
    g_trace_set_link_cmd = 0;
  }
  if ( g_trace_set_link_evt )
  {
    _qdf_mem_free(g_trace_set_link_evt);
    g_trace_set_link_evt = 0;
  }
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v12 = "%s: Invalid Context";
    goto LABEL_9;
  }
  v11 = context;
  policy_mgr_flush_deferred_csa(a1, 0xFFu);
  if ( (unsigned int)qdf_mutex_destroy(v11 + 56) )
  {
    v12 = "%s: Failed to destroy qdf_conc_list_lock";
LABEL_9:
    qdf_trace_msg(0x4Fu, 2u, v12, v3, v4, v5, v6, v7, v8, v9, v10, "policy_mgr_psoc_close");
    return 16;
  }
  v14 = *(_QWORD *)(v11 + 1192);
  if ( v14 )
  {
    _qdf_mem_free(v14);
    *(_QWORD *)(v11 + 1192) = 0;
    qdf_trace_msg(0x4Fu, 8u, "%s: HW list is freed", v15, v16, v17, v18, v19, v20, v21, v22, "policy_mgr_psoc_close");
  }
  if ( *(_QWORD *)(v11 + 2096) )
  {
    _qdf_delayed_work_destroy();
    _qdf_mem_free(*(_QWORD *)(v11 + 2096));
    *(_QWORD *)(v11 + 2096) = 0;
  }
  if ( (unsigned int)qdf_mc_timer_get_current_state(v11 + 2712) == 21 )
    qdf_mc_timer_stop(v11 + 2712);
  result = qdf_mc_timer_destroy(v11 + 2712);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Cannot deallocate emlsr opportunistic timer",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "policy_mgr_deinit_emlsr_timer");
    return 0;
  }
  return result;
}
