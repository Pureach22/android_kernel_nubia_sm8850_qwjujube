__int64 __fastcall cam_req_mgr_link_v2(unsigned int *a1)
{
  unsigned int v1; // w6
  __int64 result; // x0
  int *session_priv; // x0
  unsigned int v5; // w7
  int v6; // w8
  __int64 v7; // x21
  char *v8; // x0
  char *v9; // x20
  unsigned int v10; // w8
  unsigned int link_hdl; // w0
  __int64 v12; // x8
  __int64 v13; // x0
  unsigned int v14; // w0
  unsigned int v15; // w0
  unsigned int v16; // w0
  const char *v17; // x6
  unsigned int v18; // w25
  __int64 v19; // x0
  _QWORD v20[2]; // [xsp+10h] [xbp-B0h] BYREF
  __int64 v21; // [xsp+20h] [xbp-A0h]
  __int64 v22; // [xsp+28h] [xbp-98h]
  char *v23; // [xsp+30h] [xbp-90h]
  char s[8]; // [xsp+38h] [xbp-88h] BYREF
  __int64 v25; // [xsp+40h] [xbp-80h]
  __int64 v26; // [xsp+48h] [xbp-78h]
  __int64 v27; // [xsp+50h] [xbp-70h]
  __int64 v28; // [xsp+58h] [xbp-68h]
  __int64 v29; // [xsp+60h] [xbp-60h]
  __int64 v30; // [xsp+68h] [xbp-58h]
  __int64 v31; // [xsp+70h] [xbp-50h]
  __int64 v32; // [xsp+78h] [xbp-48h]
  __int64 v33; // [xsp+80h] [xbp-40h]
  __int64 v34; // [xsp+88h] [xbp-38h]
  __int64 v35; // [xsp+90h] [xbp-30h]
  __int64 v36; // [xsp+98h] [xbp-28h]
  __int64 v37; // [xsp+A0h] [xbp-20h]
  __int64 v38; // [xsp+A8h] [xbp-18h]
  __int64 v39; // [xsp+B0h] [xbp-10h]
  __int64 v40; // [xsp+B8h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  *(_QWORD *)s = 0;
  v25 = 0;
  v21 = 0;
  v22 = 0;
  v20[0] = 0;
  v20[1] = 0;
  if ( a1 )
  {
    v1 = a1[2];
    if ( v1 >= 0x101 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        16,
        1,
        "cam_req_mgr_link_v2",
        5203,
        "Invalid num devices %d",
        v1);
LABEL_24:
      result = 4294967274LL;
      goto LABEL_25;
    }
    mutex_lock(g_crm_core_dev + 16);
    session_priv = (int *)cam_get_session_priv(a1[1]);
    v5 = a1[1];
    if ( session_priv )
    {
      v6 = *session_priv;
      if ( *session_priv == v5 )
      {
        v7 = (__int64)session_priv;
        v8 = _cam_req_mgr_reserve_link((__int64)session_priv);
        if ( v8 )
        {
          v9 = v8;
          if ( (debug_mdl & 0x10) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x10,
              4,
              "cam_req_mgr_link_v2",
              5226,
              "link reserved %pK %x",
              v8,
              *(_DWORD *)v8);
          v10 = a1[1];
          v23 = v9;
          LODWORD(v20[0]) = v10;
          v21 = 16;
          mutex_lock(v9 + 33168);
          link_hdl = cam_create_link_hdl(v20);
          *(_DWORD *)v9 = link_hdl;
          if ( (link_hdl & 0x80000000) != 0 )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              16,
              1,
              "cam_req_mgr_link_v2",
              5237,
              "Insufficient memory to create new device handle");
            v18 = *(_DWORD *)v9;
LABEL_35:
            mutex_unlock(v9 + 33168);
            _cam_req_mgr_unreserve_link(v7, (__int64)v9);
            mutex_unlock(g_crm_core_dev + 16);
            result = v18;
            goto LABEL_25;
          }
          a1[259] = link_hdl;
          *((_QWORD *)v9 + 4158) = 0;
          v12 = (int)a1[2];
          if ( mem_trace_en == 1 )
          {
            v13 = cam_mem_trace_alloc(320 * v12, 3264, 0, "__cam_req_mgr_create_subdevs", 2822);
            *((_QWORD *)v9 + 5) = v13;
            if ( v13 )
            {
LABEL_16:
              v14 = ((__int64 (__fastcall *)(char *, unsigned int *))_cam_req_mgr_setup_link_info)(v9, a1);
              if ( (v14 & 0x80000000) != 0 )
              {
                v18 = v14;
              }
              else
              {
                raw_spin_lock_bh(v9 + 33216);
                *((_DWORD *)v9 + 8288) = 2;
                raw_spin_unlock_bh(v9 + 33216);
                snprintf(s, 0x80u, "%x-%x", a1[1], *(_DWORD *)v9);
                v15 = cam_req_mgr_workq_create(s, 60, v9 + 24, 0, 3, cam_req_mgr_process_workq_link_worker);
                if ( (v15 & 0x80000000) != 0 )
                {
                  v18 = v15;
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    16,
                    1,
                    "cam_req_mgr_link_v2",
                    5270,
                    "FATAL: unable to create worker");
                  _cam_req_mgr_destroy_link_info((__int64)v9);
                }
                else
                {
                  v16 = _cam_req_mgr_setup_payload(*((_QWORD *)v9 + 3));
                  if ( (v16 & 0x80000000) == 0 )
                  {
                    *((_QWORD *)v9 + 4165) = 0;
                    *(_QWORD *)(v9 + 33332) = 0;
                    mutex_unlock(v9 + 33168);
                    mutex_unlock(g_crm_core_dev + 16);
                    result = 0;
                    goto LABEL_25;
                  }
                  v18 = v16;
                  _cam_req_mgr_destroy_link_info((__int64)v9);
                  cam_req_mgr_workq_destroy(v9 + 24);
                }
              }
              _cam_req_mgr_destroy_subdev((const void **)v9 + 5);
              goto LABEL_34;
            }
          }
          else
          {
            v19 = _kvmalloc_node_noprof(320 * v12, 0, 3520, 0xFFFFFFFFLL);
            *((_QWORD *)v9 + 5) = v19;
            if ( v19 )
              goto LABEL_16;
          }
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            16,
            1,
            "cam_req_mgr_link_v2",
            5249,
            "Insufficient memory to create new crm subdevs");
          v18 = -12;
LABEL_34:
          cam_destroy_link_hdl(*(unsigned int *)v9);
          a1[259] = -1;
          goto LABEL_35;
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          16,
          1,
          "cam_req_mgr_link_v2",
          5222,
          "failed to reserve new link");
LABEL_23:
        mutex_unlock(g_crm_core_dev + 16);
        goto LABEL_24;
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
      "cam_req_mgr_link_v2",
      5214,
      "session: %s, link_info->ses_hdl:%x, session->ses_hdl:%x",
      v17,
      v5,
      v6);
    goto LABEL_23;
  }
  result = 4294967274LL;
  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x10,
      4,
      "cam_req_mgr_link_v2",
      5197,
      "NULL pointer");
    goto LABEL_24;
  }
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
