__int64 __fastcall haptics_comp_probe(__int64 a1)
{
  if ( *(_QWORD *)(*(_QWORD *)(a1 + 24) + 152LL) )
  {
    snd_soc_component_init_regmap();
    if ( *(_QWORD *)(a1 + 224) )
    {
      snd_soc_dapm_ignore_suspend(a1 + 208, "HAP_IN");
      snd_soc_dapm_ignore_suspend(a1 + 208, "HAP_OUT");
    }
    return 0;
  }
  else
  {
    printk(&unk_7BA0, "haptics_comp_probe");
    return 4294967274LL;
  }
}
