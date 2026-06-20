__int64 __fastcall cam_icp_mgr_trigger_recovery(__int64 a1)
{
  __int64 v2; // x21
  unsigned int v3; // w20
  unsigned int v4; // w9
  __int64 v5; // x8
  int v6; // w11
  __int64 v7; // x10
  int v8; // w25
  int v9; // w20
  __int64 v10; // x8
  _DWORD *v11; // x9
  __int64 v12; // x0
  __int64 v13; // x20
  unsigned int (__fastcall *v14)(__int64, __int64, int *, __int64); // x8
  __int64 v15; // x0
  const char *v16; // x5
  __int64 v17; // x6
  __int64 v18; // x4
  __int64 v19; // x24
  __int64 v20; // x20
  __int64 *v21; // x8
  void (__fastcall *v22)(__int64, __int64, __int64 *); // x9
  __int64 v23; // x0
  int inited; // w0
  __int16 v26; // w8
  unsigned int v27; // w0
  const char *v28; // x5
  __int64 v29; // x6
  __int64 v30; // x4
  const char *v31; // x7
  unsigned int hfi_mem; // w0
  unsigned int v33; // w0
  __int64 v34; // [xsp+10h] [xbp-20h] BYREF
  __int64 v35; // [xsp+18h] [xbp-18h]
  int v36; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v37; // [xsp+28h] [xbp-8h]

  v2 = a1 + 40960;
  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  v35 = 0;
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_mgr_trigger_recovery",
      3311,
      "[%s] Enter",
      (const char *)(a1 + 112));
    if ( *(_DWORD *)(v2 + 3188) )
      goto LABEL_4;
LABEL_6:
    *(_DWORD *)(v2 + 3188) = 1;
    if ( *(_BYTE *)(v2 + 3271) == 1 )
    {
      v4 = *(_DWORD *)(a1 + 64);
      if ( v4 )
      {
        v5 = *(_QWORD *)(a1 + 56);
        v6 = 0;
        while ( 1 )
        {
          v7 = v5 + 584LL * v6;
          v8 = v6;
          if ( *(_DWORD *)(v7 + 580) )
            break;
LABEL_9:
          v6 = v8 + 1;
          if ( v8 + 1 >= v4 )
            goto LABEL_18;
        }
        v9 = 0;
        while ( 1 )
        {
          v10 = *(_QWORD *)(*(_QWORD *)(v7 + 16) + 8LL * v9);
          if ( !v10 )
            break;
          v11 = *(_DWORD **)(v10 + 88);
          v12 = *(_QWORD *)(v10 + 112);
          if ( *(v11 - 1) != -1055839300 )
            __break(0x8229u);
          ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))v11)(v12, 0, 0, 0);
          v5 = *(_QWORD *)(a1 + 56);
          v7 = v5 + 584LL * v8;
          if ( (unsigned int)++v9 >= *(_DWORD *)(v7 + 580) )
          {
            v4 = *(_DWORD *)(a1 + 64);
            goto LABEL_9;
          }
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_mgr_dev_get_gdsc_control",
          2013,
          "Device intf for %s[%u] is NULL",
          *(const char **)v7,
          v9);
      }
    }
LABEL_18:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      2,
      "cam_icp_mgr_trigger_recovery",
      3323,
      "[%s] hw_mgr[%u] SFR:%s",
      (const char *)(a1 + 112),
      *(_DWORD *)(a1 + 144),
      (const char *)(*(_QWORD *)(a1 + 448) + 4LL));
    v13 = *(_QWORD *)(a1 + 80);
    if ( v13 )
    {
      v36 = 1;
      cam_icp_mgr_process_dbg_buf(a1);
      cam_hfi_queue_dump(*(unsigned int *)(a1 + 156), 0);
      v14 = *(unsigned int (__fastcall **)(__int64, __int64, int *, __int64))(v13 + 88);
      v15 = *(_QWORD *)(v13 + 112);
      if ( *((_DWORD *)v14 - 1) != -1055839300 )
        __break(0x8228u);
      if ( !v14(v15, 15, &v36, 4) )
        goto LABEL_25;
      v16 = "[%s] Fail to dump debug info";
      v17 = a1 + 112;
      v18 = 219;
    }
    else
    {
      v16 = "[%s] ICP device interface is NULL";
      v17 = a1 + 112;
      v18 = 208;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_dump_debug_info",
      v18,
      v16,
      v17);
