__int64 __fastcall wcd9378_mbhc_micb_ramp_control(__int64 a1, char a2)
{
  __int64 v3; // x0
  __int64 v4; // x2
  __int64 v5; // x3

  if ( (a2 & 1) != 0 )
  {
    snd_soc_component_update_bits(a1, 1075314724, 28, 12);
    v3 = a1;
    v4 = 128;
    v5 = 128;
  }
  else
  {
    snd_soc_component_update_bits(a1, 1075314724, 128, 0);
    v3 = a1;
    v4 = 28;
    v5 = 0;
  }
  return snd_soc_component_update_bits(v3, 1075314724, v4, v5);
}
