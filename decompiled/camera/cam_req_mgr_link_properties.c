__int64 __fastcall cam_req_mgr_link_properties(__int64 a1)
{
  __int64 v2; // x1
  int *link_priv; // x0
  int v4; // w7
  int v5; // w8
  int *v6; // x19
  int v7; // w24
  unsigned int v8; // w20
  const char *v9; // x6

  mutex_lock(g_crm_core_dev + 16);
  link_priv = (int *)cam_get_link_priv(*(unsigned int *)(a1 + 8), v2);
  v4 = *(_DWORD *)(a1 + 8);
  if ( !link_priv )
  {
    v5 = 0;
    v9 = "NULL";
LABEL_8:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_link_properties",
      5908,
      "link: %s, properties->link_hdl:0x%x, link->link_hdl:0x%x",
      v9,
      v4,
      v5);
    v8 = -22;
    goto LABEL_9;
  }
  v5 = *link_priv;
  v6 = link_priv;
  if ( *link_priv != v4 )
  {
    v9 = "Non-NULL";
    goto LABEL_8;
  }
  raw_spin_lock_bh(link_priv + 8304);
  v7 = v6[8288];
  raw_spin_unlock_bh(v6 + 8304);
  if ( v7 == 2 )
  {
    mutex_lock(v6 + 8292);
    v6[8341] = *(_DWORD *)(a1 + 12);
    v8 = _cam_req_mgr_send_evt(0, 7, 8, v6);
    if ( v8 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        16,
        1,
        "cam_req_mgr_link_properties",
        5931,
        "Failed to set properties on link 0x%x",
        *v6);
    }
    else if ( (debug_mdl & 0x10) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x10,
        4,
        "cam_req_mgr_link_properties",
        5934,
        "link 0x%x set properties mask:0x%x successfully",
        *v6,
        v6[8341]);
    }
    mutex_unlock(v6 + 8292);
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_link_properties",
      5918,
      "Only can config link 0x%x properties in ready state",
      *v6);
    v8 = -11;
  }
LABEL_9:
  mutex_unlock(g_crm_core_dev + 16);
  return v8;
}
