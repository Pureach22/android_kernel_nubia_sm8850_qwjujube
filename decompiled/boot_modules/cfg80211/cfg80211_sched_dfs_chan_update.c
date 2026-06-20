__int64 __fastcall cfg80211_sched_dfs_chan_update(__int64 a1)
{
  cancel_delayed_work(a1 + 368);
  return queue_delayed_work_on(32, cfg80211_wq, a1 + 368, 0);
}
