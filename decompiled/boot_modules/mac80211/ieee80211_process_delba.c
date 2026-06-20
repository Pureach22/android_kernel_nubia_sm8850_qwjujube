__int64 __fastcall ieee80211_process_delba(__int64 a1, _QWORD *a2, __int64 a3)
{
  unsigned int v3; // w9
  unsigned int v5; // w1

  v3 = *(unsigned __int16 *)(a3 + 26);
  v5 = v3 >> 12;
  if ( (v3 & 0x800) != 0 )
    return _ieee80211_stop_rx_ba_session(a2, v5, 1, 0, 1);
  else
    return _ieee80211_stop_tx_ba_session((__int64)a2, v5, 2u);
}
