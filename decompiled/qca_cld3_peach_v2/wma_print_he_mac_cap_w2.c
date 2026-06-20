__int64 __fastcall wma_print_he_mac_cap_w2(
        unsigned int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  qdf_trace_msg(
    0x36u,
    8u,
    " BSRP A-MPDU Aggregation 0x%01x, Quite Time Period 0x%01x, A-BQR 0x%01x, SR Responder 0x%01x, NDP Feedback 0x%01x, OPS 0x%01x",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a1 & 1,
    (a1 >> 1) & 1,
    (a1 >> 2) & 1,
    (a1 >> 3) & 1,
    (a1 >> 4) & 1,
    (a1 >> 5) & 1);
  return qdf_trace_msg(
           0x36u,
           8u,
           " Multi-TID aggr Tx 0x%03x, Sub Ch selective Tx 0x%01x, UL 2x996 tone RU 0x%01x, OM ctrl UL MU data disable Rx: 0x%01x",
           v10,
           v11,
           v12,
           v13,
           v14,
           v15,
           v16,
           v17,
           (a1 >> 7) & 7,
           (a1 >> 10) & 1,
           (a1 >> 11) & 1,
           (a1 >> 12) & 1);
}
