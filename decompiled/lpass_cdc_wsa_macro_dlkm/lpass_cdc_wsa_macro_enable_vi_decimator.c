__int64 __fastcall lpass_cdc_wsa_macro_enable_vi_decimator(__int64 a1)
{
  __int64 v1; // x21
  __int64 v2; // x19
  __int64 device_ptr; // x0
  __int64 result; // x0
  int v5; // w8
  unsigned int v6; // w20

  v1 = *(_QWORD *)(a1 - 8);
  v2 = *(_QWORD *)(v1 + 360);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v2 + 24), 2);
  if ( device_ptr )
  {
    v1 = *(_QWORD *)(device_ptr + 152);
    if ( (!v1 || !*(_QWORD *)(v1 + 360))
      && (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs_122, "lpass_cdc_wsa_macro_get_data") )
    {
      dev_err(*(_QWORD *)(v2 + 24), "%s: priv is null for macro!\n", "lpass_cdc_wsa_macro_enable_vi_decimator");
    }
  }
  else if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs, "lpass_cdc_wsa_macro_get_data") )
  {
    dev_err(*(_QWORD *)(v2 + 24), "%s: null device for macro!\n", "lpass_cdc_wsa_macro_enable_vi_decimator");
  }
  result = usleep_range_state(5000, 5500, 2);
  v5 = *(_DWORD *)(v1 + 636);
  if ( v5 <= 47999 )
  {
    if ( v5 == 16000 )
    {
      v6 = 1;
      if ( (*(_QWORD *)(v1 + 400) & 1) != 0 )
        goto LABEL_21;
      goto LABEL_22;
    }
    if ( v5 == 32000 )
    {
      v6 = 3;
      if ( (*(_QWORD *)(v1 + 400) & 1) == 0 )
        goto LABEL_22;
LABEL_21:
      snd_soc_component_update_bits(v2, 8772, 32, 32);
      snd_soc_component_update_bits(v2, 8804, 32, 32);
      usleep_range_state(1000, 1500, 2);
      snd_soc_component_update_bits(v2, 8772, 15, v6);
      snd_soc_component_update_bits(v2, 8804, 15, v6);
      snd_soc_component_update_bits(v2, 8772, 16, 16);
      snd_soc_component_update_bits(v2, 8804, 16, 16);
      usleep_range_state(1000, 1500, 2);
      snd_soc_component_update_bits(v2, 8772, 32, 0);
      result = snd_soc_component_update_bits(v2, 8804, 32, 0);
      goto LABEL_22;
    }
    goto LABEL_16;
  }
  if ( v5 == 96000 )
  {
    v6 = 5;
    if ( (*(_QWORD *)(v1 + 400) & 1) == 0 )
      goto LABEL_22;
    goto LABEL_21;
  }
  if ( v5 != 48000 )
  {
LABEL_16:
    v6 = 0;
    if ( (*(_QWORD *)(v1 + 400) & 1) != 0 )
      goto LABEL_21;
    goto LABEL_22;
  }
  v6 = 4;
  if ( (*(_QWORD *)(v1 + 400) & 1) != 0 )
    goto LABEL_21;
LABEL_22:
  if ( (*(_QWORD *)(v1 + 400) & 2) != 0 )
  {
    snd_soc_component_update_bits(v2, 8836, 32, 32);
    snd_soc_component_update_bits(v2, 8868, 32, 32);
    usleep_range_state(1000, 1500, 2);
    snd_soc_component_update_bits(v2, 8836, 15, v6);
    snd_soc_component_update_bits(v2, 8868, 15, v6);
    snd_soc_component_update_bits(v2, 8836, 16, 16);
    snd_soc_component_update_bits(v2, 8868, 16, 16);
    usleep_range_state(1000, 1500, 2);
    snd_soc_component_update_bits(v2, 8836, 32, 0);
    return snd_soc_component_update_bits(v2, 8868, 32, 0);
  }
  return result;
}
