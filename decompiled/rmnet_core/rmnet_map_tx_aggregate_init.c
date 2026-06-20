__int64 __fastcall rmnet_map_tx_aggregate_init(__int64 a1)
{
  __int64 v2; // x20
  __int64 result; // x0

  *(_DWORD *)(a1 + 2208) = 0;
  *(_QWORD *)(a1 + 2240) = a1 + 2240;
  v2 = a1 + 2592;
  *(_QWORD *)(a1 + 2248) = a1 + 2240;
  hrtimer_init(a1 + 2112, 1, 1);
  *(_QWORD *)(a1 + 2152) = rmnet_map_flush_tx_packet_queue;
  *(_QWORD *)(a1 + 2176) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(a1 + 2184) = a1 + 2184;
  *(_QWORD *)(a1 + 2192) = a1 + 2184;
  *(_QWORD *)(a1 + 2200) = rmnet_map_flush_tx_packet_work;
  *(_QWORD *)(a1 + 2264) = v2;
  rmnet_map_update_ul_agg_config(a1 + 2072, 0xFFFu, 20, 0, 3000000);
  *(_DWORD *)(a1 + 2408) = 0;
  *(_QWORD *)(a1 + 2440) = a1 + 2440;
  *(_QWORD *)(a1 + 2448) = a1 + 2440;
  hrtimer_init(a1 + 2312, 1, 1);
  *(_QWORD *)(a1 + 2352) = rmnet_map_flush_tx_packet_queue;
  *(_QWORD *)(a1 + 2376) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(a1 + 2384) = a1 + 2384;
  *(_QWORD *)(a1 + 2392) = a1 + 2384;
  *(_QWORD *)(a1 + 2400) = rmnet_map_flush_tx_packet_work;
  *(_QWORD *)(a1 + 2464) = v2;
  result = rmnet_map_update_ul_agg_config(a1 + 2272, 0xFFFu, 20, 0, 3000000);
  *(_QWORD *)(a1 + 2224) = dev_queue_xmit;
  *(_QWORD *)(a1 + 2424) = rmnet_ll_send_skb;
  return result;
}
