__int64 __fastcall cam_icp_mgr_hw_open(__int64 a1, _BYTE *a2)
{
  __int64 v2; // x20
  int v3; // w8
  unsigned int v4; // w8
  __int64 v5; // x19
  _BYTE *v6; // x21
  unsigned int hfi_mem; // w0
  unsigned int v8; // w8
  unsigned int v9; // w22
  unsigned int inited; // w0
  unsigned int v11; // w8
  unsigned int v12; // w0
  unsigned int v13; // w8
  const char *v14; // x5
  __int64 v15; // x6
  __int64 v16; // x4
  unsigned int v17; // w0
  unsigned int v18; // w0
  __int64 v19; // x8
  void (__fastcall *v20)(__int64, __int64, int *, __int64); // x9
  __int64 v21; // x0
  unsigned int v22; // w0
  const char *v23; // x5
  __int64 v24; // x6
  unsigned int v25; // w7
  __int64 v26; // x4
  unsigned int v27; // w0
  _BYTE *v29; // x1
  unsigned int v30; // w0
  unsigned int v31; // w20
  unsigned int v32; // w20
  int v33; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v34; // [xsp+8h] [xbp-8h]

  v2 = a1 + 40960;
  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(unsigned __int8 *)(a1 + 44228);
  v33 = 0;
  if ( v3 == 1 && *(_BYTE *)(a1 + 44237) == 1 )
  {
    v4 = 0;
    if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100,
        4,
        "cam_icp_mgr_hw_open",
        5819,
        "[%s] ICP already booted",
        (const char *)(a1 + 112));
      v4 = 0;
    }
    goto LABEL_42;
  }
  if ( !*(_QWORD *)(a1 + 80) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_hw_open",
      5825,
      "[%s] ICP device interface is invalid",
      (const char *)(a1 + 112));
    v4 = -22;
    goto LABEL_42;
  }
  if ( !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_hw_open",
      5830,
      "open args can't be NULL");
    v4 = -22;
    goto LABEL_42;
  }
  if ( *(_DWORD *)(a1 + 44148) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      2,
      "cam_icp_mgr_hw_open",
      5835,
      "[%s] recovery in progress",
      (const char *)(a1 + 112));
    v4 = -11;
    goto LABEL_42;
  }
  v5 = a1;
  v6 = a2;
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_mgr_hw_open",
      5839,
      "[%s] Start icp hw open",
      (const char *)(a1 + 112));
    a2 = v6;
    a1 = v5;
  }
  *(_DWORD *)(v2 + 3192) = 1;
  if ( a2[1] == 1 )
  {
    hfi_mem = cam_icp_allocate_hfi_mem(v5);
    a2 = v6;
    v8 = hfi_mem;
    a1 = v5;
    if ( v8 )
    {
      v9 = v8;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_hw_open",
        5846,
        "[%s] Failed in alloc hfi mem, rc %d",
        (const char *)(v5 + 112),
        v8);
LABEL_41:
      *(_DWORD *)(v2 + 3192) = 0;
      v4 = v9;
      goto LABEL_42;
    }
  }
  if ( (a2[3] & 1) == 0 )
  {
    inited = cam_icp_mgr_init_all_cores(v5);
    a2 = v6;
    v11 = inited;
    a1 = v5;
    if ( v11 )
    {
      v9 = v11;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_hw_open",
        5855,
        "[%s] Failed in device init, rc %d",
        (const char *)(v5 + 112),
        v11);
LABEL_40:
      cam_icp_free_hfi_mem(v5);
      goto LABEL_41;
    }
  }
  if ( (*(_BYTE *)(v2 + 3268) & 1) != 0 )
  {
    if ( (*(_BYTE *)(v2 + 3269) & 1) == 0 )
    {
      v12 = cam_icp_mgr_proc_resume(v5, (unsigned __int8)a2[2]);
      a2 = v6;
      v13 = v12;
      a1 = v5;
      if ( v13 )
      {
        v14 = "[%s] Failed in proc resume, rc %d";
        v15 = v5 + 112;
        v16 = 5871;
LABEL_27:
        v9 = v13;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_mgr_hw_open",
          v16,
          v14,
          v15,
          v13);
LABEL_39:
        cam_icp_mgr_device_deinit(v5);
        goto LABEL_40;
      }
    }
  }
  else
  {
    v17 = cam_icp_mgr_proc_boot(v5, (unsigned __int8)a2[2]);
    a2 = v6;
    v13 = v17;
    a1 = v5;
    if ( v13 )
    {
      v14 = "[%s] Failed in proc boot, rc %d";
      v15 = v5 + 112;
      v16 = 5864;
      goto LABEL_27;
    }
  }
  if ( a2[1] == 1 )
  {
    v18 = cam_icp_mgr_hfi_init(a1);
    if ( v18 )
    {
      v9 = v18;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_hw_open",
        5880,
        "[%s] Failed in hfi init, rc %d",
        v5 + 112);
      v19 = *(_QWORD *)(v5 + 80);
      v33 = 3;
      v20 = *(void (__fastcall **)(__int64, __int64, int *, __int64))(v19 + 88);
      v21 = *(_QWORD *)(v19 + 112);
      if ( *((_DWORD *)v20 - 1) != -1055839300 )
        __break(0x8229u);
      v20(v21, 15, &v33, 4);
      goto LABEL_38;
    }
    v22 = cam_icp_mgr_send_fw_init(v5);
    if ( v22 )
    {
      v23 = "[%s] Failed in sending fw init, rc %d";
      v24 = v5 + 112;
      v25 = v22;
      v26 = 5890;
LABEL_37:
      v9 = v25;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_hw_open",
        v26,
        v23,
        v24);
      cam_hfi_deinit(*(unsigned int *)(v5 + 156));
      *(_BYTE *)(v2 + 3277) = 0;
