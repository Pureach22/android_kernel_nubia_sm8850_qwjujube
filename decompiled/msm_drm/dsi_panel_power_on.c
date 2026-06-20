__int64 __fastcall dsi_panel_power_on(const char **a1)
{
  int v2; // w0
  unsigned int v3; // w20
  __int64 v4; // x0
  __int64 v5; // x0
  unsigned int v6; // w0
  unsigned __int64 v7; // x0
  __int64 v8; // x8
  const char *v9; // x21
  int v10; // w0
  const char *v11; // x3
  unsigned int v12; // w20
  __int64 v13; // x0
  unsigned int v14; // w0
  unsigned int v15; // w21
  __int64 v16; // x23
  unsigned int v17; // w20
  __int64 v18; // x0
  int v19; // w8
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  unsigned int v24; // w8
  unsigned int v25; // w20
  __int64 v26; // x0
  int v27; // w0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  unsigned __int64 v32; // x0
  const char *v33; // x21
  int v34; // w0
  __int64 v35; // x0

  v2 = dsi_pwr_enable_regulator((_DWORD *)a1 + 360, 1);
  if ( !v2 )
  {
    if ( (*((_BYTE *)a1 + 1274) & 1) == 0 )
    {
      v7 = (unsigned __int64)a1[202];
      if ( v7 )
      {
        if ( v7 <= 0xFFFFFFFFFFFFF000LL )
        {
          v8 = 204;
          if ( *((_BYTE *)a1 + 2024) )
            v8 = 205;
          v9 = a1[v8];
          v10 = pinctrl_select_state(v7, v9);
          if ( v10 )
          {
            v3 = v10;
            drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] failed to set pin state, rc=%d\n", *a1, v10);
            v11 = *a1;
            a1[203] = v9;
            drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] failed to set pinctrl, rc=%d\n", v11, v3);
LABEL_47:
            dsi_pwr_enable_regulator((_DWORD *)a1 + 360, 0);
            return v3;
          }
          a1[203] = v9;
        }
      }
    }
    if ( (*((_DWORD *)a1 + 399) & 0x80000000) == 0 )
    {
      v4 = *((unsigned int *)a1 + 400);
      if ( (v4 & 0x80000000) == 0 )
      {
        v5 = gpio_to_desc(v4);
        v6 = gpiod_direction_output_raw(v5, 1);
        if ( v6 )
        {
          v3 = v6;
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: unable to set dir for disp gpio rc=%d\n", v6);
LABEL_37:
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] failed to reset panel, rc=%d\n", *a1, v3);
          v28 = *((unsigned int *)a1 + 400);
          if ( (v28 & 0x80000000) == 0 )
          {
            v29 = gpio_to_desc(v28);
            gpiod_set_raw_value(v29, 0);
          }
          v30 = *((unsigned int *)a1 + 385);
          if ( (v30 & 0x80000000) == 0 )
          {
            v31 = gpio_to_desc(v30);
            gpiod_set_raw_value(v31, 0);
          }
          if ( (*((_BYTE *)a1 + 1274) & 1) == 0 )
          {
            v32 = (unsigned __int64)a1[202];
            if ( v32 )
            {
              if ( v32 <= 0xFFFFFFFFFFFFF000LL )
              {
                v33 = a1[207];
                v34 = pinctrl_select_state(v32, v33);
                if ( v34 )
                  drm_dev_printk(
                    0,
                    &unk_248D72,
                    "*ERROR* [msm-dsi-error]: [%s] failed to set pin state, rc=%d\n",
                    *a1,
                    v34);
                a1[203] = v33;
              }
            }
          }
          goto LABEL_47;
        }
      }
      if ( *((_DWORD *)a1 + 398) )
      {
        v12 = *(_DWORD *)a1[198];
        v13 = gpio_to_desc(*((unsigned int *)a1 + 399));
        v14 = gpiod_direction_output_raw(v13, v12);
        if ( v14 )
        {
          v3 = v14;
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: unable to set dir for rst gpio rc=%d\n", v14);
          goto LABEL_37;
        }
        if ( *((_DWORD *)a1 + 398) )
        {
          v15 = 0;
          do
          {
            v16 = 8LL * (int)v15;
            v17 = *(_DWORD *)&a1[198][v16];
            v18 = gpio_to_desc(*((unsigned int *)a1 + 399));
            gpiod_set_raw_value(v18, v17);
            v19 = *(_DWORD *)&a1[198][v16 + 4];
            if ( v19 )
              usleep_range_state((unsigned int)(1000 * v19), (unsigned int)(1000 * v19 + 100), 2);
            ++v15;
          }
          while ( v15 < *((_DWORD *)a1 + 398) );
        }
      }
    }
    v20 = *((unsigned int *)a1 + 385);
    if ( (v20 & 0x80000000) != 0 )
    {
      v3 = 0;
      v22 = *((unsigned int *)a1 + 402);
      if ( (v22 & 0x80000000) != 0 )
        goto LABEL_28;
    }
    else
    {
      v21 = gpio_to_desc(v20);
      v3 = gpiod_direction_output_raw(v21, 1);
      if ( v3 )
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: unable to set dir for bklt gpio rc=%d\n", v3);
      v22 = *((unsigned int *)a1 + 402);
      if ( (v22 & 0x80000000) != 0 )
      {
LABEL_28:
        v23 = *((unsigned int *)a1 + 554);
        if ( (v23 & 0x80000000) != 0 )
        {
LABEL_36:
          if ( !v3 )
            return v3;
          goto LABEL_37;
        }
LABEL_49:
        v35 = gpio_to_desc(v23);
        v3 = gpiod_direction_input(v35);
        if ( !v3 )
          return v3;
        printk(&unk_24E2D4, v3);
        goto LABEL_37;
      }
    }
    v24 = *((_DWORD *)a1 + 403) - 1;
    if ( v24 > 3 )
      v25 = 1;
    else
      v25 = dword_29D29C[v24];
    v26 = gpio_to_desc(v22);
    v27 = gpiod_direction_output_raw(v26, v25);
    if ( v27 )
    {
      v3 = v27;
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: unable to set dir for mode gpio rc=%d\n", v27);
      v23 = *((unsigned int *)a1 + 554);
      if ( (v23 & 0x80000000) != 0 )
        goto LABEL_36;
    }
    else
    {
      v23 = *((unsigned int *)a1 + 554);
      if ( (v23 & 0x80000000) != 0 )
        return 0;
    }
    goto LABEL_49;
  }
  v3 = v2;
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] failed to enable vregs, rc=%d\n", *a1, v2);
  return v3;
}
