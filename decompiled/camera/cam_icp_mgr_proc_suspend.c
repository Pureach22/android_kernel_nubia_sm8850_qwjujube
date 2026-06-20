__int64 __fastcall cam_icp_mgr_proc_suspend(__int64 a1, char a2)
{
  __int64 v2; // x20
  int v4; // w20
  __int64 result; // x0
  const char *v6; // x7
  _DWORD *v8; // x8
  __int64 v9; // x0

  v2 = *(_QWORD *)(a1 + 80);
  if ( !v2 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             256,
             1,
             "cam_icp_mgr_proc_suspend",
             4534,
             "ICP device interface is NULL");
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
  {
    if ( (a2 & 1) != 0 )
      v6 = "Y";
    else
      v6 = "N";
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_mgr_proc_suspend",
      4539,
      "%s use_proxy_boot_up:%d",
      (const char *)(a1 + 112),
      (_DWORD)v6);
    if ( (a2 & 1) != 0 )
      goto LABEL_5;
LABEL_11:
    v8 = *(_DWORD **)(v2 + 88);
    v9 = *(_QWORD *)(v2 + 112);
    if ( *(v8 - 1) != -1055839300 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v8)(v9, 2, 0, 0);
    v4 = result;
    if ( !(_DWORD)result )
      goto LABEL_15;
    goto LABEL_14;
  }
  if ( (a2 & 1) == 0 )
    goto LABEL_11;
LABEL_5:
  v4 = -22;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    256,
    1,
    "cam_icp_mgr_proc_suspend",
    4550,
    "[%s] Failed in sending icp power_collapse command to PVM rc %d",
    (const char *)(a1 + 112),
    -22);
LABEL_14:
  result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             256,
             1,
             "cam_icp_mgr_proc_suspend",
             4556,
             "[%s] Fail to suspend processor rc %d",
             (const char *)(a1 + 112),
             v4);
LABEL_15:
  *(_BYTE *)(a1 + 44229) = 0;
  return result;
}
