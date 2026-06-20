__int64 __fastcall dsi_panel_drv_deinit(const char **a1)
{
  const char *v2; // x8
  int v3; // w0
  const char *v4; // x8
  int v5; // w0
  const char *v6; // x8
  int v7; // w0
  int v8; // w8
  __int64 v9; // x20

  if ( a1 )
  {
    mutex_lock(a1 + 130);
    v2 = a1[285];
    if ( *((_DWORD *)v2 - 1) != -1699580201 )
      __break(0x8228u);
    v3 = ((__int64 (__fastcall *)(const char **))v2)(a1);
    if ( v3 )
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] failed to unregister backlight, rc=%d\n", *a1, v3);
    v4 = a1[283];
    if ( *((_DWORD *)v4 - 1) != -1699580201 )
      __break(0x8228u);
    v5 = ((__int64 (__fastcall *)(const char **))v4)(a1);
    if ( v5 )
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] failed to release gpios, rc=%d\n", *a1, v5);
    v6 = a1[282];
    if ( *((_DWORD *)v6 - 1) != -1699580201 )
      __break(0x8228u);
    v7 = ((__int64 (__fastcall *)(const char **))v6)(a1);
    if ( v7 )
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] failed to deinit gpios, rc=%d\n", *a1, v7);
    v8 = *((_DWORD *)a1 + 362) - 1;
    if ( v8 >= 0 )
    {
      v9 = 80LL * (unsigned int)v8;
      do
      {
        devm_regulator_put(*(_QWORD *)&a1[180][v9]);
        v9 -= 80;
      }
      while ( v9 != -80 );
    }
    a1[151] = nullptr;
    memset(a1 + 3, 0, 0x3E0u);
    mutex_unlock(a1 + 130);
    return 0;
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid params\n");
    return 4294967274LL;
  }
}
