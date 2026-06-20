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
  __int64 v23; // x23
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
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  char v73; // w8
  int v74; // w9
  unsigned int v75; // w9
  unsigned int v76; // w9
  char v77; // w11
  const char *v78; // x2
  __int64 result; // x0
  char v80; // w8
  char v81; // w8
  char v82; // w8
  char v83; // w8
  unsigned int v84; // w26
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  unsigned int v93; // w26
  char tdls_chan_switch_prohibited; // w0
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  unsigned int packed_tdls_setup_req_size; // w0
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  int v112; // w9
  char v113; // w8
  unsigned int v114; // w27
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  __int64 v123; // x5
  int v124; // w25
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  unsigned int v133; // w0
  double v134; // d0
  double v135; // d1
  double v136; // d2
  double v137; // d3
  double v138; // d4
  double v139; // d5
  double v140; // d6
  double v141; // d7
  double v142; // d0
  double v143; // d1
  double v144; // d2
  double v145; // d3
  double v146; // d4
  double v147; // d5
  double v148; // d6
  double v149; // d7
  unsigned __int8 *v150; // x1
  unsigned __int8 v151; // w22
  double v152; // d0
  double v153; // d1
  double v154; // d2
  double v155; // d3
  double v156; // d4
  double v157; // d5
  double v158; // d6
  double v159; // d7
  _QWORD *v160; // x20
  char *v161; // x21
  double v162; // d0
  double v163; // d1
  double v164; // d2
  double v165; // d3
  double v166; // d4
  double v167; // d5
  double v168; // d6
  double v169; // d7
  _QWORD *context; // x0
  double v171; // d0
  double v172; // d1
  double v173; // d2
  double v174; // d3
  double v175; // d4
  double v176; // d5
  double v177; // d6
  double v178; // d7
  _QWORD *v179; // [xsp+58h] [xbp-28h] BYREF
  char *v180; // [xsp+60h] [xbp-20h] BYREF
  unsigned int v181; // [xsp+68h] [xbp-18h] BYREF
  unsigned __int16 v182; // [xsp+6Ch] [xbp-14h] BYREF
  int v183; // [xsp+70h] [xbp-10h] BYREF
  __int16 v184; // [xsp+74h] [xbp-Ch]
  __int64 v185; // [xsp+78h] [xbp-8h]

  v185 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v182 = 0;
  v181 = 0;
  v179 = nullptr;
  v180 = nullptr;
  v14 = _qdf_mem_malloc(0x3D8u, "lim_send_tdls_link_setup_req_frame", 2035);
  if ( !v14 )
  {
    v78 = "%s: memory allocation failed for SetupReq";
LABEL_9:
    result = qdf_trace_msg(0x35u, 2u, v78, v15, v16, v17, v18, v19, v20, v21, v22, "lim_send_tdls_link_setup_req_frame");
    goto LABEL_42;
  }
  v23 = v14;
  *(_BYTE *)(v14 + 2) = a3;
  *(_WORD *)v14 = 12;
  v184 = WORD2(a2);
  v183 = a2;
  qdf_mem_copy((void *)(v14 + 879), (const void *)(a4 + 24), 6u);
  qdf_mem_copy((void *)(v23 + 885), (const void *)(a4 + 30), 6u);
  qdf_mem_copy((void *)(v23 + 891), &v183, 6u);
  *(_BYTE *)(v23 + 878) = 1;
  if ( (unsigned int)lim_get_capability_info(a1, (__int16 *)&v182, a4, v24, v25, v26, v27, v28, v29, v30, v31) )
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
  swap_bit_field16(v182, (_WORD *)(v23 + 4));
  v48 = wlan_reg_freq_to_chan(*(_QWORD *)(a1 + 21560), *(_DWORD *)(a4 + 284), v40, v41, v42, v43, v44, v45, v46, v47);
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
  populate_dot11f_tdls_ext_capability(a1, a4, v23 + 526);
  if ( *(_BYTE *)(a1 + 11370) == 1 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: populate WMM IE in Setup Request Frame",
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      "lim_send_tdls_link_setup_req_frame");
    v73 = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 5454LL);
    *(_BYTE *)(v23 + 898) = 1;
    v74 = *(_BYTE *)(v23 + 899) & 0xFE | *(_BYTE *)(a1 + 11368) & 1;
    *(_BYTE *)(v23 + 899) = v74;
    v75 = v74 & 0xFFFFFFFD | (2 * ((*(unsigned __int8 *)(a1 + 11368) >> 1) & 1));
    *(_BYTE *)(v23 + 899) = v75;
    v76 = v75 & 0xFFFFFFFB | (4 * ((*(unsigned __int8 *)(a1 + 11368) >> 2) & 1));
    *(_BYTE *)(v23 + 899) = v76;
    v77 = *(_BYTE *)(a1 + 11368);
    *(_BYTE *)(v23 + 897) = 1;
    *(_BYTE *)(v23 + 899) = v77 & 8 | (32 * (v73 & 3)) | v76 & 0x97;
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: populate QOS IE in Setup Request Frame",
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      "lim_send_tdls_link_setup_req_frame");
    v80 = *(_BYTE *)(v23 + 578);
    *(_BYTE *)(v23 + 577) = 1;
    *(_BYTE *)(v23 + 578) = v80 & 0x8F;
    v81 = *(_BYTE *)(a1 + 11368) & 8 | v80 & 0x87;
    *(_BYTE *)(v23 + 578) = v81;
    v82 = v81 & 0xFB | *(_BYTE *)(a1 + 11368) & 4;
    *(_BYTE *)(v23 + 578) = v82;
    v83 = v82 & 0xFD | *(_BYTE *)(a1 + 11368) & 2;
    *(_BYTE *)(v23 + 578) = v83;
    *(_BYTE *)(v23 + 578) = v83 & 0xFE | *(_BYTE *)(a1 + 11368) & 1;
  }
  v84 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 5748LL);
  populate_dot11f_tdls_ht_vht_cap(a1, v84, v23 + 816, v23 + 904, a4);
  populate_dot11f_set_tdls_he_cap(a1, v84, v23 + 920);
  populate_dotf_tdls_vht_aid(a1, v84, a2 & 0xFFFFFFFFFFFFLL, v23 + 900, a4);
  v93 = *(unsigned __int8 *)(a1 + 11369);
  if ( v93 != 1 )
    goto LABEL_14;
  if ( (mlme_get_tdls_chan_switch_prohibited(*(_QWORD *)(a4 + 16), v85, v86, v87, v88, v89, v90, v91, v92) & 1) != 0 )
  {
    v93 = *(unsigned __int8 *)(a1 + 11369);
LABEL_14:
    tdls_chan_switch_prohibited = mlme_get_tdls_chan_switch_prohibited(
                                    *(_QWORD *)(a4 + 16),
                                    v85,
                                    v86,
                                    v87,
                                    v88,
                                    v89,
                                    v90,
                                    v91,
                                    v92);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: TDLS offchan not enabled, or channel switch prohibited by AP, gLimTDLSOffChannelEnabled: %d tdls_chan_swit_prohibited: %d",
      v95,
      v96,
      v97,
      v98,
      v99,
      v100,
      v101,
      v102,
      "lim_send_tdls_link_setup_req_frame",
      v93,
      tdls_chan_switch_prohibited & 1);
    goto LABEL_15;
  }
  populate_dot11f_tdls_offchannel_params(a1, a4, v23 + 282, v23 + 543);
  if ( *(_DWORD *)(*(_QWORD *)(a1 + 8) + 1032LL) != 1 )
  {
    v113 = *(_BYTE *)(v23 + 877);
    *(_BYTE *)(v23 + 876) = 1;
    *(_BYTE *)(v23 + 877) = v113 | 1;
  }
