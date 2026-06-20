__int64 __fastcall cam_req_mgr_cb_notify_err(unsigned int *a1, __int64 a2)
{
  __int64 link_priv; // x0
  __int64 v4; // x20
  __int64 v5; // x21
  __int64 v6; // x8
  __int64 v7; // x10
  int v8; // w6
  __int64 task; // x0
  __int64 v10; // x8
  __int64 result; // x0
  _QWORD s[39]; // [xsp+8h] [xbp-138h] BYREF

  s[38] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    link_priv = cam_get_link_priv(*a1, a2);
    if ( link_priv )
    {
      v4 = link_priv;
      v5 = link_priv + 0x8000;
      memset(s, 0, 0x130u);
      LODWORD(s[0]) = 4;
      v6 = *((_QWORD *)a1 + 1);
      v7 = *((_QWORD *)a1 + 2);
      LODWORD(s[2]) = -1;
      s[1] = v6;
      s[3] = v7;
      ((void (__fastcall *)(__int64, _QWORD *))_cam_req_mgr_update_state_monitor_array)(v4, s);
      raw_spin_lock_bh(v4 + 33216);
      v8 = *(_DWORD *)(v5 + 384);
      if ( v8 == 2 )
      {
        crm_timer_reset(*(_QWORD *)(v5 + 344));
        raw_spin_unlock_bh(v4 + 33216);
        task = cam_req_mgr_workq_get_task(*(_QWORD *)(v4 + 24));
        if ( task )
        {
          v10 = *(_QWORD *)(task + 8);
          *(_DWORD *)v10 = 6;
          *(_QWORD *)(v10 + 16) = *((_QWORD *)a1 + 1);
          *(_DWORD *)(v10 + 8) = *a1;
          *(_DWORD *)(v10 + 12) = a1[1];
          *(_DWORD *)(v10 + 48) = a1[10];
          *(_DWORD *)(v10 + 32) = a1[6];
          *(_QWORD *)(task + 16) = cam_req_mgr_process_error;
          result = cam_req_mgr_workq_enqueue_task(task, v4, 0);
        }
        else
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            16,
            1,
            "cam_req_mgr_cb_notify_err",
            4219,
            "no empty task req_id %lld",
            *((_QWORD *)a1 + 1));
          result = 4294967280LL;
        }
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          16,
          2,
          "cam_req_mgr_cb_notify_err",
          4209,
          "invalid link state:%d",
          v8);
        raw_spin_unlock_bh(v4 + 33216);
        result = 0xFFFFFFFFLL;
      }
    }
    else
    {
      result = 4294967274LL;
      if ( (debug_mdl & 0x10) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x10,
          4,
          "cam_req_mgr_cb_notify_err",
          4196,
          "link ptr NULL %x",
          *a1);
        result = 4294967274LL;
      }
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_cb_notify_err",
      4189,
      "err_info is NULL");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
