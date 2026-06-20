__int64 __fastcall _cam_isp_ctx_offline_epoch_in_activated_state(__int64 *a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 *v4; // x21
  _QWORD *v5; // x22
  unsigned __int64 v7; // x1
  _QWORD *v8; // x8
  _QWORD *v9; // x9
  unsigned __int64 v10; // x20
  int *task; // x0
  int v12; // w0

  v2 = *a1;
  v4 = a1 + 5698;
  v5 = a1 + 4663;
  if ( a2 && *(_BYTE *)(a2 + 24) == 1 )
  {
    v7 = *(_QWORD *)a2;
    if ( v7 == *v5 )
    {
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "__cam_isp_ctx_offline_epoch_in_activated_state",
          3527,
          "SOF timestamp is updated at early time, qtimer: [%llu:%09llu], boot: [%llu:%09llu]",
          v7 / 0x3B9ACA00,
          v7 % 0x3B9ACA00,
          a1[4664] / 0x3B9ACA00uLL,
          a1[4664] % 0x3B9ACA00uLL);
    }
    else
    {
      _cam_isp_ctx_update_sof_ts(a1, v7, *(_QWORD *)(a2 + 16));
    }
  }
  *(_DWORD *)v4 = 1;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_offline_epoch_in_activated_state",
      3533,
      "SOF frame %lld ctx %u link: 0x%x",
      a1[1],
      *(_DWORD *)(v2 + 32),
      *(_DWORD *)(v2 + 64));
  v8 = (_QWORD *)(v2 + 128);
  v9 = *(_QWORD **)(v2 + 128);
  if ( v9 == (_QWORD *)(v2 + 128) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      2,
      "__cam_isp_ctx_offline_epoch_in_activated_state",
      3542,
      "Active list empty on ctx:%u link:0x%x - EPOCH serviced before RUP",
      *(_DWORD *)(v2 + 32),
      *(_DWORD *)(v2 + 64));
  }
  else
  {
    while ( v9 != v8 )
    {
      v10 = v9[3];
      v9 = (_QWORD *)*v9;
      if ( v10 > v5[3] )
      {
        v5[3] = v10;
        goto LABEL_17;
      }
    }
  }
  v10 = 0;
LABEL_17:
  task = cam_req_mgr_workq_get_task(v4[1]);
  if ( !task )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_schedule_apply_req",
      3496,
      "No task for worker");
    if ( !v10 )
      goto LABEL_22;
    goto LABEL_21;
  }
  *((_QWORD *)task + 2) = _cam_isp_ctx_apply_pending_req;
  v12 = cam_req_mgr_workq_enqueue_task((unsigned int *)task, (__int64)a1, 0);
  if ( v12 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_schedule_apply_req",
      3503,
      "Failed to schedule task rc:%d",
      v12);
  if ( v10 )
LABEL_21:
    _cam_isp_ctx_send_sof_timestamp((__int64)a1, v10, 0);
LABEL_22:
  _cam_isp_ctx_update_state_monitor_array((__int64)a1, 4, v10);
  return 0;
}
