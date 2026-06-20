__int64 __fastcall cam_req_mgr_cb_notify_stop(unsigned int *a1, __int64 a2)
{
  __int64 link_priv; // x0
  __int64 v4; // x19
  __int64 v5; // x22
  int v6; // w6
  __int64 task; // x0
  _DWORD *v8; // x8
  __int64 result; // x0

  if ( a1 )
  {
    link_priv = cam_get_link_priv(*a1, a2);
    if ( link_priv )
    {
      v4 = link_priv;
      v5 = link_priv + 0x8000;
      raw_spin_lock_bh(link_priv + 33216);
      v6 = *(_DWORD *)(v5 + 384);
      if ( v6 == 2 )
      {
        crm_timer_reset(*(_QWORD *)(v5 + 344));
        *(_BYTE *)(*(_QWORD *)(v5 + 344) + 64LL) = 1;
        raw_spin_unlock_bh(v4 + 33216);
        task = cam_req_mgr_workq_get_task(*(_QWORD *)(v4 + 24));
        if ( task )
        {
          v8 = *(_DWORD **)(task + 8);
          *v8 = 6;
          v8[2] = *a1;
          *(_QWORD *)(task + 16) = cam_req_mgr_process_stop;
          return cam_req_mgr_workq_enqueue_task(task, v4, 0);
        }
        else
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            16,
            1,
            "cam_req_mgr_cb_notify_stop",
            4371,
            "no empty task");
          return 4294967280LL;
        }
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          16,
          2,
          "cam_req_mgr_cb_notify_stop",
          4360,
          "invalid link state:%d",
          v6);
        raw_spin_unlock_bh(v4 + 33216);
        return 0xFFFFFFFFLL;
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
          "cam_req_mgr_cb_notify_stop",
          4353,
          "link ptr NULL %x",
          *a1);
        return 4294967274LL;
      }
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_cb_notify_stop",
      4346,
      "stop_info is NULL");
    return 4294967274LL;
  }
  return result;
}
