__int64 __fastcall policy_mgr_psoc_open(__int64 a1)
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
  _QWORD *v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v12 = "%s: Invalid Context";
    goto LABEL_5;
  }
  v11 = context;
  if ( (unsigned int)qdf_mutex_create(context + 56) )
  {
    v12 = "%s: Failed to init qdf_conc_list_lock";
LABEL_5:
    qdf_trace_msg(0x4Fu, 2u, v12, v3, v4, v5, v6, v7, v8, v9, v10, "policy_mgr_psoc_open");
    return 16;
  }
  v14 = (_QWORD *)_qdf_mem_malloc(0x38u, "policy_mgr_psoc_open", 523);
  *(_QWORD *)(v11 + 2096) = v14;
  if ( !v14 )
  {
    qdf_mutex_destroy(v11 + 56);
    return 16;
  }
  *v14 = a1;
  *(_BYTE *)(*(_QWORD *)(v11 + 2096) + 32LL) = -1;
  *(_DWORD *)(*(_QWORD *)(v11 + 2096) + 44LL) = 0;
  result = _qdf_delayed_work_create((_QWORD *)(v11 + 1008), (__int64)policy_mgr_check_sta_ap_concurrent_ch_intf, v11);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Failed to create dealyed work queue",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "policy_mgr_psoc_open");
    qdf_mutex_destroy(v11 + 56);
    _qdf_mem_free(*(_QWORD *)(v11 + 2096));
    return 16;
  }
  return result;
}
