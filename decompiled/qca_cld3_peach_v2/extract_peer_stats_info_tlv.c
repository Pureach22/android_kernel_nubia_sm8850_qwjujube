__int64 __fastcall extract_peer_stats_info_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        _QWORD *a10,
        unsigned int a11,
        __int64 a12)
{
  __int64 v12; // x21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned __int64 v46; // x20
  __int64 v47; // x8
  __int64 v48; // x8
  unsigned __int64 v49; // x8
  __int64 v51; // [xsp+0h] [xbp-40h]
  __int64 v52; // [xsp+8h] [xbp-38h]

  if ( *(_DWORD *)(*a10 + 8LL) > a11 )
  {
    v12 = a10[2] + 116LL * a11;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: mac %02x:%02x:%02x:**:**:%02x",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "dump_peer_stats_info",
      (unsigned __int8)*(_DWORD *)(v12 + 4),
      (unsigned __int8)BYTE1(*(_DWORD *)(v12 + 4)),
      (unsigned __int8)BYTE2(*(_DWORD *)(v12 + 4)),
      *(unsigned __int8 *)(v12 + 9));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: tx_bytes %d %d tx_packets %d %d tx_retries %d tx_failed %d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "dump_peer_stats_info",
      *(unsigned int *)(v12 + 12),
      *(unsigned int *)(v12 + 16),
      *(unsigned int *)(v12 + 20),
      *(unsigned int *)(v12 + 24),
      *(_DWORD *)(v12 + 44),
      *(_DWORD *)(v12 + 48));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: rx_bytes %d %d rx_packets %d %d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "dump_peer_stats_info",
      *(unsigned int *)(v12 + 28),
      *(unsigned int *)(v12 + 32),
      *(unsigned int *)(v12 + 36),
      *(unsigned int *)(v12 + 40));
    LODWORD(v52) = *(_DWORD *)(v12 + 72);
    LODWORD(v51) = *(_DWORD *)(v12 + 68);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: tx_rate_code %x rx_rate_code %x tx_rate %x rx_rate %x peer_rssi %d tx_succeed %d",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "dump_peer_stats_info",
      *(unsigned int *)(v12 + 52),
      *(unsigned int *)(v12 + 56),
      *(unsigned int *)(v12 + 60),
      *(unsigned int *)(v12 + 64),
      v51,
      v52);
    if ( *(_DWORD *)(v12 + 76) )
      qdf_trace_msg(0x31u, 8u, "%s: chain%d_rssi %d", v38, v39, v40, v41, v42, v43, v44, v45, "dump_peer_stats_info", 0);
    if ( *(_DWORD *)(v12 + 80) )
      qdf_trace_msg(0x31u, 8u, "%s: chain%d_rssi %d", v38, v39, v40, v41, v42, v43, v44, v45, "dump_peer_stats_info", 1);
    if ( *(_DWORD *)(v12 + 84) )
      qdf_trace_msg(0x31u, 8u, "%s: chain%d_rssi %d", v38, v39, v40, v41, v42, v43, v44, v45, "dump_peer_stats_info", 2);
    if ( *(_DWORD *)(v12 + 88) )
      qdf_trace_msg(0x31u, 8u, "%s: chain%d_rssi %d", v38, v39, v40, v41, v42, v43, v44, v45, "dump_peer_stats_info", 3);
    if ( *(_DWORD *)(v12 + 92) )
      qdf_trace_msg(0x31u, 8u, "%s: chain%d_rssi %d", v38, v39, v40, v41, v42, v43, v44, v45, "dump_peer_stats_info", 4);
    if ( *(_DWORD *)(v12 + 96) )
      qdf_trace_msg(0x31u, 8u, "%s: chain%d_rssi %d", v38, v39, v40, v41, v42, v43, v44, v45, "dump_peer_stats_info", 5);
    if ( *(_DWORD *)(v12 + 100) )
      qdf_trace_msg(0x31u, 8u, "%s: chain%d_rssi %d", v38, v39, v40, v41, v42, v43, v44, v45, "dump_peer_stats_info", 6);
    if ( *(_DWORD *)(v12 + 104) )
      qdf_trace_msg(0x31u, 8u, "%s: chain%d_rssi %d", v38, v39, v40, v41, v42, v43, v44, v45, "dump_peer_stats_info", 7);
    *(_WORD *)a12 = *(_DWORD *)(v12 + 4);
    *(_BYTE *)(a12 + 2) = *(_WORD *)(v12 + 6);
    *(_BYTE *)(a12 + 3) = *(_BYTE *)(v12 + 7);
    *(_WORD *)(a12 + 4) = *(_DWORD *)(v12 + 8);
    v46 = *(unsigned int *)(v12 + 20);
    *(_DWORD *)(a12 + 16) = v46;
    v47 = *(unsigned int *)(v12 + 16);
    *(_QWORD *)(a12 + 8) = v47 << 32;
    *(_QWORD *)(a12 + 8) = *(unsigned int *)(v12 + 12) | ((unsigned __int64)(unsigned int)v47 << 32);
    *(_DWORD *)(a12 + 32) = *(_DWORD *)(v12 + 36);
    v48 = *(unsigned int *)(v12 + 32);
    *(_QWORD *)(a12 + 24) = v48 << 32;
    *(_QWORD *)(a12 + 24) = *(unsigned int *)(v12 + 28) | ((unsigned __int64)(unsigned int)v48 << 32);
    *(_DWORD *)(a12 + 36) = *(_DWORD *)(v12 + 44);
    *(_DWORD *)(a12 + 40) = *(_DWORD *)(v12 + 48);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: tx_packets %d, tx_retries %d",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "extract_peer_stats_info_tlv",
      (unsigned int)v46);
    if ( (_DWORD)v46 )
    {
      LODWORD(v49) = *(_DWORD *)(a12 + 36);
      if ( (_DWORD)v49 )
        v49 = ((v46 >> 1) + 100LL * (unsigned int)v49) / v46;
    }
    else
    {
      LODWORD(v49) = 0;
    }
    *(_DWORD *)(a12 + 128) = v49;
    *(_DWORD *)(a12 + 132) = 0;
    *(_DWORD *)(a12 + 64) = *(_DWORD *)(v12 + 72);
    *(_DWORD *)(a12 + 60) = *(_DWORD *)(v12 + 68);
    *(_DWORD *)(a12 + 52) = *(_DWORD *)(v12 + 60);
    *(_DWORD *)(a12 + 44) = *(_DWORD *)(v12 + 52);
    *(_DWORD *)(a12 + 56) = *(_DWORD *)(v12 + 64);
    *(_DWORD *)(a12 + 48) = *(_DWORD *)(v12 + 56);
    *(_DWORD *)(a12 + 68) = *(_DWORD *)(v12 + 76);
    *(_DWORD *)(a12 + 72) = *(_DWORD *)(v12 + 80);
    *(_DWORD *)(a12 + 76) = *(_DWORD *)(v12 + 84);
    *(_DWORD *)(a12 + 80) = *(_DWORD *)(v12 + 88);
    *(_DWORD *)(a12 + 84) = *(_DWORD *)(v12 + 92);
    *(_DWORD *)(a12 + 88) = *(_DWORD *)(v12 + 96);
    *(_DWORD *)(a12 + 92) = *(_DWORD *)(v12 + 100);
    *(_DWORD *)(a12 + 96) = *(_DWORD *)(v12 + 104);
    *(_DWORD *)(a12 + 100) = *(_DWORD *)(v12 + 108);
    *(_DWORD *)(a12 + 104) = *(_DWORD *)(v12 + 112);
  }
  return 0;
}
