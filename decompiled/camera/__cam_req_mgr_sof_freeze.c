__int64 __fastcall _cam_req_mgr_sof_freeze(__int64 a1)
{
  __int64 v1; // x19
  __int64 task; // x0
  const char *v4; // x5
  __int64 v5; // x4

  if ( a1 == 8 )
  {
    v4 = "NULL timer";
    v5 = 2790;
  }
  else
  {
    v1 = *(_QWORD *)(a1 + 40);
    task = cam_req_mgr_workq_get_task(*(_QWORD *)(v1 + 24));
    if ( task )
    {
      **(_DWORD **)(task + 8) = 7;
      *(_QWORD *)(task + 16) = &_cam_req_mgr_process_sof_freeze;
      return cam_req_mgr_workq_enqueue_task(task, v1, 0);
    }
    v4 = "No empty task";
    v5 = 2798;
  }
  return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
           3,
           16,
           1,
           "__cam_req_mgr_sof_freeze",
           v5,
           v4);
}
