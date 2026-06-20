__int64 __fastcall ieee80211_set_multicast_to_unicast(__int64 a1, __int64 a2, char a3)
{
  *(_BYTE *)(a2 + 5268) = a3;
  return 0;
}
