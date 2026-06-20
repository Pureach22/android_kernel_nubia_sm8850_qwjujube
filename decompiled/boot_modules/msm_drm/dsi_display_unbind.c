__int64 __fastcall dsi_display_unbind(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  int v3; // w8
  int v4; // w0
  int v5; // w0
  int v6; // w0
  int v7; // w0
  __int64 v8; // x0

  if ( !a2 || !a1 || a1 == 16 )
    return drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid param(s)\n");
  v2 = *(_QWORD *)(a1 + 152);
  if ( !v2 || !*(_QWORD *)(v2 + 272) )
    return drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid display\n");
  mutex_lock(v2 + 72);
  dsi_display_manager_unregister(v2);
  mipi_dsi_host_unregister(v2 + 1264);
  v3 = *(_DWORD *)(v2 + 160);
  *(_QWORD *)(v2 + 1272) = 0;
  *(_QWORD *)(v2 + 1264) = 0;
  if ( v3 )
  {
    v4 = dsi_phy_drv_deinit();
    if ( v4 )
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] failed to deinit phy%d driver, rc=%d\n",
        *(const char **)(v2 + 32),
        0,
        v4);
    *(_QWORD *)(*(_QWORD *)(v2 + 168) + 2840LL) = 0;
    v5 = dsi_ctrl_drv_deinit(*(_QWORD *)(v2 + 168));
    if ( v5 )
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] failed to deinit ctrl%d driver, rc=%d\n",
        *(const char **)(v2 + 32),
        0,
        v5);
    if ( *(_DWORD *)(v2 + 160) >= 2u )
    {
      v6 = dsi_phy_drv_deinit();
      if ( v6 )
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] failed to deinit phy%d driver, rc=%d\n",
          *(const char **)(v2 + 32),
          1,
          v6);
      *(_QWORD *)(*(_QWORD *)(v2 + 168) + 2840LL) = 0;
      v7 = dsi_ctrl_drv_deinit(*(_QWORD *)(v2 + 216));
      if ( v7 )
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] failed to deinit ctrl%d driver, rc=%d\n",
          *(const char **)(v2 + 32),
          1,
          v7);
    }
  }
  *(_DWORD *)(v2 + 864) = 0;
  v8 = *(_QWORD *)(v2 + 1336);
  if ( v8 )
  {
    debugfs_remove(v8);
    *(_QWORD *)(v2 + 1336) = 0;
  }
  return mutex_unlock(v2 + 72);
}
