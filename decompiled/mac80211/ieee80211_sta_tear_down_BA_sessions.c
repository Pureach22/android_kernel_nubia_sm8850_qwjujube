__int64 __fastcall ieee80211_sta_tear_down_BA_sessions(_QWORD *a1, unsigned int a2)
{
  char v3; // w21
  __int64 result; // x0
  __int64 i; // x20
  __int64 v7; // x2
  unsigned __int64 v14; // x8

  v3 = a2 - 4 < 0xFFFFFFFE;
  _ieee80211_stop_rx_ba_session(a1, 0, 0, 0x24u, v3);
  _ieee80211_stop_rx_ba_session(a1, 1u, 0, 0x24u, v3);
  _ieee80211_stop_rx_ba_session(a1, 2u, 0, 0x24u, v3);
  _ieee80211_stop_rx_ba_session(a1, 3u, 0, 0x24u, v3);
  _ieee80211_stop_rx_ba_session(a1, 4u, 0, 0x24u, v3);
  _ieee80211_stop_rx_ba_session(a1, 5u, 0, 0x24u, v3);
  _ieee80211_stop_rx_ba_session(a1, 6u, 0, 0x24u, v3);
  _ieee80211_stop_rx_ba_session(a1, 7u, 0, 0x24u, v3);
  _ieee80211_stop_rx_ba_session(a1, 8u, 0, 0x24u, v3);
  _ieee80211_stop_rx_ba_session(a1, 9u, 0, 0x24u, v3);
  _ieee80211_stop_rx_ba_session(a1, 0xAu, 0, 0x24u, v3);
  _ieee80211_stop_rx_ba_session(a1, 0xBu, 0, 0x24u, v3);
  _ieee80211_stop_rx_ba_session(a1, 0xCu, 0, 0x24u, v3);
  _ieee80211_stop_rx_ba_session(a1, 0xDu, 0, 0x24u, v3);
  _ieee80211_stop_rx_ba_session(a1, 0xEu, 0, 0x24u, v3);
  _ieee80211_stop_rx_ba_session(a1, 0xFu, 0, 0x24u, v3);
  _ieee80211_stop_tx_ba_session((__int64)a1, 0, a2);
  _ieee80211_stop_tx_ba_session((__int64)a1, 1u, a2);
  _ieee80211_stop_tx_ba_session((__int64)a1, 2u, a2);
  _ieee80211_stop_tx_ba_session((__int64)a1, 3u, a2);
  _ieee80211_stop_tx_ba_session((__int64)a1, 4u, a2);
  _ieee80211_stop_tx_ba_session((__int64)a1, 5u, a2);
  _ieee80211_stop_tx_ba_session((__int64)a1, 6u, a2);
  _ieee80211_stop_tx_ba_session((__int64)a1, 7u, a2);
  _ieee80211_stop_tx_ba_session((__int64)a1, 8u, a2);
  _ieee80211_stop_tx_ba_session((__int64)a1, 9u, a2);
  _ieee80211_stop_tx_ba_session((__int64)a1, 0xAu, a2);
  _ieee80211_stop_tx_ba_session((__int64)a1, 0xBu, a2);
  _ieee80211_stop_tx_ba_session((__int64)a1, 0xCu, a2);
  _ieee80211_stop_tx_ba_session((__int64)a1, 0xDu, a2);
  _ieee80211_stop_tx_ba_session((__int64)a1, 0xEu, a2);
  result = _ieee80211_stop_tx_ba_session((__int64)a1, 0xFu, a2);
  if ( a2 == 3 )
  {
    result = wiphy_work_cancel(*(_QWORD *)(a1[9] + 72LL), a1 + 110);
    for ( i = 0; i != 16; ++i )
    {
      v7 = a1[i + 113];
      if ( v7 )
      {
        _X9 = (unsigned __int64 *)(v7 + 128);
        __asm { PRFM            #0x11, [X9] }
        do
          v14 = __ldxr(_X9);
        while ( __stlxr(v14 & 0xFFFFFFFFFFFFFF7FLL, _X9) );
        __dmb(0xBu);
        if ( (v14 & 0x80) != 0 )
          result = ieee80211_stop_tx_ba_cb((__int64)a1, i, v7);
      }
    }
  }
  return result;
}
