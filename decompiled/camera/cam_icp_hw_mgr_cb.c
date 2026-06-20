__int64 __fastcall cam_icp_hw_mgr_cb(__int64 a1, char a2)
{
  __int64 v4; // x20
  int *task; // x0
  __int64 v6; // x8
  unsigned int v7; // w21

  if ( a1 )
  {
    v4 = raw_spin_lock_irqsave(a1 + 48);
    task = cam_req_mgr_workq_get_task(*(_QWORD *)(a1 + 1000));
    if ( task )
    {
      v6 = *((_QWORD *)task + 1);
      *(_QWORD *)(v6 + 8) = a1;
      *(_BYTE *)(v6 + 16) = a2 & 1;
      *(_DWORD *)v6 = 2;
      *((_QWORD *)task + 2) = cam_icp_mgr_process_cb;
      v7 = cam_req_mgr_workq_enqueue_task((unsigned int *)task, a1, 0);
      raw_spin_unlock_irqrestore(a1 + 48, v4);
      return v7;
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_hw_mgr_cb",
        3663,
        "no empty task");
      raw_spin_unlock_irqrestore(a1 + 48, v4);
      return 4294967284LL;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_hw_mgr_cb",
      3656,
      "irq cb data is NULL");
    return 0;
  }
}
