__int64 __fastcall wcd9378_mbhc_mbhc_bias_control(__int64 a1, char a2)
{
  return snd_soc_component_update_bits(a1, 1075314709, 1, a2 & 1);
}
