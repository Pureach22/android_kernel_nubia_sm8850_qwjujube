__int64 __fastcall sta_tx_agg_session_timer_expired(__int64 result)
{
  __int64 v1; // x21
  unsigned int v2; // w19
  __int64 v3; // x20
  __int64 v4; // x22
  __int64 v5; // x1

  v1 = *(_QWORD *)(result + 104);
  v2 = *(unsigned __int8 *)(result + 142);
  if ( (*(_QWORD *)(result + 112) & 8) == 0 )
  {
    v3 = result;
    v4 = *(_QWORD *)(result + 120);
    v5 = _usecs_to_jiffies(*(unsigned __int16 *)(result + 128) << 10) + v4;
    if ( jiffies - v5 < 0 )
      return mod_timer(v3, v5);
    else
      return ieee80211_stop_tx_ba_session(v1 + 2688, v2);
  }
  return result;
}
