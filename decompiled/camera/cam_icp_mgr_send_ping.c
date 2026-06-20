__int64 __fastcall cam_icp_mgr_send_ping(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  int *task; // x0
  int *v6; // x23
  __int64 v7; // x21
  int v8; // w8
  __int64 v9; // x8
  unsigned int v10; // w0
  unsigned int v11; // w19
  __int64 result; // x0
  __int64 v13; // x0
  __int64 v14; // x21
  __int64 v15; // x1
  __int64 v16; // x22
  __int64 v17; // x0
  __int64 v18; // x23
  __int64 v19; // x1
  __int64 v20; // x24
  int v21; // w0
  __int64 v22; // x20
  unsigned int (__fastcall *v23)(__int64, __int64, int *, __int64); // x8
  __int64 v24; // x0
  const char *v25; // x5
  __int64 v26; // x6
  __int64 v27; // x4
  __int64 v28; // [xsp+20h] [xbp-20h] BYREF
  __int64 v29; // [xsp+28h] [xbp-18h]
  int v30; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v31; // [xsp+38h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 992);
  v28 = 0;
  v29 = 0;
  task = cam_req_mgr_workq_get_task(v4);
  if ( !task )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_send_ping",
      8315,
      "%s: No free task to send ping command",
      (const char *)(a2 + 29824));
LABEL_11:
    result = 4294967284LL;
    goto LABEL_12;
  }
  v6 = task;
  if ( mem_trace_en == 1 )
  {
    v7 = cam_mem_trace_alloc(24, 0xCC0u, 0, "cam_icp_mgr_send_ping", 0x207Fu);
    if ( v7 )
      goto LABEL_4;
    goto LABEL_10;
  }
  v7 = _kvmalloc_node_noprof(24, 0, 3520, 0xFFFFFFFFLL);
  if ( !v7 )
  {
LABEL_10:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_send_ping",
      8321,
      "Failed in allocating memory for ICP ctx info");
    goto LABEL_11;
  }
LABEL_4:
  v8 = *(_DWORD *)(a2 + 29224);
  *(_QWORD *)(v7 + 16) = a2;
  *(_DWORD *)(v7 + 4) = v8;
  v29 = v7;
  v28 = 0x1000500000010LL;
  *(_DWORD *)(a2 + 29192) = 0;
  _init_swait_queue_head(a2 + 29200, "&x->wait", &init_completion___key_9);
  v9 = *((_QWORD *)v6 + 1);
  *(_QWORD *)(v9 + 8) = &v28;
  *(_DWORD *)(v9 + 16) = 0;
  *(_DWORD *)v9 = 1;
  *((_QWORD *)v6 + 2) = cam_icp_mgr_process_cmd;
  v10 = cam_req_mgr_workq_enqueue_task((unsigned int *)v6, a1, 0);
  if ( !v10 )
  {
    v13 = ktime_get_with_offset(1);
    v14 = ns_to_timespec64(v13);
    v16 = v15;
    if ( cam_common_wait_for_completion_timeout(a2 + 29192) )
    {
      result = 0;
      goto LABEL_12;
    }
    v17 = ktime_get_with_offset(1);
    v18 = ns_to_timespec64(v17);
    v20 = v19;
    v21 = jiffies_to_msecs(1250, v19);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_send_ping",
      8349,
      "%s: FW response timeout for Ping handle command (timeout: %ums start: timestamp:[%lld:%06lld] end: timestamp:[%lld:%06lld])",
      (const char *)(a2 + 29824),
      v21,
      v14,
      v16 / 1000,
      v18,
      v20 / 1000);
    v22 = *(_QWORD *)(a1 + 80);
    if ( v22 )
    {
      v30 = 1;
      cam_icp_mgr_process_dbg_buf(a1);
      cam_hfi_queue_dump(*(unsigned int *)(a1 + 156), 0);
      v23 = *(unsigned int (__fastcall **)(__int64, __int64, int *, __int64))(v22 + 88);
      v24 = *(_QWORD *)(v22 + 112);
      if ( *((_DWORD *)v23 - 1) != -1055839300 )
        __break(0x8228u);
      if ( !v23(v24, 15, &v30, 4) )
        goto LABEL_23;
      v25 = "[%s] Fail to dump debug info";
      v26 = a1 + 112;
      v27 = 219;
    }
    else
    {
      v25 = "[%s] ICP device interface is NULL";
      v26 = a1 + 112;
      v27 = 208;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_dump_debug_info",
      v27,
      v25,
      v26);
LABEL_23:
    result = 4294967186LL;
    goto LABEL_12;
  }
  v11 = v10;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    256,
    1,
    "cam_icp_mgr_send_ping",
    8340,
    "Failed at enqueuing task to workq, ctx_id: %d",
    *(_DWORD *)(v7 + 4));
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)v7, 0);
  else
    kvfree(v7);
  result = v11;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
