__int64 __fastcall ieee80211_mgd_stop(_QWORD *a1)
{
  wiphy_work_cancel(*(_QWORD *)(a1[202] + 72LL), a1 + 298);
  wiphy_work_cancel(*(_QWORD *)(a1[202] + 72LL), a1 + 301);
  wiphy_work_cancel(*(_QWORD *)(a1[202] + 72LL), a1 + 304);
  wiphy_delayed_work_cancel(*(_QWORD *)(a1[202] + 72LL), a1 + 331);
  if ( a1[311] )
    ieee80211_destroy_assoc_data((__int64)a1, 2);
  if ( a1[310] )
    ieee80211_destroy_auth_data((__int64)a1, 0);
  raw_spin_lock_bh(a1 + 342);
  if ( a1[341] )
  {
    sk_skb_reason_drop(0);
    a1[341] = 0;
    a1[340] = 0;
  }
  kfree(a1[368]);
  a1[369] = 0;
  a1[368] = 0;
  raw_spin_unlock_bh(a1 + 342);
  return timer_delete_sync(a1 + 283);
}
