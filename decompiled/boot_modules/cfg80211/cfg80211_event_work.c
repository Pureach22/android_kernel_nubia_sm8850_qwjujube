__int64 __fastcall cfg80211_event_work(__int64 a1)
{
  __int64 v2; // x20

  v2 = a1 - 336;
  mutex_lock(a1 + 656);
  cfg80211_process_rdev_events(v2);
  return mutex_unlock(a1 + 656);
}
