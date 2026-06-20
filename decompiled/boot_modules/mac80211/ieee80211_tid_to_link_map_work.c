__int64 __fastcall ieee80211_tid_to_link_map_work(__int64 a1, __int64 a2)
{
  unsigned int v2; // w20
  __int64 v3; // x21
  int v5; // w22
  __int64 result; // x0

  v2 = *(unsigned __int16 *)(a2 + 2760);
  v3 = a2 - 3040;
  v5 = *(unsigned __int16 *)(a2 + 80);
  ieee80211_vif_set_links((unsigned __int16 *)(a2 - 3040), v2, 0);
  result = ieee80211_ttlm_set_links(v3, v2 & v5, v2 & ~v5);
  if ( !(_DWORD)result )
  {
    *(_WORD *)(a2 + 72) = 0;
    *(_BYTE *)(a2 + 82) = 1;
  }
  return result;
}
