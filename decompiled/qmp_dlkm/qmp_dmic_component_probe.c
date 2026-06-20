__int64 __fastcall qmp_dmic_component_probe(__int64 a1)
{
  _QWORD *v1; // x20

  v1 = *(_QWORD **)(*(_QWORD *)(a1 + 24) + 152LL);
  if ( !v1 )
    return 4294967274LL;
  v1[3] = a1;
  snd_soc_component_init_regmap();
  devm_regmap_qti_debugfs_register(v1[1], *v1);
  snd_soc_dapm_ignore_suspend(a1 + 208, *(_QWORD *)(v1[5] + 104LL));
  snd_soc_dapm_ignore_suspend(a1 + 208, *(_QWORD *)(v1[5] + 312LL));
  snd_soc_dapm_ignore_suspend(a1 + 208, *(_QWORD *)(v1[5] + 520LL));
  snd_soc_dapm_ignore_suspend(a1 + 208, "QMP_DMIC VA Function1");
  snd_soc_dapm_ignore_suspend(a1 + 208, "QMP_DMIC Function1");
  snd_soc_dapm_ignore_suspend(a1 + 208, "QMP_DMIC Function2");
  snd_soc_dapm_ignore_suspend(a1 + 208, "NORMAL_OUTPUT");
  snd_soc_dapm_ignore_suspend(a1 + 208, "VA_NORMAL_OUTPUT");
  snd_soc_dapm_ignore_suspend(a1 + 208, "LP_OUTPUT");
  snd_soc_dapm_ignore_suspend(a1 + 208, "QMP Digital Mic");
  snd_soc_dapm_ignore_suspend(a1 + 208, "QMP VA Digital Mic");
  snd_soc_dapm_sync(a1 + 208);
  return 0;
}
