__int64 __fastcall wcd9378_soc_codec_probe(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x22
  unsigned int v4; // w0
  _DWORD *v6; // x22
  int v7; // w8
  int v8; // w9
  __int64 v9; // x3
  int v10; // w8
  int v11; // w9
  __int64 v12; // x3
  int v13; // w8
  int v14; // w8
  __int64 v15; // x3
  __int64 (__fastcall *v16)(__int64, __int64, __int64); // x8
  __int64 v17; // x0
  int v18; // w0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x8
  unsigned int v22; // w19

  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
  if ( !v1 )
    return 4294967274LL;
  *(_QWORD *)(v1 + 32) = a1;
  snd_soc_component_init_regmap();
  devm_regmap_qti_debugfs_register(*(_QWORD *)(v1 + 64) + 72LL, *(_QWORD *)(v1 + 48));
  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
  if ( (snd_soc_component_read(a1, 1075315917) & 1) != 0 )
    v4 = (unsigned int)snd_soc_component_read(a1, 1075315917) >> 1;
  else
    LOBYTE(v4) = snd_soc_component_read(a1, 1075315952);
  if ( (v4 & 1) != *(_DWORD *)(v3 + 24) )
  {
    dev_err(*(_QWORD *)(a1 + 24), "wcd mode check failed\n");
    return 4294967274LL;
  }
  if ( (unsigned int)wcd9378_mbhc_init(v1 + 336, a1) )
  {
    printk(&unk_14A6E, "wcd9378_soc_codec_probe");
    return 4294967274LL;
  }
  snd_soc_dapm_ignore_suspend(a1 + 208, "AMIC1");
  snd_soc_dapm_ignore_suspend(a1 + 208, "AMIC2");
  snd_soc_dapm_ignore_suspend(a1 + 208, "AMIC3");
  snd_soc_dapm_ignore_suspend(a1 + 208, "AMIC4");
  snd_soc_dapm_ignore_suspend(a1 + 208, "VA AMIC1");
  snd_soc_dapm_ignore_suspend(a1 + 208, "VA AMIC2");
  snd_soc_dapm_ignore_suspend(a1 + 208, "VA AMIC3");
  snd_soc_dapm_ignore_suspend(a1 + 208, "VA AMIC4");
  snd_soc_dapm_ignore_suspend(a1 + 208, "IN1_HPHL");
  snd_soc_dapm_ignore_suspend(a1 + 208, "IN2_HPHR");
  snd_soc_dapm_ignore_suspend(a1 + 208, "IN3_AUX");
  snd_soc_dapm_ignore_suspend(a1 + 208, "ADC1_OUTPUT");
  snd_soc_dapm_ignore_suspend(a1 + 208, "ADC2_OUTPUT");
  snd_soc_dapm_ignore_suspend(a1 + 208, "ADC3_OUTPUT");
  snd_soc_dapm_ignore_suspend(a1 + 208, "EAR");
  snd_soc_dapm_ignore_suspend(a1 + 208, "AUX");
  snd_soc_dapm_ignore_suspend(a1 + 208, "HPHL");
  snd_soc_dapm_ignore_suspend(a1 + 208, "HPHR");
  snd_soc_dapm_sync(a1 + 208);
  wcd_cls_h_init(v1 + 300);
  wcd9378_init_reg(a1);
  v6 = *(_DWORD **)(**(_QWORD **)(*(_QWORD *)(a1 + 24) + 152LL) + 144LL);
  v7 = v6[8];
  if ( v7 > 2499 )
  {
    if ( v7 > 2749 )
    {
      if ( v7 == 2750 )
      {
        v8 = 5;
        goto LABEL_30;
      }
      if ( v7 == 2800 )
      {
        v8 = 242;
        goto LABEL_30;
      }
    }
    else
    {
      if ( v7 == 2500 )
      {
        v8 = 4;
        goto LABEL_30;
      }
      if ( v7 == 2700 )
      {
        v8 = 241;
        goto LABEL_30;
      }
    }
  }
  else if ( v7 > 1799 )
  {
    if ( v7 == 1800 )
    {
      v8 = 3;
      goto LABEL_30;
    }
    if ( v7 == 2200 )
    {
      v8 = 240;
      goto LABEL_30;
    }
  }
  else
  {
    if ( !v7 )
    {
      v8 = 1;
      goto LABEL_30;
    }
    if ( v7 == 1200 )
    {
      v8 = 2;
      goto LABEL_30;
    }
  }
  if ( (unsigned int)(v7 - 2851) <= 0xFFFFF8C4 )
  {
    printk(&unk_12F68, "wcd9378_get_micb_vout_ctl_val");
    v9 = 4294967274LL;
  }
  else
  {
    v9 = (unsigned __int16)(v7 - 1000) / 0x32u;
  }
  snd_soc_component_update_bits(a1, 1075316131, 255, v9);
  v8 = 243;
LABEL_30:
  v10 = v6[9];
  v6[11] = v8;
  if ( v10 > 2499 )
  {
    if ( v10 > 2749 )
    {
      if ( v10 == 2750 )
      {
        v11 = 5;
        goto LABEL_52;
      }
      if ( v10 == 2800 )
      {
        v11 = 242;
        goto LABEL_52;
      }
    }
    else
    {
      if ( v10 == 2500 )
      {
        v11 = 4;
        goto LABEL_52;
      }
      if ( v10 == 2700 )
      {
        v11 = 241;
        goto LABEL_52;
      }
    }
  }
  else if ( v10 > 1799 )
  {
    if ( v10 == 1800 )
    {
      v11 = 3;
      goto LABEL_52;
    }
    if ( v10 == 2200 )
    {
      v11 = 240;
      goto LABEL_52;
    }
  }
  else
  {
    if ( !v10 )
    {
      v11 = 1;
      goto LABEL_52;
    }
    if ( v10 == 1200 )
    {
      v11 = 2;
      goto LABEL_52;
    }
  }
  if ( (unsigned int)(v10 - 2851) <= 0xFFFFF8C4 )
  {
    printk(&unk_12F68, "wcd9378_get_micb_vout_ctl_val");
    v12 = 4294967274LL;
  }
  else
  {
    v12 = (unsigned __int16)(v10 - 1000) / 0x32u;
  }
  snd_soc_component_update_bits(a1, 1075316132, 255, v12);
  v11 = 244;
LABEL_52:
  v13 = v6[10];
  v6[12] = v11;
  if ( v13 > 2499 )
  {
    if ( v13 > 2749 )
    {
      if ( v13 == 2750 )
      {
        v14 = 5;
        goto LABEL_74;
      }
      if ( v13 == 2800 )
      {
        v14 = 242;
        goto LABEL_74;
      }
    }
    else
    {
      if ( v13 == 2500 )
      {
        v14 = 4;
        goto LABEL_74;
      }
      if ( v13 == 2700 )
      {
        v14 = 241;
        goto LABEL_74;
      }
    }
LABEL_71:
    if ( (unsigned int)(v13 - 2851) <= 0xFFFFF8C4 )
    {
      printk(&unk_12F68, "wcd9378_get_micb_vout_ctl_val");
      v15 = 4294967274LL;
    }
    else
    {
      v15 = (unsigned __int16)(v13 - 1000) / 0x32u;
    }
    snd_soc_component_update_bits(a1, 1075316133, 255, v15);
    v14 = 245;
    goto LABEL_74;
  }
  if ( v13 > 1799 )
  {
    if ( v13 == 1800 )
    {
      v14 = 3;
      goto LABEL_74;
    }
    if ( v13 == 2200 )
    {
      v14 = 240;
      goto LABEL_74;
    }
    goto LABEL_71;
  }
  if ( !v13 )
  {
    v14 = 1;
    goto LABEL_74;
  }
  if ( v13 != 1200 )
    goto LABEL_71;
  v14 = 2;
LABEL_74:
  v6[13] = v14;
  v16 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v1 + 3240);
  *(_DWORD *)(v1 + 3256) = 1;
  *(_QWORD *)(v1 + 3200) = wcd9378_event_notify;
  if ( !v16 )
    goto LABEL_78;
  v17 = *(_QWORD *)(v1 + 3224);
  if ( *((_DWORD *)v16 - 1) != -875060373 )
    __break(0x8228u);
  v18 = v16(v17, v1 + 3200, 1);
  if ( v18 )
  {
    v21 = *(_QWORD *)(a1 + 24);
    v22 = v18;
    dev_err(v21, "%s: Failed to register notifier %d\n", "wcd9378_soc_codec_probe", v18);
    return v22;
  }
  else
  {
LABEL_78:
    v19 = devm_kmalloc(*(_QWORD *)(a1 + 24), 32, 3520);
    *(_QWORD *)(v1 + 344) = v19;
    if ( v19 && (v20 = devm_kmalloc(*(_QWORD *)(a1 + 24), 40, 3520), (*(_QWORD *)(v1 + 352) = v20) != 0) )
    {
      *(_DWORD *)(v20 + 20) = 824;
      *(_QWORD *)v20 = a1;
      *(_QWORD *)(v20 + 8) = &wcd9378_reg_array;
      *(_QWORD *)(v20 + 24) = wcd9378_sdca_readable_register;
      *(_QWORD *)(v20 + 32) = wcd9378_sdca_writeable_register;
      sdca_devices_debugfs_dentry_create(*(_QWORD *)(v1 + 344), v20);
      return 0;
    }
    else
    {
      return 4294967284LL;
    }
  }
}
