__int64 __fastcall cfg80211_sched_scan_stopped(__int64 a1, __int64 a2)
{
  mutex_lock(a1);
  cfg80211_sched_scan_stopped_locked(a1, a2);
  return mutex_unlock(a1);
}
