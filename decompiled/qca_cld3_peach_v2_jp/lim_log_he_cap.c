void __fastcall lim_log_he_cap(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  unsigned int v10; // w8
  __int64 v11; // x19
  unsigned int v12; // w8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned __int64 v30; // x8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned __int64 v39; // x8
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
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
  unsigned int v64; // w8
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  unsigned __int64 v73; // x8
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  unsigned __int64 v82; // x8
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  unsigned __int64 v91; // x8
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
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  unsigned int v124; // t1
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  __int64 v133; // [xsp+0h] [xbp-20h]
  __int64 v134; // [xsp+0h] [xbp-20h]
  __int64 v135; // [xsp+0h] [xbp-20h]
  __int64 v136; // [xsp+0h] [xbp-20h]
  __int64 v137; // [xsp+0h] [xbp-20h]
  __int64 v138; // [xsp+0h] [xbp-20h]
  __int64 v139; // [xsp+0h] [xbp-20h]
  __int64 v140; // [xsp+0h] [xbp-20h]
  __int64 v141; // [xsp+0h] [xbp-20h]
  __int64 v142; // [xsp+0h] [xbp-20h]
  __int64 v143; // [xsp+8h] [xbp-18h]
  __int64 v144; // [xsp+8h] [xbp-18h]
  __int64 v145; // [xsp+8h] [xbp-18h]
  __int64 v146; // [xsp+8h] [xbp-18h]

  if ( *(_BYTE *)a10 )
  {
    v10 = *(_DWORD *)(a10 + 1);
    v11 = a10;
    qdf_trace_msg(
      0x35u,
      8u,
      "HE Capabilities: htc_he 0x%x twt_req 0x%x twt_res 0x%x fragmentation 0x%x max frag msdu amsdu 0x%x min frag 0x%x",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      v10 & 1,
      (v10 >> 1) & 1,
      (v10 >> 2) & 1,
      (v10 >> 3) & 3,
      (unsigned __int8)v10 >> 5,
      (v10 >> 8) & 3);
    v12 = *(_DWORD *)(v11 + 1);
    LODWORD(v133) = (v12 >> 19) & 1;
    qdf_trace_msg(
      0x35u,
      8u,
      "\ttrig frm mac pad 0x%x multi tid aggr supp 0x%x link adaptation 0x%x all ack 0x%x trigd_rsp_sched 0x%x a_bsr 0x%x",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      (v12 >> 10) & 3,
      (v12 >> 12) & 7,
      (v12 >> 15) & 3,
      (v12 >> 17) & 1,
      (v12 >> 18) & 1,
      v133);
    v21 = *(_DWORD *)(v11 + 1);
    LODWORD(v134) = (v21 >> 26) & 1;
    qdf_trace_msg(
      0x35u,
      8u,
      "\tBC twt 0x%x ba_32bit_bitmap supp 0x%x mu_cascade 0x%x ack_enabled_multitid 0x%x omi_a_ctrl 0x%x ofdma_ra 0x%x",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      (v21 >> 20) & 1,
      (v21 >> 21) & 1,
      (v21 >> 22) & 1,
      (v21 >> 23) & 1,
      (v21 >> 25) & 1,
      v134);
    v30 = *(_QWORD *)(v11 + 1);
    LODWORD(v135) = (v30 >> 33) & 1;
    qdf_trace_msg(
      0x35u,
      8u,
      "\tmax_ampdu_len exp ext 0x%x amsdu_frag 0x%x flex_twt_sched 0x%x rx_ctrl frm 0x%x bsrp_ampdu_aggr 0x%x qtp 0x%x a_bqr 0x%x",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      ((unsigned int)v30 >> 27) & 3,
      ((unsigned int)v30 >> 29) & 1,
      ((unsigned int)v30 >> 30) & 1,
      (v30 >> 31) & 1,
      HIDWORD(v30) & 1,
      v135,
      (v30 >> 34) & 1);
    v39 = *(_QWORD *)(v11 + 1);
    LODWORD(v136) = (v39 >> 43) & 1;
    qdf_trace_msg(
      0x35u,
      8u,
      "\tSR Reponder 0x%x ndp_feedback 0x%x ops_supp 0x%x amsdu_in_ampdu 0x%x multi_tid_aggr_tx 0x%x he_sub_ch_sel_tx 0x%x",
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      (v39 >> 35) & 1,
      (v39 >> 36) & 1,
      (v39 >> 37) & 1,
      (v39 >> 38) & 1,
      (v39 >> 40) & 7,
      v136);
    qdf_trace_msg(
      0x35u,
      8u,
      "\tul_2x996_tone_ru 0x%x om_ctrl_ul_mu_data_dis_rx 0x%x dynamic_smps 0x%x punctured_sounding 0x%x ht_vht_trg_frm_rx 0x%x",
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      (*(_QWORD *)(v11 + 1) >> 44) & 1LL,
      (*(_QWORD *)(v11 + 1) >> 45) & 1LL,
      (*(_QWORD *)(v11 + 1) >> 46) & 1LL,
      (*(_QWORD *)(v11 + 1) >> 47) & 1LL,
      HIWORD(*(_QWORD *)(v11 + 1)) & 1LL);
    LODWORD(v137) = *(_DWORD *)(v11 + 9) & 3;
    qdf_trace_msg(
      0x35u,
      8u,
      "\tchan width %d rx_pream_puncturing 0x%x device_class 0x%x ldpc_coding 0x%x 1x_ltf_800_gi_ppdu 0x%x midamble_tx_rx_max_nsts 0x%x",
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      (*(_QWORD *)(v11 + 1) >> 50) & 0x7FLL,
      (*(_QWORD *)(v11 + 1) >> 57) & 0xFLL,
      (*(_QWORD *)(v11 + 1) >> 61) & 1LL,
      (*(_QWORD *)(v11 + 1) >> 62) & 1LL,
      *(_QWORD *)(v11 + 1) >> 63,
      v137);
    v64 = *(_DWORD *)(v11 + 9);
    LODWORD(v138) = (v64 >> 9) & 7;
    LODWORD(v143) = (v64 >> 12) & 7;
    qdf_trace_msg(
      0x35u,
      8u,
      "\t4x_ltf_3200_gi_ndp 0x%x tb_ppdu_tx_stbc_lt_80mhz 0x%x rx_stbc_lt_80mhz 0x%x doppler 0x%x ul_mu 0x%x dcm_enc_tx 0"
      "x%x dcm_enc_rx 0x%x",
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      (v64 >> 2) & 1,
      (v64 >> 3) & 1,
      (v64 >> 4) & 1,
      (v64 >> 5) & 3,
      (v64 >> 7) & 3,
      v138,
      v143);
    v73 = *(_QWORD *)(v11 + 9);
    LODWORD(v139) = BYTE3(v73) & 7;
    LODWORD(v144) = ((unsigned int)v73 >> 27) & 7;
    qdf_trace_msg(
      0x35u,
      8u,
      "\tul_he_mu 0x%x su_bfer 0x%x su_fee 0x%x mu_bfer 0x%x bfee_sts_lt_80 0x%x bfee_sts_gt_80 0x%x num_sd_lt_80 0x%x num_sd_gt_80 0x%x",
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      ((unsigned int)v73 >> 15) & 1,
      WORD1(v73) & 1,
      ((unsigned int)v73 >> 17) & 1,
      ((unsigned int)v73 >> 18) & 1,
      ((unsigned int)v73 >> 19) & 7,
      v139,
      v144,
      (v73 >> 30) & 7);
    v82 = *(_QWORD *)(v11 + 9);
    LODWORD(v140) = (v82 >> 40) & 1;
    LODWORD(v145) = (v82 >> 41) & 1;
    qdf_trace_msg(
      0x35u,
      8u,
      "\tsu_fb_tone16 0x%x mu_fb_tone16 0x%x codebook_su 0x%x codebook_mu 0x%x bforming_feedback 0x%x he_er_su_ppdu 0x%x "
      "dl_mu_mimo_part_bw 0x%x",
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      (v82 >> 33) & 1,
      (v82 >> 34) & 1,
      (v82 >> 35) & 1,
      (v82 >> 36) & 1,
      (v82 >> 37) & 7,
      v140,
      v145);
    v91 = *(_QWORD *)(v11 + 9);
    LODWORD(v141) = (v91 >> 50) & 1;
    LODWORD(v146) = (v91 >> 46) & 7;
    qdf_trace_msg(
      0x35u,
      8u,
      "\tppet_present 0x%x srp 0x%x power_boost 0x%x ltf_800_gi_4x 0x%x tb_ppdu_tx_stbc_gt_80mhz 0x%x rx_stbc_gt_80mhz 0x%x max_nc 0x%x",
      v92,
      v93,
      v94,
      v95,
      v96,
      v97,
      v98,
      v99,
      (v91 >> 42) & 1,
      (v91 >> 43) & 1,
      (v91 >> 44) & 1,
      (v91 >> 45) & 1,
      (v91 >> 49) & 1,
      v141,
      v146);
    qdf_trace_msg(
      0x35u,
      8u,
      "\ter_ltf_800_gi_4x 0x%x ppdu_20_in_40Mhz_2G 0x%x ppdu_20_in_160_80p80Mhz 0x%x ppdu_80_in_160_80p80Mhz 0x%x er_1x_ltf_gi 0x%x",
      v100,
      v101,
      v102,
      v103,
      v104,
      v105,
      v106,
      v107,
      (*(_QWORD *)(v11 + 9) >> 51) & 1LL,
      (*(_QWORD *)(v11 + 9) >> 52) & 1LL,
      (*(_QWORD *)(v11 + 9) >> 53) & 1LL,
      (*(_QWORD *)(v11 + 9) >> 54) & 1LL,
      (*(_QWORD *)(v11 + 9) >> 55) & 1LL);
    qdf_trace_msg(
      0x35u,
      8u,
      "\tmidamble_tx_rx_1x_ltf 0x%x dcm_max_bw 0x%x longer_than_16_he_sigb_ofdm_sym 0x%x non_trig_cqi_feedback 0x%x tx_10"
      "24_qam_lt_242_tone_ru 0x%x",
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      v114,
      v115,
      HIBYTE(*(_QWORD *)(v11 + 9)) & 1LL,
      (*(_QWORD *)(v11 + 9) >> 57) & 3LL,
      (*(_QWORD *)(v11 + 9) >> 59) & 1LL,
      (*(_QWORD *)(v11 + 9) >> 60) & 1LL,
      (*(_QWORD *)(v11 + 9) >> 61) & 1LL);
    qdf_trace_msg(
      0x35u,
      8u,
      "\trx_1024_qam_lt_242_tone_ru 0x%x rx_full_bw_su_he_mu_compress_sigb 0x%x rx_he_mcs_map_lt_80 0x%x tx_he_mcs_map_lt_80 0x%x",
      v116,
      v117,
      v118,
      v119,
      v120,
      v121,
      v122,
      v123,
      (*(_QWORD *)(v11 + 9) >> 62) & 1LL,
      *(_QWORD *)(v11 + 9) >> 63,
      *(unsigned __int16 *)(v11 + 20),
      *(unsigned __int16 *)(v11 + 22));
    v124 = *(unsigned __int8 *)(v11 + 32);
    v11 += 32;
    LODWORD(v142) = (v124 >> 3) & 0xF;
    qdf_trace_msg(
      0x35u,
      8u,
      "\tRx MCS map 160 Mhz: 0x%x Tx MCS map 160 Mhz: 0x%x Rx MCS map 80+80 Mhz: 0x%x Tx MCS map 80+80 Mhz: 0x%x ppe_th::"
      " nss_count: %d, ru_idx_msk: %d",
      v125,
      v126,
      v127,
      v128,
      v129,
      v130,
      v131,
      v132,
      *(unsigned __int16 *)(v11 - 8),
      *(unsigned __int16 *)(v11 - 6),
      *(unsigned __int16 *)(v11 - 4),
      *(unsigned __int16 *)(v11 - 2),
      v124 & 7,
      v142);
    ((void (__fastcall *)(__int64, __int64, __int64, __int64))qdf_trace_hex_dump)(53, 8, v11, 25);
  }
}
