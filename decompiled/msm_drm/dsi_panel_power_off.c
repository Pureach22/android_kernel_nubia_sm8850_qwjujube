__int64 __fastcall dsi_panel_power_off(const char **a1)
{
  unsigned int v1; // w20
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  unsigned int v11; // w0
  unsigned __int64 v12; // x0
  const char *v13; // x20
  int v14; // w0
  int v15; // w21
  const char *v16; // x3

  if ( *((_BYTE *)a1 + 1972) == 1 )
  {
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: skip panel power off\n");
    return 0;
  }
  v3 = *((unsigned int *)a1 + 400);
  if ( (v3 & 0x80000000) == 0 )
  {
    v4 = gpio_to_desc(v3);
    gpiod_set_raw_value(v4, 0);
  }
  v5 = *((unsigned int *)a1 + 399);
  if ( (v5 & 0x80000000) == 0 && (*((_BYTE *)a1 + 1964) & 1) == 0 )
  {
    v6 = gpio_to_desc(v5);
    gpiod_set_raw_value(v6, 0);
  }
  v7 = *((unsigned int *)a1 + 402);
  if ( (v7 & 0x80000000) == 0 )
  {
    v8 = gpio_to_desc(v7);
    gpiod_set_raw_value(v8, 0);
  }
  v9 = *((unsigned int *)a1 + 554);
  if ( (v9 & 0x80000000) == 0 && (v10 = gpio_to_desc(v9), (v11 = gpiod_direction_input(v10)) != 0) )
  {
    printk(&unk_240CD6, v11);
    if ( (*((_BYTE *)a1 + 1274) & 1) == 0 )
      goto LABEL_13;
  }
  else if ( (*((_BYTE *)a1 + 1274) & 1) == 0 )
  {
LABEL_13:
    v12 = (unsigned __int64)a1[202];
    if ( v12 && v12 <= 0xFFFFFFFFFFFFF000LL )
    {
      v13 = a1[207];
      v14 = pinctrl_select_state(v12, v13);
      if ( v14 )
      {
        v15 = v14;
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] failed to set pin state, rc=%d\n", *a1, v14);
        v16 = *a1;
        a1[203] = v13;
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] failed set pinctrl state, rc=%d\n", v16, v15);
      }
      else
      {
        a1[203] = v13;
      }
    }
  }
  v1 = dsi_pwr_enable_regulator((_DWORD *)a1 + 360, 0);
  if ( v1 )
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] failed to enable vregs, rc=%d\n", *a1, v1);
  return v1;
}
