__int64 __fastcall lim_send_disassoc_mgmt_frame(
        __int64 result,
        unsigned int a2,
        const void *a3,
        __int64 a4,
        char a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  int v13; // w8
  __int64 v17; // x19
  char is_ml_peer_state_disconn; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  char v28; // w21
  unsigned int packed_disassociation_size; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w27
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  unsigned __int16 *v47; // x28
  char *v48; // x25
  char *v49; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned int v58; // w8
  __int16 v59; // w8
  __int64 v60; // x5
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  char *v69; // x24
  char *v70; // x25
  char *v71; // x25
  bool v72; // w26
  unsigned int v73; // w0
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  __int64 v82; // x7
  int v83; // w8
  int v84; // w9
  int v85; // w10
  char v86; // w26
  __int16 v87; // w2
  char v88; // w26
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  _QWORD *context; // x0
  int v98; // w0
  __int16 v99; // w2
  int v100; // w20
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  _QWORD *v117; // x0
  unsigned int v118; // w19
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  double v127; // d0
  double v128; // d1
  double v129; // d2
  double v130; // d3
  double v131; // d4
  double v132; // d5
  double v133; // d6
  double v134; // d7
  double v135; // d0
  double v136; // d1
  double v137; // d2
  double v138; // d3
  double v139; // d4
  double v140; // d5
  double v141; // d6
  double v142; // d7
  __int16 v143[2]; // [xsp+8h] [xbp-68h]
  __int16 v144[2]; // [xsp+8h] [xbp-68h]
  int v145; // [xsp+10h] [xbp-60h]
  int v146; // [xsp+10h] [xbp-60h]
  int v147; // [xsp+18h] [xbp-58h]
  int v148; // [xsp+20h] [xbp-50h]
  int v149; // [xsp+30h] [xbp-40h]
  int v150; // [xsp+44h] [xbp-2Ch] BYREF
  __int64 v151; // [xsp+48h] [xbp-28h] BYREF
  unsigned int v152; // [xsp+54h] [xbp-1Ch] BYREF
  char *v153; // [xsp+58h] [xbp-18h] BYREF
  int v154; // [xsp+60h] [xbp-10h] BYREF
  __int16 v155; // [xsp+64h] [xbp-Ch]
  __int64 v156; // [xsp+68h] [xbp-8h]

  v156 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v150 = 0;
  if ( a4 )
  {
    v13 = *(_DWORD *)(a4 + 7036);
    v17 = result;
    v155 = 0;
    v154 = 0;
    v153 = nullptr;
    v152 = 0;
    v151 = 0;
    if ( (v13 | 2) == 3 && *(_BYTE *)(result + 14881) == 1 )
    {
      result = qdf_trace_msg(
                 0x35u,
                 4u,
                 "%s: CAC timer is running, drop disassoc from going out",
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 a12,
                 a13,
                 "lim_send_disassoc_mgmt_frame");
      if ( (a5 & 1) == 0 )
        goto LABEL_36;
      goto LABEL_35;
    }
    is_ml_peer_state_disconn = lim_is_ml_peer_state_disconn(result, a4);
    v28 = *(_BYTE *)(a4 + 10);
    if ( (is_ml_peer_state_disconn & 1) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: disassoc tx not required for vdev id %d",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "lim_send_disassoc_mgmt_frame",
        *(unsigned __int8 *)(a4 + 10));
LABEL_35:
      result = lim_send_disassoc_cnf(v17);
      goto LABEL_36;
    }
    qdf_mem_set(&v154, 6u, 0);
    LOWORD(v154) = a2;
    packed_disassociation_size = dot11f_get_packed_disassociation_size(v17, &v154, &v152);
    if ( (packed_disassociation_size & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to calculate the packed size for a Disassociation (0x%08x)",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "lim_send_disassoc_mgmt_frame",
        packed_disassociation_size);
      v152 = 6;
    }
    else if ( packed_disassociation_size )
    {
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: There were warnings while calculating the packed size for a Disassociation (0x%08x)",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "lim_send_disassoc_mgmt_frame");
    }
    v38 = v152;
    if ( (unsigned int)cds_packet_alloc((unsigned __int16)v152 + 24, &v153, &v151) )
    {
      result = qdf_trace_msg(
                 0x35u,
                 2u,
                 "%s: Failed to allocate %d bytes for a Disassociation",
                 v39,
                 v40,
                 v41,
                 v42,
                 v43,
                 v44,
                 v45,
                 v46,
                 "lim_send_disassoc_mgmt_frame",
                 v38 + 24);
      if ( (a5 & 1) == 0 )
        goto LABEL_36;
      goto LABEL_35;
    }
    v47 = (unsigned __int16 *)(v17 + 21604);
    qdf_mem_set(v153, v38 + 24, 0);
    v48 = v153;
    v49 = v153 + 4;
    *v153 = -96;
    qdf_mem_copy(v49, a3, 6u);
    v48[10] = *(_BYTE *)(a4 + 30);
    v48[11] = *(_BYTE *)(a4 + 31);
    v48[12] = *(_BYTE *)(a4 + 32);
    v48[13] = *(_BYTE *)(a4 + 33);
    v48[14] = *(_BYTE *)(a4 + 34);
    v48[15] = *(_BYTE *)(a4 + 35);
    qdf_mem_copy(v48 + 16, a3, 6u);
    v58 = *(unsigned __int16 *)(v17 + 21604);
    if ( v58 <= 0xFFE )
      v59 = v58 + 1;
    else
      v59 = 2048;
    *v47 = v59;
    *((_WORD *)v48 + 11) = (16 * (v59 & 0xF)) | *((_WORD *)v48 + 11) & 0xFF0F;
    v60 = (unsigned __int8)(*v47 >> 4);
    *((_WORD *)v48 + 11) = (16 * *v47) & 0xFF00 | (16 * (v59 & 0xF));
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "lim_populate_mac_header",
      v59 & 0xF,
      v60,
      *v47,
      0);
    v69 = v153;
    v70 = v153;
    v153[16] = *(_BYTE *)(a4 + 24);
    v71 = v70 + 16;
    v69[17] = *(_BYTE *)(a4 + 25);
    v69[18] = *(_BYTE *)(a4 + 26);
    v69[19] = *(_BYTE *)(a4 + 27);
    v69[20] = *(_BYTE *)(a4 + 28);
    v69[21] = *(_BYTE *)(a4 + 29);
    if ( *(_BYTE *)(v17 + 21783) == 2 )
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Skip WEP bit setting per usr cfg",
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        "lim_send_disassoc_mgmt_frame");
    else
      lim_set_protected_bit(v17, a4, a3, v69);
    v72 = *(_BYTE *)(v17 + 21783) == 1;
    v73 = dot11f_pack_disassociation(v17, &v154, v153 + 24, v152, &v152);
    if ( (v73 & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to pack a Disassociation (0x%08x)",
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        v80,
        v81,
        "lim_send_disassoc_mgmt_frame",
        v73);
      result = cds_packet_free(v151);
      if ( (a5 & 1) == 0 )
        goto LABEL_36;
      goto LABEL_35;
    }
    if ( v73 )
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: There were warnings while packing a Disassociation (0x%08x)",
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        v80,
        v81,
        "lim_send_disassoc_mgmt_frame");
    if ( v69 == (char *)-4LL )
    {
      v84 = 0;
      v82 = 0;
      v83 = 0;
      v85 = 0;
    }
    else
    {
      v82 = (unsigned __int8)v69[4];
      v83 = (unsigned __int8)v69[5];
      v84 = (unsigned __int8)v69[6];
      v85 = (unsigned __int8)v69[9];
    }
    v86 = 16 * v72;
    qdf_trace_msg(
      0x35u,
      4u,
      "Disassoc TX: vdev %d seq %d reason %u and waitForAck %d to %02x:%02x:%02x:**:**:%02x From %02x:%02x:%02x:**:**:%02x",
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      *(unsigned __int8 *)(a4 + 10),
      *v47,
      (unsigned __int16)a2,
      a5 & 1,
      v82,
      v83,
      v84,
      v85,
      *(unsigned __int8 *)(a4 + 30),
      *(unsigned __int8 *)(a4 + 31),
      *(unsigned __int8 *)(a4 + 32),
      *(unsigned __int8 *)(a4 + 35));
    if ( !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a4 + 284)) || (*(_DWORD *)(a4 + 7036) & 0xFFFFFFFE) == 2 )
      v86 |= 0x40u;
    v87 = *(_WORD *)(a4 + 8);
    *(_WORD *)(a4 + 10012) = a2;
    v88 = v86 | 0x80;
    qdf_trace(53, 2u, v87, (unsigned __int8)*(_WORD *)v69 >> 4);
    v89 = lim_diag_mgmt_tx_event_report(v17, v69, a4, 0, 0);
    if ( (a5 & 1) != 0 )
    {
      context = _cds_get_context(54, (__int64)"lim_send_disassoc_mgmt_frame", v89, v90, v91, v92, v93, v94, v95, v96);
      LOBYTE(v149) = 0;
      LOWORD(v148) = 0;
      LOBYTE(v145) = v28;
      LOBYTE(v143[0]) = v88;
      LOBYTE(v147) = 0;
      v98 = wma_tx_packet(
              context,
              v151,
              v38 + 24,
              3,
              1,
              7,
              lim_tx_complete,
              v153,
              lim_disassoc_tx_complete_cnf_handler,
              *(_DWORD *)v143,
              v145,
              v147,
              v148,
              12,
              v149,
              0);
      v99 = *(_WORD *)(a4 + 8);
      v100 = v98;
      qdf_trace(53, 5u, v99, v98);
      if ( v100 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Failed to send disassoc frame",
          v101,
          v102,
          v103,
          v104,
          v105,
          v106,
          v107,
          v108,
          "lim_send_disassoc_mgmt_frame");
        goto LABEL_35;
      }
      if ( (unsigned int)tx_timer_change(v17 + 2400, 50, 0) )
      {
        result = qdf_trace_msg(
                   0x35u,
                   2u,
                   "%s: Unable to change Disassoc ack Timer val",
                   v127,
                   v128,
                   v129,
                   v130,
                   v131,
                   v132,
                   v133,
                   v134,
                   "lim_send_disassoc_mgmt_frame");
      }
      else
      {
        result = tx_timer_activate((char *)(v17 + 2400));
        if ( (_DWORD)result )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Unable to activate Disassoc ack Timer",
            v135,
            v136,
            v137,
            v138,
            v139,
            v140,
            v141,
            v142,
            "lim_send_disassoc_mgmt_frame");
          result = lim_deactivate_and_change_timer(v17, 16);
        }
      }
    }
    else
    {
      wlan_get_rssi_by_bssid(*(_QWORD *)(v17 + 21632), v71, &v150, v89);
      wlan_connectivity_mgmt_event(
        *(_QWORD *)(v17 + 21624),
        (int)v69,
        *(unsigned __int8 *)(a4 + 10),
        a2,
        1,
        v150,
        0,
        0,
        0,
        0,
        11);
      v109 = lim_cp_stats_cstats_log_disassoc_evt(a4, 0, a2);
      v117 = _cds_get_context(
               54,
               (__int64)"lim_send_disassoc_mgmt_frame",
               v109,
               v110,
               v111,
               v112,
               v113,
               v114,
               v115,
               v116);
      LOBYTE(v149) = 0;
      LOWORD(v148) = 0;
      LOBYTE(v147) = 0;
      LOBYTE(v146) = v28;
      LOBYTE(v144[0]) = v88;
      v118 = wma_tx_packet(
               v117,
               v151,
               v38 + 24,
               3,
               1,
               7,
               lim_tx_complete,
               v153,
               0,
               *(_DWORD *)v144,
               v146,
               v147,
               v148,
               12,
               v149,
               0);
      result = qdf_trace(53, 5u, *(_WORD *)(a4 + 8), v118);
      if ( v118 )
        result = qdf_trace_msg(
                   0x35u,
                   2u,
                   "%s: Failed to send Disassociation (%X)!",
                   v119,
                   v120,
                   v121,
                   v122,
                   v123,
                   v124,
                   v125,
                   v126,
                   "lim_send_disassoc_mgmt_frame",
                   v118);
    }
  }
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return result;
}
