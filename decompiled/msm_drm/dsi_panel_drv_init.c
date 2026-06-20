__int64 __fastcall dsi_panel_drv_init(const char **a1, const char *a2)
{
  const char *v4; // x9
  int v5; // w0
  unsigned int v6; // w20
  const char *v7; // x8
  int v8; // w0
  const char *v9; // x8

  if ( a1 && a2 )
  {
    mutex_lock(a1 + 130);
    v4 = a1[280];
    a1[3] = a2;
    a1[121] = (const char *)0x400000000LL;
    a1[151] = a2;
    if ( *((_DWORD *)v4 - 1) != -1699580201 )
      __break(0x8229u);
    v5 = ((__int64 (__fastcall *)(const char **))v4)(a1);
    if ( v5 )
    {
      v6 = v5;
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] failed to init pinctrl, rc=%d\n", *a1, v5);
LABEL_20:
      mutex_unlock(a1 + 130);
      return v6;
    }
    v7 = a1[281];
    if ( *((_DWORD *)v7 - 1) != -1699580201 )
      __break(0x8228u);
    v8 = ((__int64 (__fastcall *)(const char **))v7)(a1);
    if ( v8 )
    {
      v6 = v8;
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] failed to request gpios, rc=%d\n", *a1, v8);
      if ( (*((_BYTE *)a1 + 1274) & 1) != 0 )
        goto LABEL_20;
    }
    else
    {
      v9 = a1[284];
      if ( *((_DWORD *)v9 - 1) != -1699580201 )
        __break(0x8228u);
      v6 = ((__int64 (__fastcall *)(const char **))v9)(a1);
      if ( v6 != -517 )
      {
        if ( !v6 )
          goto LABEL_20;
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] failed to register backlight, rc=%d\n", *a1, v6);
      }
      dsi_panel_gpio_release(a1);
      if ( (*((_BYTE *)a1 + 1274) & 1) != 0 )
        goto LABEL_20;
    }
    devm_pinctrl_put(a1[202]);
    goto LABEL_20;
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid params\n");
  return (unsigned int)-22;
}
