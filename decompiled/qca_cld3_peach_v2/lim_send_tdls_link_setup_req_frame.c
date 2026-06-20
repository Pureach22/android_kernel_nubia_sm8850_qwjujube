__int64 __fastcall lim_send_tdls_link_setup_req_frame(
        __int64 a1,
        __int64 a2,
        char a3,
        __int64 a4,
        const void *a5,
        unsigned __int16 a6,
        int a7)
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
  __int64 v23; // x22
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned __int8 v48; // w0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  _BYTE *v65; // x23
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  char v74; // w8
  int v75; // w9
  unsigned int v76; // w9
  unsigned int v77; // w9
  char v78; // w11
  const char *v79; // x2
  __int64 result; // x0
  char v81; // w8
  char v82; // w8
  char v83; // w8
  char v84; // w8
  unsigned int v85; // w26
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  unsigned int v102; // w26
  const void *v103; // x27
  unsigned int v104; // w28
  char tdls_chan_switch_prohibited; // w0
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  unsigned int packed_tdls_setup_req_size; // w0
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  int v123; // w9
  char v124; // w8
  int v125; // w23
  double v126; // d0
  double v127; // d1
  double v128; // d2
  double v129; // d3
  double v130; // d4
  double v131; // d5
  double v132; // d6
  double v133; // d7
  __int64 v134; // x5
  int v135; // w25
  double v136; // d0
  double v137; // d1
  double v138; // d2
  double v139; // d3
  double v140; // d4
  double v141; // d5
  double v142; // d6
  double v143; // d7
  unsigned int v144; // w0
  double v145; // d0
  double v146; // d1
  double v147; // d2
  double v148; // d3
  double v149; // d4
  double v150; // d5
  double v151; // d6
  double v152; // d7
  double v153; // d0
  double v154; // d1
  double v155; // d2
  double v156; // d3
  double v157; // d4
  double v158; // d5
  double v159; // d6
  double v160; // d7
  unsigned __int8 *v161; // x22
  double v162; // d0
  double v163; // d1
  double v164; // d2
  double v165; // d3
  double v166; // d4
  double v167; // d5
  double v168; // d6
  double v169; // d7
  double v170; // d0
  double v171; // d1
  double v172; // d2
  double v173; // d3
  double v174; // d4
  double v175; // d5
  double v176; // d6
  double v177; // d7
  __int64 assoc_link_vdev; // x0
  unsigned __int8 v179; // w22
  _QWORD *v180; // x20
  char *v181; // x21
  double v182; // d0
  double v183; // d1
  double v184; // d2
  double v185; // d3
  double v186; // d4
  double v187; // d5
  double v188; // d6
  double v189; // d7
  _QWORD *context; // x0
  double v191; // d0
  double v192; // d1
  double v193; // d2
  double v194; // d3
  double v195; // d4
  double v196; // d5
  double v197; // d6
  double v198; // d7
  const void *v199; // [xsp+40h] [xbp-30h]
  int v200; // [xsp+48h] [xbp-28h]
  _BYTE v201[4]; // [xsp+4Ch] [xbp-24h] BYREF
  _QWORD *v202; // [xsp+50h] [xbp-20h] BYREF
  char *v203; // [xsp+58h] [xbp-18h] BYREF
  unsigned int v204; // [xsp+60h] [xbp-10h] BYREF
  unsigned __int16 v205; // [xsp+64h] [xbp-Ch] BYREF
  __int64 v206; // [xsp+68h] [xbp-8h]

  v206 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v205 = 0;
  v204 = 0;
  v202 = nullptr;
  v203 = nullptr;
  v201[0] = 0;
  v14 = _qdf_mem_malloc(0x3D8u, "lim_send_tdls_link_setup_req_frame", 2035);
  if ( !v14 )
  {
    v79 = "%s: memory allocation failed for SetupReq";
LABEL_9:
    result = qdf_trace_msg(0x35u, 2u, v79, v15, v16, v17, v18, v19, v20, v21, v22, "lim_send_tdls_link_setup_req_frame");
    goto LABEL_59;
  }
  v23 = v14;
  *(_BYTE *)(v14 + 2) = a3;
  *(_WORD *)v14 = 12;
  v200 = a7;
  v24 = populate_dot11f_link_iden(a4, v14 + 878, a2 & 0xFFFFFFFFFFFFLL, 0);
  if ( (unsigned int)lim_get_capability_info(a1, (__int16 *)&v205, a4, v24, v25, v26, v27, v28, v29, v30, v31) )
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: could not retrieve Capabilities value",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "lim_send_tdls_link_setup_req_frame");
  swap_bit_field16(v205, (_WORD *)(v23 + 4));
  v48 = wlan_reg_freq_to_chan(*(_QWORD *)(a1 + 21632), *(_DWORD *)(a4 + 284), v40, v41, v42, v43, v44, v45, v46, v47);
  if ( (unsigned int)populate_dot11f_rates_tdls(
                       a1,
                       (_BYTE *)(v23 + 6),
                       (_BYTE *)(v23 + 268),
                       v48,
                       v49,
                       v50,
                       v51,
                       v52,
                       v53,
                       v54,
                       v55,
                       v56) == 16 )
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: could not populate supported data rates",
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      "lim_send_tdls_link_setup_req_frame");
  v65 = (_BYTE *)(a4 + 7024);
  populate_dot11f_tdls_ext_capability(a1, a4, v23 + 526);
  if ( *(_BYTE *)(a1 + 11370) == 1 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: populate WMM IE in Setup Request Frame",
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      "lim_send_tdls_link_setup_req_frame");
    v74 = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 5670LL);
    *(_BYTE *)(v23 + 898) = 1;
    v75 = *(_BYTE *)(v23 + 899) & 0xFE | *(_BYTE *)(a1 + 11368) & 1;
    *(_BYTE *)(v23 + 899) = v75;
    v76 = v75 & 0xFFFFFFFD | (2 * ((*(unsigned __int8 *)(a1 + 11368) >> 1) & 1));
    *(_BYTE *)(v23 + 899) = v76;
    v77 = v76 & 0xFFFFFFFB | (4 * ((*(unsigned __int8 *)(a1 + 11368) >> 2) & 1));
    *(_BYTE *)(v23 + 899) = v77;
    v78 = *(_BYTE *)(a1 + 11368);
    *(_BYTE *)(v23 + 897) = 1;
    *(_BYTE *)(v23 + 899) = v78 & 8 | (32 * (v74 & 3)) | v77 & 0x97;
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: populate QOS IE in Setup Request Frame",
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      "lim_send_tdls_link_setup_req_frame");
    v81 = *(_BYTE *)(v23 + 578);
    *(_BYTE *)(v23 + 577) = 1;
    *(_BYTE *)(v23 + 578) = v81 & 0x8F;
    v82 = *(_BYTE *)(a1 + 11368) & 8 | v81 & 0x87;
    *(_BYTE *)(v23 + 578) = v82;
    v83 = v82 & 0xFB | *(_BYTE *)(a1 + 11368) & 4;
    *(_BYTE *)(v23 + 578) = v83;
    v84 = v83 & 0xFD | *(_BYTE *)(a1 + 11368) & 2;
    *(_BYTE *)(v23 + 578) = v84;
    *(_BYTE *)(v23 + 578) = v84 & 0xFE | *(_BYTE *)(a1 + 11368) & 1;
  }
  v85 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 5964LL);
  populate_dot11f_tdls_ht_vht_cap(a1, v85, v23 + 816, v23 + 904, a4);
  populate_dot11f_set_tdls_he_cap(a1, v85, v23 + 920);
  v86 = populate_dotf_tdls_vht_aid(a1, v85, a2 & 0xFFFFFFFFFFFFLL, v23 + 900, a4);
  if ( (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(a4 + 16), v86, v87, v88, v89, v90, v91, v92, v93) & 1) != 0 )
    v102 = lim_send_tdls_mgmt_frame_mlo(a1, a4);
  else
    v102 = 0;
  if ( *(_BYTE *)(a4 + 10071) == 1 )
  {
    v103 = (const void *)lim_ieee80211_pack_ehtcap_tdls(a1, a4, v201);
    if ( !v103 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: malloc failed for eht_cap_ie",
        v94,
        v95,
        v96,
        v97,
        v98,
        v99,
        v100,
        v101,
        "lim_send_tdls_link_setup_req_frame");
LABEL_58:
      result = _qdf_mem_free(v23);
      goto LABEL_59;
    }
  }
  else
  {
    v103 = nullptr;
  }
  v199 = a5;
  v104 = *(unsigned __int8 *)(a1 + 11369);
  if ( v104 != 1 )
    goto LABEL_21;
  if ( (mlme_get_tdls_chan_switch_prohibited(*(_QWORD *)(a4 + 16), v94, v95, v96, v97, v98, v99, v100, v101) & 1) != 0 )
  {
    v104 = *(unsigned __int8 *)(a1 + 11369);
LABEL_21:
    tdls_chan_switch_prohibited = mlme_get_tdls_chan_switch_prohibited(
                                    *(_QWORD *)(a4 + 16),
                                    v94,
                                    v95,
                                    v96,
                                    v97,
                                    v98,
                                    v99,
                                    v100,
                                    v101);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: TDLS offchan not enabled, or channel switch prohibited by AP, gLimTDLSOffChannelEnabled: %d tdls_chan_swit_prohibited: %d",
      v106,
      v107,
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      "lim_send_tdls_link_setup_req_frame",
      v104,
      tdls_chan_switch_prohibited & 1);
    goto LABEL_22;
  }
  populate_dot11f_tdls_offchannel_params(a1, a4, v23 + 282, v23 + 543);
  if ( *(_DWORD *)(*(_QWORD *)(a1 + 8) + 1032LL) != 1 )
  {
    v124 = *(_BYTE *)(v23 + 877);
    *(_BYTE *)(v23 + 876) = 1;
    *(_BYTE *)(v23 + 877) = v124 | 1;
  }
