__int64 __fastcall dsi_display_cont_splash_res_disable(__int64 a1)
{
  __int64 v1; // x20
  unsigned int v3; // w20

  v1 = *(_QWORD *)(a1 + 264);
  if ( *(_BYTE *)(v1 + 2212) == 1 && !strcmp(*(const char **)(v1 + 8), "secondary") )
  {
    return 0;
  }
  else
  {
    v3 = dsi_pwr_enable_regulator((_DWORD *)(v1 + 1440), 0);
    if ( v3 )
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] failed to disable vregs, rc=%d\n",
        **(const char ***)(a1 + 264),
        v3);
  }
  return v3;
}
