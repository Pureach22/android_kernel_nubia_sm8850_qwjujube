__int64 __fastcall lim_send_tdls_dis_rsp_frame(
        __int64 a1,
        unsigned __int64 a2,
        char a3,
        __int64 a4,
        const void *a5,
        unsigned __int16 a6)
{
  unsigned __int64 v6; // x27
  int v8; // w24
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x22
  unsigned __int8 v23; // w26
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
  unsigned int v65; // w24
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  unsigned int v74; // w24
  char tdls_chan_switch_prohibited; // w0
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  unsigned int packed_tdls_dis_rsp_size; // w0
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  const char *v93; // x2
  __int64 result; // x0
  unsigned int v95; // w25
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  char *v104; // x8
  unsigned int v105; // w0
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  unsigned __int8 *v122; // x1
  double v123; // d0
  double v124; // d1
  double v125; // d2
  double v126; // d3
  double v127; // d4
  double v128; // d5
  double v129; // d6
  double v130; // d7
  double v131; // d0
  double v132; // d1
  double v133; // d2
  double v134; // d3
  double v135; // d4
  double v136; // d5
  double v137; // d6
  double v138; // d7
  _QWORD *context; // x0
  double v140; // d0
  double v141; // d1
  double v142; // d2
  double v143; // d3
  double v144; // d4
  double v145; // d5
  double v146; // d6
  double v147; // d7
  char v148; // w8
  _QWORD *v149; // [xsp+48h] [xbp-38h] BYREF
  char *v150; // [xsp+50h] [xbp-30h] BYREF
  unsigned int v151; // [xsp+58h] [xbp-28h] BYREF
  unsigned __int16 v152; // [xsp+5Ch] [xbp-24h] BYREF
  int v153; // [xsp+60h] [xbp-20h] BYREF
  __int16 v154; // [xsp+64h] [xbp-1Ch]
  int v155; // [xsp+68h] [xbp-18h] BYREF
  __int16 v156; // [xsp+6Ch] [xbp-14h]
  int v157; // [xsp+70h] [xbp-10h] BYREF
  __int16 v158; // [xsp+74h] [xbp-Ch]
  __int64 v159; // [xsp+78h] [xbp-8h]

  v6 = HIDWORD(a2);
  v8 = a2;
  v159 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v155 = a2;
  v156 = WORD2(a2);
  v152 = 0;
  v151 = 0;
  v149 = nullptr;
  v150 = nullptr;
  v154 = 0;
  v153 = 0;
  v13 = _qdf_mem_malloc(0x2D8u, "lim_send_tdls_dis_rsp_frame", 1653);
  if ( !v13 )
  {
    v93 = "%s: memory allocation failed for DisRsp";
LABEL_14:
    result = qdf_trace_msg(0x35u, 2u, v93, v14, v15, v16, v17, v18, v19, v20, v21, "lim_send_tdls_dis_rsp_frame");
    goto LABEL_29;
  }
  v22 = v13;
  v23 = *(_BYTE *)(a4 + 10);
  *(_BYTE *)(v13 + 2) = a3;
  *(_WORD *)v13 = 3588;
  v158 = v6;
  v157 = v8;
  qdf_mem_copy((void *)(v13 + 631), (const void *)(a4 + 24), 6u);
  qdf_mem_copy((void *)(v22 + 643), (const void *)(a4 + 30), 6u);
  qdf_mem_copy((void *)(v22 + 637), &v157, 6u);
  *(_BYTE *)(v22 + 630) = 1;
  if ( (unsigned int)lim_get_capability_info(a1, (__int16 *)&v152, a4, v24, v25, v26, v27, v28, v29, v30, v31) )
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
      "lim_send_tdls_dis_rsp_frame");
  swap_bit_field16(v152, (_WORD *)(v22 + 4));
  v48 = wlan_reg_freq_to_chan(*(_QWORD *)(a1 + 21560), *(_DWORD *)(a4 + 284), v40, v41, v42, v43, v44, v45, v46, v47);
  if ( (unsigned int)populate_dot11f_rates_tdls(
                       a1,
                       (_BYTE *)(v22 + 6),
                       (_BYTE *)(v22 + 20),
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
      "lim_send_tdls_dis_rsp_frame");
  populate_dot11f_tdls_ext_capability(a1, a4, v22 + 312);
  v65 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 5748LL);
  populate_dot11f_tdls_ht_vht_cap(a1, v65, v22 + 568, v22 + 652, a4);
  populate_dot11f_set_tdls_he_cap(a1, v65, v22 + 668);
  v74 = *(unsigned __int8 *)(a1 + 11369);
  if ( v74 != 1 )
    goto LABEL_9;
  if ( (mlme_get_tdls_chan_switch_prohibited(*(_QWORD *)(a4 + 16), v66, v67, v68, v69, v70, v71, v72, v73) & 1) != 0 )
  {
    v74 = *(unsigned __int8 *)(a1 + 11369);
LABEL_9:
    tdls_chan_switch_prohibited = mlme_get_tdls_chan_switch_prohibited(
                                    *(_QWORD *)(a4 + 16),
                                    v66,
                                    v67,
                                    v68,
                                    v69,
                                    v70,
                                    v71,
                                    v72,
                                    v73);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: TDLS offchan not enabled, or channel switch prohibited by AP, gLimTDLSOffChannelEnabled: %d tdls_chan_swit_prohibited: %d",
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      "lim_send_tdls_dis_rsp_frame",
      v74,
      tdls_chan_switch_prohibited & 1);
    goto LABEL_10;
  }
  populate_dot11f_tdls_offchannel_params(a1, a4, v22 + 34, v22 + 132);
  if ( *(_DWORD *)(*(_QWORD *)(a1 + 8) + 1032LL) != 1 )
  {
    v148 = *(_BYTE *)(v22 + 629);
    *(_BYTE *)(v22 + 628) = 1;
    *(_BYTE *)(v22 + 629) = v148 | 1;
  }
