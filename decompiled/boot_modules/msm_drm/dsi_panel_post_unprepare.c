__int64 __fastcall dsi_panel_post_unprepare(const char **a1)
{
  unsigned int v2; // w20

  if ( a1 )
  {
    mutex_lock(a1 + 130);
    v2 = dsi_panel_power_off(a1);
    if ( v2 )
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] panel power_Off failed, rc=%d\n", *a1, v2);
    mutex_unlock(a1 + 130);
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid params\n");
    return (unsigned int)-22;
  }
  return v2;
}
