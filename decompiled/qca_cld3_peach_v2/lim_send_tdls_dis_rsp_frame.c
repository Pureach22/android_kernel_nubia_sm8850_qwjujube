__int64 __fastcall lim_send_tdls_dis_rsp_frame(
        __int64 a1,
        __int64 a2,
        char a3,
        __int64 a4,
        const void *a5,
        unsigned __int16 a6)
{
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x22
  unsigned __int8 v22; // w27
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  unsigned __int8 v47; // w0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  unsigned int v64; // w24
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  unsigned int v81; // w24
  const char *v82; // x2
  __int64 result; // x0
  const void *v84; // x25
  unsigned int v85; // w26
  char tdls_chan_switch_prohibited; // w0
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  unsigned int packed_tdls_dis_rsp_size; // w0
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  int v104; // w28
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
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  __int64 v129; // x8
  const void *v130; // x1
  char v131; // w8
  char *v132; // x8
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
  double v150; // d0
  double v151; // d1
  double v152; // d2
  double v153; // d3
  double v154; // d4
  double v155; // d5
  double v156; // d6
  double v157; // d7
  unsigned __int8 *v158; // x1
  double v159; // d0
  double v160; // d1
  double v161; // d2
  double v162; // d3
  double v163; // d4
  double v164; // d5
  double v165; // d6
  double v166; // d7
  double v167; // d0
  double v168; // d1
  double v169; // d2
  double v170; // d3
  double v171; // d4
  double v172; // d5
  double v173; // d6
  double v174; // d7
  _QWORD *context; // x0
  double v176; // d0
  double v177; // d1
  double v178; // d2
  double v179; // d3
  double v180; // d4
  double v181; // d5
  double v182; // d6
  double v183; // d7
  _BYTE v184[4]; // [xsp+4Ch] [xbp-34h] BYREF
  _QWORD *v185; // [xsp+50h] [xbp-30h] BYREF
  char *v186; // [xsp+58h] [xbp-28h] BYREF
  unsigned int v187; // [xsp+60h] [xbp-20h] BYREF
  unsigned __int16 v188; // [xsp+64h] [xbp-1Ch] BYREF
  int v189; // [xsp+68h] [xbp-18h] BYREF
  __int16 v190; // [xsp+6Ch] [xbp-14h]
  int v191; // [xsp+70h] [xbp-10h] BYREF
  __int16 v192; // [xsp+74h] [xbp-Ch]
  __int64 v193; // [xsp+78h] [xbp-8h]

  v193 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v191 = a2;
  v192 = WORD2(a2);
  v188 = 0;
  v187 = 0;
  v185 = nullptr;
  v186 = nullptr;
  v190 = 0;
  v189 = 0;
  v184[0] = 0;
  v12 = _qdf_mem_malloc(0x2D8u, "lim_send_tdls_dis_rsp_frame", 1653);
  if ( !v12 )
  {
    v82 = "%s: memory allocation failed for DisRsp";
LABEL_9:
    result = qdf_trace_msg(0x35u, 2u, v82, v13, v14, v15, v16, v17, v18, v19, v20, "lim_send_tdls_dis_rsp_frame");
    goto LABEL_48;
  }
  v21 = v12;
  v22 = *(_BYTE *)(a4 + 10);
  *(_WORD *)v12 = 3588;
  *(_BYTE *)(v12 + 2) = a3;
  v23 = populate_dot11f_link_iden(a4, v12 + 630, a2 & 0xFFFFFFFFFFFFLL, 1);
  if ( (unsigned int)lim_get_capability_info(a1, (__int16 *)&v188, a4, v23, v24, v25, v26, v27, v28, v29, v30) )
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: could not retrieve Capabilities value",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "lim_send_tdls_dis_rsp_frame");
  swap_bit_field16(v188, (_WORD *)(v21 + 4));
  v47 = wlan_reg_freq_to_chan(*(_QWORD *)(a1 + 21632), *(_DWORD *)(a4 + 284), v39, v40, v41, v42, v43, v44, v45, v46);
  if ( (unsigned int)populate_dot11f_rates_tdls(
                       a1,
                       (_BYTE *)(v21 + 6),
                       (_BYTE *)(v21 + 20),
                       v47,
                       v48,
                       v49,
                       v50,
                       v51,
                       v52,
                       v53,
                       v54,
                       v55) == 16 )
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: could not populate supported data rates",
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      "lim_send_tdls_dis_rsp_frame");
  populate_dot11f_tdls_ext_capability(a1, a4, v21 + 312);
  v64 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 5964LL);
  populate_dot11f_tdls_ht_vht_cap(a1, v64, v21 + 568, v21 + 652, a4);
  populate_dot11f_set_tdls_he_cap(a1, v64, v21 + 668);
  if ( (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(a4 + 16), v65, v66, v67, v68, v69, v70, v71, v72) & 1) != 0 )
    v81 = lim_send_tdls_mgmt_frame_mlo(a1, a4);
  else
    v81 = 0;
  if ( *(_BYTE *)(a4 + 10071) == 1 )
  {
    v84 = (const void *)lim_ieee80211_pack_ehtcap_tdls(a1, a4, v184);
    if ( !v84 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: malloc failed for eht_cap_ie",
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        v80,
        "lim_send_tdls_dis_rsp_frame");
LABEL_47:
      result = _qdf_mem_free(v21);
      goto LABEL_48;
    }
  }
  else
  {
    v84 = nullptr;
  }
  v85 = *(unsigned __int8 *)(a1 + 11369);
  if ( v85 != 1 )
    goto LABEL_18;
  if ( (mlme_get_tdls_chan_switch_prohibited(*(_QWORD *)(a4 + 16), v73, v74, v75, v76, v77, v78, v79, v80) & 1) != 0 )
  {
    v85 = *(unsigned __int8 *)(a1 + 11369);
LABEL_18:
    tdls_chan_switch_prohibited = mlme_get_tdls_chan_switch_prohibited(
                                    *(_QWORD *)(a4 + 16),
                                    v73,
                                    v74,
                                    v75,
                                    v76,
                                    v77,
                                    v78,
                                    v79,
                                    v80);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: TDLS offchan not enabled, or channel switch prohibited by AP, gLimTDLSOffChannelEnabled: %d tdls_chan_swit_prohibited: %d",
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      v94,
      "lim_send_tdls_dis_rsp_frame",
      v85,
      tdls_chan_switch_prohibited & 1);
    goto LABEL_19;
  }
  populate_dot11f_tdls_offchannel_params(a1, a4, v21 + 34, v21 + 132);
  if ( *(_DWORD *)(*(_QWORD *)(a1 + 8) + 1032LL) != 1 )
  {
    v131 = *(_BYTE *)(v21 + 629);
    *(_BYTE *)(v21 + 628) = 1;
    *(_BYTE *)(v21 + 629) = v131 | 1;
  }
