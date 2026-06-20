__int64 __fastcall ieee80211_sta_reset_beacon_monitor(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x0

  if ( (*(_BYTE *)(result + 5872) & 1) == 0 && (*(_QWORD *)(*(_QWORD *)(result + 1616) + 96LL) & 0x20000) == 0 )
  {
    v1 = result;
    v2 = round_jiffies_up(*(_QWORD *)(result + 2456) + jiffies);
    return mod_timer(v1 + 2344, v2);
  }
  return result;
}
