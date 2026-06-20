__int64 __fastcall dsi_ctrl_post_cmd_transfer(__int64 a1)
{
  int v2; // w8
  __int64 v3; // x0
  __int64 v4; // x8
  __int64 (__fastcall *v5)(_QWORD); // x8
  int v6; // w20
  __int64 v7; // x8
  _DWORD *v8; // x8
  __int64 v9; // x8
  void (__fastcall *v10)(__int64, __int64); // x8
  __int64 result; // x0
  _QWORD v12[178]; // [xsp+0h] [xbp-590h] BYREF

  v12[177] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dsi_ctrl_post_cmd_transfer",
    460,
    -1,
    4369,
    *(_DWORD *)(a1 + 8),
    *(_DWORD *)(a1 + 2920),
    -1059143953,
    v12[0]);
  v2 = *(_DWORD *)(a1 + 2920);
  if ( (v2 & 6) == 2 )
  {
    memset(v12, 0, 0x588u);
    if ( a1 )
    {
      memcpy(v12, (const void *)(a1 + 168), 0x588u);
      v3 = mutex_lock(a1 + 32);
      v4 = *(unsigned int *)(a1 + 1608);
      if ( (unsigned int)v4 >= 3 )
        goto LABEL_25;
      if ( ((8 * v4) | 0x2A0uLL) > 0x588 )
      {
        __break(1u);
        return dsi_ctrl_validate_host_state(v3);
      }
      v5 = (__int64 (__fastcall *)(_QWORD))v12[v4 + 84];
      if ( v5 )
      {
        if ( *((_DWORD *)v5 - 1) != 1445431588 )
          __break(0x8228u);
        v6 = v5(a1 + 96);
      }
      else
      {
        v6 = 0;
      }
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "dsi_ctrl_clear_dma_status",
        449,
        -1,
        *(_DWORD *)(a1 + 8),
        4369,
        v6,
        -1059143953,
        v12[0]);
      v7 = *(unsigned int *)(a1 + 1608);
      if ( (unsigned int)v7 > 2 )
LABEL_25:
        __break(0x5512u);
      v8 = (_DWORD *)v12[v7 + 81];
      if ( v8 )
      {
        if ( *(v8 - 1) != -200804075 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD))v8)(a1 + 96, v6 | 0x21u);
      }
      mutex_unlock(a1 + 32);
    }
    else
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Invalid params\n", "inv");
    }
  }
  else if ( (v2 & 1) == 0 )
  {
    ((void (__fastcall *)(__int64))dsi_ctrl_dma_cmd_wait_for_done)(a1);
  }
  mutex_lock(a1 + 32);
  v9 = *(unsigned int *)(a1 + 1608);
  if ( (unsigned int)v9 >= 3 )
    goto LABEL_25;
  v10 = *(void (__fastcall **)(__int64, __int64))(a1 + 8 * v9 + 1488);
  if ( v10 )
  {
    if ( *((_DWORD *)v10 - 1) != -25817620 )
      __break(0x8228u);
    v10(a1 + 96, a1 + 2444);
  }
  mutex_unlock(a1 + 32);
  result = dsi_ctrl_transfer_cleanup(a1);
  _ReadStatusReg(SP_EL0);
  return result;
}
