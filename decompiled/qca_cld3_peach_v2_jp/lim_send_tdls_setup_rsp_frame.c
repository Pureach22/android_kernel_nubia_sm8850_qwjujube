__int64 __fastcall lim_send_tdls_setup_rsp_frame(
        __int64 a1,
        __int64 a2,
        char a3,
        __int64 a4,
        __int16 a5,
        const void *a6,
        unsigned __int16 a7,
        int a8)
{
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x22
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned __int8 v50; // w0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  char v75; // w8
  int v76; // w9
  unsigned int v77; // w9
  unsigned int v78; // w9
  char v79; // w11
  const char *v80; // x2
  __int64 result; // x0
  char v82; // w8
  char v83; // w8
  char v84; // w8
  char v85; // w8
  unsigned int v86; // w27
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  unsigned int v95; // w27
  char tdls_chan_switch_prohibited; // w0
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  unsigned int packed_tdls_setup_rsp_size; // w0
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  int v114; // w9
  char v115; // w8
  unsigned int v116; // w27
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  __int64 v125; // x5
  int v126; // w25
  double v127; // d0
  double v128; // d1
  double v129; // d2
  double v130; // d3
  double v131; // d4
  double v132; // d5
  double v133; // d6
  double v134; // d7
  unsigned int v135; // w0
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
  unsigned __int8 *v152; // x1
  unsigned __int8 v153; // w22
  double v154; // d0
  double v155; // d1
  double v156; // d2
  double v157; // d3
  double v158; // d4
  double v159; // d5
  double v160; // d6
  double v161; // d7
  _QWORD *v162; // x20
  char *v163; // x21
  double v164; // d0
  double v165; // d1
  double v166; // d2
  double v167; // d3
  double v168; // d4
  double v169; // d5
  double v170; // d6
  double v171; // d7
  _QWORD *context; // x0
  double v173; // d0
  double v174; // d1
  double v175; // d2
  double v176; // d3
  double v177; // d4
  double v178; // d5
  double v179; // d6
  double v180; // d7
  _QWORD *v181; // [xsp+58h] [xbp-28h] BYREF
  char *v182; // [xsp+60h] [xbp-20h] BYREF
  unsigned int v183; // [xsp+68h] [xbp-18h] BYREF
  unsigned __int16 v184; // [xsp+6Ch] [xbp-14h] BYREF
  int v185; // [xsp+70h] [xbp-10h] BYREF
  __int16 v186; // [xsp+74h] [xbp-Ch]
  __int64 v187; // [xsp+78h] [xbp-8h]

  v187 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v184 = 0;
  v183 = 0;
  v181 = nullptr;
  v182 = nullptr;
  v16 = _qdf_mem_malloc(0x3E0u, "lim_send_tdls_setup_rsp_frame", 2575);
  if ( !v16 )
  {
    v80 = "%s: memory allocation failed for SetupRsp";
LABEL_9:
    result = qdf_trace_msg(0x35u, 2u, v80, v17, v18, v19, v20, v21, v22, v23, v24, "lim_send_tdls_setup_rsp_frame");
    goto LABEL_42;
  }
  v25 = v16;
  *(_BYTE *)(v16 + 4) = a3;
  *(_WORD *)v16 = 268;
  v186 = WORD2(a2);
  v185 = a2;
  qdf_mem_copy((void *)(v16 + 883), (const void *)(a4 + 24), 6u);
  qdf_mem_copy((void *)(v25 + 895), (const void *)(a4 + 30), 6u);
  qdf_mem_copy((void *)(v25 + 889), &v185, 6u);
  *(_BYTE *)(v25 + 882) = 1;
  if ( (unsigned int)lim_get_capability_info(a1, (__int16 *)&v184, a4, v26, v27, v28, v29, v30, v31, v32, v33) )
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: could not retrieve Capabilities value",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "lim_send_tdls_setup_rsp_frame");
  swap_bit_field16(v184, (_WORD *)(v25 + 6));
  v50 = wlan_reg_freq_to_chan(*(_QWORD *)(a1 + 21560), *(_DWORD *)(a4 + 284), v42, v43, v44, v45, v46, v47, v48, v49);
  if ( (unsigned int)populate_dot11f_rates_tdls(
                       a1,
                       (_BYTE *)(v25 + 8),
                       (_BYTE *)(v25 + 270),
                       v50,
                       v51,
                       v52,
                       v53,
                       v54,
                       v55,
                       v56,
                       v57,
                       v58) == 16 )
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: could not populate supported data rates",
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      "lim_send_tdls_setup_rsp_frame");
  populate_dot11f_tdls_ext_capability(a1, a4, v25 + 528);
  if ( *(_BYTE *)(a1 + 11370) == 1 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: populate WMM IE in Setup Response frame",
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      "lim_send_tdls_setup_rsp_frame");
    v75 = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 5454LL);
    *(_BYTE *)(v25 + 902) = 1;
    v76 = *(_BYTE *)(v25 + 903) & 0xFE | *(_BYTE *)(a1 + 11368) & 1;
    *(_BYTE *)(v25 + 903) = v76;
    v77 = v76 & 0xFFFFFFFD | (2 * ((*(unsigned __int8 *)(a1 + 11368) >> 1) & 1));
    *(_BYTE *)(v25 + 903) = v77;
    v78 = v77 & 0xFFFFFFFB | (4 * ((*(unsigned __int8 *)(a1 + 11368) >> 2) & 1));
    *(_BYTE *)(v25 + 903) = v78;
    v79 = *(_BYTE *)(a1 + 11368);
    *(_BYTE *)(v25 + 901) = 1;
    *(_BYTE *)(v25 + 903) = v79 & 8 | (32 * (v75 & 3)) | v78 & 0x97;
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: populate QOS IE in Setup Response frame",
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      "lim_send_tdls_setup_rsp_frame");
    v82 = *(_BYTE *)(v25 + 580);
    *(_BYTE *)(v25 + 579) = 1;
    *(_BYTE *)(v25 + 580) = v82 & 0x8F;
    v83 = *(_BYTE *)(a1 + 11368) & 8 | v82 & 0x87;
    *(_BYTE *)(v25 + 580) = v83;
    v84 = v83 & 0xFB | *(_BYTE *)(a1 + 11368) & 4;
    *(_BYTE *)(v25 + 580) = v84;
    v85 = v84 & 0xFD | *(_BYTE *)(a1 + 11368) & 2;
    *(_BYTE *)(v25 + 580) = v85;
    *(_BYTE *)(v25 + 580) = v85 & 0xFE | *(_BYTE *)(a1 + 11368) & 1;
  }
  v86 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 5748LL);
  populate_dot11f_tdls_ht_vht_cap(a1, v86, v25 + 820, v25 + 908, a4);
  populate_dot11f_set_tdls_he_cap(a1, v86, v25 + 928);
  populate_dotf_tdls_vht_aid(a1, v86, a2 & 0xFFFFFFFFFFFFLL, v25 + 904, a4);
  v95 = *(unsigned __int8 *)(a1 + 11369);
  if ( v95 != 1 )
    goto LABEL_14;
  if ( (mlme_get_tdls_chan_switch_prohibited(*(_QWORD *)(a4 + 16), v87, v88, v89, v90, v91, v92, v93, v94) & 1) != 0 )
  {
    v95 = *(unsigned __int8 *)(a1 + 11369);
LABEL_14:
    tdls_chan_switch_prohibited = mlme_get_tdls_chan_switch_prohibited(
                                    *(_QWORD *)(a4 + 16),
                                    v87,
                                    v88,
                                    v89,
                                    v90,
                                    v91,
                                    v92,
                                    v93,
                                    v94);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: TDLS offchan not enabled, or channel switch prohibited by AP, gLimTDLSOffChannelEnabled: %d tdls_chan_swit_prohibited: %d",
      v97,
      v98,
      v99,
      v100,
      v101,
      v102,
      v103,
      v104,
      "lim_send_tdls_setup_rsp_frame",
      v95,
      tdls_chan_switch_prohibited & 1);
    goto LABEL_15;
  }
  populate_dot11f_tdls_offchannel_params(a1, a4, v25 + 284, v25 + 545);
  if ( *(_DWORD *)(*(_QWORD *)(a1 + 8) + 1032LL) != 1 )
  {
    v115 = *(_BYTE *)(v25 + 881);
    *(_BYTE *)(v25 + 880) = 1;
    *(_BYTE *)(v25 + 881) = v115 | 1;
  }
