__int64 __fastcall _cam_isp_ctx_schedule_apply_req(__int64 a1)
{
  int *task; // x0
  __int64 result; // x0

  task = cam_req_mgr_workq_get_task(*(_QWORD *)(a1 + 45592));
  if ( !task )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             8,
             1,
             "__cam_isp_ctx_schedule_apply_req",
             3496,
             "No task for worker");
  *((_QWORD *)task + 2) = _cam_isp_ctx_apply_pending_req;
  result = cam_req_mgr_workq_enqueue_task((unsigned int *)task, a1, 0);
  if ( (_DWORD)result )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             8,
             1,
             "__cam_isp_ctx_schedule_apply_req",
             3503,
             "Failed to schedule task rc:%d",
             result);
  return result;
}
