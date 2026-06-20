__int64 __fastcall lpass_cdc_was_macro_config_pbr(__int64 a1, unsigned int a2, char a3)
{
  __int64 result; // x0
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x3
  __int64 v10; // x20
  char v11; // w8
  unsigned int v12; // w21
  unsigned int v13; // w23
  unsigned int v14; // w24
  unsigned int v15; // w25
  char v16; // w8
  int v17; // w8

  result = lpass_cdc_get_device_ptr(*(_QWORD *)(a1 + 24), 4);
  if ( result )
  {
    v10 = *(_QWORD *)(result + 152);
    if ( v10 && *(_QWORD *)(v10 + 248) )
    {
      if ( a2 )
      {
        if ( a2 == 1 )
        {
          v11 = 1;
          v12 = 17544;
          v13 = 17552;
          v14 = 17888;
          v15 = 1;
        }
        else
        {
          v11 = 0;
          v14 = 0;
          v13 = 0;
          v12 = 0;
          v15 = 0;
        }
      }
      else
      {
        v12 = 17416;
        v13 = 17424;
        v14 = 17792;
        v11 = 1;
        v15 = 0;
      }
      if ( *(_BYTE *)(v10 + 600) == 1 )
      {
        if ( a2 >= 2 )
        {
          __break(0x5512u);
          return lpass_cdc_wsa2_macro_enable_softclip_clk(result, v7, v8, v9);
        }
        else if ( *(_DWORD *)(v10 + 4LL * a2 + 620) <= 3u && *(_DWORD *)(v10 + 8LL * a2 + 604) <= 6u )
        {
          v16 = v11 ^ 1;
          if ( *(_DWORD *)(v10 + 468) )
            v16 = 1;
          if ( (v16 & 1) == 0 )
          {
            if ( (a3 & 3) != 0 )
            {
              snd_soc_component_update_bits(a1, v14, 8, 8);
              snd_soc_component_update_bits(a1, v13, 64, 64);
              snd_soc_component_update_bits(a1, v12, 128, 128);
              result = lpass_cdc_wsa2_macro_enable_softclip_clk(a1, v10, v15, 1);
              v17 = *(_DWORD *)(v10 + 652);
              if ( !v17 )
              {
                result = snd_soc_component_update_bits(a1, 19200, 1, 1);
                v17 = *(_DWORD *)(v10 + 652);
              }
              *(_DWORD *)(v10 + 652) = v17 + 1;
            }
            if ( (a3 & 0xC) != 0 )
            {
              if ( *(_DWORD *)(v10 + 652) )
                snd_soc_component_update_bits(a1, 19200, 1, 0);
              lpass_cdc_wsa2_macro_enable_softclip_clk(a1, v10, v15, 0);
              snd_soc_component_update_bits(a1, v14, 8, 0);
              snd_soc_component_update_bits(a1, v13, 64, 0);
              result = snd_soc_component_update_bits(a1, v12, 128, 0);
              *(_DWORD *)(v10 + 652) = (*(_DWORD *)(v10 + 652) - 1) & ~((*(_DWORD *)(v10 + 652) - 1) >> 31);
            }
          }
        }
      }
    }
    else
    {
      result = __ratelimit(&lpass_cdc_wsa2_macro_get_data__rs_120, "lpass_cdc_wsa2_macro_get_data");
      if ( (_DWORD)result )
        return dev_err(*(_QWORD *)(a1 + 24), "%s: priv is null for macro!\n", "lpass_cdc_was_macro_config_pbr");
    }
  }
  else
  {
    result = __ratelimit(&lpass_cdc_wsa2_macro_get_data__rs, "lpass_cdc_wsa2_macro_get_data");
    if ( (_DWORD)result )
      return dev_err(*(_QWORD *)(a1 + 24), "%s: null device for macro!\n", "lpass_cdc_was_macro_config_pbr");
  }
  return result;
}