LABEL_15:
  packed_tdls_setup_req_size = dot11f_get_packed_tdls_setup_req_size(a1, v23, (int *)&v181);
  if ( (packed_tdls_setup_req_size & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to calculate the packed size for a Setup Request (0x%08x)",
      v104,
      v105,
      v106,
      v107,
      v108,
      v109,
      v110,
      v111,
      "lim_send_tdls_link_setup_req_frame",
      packed_tdls_setup_req_size);
    v181 = 1160;
  }
  else if ( packed_tdls_setup_req_size )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while calculating the packed size for a Setup Request (0x%08x)",
      v104,
      v105,
      v106,
      v107,
      v108,
      v109,
      v110,
      v111,
      "lim_send_tdls_link_setup_req_frame");
  }
  if ( (*(_BYTE *)(a4 + 7024) & 1) != 0 && (*(_WORD *)(a4 + 176) & 0x200) != 0 )
  {
    v112 = 26;
  }
  else
  {
    v112 = 24;
    if ( (*(_BYTE *)(a4 + 7024) & 2) != 0 )
    {
      if ( (*(_BYTE *)(a4 + 178) & 2) != 0 )
        v112 = 26;
      else
        v112 = 24;
    }
  }
  v114 = a6 + v112 + v181;
  if ( (unsigned int)cds_packet_alloc(a6 + (unsigned __int16)v112 + (unsigned __int16)v181 + 9, &v180, &v179) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to allocate %d bytes for a TDLS Setup Request",
      v115,
      v116,
      v117,
      v118,
      v119,
      v120,
      v121,
      v122,
      "lim_send_tdls_link_setup_req_frame",
      v114 + 9);
