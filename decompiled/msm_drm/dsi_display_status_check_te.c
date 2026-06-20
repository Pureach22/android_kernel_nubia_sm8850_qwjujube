__int64 __fastcall dsi_display_status_check_te(__int64 *a1, __int64 a2)
{
  __int64 v2; // x22
  int v3; // w20
  __int64 v5; // x0
  __int64 v6; // x0
  unsigned int v7; // w21
  __int64 v8; // x0
  unsigned int v9; // w23
  int v10; // w22
  __int64 v11; // x0
  int v12; // w8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 result; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x8
  _QWORD v23[13]; // [xsp+8h] [xbp-68h] BYREF

  v23[12] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (_DWORD)a2 )
  {
    v2 = *a1;
    v3 = a2;
    memset(v23, 0, 96);
    if ( v2 )
    {
      if ( *((_BYTE *)a1 + 1641) == 1 )
      {
        drm_dev_printk(0, &unk_2597DF, "[msm-dsi-info]: GPIO's are not enabled in trusted VM\n");
        goto LABEL_12;
      }
      if ( (a1[15] & 0x80000000) == 0 )
      {
        *((_DWORD *)a1 + 32) = 0;
        _init_swait_queue_head(a1 + 17, "&x->wait", &init_completion___key_7);
        v5 = gpio_to_desc(*((unsigned int *)a1 + 30));
        v6 = gpiod_to_irq(v5);
        v7 = v6;
        irq_modify_status(v6, 0, 0x80000);
        if ( (msm_gpio_get_pin_address(*((unsigned int *)a1 + 30), v23) & 1) == 0 )
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Failed to get GPIO pin address\n");
        v8 = devm_ioremap(*a1 + 16);
        v9 = readl_relaxed_21(v8);
        v10 = devm_request_threaded_irq(v2 + 16, v7, dsi_display_panel_te_irq_handler, 0, 8194, "TE_GPIO");
        v11 = devm_ioremap(*a1 + 16);
        writel_relaxed_18(v9, v11);
        if ( !v10 )
        {
          disable_irq(v7);
          *((_BYTE *)a1 + 124) = 0;
          goto LABEL_12;
        }
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: TE request_irq failed for ESD rc:%d\n", v10);
        irq_modify_status(v7, 0x80000, 0);
      }
      printk(&unk_24AAB2, a2);
      v22 = a1[33];
      if ( *(_DWORD *)(v22 + 1724) == 2 )
        *(_BYTE *)(v22 + 1720) = 0;
    }
    else
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid platform device\n");
    }
LABEL_12:
    v12 = *((unsigned __int8 *)a1 + 124);
    if ( (v12 & 1) != 0 )
    {
      if ( v3 >= 1 )
        goto LABEL_14;
    }
    else
    {
      v13 = gpio_to_desc(*((unsigned int *)a1 + 30));
      v14 = gpiod_to_irq(v13);
      enable_irq(v14);
      v12 = 1;
      *((_BYTE *)a1 + 124) = 1;
      if ( v3 >= 1 )
      {
        do
        {
LABEL_14:
          *((_DWORD *)a1 + 32) = 0;
          if ( !wait_for_completion_timeout(a1 + 16, 15) )
          {
            drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: TE check failed\n");
            if ( *((_BYTE *)a1 + 124) == 1 )
            {
              v20 = gpio_to_desc(*((unsigned int *)a1 + 30));
              v21 = gpiod_to_irq(v20);
              disable_irq(v21);
              *((_BYTE *)a1 + 124) = 0;
            }
            result = 4294967274LL;
            goto LABEL_24;
          }
          --v3;
        }
        while ( v3 );
        if ( (*((_BYTE *)a1 + 124) & 1) != 0 )
          goto LABEL_20;
        goto LABEL_21;
      }
    }
    if ( v12 )
    {
LABEL_20:
      v15 = gpio_to_desc(*((unsigned int *)a1 + 30));
      v16 = gpiod_to_irq(v15);
      disable_irq(v16);
      *((_BYTE *)a1 + 124) = 0;
    }
LABEL_21:
    v17 = gpio_to_desc(*((unsigned int *)a1 + 30));
    v18 = gpiod_to_irq(v17);
    if ( (_DWORD)v18 )
      free_irq(v18, a1);
  }
  result = 1;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