LABEL_22:
  packed_tdls_setup_req_size = dot11f_get_packed_tdls_setup_req_size(a1, v23, (int *)&v204);
  if ( (packed_tdls_setup_req_size & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to calculate the packed size for a Setup Request (0x%08x)",
      v115,
      v116,
      v117,
      v118,
      v119,
      v120,
      v121,
      v122,
      "lim_send_tdls_link_setup_req_frame",
      packed_tdls_setup_req_size);
    v204 = 1160;
  }
  else if ( packed_tdls_setup_req_size )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while calculating the packed size for a Setup Request (0x%08x)",
      v115,
      v116,
      v117,
      v118,
      v119,
      v120,
      v121,
      v122,
      "lim_send_tdls_link_setup_req_frame");
  }
  if ( (*v65 & 1) != 0 && (*(_WORD *)(a4 + 176) & 0x200) != 0 )
  {
    v123 = 26;
  }
  else
  {
    v123 = 24;
    if ( (*v65 & 2) != 0 )
    {
      if ( (*(_BYTE *)(a4 + 178) & 2) != 0 )
        v123 = 26;
      else
        v123 = 24;
    }
  }
  v125 = a6 + (unsigned __int16)v102 + v204 + v123 + v201[0];
  if ( (unsigned int)cds_packet_alloc(
                       a6 + (unsigned __int16)v102 + (unsigned __int16)v204 + (unsigned __int16)v123 + v201[0] + 9,
                       &v203,
                       &v202) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to allocate %d bytes for a TDLS Setup Request",
      v126,
      v127,
      v128,
      v129,
      v130,
      v131,
      v132,
      v133,
      "lim_send_tdls_link_setup_req_frame",
      (unsigned int)(v125 + 9));
