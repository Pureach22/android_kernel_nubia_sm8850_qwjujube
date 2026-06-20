__int64 __fastcall wcd938x_rx_clk_disable(__int64 result)
{
  __int64 v1; // x8
  int v2; // w9
  __int64 v3; // x19

  v1 = *(_QWORD *)(*(_QWORD *)(result + 24) + 152LL);
  v2 = *(_DWORD *)(v1 + 344) - 1;
  *(_DWORD *)(v1 + 344) = v2;
  if ( !v2 )
  {
    v3 = result;
    snd_soc_component_update_bits(result, 12296, 64, 0);
    snd_soc_component_update_bits(v3, 12296, 128, 0);
    snd_soc_component_update_bits(v3, 12296, 1, 0);
    snd_soc_component_update_bits(v3, 13320, 2, 0);
    return snd_soc_component_update_bits(v3, 13320, 1, 0);
  }
  return result;
}
