__int64 __fastcall rmnet_map_flush_tx_packet_queue(__int64 a1)
{
  queue_work_on(32, system_wq, a1 + 64);
  return 0;
}
