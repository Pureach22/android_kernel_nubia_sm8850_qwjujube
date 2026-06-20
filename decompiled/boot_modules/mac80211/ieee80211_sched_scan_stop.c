__int64 __fastcall ieee80211_sched_scan_stop(__int64 a1)
{
  if ( a1 )
  {
    if ( *(_QWORD *)(*(_QWORD *)(a1 + 2000) + 208LL) )
      return ieee80211_request_sched_scan_stop(a1 + 1536);
    else
      return 4294967201LL;
  }
  else
  {
    __break(0x800u);
    return ieee80211_set_rekey_data();
  }
}
