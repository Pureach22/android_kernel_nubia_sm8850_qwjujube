__int64 __fastcall lpass_cdc_rx_macro_config_compander(__int64 result, _BYTE *a2, __int64 a3, char a4)
{
  int v4; // w22
  unsigned __int16 v5; // w21
  unsigned __int16 v6; // w20
  unsigned int v7; // w9
  bool v8; // zf
  int v9; // w11
  _BOOL4 v10; // w12
  __int64 v11; // x2
  char v12; // w23
  __int64 v13; // x1
  unsigned int v14; // w25
  __int64 v15; // x19
  __int64 v16; // x19

  if ( (_DWORD)a3 != 2 )
  {
    if ( (unsigned int)a3 >= 2 )
    {
      __break(0x5512u);
      return lpass_cdc_rx_macro_config_softclip(result, a2, a3);
    }
    else if ( *(_DWORD *)&a2[4 * (unsigned int)a3 + 8] && !a2[16] )
    {
      v4 = 96 * a3;
      v5 = (192 * a3) | 0x1404;
      v6 = (96 * a3) | 0x1800;
      if ( (a4 & 3) != 0 )
      {
        v7 = (unsigned __int8)a2[96];
        v8 = (_DWORD)a3 == 0;
        v9 = (unsigned __int8)a2[87];
        v10 = a3 == 0;
        if ( (_DWORD)a3 )
          v11 = 4152;
        else
          v11 = 4132;
        v12 = a4;
        if ( v8 )
          v13 = 4128;
        else
          v13 = 4148;
        if ( (v10 & v9) != 0 )
          v14 = 2;
        else
          v14 = v7;
        v15 = result;
        lpass_cdc_load_compander_coeff(result, v13, v11, &comp_coeff_table[25 * v7], 25);
        lpass_cdc_update_compander_setting(v15, (unsigned int)(v4 + 6176), (char *)&comp_setting_table + 12 * v14);
        snd_soc_component_update_bits(v15, v6, 1, 1);
        snd_soc_component_update_bits(v15, v6, 2, 2);
        snd_soc_component_update_bits(v15, v6, 2, 0);
        snd_soc_component_update_bits(v15, v5, 2, 2);
        a4 = v12;
        result = v15;
      }
      if ( (a4 & 0xC) != 0 )
      {
        v16 = result;
        snd_soc_component_update_bits(result, v6, 4, 4);
        snd_soc_component_update_bits(v16, v5, 2, 0);
        snd_soc_component_update_bits(v16, v6, 1, 0);
        return snd_soc_component_update_bits(v16, v6, 4, 0);
      }
    }
  }
  return result;
}
