size_t __fastcall sysfs_store_generic_dreadlp(int a1, int a2, char *string, size_t maxlen)
{
  size_t v4; // x19

  if ( main_panel )
  {
    v4 = maxlen;
    zte_panel_reg_handle(main_panel, string, maxlen);
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: No panel device\n", maxlen);
    return -19;
  }
  return v4;
}
