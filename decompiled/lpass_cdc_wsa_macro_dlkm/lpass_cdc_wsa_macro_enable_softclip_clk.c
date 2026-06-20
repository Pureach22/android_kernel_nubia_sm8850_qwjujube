__int64 __fastcall lpass_cdc_wsa_macro_enable_softclip_clk(__int64 result, __int64 a2, unsigned int a3, char a4)
{
  __int64 v4; // x21
  int v5; // w20
  int v6; // w9
  unsigned int v7; // w22
  __int64 v8; // x19
  int v9; // w9
  __int64 v10; // x19

  v4 = a2 + 616;
  v5 = 1 << a3;
  v6 = *(_DWORD *)(a2 + 616 + 4LL * a3);
  if ( (a4 & 1) != 0 )
  {
    if ( !v6 )
    {
      v7 = a3;
      v8 = result;
      snd_soc_component_update_bits(result, (unsigned __int16)(32 * a3 + 9792), 1, 1);
      result = snd_soc_component_update_bits(v8, 8472, (unsigned __int8)v5, (unsigned __int8)v5);
      v6 = *(_DWORD *)(v4 + 4LL * v7);
      a3 = v7;
    }
    *(_DWORD *)(v4 + 4LL * a3) = v6 + 1;
  }
  else
  {
    v9 = v6 - 1;
    *(_DWORD *)(v4 + 4LL * a3) = v9;
    if ( !v9 )
    {
      v10 = result;
      snd_soc_component_update_bits(result, (unsigned __int16)(32 * a3 + 9792), 1, 0);
      return snd_soc_component_update_bits(v10, 8472, (unsigned __int8)v5, 0);
    }
  }
  return result;
}