LABEL_19:
  packed_tdls_dis_rsp_size = dot11f_get_packed_tdls_dis_rsp_size(a1, v21, (int *)&v187);
  if ( (packed_tdls_dis_rsp_size & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to calculate the packed size for a Discovery Response (0x%08x)",
      v96,
      v97,
      v98,
      v99,
      v100,
      v101,
      v102,
      v103,
      "lim_send_tdls_dis_rsp_frame",
      packed_tdls_dis_rsp_size);
    v187 = 1160;
  }
  else if ( packed_tdls_dis_rsp_size )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while calculating the packed size for a Discovery Response (0x%08x)",
      v96,
      v97,
      v98,
      v99,
      v100,
      v101,
      v102,
      v103,
      "lim_send_tdls_dis_rsp_frame");
  }
  v104 = a6 + (unsigned __int16)v81 + v187 + v184[0];
  if ( (unsigned int)cds_packet_alloc(a6 + (unsigned __int16)v81 + (unsigned __int16)v187 + v184[0] + 24, &v186, &v185) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to allocate %d bytes for a TDLS Discovery Request",
      v105,
      v106,
      v107,
      v108,
      v109,
      v110,
      v111,
      v112,
      "lim_send_tdls_dis_rsp_frame",
      (unsigned int)(v104 + 24));
LABEL_46:
    _qdf_mem_free((__int64)v84);
    goto LABEL_47;
  }
  qdf_mem_set(v186, (unsigned int)(v104 + 24), 0);
  if ( (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(a4 + 16), v113, v114, v115, v116, v117, v118, v119, v120) & 1) == 0 )
  {
    v130 = (const void *)(a4 + 30);
    goto LABEL_31;
  }
  v129 = *(_QWORD *)(*(_QWORD *)(a4 + 16) + 1360LL);
  if ( v129 )
  {
    v130 = (const void *)(v129 + 17);
LABEL_31:
    qdf_mem_copy(&v189, v130, 6u);
    goto LABEL_32;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: mlo_dev_ctx is NULL",
    v121,
    v122,
    v123,
    v124,
    v125,
    v126,
    v127,
    v128,
    "lim_tdls_copy_self_mac");
