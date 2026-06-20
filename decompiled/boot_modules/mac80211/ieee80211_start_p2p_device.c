__int64 __fastcall ieee80211_start_p2p_device(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = ieee80211_check_combinations(a2 - 16, 0, 0, 0, 0xFFFFFFFFLL);
  if ( (result & 0x80000000) == 0 )
    return ieee80211_do_open(a2, 1);
  return result;
}
