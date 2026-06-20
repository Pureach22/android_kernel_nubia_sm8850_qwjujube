__int64 __fastcall ieee80211_beacon_get_template_ema_index(
        unsigned __int64 a1,
        _DWORD *a2,
        __int64 a3,
        unsigned int a4,
        unsigned __int8 a5)
{
  return _ieee80211_beacon_get(a1, a2, a3, 1, a4, a5, nullptr);
}
