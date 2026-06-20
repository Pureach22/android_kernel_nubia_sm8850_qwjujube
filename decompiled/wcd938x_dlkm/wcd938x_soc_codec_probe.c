__int64 __fastcall wcd938x_soc_codec_probe(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x1
  __int64 v4; // x0
  unsigned int hwdep; // w0
  unsigned int v6; // w0
  int v7; // w8
  __int64 result; // x0
  __int64 (__fastcall *v9)(__int64, __int64, __int64); // x8
  __int64 v10; // x0
  __int64 v11; // x8
  unsigned int v12; // w19
  unsigned int v13; // w21
  unsigned __int64 v20; // x9

  dev_info(*(_QWORD *)(a1 + 24), "%s()\n", "wcd938x_soc_codec_probe");
  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL);
  if ( !v2 )
    return 4294967274LL;
  v3 = *(_QWORD *)(v2 + 32);
  *(_QWORD *)(v2 + 16) = a1;
  snd_soc_component_init_regmap(a1, v3);
  devm_regmap_qti_debugfs_register(*(_QWORD *)(v2 + 48) + 72LL, *(_QWORD *)(v2 + 32));
  *(_DWORD *)(v2 + 8) = ((unsigned int)snd_soc_component_read(a1, 13488) >> 1) & 0xF;
  v4 = devm_kmalloc(*(_QWORD *)(a1 + 24), 120, 3520);
  *(_QWORD *)(v2 + 88) = v4;
  if ( !v4 )
  {
    dev_err(*(_QWORD *)(a1 + 24), "Failed to allocate fw_data\n");
    return 4294967284LL;
  }
  _X8 = (unsigned __int64 *)(v4 + 32);
  __asm { PRFM            #0x11, [X8] }
  do
    v20 = __ldxr(_X8);
  while ( __stxr(v20 | 4, _X8) );
  hwdep = wcd_cal_create_hwdep(*(_QWORD *)(v2 + 88), 1000, a1);
  if ( (hwdep & 0x80000000) != 0 )
  {
    v13 = hwdep;
    dev_err(*(_QWORD *)(a1 + 24), "%s hwdep failed %d\n", "wcd938x_soc_codec_probe");
LABEL_22:
    *(_QWORD *)(v2 + 88) = 0;
    return v13;
  }
  v6 = wcd938x_mbhc_init(v2 + 256, a1, *(_QWORD *)(v2 + 88));
  if ( v6 )
  {
    v13 = v6;
    printk(&unk_13F07, "wcd938x_soc_codec_probe");
    goto LABEL_22;
  }
  snd_soc_dapm_ignore_suspend(a1 + 208, "WCD938X_AIF Playback");
  snd_soc_dapm_ignore_suspend(a1 + 208, "WCD938X_AIF Capture");
  snd_soc_dapm_ignore_suspend(a1 + 208, "AMIC1");
  snd_soc_dapm_ignore_suspend(a1 + 208, "AMIC2");
  snd_soc_dapm_ignore_suspend(a1 + 208, "AMIC3");
  snd_soc_dapm_ignore_suspend(a1 + 208, "AMIC4");
  snd_soc_dapm_ignore_suspend(a1 + 208, "AMIC5");
  snd_soc_dapm_ignore_suspend(a1 + 208, "AMIC6");
  snd_soc_dapm_ignore_suspend(a1 + 208, "AMIC7");
  snd_soc_dapm_ignore_suspend(a1 + 208, "VA AMIC1");
  snd_soc_dapm_ignore_suspend(a1 + 208, "VA AMIC2");
  snd_soc_dapm_ignore_suspend(a1 + 208, "VA AMIC3");
  snd_soc_dapm_ignore_suspend(a1 + 208, "VA AMIC4");
  snd_soc_dapm_ignore_suspend(a1 + 208, "VA AMIC5");
  snd_soc_dapm_ignore_suspend(a1 + 208, "VA AMIC6");
  snd_soc_dapm_ignore_suspend(a1 + 208, "VA AMIC7");
  snd_soc_dapm_ignore_suspend(a1 + 208, "WCD_TX_OUTPUT");
  snd_soc_dapm_ignore_suspend(a1 + 208, "IN1_HPHL");
  snd_soc_dapm_ignore_suspend(a1 + 208, "IN2_HPHR");
  snd_soc_dapm_ignore_suspend(a1 + 208, "IN3_AUX");
  snd_soc_dapm_ignore_suspend(a1 + 208, "EAR");
  snd_soc_dapm_ignore_suspend(a1 + 208, "AUX");
  snd_soc_dapm_ignore_suspend(a1 + 208, "HPHL");
  snd_soc_dapm_ignore_suspend(a1 + 208, "HPHR");
  snd_soc_dapm_ignore_suspend(a1 + 208, "WCD_TX_DUMMY");
  snd_soc_dapm_ignore_suspend(a1 + 208, "WCD_RX_DUMMY");
  snd_soc_dapm_sync(a1 + 208);
  wcd_cls_h_init(v2 + 224);
  wcd938x_init_reg(a1);
  v7 = *(_DWORD *)(v2 + 8);
  if ( !v7 )
  {
    result = snd_soc_add_component_controls(a1, &wcd9380_snd_controls, 6);
    if ( (result & 0x80000000) != 0 )
    {
LABEL_21:
      v13 = result;
      dev_err(*(_QWORD *)(a1 + 24), "%s: Failed to add snd ctrls for variant: %d\n", "wcd938x_soc_codec_probe");
      goto LABEL_22;
    }
    if ( *(_DWORD *)(v2 + 8) != 5 )
      goto LABEL_13;
LABEL_12:
    result = snd_soc_add_component_controls(a1, &wcd9385_snd_controls, 6);
    if ( (result & 0x80000000) == 0 )
      goto LABEL_13;
    goto LABEL_21;
  }
  result = 0;
  if ( v7 == 5 )
    goto LABEL_12;
LABEL_13:
  v9 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v2 + 3136);
  *(_DWORD *)(v2 + 3152) = 1;
  *(_QWORD *)(v2 + 3096) = wcd938x_event_notify;
  if ( v9 )
  {
    v10 = *(_QWORD *)(v2 + 3120);
    if ( *((_DWORD *)v9 - 1) != -875060373 )
      __break(0x8228u);
    result = v9(v10, v2 + 3096, 1);
    if ( (_DWORD)result )
    {
      v11 = *(_QWORD *)(a1 + 24);
      v12 = result;
      dev_err(v11, "%s: Failed to register notifier %d\n", "wcd938x_soc_codec_probe", result);
      return v12;
    }
  }
  return result;
}
