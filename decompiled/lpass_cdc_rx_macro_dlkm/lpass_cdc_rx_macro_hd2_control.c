__int64 __fastcall lpass_cdc_rx_macro_hd2_control(__int64 result, __int64 a2, __int16 a3, char a4)
{
  unsigned int v4; // w20
  unsigned int v5; // w19
  char v6; // w22
  __int64 v7; // x21
  __int64 v8; // x21

  if ( !*(_BYTE *)(a2 + 16) )
  {
    if ( a3 )
    {
      if ( a3 != 1 )
        return result;
      v4 = 5316;
      v5 = 5356;
      if ( (a4 & 3) == 0 )
        goto LABEL_7;
    }
    else
    {
      v4 = 5124;
      v5 = 5164;
      if ( (a4 & 3) == 0 )
      {
LABEL_7:
        if ( (a4 & 0xC) != 0 )
        {
          v8 = result;
          snd_soc_component_update_bits(result, v4, 4, 0);
          return snd_soc_component_update_bits(v8, v5, 60, 0);
        }
        return result;
      }
    }
    v6 = a4;
    v7 = result;
    snd_soc_component_update_bits(result, v5, 60, 20);
    snd_soc_component_update_bits(v7, v4, 4, 4);
    a4 = v6;
    result = v7;
    goto LABEL_7;
  }
  return result;
}
