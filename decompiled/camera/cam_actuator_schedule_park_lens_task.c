__int64 __fastcall cam_actuator_schedule_park_lens_task(__int64 a1)
{
  int *task; // x0

  task = cam_req_mgr_workq_get_task(*(_QWORD *)(a1 + 4672));
  if ( task )
  {
    *((_QWORD *)task + 2) = cam_actuator_park_lens_cb;
    return cam_req_mgr_workq_enqueue_task((unsigned int *)task, a1, 0);
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x2000,
      1,
      "cam_actuator_schedule_park_lens_task",
      511,
      "No empty task available");
    return 4294967284LL;
  }
}
