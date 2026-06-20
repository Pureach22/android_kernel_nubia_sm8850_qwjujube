__int64 __fastcall ieee80211_rx_bss_put(__int64 result, __int64 a2)
{
  if ( a2 )
    return cfg80211_put_bss(*(_QWORD *)(result + 72), a2 - 96);
  return result;
}
