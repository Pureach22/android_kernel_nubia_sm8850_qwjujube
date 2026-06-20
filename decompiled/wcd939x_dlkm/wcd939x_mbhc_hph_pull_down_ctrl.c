__int64 __fastcall wcd939x_mbhc_hph_pull_down_ctrl(__int64 a1, char a2)
{
  __int64 v2; // x3
  unsigned int v4; // w20

  if ( (a2 & 1) != 0 )
    v2 = 64;
  else
    v2 = 0;
  if ( (a2 & 1) != 0 )
    v4 = 16;
  else
    v4 = 0;
  snd_soc_component_update_bits(a1, 12498, 64, v2);
  return snd_soc_component_update_bits(a1, 12498, 16, v4);
}
