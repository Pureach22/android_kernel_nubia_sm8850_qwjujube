__int64 __fastcall lim_send_neighbor_report_request_frame(
        __int64 a1,
        char *a2,
        unsigned __int8 *a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  char v15; // w23
  char v17; // w9
  int v18; // w10
  unsigned int packed_neighbor_report_request_size; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w24
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  const char *v37; // x2
  __int64 v38; // x4
  char *v39; // x22
  char *v40; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned int v49; // w9
  __int16 v50; // w9
  __int64 v51; // x5
  char *v52; // x22
  unsigned int v53; // w0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x4
  __int64 v63; // x5
  __int64 v64; // x6
  __int64 v65; // x7
  __int64 result; // x0
  char v67; // w20
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  _QWORD *context; // x0
  int v77; // w0
  __int16 v78; // w2
  unsigned int v79; // w19
  __int64 v80; // [xsp+48h] [xbp-48h] BYREF
  unsigned int v81; // [xsp+54h] [xbp-3Ch] BYREF
  char *v82; // [xsp+58h] [xbp-38h] BYREF
  _QWORD v83[6]; // [xsp+60h] [xbp-30h] BYREF

  v83[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v83, 0, 37);
  v82 = nullptr;
  v81 = 0;
  v80 = 0;
  if ( a4 )
  {
    v15 = *(_BYTE *)(a4 + 10);
    qdf_mem_set(v83, 0x25u, 0);
    v17 = *a2;
    v18 = (unsigned __int8)a2[1];
    LOWORD(v83[0]) = 1029;
    BYTE2(v83[0]) = v17;
    if ( v18 )
      populate_dot11f_ssid(a1, a2 + 2, (char *)v83 + 3);
    packed_neighbor_report_request_size = dot11f_get_packed_neighbor_report_request_size(a1, v83, &v81);
    if ( (packed_neighbor_report_request_size & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to calculate the packed size for a Neighbor Report Request(0x%08x)",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "lim_send_neighbor_report_request_frame",
        packed_neighbor_report_request_size);
      v81 = 37;
    }
    else if ( packed_neighbor_report_request_size )
    {
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: There were warnings while calculating the packed size for a Neighbor Report Request(0x%08x)",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "lim_send_neighbor_report_request_frame");
    }
    v28 = v81;
    if ( (unsigned int)cds_packet_alloc((unsigned __int16)v81 + 24, &v82, &v80) )
    {
      v37 = "%s: Failed to allocate %d bytes for a Neighbor Report Request";
      v38 = v28 + 24;
    }
    else
    {
      qdf_mem_set(v82, v28 + 24, 0);
      v39 = v82;
      v40 = v82 + 4;
      *v82 = -48;
      qdf_mem_copy(v40, a3, 6u);
      v39[10] = *(_BYTE *)(a4 + 30);
      v39[11] = *(_BYTE *)(a4 + 31);
      v39[12] = *(_BYTE *)(a4 + 32);
      v39[13] = *(_BYTE *)(a4 + 33);
      v39[14] = *(_BYTE *)(a4 + 34);
      v39[15] = *(_BYTE *)(a4 + 35);
      qdf_mem_copy(v39 + 16, a3, 6u);
      v49 = *(unsigned __int16 *)(a1 + 21604);
      if ( v49 <= 0xFFE )
        v50 = v49 + 1;
      else
        v50 = 2048;
      *(_WORD *)(a1 + 21604) = v50;
      *((_WORD *)v39 + 11) = (16 * (v50 & 0xF)) | *((_WORD *)v39 + 11) & 0xFF0F;
      v51 = (unsigned __int8)(*(_WORD *)(a1 + 21604) >> 4);
      *((_WORD *)v39 + 11) = (16 * *(_WORD *)(a1 + 21604)) & 0xFF00 | (16 * (v50 & 0xF));
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        "lim_populate_mac_header",
        v50 & 0xF,
        v51,
        *(unsigned __int16 *)(a1 + 21604),
        0);
      v52 = v82;
      v82[16] = *(_BYTE *)(a4 + 24);
      v52[17] = *(_BYTE *)(a4 + 25);
      v52[18] = *(_BYTE *)(a4 + 26);
      v52[19] = *(_BYTE *)(a4 + 27);
      v52[20] = *(_BYTE *)(a4 + 28);
      v52[21] = *(_BYTE *)(a4 + 29);
      lim_set_protected_bit(a1, a4, a3, v52);
      v53 = dot11f_pack_neighbor_report_request(a1, v83, v82 + 24, v81, &v81);
      if ( (v53 & 0x10000000) != 0 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Failed to pack an Neighbor Report Request (0x%08x)",
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          "lim_send_neighbor_report_request_frame",
          v53);
        cds_packet_free(v80);
        goto LABEL_21;
      }
      if ( v53 )
        qdf_trace_msg(
          0x35u,
          3u,
          "%s: There were warnings while packing Neighbor Report Request (0x%08x)",
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          "lim_send_neighbor_report_request_frame");
      if ( a3 )
      {
        v62 = *a3;
        v63 = a3[1];
        v64 = a3[2];
        v65 = a3[5];
      }
      else
      {
        v64 = 0;
        v62 = 0;
        v63 = 0;
        v65 = 0;
      }
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Sending a Neighbor Report Request to %02x:%02x:%02x:**:**:%02x",
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        "lim_send_neighbor_report_request_frame",
        v62,
        v63,
        v64,
        v65);
      if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a4 + 284)) && (*(_DWORD *)(a4 + 7036) & 0xFFFFFFFE) != 2 )
        v67 = 0;
      else
        v67 = 64;
      qdf_trace(53, 2u, *(_WORD *)(a4 + 8), (unsigned __int8)*(_WORD *)v52 >> 4);
      context = _cds_get_context(
                  54,
                  (__int64)"lim_send_neighbor_report_request_frame",
                  v68,
                  v69,
                  v70,
                  v71,
                  v72,
                  v73,
                  v74,
                  v75);
      v77 = wma_tx_packet(context, v80, v28 + 24, 3, 1, 7, lim_tx_complete, v82, 0, v67, v15, 0, 0, 12, 0, 0);
      v78 = *(_WORD *)(a4 + 8);
      v79 = v77;
      qdf_trace(53, 5u, v78, v77);
      if ( !v79 )
      {
        result = 0;
        goto LABEL_22;
      }
      v37 = "%s: wma_tx_frame FAILED! Status [%d]";
      v38 = v79;
    }
    qdf_trace_msg(0x35u, 2u, v37, v29, v30, v31, v32, v33, v34, v35, v36, "lim_send_neighbor_report_request_frame", v38);
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: (!psession) in Request to send Neighbor Report request action frame",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "lim_send_neighbor_report_request_frame");
  }
LABEL_21:
  result = 16;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
