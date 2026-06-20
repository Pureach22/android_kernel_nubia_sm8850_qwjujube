__int64 __fastcall wma_print_he_mac_cap_w1(
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
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v35; // [xsp+0h] [xbp-10h]
  __int64 v36; // [xsp+0h] [xbp-10h]
  __int64 v37; // [xsp+8h] [xbp-8h]

  qdf_trace_msg(
    0x36u,
    8u,
    "%s: HE MAC Caps: HTC-HE control 0x%01x, TWT Requestor 0x%01x, TWT Responder 0x%01x, Fragmentation 0x%02x, Max no.of "
    "MSDUs 0x%03x, Min. frag 0x%02x",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wma_print_he_mac_cap_w1",
    a1 & 1,
    (a1 >> 1) & 1,
    (a1 >> 2) & 1,
    (a1 >> 3) & 3,
    (unsigned __int8)a1 >> 5,
    (a1 >> 8) & 3);
  LODWORD(v35) = (a1 >> 19) & 1;
  qdf_trace_msg(
    0x36u,
    8u,
    " Trigger MAC pad dur 0x%02x, Multi-TID aggr Rx 0x%03x, Link adaptation 0x%02x, All ACK 0x%01x, UL MU resp sched 0x%0"
    "1x, A-Buff status 0x%01x",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    (a1 >> 10) & 3,
    (a1 >> 12) & 7,
    (a1 >> 15) & 3,
    (a1 >> 17) & 1,
    (a1 >> 18) & 1,
    v35);
  LODWORD(v36) = (a1 >> 26) & 1;
  LODWORD(v37) = (a1 >> 27) & 3;
  qdf_trace_msg(
    0x36u,
    8u,
    " BC TWT 0x%01x, 32bit BA 0x%01x, MU Cascading 0x%01x, ACK enabled Multi-TID 0x%01x, OMI A-Control 0x%01x, OFDMA RA 0"
    "x%01x, Max A-MPDU 0x%02x",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    (a1 >> 20) & 1,
    (a1 >> 21) & 1,
    (a1 >> 22) & 1,
    (a1 >> 23) & 1,
    (a1 >> 25) & 1,
    v36,
    v37);
  return qdf_trace_msg(
           0x36u,
           8u,
           " A-MSDU Fragmentation: 0x%01x, Flex. TWT sched 0x%01x, Rx Ctrl frame to MBSS: 0x%01x",
           v26,
           v27,
           v28,
           v29,
           v30,
           v31,
           v32,
           v33,
           (a1 >> 29) & 1,
           (a1 >> 30) & 1,
           a1 >> 31);
}
