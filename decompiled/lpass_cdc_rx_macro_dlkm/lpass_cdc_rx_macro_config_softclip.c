__int64 __fastcall lpass_cdc_rx_macro_config_softclip(__int64 result, __int64 a2, char a3)
{
  __int64 v5; // x19
  int v6; // w8
  int v7; // w8

  if ( *(_DWORD *)(a2 + 2324) )
  {
    v5 = result;
    if ( (a3 & 3) != 0 )
    {
      v6 = *(_DWORD *)(a2 + 2332);
      if ( !v6 )
      {
        snd_soc_component_update_bits(result, 4416, 1, 1);
        v6 = *(_DWORD *)(a2 + 2332);
      }
      *(_DWORD *)(a2 + 2332) = v6 + 1;
      result = snd_soc_component_update_bits(v5, 4420, 1, 1);
    }
    if ( (a3 & 0xC) != 0 )
    {
      result = snd_soc_component_update_bits(v5, 4420, 1, 0);
      v7 = *(_DWORD *)(a2 + 2332) - 1;
      *(_DWORD *)(a2 + 2332) = v7;
      if ( !v7 )
        return snd_soc_component_update_bits(v5, 4416, 1, 0);
    }
  }
  return result;
}
