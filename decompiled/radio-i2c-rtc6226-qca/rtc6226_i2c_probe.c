__int64 __fastcall rtc6226_i2c_probe(_QWORD *a1)
{
  __int64 (*v2)(void); // x8
  __int64 result; // x0
  unsigned __int64 v4; // x21
  unsigned __int64 v5; // x20
  __int64 v6; // x0
  __int64 v7; // x23
  __int64 v8; // x22
  unsigned int v9; // w0
  unsigned int v10; // w24
  unsigned int v11; // w0
  __int64 v12; // x0
  void *v13; // x0
  __int64 v14; // x8
  unsigned int v15; // w0
  __int64 v16; // x0
  unsigned int v17; // w0
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x8
  void *v25; // x0
  __int64 v26; // x8
  _QWORD *v27; // x8
  _QWORD *v28; // x8

  v2 = *(__int64 (**)(void))(*(_QWORD *)(a1[3] + 16LL) + 32LL);
  if ( *((_DWORD *)v2 - 1) != 2093148950 )
    __break(0x8228u);
  if ( (v2() & 1) == 0 )
    return 4294967277LL;
  v4 = regulator_get(a1 + 4, &unk_DAC3);
  if ( v4 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_D796, "rtc6226_i2c_probe");
    return (unsigned int)v4;
  }
  v5 = regulator_get(a1 + 4, "vdd");
  if ( v5 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_CF39, "rtc6226_i2c_probe");
    regulator_put(v4);
    return (unsigned int)v5;
  }
  v6 = _kmalloc_cache_noprof(i2c_del_driver, 3520, 3512);
  if ( !v6 )
  {
    regulator_put(v4);
    regulator_put(v5);
    return 4294967284LL;
  }
  v7 = v6 + 24;
  v8 = v6;
  v9 = v4l2_device_register(a1 + 4, v6 + 24);
  if ( (v9 & 0x80000000) != 0 )
  {
    v10 = v9;
    printk(&unk_DAC7, "rtc6226_i2c_probe");
    goto LABEL_57;
  }
  *(_DWORD *)(v8 + 1752) = 0;
  *(_QWORD *)(v8 + 3488) = a1;
  _mutex_init(v8 + 1872, "&radio->lock", &rtc6226_i2c_probe___key);
  *(_DWORD *)(v8 + 3448) = 0;
  _init_swait_queue_head(v8 + 3456, "&x->wait", &init_completion___key);
  v11 = rtc6226_parse_dt(a1 + 4, v8);
  if ( v11 )
  {
    v10 = v11;
    printk(&unk_CBFB, "rtc6226_i2c_probe");
    goto LABEL_56;
  }
  v12 = devm_kmalloc(a1 + 4, 32, 3520);
  *(_QWORD *)(v8 + 1728) = v12;
  if ( v12 )
  {
    v14 = a1[97];
    *(_QWORD *)v12 = v5;
    *(_QWORD *)(v12 + 8) = "vdd";
    *(_BYTE *)(v12 + 28) = 0;
    of_property_read_variable_u32_array(v14, "rtc6226,vdd-load", v12 + 24, 1, 0);
    printk(&unk_D567, "rtc6226_i2c_probe");
    v15 = rtc6226_dt_parse_vreg_info(a1 + 4, *(_QWORD *)(v8 + 1728), "rtc6226,vdd-supply-voltage");
    if ( (v15 & 0x80000000) != 0 )
    {
      v10 = v15;
      v25 = &unk_D7CB;
    }
    else
    {
      v16 = devm_kmalloc(a1 + 4, 32, 3520);
      *(_QWORD *)(v8 + 1736) = v16;
      if ( !v16 )
      {
        v13 = &unk_D3E5;
        goto LABEL_16;
      }
      *(_QWORD *)v16 = v4;
      *(_QWORD *)(v16 + 8) = &unk_DAC3;
      *(_BYTE *)(v16 + 28) = 0;
      v17 = rtc6226_dt_parse_vreg_info(a1 + 4, v16, "rtc6226,vio-supply-voltage");
      if ( (v17 & 0x80000000) == 0 )
      {
        if ( (unsigned int)rtc6226_pinctrl_init(v8) )
          printk(&unk_D2A8, "rtc6226_i2c_probe");
        memcpy((void *)(v8 + 144), &rtc6226_viddev_template, 0x538u);
        *(_QWORD *)(v8 + 1424) = &rtc6226_ioctl_ops;
        *(_QWORD *)(v8 + 1248) = v7;
        *(_DWORD *)(v8 + 320) = 17106176;
        *(_QWORD *)(v8 + 480) = v8;
        *(_DWORD *)(v8 + 3120) = 300;
        v18 = _kmalloc_noprof(*(unsigned int *)(v8 + 3120), 3264);
        v19 = v8;
        *(_QWORD *)(v8 + 1920) = v18;
        if ( !v18 )
        {
          v10 = -5;
LABEL_55:
          video_device_release_empty(v19 + 144);
          goto LABEL_56;
        }
        *(_DWORD *)(v8 + 1972) = 0;
        if ( (unsigned int)_kfifo_alloc(v8 + 3136, 256, 1, 3264) )
          goto LABEL_43;
        *(_DWORD *)(v8 + 1976) = 0;
        if ( (unsigned int)_kfifo_alloc(v8 + 3160, 256, 1, 3264) )
          goto LABEL_43;
        *(_DWORD *)(v8 + 1980) = 0;
        if ( (unsigned int)_kfifo_alloc(v8 + 3184, 256, 1, 3264) )
          goto LABEL_43;
        *(_DWORD *)(v8 + 1984) = 0;
        if ( (unsigned int)_kfifo_alloc(v8 + 3208, 256, 1, 3264) )
          goto LABEL_43;
        *(_DWORD *)(v8 + 1988) = 0;
        if ( (unsigned int)_kfifo_alloc(v8 + 3232, 256, 1, 3264) )
          goto LABEL_43;
        *(_DWORD *)(v8 + 1992) = 0;
        if ( (unsigned int)_kfifo_alloc(v8 + 3256, 256, 1, 3264)
          || (*(_DWORD *)(v8 + 1996) = 0, (unsigned int)_kfifo_alloc(v8 + 3280, 256, 1, 3264))
          || (*(_DWORD *)(v8 + 2000) = 0, (unsigned int)_kfifo_alloc(v8 + 3304, 256, 1, 3264))
          || (*(_DWORD *)(v8 + 2004) = 0, (unsigned int)_kfifo_alloc(v8 + 3328, 256, 1, 3264))
          || (*(_DWORD *)(v8 + 2008) = 0, (unsigned int)_kfifo_alloc(v8 + 3352, 256, 1, 3264))
          || (*(_DWORD *)(v8 + 2012) = 0, (unsigned int)_kfifo_alloc(v8 + 3376, 256, 1, 3264))
          || (*(_DWORD *)(v8 + 2016) = 0, (unsigned int)_kfifo_alloc(v8 + 3400, 256, 1, 3264))
          || (*(_DWORD *)(v8 + 2020) = 0, (unsigned int)_kfifo_alloc(v8 + 3424, 256, 1, 3264)) )
        {
LABEL_43:
          printk(&unk_CC9A, "rtc6226_i2c_probe");
          v10 = -12;
        }
        else
        {
          *(_DWORD *)(v8 + 1744) = -1;
          *(_QWORD *)(v8 + 2048) = 0;
          *(_QWORD *)(v8 + 2040) = 0;
          *(_QWORD *)(v8 + 2032) = 0;
          *(_QWORD *)(v8 + 3124) = 0;
          _init_waitqueue_head(v8 + 2520, "&radio->event_queue", &rtc6226_i2c_probe___key_50);
          _init_waitqueue_head(v8 + 1832, "&radio->read_queue", &rtc6226_i2c_probe___key_52);
          _init_waitqueue_head(&rtc6226_wq, "&rtc6226_wq", &rtc6226_i2c_probe___key_54);
          v20 = alloc_workqueue("%s", (const char *)0x6000A);
          *(_QWORD *)(v8 + 2032) = v20;
          if ( !v20 )
          {
            v24 = v8;
            v10 = -12;
LABEL_54:
            kfree(*(_QWORD *)(v24 + 1920));
            v19 = v8;
            goto LABEL_55;
          }
          v21 = alloc_workqueue("%s", (const char *)0x6000A);
          *(_QWORD *)(v8 + 2040) = v21;
          if ( v21 )
          {
            v22 = alloc_workqueue("%s", (const char *)0x6000A);
            v23 = v8;
            *(_QWORD *)(v8 + 2048) = v22;
            if ( v22 )
            {
              result = _video_register_device(v8 + 144, 2, 0xFFFFFFFFLL, 1, **(_QWORD **)(v8 + 312));
              if ( !(_DWORD)result )
              {
                a1[23] = v8;
                return result;
              }
              v10 = result;
              dev_info(a1 + 4, "Could not register video device\n");
              destroy_workqueue(*(_QWORD *)(v8 + 2048));
              v23 = v8;
            }
            else
            {
              v10 = -12;
            }
            destroy_workqueue(*(_QWORD *)(v23 + 2040));
            v26 = v8;
          }
          else
          {
            v26 = v8;
            v10 = -12;
          }
          destroy_workqueue(*(_QWORD *)(v26 + 2032));
        }
        v24 = v8;
        goto LABEL_54;
      }
      v10 = v17;
      v25 = &unk_D150;
    }
    printk(v25, "rtc6226_i2c_probe");
    goto LABEL_56;
  }
  v13 = &unk_CFB8;
LABEL_16:
  printk(v13, "rtc6226_i2c_probe");
  v10 = -12;
LABEL_56:
  v4l2_device_unregister(v7);
LABEL_57:
  v27 = *(_QWORD **)(v8 + 1736);
  if ( v27 && *v27 )
  {
    regulator_put(*v27);
    devm_kfree(a1 + 4, *(_QWORD *)(v8 + 1736));
  }
  else
  {
    regulator_put(v4);
  }
  v28 = *(_QWORD **)(v8 + 1728);
  if ( v28 && *v28 )
  {
    regulator_put(*v28);
    devm_kfree(a1 + 4, *(_QWORD *)(v8 + 1728));
  }
  else
  {
    regulator_put(v5);
  }
  kfree(v8);
  return v10;
}
