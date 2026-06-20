_QWORD *__fastcall ieee80211_sched_scan_end(_QWORD *result)
{
  if ( result[607] )
  {
    result[607] = 0;
    result[608] = 0;
    return (_QWORD *)cfg80211_sched_scan_stopped_locked(result[9], 0);
  }
  return result;
}
