__int64 __fastcall dump_cfr_peer_tx_event_enh(
        unsigned int *a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  int v37; // [xsp+0h] [xbp-20h]
  __int64 v38; // [xsp+0h] [xbp-20h]
  __int64 v39; // [xsp+0h] [xbp-20h]
  int v40; // [xsp+8h] [xbp-18h]
  __int64 v41; // [xsp+8h] [xbp-18h]
  int v42; // [xsp+10h] [xbp-10h]
  __int64 v43; // [xsp+10h] [xbp-10h]

  v42 = *((unsigned __int8 *)a1 + 13);
  v40 = *((unsigned __int8 *)a1 + 10);
  v37 = *((unsigned __int8 *)a1 + 9);
  qdf_trace_msg(
    0x6Au,
    8u,
    "%s: <TXCOMP><%u>CFR capture method: %d vdev_id: %d mac: %02x:%02x:%02x:**:**:%02x",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "dump_cfr_peer_tx_event_enh",
    a2,
    *a1,
    a1[1],
    *((unsigned __int8 *)a1 + 8),
    v37,
    v40,
    v42);
  LODWORD(v43) = a1[9];
  LODWORD(v41) = a1[8];
  LODWORD(v38) = a1[7];
  qdf_trace_msg(
    0x6Au,
    8u,
    "%s: <TXCOMP><%u>Chan: %d bw: %d phymode: %d cfreq1: %d cfrq2: %d nss: %d\n",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "dump_cfr_peer_tx_event_enh",
    a2,
    a1[4],
    a1[5],
    a1[6],
    v38,
    v41,
    v43);
  qdf_trace_msg(
    0x6Au,
    8u,
    "%s: <TXCOMP><%u>Correlation_info1: 0x%08x Correlation_info2: 0x%08x\n",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    "dump_cfr_peer_tx_event_enh",
    a2,
    a1[10],
    a1[11]);
  LODWORD(v39) = a1[15];
  return qdf_trace_msg(
           0x6Au,
           8u,
           "%s: <TXCOMP><%u>status: 0x%x ts: %d counter: %d rssi0: 0x%08x\n",
           v28,
           v29,
           v30,
           v31,
           v32,
           v33,
           v34,
           v35,
           "dump_cfr_peer_tx_event_enh",
           a2,
           a1[12],
           a1[13],
           a1[14],
           v39);
}
