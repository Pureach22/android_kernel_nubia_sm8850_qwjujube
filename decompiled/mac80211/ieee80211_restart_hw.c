__int64 __fastcall ieee80211_restart_hw(__int64 a1)
{
  dev_info(*(_QWORD *)(a1 + 72) + 392LL, "Hardware restart was requested\n");
  ieee80211_stop_queues_by_reason(a1, 0xFFFF, 4, 0);
  *(_BYTE *)(a1 + 1470) = 1;
  return queue_work_on(32, system_freezable_wq, a1 + 5160);
}
