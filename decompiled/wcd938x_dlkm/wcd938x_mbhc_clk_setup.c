__int64 __fastcall wcd938x_mbhc_clk_setup(__int64 a1, char a2)
{
  __int64 v2; // x3

  if ( (a2 & 1) != 0 )
    v2 = 128;
  else
    v2 = 0;
  return snd_soc_component_update_bits(a1, 12576, 128, v2);
}
