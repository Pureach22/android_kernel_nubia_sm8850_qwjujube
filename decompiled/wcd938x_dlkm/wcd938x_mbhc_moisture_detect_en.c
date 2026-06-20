__int64 __fastcall wcd938x_mbhc_moisture_detect_en(__int64 a1, char a2)
{
  __int64 v3; // x0
  __int64 v4; // x3

  v3 = *(_QWORD *)(a1 + 216);
  if ( (a2 & 1) != 0 )
    v4 = (unsigned int)(4 * *(_DWORD *)(a1 + 192));
  else
    v4 = 0;
  return snd_soc_component_update_bits(v3, 12577, 12, v4);
}