LABEL_57:
    _qdf_mem_free((__int64)v103);
    goto LABEL_58;
  }
  qdf_mem_set(v203, (unsigned int)(v125 + 9), 0);
  if ( v200 == 1 )
    v134 = 4;
  else
    v134 = 1;
  v135 = lim_prepare_tdls_frame_header(a1, v203, v23 + 878, 0, 0, v134, a4);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: SupportedChnlWidth: %x rxMCSMap: %x rxMCSMap: %x txSupDataRate: %x",
    v136,
    v137,
    v138,
    v139,
    v140,
    v141,
    v142,
    v143,
    "lim_send_tdls_link_setup_req_frame",
    (*(unsigned __int16 *)(v23 + 905) >> 2) & 3,
    *(unsigned __int16 *)(v23 + 910),
    *(unsigned __int16 *)(v23 + 914),
    *(_WORD *)(v23 + 916) & 0x1FFF);
  v144 = dot11f_pack_tdls_setup_req(a1, v23, &v203[v135], v204, &v204);
  if ( (v144 & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to pack a TDLS Setup request (0x%08x)",
      v145,
      v146,
      v147,
      v148,
      v149,
      v150,
      v151,
      v152,
      "lim_send_tdls_link_setup_req_frame",
      v144);
    cds_packet_free((__int64)v202);
    goto LABEL_57;
  }
  if ( v144 )
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while packing TDLS Setup Request (0x%08x)",
      v145,
      v146,
      v147,
      v148,
      v149,
      v150,
      v151,
      v152,
      "lim_send_tdls_link_setup_req_frame");
  lim_cp_stats_cstats_log_setup_req_evt((char *)v23, a4);
  _qdf_mem_free(v23);
  if ( a6 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Copy Additional Ie Len = %d",
      v153,
      v154,
      v155,
      v156,
      v157,
      v158,
      v159,
      v160,
      "lim_send_tdls_link_setup_req_frame",
      a6);
    qdf_mem_copy(&v203[v204 + v135], v199, a6);
    v204 += a6;
  }
  if ( v201[0] )
  {
    qdf_mem_copy(&v203[v204 + v135], v103, v201[0]);
    _qdf_mem_free((__int64)v103);
    v204 += v201[0];
  }
  v161 = (unsigned __int8 *)(a4 + 10);
  if ( (_WORD)v102 )
  {
    if ( (unsigned int)lim_fill_complete_mlo_ie(a4, v102, &v203[v204 + v135]) )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: assemble ml ie error",
        v153,
        v154,
        v155,
        v156,
        v157,
        v158,
        v159,
        v160,
        "lim_send_tdls_link_setup_req_frame");
      LOWORD(v102) = 0;
    }
    v204 += (unsigned __int16)v102;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: [TDLS] action: %d (%s) -AP-> OTA peer=%02x:%02x:%02x:**:**:%02x",
    v153,
    v154,
    v155,
    v156,
    v157,
    v158,
    v159,
    v160,
    "lim_send_tdls_link_setup_req_frame",
    0,
    "TDLS_SETUP_REQUEST",
    (unsigned __int8)a2,
    BYTE1(a2),
    BYTE2(a2),
    BYTE5(a2));
  *(_DWORD *)(a1 + 12368) = *(unsigned __int8 *)(a4 + 10);
  if ( (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(a4 + 16), v162, v163, v164, v165, v166, v167, v168, v169) & 1) != 0 )
  {
    assoc_link_vdev = wlan_mlo_get_assoc_link_vdev(*(_QWORD *)(a4 + 16));
    if ( assoc_link_vdev )
      v161 = (unsigned __int8 *)(assoc_link_vdev + 168);
  }
  v179 = *v161;
  lim_diag_mgmt_tx_event_report(a1, (unsigned __int8 *)v203, a4, 0, 0, v170, v171, v172, v173, v174, v175, v176, v177);
  v180 = v202;
  v181 = v203;
  context = _cds_get_context(
              54,
              (__int64)"wma_tx_frame_with_tx_complete_send",
              v182,
              v183,
              v184,
              v185,
              v186,
              v187,
              v188,
              v189);
  result = wma_tx_packet(
             (__int64)context,
             v180,
             (unsigned __int16)v125 + 9,
             5u,
             v191,
             v192,
             v193,
             v194,
             v195,
             v196,
             v197,
             v198,
             1,
             4,
             lim_tx_complete,
             v181,
             (__int64)lim_mgmt_tdls_tx_complete,
             192,
             v179,
             0,
             0,
             0xCu,
             0,
             0);
  if ( (_DWORD)result )
  {
    v79 = "%s: could not send TDLS Setup Request frame!";
    *(_DWORD *)(a1 + 12368) = 255;
    goto LABEL_9;
  }
LABEL_59:
  _ReadStatusReg(SP_EL0);
  return result;
}
