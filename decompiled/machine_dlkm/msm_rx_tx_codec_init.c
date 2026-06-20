__int64 __fastcall msm_rx_tx_codec_init(_QWORD *a1)
{
  __int64 v2; // x23
  __int64 v3; // x0
  __int64 v4; // x2
  __int64 v5; // x20
  __int64 module_entry; // x0
  __int64 v7; // x21
  __int64 v8; // x1
  __int64 v9; // x2
  unsigned int v10; // w22
  __int64 v11; // x0
  __int64 v12; // x21
  int v13; // w8
  __int64 v14; // x22
  __int64 v15; // x23
  __int64 v16; // x1
  __int64 v17; // x0
  __int64 v18; // x22
  __int64 v19; // x0
  __int64 v21; // x0
  __int64 v22; // x2

  v2 = *(_QWORD *)(a1[1] + 784LL);
  v3 = snd_soc_rtdcom_lookup(a1, "lpass-cdc");
  if ( !v3 )
  {
    printk(&unk_12A17, "msm_rx_tx_codec_init", v4);
    return 0;
  }
  v5 = v3;
  snd_soc_dapm_new_controls(v3 + 208, &msm_int_dapm_widgets, 13);
  snd_soc_dapm_ignore_suspend(v5 + 208, "Digital Mic0");
  snd_soc_dapm_ignore_suspend(v5 + 208, "Digital Mic1");
  snd_soc_dapm_ignore_suspend(v5 + 208, "Digital Mic2");
  snd_soc_dapm_ignore_suspend(v5 + 208, "Digital Mic3");
  snd_soc_dapm_ignore_suspend(v5 + 208, "Digital Mic4");
  snd_soc_dapm_ignore_suspend(v5 + 208, "Digital Mic5");
  snd_soc_dapm_ignore_suspend(v5 + 208, "Digital Mic6");
  snd_soc_dapm_ignore_suspend(v5 + 208, "Digital Mic7");
  snd_soc_dapm_ignore_suspend(v5 + 208, "Analog Mic1");
  snd_soc_dapm_ignore_suspend(v5 + 208, "Analog Mic2");
  snd_soc_dapm_ignore_suspend(v5 + 208, "Analog Mic3");
  snd_soc_dapm_ignore_suspend(v5 + 208, "Analog Mic4");
  snd_soc_dapm_ignore_suspend(v5 + 208, "Analog Mic5");
  if ( *(_DWORD *)(v2 + 96) )
  {
    if ( *(_QWORD *)v2 )
      goto LABEL_9;
  }
  else
  {
    lpass_cdc_set_port_map(v5, 3, &sm_rx_port_map);
    if ( *(_QWORD *)v2 )
      goto LABEL_9;
  }
  module_entry = snd_info_create_module_entry(
                   *(_QWORD *)(*(_QWORD *)(a1[1] + 80LL) + 392LL),
                   "codecs",
                   *(_QWORD *)(*(_QWORD *)(a1[1] + 80LL) + 608LL));
  if ( !module_entry )
    return 0;
  v7 = module_entry;
  *(_WORD *)(module_entry + 8) = 16749;
  if ( (snd_info_register() & 0x80000000) != 0 )
  {
    v19 = v7;
    goto LABEL_31;
  }
  *(_QWORD *)v2 = v7;
LABEL_9:
  lpass_cdc_info_create_codec_entry();
  lpass_cdc_register_wake_irq(v5, 0);
  v10 = 0;
  if ( *(_DWORD *)(v2 + 96) )
  {
LABEL_21:
    codec_reg_done = 1;
    msm_common_dai_link_init(a1, v8, v9);
    return v10;
  }
  v11 = snd_soc_rtdcom_lookup(a1, "wcd939x_codec");
  if ( v11 )
  {
    v12 = v11;
    v13 = 1;
  }
  else
  {
    printk(&unk_140A1, "msm_rx_tx_codec_init", "wcd939x_codec");
    v21 = snd_soc_rtdcom_lookup(a1, "wcd9378_codec");
    if ( !v21 )
    {
      printk(&unk_12349, "msm_rx_tx_codec_init", v22);
      return (unsigned int)-22;
    }
    v12 = v21;
    v13 = 2;
  }
  *(_DWORD *)(v2 + 148) = v13;
  v14 = *(_QWORD *)(*(_QWORD *)(v12 + 32) + 80LL);
  snd_soc_dapm_ignore_suspend(v12 + 208, "EAR");
  if ( *(_DWORD *)(v2 + 148) != 1 )
    snd_soc_dapm_ignore_suspend(v12 + 208, &unk_12361);
  snd_soc_dapm_ignore_suspend(v12 + 208, "HPHL");
  snd_soc_dapm_ignore_suspend(v12 + 208, "HPHR");
  snd_soc_dapm_ignore_suspend(v12 + 208, "AMIC1");
  snd_soc_dapm_ignore_suspend(v12 + 208, "AMIC2");
  snd_soc_dapm_ignore_suspend(v12 + 208, "AMIC3");
  snd_soc_dapm_ignore_suspend(v12 + 208, "AMIC4");
  snd_soc_dapm_sync(v12 + 208);
  v15 = *(_QWORD *)(*(_QWORD *)(v12 + 32) + 784LL);
  if ( !*(_QWORD *)v15 )
  {
    v17 = snd_info_create_module_entry(*(_QWORD *)(v14 + 392), "codecs", *(_QWORD *)(v14 + 608));
    if ( v17 )
    {
      v18 = v17;
      *(_WORD *)(v17 + 8) = 16749;
      if ( (snd_info_register() & 0x80000000) == 0 )
      {
        *(_QWORD *)v15 = v18;
        goto LABEL_15;
      }
      v19 = v18;
LABEL_31:
      snd_info_free_entry(v19);
      return 0;
    }
    return 0;
  }
LABEL_15:
  if ( *(_DWORD *)(v15 + 148) == 2 )
  {
    wcd9378_info_create_codec_entry();
  }
  else
  {
    wcd939x_info_create_codec_entry();
    if ( (unsigned int)wcd939x_get_codec_variant(v12) == 5 )
    {
      v16 = 1;
      goto LABEL_20;
    }
  }
  v16 = 0;
LABEL_20:
  v10 = lpass_cdc_rx_set_fir_capability(v5, v16);
  if ( (v10 & 0x80000000) == 0 )
    goto LABEL_21;
  if ( (unsigned int)__ratelimit(&msm_rx_tx_codec_init__rs, "msm_rx_tx_codec_init") )
    dev_err(*(_QWORD *)(v12 + 24), "%s: set fir capability failed: %d\n", "msm_rx_tx_codec_init", v10);
  return v10;
}
