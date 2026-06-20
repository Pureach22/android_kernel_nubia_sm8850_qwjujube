__int64 __fastcall ieee80211_s1g_sta_rate_init(__int64 result)
{
  __int16 v1; // w10

  v1 = *(_WORD *)(result + 2393);
  *(_DWORD *)(result + 1804) = 81920;
  *(_WORD *)(result + 2393) = v1 | 0x2000;
  return result;
}
