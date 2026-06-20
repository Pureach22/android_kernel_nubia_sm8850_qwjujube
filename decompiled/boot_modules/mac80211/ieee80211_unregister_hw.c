__int64 __fastcall ieee80211_unregister_hw(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x0

  tasklet_kill(a1 + 2384);
  tasklet_kill(a1 + 1512);
  unregister_inetaddr_notifier(a1 + 5104);
  v2 = unregister_inet6addr_notifier(a1 + 5128);
  rtnl_lock(v2);
  ieee80211_remove_interfaces(a1);
  ieee80211_txq_teardown_flows(a1);
  mutex_lock(*(_QWORD *)(a1 + 72));
  wiphy_delayed_work_cancel(*(_QWORD *)(a1 + 72), a1 + 5192);
  wiphy_work_cancel(*(_QWORD *)(a1 + 72), a1 + 1408);
  wiphy_work_cancel(*(_QWORD *)(a1 + 72), a1 + 4832);
  wiphy_work_cancel(*(_QWORD *)(a1 + 72), a1 + 1480);
  v3 = mutex_unlock(*(_QWORD *)(a1 + 72));
  rtnl_unlock(v3);
  cancel_work_sync(a1 + 5160);
  ieee80211_clear_tx_pending(a1);
  rate_control_deinitialize(a1);
  if ( *(_DWORD *)(a1 + 1568) || *(_DWORD *)(a1 + 1592) )
    dev_warn(*(_QWORD *)(a1 + 72) + 392LL, "skb_queue not empty\n");
  skb_queue_purge_reason(a1 + 1552, 85);
  skb_queue_purge_reason(a1 + 1576, 85);
  wiphy_unregister(*(_QWORD *)(a1 + 72));
  destroy_workqueue(*(_QWORD *)(a1 + 472));
  return kfree(*(_QWORD *)(a1 + 4744));
}
