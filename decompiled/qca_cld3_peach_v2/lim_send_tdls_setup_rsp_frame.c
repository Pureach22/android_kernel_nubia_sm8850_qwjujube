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
  _BYTE *v67; // x25
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  char v76; // w8
  int v77; // w9
  unsigned int v78; // w9
  unsigned int v79; // w9
  char v80; // w11
  const char *v81; // x2
  __int64 result; // x0
  char v83; // w8
  char v84; // w8
  char v85; // w8
  char v86; // w8
  unsigned int v87; // w23
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
  unsigned int v104; // w26
  const void *v105; // x28
  unsigned int v106; // w23
  char tdls_chan_switch_prohibited; // w0
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  unsigned int packed_tdls_setup_rsp_size; // w0
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  int v125; // w9
  char v126; // w8
  int v127; // w25
  double v128; // d0
  double v129; // d1
  double v130; // d2
  double v131; // d3
  double v132; // d4
  double v133; // d5
  double v134; // d6
  double v135; // d7
  __int64 v136; // x5
  int v137; // w23
  double v138; // d0
  double v139; // d1
  double v140; // d2
  double v141; // d3
  double v142; // d4
  double v143; // d5
  double v144; // d6
  double v145; // d7
  unsigned int v146; // w0
  double v147; // d0
  double v148; // d1
  double v149; // d2
  double v150; // d3
  double v151; // d4
  double v152; // d5
  double v153; // d6
  double v154; // d7
  double v155; // d0
  double v156; // d1
  double v157; // d2
  double v158; // d3
  double v159; // d4
  double v160; // d5
  double v161; // d6
  double v162; // d7
  unsigned __int8 *v163; // x22
  double v164; // d0
  double v165; // d1
  double v166; // d2
  double v167; // d3
  double v168; // d4
  double v169; // d5
  double v170; // d6
  double v171; // d7
  double v172; // d0
  double v173; // d1
  double v174; // d2
  double v175; // d3
  double v176; // d4
  double v177; // d5
  double v178; // d6
  double v179; // d7
  __int64 assoc_link_vdev; // x0
  unsigned __int8 v181; // w22
  _QWORD *v182; // x20
  char *v183; // x21
  double v184; // d0
  double v185; // d1
  double v186; // d2
  double v187; // d3
  double v188; // d4
  double v189; // d5
  double v190; // d6
  double v191; // d7
  _QWORD *context; // x0
  double v193; // d0
  double v194; // d1
  double v195; // d2
  double v196; // d3
  double v197; // d4
  double v198; // d5
  double v199; // d6
  double v200; // d7
  const void *v201; // [xsp+48h] [xbp-38h]
  int v202; // [xsp+54h] [xbp-2Ch]
  _BYTE v203[4]; // [xsp+5Ch] [xbp-24h] BYREF
  _QWORD *v204; // [xsp+60h] [xbp-20h] BYREF
  char *v205; // [xsp+68h] [xbp-18h] BYREF
  unsigned int v206; // [xsp+70h] [xbp-10h] BYREF
  unsigned __int16 v207; // [xsp+74h] [xbp-Ch] BYREF
  __int64 v208; // [xsp+78h] [xbp-8h]

  v208 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v207 = 0;
  v206 = 0;
  v204 = nullptr;
  v205 = nullptr;
  v203[0] = 0;
  v16 = _qdf_mem_malloc(0x3E0u, "lim_send_tdls_setup_rsp_frame", 2575);
  if ( !v16 )
  {
    v81 = "%s: memory allocation failed for SetupRsp";
LABEL_9:
    result = qdf_trace_msg(0x35u, 2u, v81, v17, v18, v19, v20, v21, v22, v23, v24, "lim_send_tdls_setup_rsp_frame");
    goto LABEL_59;
  }
  v25 = v16;
  *(_BYTE *)(v16 + 4) = a3;
  *(_WORD *)v16 = 268;
  v201 = a6;
  v26 = populate_dot11f_link_iden(a4, v16 + 882, a2 & 0xFFFFFFFFFFFFLL, 1);
  if ( (unsigned int)lim_get_capability_info(a1, (__int16 *)&v207, a4, v26, v27, v28, v29, v30, v31, v32, v33) )
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
  v202 = a8;
  swap_bit_field16(v207, (_WORD *)(v25 + 6));
  v50 = wlan_reg_freq_to_chan(*(_QWORD *)(a1 + 21632), *(_DWORD *)(a4 + 284), v42, v43, v44, v45, v46, v47, v48, v49);
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
  v67 = (_BYTE *)(a4 + 7024);
  populate_dot11f_tdls_ext_capability(a1, a4, v25 + 528);
  if ( *(_BYTE *)(a1 + 11370) == 1 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: populate WMM IE in Setup Response frame",
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      "lim_send_tdls_setup_rsp_frame");
    v76 = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 5670LL);
    *(_BYTE *)(v25 + 902) = 1;
    v77 = *(_BYTE *)(v25 + 903) & 0xFE | *(_BYTE *)(a1 + 11368) & 1;
    *(_BYTE *)(v25 + 903) = v77;
    v78 = v77 & 0xFFFFFFFD | (2 * ((*(unsigned __int8 *)(a1 + 11368) >> 1) & 1));
    *(_BYTE *)(v25 + 903) = v78;
    v79 = v78 & 0xFFFFFFFB | (4 * ((*(unsigned __int8 *)(a1 + 11368) >> 2) & 1));
    *(_BYTE *)(v25 + 903) = v79;
    v80 = *(_BYTE *)(a1 + 11368);
    *(_BYTE *)(v25 + 901) = 1;
    *(_BYTE *)(v25 + 903) = v80 & 8 | (32 * (v76 & 3)) | v79 & 0x97;
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: populate QOS IE in Setup Response frame",
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      "lim_send_tdls_setup_rsp_frame");
    v83 = *(_BYTE *)(v25 + 580);
    *(_BYTE *)(v25 + 579) = 1;
    *(_BYTE *)(v25 + 580) = v83 & 0x8F;
    v84 = *(_BYTE *)(a1 + 11368) & 8 | v83 & 0x87;
    *(_BYTE *)(v25 + 580) = v84;
    v85 = v84 & 0xFB | *(_BYTE *)(a1 + 11368) & 4;
    *(_BYTE *)(v25 + 580) = v85;
    v86 = v85 & 0xFD | *(_BYTE *)(a1 + 11368) & 2;
    *(_BYTE *)(v25 + 580) = v86;
    *(_BYTE *)(v25 + 580) = v86 & 0xFE | *(_BYTE *)(a1 + 11368) & 1;
  }
  v87 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 5964LL);
  populate_dot11f_tdls_ht_vht_cap(a1, v87, v25 + 820, v25 + 908, a4);
  populate_dot11f_set_tdls_he_cap(a1, v87, v25 + 928);
  v88 = populate_dotf_tdls_vht_aid(a1, v87, a2 & 0xFFFFFFFFFFFFLL, v25 + 904, a4);
  if ( (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(a4 + 16), v88, v89, v90, v91, v92, v93, v94, v95) & 1) != 0 )
    v104 = lim_send_tdls_mgmt_frame_mlo(a1, a4);
  else
    v104 = 0;
  if ( *(_BYTE *)(a4 + 10071) == 1 )
  {
    v105 = (const void *)lim_ieee80211_pack_ehtcap_tdls(a1, a4, v203);
    if ( !v105 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: malloc failed for eht_cap_ie",
        v96,
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        "lim_send_tdls_setup_rsp_frame");
LABEL_58:
      result = _qdf_mem_free(v25);
      goto LABEL_59;
    }
  }
  else
  {
    v105 = nullptr;
  }
  v106 = *(unsigned __int8 *)(a1 + 11369);
  if ( v106 != 1 )
    goto LABEL_21;
  if ( (mlme_get_tdls_chan_switch_prohibited(*(_QWORD *)(a4 + 16), v96, v97, v98, v99, v100, v101, v102, v103) & 1) != 0 )
  {
    v106 = *(unsigned __int8 *)(a1 + 11369);
LABEL_21:
    tdls_chan_switch_prohibited = mlme_get_tdls_chan_switch_prohibited(
                                    *(_QWORD *)(a4 + 16),
                                    v96,
                                    v97,
                                    v98,
                                    v99,
                                    v100,
                                    v101,
                                    v102,
                                    v103);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: TDLS offchan not enabled, or channel switch prohibited by AP, gLimTDLSOffChannelEnabled: %d tdls_chan_swit_prohibited: %d",
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      v114,
      v115,
      "lim_send_tdls_setup_rsp_frame",
      v106,
      tdls_chan_switch_prohibited & 1);
    goto LABEL_22;
  }
  populate_dot11f_tdls_offchannel_params(a1, a4, v25 + 284, v25 + 545);
  if ( *(_DWORD *)(*(_QWORD *)(a1 + 8) + 1032LL) != 1 )
  {
    v126 = *(_BYTE *)(v25 + 881);
    *(_BYTE *)(v25 + 880) = 1;
    *(_BYTE *)(v25 + 881) = v126 | 1;
  }