LABEL_10:
  packed_tdls_dis_rsp_size = dot11f_get_packed_tdls_dis_rsp_size(a1, v22, (int *)&v151);
  if ( (packed_tdls_dis_rsp_size & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to calculate the packed size for a Discovery Response (0x%08x)",
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      "lim_send_tdls_dis_rsp_frame",
      packed_tdls_dis_rsp_size);
    v151 = 1160;
  }
  else if ( packed_tdls_dis_rsp_size )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while calculating the packed size for a Discovery Response (0x%08x)",
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      "lim_send_tdls_dis_rsp_frame");
  }
  v95 = a6 + v151;
  if ( (unsigned int)cds_packet_alloc(a6 + (unsigned __int16)v151 + 24, &v150, &v149) )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to allocate %d bytes for a TDLS Discovery Request",
      v96,
      v97,
      v98,
      v99,
      v100,
      v101,
      v102,
      v103,
      "lim_send_tdls_dis_rsp_frame",
      v95 + 24);
LABEL_28:
    _qdf_mem_free(0);
    result = _qdf_mem_free(v22);
    goto LABEL_29;
  }
  qdf_mem_set(v150, v95 + 24, 0);
  qdf_mem_copy(&v153, (const void *)(a4 + 30), 6u);
  lim_populate_mac_header(a1, (__int64)v150, 0, 13, &v155, &v153);
  v104 = v150;
  *(_WORD *)v150 &= 0xEEFFu;
  v104[16] = *(_BYTE *)(a4 + 24);
  v104[17] = *(_BYTE *)(a4 + 25);
  v104[18] = *(_BYTE *)(a4 + 26);
  v104[19] = *(_BYTE *)(a4 + 27);
  v104[20] = *(_BYTE *)(a4 + 28);
  v104[21] = *(_BYTE *)(a4 + 29);
  v105 = dot11f_pack_tdls_dis_rsp(a1, v22, v150 + 24, v151, &v151);
  if ( (v105 & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to pack a TDLS discovery response (0x%08x)",
      v106,
      v107,
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      "lim_send_tdls_dis_rsp_frame",
      v105);
    cds_packet_free((__int64)v149);
    goto LABEL_28;
  }
  if ( v105 )
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while packing TDLS Discovery Response (0x%08x)",
      v106,
      v107,
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      "lim_send_tdls_dis_rsp_frame");
  lim_cp_stats_cstats_log_disc_resp_evt((char *)v22, a4);
  _qdf_mem_free(v22);
  if ( a6 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Copy Additional Ie Len: %d",
      v114,
      v115,
      v116,
      v117,
      v118,
      v119,
      v120,
      v121,
      "lim_send_tdls_dis_rsp_frame",
      a6);
    qdf_mem_copy(&v150[v151 + 24], a5, a6);
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: [TDLS] action: %d (%s) -DIRECT-> OTA peer=%02x:%02x:%02x:**:**:%02x",
    v114,
    v115,
    v116,
    v117,
    v118,
    v119,
    v120,
    v121,
    "lim_send_tdls_dis_rsp_frame",
    14,
    "TDLS_DISCOVERY_RESPONSE",
    (unsigned __int8)v155,
    BYTE1(v155),
    BYTE2(v155),
    HIBYTE(v156));
  v122 = (unsigned __int8 *)v150;
  *(_DWORD *)(a1 + 12368) = *(unsigned __int8 *)(a4 + 10);
  lim_diag_mgmt_tx_event_report(a1, v122, a4, 0, 0, v123, v124, v125, v126, v127, v128, v129, v130);
  context = _cds_get_context(54, (__int64)"lim_send_tdls_dis_rsp_frame", v131, v132, v133, v134, v135, v136, v137, v138);
  result = wma_tx_packet(
             (__int64)context,
             v149,
             (unsigned __int16)v95 + 24,
             3u,
             v140,
             v141,
             v142,
             v143,
             v144,
             v145,
             v146,
             v147,
             0,
             0,
             lim_tx_complete,
             v150,
             (__int64)lim_mgmt_tdls_tx_complete,
             2,
             v23,
             0,
             0,
             0xCu,
             0);
  if ( (_DWORD)result )
  {
    v93 = "%s: could not send TDLS Discovery Response frame!";
    *(_DWORD *)(a1 + 12368) = 255;
    goto LABEL_14;
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
