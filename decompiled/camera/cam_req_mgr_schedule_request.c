__int64 __fastcall cam_req_mgr_schedule_request(__int64 a1)
{
  __int64 v2; // x1
  __int64 link_priv; // x0
  int v4; // w7
  int v5; // w8
  __int64 v6; // x6
  __int64 v7; // x7
  unsigned int v8; // w20
  const char *v9; // x6

  _ReadStatusReg(SP_EL0);
  if ( a1 )
  {
    mutex_lock(g_crm_core_dev + 16);
    link_priv = cam_get_link_priv(*(unsigned int *)(a1 + 4), v2);
    v4 = *(_DWORD *)(a1 + 4);
    if ( link_priv )
    {
      v5 = *(_DWORD *)link_priv;
      if ( *(_DWORD *)link_priv == v4 )
      {
        if ( *(_QWORD *)(link_priv + 33160) )
        {
          v6 = *(_QWORD *)(a1 + 24);
          v7 = *(_QWORD *)(link_priv + 33264);
          if ( v6 <= v7 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              16,
              3,
              "cam_req_mgr_schedule_request",
              5382,
              "request %lld is flushed, last_flush_id to flush %d",
              v6,
              v7);
            v8 = -53;
          }
          else
          {
            *(_QWORD *)(link_priv + 33264) = 0;
            if ( (debug_mdl & 0x10) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x10,
                4,
                "cam_req_mgr_schedule_request",
                5391,
                "link 0x%x req %lld, sync_mode %d",
                *(_DWORD *)(a1 + 4),
                *(_QWORD *)(a1 + 24),
                *(_DWORD *)(a1 + 12));
            v8 = ((__int64 (*)(void))cam_req_mgr_process_sched_req)();
            if ( (debug_mdl & 0x1000010) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x1000010,
                4,
                "cam_req_mgr_schedule_request",
                5409,
                "Open req %lld on link 0x%x with sync_mode %d",
                *(_QWORD *)(a1 + 24),
                *(_DWORD *)(a1 + 4),
                *(_DWORD *)(a1 + 12));
          }
          goto LABEL_15;
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          16,
          2,
          "cam_req_mgr_schedule_request",
          5374,
          "session ptr NULL %x",
          v4);
LABEL_14:
        v8 = -22;
LABEL_15:
        mutex_unlock(g_crm_core_dev + 16);
        goto LABEL_16;
      }
      v9 = "Non-NULL";
    }
    else
    {
      v5 = 0;
      v9 = "NULL";
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_schedule_request",
      5367,
      "link: %s, sched_req->link_hdl:%x, link->link_hdl:%x",
      v9,
      v4,
      v5);
    goto LABEL_14;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    16,
    1,
    "cam_req_mgr_schedule_request",
    5358,
    "csl_req is NULL");
  v8 = -22;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return v8;
}
