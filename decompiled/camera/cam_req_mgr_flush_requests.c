__int64 __fastcall cam_req_mgr_flush_requests(unsigned int *a1)
{
  unsigned int v1; // w6
  int *session_priv; // x0
  __int64 v5; // x1
  __int64 v6; // x7
  int v7; // w8
  __int64 link_priv; // x0
  __int64 v9; // x20
  __int64 task; // x0
  __int64 v11; // x8
  __int64 v12; // x21
  unsigned int v13; // w0
  unsigned int v14; // w19
  const char *v15; // x6
  const char *v16; // x5
  __int64 v17; // x4

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_flush_requests",
      5742,
      "flush req is NULL");
    return 4294967282LL;
  }
  v1 = a1[2];
  if ( v1 >= 2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_flush_requests",
      5747,
      "incorrect flush type %x",
      v1);
    return 4294967274LL;
  }
  mutex_lock(g_crm_core_dev + 16);
  session_priv = (int *)cam_get_session_priv(*a1);
  v6 = *a1;
  if ( !session_priv )
  {
    v7 = 0;
    v15 = "NULL";
LABEL_15:
    v16 = "session: %s, flush_info->ses_hdl:%x, session->ses_hdl:%x";
    v17 = 5758;
    goto LABEL_16;
  }
  v7 = *session_priv;
  if ( *session_priv != (_DWORD)v6 )
  {
    v15 = "Non-NULL";
    goto LABEL_15;
  }
  if ( !session_priv[1] )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      2,
      "cam_req_mgr_flush_requests",
      5764,
      "No active links in session %x",
      v6);
    v14 = 0;
    goto LABEL_17;
  }
  link_priv = cam_get_link_priv(a1[1], v5);
  v6 = a1[1];
  if ( link_priv )
  {
    v7 = *(_DWORD *)link_priv;
    v9 = link_priv;
    if ( *(_DWORD *)link_priv == (_DWORD)v6 )
    {
      task = cam_req_mgr_workq_get_task(*(_QWORD *)(link_priv + 24));
      if ( task )
      {
        v11 = *(_QWORD *)(task + 8);
        *(_DWORD *)v11 = 9;
        v12 = task;
        *(_QWORD *)(v11 + 24) = *((_QWORD *)a1 + 2);
        *(_DWORD *)(v11 + 12) = a1[1];
        *(_DWORD *)(v11 + 16) = a1[2];
        *(_DWORD *)(v11 + 20) = a1[3];
        *(_QWORD *)(task + 16) = cam_req_mgr_process_flush_req;
        *(_DWORD *)(v9 + 33120) = 0;
        _init_swait_queue_head(v9 + 33128, "&x->wait", &init_completion___key);
        v13 = cam_req_mgr_workq_enqueue_task(v12, v9, 0);
        if ( v13 )
        {
          v14 = v13;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            16,
            1,
            "cam_req_mgr_flush_requests",
            5794,
            "Failed to queue flush task rc: %d",
            v13);
        }
        else if ( cam_common_wait_for_completion_timeout(v9 + 33120, 250) )
        {
          v14 = 0;
        }
        else
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            16,
            2,
            "cam_req_mgr_flush_requests",
            5805,
            "Flush call timeout for session_hdl %u link_hdl %u type: %d",
            a1[1],
            *a1,
            a1[2]);
          v14 = -110;
        }
      }
      else
      {
        v14 = -12;
      }
      goto LABEL_17;
    }
    v15 = "Non-NULL";
  }
  else
  {
    v7 = 0;
    v15 = "NULL";
  }
  v16 = "link: %s, flush_info->link_hdl:%x, link->link_hdl:%x";
  v17 = 5772;
LABEL_16:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, const char *, __int64, int))cam_print_log)(
    3,
    16,
    1,
    "cam_req_mgr_flush_requests",
    v17,
    v16,
    v15,
    v6,
    v7);
  v14 = -22;
LABEL_17:
  mutex_unlock(g_crm_core_dev + 16);
  return v14;
}
