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
  char v19; // w26
  unsigned int packed_disassociation_size; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w27
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned __int16 *v38; // x28
  char *v39; // x24
  char *v40; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned int v49; // w8
  __int16 v50; // w8
  __int64 v51; // x5
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  char *v60; // x23
  char *v61; // x24
  char *v62; // x24
  bool v63; // w25
  unsigned int v64; // w0
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  __int64 v73; // x7
  int v74; // w8
  int v75; // w9
  int v76; // w10
  char v77; // w25
  __int16 v78; // w2
  char v79; // w25
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  _QWORD *context; // x0
  int v89; // w0
  __int16 v90; // w2
  int v91; // w20
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  _QWORD *v108; // x0
  unsigned int v109; // w19
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  double v118; // d0
  double v119; // d1
  double v120; // d2
  double v121; // d3
  double v122; // d4
  double v123; // d5
  double v124; // d6
  double v125; // d7
  double v126; // d0
  double v127; // d1
  double v128; // d2
  double v129; // d3
  double v130; // d4
  double v131; // d5
  double v132; // d6
  double v133; // d7
  __int16 v134[2]; // [xsp+8h] [xbp-68h]
  __int16 v135[2]; // [xsp+8h] [xbp-68h]
  int v136; // [xsp+10h] [xbp-60h]
  int v137; // [xsp+10h] [xbp-60h]
  int v138; // [xsp+18h] [xbp-58h]
  int v139; // [xsp+20h] [xbp-50h]
  int v140; // [xsp+30h] [xbp-40h]
  int v141; // [xsp+44h] [xbp-2Ch] BYREF
  __int64 v142; // [xsp+48h] [xbp-28h] BYREF
  unsigned int v143; // [xsp+54h] [xbp-1Ch] BYREF
  char *v144; // [xsp+58h] [xbp-18h] BYREF
  int v145; // [xsp+60h] [xbp-10h] BYREF
  __int16 v146; // [xsp+64h] [xbp-Ch]
  __int64 v147; // [xsp+68h] [xbp-8h]

  v147 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v141 = 0;
  if ( a4 )
  {
    v13 = *(_DWORD *)(a4 + 7036);
    v17 = result;
    v146 = 0;
    v145 = 0;
    v144 = nullptr;
    v143 = 0;
    v142 = 0;
    if ( (v13 | 2) == 3 && *(_BYTE *)(result + 14809) == 1 )
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
        goto LABEL_34;
      goto LABEL_33;
    }
    v19 = *(_BYTE *)(a4 + 10);
    qdf_mem_set(&v145, 6u, 0);
    LOWORD(v145) = a2;
    packed_disassociation_size = dot11f_get_packed_disassociation_size(v17, &v145, &v143);
    if ( (packed_disassociation_size & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to calculate the packed size for a Disassociation (0x%08x)",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "lim_send_disassoc_mgmt_frame",
        packed_disassociation_size);
      v143 = 6;
    }
    else if ( packed_disassociation_size )
    {
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: There were warnings while calculating the packed size for a Disassociation (0x%08x)",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "lim_send_disassoc_mgmt_frame");
    }
    v29 = v143;
    if ( (unsigned int)cds_packet_alloc((unsigned __int16)v143 + 24, &v144, &v142) )
    {
      result = qdf_trace_msg(
                 0x35u,
                 2u,
                 "%s: Failed to allocate %d bytes for a Disassociation",
                 v30,
                 v31,
                 v32,
                 v33,
                 v34,
                 v35,
                 v36,
                 v37,
                 "lim_send_disassoc_mgmt_frame",
                 v29 + 24);
      if ( (a5 & 1) == 0 )
        goto LABEL_34;
      goto LABEL_33;
    }
    v38 = (unsigned __int16 *)(v17 + 21532);
    qdf_mem_set(v144, v29 + 24, 0);
    v39 = v144;
    v40 = v144 + 4;
    *v144 = -96;
    qdf_mem_copy(v40, a3, 6u);
    v39[10] = *(_BYTE *)(a4 + 30);
    v39[11] = *(_BYTE *)(a4 + 31);
    v39[12] = *(_BYTE *)(a4 + 32);
    v39[13] = *(_BYTE *)(a4 + 33);
    v39[14] = *(_BYTE *)(a4 + 34);
    v39[15] = *(_BYTE *)(a4 + 35);
    qdf_mem_copy(v39 + 16, a3, 6u);
    v49 = *(unsigned __int16 *)(v17 + 21532);
    if ( v49 <= 0xFFE )
      v50 = v49 + 1;
    else
      v50 = 2048;
    *v38 = v50;
    *((_WORD *)v39 + 11) = (16 * (v50 & 0xF)) | *((_WORD *)v39 + 11) & 0xFF0F;
    v51 = (unsigned __int8)(*v38 >> 4);
    *((_WORD *)v39 + 11) = (16 * *v38) & 0xFF00 | (16 * (v50 & 0xF));
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
      *v38,
      0);
    v60 = v144;
    v61 = v144;
    v144[16] = *(_BYTE *)(a4 + 24);
    v62 = v61 + 16;
    v60[17] = *(_BYTE *)(a4 + 25);
    v60[18] = *(_BYTE *)(a4 + 26);
    v60[19] = *(_BYTE *)(a4 + 27);
    v60[20] = *(_BYTE *)(a4 + 28);
    v60[21] = *(_BYTE *)(a4 + 29);
    if ( *(_BYTE *)(v17 + 21711) == 2 )
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Skip WEP bit setting per usr cfg",
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        "lim_send_disassoc_mgmt_frame");
    else
      lim_set_protected_bit(v17, a4, a3, v60);
    v63 = *(_BYTE *)(v17 + 21711) == 1;
    v64 = dot11f_pack_disassociation(v17, &v145, v144 + 24, v143, &v143);
    if ( (v64 & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to pack a Disassociation (0x%08x)",
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        "lim_send_disassoc_mgmt_frame",
        v64);
      result = cds_packet_free(v142);
      if ( (a5 & 1) == 0 )
        goto LABEL_34;
      goto LABEL_33;
    }
    if ( v64 )
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: There were warnings while packing a Disassociation (0x%08x)",
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        "lim_send_disassoc_mgmt_frame");
    if ( v60 == (char *)-4LL )
    {
      v75 = 0;
      v73 = 0;
      v74 = 0;
      v76 = 0;
    }
    else
    {
      v73 = (unsigned __int8)v60[4];
      v74 = (unsigned __int8)v60[5];
      v75 = (unsigned __int8)v60[6];
      v76 = (unsigned __int8)v60[9];
    }
    v77 = 16 * v63;
    qdf_trace_msg(
      0x35u,
      4u,
      "Disassoc TX: vdev %d seq %d reason %u and waitForAck %d to %02x:%02x:%02x:**:**:%02x From %02x:%02x:%02x:**:**:%02x",
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      *(unsigned __int8 *)(a4 + 10),
      *v38,
      (unsigned __int16)a2,
      a5 & 1,
      v73,
      v74,
      v75,
      v76,
      *(unsigned __int8 *)(a4 + 30),
      *(unsigned __int8 *)(a4 + 31),
      *(unsigned __int8 *)(a4 + 32),
      *(unsigned __int8 *)(a4 + 35));
    if ( !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a4 + 284)) || (*(_DWORD *)(a4 + 7036) & 0xFFFFFFFE) == 2 )
      v77 |= 0x40u;
    v78 = *(_WORD *)(a4 + 8);
    *(_WORD *)(a4 + 10012) = a2;
    v79 = v77 | 0x80;
    qdf_trace(53, 2u, v78, (unsigned __int8)*(_WORD *)v60 >> 4);
    v80 = lim_diag_mgmt_tx_event_report(v17, v60, a4, 0, 0);
    if ( (a5 & 1) != 0 )
    {
      context = _cds_get_context(54, (__int64)"lim_send_disassoc_mgmt_frame", v80, v81, v82, v83, v84, v85, v86, v87);
      LOBYTE(v140) = 0;
      LOWORD(v139) = 0;
      LOBYTE(v136) = v19;
      LOBYTE(v134[0]) = v79;
      LOBYTE(v138) = 0;
      v89 = wma_tx_packet(
              context,
              v142,
              v29 + 24,
              3,
              1,
              7,
              lim_tx_complete,
              v144,
              lim_disassoc_tx_complete_cnf_handler,
              *(_DWORD *)v134,
              v136,
              v138,
              v139,
              12,
              v140,
              0);
      v90 = *(_WORD *)(a4 + 8);
      v91 = v89;
      qdf_trace(53, 5u, v90, v89);
      if ( v91 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Failed to send disassoc frame",
          v92,
          v93,
          v94,
          v95,
          v96,
          v97,
          v98,
          v99,
          "lim_send_disassoc_mgmt_frame");
LABEL_33:
        result = lim_send_disassoc_cnf(v17);
        goto LABEL_34;
      }
      if ( (unsigned int)tx_timer_change(v17 + 2400, 50, 0) )
      {
        result = qdf_trace_msg(
                   0x35u,
                   2u,
                   "%s: Unable to change Disassoc ack Timer val",
                   v118,
                   v119,
                   v120,
                   v121,
                   v122,
                   v123,
                   v124,
                   v125,
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
            v126,
            v127,
            v128,
            v129,
            v130,
            v131,
            v132,
            v133,
            "lim_send_disassoc_mgmt_frame");
          result = lim_deactivate_and_change_timer(v17, 16);
        }
      }
    }
    else
    {
      wlan_get_rssi_by_bssid(*(_QWORD *)(v17 + 21560), v62, &v141, v80);
      wlan_connectivity_mgmt_event(
        *(_QWORD *)(v17 + 21552),
        (int)v60,
        *(unsigned __int8 *)(a4 + 10),
        a2,
        1,
        v141,
        0,
        0,
        0,
        0,
        11);
      v100 = lim_cp_stats_cstats_log_disassoc_evt(a4, 0, a2);
      v108 = _cds_get_context(
               54,
               (__int64)"lim_send_disassoc_mgmt_frame",
               v100,
               v101,
               v102,
               v103,
               v104,
               v105,
               v106,
               v107);
      LOBYTE(v140) = 0;
      LOWORD(v139) = 0;
      LOBYTE(v138) = 0;
      LOBYTE(v137) = v19;
      LOBYTE(v135[0]) = v79;
      v109 = wma_tx_packet(
               v108,
               v142,
               v29 + 24,
               3,
               1,
               7,
               lim_tx_complete,
               v144,
               0,
               *(_DWORD *)v135,
               v137,
               v138,
               v139,
               12,
               v140,
               0);
      result = qdf_trace(53, 5u, *(_WORD *)(a4 + 8), v109);
      if ( v109 )
        result = qdf_trace_msg(
                   0x35u,
                   2u,
                   "%s: Failed to send Disassociation (%X)!",
                   v110,
                   v111,
                   v112,
                   v113,
                   v114,
                   v115,
                   v116,
                   v117,
                   "lim_send_disassoc_mgmt_frame",
                   v109);
    }
  }
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
