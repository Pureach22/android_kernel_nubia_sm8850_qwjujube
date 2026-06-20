__int64 __fastcall ieee80211_sta_rx_queued_ext(__int64 result, __int64 a2)
{
  _WORD *v2; // x8

  v2 = *(_WORD **)(a2 + 224);
  if ( (*v2 & 0xF0) == 0x10 )
    return ((__int64 (__fastcall *)(__int64, _WORD *, _QWORD, __int64))ieee80211_rx_mgmt_beacon)(
             result + 3616,
             v2,
             *(unsigned int *)(a2 + 112),
             a2 + 40);
  return result;
}
