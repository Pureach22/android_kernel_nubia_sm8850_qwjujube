__int64 __fastcall lpass_cdc_rx_macro_init(__int64 a1)
{
  __int64 device_ptr; // x0
  __int64 v3; // x21
  __int64 v4; // x20
  unsigned int v5; // w0
  const char *v7; // x1
  unsigned int v8; // w19

  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(a1 + 24), 1);
  if ( !device_ptr )
  {
    dev_err(*(_QWORD *)(a1 + 24), "%s: null device for macro!\n", "lpass_cdc_rx_macro_init");
    return 4294967274LL;
  }
  v3 = *(_QWORD *)(device_ptr + 152);
  v4 = device_ptr;
  if ( !v3 )
  {
    dev_err(*(_QWORD *)(a1 + 24), "%s: priv is null for macro!\n", "lpass_cdc_rx_macro_init");
    return 4294967274LL;
  }
  v5 = snd_soc_dapm_new_controls(a1 + 208, &lpass_cdc_rx_macro_dapm_widgets, 76);
  if ( (v5 & 0x80000000) != 0 )
  {
    v7 = "%s: failed to add controls\n";
  }
  else
  {
    v5 = snd_soc_dapm_add_routes(a1 + 208, &rx_audio_map, 292);
    if ( (v5 & 0x80000000) != 0 )
    {
      v7 = "%s: failed to add routes\n";
    }
    else
    {
      v5 = snd_soc_dapm_new_widgets(*(_QWORD *)(a1 + 232));
      if ( (v5 & 0x80000000) != 0 )
      {
        v7 = "%s: failed to add widgets\n";
      }
      else
      {
        v5 = snd_soc_add_component_controls(a1, &lpass_cdc_rx_macro_snd_controls, 51);
        if ( (v5 & 0x80000000) == 0 )
        {
          *(_BYTE *)(v3 + 94) = 1;
          *(_WORD *)(v3 + 2352) = 0;
          snd_soc_dapm_ignore_suspend(a1 + 208, "RX_MACRO_AIF1 Playback");
          snd_soc_dapm_ignore_suspend(a1 + 208, "RX_MACRO_AIF2 Playback");
          snd_soc_dapm_ignore_suspend(a1 + 208, "RX_MACRO_AIF3 Playback");
          snd_soc_dapm_ignore_suspend(a1 + 208, "RX_MACRO_AIF4 Playback");
          snd_soc_dapm_ignore_suspend(a1 + 208, "RX_MACRO_AIF5 Playback");
          snd_soc_dapm_ignore_suspend(a1 + 208, "RX_MACRO_AIF6 Playback");
          snd_soc_dapm_ignore_suspend(a1 + 208, "HPHL_OUT");
          snd_soc_dapm_ignore_suspend(a1 + 208, "HPHR_OUT");
          snd_soc_dapm_ignore_suspend(a1 + 208, "AUX_OUT");
          snd_soc_dapm_ignore_suspend(a1 + 208, "PCM_OUT");
          snd_soc_dapm_ignore_suspend(a1 + 208, "RX_TX DEC0_INP");
          snd_soc_dapm_ignore_suspend(a1 + 208, "RX_TX DEC1_INP");
          snd_soc_dapm_ignore_suspend(a1 + 208, "RX_TX DEC2_INP");
          snd_soc_dapm_ignore_suspend(a1 + 208, "RX_TX DEC3_INP");
          snd_soc_dapm_sync(a1 + 208);
          snd_soc_component_update_bits(a1, 5172, 7, 2);
          snd_soc_component_update_bits(a1, 5364, 7, 2);
          snd_soc_component_update_bits(a1, 5568, 7, 2);
          snd_soc_component_update_bits(a1, 5136, 3, 2);
          snd_soc_component_update_bits(a1, 5328, 3, 2);
          snd_soc_component_update_bits(a1, 5520, 3, 2);
          *(_QWORD *)(v3 + 304) = a1;
          return 0;
        }
        v7 = "%s: failed to add snd_ctls\n";
      }
    }
  }
  v8 = v5;
  dev_err(v4, v7, "lpass_cdc_rx_macro_init");
  return v8;
}
