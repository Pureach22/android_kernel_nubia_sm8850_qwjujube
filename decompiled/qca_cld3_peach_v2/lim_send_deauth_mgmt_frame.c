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
  void *v18; // x26
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  char v27; // w24
  unsigned int packed_de_auth_size; // w0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w28
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  char *v46; // x23
  char *v47; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  unsigned int v56; // w8
  __int16 v57; // w8
  __int64 v58; // x5
  char *v59; // x23
  unsigned __int8 *v60; // x25
  char *v61; // x3
  unsigned int v62; // w0
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v71; // x26
  __int64 v72; // x7
  int v73; // w8
  int v74; // w9
  int v75; // w10
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  char v84; // w8
  __int64 v85; // x0
  __int64 v86; // x26
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  _QWORD *context; // x0
  unsigned int v96; // w21
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  _QWORD *v121; // x0
  __int64 v122; // x1
  char *v123; // x7
  __int64 v124; // x4
  char v125; // w8
  __int64 v126; // x2
  double v127; // d0
  double v128; // d1
  double v129; // d2
  double v130; // d3
  double v131; // d4
  double v132; // d5
  double v133; // d6
  double v134; // d7
  unsigned int v135; // w20
  double v136; // d0
  double v137; // d1
  double v138; // d2
  double v139; // d3
  double v140; // d4
  double v141; // d5
  double v142; // d6
  double v143; // d7
  double v144; // d0
  double v145; // d1
  double v146; // d2
  double v147; // d3
  double v148; // d4
  double v149; // d5
  double v150; // d6
  double v151; // d7
  const char *v152; // x2
  double v153; // d0
  double v154; // d1
  double v155; // d2
  double v156; // d3
  double v157; // d4
  double v158; // d5
  double v159; // d6
  double v160; // d7
  __int16 v161[2]; // [xsp+8h] [xbp-78h]
  int v162; // [xsp+10h] [xbp-70h]
  int v163; // [xsp+18h] [xbp-68h]
  int v164; // [xsp+20h] [xbp-60h]
  int v165; // [xsp+30h] [xbp-50h]
  char v166; // [xsp+48h] [xbp-38h]
  __int16 v167[2]; // [xsp+50h] [xbp-30h] BYREF
  int v168; // [xsp+54h] [xbp-2Ch] BYREF
  __int64 v169; // [xsp+58h] [xbp-28h] BYREF
  unsigned int v170; // [xsp+64h] [xbp-1Ch] BYREF
  char *v171; // [xsp+68h] [xbp-18h] BYREF
  int v172; // [xsp+70h] [xbp-10h] BYREF
  __int16 v173; // [xsp+74h] [xbp-Ch]
  __int64 v174; // [xsp+78h] [xbp-8h]

  v174 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v168 = 0;
  if ( !a4 )
    goto LABEL_30;
  v13 = *(_DWORD *)(a4 + 7036);
  v17 = result;
  v173 = 0;
  v172 = 0;
  v171 = nullptr;
  v170 = 0;
  v169 = 0;
  v167[0] = 0;
  if ( (v13 | 2) == 3 )
  {
    if ( *(_BYTE *)(result + 14881) )
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
          goto LABEL_30;
        goto LABEL_29;
      }
      goto LABEL_13;
    }
    v18 = a3;
    if ( (_WORD)a2 == 0xFFFF )
    {
LABEL_13:
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
        goto LABEL_30;
      goto LABEL_29;
    }
  }
  else
  {
    v18 = a3;
    if ( (lim_is_ml_peer_state_disconn(result, a4) & 1) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Deauth tx not required for vdev id %d",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "lim_send_deauth_mgmt_frame",
        *(unsigned __int8 *)(a4 + 10));
      goto LABEL_29;
    }
  }
  v27 = *(_BYTE *)(a4 + 10);
  qdf_mem_set(&v172, 6u, 0);
  LOWORD(v172) = a2;
  packed_de_auth_size = dot11f_get_packed_de_auth_size(v17, &v172, &v170);
  if ( (packed_de_auth_size & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to calculate the packed size for a De-Authentication (0x%08x)",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "lim_send_deauth_mgmt_frame",
      packed_de_auth_size);
    v170 = 6;
  }
  else if ( packed_de_auth_size )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while calculating the packed size for a De-Authentication (0x%08x)",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "lim_send_deauth_mgmt_frame");
  }
  v37 = v170;
  if ( (unsigned int)cds_packet_alloc((unsigned __int16)v170 + 24, &v171, &v169) )
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Failed to allocate %d bytes for a De-Authentication",
               v38,
               v39,
               v40,
               v41,
               v42,
               v43,
               v44,
               v45,
               "lim_send_deauth_mgmt_frame",
               v37 + 24);
    if ( (a5 & 1) == 0 )
      goto LABEL_30;
    goto LABEL_29;
  }
  qdf_mem_set(v171, v37 + 24, 0);
  v46 = v171;
  v47 = v171 + 4;
  *v171 = -64;
  qdf_mem_copy(v47, v18, 6u);
  v46[10] = *(_BYTE *)(a4 + 30);
  v46[11] = *(_BYTE *)(a4 + 31);
  v46[12] = *(_BYTE *)(a4 + 32);
  v46[13] = *(_BYTE *)(a4 + 33);
  v46[14] = *(_BYTE *)(a4 + 34);
  v46[15] = *(_BYTE *)(a4 + 35);
  qdf_mem_copy(v46 + 16, v18, 6u);
  v56 = *(unsigned __int16 *)(v17 + 21604);
  if ( v56 <= 0xFFE )
    v57 = v56 + 1;
  else
    v57 = 2048;
  *(_WORD *)(v17 + 21604) = v57;
  *((_WORD *)v46 + 11) = (16 * (v57 & 0xF)) | *((_WORD *)v46 + 11) & 0xFF0F;
  v58 = (unsigned __int8)(*(_WORD *)(v17 + 21604) >> 4);
  *((_WORD *)v46 + 11) = (16 * *(_WORD *)(v17 + 21604)) & 0xFF00 | (16 * (v57 & 0xF));
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    "lim_populate_mac_header",
    v57 & 0xF,
    v58,
    *(unsigned __int16 *)(v17 + 21604),
    0);
  v59 = v171;
  v60 = (unsigned __int8 *)v18;
  v61 = v171;
  v171[16] = *(_BYTE *)(a4 + 24);
  v59[17] = *(_BYTE *)(a4 + 25);
  v59[18] = *(_BYTE *)(a4 + 26);
  v59[19] = *(_BYTE *)(a4 + 27);
  v59[20] = *(_BYTE *)(a4 + 28);
  v59[21] = *(_BYTE *)(a4 + 29);
  lim_set_protected_bit(v17, a4, v18, v61);
  v62 = dot11f_pack_de_auth(v17, &v172, v171 + 24, v170, &v170);
  if ( (v62 & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to pack a DeAuthentication (0x%08x)",
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      "lim_send_deauth_mgmt_frame",
      v62);
    result = cds_packet_free(v169);
    if ( (a5 & 1) == 0 )
      goto LABEL_30;
LABEL_29:
    result = lim_send_deauth_cnf((_QWORD *)v17, *(unsigned __int8 *)(a4 + 10));
    goto LABEL_30;
  }
  if ( v62 )
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while packing a De-Authentication (0x%08x)",
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      "lim_send_deauth_mgmt_frame");
  v71 = jiffies;
  if ( lim_send_deauth_mgmt_frame___last_ticks - jiffies + 125 < 0 )
  {
    if ( v59 == (char *)-4LL )
    {
      v74 = 0;
      v72 = 0;
      v73 = 0;
      v75 = 0;
    }
    else
    {
      v72 = (unsigned __int8)v59[4];
      v73 = (unsigned __int8)v59[5];
      v74 = (unsigned __int8)v59[6];
      v75 = (unsigned __int8)v59[9];
    }
    qdf_trace_msg(
      0x35u,
      4u,
      "Deauth TX: vdev %d seq_num %d reason %u waitForAck %d to %02x:%02x:%02x:**:**:%02x from %02x:%02x:%02x:**:**:%02x",
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      *(unsigned __int8 *)(a4 + 10),
      *(unsigned __int16 *)(v17 + 21604),
      (unsigned __int16)a2,
      a5 & 1,
      v72,
      v73,
      v74,
      v75,
      *(unsigned __int8 *)(a4 + 30),
      *(unsigned __int8 *)(a4 + 31),
      *(unsigned __int8 *)(a4 + 32),
      *(unsigned __int8 *)(a4 + 35));
    lim_send_deauth_mgmt_frame___last_ticks = v71;
  }
  if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a4 + 284)) && (*(_DWORD *)(a4 + 7036) & 0xFFFFFFFE) != 2 )
    v84 = 0x80;
  else
    v84 = -64;
  v166 = v84;
  v85 = dph_lookup_hash_entry(v76, v77, v78, v79, v80, v81, v82, v83, v17, v60, v167, a4 + 360);
  *(_WORD *)(a4 + 10012) = a2;
  v86 = v85;
  qdf_trace(53, 2u, *(_WORD *)(a4 + 8), (unsigned __int8)*(_WORD *)v59 >> 4);
  if ( (a5 & 1) != 0 )
  {
    v87 = lim_diag_mgmt_tx_event_report(v17, v59, a4, 0, 0);
    if ( !*(_DWORD *)(a4 + 7036) && *(_BYTE *)(*(_QWORD *)(v17 + 8) + 3530LL) && !*(_BYTE *)(a4 + 9790) )
    {
      *(_BYTE *)(a4 + 9790) = *(_BYTE *)(*(_QWORD *)(v17 + 8) + 3530LL);
      *(_WORD *)(a4 + 9788) = a2;
      qdf_mem_copy((void *)(a4 + 9782), v60, 6u);
    }
    context = _cds_get_context(54, (__int64)"lim_send_deauth_mgmt_frame", v87, v88, v89, v90, v91, v92, v93, v94);
    LOBYTE(v162) = v27;
    LOBYTE(v165) = 0;
    LOWORD(v164) = 0;
    LOBYTE(v161[0]) = v166;
    LOBYTE(v163) = 0;
    v96 = wma_tx_packet(
            context,
            v169,
            v37 + 24,
            3,
            1,
            7,
            lim_tx_complete,
            v171,
            lim_deauth_tx_complete_cnf_handler,
            *(_DWORD *)v161,
            v162,
            v163,
            v164,
            12,
            v165,
            0);
    qdf_trace(53, 5u, *(_WORD *)(a4 + 8), v96);
    if ( v96 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to send De-Authentication (%X)!",
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        "lim_send_deauth_mgmt_frame",
        v96);
      result = lim_process_deauth_ack_timeout(
                 v17,
                 *(unsigned __int16 *)(a4 + 8),
                 v105,
                 v106,
                 v107,
                 v108,
                 v109,
                 v110,
                 v111,
                 v112);
      goto LABEL_30;
    }
    if ( (unsigned int)tx_timer_change_context(v17 + 2664, *(unsigned __int8 *)(a4 + 10)) )
    {
      v152 = "%s: Unable to update the vdev id in the Deauth ack timer";
LABEL_54:
      result = qdf_trace_msg(
                 0x35u,
                 2u,
                 v152,
                 v144,
                 v145,
                 v146,
                 v147,
                 v148,
                 v149,
                 v150,
                 v151,
                 "lim_send_deauth_mgmt_frame");
      goto LABEL_30;
    }
    if ( (unsigned int)tx_timer_change(v17 + 2664, 50, 0) )
    {
      v152 = "%s: Unable to change Deauth ack Timer val";
      goto LABEL_54;
    }
    result = tx_timer_activate((char *)(v17 + 2664));
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Unable to activate Deauth ack Timer",
        v153,
        v154,
        v155,
        v156,
        v157,
        v158,
        v159,
        v160,
        "lim_send_deauth_mgmt_frame");
      result = lim_deactivate_and_change_timer(v17, 17);
    }
  }
  else
  {
    if ( v86 && *(_BYTE *)(v86 + 356) == 4 )
    {
      v113 = lim_diag_mgmt_tx_event_report(v17, v59, a4, 0, 0);
      v121 = _cds_get_context(54, (__int64)"lim_send_deauth_mgmt_frame", v113, v114, v115, v116, v117, v118, v119, v120);
      v122 = v169;
      v123 = v171;
      v124 = 0;
      LOBYTE(v162) = v27;
      v125 = v166;
      v126 = v37 + 24;
      LOBYTE(v165) = 0;
    }
    else
    {
      lim_diag_mgmt_tx_event_report(v17, v59, a4, 0, 0);
      wlan_get_rssi_by_bssid(*(_QWORD *)(v17 + 21632), v59 + 16, &v168);
      wlan_connectivity_mgmt_event(
        *(_QWORD *)(v17 + 21624),
        (int)v59,
        *(unsigned __int8 *)(a4 + 10),
        a2,
        1,
        v168,
        0,
        0,
        0,
        0,
        9);
      lim_cp_stats_cstats_log_deauth_evt(a4, 0, a2);
      v121 = _cds_get_context(54, (__int64)"lim_send_deauth_mgmt_frame", v127, v128, v129, v130, v131, v132, v133, v134);
      v122 = v169;
      v123 = v171;
      v126 = v37 + 24;
      LOBYTE(v162) = v27;
      v125 = v166;
      v124 = 1;
      LOBYTE(v165) = 0;
    }
    LOWORD(v164) = 0;
    LOBYTE(v163) = 0;
    LOBYTE(v161[0]) = v125;
    v135 = wma_tx_packet(
             v121,
             v122,
             v126,
             3,
             v124,
             7,
             lim_tx_complete,
             v123,
             0,
             *(_DWORD *)v161,
             v162,
             v163,
             v164,
             12,
             v165,
             0);
    result = qdf_trace(53, 5u, *(_WORD *)(a4 + 8), v135);
    if ( v135 )
      result = qdf_trace_msg(
                 0x35u,
                 2u,
                 "%s: Failed to send De-Authentication (%X)!",
                 v136,
                 v137,
                 v138,
                 v139,
                 v140,
                 v141,
                 v142,
                 v143,
                 "lim_send_deauth_mgmt_frame",
                 v135);
  }
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
