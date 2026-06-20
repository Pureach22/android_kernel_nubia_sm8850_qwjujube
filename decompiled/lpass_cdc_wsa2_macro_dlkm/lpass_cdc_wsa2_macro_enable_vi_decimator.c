__int64 __fastcall lpass_cdc_wsa2_macro_enable_vi_decimator(__int64 a1)
{
  __int64 device_ptr; // x0
  __int64 v3; // x21
  __int64 result; // x0
  int v5; // w8
  unsigned int v6; // w20

  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(a1 + 24), 4);
  if ( device_ptr )
  {
    v3 = *(_QWORD *)(device_ptr + 152);
    if ( v3 && *(_QWORD *)(v3 + 248) )
    {
      result = usleep_range_state(5000, 5500, 2);
      v5 = *(_DWORD *)(v3 + 508);
      if ( v5 > 47999 )
      {
        if ( v5 != 96000 )
        {
          if ( v5 == 48000 )
          {
            v6 = 4;
            if ( (*(_QWORD *)(v3 + 296) & 1) == 0 )
              goto LABEL_24;
            goto LABEL_23;
          }
          goto LABEL_18;
        }
        v6 = 5;
        if ( (*(_QWORD *)(v3 + 296) & 1) == 0 )
        {
LABEL_24:
          if ( (*(_QWORD *)(v3 + 296) & 2) != 0 )
          {
            snd_soc_component_update_bits(a1, 17028, 32, 32);
            snd_soc_component_update_bits(a1, 17060, 32, 32);
            snd_soc_component_update_bits(a1, 17028, 15, v6);
            snd_soc_component_update_bits(a1, 17060, 15, v6);
            snd_soc_component_update_bits(a1, 17028, 16, 16);
            snd_soc_component_update_bits(a1, 17060, 16, 16);
            snd_soc_component_update_bits(a1, 17028, 32, 0);
            result = snd_soc_component_update_bits(a1, 17060, 32, 0);
          }
          if ( *(_BYTE *)(v3 + 665) == 1 && *(_DWORD *)(v3 + 508) == 48000 )
            return snd_soc_component_update_bits(a1, 16516, 7, 7);
          return result;
        }
      }
      else
      {
        if ( v5 != 16000 )
        {
          if ( v5 == 32000 )
          {
            v6 = 3;
            if ( (*(_QWORD *)(v3 + 296) & 1) == 0 )
              goto LABEL_24;
            goto LABEL_23;
          }
LABEL_18:
          v6 = 0;
          if ( (*(_QWORD *)(v3 + 296) & 1) == 0 )
            goto LABEL_24;
          goto LABEL_23;
        }
        v6 = 1;
        if ( (*(_QWORD *)(v3 + 296) & 1) == 0 )
          goto LABEL_24;
      }
LABEL_23:
      snd_soc_component_update_bits(a1, 16964, 32, 32);
      snd_soc_component_update_bits(a1, 16996, 32, 32);
      snd_soc_component_update_bits(a1, 16964, 15, v6);
      snd_soc_component_update_bits(a1, 16996, 15, v6);
      snd_soc_component_update_bits(a1, 16964, 16, 16);
      snd_soc_component_update_bits(a1, 16996, 16, 16);
      snd_soc_component_update_bits(a1, 16964, 32, 0);
      result = snd_soc_component_update_bits(a1, 16996, 32, 0);
      goto LABEL_24;
    }
    result = __ratelimit(&lpass_cdc_wsa2_macro_get_data__rs_120, "lpass_cdc_wsa2_macro_get_data");
    if ( (_DWORD)result )
      return dev_err(*(_QWORD *)(a1 + 24), "%s: priv is null for macro!\n", "lpass_cdc_wsa2_macro_enable_vi_decimator");
  }
  else
  {
    result = __ratelimit(&lpass_cdc_wsa2_macro_get_data__rs, "lpass_cdc_wsa2_macro_get_data");
    if ( (_DWORD)result )
      return dev_err(*(_QWORD *)(a1 + 24), "%s: null device for macro!\n", "lpass_cdc_wsa2_macro_enable_vi_decimator");
  }
  return result;
}
