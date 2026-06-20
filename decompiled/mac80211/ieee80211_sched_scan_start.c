__int64 __fastcall ieee80211_sched_scan_start(__int64 a1, __int64 a2, __int64 a3)
{
  if ( *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 4304) + 464LL) + 200LL) )
    return ieee80211_request_sched_scan_start(a2 + 2688, a3);
  else
    return 4294967201LL;
}
