bool __fastcall wcd9378_mbhc_get_moisture_status(__int64 a1)
{
  int v2; // w9
  __int64 v3; // x0
  __int64 v4; // x21
  __int64 v5; // x19

  v2 = *(_DWORD *)(a1 + 192);
  v3 = *(_QWORD *)(a1 + 216);
  if ( v2 && !*(_DWORD *)(*(_QWORD *)(a1 + 112) + 88LL) && (*(_BYTE *)(a1 + 163) & 1) != 0 )
  {
    v4 = a1;
    v5 = v3;
    if ( (snd_soc_component_read(v3, 1075314977) & 0xC) == 0 )
    {
      snd_soc_component_update_bits(*(_QWORD *)(v4 + 216), 1075314977, 12, (unsigned int)(4 * *(_DWORD *)(v4 + 192)));
      return (snd_soc_component_read(v5, 1075314981) & 0x20) == 0;
    }
  }
  else
  {
    snd_soc_component_update_bits(v3, 1075314977, 12, 0);
  }
  return 0;
}
