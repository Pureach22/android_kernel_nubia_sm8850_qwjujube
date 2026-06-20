__int64 __fastcall wcd9378_mbhc_hph_l_pull_up_control(__int64 a1, unsigned int a2)
{
  __int64 v2; // x3

  if ( a2 <= 0x18 )
    v2 = a2;
  else
    v2 = 8;
  return snd_soc_component_update_bits(a1, 1075315121, 31, v2);
}
