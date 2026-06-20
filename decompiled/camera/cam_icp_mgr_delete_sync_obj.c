_QWORD *__fastcall cam_icp_mgr_delete_sync_obj(__int64 a1)
{
  __int64 v1; // x20
  int *task; // x0
  int *v4; // x21
  __int64 v5; // x0
  _QWORD *result; // x0
  __int64 v7; // x22
  __int64 v8; // x8

  v1 = *(_QWORD *)(a1 + 8);
  task = cam_req_mgr_workq_get_task(*(_QWORD *)(v1 + 992));
  if ( !task )
    return (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       3,
                       256,
                       1,
                       "cam_icp_mgr_delete_sync_obj",
                       7562,
                       "%s: no empty task",
                       (const char *)(a1 + 29824));
  v4 = task;
  if ( mem_trace_en == 1 )
    v5 = cam_mem_trace_alloc(24, 0x820u, 0, "cam_icp_mgr_delete_sync_obj", 0x1D8Eu);
  else
    v5 = _kvmalloc_node_noprof(24, 0, 2336, 0xFFFFFFFFLL);
  v7 = v5;
  if ( !v5 )
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       256,
                       1,
                       "cam_icp_mgr_delete_sync_obj",
                       7568,
                       "Failed in allocating ICP ctx info");
  *(_QWORD *)(v5 + 16) = a1;
  *(_DWORD *)(v5 + 4) = *(_DWORD *)(a1 + 29224);
  v8 = *((_QWORD *)v4 + 1);
  *(_QWORD *)(v8 + 8) = v5;
  *(_DWORD *)(v8 + 16) = 0;
  *(_DWORD *)v8 = 1;
  *((_QWORD *)v4 + 2) = cam_icp_mgr_delete_sync;
  result = (_QWORD *)cam_req_mgr_workq_enqueue_task((unsigned int *)v4, v1, 0);
  if ( (_DWORD)result )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_delete_sync_obj",
      7583,
      "Failed at enqueuing task to workq, ctx_id: %d",
      *(_DWORD *)(v7 + 4));
    if ( mem_trace_en == 1 )
      return cam_mem_trace_free((_QWORD *)v7, 0);
    else
      return (_QWORD *)kvfree(v7);
  }
  return result;
}
