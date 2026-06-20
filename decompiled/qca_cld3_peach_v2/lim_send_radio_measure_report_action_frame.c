__int64 __fastcall lim_send_radio_measure_report_action_frame(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        char a4,
        __int64 a5,
        unsigned __int8 *a6,
        __int64 a7)
{
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x19
  char v24; // w8
  unsigned int v25; // w8
  char v26; // w28
  int v27; // w21
  __int64 v28; // x27
  __int64 v29; // x20
  char v30; // w9
  char v31; // w9
  _BYTE *v33; // x23
  char v34; // w9
  int v35; // w10
  char v36; // w9
  __int64 result; // x0
  unsigned int v38; // w25
  unsigned int packed_radio_measurement_report_size; // w4
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48; // w28
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  char *v57; // x20
  char *v58; // x0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  unsigned int v67; // w9
  __int16 v68; // w9
  __int64 v69; // x5
  _BYTE *v70; // x26
  unsigned int v71; // w4
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  unsigned __int8 v80; // w24
  __int64 v81; // x22
  int v82; // w9
  int v83; // w10
  int v84; // w11
  int v85; // w12
  char v86; // w21
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  _QWORD *context; // x0
  unsigned int v96; // w20
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  __int64 v105; // x22
  int v106; // [xsp+8h] [xbp-78h]
  int v107; // [xsp+10h] [xbp-70h]
  int v108; // [xsp+18h] [xbp-68h]
  int v109; // [xsp+20h] [xbp-60h]
  char v110; // [xsp+40h] [xbp-40h]
  unsigned __int8 *v111; // [xsp+48h] [xbp-38h]
  unsigned __int8 v112; // [xsp+54h] [xbp-2Ch]
  __int64 v113; // [xsp+58h] [xbp-28h]
  __int64 v114; // [xsp+60h] [xbp-20h] BYREF
  unsigned int v115; // [xsp+6Ch] [xbp-14h] BYREF
  void *v116[2]; // [xsp+70h] [xbp-10h] BYREF

  v116[1] = *(void **)(_ReadStatusReg(SP_EL0) + 1808);
  v116[0] = nullptr;
  v115 = 0;
  v114 = 0;
  v14 = _qdf_mem_malloc(0x848u, "lim_send_radio_measure_report_action_frame", 6708);
  if ( v14 )
  {
    v23 = v14;
    if ( !a7 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: session not found",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "lim_send_radio_measure_report_action_frame");
LABEL_27:
      _qdf_mem_free(v23);
LABEL_28:
      result = 16;
      goto LABEL_29;
    }
    v24 = *(_BYTE *)(a7 + 10);
    *(_BYTE *)(v14 + 2) = a2;
    *(_WORD *)v14 = 261;
    v110 = v24;
    LOWORD(v25) = a3;
    *(_WORD *)(v14 + 4) = a3;
    if ( a3 )
    {
      v26 = 0;
      v111 = a6;
      v27 = 1;
      v112 = a2;
      v28 = 0;
      v113 = a7;
      while ( 1 )
      {
        if ( v28 == 2112 )
          __break(0x5512u);
        v29 = a5 + v28;
        v33 = (_BYTE *)(v23 + v28);
        v33[11] = *(_BYTE *)(a5 + v28 + 3);
        v34 = *(_BYTE *)(v23 + v28 + 10);
        v33[9] = *(_BYTE *)(a5 + v28);
        v33[10] = v34 & 0xFE;
        v35 = *(unsigned __int8 *)(a5 + v28 + 3);
        switch ( v35 )
        {
          case 3:
            populate_dot11f_chan_load_report(a1, v33 + 8, v29 + 8);
            break;
          case 7:
            v29 = a5 + v28;
            populate_dot11f_rrm_sta_stats_report(a1, v33 + 8, a5 + v28 + 8);
            break;
          case 5:
            if ( (a4 & 1) != 0 )
              v26 |= v27 - 1 == (unsigned __int16)v25 - 1;
            v29 = a5 + v28;
            populate_dot11f_beacon_report(a1, v33 + 8, a5 + v28 + 8, v26 & 1);
            break;
          default:
            v36 = v34 & 0xFC | (2 * (*(_BYTE *)(a5 + v28 + 2) & 1));
            v33[10] = v36;
            v31 = v36 & 0xFB | (4 * (*(_BYTE *)(a5 + v28 + 1) & 1));
            goto LABEL_7;
        }
        v30 = v33[10] & 0xFD | (2 * (*(_BYTE *)(v29 + 2) & 1));
        v33[10] = v30;
        v31 = v30 & 0xFB | (4 * (*(_BYTE *)(v29 + 1) & 1));
LABEL_7:
        v25 = *(unsigned __int16 *)(v23 + 4);
        v28 += 264;
        v33[10] = v31;
        v33[8] = 1;
        if ( v25 <= (unsigned __int16)v27++ )
        {
          a7 = v113;
          a2 = v112;
          v38 = v26 & 1;
          a6 = v111;
          goto LABEL_21;
        }
      }
    }
    v38 = 0;
LABEL_21:
    packed_radio_measurement_report_size = dot11f_get_packed_radio_measurement_report_size(a1, v23, &v115);
    if ( (packed_radio_measurement_report_size & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "TX: [802.11 RRM] Failed to get packed size for RM Report (0x%08x)",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        packed_radio_measurement_report_size);
      v115 = 11;
      goto LABEL_27;
    }
    if ( packed_radio_measurement_report_size )
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: Warnings while calculating the size for Radio Measure Report (0x%08x)",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "lim_send_radio_measure_report_action_frame");
    v48 = v115;
    if ( (unsigned int)cds_packet_alloc((unsigned __int16)v115 + 24, v116, &v114) )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "TX: [802.11 RRM] Allocation of %d bytes failed for RMReport",
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v48 + 24);
      goto LABEL_27;
    }
    qdf_mem_set(v116[0], v48 + 24, 0);
    v57 = (char *)v116[0];
    v58 = (char *)v116[0] + 4;
    *(_BYTE *)v116[0] = -48;
    qdf_mem_copy(v58, a6, 6u);
    v57[10] = *(_BYTE *)(a7 + 30);
    v57[11] = *(_BYTE *)(a7 + 31);
    v57[12] = *(_BYTE *)(a7 + 32);
    v57[13] = *(_BYTE *)(a7 + 33);
    v57[14] = *(_BYTE *)(a7 + 34);
    v57[15] = *(_BYTE *)(a7 + 35);
    qdf_mem_copy(v57 + 16, a6, 6u);
    v67 = *(unsigned __int16 *)(a1 + 21604);
    if ( v67 <= 0xFFE )
      v68 = v67 + 1;
    else
      v68 = 2048;
    *(_WORD *)(a1 + 21604) = v68;
    *((_WORD *)v57 + 11) = (16 * (v68 & 0xF)) | *((_WORD *)v57 + 11) & 0xFF0F;
    v69 = (unsigned __int8)(*(_WORD *)(a1 + 21604) >> 4);
    *((_WORD *)v57 + 11) = (16 * *(_WORD *)(a1 + 21604)) & 0xFF00 | (16 * (v68 & 0xF));
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      "lim_populate_mac_header",
      v68 & 0xF,
      v69,
      *(unsigned __int16 *)(a1 + 21604),
      0);
    v70 = v116[0];
    *((_BYTE *)v116[0] + 16) = *(_BYTE *)(a7 + 24);
    v70[17] = *(_BYTE *)(a7 + 25);
    v70[18] = *(_BYTE *)(a7 + 26);
    v70[19] = *(_BYTE *)(a7 + 27);
    v70[20] = *(_BYTE *)(a7 + 28);
    v70[21] = *(_BYTE *)(a7 + 29);
    lim_set_protected_bit(a1, a7, a6, v70);
    v71 = dot11f_pack_radio_measurement_report(a1, v23, (char *)v116[0] + 24, v115, &v115);
    if ( (v71 & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "Failed to pack an Radio Measure Report (0x%08x)",
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        v71);
      _qdf_mem_free(v23);
      cds_packet_free(v114);
      goto LABEL_28;
    }
    v80 = a3;
    if ( v71 )
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: Warnings while packing Radio Measure Report (0x%08x)",
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        "lim_send_radio_measure_report_action_frame");
    v81 = jiffies;
    if ( lim_send_radio_measure_report_action_frame___last_ticks - jiffies + 125 < 0 )
    {
      if ( a6 )
      {
        v82 = *a6;
        v83 = a6[1];
        v84 = a6[2];
        v85 = a6[5];
      }
      else
      {
        v84 = 0;
        v82 = 0;
        v83 = 0;
        v85 = 0;
      }
      qdf_trace_msg(
        0x35u,
        4u,
        "TX: type:%d seq_no:%d dialog_token:%d no. of APs:%d is_last_rpt:%d num_report:%d peer:%02x:%02x:%02x:**:**:%02x",
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        *(unsigned __int8 *)(v23 + 11),
        *((unsigned __int16 *)v70 + 11) >> 4,
        a2,
        *(unsigned __int16 *)(v23 + 4),
        v38,
        v80,
        v82,
        v83,
        v84,
        v85);
      lim_send_radio_measure_report_action_frame___last_ticks = v81;
    }
    if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a7 + 284)) && (*(_DWORD *)(a7 + 7036) & 0xFFFFFFFE) != 2 )
      v86 = 0;
    else
      v86 = 64;
    qdf_trace(53, 2u, *(_WORD *)(a7 + 8), (unsigned __int8)*(_WORD *)v70 >> 4);
    context = _cds_get_context(
                54,
                (__int64)"lim_send_radio_measure_report_action_frame",
                v87,
                v88,
                v89,
                v90,
                v91,
                v92,
                v93,
                v94);
    LOWORD(v109) = 0;
    LOBYTE(v107) = v110;
    LOBYTE(v106) = v86;
    LOBYTE(v108) = 0;
    v96 = wma_tx_packet(
            context,
            v114,
            v48 + 24,
            3,
            1,
            7,
            lim_tx_complete,
            v116[0],
            lim_mgmt_radio_measure_report_tx_complete,
            v106,
            v107,
            v108,
            v109,
            12,
            0,
            0);
    qdf_trace(53, 5u, *(_WORD *)(a7 + 8), v96);
    if ( v96 )
    {
      v105 = jiffies;
      if ( lim_send_radio_measure_report_action_frame___last_ticks_203 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "TX: [802.11 RRM] Send FAILED! err_status [%d]",
          v97,
          v98,
          v99,
          v100,
          v101,
          v102,
          v103,
          v104,
          v96);
        lim_send_radio_measure_report_action_frame___last_ticks_203 = v105;
      }
      v96 = 16;
    }
    _qdf_mem_free(v23);
    result = v96;
  }
  else
  {
    result = 2;
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
