__int64 __fastcall cam_icp_device_timer_cb(__int64 a1)
{
  __int64 v2; // x19
  __int64 v3; // x20
  int *task; // x0
  __int64 v5; // x8

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 568LL);
  v3 = raw_spin_lock_irqsave(v2 + 48);
  task = cam_req_mgr_workq_get_task(*(_QWORD *)(v2 + 1008));
  if ( task )
  {
    v5 = *((_QWORD *)task + 1);
    *(_QWORD *)(v5 + 8) = *(_QWORD *)(a1 + 40);
    *(_DWORD *)v5 = 2;
    *((_QWORD *)task + 2) = cam_icp_deinit_idle_clk;
    cam_req_mgr_workq_enqueue_task((unsigned int *)task, v2, 0);
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_device_timer_cb",
      895,
      "[%s] empty task",
      (const char *)(v2 + 112));
  }
  return raw_spin_unlock_irqrestore(v2 + 48, v3);
}
