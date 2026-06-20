__int64 __fastcall ieee80211_ibss_leave(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x0

  ieee80211_ibss_disconnect(a1);
  v2 = *(_QWORD *)(a1 + 2392);
  *(_BYTE *)(a1 + 2384) = 0;
  *(_DWORD *)(a1 + 2346) = 0;
  *(_WORD *)(a1 + 2350) = 0;
  v3 = kfree(v2);
  *(_QWORD *)(a1 + 2392) = 0;
  *(_BYTE *)(a1 + 2385) = 0;
  *(_QWORD *)(a1 + 2448) = 0;
  *(_QWORD *)(a1 + 2456) = 0;
  *(_QWORD *)(a1 + 2464) = 0;
  *(_WORD *)(a1 + 2472) = 0;
  *(_QWORD *)(a1 + 2474) = 0;
  *(_QWORD *)(a1 + 2482) = 0;
  *(_QWORD *)(a1 + 2490) = 0;
  *(_WORD *)(a1 + 2498) = 0;
  synchronize_rcu(v3);
  skb_queue_purge_reason(a1 + 1984, 85);
  timer_delete_sync(a1 + 2264);
  return 0;
}
