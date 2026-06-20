__int64 __fastcall lpass_cdc_wsa_macro_config_compander(__int64 a1, int a2, char a3)
{
  __int64 result; // x0
  __int64 v7; // x8
  __int64 v8; // x9
  unsigned int v9; // w10
  int *v10; // x2
  int v11; // w10
  unsigned int v12; // w3
  int v13; // w11
  int v14; // w8
  int v15; // w9
  unsigned __int16 v16; // w22
  int v17; // w8
  unsigned __int16 v18; // w21

  result = lpass_cdc_get_device_ptr(*(_QWORD *)(a1 + 24), 2);
  if ( result )
  {
    v7 = *(_QWORD *)(result + 152);
    if ( v7 && *(_QWORD *)(v7 + 360) )
    {
      if ( a2 >= 2 )
        return dev_err(
                 *(_QWORD *)(a1 + 24),
                 "%s: Invalid compander value: %d\n",
                 "lpass_cdc_wsa_macro_config_compander",
                 a2);
      if ( *(_DWORD *)(v7 + 4LL * (unsigned int)a2 + 8) )
      {
        v8 = v7 + 4LL * (unsigned int)a2;
        v9 = *(unsigned __int16 *)(v8 + 16);
        if ( v9 > 0x12 )
          v9 = 0;
        v10 = (int *)&comp_setting_table + 3 * v9;
        v11 = *(_DWORD *)(v8 + 748);
        if ( !v11 )
          goto LABEL_25;
        v12 = (unsigned __int16)(*(_WORD *)(v7 + 596) + 2 * a2);
        if ( v12 >= 4 )
          return dev_err(*(_QWORD *)(a1 + 24), "%s: Invalid index: %d\n", "lpass_cdc_wsa_macro_config_compander", v12);
        v13 = *(_DWORD *)(v7 + 4LL * (unsigned __int16)(*(_WORD *)(v7 + 596) + 2 * a2) + 732);
        v14 = 15;
        v15 = -15 * v13 + 210;
        if ( v11 > 3 )
        {
          if ( v11 == 6 )
            goto LABEL_24;
          if ( v11 != 4 )
          {
LABEL_23:
            v14 = 0;
            goto LABEL_24;
          }
        }
        else if ( v11 != 1 )
        {
          if ( v11 != 3 )
            goto LABEL_23;
LABEL_24:
          *v10 = 2 * v15 / 10;
          v10[1] = v14;
LABEL_25:
          v16 = ((_WORD)a2 << 7) + 9220;
          v17 = 96 * a2;
          v18 = 96 * a2 + 9600;
          if ( (a3 & 3) != 0 )
          {
            lpass_cdc_update_compander_setting(a1, (unsigned int)(v17 + 9632), v10);
            snd_soc_component_update_bits(a1, v18, 1, 1);
            snd_soc_component_update_bits(a1, v18, 2, 2);
            snd_soc_component_update_bits(a1, v18, 2, 0);
            result = snd_soc_component_update_bits(a1, v16, 2, 2);
          }
          if ( (a3 & 0xC) != 0 )
          {
            snd_soc_component_update_bits(a1, v18, 4, 4);
            snd_soc_component_update_bits(a1, v16, 2, 0);
            snd_soc_component_update_bits(a1, v18, 2, 2);
            snd_soc_component_update_bits(a1, v18, 2, 0);
            snd_soc_component_update_bits(a1, v18, 1, 0);
            return snd_soc_component_update_bits(a1, v18, 4, 0);
          }
          return result;
        }
        v15 = -15 * v13 + 270;
        v14 = 0;
        if ( v13 <= 5 )
          v15 = 210;
        goto LABEL_24;
      }
    }
    else
    {
      result = __ratelimit(&lpass_cdc_wsa_macro_get_data__rs_122, "lpass_cdc_wsa_macro_get_data");
      if ( (_DWORD)result )
        return dev_err(*(_QWORD *)(a1 + 24), "%s: priv is null for macro!\n", "lpass_cdc_wsa_macro_config_compander");
    }
  }
  else
  {
    result = __ratelimit(&lpass_cdc_wsa_macro_get_data__rs, "lpass_cdc_wsa_macro_get_data");
    if ( (_DWORD)result )
      return dev_err(*(_QWORD *)(a1 + 24), "%s: null device for macro!\n", "lpass_cdc_wsa_macro_config_compander");
  }
  return result;
}
