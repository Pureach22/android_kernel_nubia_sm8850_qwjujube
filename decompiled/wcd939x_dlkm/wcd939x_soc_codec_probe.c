__int64 __fastcall wcd939x_soc_codec_probe(__int64 a1)
{
  __int64 *v2; // x19
  __int64 v3; // x1
  __int64 v4; // x0
  __int64 v5; // x9
  __int64 v6; // x0
  unsigned int hwdep; // w0
  unsigned int v8; // w0
  int v9; // w8
  __int64 result; // x0
  __int64 (__fastcall *v11)(__int64, __int64 *, __int64); // x8
  __int64 v12; // x0
  unsigned int v13; // w19
  unsigned int v14; // w21
  unsigned __int64 v21; // x9

  dev_info(*(_QWORD *)(a1 + 24), "%s()\n", "wcd939x_soc_codec_probe");
  v2 = *(__int64 **)(*(_QWORD *)(a1 + 24) + 152LL);
  if ( !v2 )
    return 4294967274LL;
  v3 = v2[4];
  v2[2] = a1;
  snd_soc_component_init_regmap(a1, v3);
  devm_regmap_qti_debugfs_register(v2[6] + 72, v2[4]);
  v4 = proc_mkdir("wcd939x_reginfo", 0);
  v2[414] = v4;
  if ( v4 )
  {
    if ( !proc_create_data("wcd939x_regdump", 292, v4, &wcd939x_proc_ops, v2) )
    {
      dev_err(*(_QWORD *)(a1 + 24), "%s: error creating proc reg read interface\n", "wcd939x_soc_codec_probe");
      proc_remove(v2[414]);
      v2[414] = 0;
    }
  }
  else
  {
    dev_err(*(_QWORD *)(a1 + 24), "%s: error creating proc dir interface\n", "wcd939x_soc_codec_probe");
  }
  v5 = *v2;
  *((_DWORD *)v2 + 2) = 5;
  *((_BYTE *)v2 + 313) = of_find_property(*(_QWORD *)(v5 + 744), "qcom,hph-2p15v-mode", 0) != 0;
  v6 = devm_kmalloc(*(_QWORD *)(a1 + 24), 120, 3520);
  v2[11] = v6;
  if ( !v6 )
  {
    dev_err(*(_QWORD *)(a1 + 24), "Failed to allocate fw_data\n");
    return 4294967284LL;
  }
  _X8 = (unsigned __int64 *)(v6 + 32);
  __asm { PRFM            #0x11, [X8] }
  do
    v21 = __ldxr(_X8);
  while ( __stxr(v21 | 4, _X8) );
  hwdep = wcd_cal_create_hwdep(v2[11], 1000, a1);
  if ( (hwdep & 0x80000000) != 0 )
  {
    v14 = hwdep;
    dev_err(*(_QWORD *)(a1 + 24), "%s hwdep failed %d\n", "wcd939x_soc_codec_probe");
LABEL_26:
    v2[11] = 0;
    return v14;
  }
  v8 = wcd939x_mbhc_init(v2 + 32, a1, v2[11]);
  if ( v8 )
  {
    v14 = v8;
    printk(&unk_1A7D6, "wcd939x_soc_codec_probe");
    goto LABEL_26;
  }
  snd_soc_dapm_ignore_suspend(a1 + 208, "WCD939X_AIF Playback");
  snd_soc_dapm_ignore_suspend(a1 + 208, "WCD939X_AIF Capture");
  snd_soc_dapm_ignore_suspend(a1 + 208, "AMIC1");
  snd_soc_dapm_ignore_suspend(a1 + 208, "AMIC2");
  snd_soc_dapm_ignore_suspend(a1 + 208, "AMIC3");
  snd_soc_dapm_ignore_suspend(a1 + 208, "AMIC4");
  snd_soc_dapm_ignore_suspend(a1 + 208, "AMIC5");
  snd_soc_dapm_ignore_suspend(a1 + 208, "VA AMIC1");
  snd_soc_dapm_ignore_suspend(a1 + 208, "VA AMIC2");
  snd_soc_dapm_ignore_suspend(a1 + 208, "VA AMIC3");
  snd_soc_dapm_ignore_suspend(a1 + 208, "VA AMIC4");
  snd_soc_dapm_ignore_suspend(a1 + 208, "VA AMIC5");
  snd_soc_dapm_ignore_suspend(a1 + 208, "WCD_TX_OUTPUT");
  snd_soc_dapm_ignore_suspend(a1 + 208, "IN1_HPHL");
  snd_soc_dapm_ignore_suspend(a1 + 208, "IN2_HPHR");
  snd_soc_dapm_ignore_suspend(a1 + 208, "IN3_EAR");
  snd_soc_dapm_ignore_suspend(a1 + 208, "EAR");
  snd_soc_dapm_ignore_suspend(a1 + 208, "HPHL");
  snd_soc_dapm_ignore_suspend(a1 + 208, "HPHR");
  snd_soc_dapm_ignore_suspend(a1 + 208, "WCD_TX_DUMMY");
  snd_soc_dapm_ignore_suspend(a1 + 208, "WCD_RX_DUMMY");
  snd_soc_dapm_sync(a1 + 208);
  wcd_cls_h_init(v2 + 28);
  wcd939x_init_reg(a1);
  v9 = *((_DWORD *)v2 + 2);
  if ( !v9 )
  {
    result = snd_soc_add_component_controls(a1, &wcd9390_snd_controls, 6);
    if ( (result & 0x80000000) != 0 )
    {
LABEL_25:
      v14 = result;
      dev_err(*(_QWORD *)(a1 + 24), "%s: Failed to add snd ctrls for variant: %d\n", "wcd939x_soc_codec_probe");
      goto LABEL_26;
    }
    if ( *((_DWORD *)v2 + 2) != 5 )
      goto LABEL_16;
LABEL_15:
    result = snd_soc_add_component_controls(a1, &wcd9395_snd_controls, 5);
    if ( (result & 0x80000000) == 0 )
      goto LABEL_16;
    goto LABEL_25;
  }
  result = 0;
  if ( v9 == 5 )
    goto LABEL_15;
LABEL_16:
  v11 = (__int64 (__fastcall *)(__int64, __int64 *, __int64))v2[395];
  v2[390] = (__int64)wcd939x_event_notify;
  if ( v11 )
  {
    v12 = v2[393];
    if ( *((_DWORD *)v11 - 1) != -875060373 )
      __break(0x8228u);
    result = v11(v12, v2 + 390, 1);
    if ( (_DWORD)result )
    {
      v13 = result;
      dev_err(*(_QWORD *)(a1 + 24), "%s: Failed to register notifier %d\n", "wcd939x_soc_codec_probe", result);
      return v13;
    }
  }
  return result;
}
