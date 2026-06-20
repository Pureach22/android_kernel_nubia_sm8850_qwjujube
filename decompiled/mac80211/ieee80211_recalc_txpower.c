__int64 __fastcall ieee80211_recalc_txpower(__int64 a1, __int64 a2)
{
  char v2; // w20
  __int64 result; // x0

  v2 = a2;
  result = _ieee80211_recalc_txpower(a1, a2);
  if ( (result & 1) != 0 || (v2 & 1) != 0 && (*(_QWORD *)(a1 + 1632) & 1) != 0 )
    return ieee80211_link_info_change_notify(a1, a1 + 3616, 0x40000);
  return result;
}
