__int64 __fastcall cam_icp_mgr_icp_power_collapse(__int64 a1, __int64 a2)
{
  __int64 v4; // x25
  unsigned int v5; // w20
  __int64 (__fastcall *v6)(__int64, char *, __int64); // x8
  __int64 v7; // x0
  char v9[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 80);
  v9[0] = 1;
  if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x2000100,
      4,
      "cam_icp_mgr_icp_power_collapse",
      4604,
      "[%s] ENTER",
      (const char *)(a1 + 112));
    if ( v4 )
      goto LABEL_4;
LABEL_15:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_icp_power_collapse",
      4606,
      "[%s] ICP device interface is NULL",
      (const char *)(a1 + 112));
    v5 = -22;
    goto LABEL_16;
  }
  if ( !v4 )
    goto LABEL_15;
LABEL_4:
  v5 = _power_collapse(a1, a2);
  if ( v5 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_icp_power_collapse",
      4613,
      "[%s] Fail to power collapse ICP rc: %d",
      (const char *)(a1 + 112),
      v5);
  if ( (*(_BYTE *)(a2 + 3) & 1) == 0 )
  {
    v6 = *(__int64 (__fastcall **)(__int64, char *, __int64))(v4 + 24);
    v7 = *(_QWORD *)(v4 + 112);
    if ( *((_DWORD *)v6 - 1) != 1989616049 )
      __break(0x8228u);
    v5 = v6(v7, v9, 1);
    if ( v5 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_icp_power_collapse",
        4619,
        "[%s] Fail to deinit ICP",
        (const char *)(a1 + 112));
  }
  if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x2000100,
      4,
      "cam_icp_mgr_icp_power_collapse",
      4622,
      "[%s] EXIT",
      (const char *)(a1 + 112));
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return v5;
}
