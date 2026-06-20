__int64 __fastcall sub_3B150(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  return cfg80211_set_dfs_state(a1, a2, a3, a4, (unsigned int)(a8 + __ROR4__(a8, 47)));
}