LABEL_22:
  *(_WORD *)(v25 + 2) = a5;
  packed_tdls_setup_rsp_size = dot11f_get_packed_tdls_setup_rsp_size(a1, v25, (int *)&v206);
  if ( (packed_tdls_setup_rsp_size & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to calculate the packed size for a Setup Response (0x%08x)",
      v117,
      v118,
      v119,
      v120,
      v121,
      v122,
      v123,
      v124,
      "lim_send_tdls_setup_rsp_frame",
      packed_tdls_setup_rsp_size);
    v206 = 1160;
  }
  else if ( packed_tdls_setup_rsp_size )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while calculating the packed size for Setup Response (0x%08x)",
      v117,
      v118,
      v119,
      v120,
      v121,
      v122,
      v123,
      v124,
      "lim_send_tdls_setup_rsp_frame");
  }
  if ( (*v67 & 1) != 0 && (*(_WORD *)(a4 + 176) & 0x200) != 0 )
  {
    v125 = 26;
  }
  else
  {
    v125 = 24;
    if ( (*v67 & 2) != 0 )
    {
      if ( (*(_BYTE *)(a4 + 178) & 2) != 0 )
        v125 = 26;
      else
        v125 = 24;
    }
  }
  v127 = a7 + (unsigned __int16)v104 + v206 + v125 + v203[0];
  if ( (unsigned int)cds_packet_alloc(
                       a7 + (unsigned __int16)v104 + (unsigned __int16)v206 + (unsigned __int16)v125 + v203[0] + 9,
                       &v205,
                       &v204) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to allocate %d bytes for a TDLS Setup Response",
      v128,
      v129,
      v130,
      v131,
      v132,
      v133,
      v134,
      v135,
      "lim_send_tdls_setup_rsp_frame",
      (unsigned int)(v127 + 9));
