__int64 __fastcall cam_jpeg_hw_mgr_sched_bottom_half(int a1, int a2, __int64 a3)
{
  __int64 v6; // x19
  int *task; // x0
  __int64 v8; // x8
  unsigned int v9; // w20

  v6 = raw_spin_lock_irqsave(&dword_3A8CC8);
  task = cam_req_mgr_workq_get_task(qword_3AA0A8);
  if ( task )
  {
    v8 = *((_QWORD *)task + 1);
    *(_QWORD *)(v8 + 16) = a3;
    *(_DWORD *)(v8 + 4) = a2;
    *(_DWORD *)(v8 + 8) = a1;
    *(_DWORD *)v8 = 2;
    *((_QWORD *)task + 2) = cam_jpeg_mgr_bottom_half_irq;
    v9 = cam_req_mgr_workq_enqueue_task((unsigned int *)task, (__int64)&g_jpeg_hw_mgr, 0);
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_hw_mgr_sched_bottom_half",
      611,
      "no empty task");
    v9 = -12;
  }
  raw_spin_unlock_irqrestore(&dword_3A8CC8, v6);
  return v9;
}
