__int64 __fastcall dsi_panel_gpio_request(__int64 a1)
{
  __int64 v2; // x0
  int v3; // w0
  unsigned int v4; // w20
  __int64 v5; // x0
  int v6; // w0
  int v7; // w0
  __int64 v8; // x0
  int v9; // w0
  __int64 v10; // x0
  int v11; // w0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  unsigned int v17; // w0

  if ( *(_BYTE *)(a1 + 2212) == 1 && !strcmp(*(const char **)(a1 + 8), "secondary") )
    return 0;
  v2 = *(unsigned int *)(a1 + 1596);
  if ( (v2 & 0x80000000) == 0 )
  {
    v3 = gpio_request(v2);
    if ( v3 )
    {
      v4 = v3;
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: request for reset_gpio failed, rc=%d\n", v3);
      return v4;
    }
  }
  v5 = *(unsigned int *)(a1 + 1600);
  if ( (v5 & 0x80000000) != 0 || (v6 = gpio_request(v5)) == 0 )
  {
    if ( *(_BYTE *)(a1 + 2232) == 1 && (*(_DWORD *)(a1 + 1604) & 0x80000000) == 0 )
    {
      v7 = gpio_request_one();
      if ( v7 )
      {
        v4 = v7;
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: request for oled_en_gpio failed, rc=%d\n", v7);
LABEL_23:
        v14 = *(unsigned int *)(a1 + 1600);
        if ( (v14 & 0x80000000) == 0 )
          gpio_free(v14);
        goto LABEL_25;
      }
    }
    v8 = *(unsigned int *)(a1 + 1540);
    if ( (v8 & 0x80000000) == 0 )
    {
      v9 = gpio_request(v8);
      if ( v9 )
      {
        v4 = v9;
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: request for bklt_en_gpio failed, rc=%d\n", v9);
LABEL_20:
        if ( *(_BYTE *)(a1 + 2232) == 1 )
        {
          v13 = *(unsigned int *)(a1 + 1604);
          if ( (v13 & 0x80000000) == 0 )
            gpio_free(v13);
        }
        goto LABEL_23;
      }
    }
    v10 = *(unsigned int *)(a1 + 1608);
    if ( (v10 & 0x80000000) == 0 )
    {
      v11 = gpio_request(v10);
      if ( v11 )
      {
        v4 = v11;
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: request for mode_gpio failed, rc=%d\n", v11);
        v12 = *(unsigned int *)(a1 + 1540);
        if ( (v12 & 0x80000000) == 0 )
          gpio_free(v12);
        goto LABEL_20;
      }
    }
    v16 = *(unsigned int *)(a1 + 2216);
    if ( (v16 & 0x80000000) == 0 )
    {
      v17 = gpio_request(v16);
      if ( v17 )
      {
        printk(&unk_271C3E, v17);
        v4 = 0;
        *(_DWORD *)(a1 + 2216) = -1;
        return v4;
      }
    }
    return 0;
  }
  v4 = v6;
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: request for disp_en_gpio failed, rc=%d\n", v6);
LABEL_25:
  v15 = *(unsigned int *)(a1 + 1596);
  if ( (v15 & 0x80000000) == 0 )
    gpio_free(v15);
  return v4;
}
