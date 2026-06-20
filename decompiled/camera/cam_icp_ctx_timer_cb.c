__int64 __fastcall cam_icp_ctx_timer_cb(__int64 a1)
{
  __int64 v1; // x23
  __int64 v2; // x19
  __int64 v3; // x0
  __int64 v4; // x20
  __int64 v5; // x21
  int *task; // x0
  __int64 v7; // x8

  v1 = *(_QWORD *)(a1 + 40);
  v2 = *(_QWORD *)(v1 + 8);
  if ( mem_trace_en == 1 )
    v3 = cam_mem_trace_alloc(24, 0x820u, 0, "cam_icp_ctx_timer_cb", 0x352u);
  else
    v3 = _kvmalloc_node_noprof(24, 0, 2336, 0xFFFFFFFFLL);
  v4 = v3;
  if ( v3 )
  {
    *(_QWORD *)(v3 + 16) = v1;
    *(_DWORD *)(v3 + 4) = *(_DWORD *)(v1 + 29224);
    v5 = raw_spin_lock_irqsave(v2 + 48);
    task = cam_req_mgr_workq_get_task(*(_QWORD *)(v2 + 1008));
    if ( task )
    {
      v7 = *((_QWORD *)task + 1);
      *(_QWORD *)(v7 + 8) = v4;
      *(_DWORD *)v7 = 2;
      *((_QWORD *)task + 2) = cam_icp_ctx_timer;
      if ( !(unsigned int)cam_req_mgr_workq_enqueue_task((unsigned int *)task, v2, 0) )
        return raw_spin_unlock_irqrestore(v2 + 48, v5);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_ctx_timer_cb",
        875,
        "Failed at enqueuing task to workq, ctx_id: %d",
        *(_DWORD *)(v4 + 4));
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_ctx_timer_cb",
        862,
        "%s: empty task",
        (const char *)(v1 + 29824));
    }
    if ( mem_trace_en == 1 )
      cam_mem_trace_free((_QWORD *)v4, 0);
    else
      kvfree(v4);
    return raw_spin_unlock_irqrestore(v2 + 48, v5);
  }
  return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
           3,
           256,
           1,
           "cam_icp_ctx_timer_cb",
           852,
           "Failed in allocating ICP ctx info");
}
