__int64 __fastcall wlan_hdd_wake_non_priority_queue(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x20
  __int64 result; // x0

  netif_tx_wake_queue(*(_QWORD *)(*(_QWORD *)(a1 + 32) + 24LL) + 384LL);
  netif_tx_wake_queue(*(_QWORD *)(*(_QWORD *)(a1 + 32) + 24LL) + 768LL);
  netif_tx_wake_queue(*(_QWORD *)(*(_QWORD *)(a1 + 32) + 24LL) + 1152LL);
  netif_tx_wake_queue(*(_QWORD *)(*(_QWORD *)(a1 + 32) + 24LL) + 1536LL);
  netif_tx_wake_queue(*(_QWORD *)(*(_QWORD *)(a1 + 32) + 24LL) + 1920LL);
  netif_tx_wake_queue(*(_QWORD *)(*(_QWORD *)(a1 + 32) + 24LL) + 2304LL);
  netif_tx_wake_queue(*(_QWORD *)(*(_QWORD *)(a1 + 32) + 24LL) + 2688LL);
  netif_tx_wake_queue(*(_QWORD *)(*(_QWORD *)(a1 + 32) + 24LL) + 3072LL);
  netif_tx_wake_queue(*(_QWORD *)(*(_QWORD *)(a1 + 32) + 24LL) + 3456LL);
  netif_tx_wake_queue(*(_QWORD *)(*(_QWORD *)(a1 + 32) + 24LL) + 3840LL);
  netif_tx_wake_queue(*(_QWORD *)(*(_QWORD *)(a1 + 32) + 24LL) + 4224LL);
  netif_tx_wake_queue(*(_QWORD *)(*(_QWORD *)(a1 + 32) + 24LL) + 4608LL);
  v2 = 4992;
  if ( *(_DWORD *)(a1 + 40) == 11 )
    v3 = 33;
  else
    v3 = 4;
  do
  {
    result = netif_tx_wake_queue(*(_QWORD *)(*(_QWORD *)(a1 + 32) + 24LL) + v2);
    --v3;
    v2 += 384;
  }
  while ( v3 );
  return result;
}
