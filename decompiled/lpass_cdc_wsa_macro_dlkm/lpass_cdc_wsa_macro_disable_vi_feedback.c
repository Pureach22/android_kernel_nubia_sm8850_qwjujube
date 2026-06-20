__int64 __fastcall lpass_cdc_wsa_macro_disable_vi_feedback(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x21
  __int64 device_ptr; // x0
  __int64 v6; // x20

  v3 = *(_QWORD *)(a1 + 40);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v3 - 184), 2);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs, "lpass_cdc_wsa_macro_get_data") )
      dev_err(*(_QWORD *)(v3 - 184), "%s: null device for macro!\n", "lpass_cdc_wsa_macro_disable_vi_feedback");
    return 4294967274LL;
  }
  v6 = *(_QWORD *)(device_ptr + 152);
  if ( !v6 || !*(_QWORD *)(v6 + 360) )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs_122, "lpass_cdc_wsa_macro_get_data") )
      dev_err(*(_QWORD *)(v3 - 184), "%s: priv is null for macro!\n", "lpass_cdc_wsa_macro_disable_vi_feedback");
    return 4294967274LL;
  }
  if ( a3 == 8 )
  {
    if ( (*(_QWORD *)(v6 + 400) & 1) != 0 )
    {
      snd_soc_component_update_bits(v3 - 208, 8772, 32, 32);
      snd_soc_component_update_bits(v3 - 208, 8804, 32, 32);
      snd_soc_component_update_bits(v3 - 208, 8772, 16, 0);
      snd_soc_component_update_bits(v3 - 208, 8804, 16, 0);
      snd_soc_component_update_bits(v3 - 208, 8772, 32, 0);
      snd_soc_component_update_bits(v3 - 208, 8804, 32, 0);
    }
    if ( (*(_QWORD *)(v6 + 400) & 2) != 0 )
    {
      snd_soc_component_update_bits(v3 - 208, 8836, 32, 32);
      snd_soc_component_update_bits(v3 - 208, 8868, 32, 32);
      snd_soc_component_update_bits(v3 - 208, 8836, 16, 0);
      snd_soc_component_update_bits(v3 - 208, 8868, 16, 0);
      snd_soc_component_update_bits(v3 - 208, 8836, 32, 0);
      snd_soc_component_update_bits(v3 - 208, 8868, 32, 0);
    }
  }
  return 0;
}
