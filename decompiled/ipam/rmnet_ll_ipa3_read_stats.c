__int64 __fastcall rmnet_ll_ipa3_read_stats(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v7; // w0

  v7 = scnprintf(
         &dbg_buff_3,
         4096,
         "Queue Leng=%u\n"
         "outstanding_pkts=%u\n"
         "tx_pkt_sent=%u\n"
         "rx_pkt_rcvd=%u\n"
         "tx_byte_sent=%llu\n"
         "rx_byte_rcvd=%llu\n"
         "tx_pkt_dropped=%u\n"
         "rx_pkt_dropped=%u\n"
         "tx_byte_dropped=%llu\n"
         "rx_byte_dropped=%llu\n",
         *(_DWORD *)(rmnet_ll_ipa3_ctx + 664),
         *(_DWORD *)rmnet_ll_ipa3_ctx,
         *(_DWORD *)(rmnet_ll_ipa3_ctx + 4),
         *(_DWORD *)(rmnet_ll_ipa3_ctx + 8),
         *(_QWORD *)(rmnet_ll_ipa3_ctx + 16),
         *(_QWORD *)(rmnet_ll_ipa3_ctx + 24),
         *(_DWORD *)(rmnet_ll_ipa3_ctx + 32),
         *(_DWORD *)(rmnet_ll_ipa3_ctx + 36),
         *(_QWORD *)(rmnet_ll_ipa3_ctx + 40),
         *(_QWORD *)(rmnet_ll_ipa3_ctx + 48));
  return simple_read_from_buffer(a2, a3, a4, &dbg_buff_3, v7);
}