LABEL_38:
      cam_icp_mgr_proc_shutdown(v5, (unsigned __int8)v6[2], (unsigned __int8)v6[3]);
      goto LABEL_39;
    }
    v27 = cam_icp_mgr_send_memory_region_info(v5);
    if ( v27 )
    {
      v23 = "[%s] Failed in sending mem region info, rc %d";
      v24 = v5 + 112;
      v25 = v27;
      v26 = 5897;
      goto LABEL_37;
    }
    a1 = v5;
    *(_BYTE *)(v2 + 3277) = 1;
  }
  *(_DWORD *)(v2 + 3120) = 0;
  *(_BYTE *)(v2 + 3268) = 1;
  *(_DWORD *)(v2 + 3188) = 0;
  *(_DWORD *)(v2 + 3192) = 0;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    256,
    3,
    "cam_icp_mgr_hw_open",
    5909,
    "[%s] FW download done successfully",
    (const char *)(a1 + 112));
  v29 = v6;
  v4 = 0;
  if ( (v6[3] & 1) == 0 )
  {
    v30 = cam_icp_device_deint(v5);
    if ( v30 )
    {
      v31 = v30;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_hw_open",
        5915,
        "[%s] Failed in device deinit rc %d",
        (const char *)(v5 + 112),
        v30);
      v4 = v31;
    }
    else
    {
      v4 = 0;
    }
    v29 = v6;
  }
  if ( *v29 == 1 )
  {
    v32 = cam_icp_mgr_icp_power_collapse(v5, (__int64)v29);
    if ( v32 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_hw_open",
        5924,
        "[%s] Failed in icp power collapse rc %d",
        (const char *)(v5 + 112),
        v32);
    if ( (debug_mdl & 0x100) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x100,
        4,
        "cam_icp_mgr_hw_open",
        5926,
        "[%s] deinit all clocks at boot up",
        (const char *)(v5 + 112));
    v4 = v32;
  }
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return v4;
}
