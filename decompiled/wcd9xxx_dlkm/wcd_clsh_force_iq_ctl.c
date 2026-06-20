__int64 __fastcall wcd_clsh_force_iq_ctl(__int64 a1, int a2, char a3)
{
  unsigned int v5; // w20
  __int64 result; // x0
  unsigned int v7; // w22
  __int64 v8; // x3

  if ( (a3 & 1) == 0 )
  {
    v8 = 0;
    v5 = 6;
    v7 = 128;
LABEL_6:
    snd_soc_component_update_bits(a1, 12600, 32, v8);
    snd_soc_component_update_bits(a1, 12479, 240, v7);
    return snd_soc_component_update_bits(a1, 12497, 14, v5);
  }
  snd_soc_component_update_bits(a1, 12463, 224, 160);
  v5 = 2;
  usleep_range_state(100, 110, 2);
  snd_soc_component_update_bits(a1, 12441, 2, 2);
  result = snd_soc_component_update_bits(a1, 12440, 255, 28);
  v7 = 192;
  v8 = 32;
  if ( a2 == 8 || a2 == 4 )
    goto LABEL_6;
  return result;
}
