__int64 __fastcall ieee80211_stop_p2p_device(__int64 a1, __int64 a2)
{
  return ieee80211_sdata_stop(a2 - 16);
}
