__int64 __fastcall wcd939x_mbhc_moisture_config(__int64 a1)
{
  int v2; // w9
  __int64 v3; // x0
  __int64 v4; // x3
  unsigned int v5; // w9

  v2 = *(_DWORD *)(a1 + 192);
  v3 = *(_QWORD *)(a1 + 216);
  if ( v2 && !*(_DWORD *)(*(_QWORD *)(a1 + 112) + 88LL) )
  {
    v5 = 4 * v2;
    if ( *(_BYTE *)(a1 + 163) )
      v4 = v5;
    else
      v4 = 0;
  }
  else
  {
    v4 = 0;
  }
  return snd_soc_component_update_bits(v3, 12577, 12, v4);
}