LABEL_25:
    cam_icp_mgr_dump_active_req_info(a1);
    mutex_lock(a1);
    v19 = 0;
    v20 = 0;
    while ( 1 )
    {
      mutex_lock(*(_QWORD *)(a1 + 88) + v20);
      v21 = *(__int64 **)(*(_QWORD *)(a1 + 96) + v19);
      if ( v21 )
      {
        if ( *((_DWORD *)v21 + 26) == 2 )
          break;
      }
      mutex_unlock(*(_QWORD *)(a1 + 88) + v20);
      v19 += 8;
      v20 += 48;
      if ( v19 == 432 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_mgr_trigger_recovery",
          3347,
          "[%s] Fail to report system failure to userspace due to no active ctx",
          (const char *)(a1 + 112));
        goto LABEL_33;
      }
    }
    LODWORD(v35) = 1;
    v22 = (void (__fastcall *)(__int64, __int64, __int64 *))v21[12];
    v23 = *v21;
    if ( *((_DWORD *)v22 - 1) != 414296116 )
      __break(0x8229u);
    v22(v23, 1, &v34);
    mutex_unlock(*(_QWORD *)(a1 + 88) + v20);
LABEL_33:
    if ( *(_BYTE *)(v2 + 3300) == 1 )
      panic("CAMERA - [%s] WD......\n", (const char *)(a1 + 112));
    if ( *(_DWORD *)(v2 + 3192) || !*(_DWORD *)(v2 + 3188) )
    {
      v3 = 0;
      goto LABEL_36;
    }
    if ( *(_BYTE *)(v2 + 3268) == 1 )
      cam_icp_mgr_proc_shutdown(a1, 0, (*(_BYTE *)(v2 + 3277) & 1) == 0);
    inited = cam_icp_mgr_init_all_cores(a1);
    if ( inited )
    {
      v3 = inited;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_restart_icp",
        5984,
        "[%s] Failed in device init, rc %d",
        (const char *)(a1 + 112),
        inited);
      v26 = debug_mdl;
      if ( (debug_mdl & 0x100) == 0 )
        goto LABEL_36;
LABEL_48:
      if ( !debug_priority )
      {
        if ( *(_DWORD *)(v2 + 3188) )
          v31 = "N";
        else
          v31 = "Y";
        ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          v26 & 0x100,
          4,
          "cam_icp_mgr_trigger_recovery",
          3364,
          "[%s] recovery success: %s",
          a1 + 112,
          v31);
      }
      goto LABEL_36;
    }
    v27 = cam_icp_mgr_proc_boot(a1, 0);
    if ( v27 )
    {
      v3 = v27;
      v28 = "[%s] Failed in proc boot, rc %d";
      v29 = a1 + 112;
      v30 = 5992;
LABEL_46:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_restart_icp",
        v30,
        v28,
        v29,
        v3);
      goto LABEL_47;
    }
    if ( *(_BYTE *)(v2 + 3277) == 1 )
    {
      cam_hfi_deinit(*(unsigned int *)(a1 + 156));
      v3 = cam_icp_mgr_hfi_init_util(a1);
      if ( !v3 )
        goto LABEL_60;
    }
    else
    {
      hfi_mem = cam_icp_allocate_hfi_mem(a1);
      if ( hfi_mem )
      {
        v3 = hfi_mem;
        v28 = "[%s] Failed in alloc hfi mem, rc %d";
        v29 = a1 + 112;
        v30 = 6007;
        goto LABEL_46;
      }
      v33 = cam_icp_mgr_hfi_init_util(a1);
      if ( !v33 )
      {
LABEL_60:
        *(_BYTE *)(v2 + 3268) = 1;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          3,
          "cam_icp_mgr_restart_icp",
          6020,
          "[%s] FW download done successfully",
          (const char *)(a1 + 112));
        cam_icp_mgr_device_deinit(a1);
        v3 = 0;
        *(_DWORD *)(v2 + 3188) = 0;
        v26 = debug_mdl;
        if ( (debug_mdl & 0x100) == 0 )
          goto LABEL_36;
        goto LABEL_48;
      }
      v3 = v33;
      cam_icp_free_hfi_mem(a1);
    }
LABEL_47:
    cam_icp_mgr_device_deinit(a1);
    v26 = debug_mdl;
    if ( (debug_mdl & 0x100) != 0 )
      goto LABEL_48;
LABEL_36:
    mutex_unlock(a1);
    goto LABEL_37;
  }
  if ( !*(_DWORD *)(a1 + 44148) )
    goto LABEL_6;
LABEL_4:
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    256,
    1,
    "cam_icp_mgr_trigger_recovery",
    3314,
    "%s SSR is set",
    (const char *)(a1 + 112));
  v3 = 0;
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return v3;
}
