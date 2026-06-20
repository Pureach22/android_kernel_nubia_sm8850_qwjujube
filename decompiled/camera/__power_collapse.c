__int64 __fastcall _power_collapse(__int64 a1, __int64 a2)
{
  __int64 v3; // x21
  __int64 v4; // x20
  __int64 v5; // x25
  _DWORD *v6; // x8
  __int64 v7; // x0
  unsigned int v8; // w20
  __int64 v9; // x0
  __int64 v10; // x20
  __int64 v11; // x1
  __int64 v12; // x22
  __int64 v13; // x21
  __int64 v14; // x20
  __int64 v16; // x0
  __int64 v17; // x23
  __int64 v18; // x1
  __int64 v19; // x24
  int v20; // w7
  __int64 v21; // x20

  if ( !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "__power_collapse",
      4566,
      "pc_args cannot be NULL");
    return (unsigned int)-22;
  }
  v3 = a1 + 40960;
  if ( (*(_BYTE *)(a2 + 2) & 1) != 0 || *(_BYTE *)(a1 + 44230) == 1 && !*(_DWORD *)(a1 + 44148) )
  {
    if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
    {
      v21 = a2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x2000100,
        4,
        "__power_collapse",
        4580,
        "[%s] Sending PC prep ICP PC enabled",
        (const char *)(a1 + 112));
      a2 = v21;
    }
    if ( *(_BYTE *)(a2 + 1) != 1 )
    {
      v8 = 0;
LABEL_31:
      cam_icp_mgr_proc_suspend(a1, *(unsigned __int8 *)(a2 + 2));
      return v8;
    }
    v4 = *(_QWORD *)(a1 + 80);
    if ( v4 )
    {
      *(_DWORD *)(v3 + 3064) = 0;
      v5 = a2;
      if ( (debug_mdl & 0x100) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x100,
          4,
          "cam_icp_mgr_send_pc_prep",
          4399,
          "[%s] Sending pc prep command",
          (const char *)(a1 + 112));
      v6 = *(_DWORD **)(v4 + 88);
      v7 = *(_QWORD *)(v4 + 112);
      if ( *(v6 - 1) != -1055839300 )
        __break(0x8228u);
      v8 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v6)(v7, 11, 0, 0);
      if ( !v8 )
      {
        if ( (debug_mdl & 0x100) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x100,
            4,
            "cam_icp_mgr_send_pc_prep",
            4405,
            "[%s] Wait for PC_PREP_DONE Message\n",
            (const char *)(a1 + 112));
        v9 = ktime_get_with_offset(1);
        v10 = ns_to_timespec64(v9);
        v12 = v11;
        v13 = cam_common_wait_for_completion_timeout(v3 + 3064);
        if ( v13 )
        {
          v8 = 0;
        }
        else
        {
          v16 = ktime_get_with_offset(1);
          v17 = ns_to_timespec64(v16);
          v19 = v18;
          v20 = jiffies_to_msecs(1250, v18);
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_mgr_send_pc_prep",
            4409,
            "[%s] FW response timeout for PC PREP handle command (timeout: %ums start: timestamp:[%lld:%06lld] end: times"
            "tamp:[%lld:%06lld])",
            (const char *)(a1 + 112),
            v20,
            v10,
            v12 / 1000,
            v17,
            v19 / 1000);
          v8 = -110;
        }
        if ( (debug_mdl & 0x100) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x100,
            4,
            "cam_icp_mgr_send_pc_prep",
            4412,
            "[%s] Done Waiting for PC_PREP Message\n",
            (const char *)(a1 + 112));
          if ( v13 )
            goto LABEL_37;
        }
        else if ( v13 )
        {
LABEL_37:
          v8 = 0;
          goto LABEL_30;
        }
      }
    }
    else
    {
      v5 = a2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_send_pc_prep",
        4393,
        "[%s] device interface is NULL",
        (const char *)(a1 + 112));
      v8 = -22;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "__power_collapse",
      4586,
      "[%s] Failed in send pc prep rc %d",
      (const char *)(a1 + 112),
      v8);
LABEL_30:
    a2 = v5;
    goto LABEL_31;
  }
  v14 = a2;
  cam_icp_mgr_proc_suspend(a1, 0);
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_mgr_hw_close_k",
      4490,
      "[%s] KMD calls close",
      (const char *)(a1 + 112));
  v8 = cam_icp_mgr_hw_close(a1, v14);
  if ( v8 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "__power_collapse",
      4577,
      "[%s] Failed in hw close rc %d",
      (const char *)(a1 + 112),
      v8);
  return v8;
}