LABEL_15:
  *(_WORD *)(v25 + 2) = a5;
  packed_tdls_setup_rsp_size = dot11f_get_packed_tdls_setup_rsp_size(a1, v25, (int *)&v183);
  if ( (packed_tdls_setup_rsp_size & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to calculate the packed size for a Setup Response (0x%08x)",
      v106,
      v107,
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      "lim_send_tdls_setup_rsp_frame",
      packed_tdls_setup_rsp_size);
    v183 = 1160;
  }
  else if ( packed_tdls_setup_rsp_size )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while calculating the packed size for Setup Response (0x%08x)",
      v106,
      v107,
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      "lim_send_tdls_setup_rsp_frame");
  }
  if ( (*(_BYTE *)(a4 + 7024) & 1) != 0 && (*(_WORD *)(a4 + 176) & 0x200) != 0 )
  {
    v114 = 26;
  }
  else
  {
    v114 = 24;
    if ( (*(_BYTE *)(a4 + 7024) & 2) != 0 )
    {
      if ( (*(_BYTE *)(a4 + 178) & 2) != 0 )
        v114 = 26;
      else
        v114 = 24;
    }
  }
  v116 = a7 + v114 + v183;
  if ( (unsigned int)cds_packet_alloc(a7 + (unsigned __int16)v114 + (unsigned __int16)v183 + 9, &v182, &v181) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to allocate %d bytes for a TDLS Setup Response",
      v117,
      v118,
      v119,
      v120,
      v121,
      v122,
      v123,
      v124,
      "lim_send_tdls_setup_rsp_frame",
      v116 + 9);