LABEL_41:
    _qdf_mem_free(0);
    result = _qdf_mem_free(v23);
    goto LABEL_42;
  }
  qdf_mem_set(v180, v114 + 9, 0);
  if ( a7 == 1 )
    v123 = 4;
  else
    v123 = 1;
  v124 = lim_prepare_tdls_frame_header(a1, v180, v23 + 878, 0, 0, v123, a4);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: SupportedChnlWidth: %x rxMCSMap: %x rxMCSMap: %x txSupDataRate: %x",
    v125,
    v126,
    v127,
    v128,
    v129,
    v130,
    v131,
    v132,
    "lim_send_tdls_link_setup_req_frame",
    (*(unsigned __int16 *)(v23 + 905) >> 2) & 3,
    *(unsigned __int16 *)(v23 + 910),
    *(unsigned __int16 *)(v23 + 914),
    *(_WORD *)(v23 + 916) & 0x1FFF);
  v133 = dot11f_pack_tdls_setup_req(a1, v23, &v180[v124], v181, &v181);
  if ( (v133 & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to pack a TDLS Setup request (0x%08x)",
      v134,
      v135,
      v136,
      v137,
      v138,
      v139,
      v140,
      v141,
      "lim_send_tdls_link_setup_req_frame",
      v133);
    cds_packet_free((__int64)v179);
    goto LABEL_41;
  }
  if ( v133 )
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while packing TDLS Setup Request (0x%08x)",
      v134,
      v135,
      v136,
      v137,
      v138,
      v139,
      v140,
      v141,
      "lim_send_tdls_link_setup_req_frame");
  lim_cp_stats_cstats_log_setup_req_evt((char *)v23, a4);
  _qdf_mem_free(v23);
  if ( a6 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Copy Additional Ie Len = %d",
      v142,
      v143,
      v144,
      v145,
      v146,
      v147,
      v148,
      v149,
      "lim_send_tdls_link_setup_req_frame",
      a6);
    qdf_mem_copy(&v180[v181 + v124], a5, a6);
    v181 += a6;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: [TDLS] action: %d (%s) -AP-> OTA peer=%02x:%02x:%02x:**:**:%02x",
    v142,
    v143,
    v144,
    v145,
    v146,
    v147,
    v148,
    v149,
    "lim_send_tdls_link_setup_req_frame",
    0,
    "TDLS_SETUP_REQUEST",
    (unsigned __int8)a2,
    BYTE1(a2),
    BYTE2(a2),
    BYTE5(a2));
  v150 = (unsigned __int8 *)v180;
  *(_DWORD *)(a1 + 12368) = *(unsigned __int8 *)(a4 + 10);
  v151 = *(_BYTE *)(a4 + 10);
  lim_diag_mgmt_tx_event_report(a1, v150, a4, 0, 0, v152, v153, v154, v155, v156, v157, v158, v159);
  v160 = v179;
  v161 = v180;
  context = _cds_get_context(
              54,
              (__int64)"wma_tx_frame_with_tx_complete_send",
              v162,
              v163,
              v164,
              v165,
              v166,
              v167,
              v168,
              v169);
  result = wma_tx_packet(
             (__int64)context,
             v160,
             (unsigned __int16)v114 + 9,
             5u,
             v171,
             v172,
             v173,
             v174,
             v175,
             v176,
             v177,
             v178,
             1,
             4,
             lim_tx_complete,
             v161,
             (__int64)lim_mgmt_tdls_tx_complete,
             192,
             v151,
             0,
             0,
             0xCu,
             0);
  if ( (_DWORD)result )
  {
    v78 = "%s: could not send TDLS Setup Request frame!";
    *(_DWORD *)(a1 + 12368) = 255;
    goto LABEL_9;
  }
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return result;
}
