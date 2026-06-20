__int64 __fastcall cam_req_mgr_schedule_request_v3(__int64 a1)
{
  __int64 v2; // x1
  unsigned int *link_priv; // x0
  __int64 v4; // x1
  unsigned int v5; // w7
  int v6; // w8
  __int64 v7; // x23
  __int64 v8; // x6
  __int64 v9; // x7
  int v10; // w8
  unsigned int v11; // w10
  int v12; // w9
  __int64 v13; // x7
  int v14; // w9
  int v15; // w10
  int v16; // w9
  int v17; // w9
  const char *v18; // x6
  unsigned int v19; // w20
  const char *v21; // x5
  __int64 v22; // x2
  __int64 v23; // x4
  __int64 v24; // x6
  int v25; // w8
  unsigned int v26; // w8
  _DWORD *v27; // x23
  unsigned int *v28; // x24
  int *v29; // x0
  __int64 v30; // x1
  int v31; // w8
  int v32; // w8
  __int64 v33; // x0
  int *v34; // x0
  __int64 v35; // x1
  __int64 v36; // x0
  int *v37; // x0
  __int64 v38; // x1
  __int64 v39; // x0
  int *v40; // x0
  __int64 v41; // x1
  __int64 v42; // x0
  __int64 v43; // x6
  const char *v44; // x7
  unsigned int *v45; // x24
  int v46; // [xsp+8h] [xbp-58h]
  __int64 v47; // [xsp+10h] [xbp-50h] BYREF
  __int64 v48; // [xsp+18h] [xbp-48h]
  __int64 v49; // [xsp+20h] [xbp-40h]
  __int64 v50; // [xsp+28h] [xbp-38h]
  __int64 v51; // [xsp+30h] [xbp-30h]
  __int64 v52; // [xsp+38h] [xbp-28h]
  __int64 v53; // [xsp+40h] [xbp-20h]
  __int64 v54; // [xsp+48h] [xbp-18h]
  __int64 v55; // [xsp+50h] [xbp-10h]
  __int64 v56; // [xsp+58h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  v47 = 0;
  mutex_lock(g_crm_core_dev + 16);
  link_priv = (unsigned int *)cam_get_link_priv(*(unsigned int *)(a1 + 8), v2);
  v5 = *(_DWORD *)(a1 + 8);
  if ( !link_priv )
  {
    v6 = 0;
    v18 = "NULL";
LABEL_12:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_schedule_request_v3",
      5534,
      "link: %s, sched_req->link_hdl:%x, link->link_hdl:%x",
      v18,
      v5,
      v6);
LABEL_13:
    v19 = -22;
    goto LABEL_14;
  }
  v6 = *link_priv;
  if ( *link_priv != v5 )
  {
    v18 = "Non-NULL";
    goto LABEL_12;
  }
  v7 = *((_QWORD *)link_priv + 4145);
  if ( !v7 )
  {
    v21 = "session ptr NULL %x";
    v22 = 2;
    v23 = 5541;
    v24 = v5;
LABEL_16:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      16,
      v22,
      "cam_req_mgr_schedule_request_v3",
      v23,
      v21,
      v24);
    goto LABEL_13;
  }
  v8 = *(_QWORD *)(a1 + 32);
  v9 = *((_QWORD *)link_priv + 4158);
  if ( v8 <= v9 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      3,
      "cam_req_mgr_schedule_request_v3",
      5549,
      "request %lld is flushed, last_flush_id to flush %d",
      v8,
      v9);
    v19 = -53;
    goto LABEL_14;
  }
  *((_QWORD *)link_priv + 4158) = 0;
  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
  {
    v45 = link_priv;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10,
      4,
      "cam_req_mgr_schedule_request_v3",
      5559,
      "link 0x%x req %lld, sync_mode %d num_links %d",
      *(_DWORD *)(a1 + 8),
      *(_QWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 16),
      *(_DWORD *)(a1 + 24));
    link_priv = v45;
  }
  v10 = *(_DWORD *)(a1 + 16);
  v11 = *(_DWORD *)(a1 + 20);
  v12 = *(_DWORD *)(a1 + 8);
  v13 = *(_QWORD *)(a1 + 32);
  LODWORD(v47) = 0;
  v48 = 0;
  v53 = 0;
  v54 = 0;
  HIDWORD(v47) = v12;
  v14 = *(_DWORD *)(a1 + 40);
  v50 = v13;
  HIDWORD(v48) = v10;
  v49 = v11;
  v15 = *(_DWORD *)(a1 + 28);
  v51 = 0;
  LODWORD(v52) = 0;
  HIDWORD(v52) = v15;
  LODWORD(v53) = v14;
  v16 = *(_DWORD *)(v7 + 104);
  v54 = a1 + 44;
  v55 = 0;
  if ( v16 )
    v17 = v16 == 1;
  else
    v17 = *(_DWORD *)(a1 + 12);
  LODWORD(v48) = v17;
  if ( v10 == 1 )
  {
    v25 = *(_DWORD *)(a1 + 24);
    if ( (unsigned int)(v25 - 5) < 0xFFFFFFFC )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, int, int, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64))cam_print_log)(
        3,
        16,
        1,
        "cam_req_mgr_schedule_request_v3",
        5582,
        "link:0x%x req:%lld invalid num_links:%d",
        *link_priv,
        v13,
        v25,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56);
      goto LABEL_13;
    }
    v27 = (_DWORD *)(a1 + 64);
    v26 = *(_DWORD *)(a1 + 64);
    if ( v26 )
    {
      v28 = link_priv;
      v29 = (int *)cam_get_link_priv(v26, v4);
      if ( !v29 )
      {
        v43 = 0;
        v31 = 0;
        v44 = "NULL";
        goto LABEL_44;
      }
      v31 = *v29;
      if ( *v29 != *v27 )
      {
        v43 = 0;
        v44 = "Non-NULL";
        goto LABEL_44;
      }
      v32 = *(_DWORD *)(a1 + 24);
      link_priv = v28;
      if ( v32 < 2 )
        goto LABEL_45;
      v27 = (_DWORD *)(a1 + 68);
      v33 = *(unsigned int *)(a1 + 68);
      if ( !(_DWORD)v33 )
      {
        v24 = 1;
        goto LABEL_41;
      }
      v34 = (int *)cam_get_link_priv(v33, v30);
      if ( !v34 )
      {
        v31 = 0;
        v44 = "NULL";
        v43 = 1;
        goto LABEL_44;
      }
      v31 = *v34;
      if ( *v34 != *v27 )
      {
        v44 = "Non-NULL";
        v43 = 1;
        goto LABEL_44;
      }
      v32 = *(_DWORD *)(a1 + 24);
      link_priv = v28;
      if ( v32 < 3 )
        goto LABEL_45;
      v27 = (_DWORD *)(a1 + 72);
      v36 = *(unsigned int *)(a1 + 72);
      if ( !(_DWORD)v36 )
      {
        v24 = 2;
        goto LABEL_41;
      }
      v37 = (int *)cam_get_link_priv(v36, v35);
      if ( !v37 )
      {
        v31 = 0;
        v44 = "NULL";
        v43 = 2;
        goto LABEL_44;
      }
      v31 = *v37;
      if ( *v37 != *v27 )
      {
        v44 = "Non-NULL";
        v43 = 2;
        goto LABEL_44;
      }
      v32 = *(_DWORD *)(a1 + 24);
      link_priv = v28;
      if ( v32 < 4 )
      {
LABEL_45:
        LODWORD(v52) = v32;
        v55 = a1 + 64;
        goto LABEL_46;
      }
      v27 = (_DWORD *)(a1 + 76);
      v39 = *(unsigned int *)(a1 + 76);
      if ( (_DWORD)v39 )
      {
        v40 = (int *)cam_get_link_priv(v39, v38);
        if ( v40 )
        {
          v31 = *v40;
          if ( *v40 == *v27 )
          {
            v32 = *(_DWORD *)(a1 + 24);
            link_priv = v28;
            if ( v32 >= 5 )
            {
              v42 = *(unsigned int *)(a1 + 80);
              if ( (_DWORD)v42 )
              {
                cam_get_link_priv(v42, v41);
                __break(0x5512u);
                JUMPOUT(0x394CE20);
              }
              v24 = 4;
              goto LABEL_41;
            }
            goto LABEL_45;
          }
          v44 = "Non-NULL";
          v43 = 3;
        }
        else
        {
          v31 = 0;
          v44 = "NULL";
          v43 = 3;
        }
LABEL_44:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, const char *, _DWORD, int, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64))cam_print_log)(
          3,
          16,
          1,
          "cam_req_mgr_schedule_request_v3",
          5602,
          "Invalid sync link, sync link[%d]: %s sched_req->link_hdl: %x sync_links->link_hdl: 0x%x",
          v43,
          v44,
          *v27,
          v31,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56);
        goto LABEL_13;
      }
      v24 = 3;
    }
    else
    {
      v24 = 0;
    }
LABEL_41:
    v21 = "link handle %d in sched_req is null";
    v22 = 1;
    v23 = 5589;
    goto LABEL_16;
  }
LABEL_46:
  v19 = ((__int64 (__fastcall *)(unsigned int *, __int64 *))cam_req_mgr_process_sched_req)(link_priv, &v47);
  if ( (debug_mdl & 0x1000010) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x1000010,
      4,
      "cam_req_mgr_schedule_request_v3",
      5615,
      "Open req %lld on link 0x%x with sync_mode %d",
      *(_QWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 8),
      *(_DWORD *)(a1 + 16));
LABEL_14:
  mutex_unlock(g_crm_core_dev + 16);
  _ReadStatusReg(SP_EL0);
  return v19;
}
