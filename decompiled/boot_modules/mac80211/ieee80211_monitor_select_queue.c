__int64 __fastcall ieee80211_monitor_select_queue(__int64 a1, __int64 a2)
{
  __int64 v4; // x21
  unsigned int v5; // w23
  __int64 v6; // x22

  if ( *(unsigned __int16 *)(*(_QWORD *)(a1 + 4304) + 128LL) < 4u )
    return 0;
  *(_QWORD *)(a2 + 72) = 0;
  *(_QWORD *)(a2 + 80) = 0;
  *(_QWORD *)(a2 + 56) = 0;
  *(_QWORD *)(a2 + 64) = 0;
  *(_QWORD *)(a2 + 40) = 0;
  *(_QWORD *)(a2 + 48) = 0;
  if ( (((__int64 (__fastcall *)(__int64, __int64))ieee80211_parse_tx_radiotap)(a2, a1) & 1) == 0 )
    return 0;
  v4 = *(_QWORD *)(a2 + 224);
  v5 = *(_DWORD *)(a2 + 112);
  v6 = *(unsigned __int16 *)(v4 + 2);
  if ( v5 >= (int)v6 + 2 && v5 >= (unsigned int)ieee80211_hdrlen(*(unsigned __int16 *)(v4 + v6)) + (unsigned int)v6 )
    return ieee80211_select_queue_80211(a1 + 2688, a2, v4 + v6);
  else
    return 0;
}
