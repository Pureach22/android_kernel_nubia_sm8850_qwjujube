__int64 __fastcall ieee80211_request_sched_scan_start(unsigned __int64 a1, unsigned __int64 a2)
{
  if ( *(_QWORD *)(*(_QWORD *)(a1 + 1616) + 4856LL) )
    return 4294967280LL;
  else
    return _ieee80211_request_sched_scan_start(a1, a2);
}
