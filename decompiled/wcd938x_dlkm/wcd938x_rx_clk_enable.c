__int64 __fastcall wcd938x_rx_clk_enable(__int64 result)
{
  __int64 v1; // x20
  int v2; // w8
  __int64 v3; // x19

  v1 = *(_QWORD *)(*(_QWORD *)(result + 24) + 152LL);
  v2 = *(_DWORD *)(v1 + 344);
  if ( !v2 )
  {
    v3 = result;
    snd_soc_component_update_bits(result, 13320, 1, 1);
    snd_soc_component_update_bits(v3, 12296, 1, 1);
    snd_soc_component_update_bits(v3, 13325, 64, 0);
    snd_soc_component_update_bits(v3, 13326, 64, 0);
    snd_soc_component_update_bits(v3, 13327, 64, 0);
    snd_soc_component_update_bits(v3, 13320, 2, 2);
    result = snd_soc_component_update_bits(v3, 12584, 16, 16);
    v2 = *(_DWORD *)(v1 + 344);
  }
  *(_DWORD *)(v1 + 344) = v2 + 1;
  return result;
}
