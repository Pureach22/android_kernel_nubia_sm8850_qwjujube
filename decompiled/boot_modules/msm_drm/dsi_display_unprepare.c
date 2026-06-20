__int64 __fastcall dsi_display_unprepare(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  int v9; // w0
  int v10; // w0
  int v11; // w0
  int v12; // w0
  int v13; // w20
  int v14; // w0
  unsigned int v15; // w20
  int v16; // w0
  unsigned int v17; // w8
  int v18; // w7
  _QWORD *v19; // x8
  _QWORD *v20; // x8
  __int64 v21; // x0
  char v23; // [xsp+0h] [xbp+0h]
  char v24; // [xsp+0h] [xbp+0h]

  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    return (unsigned int)-22;
  }
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dsi_display_unprepare",
    9976,
    -1,
    4369,
    *(unsigned __int8 *)(a1 + 848),
    -1059143953,
    a8,
    v23);
  mutex_lock(a1 + 72);
  if ( (*(_BYTE *)(a1 + 1217) & 1) == 0 && (*(_BYTE *)(a1 + 64) & 1) == 0 && (*(_BYTE *)(a1 + 1641) & 1) == 0 )
  {
    v9 = dsi_panel_unprepare(*(_QWORD *)(a1 + 264));
    if ( v9 )
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] panel unprepare failed, rc=%d\n",
        *(const char **)(a1 + 32),
        v9);
  }
  v10 = dsi_display_ctrl_host_disable(a1);
  if ( v10 )
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: [%s] failed to disable DSI host, rc=%d\n",
      *(const char **)(a1 + 32),
      v10);
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 264) + 2024LL) == 1 && *(_DWORD *)(a1 + 888) == 1 )
  {
    v11 = dsi_display_clk_ctrl(*(_QWORD *)(a1 + 1328), 4, 0);
    if ( v11 )
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] failed to disable esync clocks, rc=%d\n",
        *(const char **)(a1 + 32),
        v11);
  }
  v12 = dsi_display_clk_ctrl(*(_QWORD *)(a1 + 1320), 2, 0);
  if ( v12 )
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: [%s] failed to disable Link clocks, rc=%d\n",
      *(const char **)(a1 + 32),
      v12);
  if ( *(_DWORD *)(a1 + 160) )
  {
    v13 = dsi_ctrl_host_deinit(*(_QWORD *)(a1 + 168));
    if ( v13 )
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] failed to deinit host_%d, rc=%d\n",
        *(const char **)(a1 + 32),
        0,
        v13);
    if ( *(_DWORD *)(a1 + 160) < 2u )
    {
      if ( !v13 )
        goto LABEL_24;
    }
    else
    {
      v14 = dsi_ctrl_host_deinit(*(_QWORD *)(a1 + 216));
      if ( !v14 )
        goto LABEL_24;
      v13 = v14;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] failed to deinit host_%d, rc=%d\n",
        *(const char **)(a1 + 32),
        1,
        v14);
    }
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: [%s] failed to deinit controller, rc=%d\n",
      *(const char **)(a1 + 32),
      v13);
  }
LABEL_24:
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 264) + 1962LL) & 1) == 0 )
  {
    v16 = dsi_display_mgr_phy_disable(a1);
    if ( v16 )
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] failed to disable DSI PHY, rc=%d\n",
        *(const char **)(a1 + 32),
        v16);
  }
  v15 = dsi_display_clk_ctrl(*(_QWORD *)(a1 + 1320), 1, 0);
  if ( v15 )
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: [%s] failed to disable DSI clocks, rc=%d\n",
      *(const char **)(a1 + 32),
      v15);
  v17 = *(_DWORD *)(a1 + 160);
  if ( v17 )
  {
    if ( a1 != -168 )
    {
      dsi_ctrl_isr_configure(*(_QWORD *)(a1 + 168), 0);
      v17 = *(_DWORD *)(a1 + 160);
    }
    if ( v17 >= 2 && a1 != -216 )
      dsi_ctrl_isr_configure(*(_QWORD *)(a1 + 216), 0);
  }
  if ( (*(_BYTE *)(a1 + 1217) & 1) == 0 && (*(_BYTE *)(a1 + 64) & 1) == 0 && (*(_BYTE *)(a1 + 1641) & 1) == 0 )
  {
    v15 = dsi_display_mgr_panel_post_unprepare(a1);
    if ( v15 )
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] panel post-unprepare failed, rc=%d\n",
        *(const char **)(a1 + 32),
        v15);
  }
  *(_BYTE *)(a1 + 1642) = 0;
  mutex_unlock(a1 + 72);
  if ( *(_DWORD *)(a1 + 160) )
  {
    v19 = *(_QWORD **)(a1 + 168);
    v19[249] = 0;
    v19[248] = 0;
    v19[247] = 0;
    if ( *(_DWORD *)(a1 + 160) >= 2u )
    {
      v20 = *(_QWORD **)(a1 + 216);
      v20[249] = 0;
      v20[248] = 0;
      v20[247] = 0;
    }
  }
  v21 = *(_QWORD *)(a1 + 1376);
  if ( v21 )
  {
    destroy_workqueue(v21);
    *(_QWORD *)(a1 + 1376) = 0;
  }
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dsi_display_unprepare",
    10044,
    -1,
    8738,
    *(unsigned __int8 *)(a1 + 848),
    -1059143953,
    v18,
    v24);
  return v15;
}
