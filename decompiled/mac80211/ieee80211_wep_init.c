__int64 __fastcall ieee80211_wep_init(__int64 a1)
{
  return get_random_bytes(a1 + 4608, 4);
}
