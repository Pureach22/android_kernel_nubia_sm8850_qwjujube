__int64 __fastcall wcd939x_mbhc_zdet_leakage_resistance(__int64 a1, char a2)
{
  __int64 v2; // x0
  __int64 v3; // x3

  v2 = *(_QWORD *)(a1 + 216);
  if ( (a2 & 1) != 0 )
    v3 = 128;
  else
    v3 = 0;
  return snd_soc_component_update_bits(v2, 12377, 128, v3);
}
