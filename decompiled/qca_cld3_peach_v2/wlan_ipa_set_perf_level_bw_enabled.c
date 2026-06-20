__int64 __fastcall wlan_ipa_set_perf_level_bw_enabled(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(a1 + 1464);
  if ( !v1 )
    return v1 & 1;
  if ( (*(_DWORD *)v1 & 0x11) == 1 )
  {
    LOBYTE(v1) = *(_BYTE *)(v1 + 36);
    return v1 & 1;
  }
  return 0;
}
