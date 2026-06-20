__int64 __fastcall dsi_panel_bl_register(const char **a1)
{
  int v1; // w3
  unsigned int v2; // w19
  __int64 v5; // x0
  unsigned __int64 v7; // x0
  const char **v8; // x8
  const char *v9; // x1
  int v10; // w0

  if ( (*((_BYTE *)a1 + 1274) & 1) != 0 )
    return 0;
  v1 = *((_DWORD *)a1 + 368);
  if ( (unsigned int)(v1 - 2) < 3 )
  {
    return 0;
  }
  else if ( v1 )
  {
    if ( v1 == 1 )
    {
      v5 = backlight_device_get_by_type(1);
      if ( v5 )
      {
        v2 = 0;
        a1[196] = (const char *)v5;
      }
      else
      {
        v2 = -517;
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] fail raw backlight register rc=%d\n",
          *a1,
          4294966779LL);
      }
    }
    else
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Backlight type(%d) not supported\n", v1);
      return (unsigned int)-524;
    }
  }
  else
  {
    v7 = devm_pwm_get(a1[152], 0);
    v2 = v7;
    v8 = a1;
    a1[193] = (const char *)v7;
    if ( v7 && v7 < 0xFFFFFFFFFFFFF001LL )
    {
      v9 = a1[208];
      if ( v9 )
      {
        v10 = pinctrl_select_state(a1[202], v9);
        v8 = a1;
        if ( v10 )
        {
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] failed to set pwm pinctrl, rc=%d\n", *a1, v10);
          v8 = a1;
        }
      }
      v2 = 0;
      v8[203] = v8[208];
    }
    else
    {
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] failed to request pwm, rc=%d\n",
        *a1,
        (unsigned int)v7);
    }
  }
  return v2;
}
