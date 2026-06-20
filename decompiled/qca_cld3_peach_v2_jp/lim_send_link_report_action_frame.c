__int64 __fastcall lim_send_link_report_action_frame(
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
  int v15; // w23
  char v17; // w9
  char v18; // w8
  int v19; // w8
  unsigned int packed_link_measurement_report_size; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w24
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  char *v38; // x22
  char *v39; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48; // w9
  __int16 v49; // w9
  __int64 v50; // x5
  char *v51; // x22
  unsigned int v52; // w0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x26
  __int64 v62; // x4
  __int64 v63; // x5
  __int64 v64; // x6
  __int64 v65; // x7
  char v66; // w20
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  _QWORD *context; // x0
  int v76; // w0
  __int16 v77; // w2
  unsigned int v78; // w19
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  __int64 v87; // x21
  __int64 result; // x0
  __int64 v89; // [xsp+40h] [xbp-30h] BYREF
  unsigned int v90; // [xsp+4Ch] [xbp-24h] BYREF
  char *v91; // [xsp+50h] [xbp-20h] BYREF
  _WORD v92[8]; // [xsp+58h] [xbp-18h] BYREF
  __int64 v93; // [xsp+68h] [xbp-8h]

  v93 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v91 = nullptr;
  memset(v92, 0, 11);
  v90 = 0;
  v89 = 0;
  if ( a4 )
  {
    v15 = *(unsigned __int8 *)(a4 + 10);
    qdf_mem_set(v92, 0xBu, 0);
    v17 = *a2;
    v92[0] = 773;
    v18 = a2[1];
    *(_WORD *)((char *)&v92[1] + 1) = 547;
    HIBYTE(v92[2]) = v18;
    v19 = *(_DWORD *)(a2 + 2);
    LOBYTE(v92[1]) = v17;
    LOBYTE(v92[3]) = 0;
    *(_DWORD *)((char *)&v92[3] + 1) = v19;
    packed_link_measurement_report_size = dot11f_get_packed_link_measurement_report_size(a1, v92, &v90);
    if ( (packed_link_measurement_report_size & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to calculate the packed size for a Link Report (0x%08x)",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "lim_send_link_report_action_frame",
        packed_link_measurement_report_size);
      v90 = 11;
    }
    else if ( packed_link_measurement_report_size )
    {
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: There were warnings while calculating the packed size for a Link Report (0x%08x)",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "lim_send_link_report_action_frame");
    }
    v29 = v90;
    if ( (unsigned int)cds_packet_alloc((unsigned __int16)v90 + 24, &v91, &v89) )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to allocate %d bytes for a Link Report",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "lim_send_link_report_action_frame",
        v29 + 24);
    }
    else
    {
      qdf_mem_set(v91, v29 + 24, 0);
      v38 = v91;
      v39 = v91 + 4;
      *v91 = -48;
      qdf_mem_copy(v39, a3, 6u);
      v38[10] = *(_BYTE *)(a4 + 30);
      v38[11] = *(_BYTE *)(a4 + 31);
      v38[12] = *(_BYTE *)(a4 + 32);
      v38[13] = *(_BYTE *)(a4 + 33);
      v38[14] = *(_BYTE *)(a4 + 34);
      v38[15] = *(_BYTE *)(a4 + 35);
      qdf_mem_copy(v38 + 16, a3, 6u);
      v48 = *(unsigned __int16 *)(a1 + 21532);
      if ( v48 <= 0xFFE )
        v49 = v48 + 1;
      else
        v49 = 2048;
      *(_WORD *)(a1 + 21532) = v49;
      *((_WORD *)v38 + 11) = (16 * (v49 & 0xF)) | *((_WORD *)v38 + 11) & 0xFF0F;
      v50 = (unsigned __int8)(*(_WORD *)(a1 + 21532) >> 4);
      *((_WORD *)v38 + 11) = (16 * *(_WORD *)(a1 + 21532)) & 0xFF00 | (16 * (v49 & 0xF));
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "lim_populate_mac_header",
        v49 & 0xF,
        v50,
        *(unsigned __int16 *)(a1 + 21532),
        0);
      v51 = v91;
      v91[16] = *(_BYTE *)(a4 + 24);
      v51[17] = *(_BYTE *)(a4 + 25);
      v51[18] = *(_BYTE *)(a4 + 26);
      v51[19] = *(_BYTE *)(a4 + 27);
      v51[20] = *(_BYTE *)(a4 + 28);
      v51[21] = *(_BYTE *)(a4 + 29);
      lim_set_protected_bit(a1, a4, a3, v51);
      v52 = dot11f_pack_link_measurement_report(a1, v92, v91 + 24, v90, &v90);
      if ( (v52 & 0x10000000) != 0 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Failed to pack an Link Report (0x%08x)",
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          "lim_send_link_report_action_frame",
          v52);
        cds_packet_free(v89);
      }
      else
      {
        if ( v52 )
          qdf_trace_msg(
            0x35u,
            3u,
            "%s: There were warnings while packing Link Report (0x%08x)",
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            "lim_send_link_report_action_frame");
        v61 = jiffies;
        if ( lim_send_link_report_action_frame___last_ticks - jiffies + 125 < 0 )
        {
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
            3u,
            "%s: RRM: Sending Link Report to %02x:%02x:%02x:**:**:%02x on vdev[%d]",
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            "lim_send_link_report_action_frame",
            v62,
            v63,
            v64,
            v65,
            v15);
          lim_send_link_report_action_frame___last_ticks = v61;
        }
        if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a4 + 284)) && (*(_DWORD *)(a4 + 7036) & 0xFFFFFFFE) != 2 )
          v66 = 0;
        else
          v66 = 64;
        qdf_trace(53, 2u, *(_WORD *)(a4 + 8), (unsigned __int8)*(_WORD *)v51 >> 4);
        context = _cds_get_context(
                    54,
                    (__int64)"lim_send_link_report_action_frame",
                    v67,
                    v68,
                    v69,
                    v70,
                    v71,
                    v72,
                    v73,
                    v74);
        v76 = wma_tx_packet(context, v89, v29 + 24, 3, 1, 7, lim_tx_complete, v91, 0, v66, (_BYTE)v15, 0, 0, 12, 0, 0);
        v77 = *(_WORD *)(a4 + 8);
        v78 = v76;
        qdf_trace(53, 5u, v77, v76);
        if ( !v78 )
        {
          result = 0;
          goto LABEL_29;
        }
        v87 = jiffies;
        if ( lim_send_link_report_action_frame___last_ticks_193 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: wma_tx_frame FAILED! Status [%d]",
            v79,
            v80,
            v81,
            v82,
            v83,
            v84,
            v85,
            v86,
            "lim_send_link_report_action_frame",
            v78);
          lim_send_link_report_action_frame___last_ticks_193 = v87;
        }
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: RRM: Send link report: NULL PE session",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "lim_send_link_report_action_frame");
  }
  result = 16;
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
