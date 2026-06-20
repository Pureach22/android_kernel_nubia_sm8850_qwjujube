__int64 __fastcall wcd939x_rx_clk_enable(__int64 result)
{
  __int64 v1; // x20
  int v2; // w8
  __int64 v3; // x19

  v1 = *(_QWORD *)(*(_QWORD *)(result + 24) + 152LL);
  v2 = *(_DWORD *)(v1 + 368);
  if ( !v2 )
  {
    v3 = result;
    snd_soc_component_update_bits(result, 12296, 1, 1);
    snd_soc_component_update_bits(v3, 13320, 1, 1);
    snd_soc_component_update_bits(v3, 13320, 2, 2);
    snd_soc_component_update_bits(v3, 13320, 4, 4);
    snd_soc_component_update_bits(v3, 13321, 1, 1);
    snd_soc_component_update_bits(v3, 13321, 2, 2);
    result = snd_soc_component_update_bits(v3, 13321, 4, 4);
    v2 = *(_DWORD *)(v1 + 368);
  }
  *(_DWORD *)(v1 + 368) = v2 + 1;
  return result;
}
