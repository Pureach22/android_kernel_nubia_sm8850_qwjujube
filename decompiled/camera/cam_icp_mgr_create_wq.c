__int64 __fastcall cam_icp_mgr_create_wq(__int64 a1)
{
  unsigned int v2; // w0
  unsigned int v3; // w20
  unsigned int v4; // w0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x9
  __int64 v13; // x10
  __int64 v14; // x8
  __int64 v15; // x9
  __int64 v16; // x10
  __int64 v17; // x8
  __int64 v18; // x9
  __int64 v19; // x10
  _QWORD *v20; // x0
  _QWORD *v21; // x0
  _QWORD v23[5]; // [xsp+8h] [xbp-28h] BYREF

  v23[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v23, 0, 32);
  scnprintf(v23, 32, "%s_command_queue", (const char *)(a1 + 112));
  v2 = cam_req_mgr_workq_create(
         "icp_command_queue",
         0x64u,
         (__int64 *)(a1 + 992),
         0,
         0,
         (__int64)cam_req_mgr_process_workq_icp_command_queue);
  if ( v2 )
  {
    v3 = v2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_create_wq",
      9782,
      "[%s] unable to create a command worker for %s",
      (const char *)(a1 + 112),
      (const char *)v23);
    goto LABEL_37;
  }
  scnprintf(v23, 32, "%s_message_queue", (const char *)(a1 + 112));
  v4 = cam_req_mgr_workq_create(
         (const char *)v23,
         0x64u,
         (__int64 *)(a1 + 1000),
         1,
         0,
         (__int64)cam_req_mgr_process_workq_icp_message_queue);
  if ( v4 )
  {
    v3 = v4;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_create_wq",
      9792,
      "[%s] unable to create a message worker for %s",
      (const char *)(a1 + 112),
      (const char *)v23);
LABEL_36:
    cam_req_mgr_workq_destroy((_QWORD *)(a1 + 992));
    goto LABEL_37;
  }
  scnprintf(v23, 32, "%s_timer_queue", (const char *)(a1 + 112));
  v3 = cam_req_mgr_workq_create(
         (const char *)v23,
         0x64u,
         (__int64 *)(a1 + 1008),
         1,
         0,
         (__int64)cam_req_mgr_process_workq_icp_timer_queue);
  if ( v3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_create_wq",
      9802,
      "[%s] unable to create a timer worker for %s",
      (const char *)(a1 + 112),
      (const char *)v23);
LABEL_35:
    cam_req_mgr_workq_destroy((_QWORD *)(a1 + 1000));
    goto LABEL_36;
  }
  if ( mem_trace_en == 1 )
  {
    v5 = cam_mem_trace_alloc(2400, 0xCC0u, 0, "cam_icp_mgr_create_wq", 0x264Fu);
    *(_QWORD *)(a1 + 44056) = v5;
    if ( !v5 )
      goto LABEL_26;
  }
  else
  {
    v6 = _kvmalloc_node_noprof(2400, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(a1 + 44056) = v6;
    if ( !v6 )
    {
LABEL_26:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_create_wq",
        9810,
        "[%s] Mem reservation fail for cmd_work_data",
        (const char *)(a1 + 112));
LABEL_34:
      cam_req_mgr_workq_destroy((_QWORD *)(a1 + 1008));
      goto LABEL_35;
    }
  }
  if ( mem_trace_en == 1 )
  {
    v7 = cam_mem_trace_alloc(2400, 0xCC0u, 0, "cam_icp_mgr_create_wq", 0x2656u);
    *(_QWORD *)(a1 + 44064) = v7;
    if ( !v7 )
      goto LABEL_27;
  }
  else
  {
    v8 = _kvmalloc_node_noprof(2400, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(a1 + 44064) = v8;
    if ( !v8 )
    {
LABEL_27:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_create_wq",
        9817,
        "[%s] Mem reservation fail for msg_work_data",
        (const char *)(a1 + 112));
LABEL_31:
      v21 = *(_QWORD **)(a1 + 44056);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v21, 0);
      else
        kvfree(v21);
      goto LABEL_34;
    }
  }
  if ( mem_trace_en == 1 )
  {
    v9 = cam_mem_trace_alloc(2400, 0xCC0u, 0, "cam_icp_mgr_create_wq", 0x265Eu);
    *(_QWORD *)(a1 + 44072) = v9;
    if ( !v9 )
    {
LABEL_28:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_create_wq",
        9825,
        "[%s] Mem reservation fail for timer_work_data",
        (const char *)(a1 + 112));
      v20 = *(_QWORD **)(a1 + 44064);
      if ( (mem_trace_en & 1) != 0 )
        cam_mem_trace_free(v20, 0);
      else
        kvfree(v20);
      goto LABEL_31;
    }
  }
  else
  {
    v10 = _kvmalloc_node_noprof(2400, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(a1 + 44072) = v10;
    if ( !v10 )
      goto LABEL_28;
  }
  v11 = 0;
  v12 = 8;
  do
  {
    v13 = *(_QWORD *)(a1 + 44064) + v11;
    v11 += 24;
    *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 1000) + 296LL) + v12) = v13;
    v12 += 72;
  }
  while ( v11 != 2400 );
  v14 = 0;
  v15 = 8;
  do
  {
    v16 = *(_QWORD *)(a1 + 44056) + v14;
    v14 += 24;
    *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 992) + 296LL) + v15) = v16;
    v15 += 72;
  }
  while ( v14 != 2400 );
  v17 = 0;
  v18 = 8;
  do
  {
    v3 = 0;
    v19 = *(_QWORD *)(a1 + 44072) + v17;
    v17 += 24;
    *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 1008) + 296LL) + v18) = v19;
    v18 += 72;
  }
  while ( v17 != 2400 );
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return v3;
}
