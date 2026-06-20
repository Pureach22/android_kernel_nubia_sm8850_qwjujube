__int64 __fastcall dp_rx_tid_stats_cb(__int64 a1, _DWORD *a2, __int64 a3)
{
  int v3; // w8
  __int64 result; // x0

  v3 = *(_DWORD *)(a3 + 4);
  if ( v3 )
  {
    if ( v3 != 255 )
      return DP_PRINT_STATS("REO stats failure %d for TID %d", v3, *a2);
  }
  else
  {
    DP_PRINT_STATS(
      "REO queue stats (TID: %d):\n"
      "ssn: %d\n"
      "curr_idx  : %d\n"
      "pn_31_0   : %08x\n"
      "pn_63_32  : %08x\n"
      "pn_95_64  : %08x\n"
      "pn_127_96 : %08x\n"
      "last_rx_enq_tstamp : %08x\n"
      "last_rx_deq_tstamp : %08x\n"
      "rx_bitmap_31_0     : %08x\n"
      "rx_bitmap_63_32    : %08x\n"
      "rx_bitmap_95_64    : %08x\n"
      "rx_bitmap_127_96   : %08x\n"
      "rx_bitmap_159_128  : %08x\n"
      "rx_bitmap_191_160  : %08x\n"
      "rx_bitmap_223_192  : %08x\n"
      "rx_bitmap_255_224  : %08x\n",
      *a2,
      *(unsigned __int16 *)(a3 + 12),
      *(unsigned __int8 *)(a3 + 14),
      *(_DWORD *)(a3 + 16),
      *(_DWORD *)(a3 + 20),
      *(_DWORD *)(a3 + 24),
      *(_DWORD *)(a3 + 28),
      *(_DWORD *)(a3 + 32),
      *(_DWORD *)(a3 + 36),
      *(_DWORD *)(a3 + 40),
      *(_DWORD *)(a3 + 44),
      *(_DWORD *)(a3 + 48),
      *(_DWORD *)(a3 + 52),
      *(_DWORD *)(a3 + 56),
      *(_DWORD *)(a3 + 60),
      *(_DWORD *)(a3 + 64),
      *(_DWORD *)(a3 + 68));
    DP_PRINT_STATS(
      "curr_mpdu_cnt      : %d\n"
      "curr_msdu_cnt      : %d\n"
      "fwd_timeout_cnt    : %d\n"
      "fwd_bar_cnt        : %d\n"
      "dup_cnt            : %d\n"
      "frms_in_order_cnt  : %d\n"
      "bar_rcvd_cnt       : %d\n"
      "mpdu_frms_cnt      : %d\n"
      "msdu_frms_cnt      : %d\n"
      "total_byte_cnt     : %d\n"
      "late_recv_mpdu_cnt : %d\n"
      "win_jump_2k        : %d\n"
      "hole_cnt           : %d\n",
      *(unsigned __int8 *)(a3 + 72),
      *(unsigned __int8 *)(a3 + 73),
      *(unsigned __int8 *)(a3 + 74),
      *(unsigned __int8 *)(a3 + 75),
      *(unsigned __int16 *)(a3 + 76),
      *(_DWORD *)(a3 + 80),
      *(unsigned __int8 *)(a3 + 84),
      *(_DWORD *)(a3 + 88),
      *(_DWORD *)(a3 + 92),
      *(_DWORD *)(a3 + 96),
      *(unsigned __int16 *)(a3 + 100),
      *(unsigned __int8 *)(a3 + 102),
      *(unsigned __int16 *)(a3 + 104));
    return DP_PRINT_STATS(
             "Addba Req          : %d\n"
             "Addba Resp         : %d\n"
             "Addba Resp success : %d\n"
             "Addba Resp failed  : %d\n"
             "Delba Req received : %d\n"
             "Delba Tx success   : %d\n"
             "Delba Tx Fail      : %d\n"
             "BA window size     : %d\n"
             "Pn size            : %d\n",
             a2[1],
             a2[2],
             a2[4],
             a2[5],
             a2[3],
             a2[28],
             a2[29],
             *((unsigned __int16 *)a2 + 36),
             *((unsigned __int8 *)a2 + 24));
  }
  return result;
}
