__int64 __fastcall cam_req_mgr_destroy_session(unsigned int *a1, char a2)
{
  int *session_priv; // x0
  unsigned int v5; // w7
  int v6; // w8
  int *v7; // x20
  char v8; // w23
  __int64 v9; // x21
  __int64 v10; // x21
  __int64 v11; // x21
  __int64 v12; // x21
  int **v13; // x8
  _DWORD *v14; // x0
  __int64 v15; // x9
  unsigned int v16; // w20
  const char *v17; // x6

  if ( a1 )
  {
    mutex_lock(g_crm_core_dev + 16);
    session_priv = (int *)cam_get_session_priv(*a1);
    v5 = *a1;
    if ( session_priv )
    {
      v6 = *session_priv;
      v7 = session_priv;
      if ( *session_priv == v5 )
      {
        mutex_lock(session_priv + 14);
        if ( !v7[1] )
        {
LABEL_27:
          v13 = *((int ***)v7 + 6);
          v14 = v7 + 10;
          if ( *v13 == v7 + 10 && (v15 = *(_QWORD *)v14, *(_DWORD **)(*(_QWORD *)v14 + 8LL) == v14) )
          {
            *(_QWORD *)(v15 + 8) = v13;
            *v13 = (int *)v15;
          }
          else
          {
            _list_del_entry_valid_or_report();
          }
          *((_QWORD *)v7 + 5) = 0xDEAD000000000100LL;
          *((_QWORD *)v7 + 6) = 0xDEAD000000000122LL;
          mutex_unlock(v7 + 14);
          if ( mem_trace_en == 1 )
            cam_mem_trace_free(v7, 0);
          else
            kvfree(v7);
          v16 = cam_destroy_session_hdl(*a1);
          if ( (v16 & 0x80000000) != 0 )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              16,
              1,
              "cam_req_mgr_destroy_session",
              5065,
              "unable to destroy session_hdl = %x rc %d",
              *a1,
              v16);
          goto LABEL_41;
        }
        v8 = a2 & 1;
        if ( (debug_mdl & 0x10) != 0 && !debug_priority )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
            3,
            debug_mdl & 0x10,
            4,
            "cam_req_mgr_destroy_session",
            5041,
            "destroy session %x num_active_links %d",
            *a1);
          v9 = *((_QWORD *)v7 + 1);
          if ( v9 )
          {
LABEL_8:
            if ( (debug_mdl & 0x10) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x10,
                4,
                "cam_req_mgr_destroy_session",
                5049,
                "Unlink link hdl 0x%x",
                *(_DWORD *)v9);
            *(_BYTE *)(v9 + 33292) = v8;
            _cam_req_mgr_unlink(v7, v9);
            _cam_req_mgr_free_link(v9);
          }
        }
        else
        {
          v9 = *((_QWORD *)v7 + 1);
          if ( v9 )
            goto LABEL_8;
        }
        v10 = *((_QWORD *)v7 + 2);
        if ( v10 )
        {
          if ( (debug_mdl & 0x10) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x10,
              4,
              "cam_req_mgr_destroy_session",
              5049,
              "Unlink link hdl 0x%x",
              *(_DWORD *)v10);
          *(_BYTE *)(v10 + 33292) = v8;
          _cam_req_mgr_unlink(v7, v10);
          _cam_req_mgr_free_link(v10);
        }
        v11 = *((_QWORD *)v7 + 3);
        if ( v11 )
        {
          if ( (debug_mdl & 0x10) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x10,
              4,
              "cam_req_mgr_destroy_session",
              5049,
              "Unlink link hdl 0x%x",
              *(_DWORD *)v11);
          *(_BYTE *)(v11 + 33292) = v8;
          _cam_req_mgr_unlink(v7, v11);
          _cam_req_mgr_free_link(v11);
        }
        v12 = *((_QWORD *)v7 + 4);
        if ( v12 )
        {
          if ( (debug_mdl & 0x10) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x10,
              4,
              "cam_req_mgr_destroy_session",
              5049,
              "Unlink link hdl 0x%x",
              *(_DWORD *)v12);
          *(_BYTE *)(v12 + 33292) = v8;
          _cam_req_mgr_unlink(v7, v12);
          _cam_req_mgr_free_link(v12);
        }
        goto LABEL_27;
      }
      v17 = "Non-NULL";
    }
    else
    {
      v6 = 0;
      v17 = "NULL";
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_destroy_session",
      5031,
      "session: %s, ses_info->ses_hdl:%x, session->ses_hdl:%x",
      v17,
      v5,
      v6);
    v16 = -2;
LABEL_41:
    mutex_unlock(g_crm_core_dev + 16);
    return v16;
  }
  v16 = -22;
  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x10,
      4,
      "cam_req_mgr_destroy_session",
      5022,
      "NULL session info pointer");
  return v16;
}
