bool __fastcall ieee80211_s1g_is_twt_setup(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(a1 + 224);
  if ( (*(_WORD *)v1 & 0xFC) != 0xD0 )
    return 0;
  if ( *(_BYTE *)(v1 + 24) == 22 )
    return *(_BYTE *)(v1 + 25) == 6;
  return 0;
}
