__int64 __fastcall cam_req_mgr_cb_notify_timer(unsigned int *a1, __int64 a2)
{
  __int64 link_priv; // x0
  _DWORD *v4; // x19
  __int64 v5; // x22
  unsigned int v6; // w6
  __int64 result; // x0
  __int64 v8; // x8

  if ( a1 )
  {
    link_priv = cam_get_link_priv(*a1, a2);
    if ( link_priv )
    {
      v4 = (_DWORD *)link_priv;
      v5 = link_priv + 0x8000;
      raw_spin_lock_bh(link_priv + 33216);
      v6 = *(_DWORD *)(v5 + 384);
      if ( v6 > 1 )
      {
        v8 = *(_QWORD *)(v5 + 344);
        if ( v8 )
        {
          *(_BYTE *)(v8 + 64) = *((_BYTE *)a1 + 8) ^ 1;
          crm_timer_reset(*(_QWORD *)(v5 + 344));
          if ( (debug_mdl & 0x10) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x10,
              4,
              "cam_req_mgr_cb_notify_timer",
              4318,
              "link %x pause_timer %d",
              *v4,
              *(unsigned __int8 *)(*(_QWORD *)(v5 + 344) + 64LL));
        }
        raw_spin_unlock_bh(v4 + 8304);
        return 0;
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          16,
          2,
          "cam_req_mgr_cb_notify_timer",
          4306,
          "invalid link state:%d",
          v6);
        raw_spin_unlock_bh(v4 + 8304);
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
          "cam_req_mgr_cb_notify_timer",
          4299,
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
      "cam_req_mgr_cb_notify_timer",
      4292,
      "timer data  is NULL");
    return 4294967274LL;
  }
  return result;
}
