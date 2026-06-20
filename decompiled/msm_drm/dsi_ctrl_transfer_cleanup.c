__int64 __fastcall dsi_ctrl_transfer_cleanup(__int64 a1)
{
  int v2; // w0
  int v3; // w1
  const char *v5; // x3
  __int64 v6; // x8
  __int64 v7; // x9
  _DWORD *v8; // x8
  __int64 v9; // x8
  void (__fastcall *v10)(__int64, __int64); // x8
  const char *v11; // x3
  unsigned int (__fastcall *v12)(__int64, __int64, __int64); // x8
  __int64 v13; // x0
  const char *v14; // x3
  char vars0; // [xsp+0h] [xbp+0h]

  mutex_lock(a1 + 32);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dsi_ctrl_transfer_cleanup",
    3736,
    -1,
    4369,
    *(_DWORD *)(a1 + 8),
    *(_DWORD *)(a1 + 2920),
    -1059143953,
    vars0);
  v2 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))dsi_ctrl_set_cmd_engine_state)(a1, 0, 0);
  if ( v2 )
  {
    if ( a1 )
      v5 = *(const char **)(a1 + 16);
    else
      v5 = "inv";
    v2 = drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: failed to disable command engine\n", v5);
  }
  if ( (*(_BYTE *)(a1 + 2920) & 1) != 0 )
    goto LABEL_20;
  if ( a1 )
  {
    v6 = *(unsigned int *)(a1 + 1608);
    if ( (unsigned int)v6 >= 3 )
      goto LABEL_28;
    v7 = a1 + 8 * v6;
    if ( *(_QWORD *)(v7 + 1272) && *(_QWORD *)(a1 + 912 + 8 * v6) )
    {
      v8 = *(_DWORD **)(v7 + 1248);
      if ( *(v8 - 1) != -640374085 )
        __break(0x8228u);
      v2 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v8)(a1 + 96, 2, 0);
      v9 = *(unsigned int *)(a1 + 1608);
      if ( (unsigned int)v9 <= 2 )
      {
        v10 = *(void (__fastcall **)(__int64, __int64))(a1 + 912 + 8 * v9);
        if ( *((_DWORD *)v10 - 1) != 2055766805 )
          __break(0x8228u);
        v10(a1 + 96, 32);
        goto LABEL_20;
      }
LABEL_28:
      __break(0x5512u);
      __asm { LDTR            B0, [X13,#-0xF1] }
      return dsi_ctrl_transfer_unprepare(v2, v3);
    }
    v11 = *(const char **)(a1 + 16);
  }
  else
  {
    v11 = "inv";
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Invalid params\n", v11);
LABEL_20:
  mutex_unlock(a1 + 32);
  v12 = *(unsigned int (__fastcall **)(__int64, __int64, __int64))(a1 + 1640);
  v13 = *(_QWORD *)(a1 + 1632);
  if ( *((_DWORD *)v12 - 1) != 1407241817 )
    __break(0x8228u);
  if ( v12(v13, 3, 1) )
  {
    if ( a1 )
      v14 = *(const char **)(a1 + 16);
    else
      v14 = "inv";
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: failed to disable clocks\n", v14);
  }
  return _pm_runtime_idle(*(_QWORD *)(*(_QWORD *)(a1 + 80) + 8LL), 4);
}