LABEL_41:
    _qdf_mem_free(0);
    result = _qdf_mem_free(v25);
    goto LABEL_42;
  }
  qdf_mem_set(v182, v116 + 9, 0);
  if ( a8 == 1 )
    v125 = 4;
  else
    v125 = 1;
  v126 = lim_prepare_tdls_frame_header(a1, v182, v25 + 882, 0, 1, v125, a4);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: SupportedChnlWidth: %x rxMCSMap: %x rxMCSMap: %x txSupDataRate: %x",
    v127,
    v128,
    v129,
    v130,
    v131,
    v132,
    v133,
    v134,
    "lim_send_tdls_setup_rsp_frame",
    (*(unsigned __int16 *)(v25 + 909) >> 2) & 3,
    *(unsigned __int16 *)(v25 + 914),
    *(unsigned __int16 *)(v25 + 918),
    *(_WORD *)(v25 + 920) & 0x1FFF);
  v135 = dot11f_pack_tdls_setup_rsp(a1, v25, &v182[v126], v183, &v183);
  if ( (v135 & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to pack a TDLS Setup Response (0x%08x)",
      v136,
      v137,
      v138,
      v139,
      v140,
      v141,
      v142,
      v143,
      "lim_send_tdls_setup_rsp_frame",
      v135);
    cds_packet_free((__int64)v181);
    goto LABEL_41;
  }
  if ( v135 )
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while packing TDLS Setup Response (0x%08x)",
      v136,
      v137,
      v138,
      v139,
      v140,
      v141,
      v142,
      v143,
      "lim_send_tdls_setup_rsp_frame");
  lim_cp_stats_cstats_log_setup_resp_evt((__int16 *)v25, a4);
  _qdf_mem_free(v25);
  if ( a7 )
  {
    qdf_mem_copy(&v182[v183 + v126], a6, a7);
    v183 += a7;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: [TDLS] vdev:%d action: %d (%s) -AP-> OTA peer=%02x:%02x:%02x:**:**:%02x",
    v144,
    v145,
    v146,
    v147,
    v148,
    v149,
    v150,
    v151,
    "lim_send_tdls_setup_rsp_frame",
    *(unsigned __int8 *)(a4 + 10),
    1,
    "TDLS_SETUP_RESPONSE",
    (unsigned __int8)a2,
    BYTE1(a2),
    BYTE2(a2),
    BYTE5(a2));
  v152 = (unsigned __int8 *)v182;
  *(_DWORD *)(a1 + 12368) = *(unsigned __int8 *)(a4 + 10);
  v153 = *(_BYTE *)(a4 + 10);
  lim_diag_mgmt_tx_event_report(a1, v152, a4, 0, 0, v154, v155, v156, v157, v158, v159, v160, v161);
  v162 = v181;
  v163 = v182;
  context = _cds_get_context(
              54,
              (__int64)"wma_tx_frame_with_tx_complete_send",
              v164,
              v165,
              v166,
              v167,
              v168,
              v169,
              v170,
              v171);
  result = wma_tx_packet(
             (__int64)context,
             v162,
             (unsigned __int16)v116 + 9,
             5u,
             v173,
             v174,
             v175,
             v176,
             v177,
             v178,
             v179,
             v180,
             1,
             4,
             lim_tx_complete,
             v163,
             (__int64)lim_mgmt_tdls_tx_complete,
             192,
             v153,
             0,
             0,
             0xCu,
             0);
  if ( (_DWORD)result )
  {
    v80 = "%s: could not send TDLS Dis Request frame!";
    *(_DWORD *)(a1 + 12368) = 255;
    goto LABEL_9;
  }
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return result;
}
