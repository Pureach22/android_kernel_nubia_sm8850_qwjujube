__int64 __fastcall sub_B4D38(int a1, unsigned __int64 *a2, void *a3)
{
  int v3; // kr00_4

  v3 = __ldxp(a2);
  return cfg80211_get_station(a1, v3, a3);
}
