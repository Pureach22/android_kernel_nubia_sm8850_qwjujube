__int64 __fastcall wcd938x_mbhc_gnd_det_ctrl(__int64 a1, char a2)
{
  __int64 v3; // x0
  __int64 v4; // x2
  __int64 v5; // x3

  if ( (a2 & 1) != 0 )
  {
    snd_soc_component_update_bits(a1, 12308, 2, 2);
    v3 = a1;
    v4 = 64;
    v5 = 64;
  }
  else
  {
    snd_soc_component_update_bits(a1, 12308, 64, 0);
    v3 = a1;
    v4 = 2;
    v5 = 0;
  }
  return snd_soc_component_update_bits(v3, 12308, v4, v5);
}
