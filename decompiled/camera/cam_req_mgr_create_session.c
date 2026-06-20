__int64 __fastcall cam_req_mgr_create_session(unsigned int *a1)
{
  __int64 v2; // x0
  unsigned int session_hdl; // w20
  __int64 v4; // x19
  __int64 v5; // x0
  __int64 v6; // x1
  __int64 v7; // x2

  if ( a1 )
  {
    mutex_lock(g_crm_core_dev + 16);
    if ( mem_trace_en == 1 )
      v2 = cam_mem_trace_alloc(112, 3264, 0, "cam_req_mgr_create_session", 4921);
    else
      v2 = _kvmalloc_node_noprof(112, 0, 3520, 0xFFFFFFFFLL);
    v4 = v2;
    if ( v2 )
    {
      session_hdl = cam_create_session_hdl(v2);
      if ( (session_hdl & 0x80000000) != 0 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          16,
          1,
          "cam_req_mgr_create_session",
          4930,
          "unable to create session_hdl = %x",
          session_hdl);
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v4, 0);
        else
          kvfree(v4);
      }
      else
      {
        *a1 = session_hdl;
        _mutex_init(v4 + 56, "&cam_session->lock", &cam_req_mgr_create_session___key);
        if ( (debug_mdl & 0x10) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x10,
            4,
            "cam_req_mgr_create_session",
            4939,
            "LOCK_DBG session lock %pK hdl 0x%x",
            (const void *)(v4 + 56),
            session_hdl);
        mutex_lock(v4 + 56);
        *(_DWORD *)v4 = session_hdl;
        *(_DWORD *)(v4 + 4) = 0;
        v5 = v4 + 40;
        v6 = g_crm_core_dev;
        *(_DWORD *)(v4 + 108) = 0;
        v7 = *(_QWORD *)v6;
        if ( *(_QWORD *)(*(_QWORD *)v6 + 8LL) != v6 || v5 == v6 || v7 == v5 )
        {
          _list_add_valid_or_report(v5);
        }
        else
        {
          *(_QWORD *)(v7 + 8) = v5;
          *(_QWORD *)(v4 + 40) = v7;
          *(_QWORD *)(v4 + 48) = v6;
          *(_QWORD *)v6 = v5;
        }
        mutex_unlock(v4 + 56);
        session_hdl = 0;
      }
    }
    else
    {
      session_hdl = -12;
    }
    mutex_unlock(g_crm_core_dev + 16);
  }
  else
  {
    session_hdl = -22;
    if ( (debug_mdl & 0x10) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x10,
        4,
        "cam_req_mgr_create_session",
        4916,
        "NULL session info pointer");
  }
  return session_hdl;
}
