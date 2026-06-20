__int64 __fastcall cam_req_mgr_unlink(unsigned int *a1)
{
  int *session_priv; // x0
  __int64 v3; // x1
  int v4; // w7
  int v5; // w8
  __int64 v6; // x20
  unsigned int *link_priv; // x0
  unsigned int v8; // w7
  unsigned int v9; // w8
  unsigned int *v10; // x21
  unsigned int v11; // w19
  const char *v13; // x6
  const char *v14; // x6

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_unlink",
      5311,
      "NULL pointer");
    return 4294967274LL;
  }
  mutex_lock(g_crm_core_dev + 16);
  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10,
      4,
      "cam_req_mgr_unlink",
      5316,
      "link_hdl %x",
      a1[1]);
  session_priv = (int *)cam_get_session_priv(*a1);
  v4 = *a1;
  if ( !session_priv )
  {
    v5 = 0;
    v13 = "NULL";
LABEL_13:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_unlink",
      5323,
      "session: %s, unlink_info->ses_hdl:%x, cam_session->ses_hdl:%x",
      v13,
      v4,
      v5);
    mutex_unlock(g_crm_core_dev + 16);
    return 4294967274LL;
  }
  v5 = *session_priv;
  if ( *session_priv != v4 )
  {
    v13 = "Non-NULL";
    goto LABEL_13;
  }
  v6 = (__int64)session_priv;
  link_priv = (unsigned int *)cam_get_link_priv(a1[1], v3);
  v8 = a1[1];
  if ( !link_priv )
  {
    v9 = 0;
    v14 = "NULL";
LABEL_16:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_unlink",
      5333,
      "link: %s, unlink_info->link_hdl:%x, link->link_hdl:%x",
      v14,
      v8,
      v9);
    v11 = -22;
    goto LABEL_17;
  }
  v9 = *link_priv;
  if ( *link_priv != v8 )
  {
    v14 = "Non-NULL";
    goto LABEL_16;
  }
  v10 = link_priv;
  mutex_lock(v6 + 56);
  v11 = _cam_req_mgr_unlink(v6, v10);
  mutex_unlock(v6 + 56);
  _cam_req_mgr_unreserve_link(v6, (__int64)v10);
LABEL_17:
  mutex_unlock(g_crm_core_dev + 16);
  return v11;
}
