__int64 __fastcall dsi_display_cont_splash_config(__int64 a1)
{
  __int64 v2; // x21
  unsigned int v3; // w0
  __int64 v4; // x0
  int v5; // w7
  unsigned int v6; // w8
  unsigned int v7; // w0
  unsigned int v8; // w20
  unsigned int v9; // w8
  unsigned int v10; // w8
  unsigned int v17; // w10
  int v18; // w7
  __int64 v19; // x8
  unsigned int v20; // w0
  char v22; // [xsp+0h] [xbp+0h]

  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid input display param\n");
    return (unsigned int)-22;
  }
  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 8LL);
  v3 = _pm_runtime_resume(v2, 4);
  if ( (v3 & 0x80000000) == 0 )
  {
    mutex_lock(a1 + 72);
    v4 = *(_QWORD *)(a1 + 1312);
    *(_BYTE *)(a1 + 64) = 1;
    dsi_display_clk_mngr_update_splash_status(v4, 1);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dsi_display_cont_splash_config",
      5845,
      -1,
      4369,
      *(unsigned __int8 *)(a1 + 64),
      -1059143953,
      v5,
      v22);
    v6 = *(_DWORD *)(a1 + 160);
    if ( v6 )
    {
      if ( a1 != -168 )
      {
        dsi_ctrl_isr_configure(*(_QWORD *)(a1 + 168), 1);
        v6 = *(_DWORD *)(a1 + 160);
      }
      if ( v6 >= 2 && a1 != -216 )
        dsi_ctrl_isr_configure(*(_QWORD *)(a1 + 216), 1);
    }
    v7 = dsi_display_clk_ctrl(*(_QWORD *)(a1 + 1320), 3, 1);
    if ( v7 )
    {
      v8 = v7;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] failed to enable DSI link clocks, rc=%d\n",
        *(const char **)(a1 + 32),
        v7);
      v9 = *(_DWORD *)(a1 + 160);
      if ( !v9 )
      {
LABEL_16:
        dsi_display_clk_mngr_update_splash_status(*(_QWORD *)(a1 + 1312), 0);
        _pm_runtime_idle(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 8LL), 4);
        *(_BYTE *)(a1 + 64) = 0;
        mutex_unlock(a1 + 72);
        return v8;
      }
    }
    else
    {
      v19 = *(_QWORD *)(a1 + 264);
      if ( *(_BYTE *)(v19 + 2024) != 1
        || *(_DWORD *)(v19 + 1352) != 1
        || (v20 = dsi_display_clk_ctrl(*(_QWORD *)(a1 + 1328), 4, 1)) == 0 )
      {
        mutex_unlock(a1 + 72);
        dsi_panel_bl_handoff(*(_QWORD *)(a1 + 264));
        return 0;
      }
      v8 = v20;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] failed to enable DSI link clocks, rc=%d\n",
        *(const char **)(a1 + 32),
        v20);
      dsi_display_clk_ctrl(*(_QWORD *)(a1 + 1320), 3, 0);
      v9 = *(_DWORD *)(a1 + 160);
      if ( !v9 )
        goto LABEL_16;
    }
    if ( a1 != -168 )
    {
      dsi_ctrl_isr_configure(*(_QWORD *)(a1 + 168), 0);
      v9 = *(_DWORD *)(a1 + 160);
    }
    if ( v9 >= 2 && a1 != -216 )
      dsi_ctrl_isr_configure(*(_QWORD *)(a1 + 216), 0);
    goto LABEL_16;
  }
  v10 = *(_DWORD *)(v2 + 480);
  v8 = v3;
  do
  {
    if ( !v10 )
      break;
    _X12 = (unsigned int *)(v2 + 480);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v17 = __ldxr(_X12);
      if ( v17 != v10 )
        break;
      if ( !__stlxr(v10 - 1, _X12) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v17 == v10;
    v10 = v17;
  }
  while ( !_ZF );
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to enable power resource %d\n", v3);
  sde_evtlog_log(sde_dbg_base_evtlog, "dsi_display_cont_splash_config", 5834, -1, v8, 60333, -1059143953, v18, v22);
  return v8;
}
