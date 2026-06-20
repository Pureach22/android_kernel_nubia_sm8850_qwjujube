__int64 __fastcall lim_send_deauth_mgmt_frame(
        __int64 result,
        unsigned int a2,
        void *a3,
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
  __int64 v17; // x20
  char v19; // w25
  unsigned int packed_de_auth_size; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w28
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  char *v38; // x24
  char *v39; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48; // w8
  __int16 v49; // w8
  __int64 v50; // x5
  char *v51; // x24
  char *v52; // x3
  unsigned int v53; // w0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x26
  __int64 v63; // x7
  int v64; // w8
  int v65; // w9
  int v66; // w10
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  char v75; // w8
  __int64 v76; // x0
  __int64 v77; // x26
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  _QWORD *context; // x0
  unsigned int v87; // w21
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  _QWORD *v112; // x0
  __int64 v113; // x1
  char *v114; // x7
  __int64 v115; // x4
  char v116; // w8
  __int64 v117; // x2
  double v118; // d0
  double v119; // d1
  double v120; // d2
  double v121; // d3
  double v122; // d4
  double v123; // d5
  double v124; // d6
  double v125; // d7
  unsigned int v126; // w20
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
  const char *v143; // x2
  double v144; // d0
  double v145; // d1
  double v146; // d2
  double v147; // d3
  double v148; // d4
  double v149; // d5
  double v150; // d6
  double v151; // d7
  __int16 v152[2]; // [xsp+8h] [xbp-78h]
  int v153; // [xsp+10h] [xbp-70h]
  int v154; // [xsp+18h] [xbp-68h]
  int v155; // [xsp+20h] [xbp-60h]
  int v156; // [xsp+30h] [xbp-50h]
  char v157; // [xsp+48h] [xbp-38h]
  __int16 v158[2]; // [xsp+50h] [xbp-30h] BYREF
  int v159; // [xsp+54h] [xbp-2Ch] BYREF
  __int64 v160; // [xsp+58h] [xbp-28h] BYREF
  unsigned int v161; // [xsp+64h] [xbp-1Ch] BYREF
  char *v162; // [xsp+68h] [xbp-18h] BYREF
  int v163; // [xsp+70h] [xbp-10h] BYREF
  __int16 v164; // [xsp+74h] [xbp-Ch]
  __int64 v165; // [xsp+78h] [xbp-8h]

  v165 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v159 = 0;
  if ( a4 )
  {
    v13 = *(_DWORD *)(a4 + 7036);
    v17 = result;
    v164 = 0;
    v163 = 0;
    v162 = nullptr;
    v161 = 0;
    v160 = 0;
    v158[0] = 0;
    if ( (v13 | 2) == 3 )
    {
      if ( *(_BYTE *)(result + 14809) )
      {
        result = qdf_trace_msg(
                   0x35u,
                   4u,
                   "%s: CAC timer is running, drop the deauth from going out",
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   a11,
                   a12,
                   a13,
                   "lim_send_deauth_mgmt_frame");
        if ( (_WORD)a2 != 0xFFFF )
        {
          if ( (a5 & 1) == 0 )
            goto LABEL_28;
          goto LABEL_27;
        }
        goto LABEL_11;
      }
      if ( (_WORD)a2 == 0xFFFF )
      {
LABEL_11:
        result = qdf_trace_msg(
                   0x35u,
                   4u,
                   "%s: Silent deauth, remove the peer",
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   a11,
                   a12,
                   a13,
                   "lim_send_deauth_mgmt_frame");
        if ( (a5 & 1) == 0 )
          goto LABEL_28;
        goto LABEL_27;
      }
    }
    v19 = *(_BYTE *)(a4 + 10);
    qdf_mem_set(&v163, 6u, 0);
    LOWORD(v163) = a2;
    packed_de_auth_size = dot11f_get_packed_de_auth_size(v17, &v163, &v161);
    if ( (packed_de_auth_size & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to calculate the packed size for a De-Authentication (0x%08x)",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "lim_send_deauth_mgmt_frame",
        packed_de_auth_size);
      v161 = 6;
    }
    else if ( packed_de_auth_size )
    {
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: There were warnings while calculating the packed size for a De-Authentication (0x%08x)",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "lim_send_deauth_mgmt_frame");
    }
    v29 = v161;
    if ( (unsigned int)cds_packet_alloc((unsigned __int16)v161 + 24, &v162, &v160) )
    {
      result = qdf_trace_msg(
                 0x35u,
                 2u,
                 "%s: Failed to allocate %d bytes for a De-Authentication",
                 v30,
                 v31,
                 v32,
                 v33,
                 v34,
                 v35,
                 v36,
                 v37,
                 "lim_send_deauth_mgmt_frame",
                 v29 + 24);
      if ( (a5 & 1) == 0 )
        goto LABEL_28;
      goto LABEL_27;
    }
    qdf_mem_set(v162, v29 + 24, 0);
    v38 = v162;
    v39 = v162 + 4;
    *v162 = -64;
    qdf_mem_copy(v39, a3, 6u);
    v38[10] = *(_BYTE *)(a4 + 30);
    v38[11] = *(_BYTE *)(a4 + 31);
    v38[12] = *(_BYTE *)(a4 + 32);
    v38[13] = *(_BYTE *)(a4 + 33);
    v38[14] = *(_BYTE *)(a4 + 34);
    v38[15] = *(_BYTE *)(a4 + 35);
    qdf_mem_copy(v38 + 16, a3, 6u);
    v48 = *(unsigned __int16 *)(v17 + 21532);
    if ( v48 <= 0xFFE )
      v49 = v48 + 1;
    else
      v49 = 2048;
    *(_WORD *)(v17 + 21532) = v49;
    *((_WORD *)v38 + 11) = (16 * (v49 & 0xF)) | *((_WORD *)v38 + 11) & 0xFF0F;
    v50 = (unsigned __int8)(*(_WORD *)(v17 + 21532) >> 4);
    *((_WORD *)v38 + 11) = (16 * *(_WORD *)(v17 + 21532)) & 0xFF00 | (16 * (v49 & 0xF));
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
      *(unsigned __int16 *)(v17 + 21532),
      0);
    v51 = v162;
    v52 = v162;
    v162[16] = *(_BYTE *)(a4 + 24);
    v51[17] = *(_BYTE *)(a4 + 25);
    v51[18] = *(_BYTE *)(a4 + 26);
    v51[19] = *(_BYTE *)(a4 + 27);
    v51[20] = *(_BYTE *)(a4 + 28);
    v51[21] = *(_BYTE *)(a4 + 29);
    lim_set_protected_bit(v17, a4, a3, v52);
    v53 = dot11f_pack_de_auth(v17, &v163, v162 + 24, v161, &v161);
    if ( (v53 & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to pack a DeAuthentication (0x%08x)",
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        "lim_send_deauth_mgmt_frame",
        v53);
      result = cds_packet_free(v160);
      if ( (a5 & 1) != 0 )
LABEL_27:
        result = lim_send_deauth_cnf((_QWORD *)v17, *(unsigned __int8 *)(a4 + 10));
    }
    else
    {
      if ( v53 )
        qdf_trace_msg(
          0x35u,
          3u,
          "%s: There were warnings while packing a De-Authentication (0x%08x)",
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          "lim_send_deauth_mgmt_frame");
      v62 = jiffies;
      if ( lim_send_deauth_mgmt_frame___last_ticks - jiffies + 125 < 0 )
      {
        if ( v51 == (char *)-4LL )
        {
          v65 = 0;
          v63 = 0;
          v64 = 0;
          v66 = 0;
        }
        else
        {
          v63 = (unsigned __int8)v51[4];
          v64 = (unsigned __int8)v51[5];
          v65 = (unsigned __int8)v51[6];
          v66 = (unsigned __int8)v51[9];
        }
        qdf_trace_msg(
          0x35u,
          4u,
          "Deauth TX: vdev %d seq_num %d reason %u waitForAck %d to %02x:%02x:%02x:**:**:%02x from %02x:%02x:%02x:**:**:%02x",
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          *(unsigned __int8 *)(a4 + 10),
          *(unsigned __int16 *)(v17 + 21532),
          (unsigned __int16)a2,
          a5 & 1,
          v63,
          v64,
          v65,
          v66,
          *(unsigned __int8 *)(a4 + 30),
          *(unsigned __int8 *)(a4 + 31),
          *(unsigned __int8 *)(a4 + 32),
          *(unsigned __int8 *)(a4 + 35));
        lim_send_deauth_mgmt_frame___last_ticks = v62;
      }
      if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a4 + 284)) && (*(_DWORD *)(a4 + 7036) & 0xFFFFFFFE) != 2 )
        v75 = 0x80;
      else
        v75 = -64;
      v157 = v75;
      v76 = dph_lookup_hash_entry(v67, v68, v69, v70, v71, v72, v73, v74, v17, (unsigned __int8 *)a3, v158, a4 + 360);
      *(_WORD *)(a4 + 10012) = a2;
      v77 = v76;
      qdf_trace(53, 2u, *(_WORD *)(a4 + 8), (unsigned __int8)*(_WORD *)v51 >> 4);
      if ( (a5 & 1) != 0 )
      {
        v78 = lim_diag_mgmt_tx_event_report(v17, v51, a4, 0, 0);
        if ( !*(_DWORD *)(a4 + 7036) && *(_BYTE *)(*(_QWORD *)(v17 + 8) + 3330LL) && !*(_BYTE *)(a4 + 9790) )
        {
          *(_BYTE *)(a4 + 9790) = *(_BYTE *)(*(_QWORD *)(v17 + 8) + 3330LL);
          *(_WORD *)(a4 + 9788) = a2;
          qdf_mem_copy((void *)(a4 + 9782), a3, 6u);
        }
        context = _cds_get_context(54, (__int64)"lim_send_deauth_mgmt_frame", v78, v79, v80, v81, v82, v83, v84, v85);
        LOBYTE(v153) = v19;
        LOBYTE(v156) = 0;
        LOWORD(v155) = 0;
        LOBYTE(v152[0]) = v157;
        LOBYTE(v154) = 0;
        v87 = wma_tx_packet(
                context,
                v160,
                v29 + 24,
                3,
                1,
                7,
                lim_tx_complete,
                v162,
                lim_deauth_tx_complete_cnf_handler,
                *(_DWORD *)v152,
                v153,
                v154,
                v155,
                12,
                v156,
                0);
        qdf_trace(53, 5u, *(_WORD *)(a4 + 8), v87);
        if ( v87 )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Failed to send De-Authentication (%X)!",
            v88,
            v89,
            v90,
            v91,
            v92,
            v93,
            v94,
            v95,
            "lim_send_deauth_mgmt_frame",
            v87);
          result = lim_process_deauth_ack_timeout(
                     v17,
                     *(unsigned __int16 *)(a4 + 8),
                     v96,
                     v97,
                     v98,
                     v99,
                     v100,
                     v101,
                     v102,
                     v103);
          goto LABEL_28;
        }
        if ( (unsigned int)tx_timer_change_context(v17 + 2664, *(unsigned __int8 *)(a4 + 10)) )
        {
          v143 = "%s: Unable to update the vdev id in the Deauth ack timer";
LABEL_52:
          result = qdf_trace_msg(
                     0x35u,
                     2u,
                     v143,
                     v135,
                     v136,
                     v137,
                     v138,
                     v139,
                     v140,
                     v141,
                     v142,
                     "lim_send_deauth_mgmt_frame");
          goto LABEL_28;
        }
        if ( (unsigned int)tx_timer_change(v17 + 2664, 50, 0) )
        {
          v143 = "%s: Unable to change Deauth ack Timer val";
          goto LABEL_52;
        }
        result = tx_timer_activate((char *)(v17 + 2664));
        if ( (_DWORD)result )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Unable to activate Deauth ack Timer",
            v144,
            v145,
            v146,
            v147,
            v148,
            v149,
            v150,
            v151,
            "lim_send_deauth_mgmt_frame");
          result = lim_deactivate_and_change_timer(v17, 17);
        }
      }
      else
      {
        if ( v77 && *(_BYTE *)(v77 + 344) == 4 )
        {
          v104 = lim_diag_mgmt_tx_event_report(v17, v51, a4, 0, 0);
          v112 = _cds_get_context(
                   54,
                   (__int64)"lim_send_deauth_mgmt_frame",
                   v104,
                   v105,
                   v106,
                   v107,
                   v108,
                   v109,
                   v110,
                   v111);
          v113 = v160;
          v114 = v162;
          v115 = 0;
          LOBYTE(v153) = v19;
          v116 = v157;
          v117 = v29 + 24;
          LOBYTE(v156) = 0;
        }
        else
        {
          lim_diag_mgmt_tx_event_report(v17, v51, a4, 0, 0);
          wlan_get_rssi_by_bssid(*(_QWORD *)(v17 + 21560), v51 + 16, &v159);
          wlan_connectivity_mgmt_event(
            *(_QWORD *)(v17 + 21552),
            (int)v51,
            *(unsigned __int8 *)(a4 + 10),
            a2,
            1,
            v159,
            0,
            0,
            0,
            0,
            9);
          lim_cp_stats_cstats_log_deauth_evt(a4, 0, a2);
          v112 = _cds_get_context(
                   54,
                   (__int64)"lim_send_deauth_mgmt_frame",
                   v118,
                   v119,
                   v120,
                   v121,
                   v122,
                   v123,
                   v124,
                   v125);
          v113 = v160;
          v114 = v162;
          v117 = v29 + 24;
          LOBYTE(v153) = v19;
          v116 = v157;
          v115 = 1;
          LOBYTE(v156) = 0;
        }
        LOWORD(v155) = 0;
        LOBYTE(v154) = 0;
        LOBYTE(v152[0]) = v116;
        v126 = wma_tx_packet(
                 v112,
                 v113,
                 v117,
                 3,
                 v115,
                 7,
                 lim_tx_complete,
                 v114,
                 0,
                 *(_DWORD *)v152,
                 v153,
                 v154,
                 v155,
                 12,
                 v156,
                 0);
        result = qdf_trace(53, 5u, *(_WORD *)(a4 + 8), v126);
        if ( v126 )
          result = qdf_trace_msg(
                     0x35u,
                     2u,
                     "%s: Failed to send De-Authentication (%X)!",
                     v127,
                     v128,
                     v129,
                     v130,
                     v131,
                     v132,
                     v133,
                     v134,
                     "lim_send_deauth_mgmt_frame",
                     v126);
      }
    }
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
