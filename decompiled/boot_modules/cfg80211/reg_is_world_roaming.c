bool __fastcall reg_is_world_roaming(__int64 a1)
{
  __int64 v1; // x9

  v1 = *(_QWORD *)(a1 + 384);
  return cfg80211_regdomain != -20
      && *(_BYTE *)(cfg80211_regdomain + 20) == 48
      && *(_BYTE *)(cfg80211_regdomain + 21) == 48
      || v1 && *(_BYTE *)(v1 + 20) == 48 && *(_BYTE *)(v1 + 21) == 48
      || last_request && *((_DWORD *)last_request + 5) != 3 && (*(_BYTE *)(a1 + 104) & 1) != 0;
}
