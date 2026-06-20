__int64 __fastcall lpass_cdc_wsa2_macro_update_vi_feedback(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x19
  __int64 device_ptr; // x0
  __int64 v6; // x21
  __int64 v7; // x19

  v3 = *(_QWORD *)(a1 + 40);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v3 - 184), 4);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_get_data__rs, "lpass_cdc_wsa2_macro_get_data") )
      dev_err(*(_QWORD *)(v3 - 184), "%s: null device for macro!\n", "lpass_cdc_wsa2_macro_update_vi_feedback");
    return 4294967274LL;
  }
  v6 = *(_QWORD *)(device_ptr + 152);
  if ( !v6 || !*(_QWORD *)(v6 + 248) )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_get_data__rs_120, "lpass_cdc_wsa2_macro_get_data") )
      dev_err(*(_QWORD *)(v3 - 184), "%s: priv is null for macro!\n", "lpass_cdc_wsa2_macro_update_vi_feedback");
    return 4294967274LL;
  }
  v7 = v3 - 208;
  if ( a3 != 8 )
  {
    if ( a3 == 1 && *(_BYTE *)(v6 + 665) == 1 )
    {
      lpass_cdc_wsa2_macro_enable_vi_decimator(v7);
      return 0;
    }
    return 0;
  }
  if ( (*(_QWORD *)(v6 + 296) & 1) != 0 )
  {
    snd_soc_component_update_bits(v7, 16964, 32, 32);
    snd_soc_component_update_bits(v7, 16996, 32, 32);
    snd_soc_component_update_bits(v7, 16964, 16, 0);
    snd_soc_component_update_bits(v7, 16996, 16, 0);
    snd_soc_component_update_bits(v7, 16964, 32, 0);
    snd_soc_component_update_bits(v7, 16996, 32, 0);
  }
  if ( (*(_QWORD *)(v6 + 296) & 2) == 0 )
    return 0;
  snd_soc_component_update_bits(v7, 17028, 32, 32);
  snd_soc_component_update_bits(v7, 17060, 32, 32);
  snd_soc_component_update_bits(v7, 17028, 16, 0);
  snd_soc_component_update_bits(v7, 17060, 16, 0);
  snd_soc_component_update_bits(v7, 17028, 32, 0);
  snd_soc_component_update_bits(v7, 17060, 32, 0);
  if ( *(_BYTE *)(v6 + 665) == 1 && *(_DWORD *)(v6 + 508) == 48000 )
  {
    snd_soc_component_update_bits(v7, 16516, 3, 3);
    if ( (*(_BYTE *)(v6 + 665) & 1) == 0 )
      return 0;
  }
  else if ( !*(_BYTE *)(v6 + 665) )
  {
    return 0;
  }
  *(_BYTE *)(v6 + 665) = 0;
  return 0;
}
