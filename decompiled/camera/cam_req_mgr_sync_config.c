__int64 __fastcall cam_req_mgr_sync_config(unsigned int *a1)
{
  const char *v1; // x5
  __int64 v2; // x4
  unsigned int v3; // w6
  unsigned int v4; // w7
  unsigned int *v5; // x23
  int *session_priv; // x0
  unsigned int v8; // w7
  int v9; // w8
  int *v10; // x19
  __int64 v11; // x1
  unsigned __int64 v12; // x0
  __int64 v13; // x20
  __int64 result; // x0
  __int64 v15; // x0
  __int64 link_priv; // x0
  int v17; // w9
  _QWORD *v18; // x9
  unsigned int *v19; // x8
  const char *v20; // x6
  _DWORD *v21; // x24
  _DWORD *v22; // x13
  _DWORD *v23; // x14
  __int64 v24; // x25
  const char *v25; // x23
  __int64 v27; // x15
  int v28; // w0
  __int64 v29; // x15
  int v30; // w0
  __int64 v31; // x15
  __int64 v32; // x6
  const char *v33; // x5
  const char *v34; // x20
  _DWORD *v35; // x23
  __int64 v36; // x24
  _DWORD *v37; // x25
  _DWORD *v38; // x25
  __int64 v39; // x13
  __int64 v40; // x13
  unsigned int v41; // w20
  __int64 v42; // x1
  _DWORD *v43; // [xsp+8h] [xbp-28h]
  _DWORD *v44; // [xsp+10h] [xbp-20h]
  _DWORD *v45; // [xsp+10h] [xbp-20h]
  _DWORD *v46; // [xsp+10h] [xbp-20h]
  __int64 v47; // [xsp+18h] [xbp-18h]
  __int64 v48; // [xsp+20h] [xbp-10h]
  __int64 v49; // [xsp+28h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_sync_config",
      5630,
      "NULL pointer");
LABEL_14:
    result = 4294967274LL;
LABEL_15:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( a1[2] >= 3 )
  {
    v1 = "Invalid num links %d";
    v2 = 5637;
LABEL_13:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_sync_config",
      v2,
      v1);
    goto LABEL_14;
  }
  if ( a1[1] >= 2 )
  {
    v1 = "Invalid sync mode %d";
    v2 = 5643;
    goto LABEL_13;
  }
  v3 = a1[3];
  v4 = a1[4];
  v5 = a1 + 3;
  if ( !v3 || !v4 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      2,
      "cam_req_mgr_sync_config",
      5649,
      "Invalid link handles 0x%x 0x%x",
      v3,
      v4);
    goto LABEL_14;
  }
  mutex_lock(g_crm_core_dev + 16);
  session_priv = (int *)cam_get_session_priv(*a1);
  v8 = *a1;
  if ( !session_priv )
  {
LABEL_27:
    v9 = 0;
    v20 = "NULL";
LABEL_29:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_sync_config",
      5659,
      "session: %s, sync_info->session_hdl:%x, session->ses_hdl:%x",
      v20,
      v8,
      v9);
    mutex_unlock(g_crm_core_dev + 16);
    goto LABEL_14;
  }
  v9 = *session_priv;
  v10 = session_priv;
  if ( *session_priv != v8 )
  {
    v20 = "Non-NULL";
    goto LABEL_29;
  }
  v47 = 0;
  v48 = 0;
  mutex_lock(session_priv + 14);
  v12 = a1[2];
  if ( (int)v12 >= 1 )
  {
    v13 = 0;
    while ( 1 )
    {
      if ( v13 == 2 )
        goto LABEL_26;
      v15 = v5[v13];
      if ( !(_DWORD)v15 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          16,
          1,
          "cam_req_mgr_sync_config",
          5669,
          "link handle %d is null",
          v13);
        goto LABEL_71;
      }
      link_priv = cam_get_link_priv(v15, v11);
      *(&v47 + v13) = link_priv;
      if ( !link_priv )
        break;
      v17 = *(_DWORD *)link_priv;
      v8 = v5[v13];
      if ( *(_DWORD *)link_priv != v8 )
        goto LABEL_70;
      v18 = (_QWORD *)(link_priv + 0x8000);
      v19 = a1;
      *(_BYTE *)(link_priv + 33252) = 0;
      *(_BYTE *)(link_priv + 33276) = 0;
      *(_BYTE *)(link_priv + 33278) = 0;
      *(_QWORD *)(link_priv + 33280) = -1;
      *(_DWORD *)(link_priv + 33248) = 0;
      v12 = a1[2];
      if ( (int)v12 - 1 >= 1 )
      {
        v18[57] = 0;
        v12 = a1[2];
        if ( (int)v12 - 1 >= 2 )
        {
          v18[58] = 0;
          v12 = a1[2];
          if ( (int)v12 - 1 >= 3 )
          {
            v18[59] = 0;
            v12 = a1[2];
            if ( (int)v12 - 1 > 3 )
              goto LABEL_26;
          }
        }
      }
      if ( ++v13 >= (int)v12 )
        goto LABEL_31;
    }
    v8 = v5[v13];
    v17 = 0;