LABEL_32:
  lim_populate_mac_header(a1, (__int64)v186, 0, 13, &v191, &v189);
  v132 = v186;
  *(_WORD *)v186 &= 0xEEFFu;
  v132[16] = *(_BYTE *)(a4 + 24);
  v132[17] = *(_BYTE *)(a4 + 25);
  v132[18] = *(_BYTE *)(a4 + 26);
  v132[19] = *(_BYTE *)(a4 + 27);
  v132[20] = *(_BYTE *)(a4 + 28);
  v132[21] = *(_BYTE *)(a4 + 29);
  v133 = dot11f_pack_tdls_dis_rsp(a1, v21, v186 + 24, v187, &v187);
  if ( (v133 & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to pack a TDLS discovery response (0x%08x)",
      v134,
      v135,
      v136,
      v137,
      v138,
      v139,
      v140,
      v141,
      "lim_send_tdls_dis_rsp_frame",
      v133);
    cds_packet_free((__int64)v185);
    goto LABEL_46;
  }
  if ( v133 )
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while packing TDLS Discovery Response (0x%08x)",
      v134,
      v135,
      v136,
      v137,
      v138,
      v139,
      v140,
      v141,
      "lim_send_tdls_dis_rsp_frame");
  if ( v184[0] )
  {
    qdf_mem_copy(&v186[v187 + 24], v84, v184[0]);
    _qdf_mem_free((__int64)v84);
    v187 += v184[0];
  }
  if ( (_WORD)v81 )
  {
    if ( (unsigned int)lim_fill_complete_mlo_ie(a4, v81, &v186[v187 + 24]) )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: assemble ml ie error",
        v142,
        v143,
        v144,
        v145,
        v146,
        v147,
        v148,
        v149,
        "lim_send_tdls_dis_rsp_frame");
      LOWORD(v81) = 0;
    }
    v187 += (unsigned __int16)v81;
  }
  lim_cp_stats_cstats_log_disc_resp_evt((char *)v21, a4);
  _qdf_mem_free(v21);
  if ( a6 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Copy Additional Ie Len: %d",
      v150,
      v151,
      v152,
      v153,
      v154,
      v155,
      v156,
      v157,
      "lim_send_tdls_dis_rsp_frame",
      a6);
    qdf_mem_copy(&v186[v187 + 24], a5, a6);
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: [TDLS] action: %d (%s) -DIRECT-> OTA peer=%02x:%02x:%02x:**:**:%02x",
    v150,
    v151,
    v152,
    v153,
    v154,
    v155,
    v156,
    v157,
    "lim_send_tdls_dis_rsp_frame",
    14,
    "TDLS_DISCOVERY_RESPONSE",
    (unsigned __int8)v191,
    BYTE1(v191),
    BYTE2(v191),
    HIBYTE(v192));
  v158 = (unsigned __int8 *)v186;
  *(_DWORD *)(a1 + 12368) = *(unsigned __int8 *)(a4 + 10);
  lim_diag_mgmt_tx_event_report(a1, v158, a4, 0, 0, v159, v160, v161, v162, v163, v164, v165, v166);
  context = _cds_get_context(54, (__int64)"lim_send_tdls_dis_rsp_frame", v167, v168, v169, v170, v171, v172, v173, v174);
  result = wma_tx_packet(
             (__int64)context,
             v185,
             (unsigned __int16)v104 + 24,
             3u,
             v176,
             v177,
             v178,
             v179,
             v180,
             v181,
             v182,
             v183,
             0,
             0,
             lim_tx_complete,
             v186,
             (__int64)lim_mgmt_tdls_tx_complete,
             2,
             v22,
             0,
             0,
             0xCu,
             0,
             0x40Eu);
  if ( (_DWORD)result )
  {
    v82 = "%s: could not send TDLS Discovery Response frame!";
    *(_DWORD *)(a1 + 12368) = 255;
    goto LABEL_9;
  }
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return result;
}
