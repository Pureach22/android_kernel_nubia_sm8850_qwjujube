__int64 __fastcall lpass_cdc_rx_macro_hphdelay_lutbypass(__int64 result, __int64 a2, __int16 a3, char a4)
{
  char v4; // w22
  __int64 v5; // x21
  __int64 v6; // x23
  unsigned int v7; // w20
  unsigned int v8; // w19
  __int64 v9; // x21

  if ( !*(_BYTE *)(a2 + 16) )
  {
    if ( a3 == 1 )
    {
      if ( (a4 & 3) != 0 )
      {
        v5 = a2;
        v4 = a4;
        v6 = result;
        v8 = 4156;
        snd_soc_component_update_bits(result, 4156, 128, 128);
        v7 = 6268;
LABEL_13:
        if ( *(_BYTE *)(v5 + 96) == 1 )
          snd_soc_component_update_bits(v6, v7, 32, 0);
        result = v6;
        a4 = v4;
        goto LABEL_16;
      }
      v8 = 4156;
      v7 = 6268;
    }
    else
    {
      if ( a3 )
        return result;
      if ( (a4 & 3) != 0 )
      {
        v4 = a4;
        v5 = a2;
        v6 = result;
        if ( *(_BYTE *)(a2 + 87) == 1 )
        {
          snd_soc_component_update_bits(result, 5128, 2, 2);
          v7 = 6172;
          v8 = 4136;
        }
        else
        {
          v8 = 4136;
          snd_soc_component_update_bits(result, 4136, 128, 128);
          v7 = 6172;
        }
        goto LABEL_13;
      }
      v8 = 4136;
      v7 = 6172;
    }
LABEL_16:
    if ( (a4 & 0xC) != 0 )
    {
      v9 = result;
      snd_soc_component_update_bits(result, 5128, 2, 0);
      snd_soc_component_update_bits(v9, v8, 128, 0);
      return snd_soc_component_update_bits(v9, v7, 32, 32);
    }
  }
  return result;
}
