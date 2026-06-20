bool __fastcall cfg80211_does_bw_fit_range(_DWORD *a1, int a2, unsigned int a3)
{
  return a2 - (a3 >> 1) >= *a1 && (a3 >> 1) + a2 <= a1[1];
}
