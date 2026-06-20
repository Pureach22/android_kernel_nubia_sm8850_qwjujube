__int64 __fastcall dsi_display_mipi_host_init(__int64 *a1)
{
  __int64 v1; // x9
  unsigned int v3; // w19

  v1 = *a1;
  a1[159] = (__int64)dsi_host_ops;
  a1[158] = v1 + 16;
  v3 = mipi_dsi_host_register(a1 + 158);
  if ( v3 )
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: [%s] failed to register mipi dsi host, rc=%d\n",
      (const char *)a1[4],
      v3);
  return v3;
}
