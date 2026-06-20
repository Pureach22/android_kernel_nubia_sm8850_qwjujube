__int64 __fastcall policy_mgr_psoc_close(__int64 a1)
{
  __int64 context; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x19
  const char *v11; // x2
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v11 = "%s: Invalid Context";
    goto LABEL_5;
  }
  v10 = context;
  if ( (unsigned int)qdf_mutex_destroy(context + 56) )
  {
    v11 = "%s: Failed to destroy qdf_conc_list_lock";
LABEL_5:
    qdf_trace_msg(0x4Fu, 2u, v11, v2, v3, v4, v5, v6, v7, v8, v9, "policy_mgr_psoc_close");
    return 16;
  }
  v13 = *(_QWORD *)(v10 + 1192);
  if ( v13 )
  {
    _qdf_mem_free(v13);
    *(_QWORD *)(v10 + 1192) = 0;
    qdf_trace_msg(0x4Fu, 8u, "%s: HW list is freed", v14, v15, v16, v17, v18, v19, v20, v21, "policy_mgr_psoc_close");
  }
  if ( *(_QWORD *)(v10 + 2096) )
  {
    _qdf_delayed_work_destroy();
    _qdf_mem_free(*(_QWORD *)(v10 + 2096));
    *(_QWORD *)(v10 + 2096) = 0;
  }
  return 0;
}
