__int64 __fastcall ieee80211_sched_scan_stopped_work(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  if ( *(_QWORD *)(a2 + 24) )
  {
    *(_QWORD *)(a2 + 24) = 0;
    *(_QWORD *)(a2 + 32) = 0;
    return cfg80211_sched_scan_stopped_locked(*(_QWORD *)(a2 - 4760), 0);
  }
  return result;
}