LABEL_57:
    _qdf_mem_free((__int64)v105);
    goto LABEL_58;
  }
  qdf_mem_set(v205, (unsigned int)(v127 + 9), 0);
  if ( v202 == 1 )
    v136 = 4;
  else
    v136 = 1;
  v137 = lim_prepare_tdls_frame_header(a1, v205, v25 + 882, 0, 1, v136, a4);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: SupportedChnlWidth: %x rxMCSMap: %x rxMCSMap: %x txSupDataRate: %x",
    v138,
    v139,
    v140,
    v141,
    v142,
    v143,
    v144,
    v145,
    "lim_send_tdls_setup_rsp_frame",
    (*(unsigned __int16 *)(v25 + 909) >> 2) & 3,
    *(unsigned __int16 *)(v25 + 914),
    *(unsigned __int16 *)(v25 + 918),
    *(_WORD *)(v25 + 920) & 0x1FFF);
  v146 = dot11f_pack_tdls_setup_rsp(a1, v25, &v205[v137], v206, &v206);
  if ( (v146 & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to pack a TDLS Setup Response (0x%08x)",
      v147,
      v148,
      v149,
      v150,
      v151,
      v152,
      v153,
      v154,
      "lim_send_tdls_setup_rsp_frame",
      v146);
    cds_packet_free((__int64)v204);
    goto LABEL_57;
  }
  if ( v146 )
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while packing TDLS Setup Response (0x%08x)",
      v147,
      v148,
      v149,
      v150,
      v151,
      v152,
      v153,
      v154,
      "lim_send_tdls_setup_rsp_frame");
  lim_cp_stats_cstats_log_setup_resp_evt((__int16 *)v25, a4);
  _qdf_mem_free(v25);
  if ( a7 )
  {
    qdf_mem_copy(&v205[v206 + v137], v201, a7);
    v206 += a7;
  }
  if ( v203[0] )
  {
    qdf_mem_copy(&v205[v206 + v137], v105, v203[0]);
    _qdf_mem_free((__int64)v105);
    v206 += v203[0];
  }
  v163 = (unsigned __int8 *)(a4 + 10);
  if ( (_WORD)v104 )
  {
    if ( (unsigned int)lim_fill_complete_mlo_ie(a4, v104, &v205[v206 + v137]) )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: assemble ml ie error",
        v155,
        v156,
        v157,
        v158,
        v159,
        v160,
        v161,
        v162,
        "lim_send_tdls_setup_rsp_frame");
      LOWORD(v104) = 0;
    }
    v206 += (unsigned __int16)v104;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: [TDLS] vdev:%d action: %d (%s) -AP-> OTA peer=%02x:%02x:%02x:**:**:%02x",
    v155,
    v156,
    v157,
    v158,
    v159,
    v160,
    v161,
    v162,
    "lim_send_tdls_setup_rsp_frame",
    *(unsigned __int8 *)(a4 + 10),
    1,
    "TDLS_SETUP_RESPONSE",
    (unsigned __int8)a2,
    BYTE1(a2),
    BYTE2(a2),
    BYTE5(a2));
  *(_DWORD *)(a1 + 12368) = *(unsigned __int8 *)(a4 + 10);
  if ( (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(a4 + 16), v164, v165, v166, v167, v168, v169, v170, v171) & 1) != 0 )
  {
    assoc_link_vdev = wlan_mlo_get_assoc_link_vdev(*(_QWORD *)(a4 + 16));
    if ( assoc_link_vdev )
      v163 = (unsigned __int8 *)(assoc_link_vdev + 168);
  }
  v181 = *v163;
  lim_diag_mgmt_tx_event_report(a1, (unsigned __int8 *)v205, a4, 0, 0, v172, v173, v174, v175, v176, v177, v178, v179);
  v182 = v204;
  v183 = v205;
  context = _cds_get_context(
              54,
              (__int64)"wma_tx_frame_with_tx_complete_send",
              v184,
              v185,
              v186,
              v187,
              v188,
              v189,
              v190,
              v191);
  result = wma_tx_packet(
             (__int64)context,
             v182,
             (unsigned __int16)v127 + 9,
             5u,
             v193,
             v194,
             v195,
             v196,
             v197,
             v198,
             v199,
             v200,
             1,
             4,
             lim_tx_complete,
             v183,
             (__int64)lim_mgmt_tdls_tx_complete,
             192,
             v181,
             0,
             0,
             0xCu,
             0,
             0);
  if ( (_DWORD)result )
  {
    v81 = "%s: could not send TDLS Dis Request frame!";
    *(_DWORD *)(a1 + 12368) = 255;
    goto LABEL_9;
  }
LABEL_59:
  _ReadStatusReg(SP_EL0);
  return result;
}
