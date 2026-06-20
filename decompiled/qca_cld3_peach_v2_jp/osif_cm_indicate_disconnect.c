__int64 __fastcall osif_cm_indicate_disconnect(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        unsigned int a8)
{
  return cfg80211_disconnected(a2, a3, a5, a6, a4, a8);
}