LABEL_70:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      16,
      1,
      "cam_req_mgr_sync_config",
      5678,
      "link: %s, sync_info->link_hdl:%x, link->link_hdl:%x",
      "Non-NULL",
      v8,
      v17);
LABEL_71:
    v41 = -22;
    goto LABEL_72;
  }
  v19 = a1;
LABEL_31:
  v21 = &unk_393000;
  if ( v19[1] != 1 )
  {
    if ( (int)v12 < 1
      || (v39 = v47 + 0x8000, *(_BYTE *)(v47 + 33277) = 1, *(_QWORD *)(v39 + 528) = 0, (int)v19[2] < 2)
      || (v40 = v48 + 0x8000, *(_BYTE *)(v48 + 33277) = 1, *(_QWORD *)(v40 + 528) = 0, (int)v19[2] <= 2) )
    {
LABEL_65:
      v41 = 0;
      v42 = debug_mdl & 0x1000010;
      v10[27] = v19[1];
      if ( v42 )
      {
        if ( !v21[919] )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
            3,
            v42,
            4,
            "cam_req_mgr_sync_config",
            5722,
            "Sync config completed on %d links with sync_mode %d",
            v19[2]);
          v41 = 0;
        }
      }
LABEL_72:
      mutex_unlock(v10 + 14);
      mutex_unlock(g_crm_core_dev + 16);
      result = v41;
      goto LABEL_15;
    }
LABEL_26:
    __break(0x5512u);
    goto LABEL_27;
  }
  if ( (int)v12 < 1 )
    goto LABEL_65;
  v22 = (_DWORD *)v47;
  v23 = (_DWORD *)v48;
  v24 = 0;
  v25 = "link %x adds sync link:";
  while ( (debug_mdl & 0x1000010) == 0 || v21[919] != 0 )
  {
    if ( (int)v12 >= 1 )
      goto LABEL_39;
LABEL_55:
    if ( v24 == 2 )
      goto LABEL_26;
LABEL_56:
    if ( (v24 & 0x1FFFFFFFFFFFFFFELL) != 0 )
      goto LABEL_73;
    v31 = *(&v47 + v24++);
    v31 += 0x8000;
    *(_BYTE *)(v31 + 509) = 1;
    *(_QWORD *)(v31 + 528) = 0;
    v12 = (int)v19[2];
    if ( v24 >= (__int64)v12 )
      goto LABEL_65;
  }
  if ( (unsigned __int64)v24 > 1 )
    goto LABEL_26;
  v32 = *(unsigned int *)*(&v47 + v24);
  v33 = v25;
  v34 = v25;
  v35 = v21;
  v36 = v24;
  v44 = v22;
  v37 = v23;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
    3,
    debug_mdl & 0x1000010,
    4,
    "cam_req_mgr_sync_config",
    5698,
    v33,
    v32);
  v22 = v44;
  v12 = a1[2];
  v23 = v37;
  v24 = v36;
  v21 = v35;
  v25 = v34;
  v19 = a1;
  if ( (int)v12 < 1 )
    goto LABEL_55;
LABEL_39:
  v12 = 8 * v24;
  if ( !v24 )
  {
    if ( (int)v19[2] < 2 )
      goto LABEL_56;
    if ( v12 > 0xF )
      goto LABEL_73;
    v29 = v47 + 0x8000;
    v30 = *(_DWORD *)(v47 + 33248);
    *(_QWORD *)(v47 + 33224) = v23;
    *(_DWORD *)(v29 + 480) = v30 + 1;
    if ( (debug_mdl & 0x1000010) != 0 && !v21[919] )
    {
      v43 = v23;
      v46 = v22;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x1000010,
        4,
        "cam_req_mgr_sync_config",
        5705,
        "sync_link[%d] : %x",
        0,
        *v23);
      v23 = v43;
      v22 = v46;
      v19 = a1;
    }
    v12 = v19[2];
LABEL_53:
    if ( (int)v12 > 2 )
      goto LABEL_26;
    goto LABEL_56;
  }
  if ( v24 != 1 )
    goto LABEL_26;
  if ( v12 <= 0x10 )
  {
    v27 = v48 + 0x8000;
    v28 = *(_DWORD *)(v48 + 33248);
    *(_QWORD *)(v48 + 33224) = v22;
    *(_DWORD *)(v27 + 480) = v28 + 1;
    if ( (debug_mdl & 0x1000010) != 0 && !v21[919] )
    {
      v45 = v22;
      v38 = v23;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x1000010,
        4,
        "cam_req_mgr_sync_config",
        5705,
        "sync_link[%d] : %x",
        0,
        *v22);
      v22 = v45;
      v23 = v38;
      v24 = 1;
      v25 = "link %x adds sync link:";
      v19 = a1;
    }
    v12 = v19[2];
    if ( (int)v12 < 2 )
      goto LABEL_56;
    goto LABEL_53;
  }
LABEL_73:
  __break(1u);
  return cam_req_mgr_flush_requests(v12);
}
