__int64 __fastcall dsi_ctrl_drv_deinit(__int64 a1)
{
  __int64 v2; // x0
  unsigned int v3; // w20

  if ( a1 )
  {
    mutex_lock(a1 + 32);
    v2 = *(_QWORD *)(a1 + 2856);
    if ( v2 )
    {
      debugfs_remove(v2);
      *(_QWORD *)(a1 + 2856) = 0;
    }
    v3 = dsi_ctrl_buffer_deinit((_QWORD *)a1);
    if ( v3 )
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: %s: Failed to free cmd buffers, rc=%d\n",
        *(const char **)(a1 + 16),
        v3);
    mutex_unlock(a1 + 32);
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Invalid params\n", "inv");
    return (unsigned int)-22;
  }
  return v3;
}
