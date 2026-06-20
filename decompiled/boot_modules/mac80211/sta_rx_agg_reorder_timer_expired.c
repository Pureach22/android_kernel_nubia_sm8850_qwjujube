__int64 __fastcall sta_rx_agg_reorder_timer_expired(__int64 a1)
{
  __int64 v2; // x0

  _rcu_read_lock();
  v2 = ieee80211_release_reorder_timeout(*(_QWORD *)(a1 - 48), *(unsigned __int8 *)(a1 + 58));
  return _rcu_read_unlock(v2);
}
