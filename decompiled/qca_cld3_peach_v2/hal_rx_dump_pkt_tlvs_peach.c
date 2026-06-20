unsigned int *__fastcall hal_rx_dump_pkt_tlvs_peach(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        unsigned __int8 a11)
{
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  hal_rx_dump_msdu_end_tlv_peach(a10, a11, a1, a2, a3, a4, a5, a6, a7, a8);
  return hal_rx_dump_mpdu_start_tlv_peach((unsigned int *)(a10 + 64), a11, v13, v14, v15, v16, v17, v18, v19, v20);
}
