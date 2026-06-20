__int64 __fastcall cam_icp_mgr_send_fw_init(__int64 a1)
{
  __int64 v2; // x20
  __int16 v3; // w8
  _DWORD *v4; // x8
  __int64 v5; // x0
  unsigned int v6; // w0
  unsigned int v7; // w20
  __int64 v8; // x0
  __int64 v9; // x20
  __int64 v10; // x1
  __int64 v11; // x21
  __int16 v12; // w8
  __int64 v13; // x0
  __int64 v14; // x22
  __int64 v15; // x1
  __int64 v16; // x23
  int v17; // w0
  __int64 v18; // x20
  unsigned int (__fastcall *v19)(__int64, __int64, int *, __int64); // x8
  __int64 v20; // x0
  const char *v21; // x5
  __int64 v22; // x6
  __int64 v23; // x4
  int v25; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+28h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 80);
  if ( !v2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_send_fw_init",
      5556,
      "%s: ICP device interface is NULL",
      (const char *)(a1 + 112));
    v7 = -22;
    goto LABEL_23;
  }
  v3 = debug_mdl;
  *(_DWORD *)(a1 + 44024) = 0;
  if ( (v3 & 0x100) != 0 && !debug_priority )
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v3 & 0x100,
      4,
      "cam_icp_mgr_send_fw_init",
      5562,
      "[%s] Sending HFI init command",
      (const char *)(a1 + 112));
  v4 = *(_DWORD **)(v2 + 88);
  v5 = *(_QWORD *)(v2 + 112);
  if ( *(v4 - 1) != -1055839300 )
    __break(0x8228u);
  v6 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v4)(v5, 6, 0, 0);
  if ( v6 )
  {
    v7 = v6;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_send_fw_init",
      5567,
      "[%s] Failed in sending HFI init command rc %d",
      (const char *)(a1 + 112),
      v6);
    goto LABEL_23;
  }
  v8 = ktime_get_with_offset(1);
  v9 = ns_to_timespec64(v8);
  v11 = v10;
  if ( !cam_common_wait_for_completion_timeout(a1 + 44024) )
  {
    v13 = ktime_get_with_offset(1);
    v14 = ns_to_timespec64(v13);
    v16 = v15;
    v17 = jiffies_to_msecs(1250, v15);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_send_fw_init",
      5575,
      "[%s] FW response timeout for FW init handle command (timeout: %ums start: timestamp:[%lld:%06lld] end: timestamp:[%lld:%06lld])",
      (const char *)(a1 + 112),
      v17,
      v9,
      v11 / 1000,
      v14,
      v16 / 1000);
    v18 = *(_QWORD *)(a1 + 80);
    if ( v18 )
    {
      v25 = 1;
      cam_icp_mgr_process_dbg_buf(a1);
      cam_hfi_queue_dump(*(unsigned int *)(a1 + 156), 0);
      v19 = *(unsigned int (__fastcall **)(__int64, __int64, int *, __int64))(v18 + 88);
      v20 = *(_QWORD *)(v18 + 112);
      if ( *((_DWORD *)v19 - 1) != -1055839300 )
        __break(0x8228u);
      if ( !v19(v20, 15, &v25, 4) )
      {
LABEL_20:
        v7 = -110;
        v12 = debug_mdl;
        if ( (debug_mdl & 0x100) == 0 )
          goto LABEL_23;
        goto LABEL_21;
      }
      v21 = "[%s] Fail to dump debug info";
      v22 = a1 + 112;
      v23 = 219;
    }
    else
    {
      v21 = "[%s] ICP device interface is NULL";
      v22 = a1 + 112;
      v23 = 208;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_dump_debug_info",
      v23,
      v21,
      v22);
    goto LABEL_20;
  }
  v7 = 0;
  v12 = debug_mdl;
  if ( (debug_mdl & 0x100) == 0 )
    goto LABEL_23;
LABEL_21:
  if ( !debug_priority )
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v12 & 0x100,
      4,
      "cam_icp_mgr_send_fw_init",
      5581,
      "[%s] Done Waiting for INIT DONE Message",
      (const char *)(a1 + 112));
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return v7;
}
