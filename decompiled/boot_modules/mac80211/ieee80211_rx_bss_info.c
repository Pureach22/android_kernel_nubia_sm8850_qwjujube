__int64 __fastcall ieee80211_rx_bss_info(_QWORD *a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x20
  __int64 result; // x0

  v6 = *(_QWORD *)(*a1 + 1616LL);
  result = ieee80211_get_channel_khz(
             *(_QWORD *)(v6 + 72),
             ((*(unsigned __int16 *)(a4 + 28) << 18 >> 31) & 0x1F4) + 1000 * (*(_WORD *)(a4 + 28) & 0x1FFFu));
  if ( result )
  {
    result = ieee80211_bss_info_update(v6, a4, a2, a3, result);
    if ( result )
    {
      *(_QWORD *)(a1[118] + 80LL) = *(_QWORD *)(result + 56);
      return ieee80211_rx_bss_put(v6, result);
    }
  }
  return result;
}
