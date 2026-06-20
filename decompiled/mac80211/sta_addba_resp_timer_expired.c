__int64 __fastcall sta_addba_resp_timer_expired(__int64 result)
{
  if ( (*(_QWORD *)(result + 72) & 2) == 0 )
    return ieee80211_stop_tx_ba_session(*(_QWORD *)(result + 64) + 2688LL, *(unsigned __int8 *)(result + 102));
  return result;
}
