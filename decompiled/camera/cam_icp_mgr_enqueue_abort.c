__int64 __fastcall cam_icp_mgr_enqueue_abort(__int64 a1)
{
  __int64 v2; // x19
  int *task; // x0
  int *v4; // x21
  __int64 v5; // x0
  __int64 result; // x0
  __int64 v7; // x22
  int v8; // w8
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x21
  __int64 v12; // x1
  __int64 v13; // x22
  __int64 v14; // x0
  __int64 v15; // x23
  __int64 v16; // x1
  __int64 v17; // x24
  int v18; // w0
  __int64 v19; // x21
  __int64 (__fastcall *v20)(__int64, __int64, int *, __int64); // x8
  __int64 v21; // x0
  const char *v22; // x5
  __int64 v23; // x6
  __int64 v24; // x4
  __int64 v25; // x21
  unsigned int v32; // w9
  unsigned int v35; // w10
  int v36; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v37; // [xsp+28h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 8);
  task = cam_req_mgr_workq_get_task(*(_QWORD *)(v2 + 992));
  if ( !task )
  {
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               256,
               1,
               "cam_icp_mgr_enqueue_abort",
               7684,
               "%s: no empty task",
               (const char *)(a1 + 29824));
    goto LABEL_39;
  }
  v4 = task;
  if ( mem_trace_en == 1 )
    v5 = cam_mem_trace_alloc(24, 0xCC0u, 0, "cam_icp_mgr_enqueue_abort", 0x1E08u);
  else
    v5 = _kvmalloc_node_noprof(24, 0, 3520, 0xFFFFFFFFLL);
  v7 = v5;
  if ( !v5 )
  {
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               256,
               1,
               "cam_icp_mgr_enqueue_abort",
               7690,
               "Failed in allocating memory for ICP ctx info");
    goto LABEL_39;
  }
  v8 = *(_DWORD *)(a1 + 29224);
  *(_QWORD *)(v5 + 8) = v2;
  *(_QWORD *)(v5 + 16) = a1;
  *(_DWORD *)(v5 + 4) = v8;
  *(_DWORD *)(a1 + 29192) = 0;
  v9 = *((_QWORD *)v4 + 1);
  *(_QWORD *)(v9 + 8) = v5;
  *(_DWORD *)v9 = 1;
  *((_QWORD *)v4 + 2) = cam_icp_mgr_abort_handle_wq;
  _X8 = (unsigned int *)(v2 + 44176);
  __asm { PRFM            #0x11, [X8] }
  do
    v32 = __ldxr(_X8);
  while ( __stxr(v32 + 1, _X8) );
  cam_icp_update_clk_util(*(unsigned int *)(a1 + 29300), v2, a1);
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_mgr_enqueue_abort",
      7708,
      "[%s] voting device to %u rate",
      (const char *)(v2 + 112),
      *(_DWORD *)(a1 + 29300));
  if ( !(unsigned int)cam_req_mgr_workq_enqueue_task((unsigned int *)v4, v2, 0) )
  {
    v10 = ktime_get_with_offset(1);
    v11 = ns_to_timespec64(v10);
    v13 = v12;
    result = cam_common_wait_for_completion_timeout(a1 + 29192);
    if ( result )
    {
      if ( (debug_mdl & 0x100) != 0 && !debug_priority )
        result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                   3,
                   debug_mdl & 0x100,
                   4,
                   "cam_icp_mgr_enqueue_abort",
                   7734,
                   "%s: Abort after flush is success",
                   (const char *)(a1 + 29824));
      goto LABEL_34;
    }
    v14 = ktime_get_with_offset(1);
    v15 = ns_to_timespec64(v14);
    v17 = v16;
    v18 = jiffies_to_msecs(500, v16);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_enqueue_abort",
      7722,
      "%s FW response timeout for Abort handle command (timeout: %ums start: timestamp:[%lld:%06lld] end: timestamp:[%lld:%06lld])",
      (const char *)(a1 + 29824),
      v18,
      v11,
      v13 / 1000,
      v15,
      v17 / 1000);
    v19 = *(_QWORD *)(v2 + 80);
    if ( v19 )
    {
      v36 = 1;
      cam_icp_mgr_process_dbg_buf(v2);
      cam_hfi_queue_dump(*(unsigned int *)(v2 + 156), 0);
      v20 = *(__int64 (__fastcall **)(__int64, __int64, int *, __int64))(v19 + 88);
      v21 = *(_QWORD *)(v19 + 112);
      if ( *((_DWORD *)v20 - 1) != -1055839300 )
        __break(0x8228u);
      result = v20(v21, 15, &v36, 4);
      if ( !(_DWORD)result )
        goto LABEL_26;
      v22 = "[%s] Fail to dump debug info";
      v23 = v2 + 112;
      v24 = 219;
    }
    else
    {
      v22 = "[%s] ICP device interface is NULL";
      v23 = v2 + 112;
      v24 = 208;
    }
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
               3,
               256,
               1,
               "cam_icp_dump_debug_info",
               v24,
               v22,
               v23);
LABEL_26:
    *(_BYTE *)(a1 + 30000) = 1;
    if ( *(_BYTE *)(v2 + 44260) == 1 )
      panic("CAMERA - [%s] FLUSH abort timeout......\n", (const char *)(v2 + 112));
    goto LABEL_34;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    256,
    1,
    "cam_icp_mgr_enqueue_abort",
    7713,
    "Failed at enqueuing task to workq, ctx_id: %d",
    *(_DWORD *)(v7 + 4));
  if ( mem_trace_en == 1 )
    result = (__int64)cam_mem_trace_free((_QWORD *)v7, 0);
  else
    result = kvfree(v7);
LABEL_34:
  _X8 = (unsigned int *)(v2 + 44176);
  __asm { PRFM            #0x11, [X8] }
  do
    v35 = __ldxr(_X8);
  while ( __stxr(v35 - 1, _X8) );
  if ( !*(_DWORD *)(v2 + 44176) )
  {
    v25 = *(_QWORD *)(a1 + 16);
    result = cam_icp_update_clk_util(*(unsigned int *)(v25 + 28), v2, a1);
    if ( (debug_mdl & 0x100) != 0 && !debug_priority )
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 debug_mdl & 0x100,
                 4,
                 "cam_icp_mgr_enqueue_abort",
                 7743,
                 "[%s] voting device back to %u rate",
                 (const char *)(v2 + 112),
                 *(_DWORD *)(v25 + 28));
  }
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return result;
}
