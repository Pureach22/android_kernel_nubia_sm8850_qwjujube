__int64 __fastcall sub_5AB068(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x9
  __int64 v7; // x22

  return wlan_coex_multi_config_send(a1, a2, a3, a4, a5, a6, (unsigned __int128)(v7 * (__int128)v6) >> 64);
}
