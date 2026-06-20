__int64 __fastcall wma_config_stats_ext_threshold(
        __int64 *a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x19
  _DWORD *v22; // x23
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
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  int v71; // w8
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
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
  double v112; // d0
  double v113; // d1
  double v114; // d2
  double v115; // d3
  double v116; // d4
  double v117; // d5
  double v118; // d6
  double v119; // d7
  double v120; // d0
  double v121; // d1
  double v122; // d2
  double v123; // d3
  double v124; // d4
  double v125; // d5
  double v126; // d6
  double v127; // d7
  double v128; // d0
  double v129; // d1
  double v130; // d2
  double v131; // d3
  double v132; // d4
  double v133; // d5
  double v134; // d6
  double v135; // d7
  double v136; // d0
  double v137; // d1
  double v138; // d2
  double v139; // d3
  double v140; // d4
  double v141; // d5
  double v142; // d6
  double v143; // d7
  int v144; // [xsp+0h] [xbp-10h]

  if ( !a2 )
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: Invalid threshold input",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "wma_config_stats_ext_threshold");
  result = wmi_buf_alloc_fl(*a1, 0xD8u, "wma_config_stats_ext_threshold", 0xCA5u);
  if ( result )
  {
    v21 = result;
    v22 = *(_DWORD **)(result + 224);
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Setting fixed parameters. tag=%d, len=%d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wma_config_stats_ext_threshold",
      581,
      28);
    *v22 = 38076444;
    v22[1] = a2[1];
    v22[2] = a2[2];
    v22[3] = a2[4];
    v22[4] = a2[5];
    v22[5] = a2[6];
    v22[6] = a2[7];
    v22[7] = a2[8];
    v22[8] = 37814304;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Setting cca parameters. tag=%d, len=%d",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "wma_config_stats_ext_threshold",
      577,
      32);
    v22[9] = a2[9];
    v22[10] = a2[10];
    v22[11] = a2[11];
    v22[12] = a2[12];
    v22[13] = a2[13];
    v22[14] = a2[14];
    v22[15] = a2[15];
    v22[16] = a2[16];
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: idle time=%d, tx_time=%d, in_bss=%d, out_bss=%d",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "wma_config_stats_ext_threshold");
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: rx_busy=%d, rx_bad=%d, tx_bad=%d, not_avail=%d",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      "wma_config_stats_ext_threshold",
      (unsigned int)v22[13],
      (unsigned int)v22[14],
      (unsigned int)v22[15],
      (unsigned int)v22[16]);
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Setting signal parameters. tag=%d, len=%d",
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      "wma_config_stats_ext_threshold",
      578,
      8);
    v22[17] = 37879816;
    v22[18] = a2[17];
    v22[19] = a2[18];
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: snr=%d, nf=%d",
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      "wma_config_stats_ext_threshold");
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Setting TX parameters. tag=%d, len=%d",
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      "wma_config_stats_ext_threshold",
      579,
      80);
    v22[20] = 37945396;
    v22[21] = a2[19];
    v22[22] = a2[20];
    v22[23] = a2[21];
    v22[24] = a2[22];
    v71 = a2[23];
    v22[25] = v71;
    v22[26] = a2[24];
    v22[27] = a2[25];
    v22[28] = a2[26];
    v22[29] = a2[27];
    v22[30] = a2[28];
    v22[31] = a2[29];
    v22[32] = a2[30];
    v22[33] = a2[31];
    v144 = v71;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: msdu=%d, mpdu=%d, ppdu=%d, bytes=%d, msdu_drop=%d",
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      "wma_config_stats_ext_threshold",
      v144);
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: byte_drop=%d, mpdu_retry=%d, mpdu_fail=%d, ppdu_fail=%d",
      v80,
      v81,
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      "wma_config_stats_ext_threshold",
      (unsigned int)v22[26],
      (unsigned int)v22[27],
      (unsigned int)v22[28],
      (unsigned int)v22[29]);
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: aggr=%d, succ_mcs=%d, fail_mcs=%d, delay=%d",
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      v94,
      v95,
      "wma_config_stats_ext_threshold",
      (unsigned int)v22[30],
      (unsigned int)v22[31],
      (unsigned int)v22[32],
      (unsigned int)v22[33]);
    v22[34] = 38010936;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Setting RX parameters. tag=%d, len=%d",
      v96,
      v97,
      v98,
      v99,
      v100,
      v101,
      v102,
      v103,
      "wma_config_stats_ext_threshold",
      580,
      56);
    v22[35] = a2[32];
    v22[36] = a2[33];
    v22[37] = a2[34];
    v22[38] = a2[35];
    v22[39] = a2[36];
    v22[40] = a2[38];
    v22[41] = a2[39];
    v22[42] = a2[40];
    v22[43] = a2[41];
    v22[44] = a2[42];
    v22[45] = a2[43];
    v22[46] = a2[44];
    v22[47] = a2[45];
    v22[48] = a2[46];
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: rx_mpdu=%d, rx_bytes=%d, rx_ppdu=%d, rx_pbytes=%d",
      v104,
      v105,
      v106,
      v107,
      v108,
      v109,
      v110,
      v111,
      "wma_config_stats_ext_threshold");
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: disorder=%d, rx_dup=%d, rx_aggr=%d, rx_mcs=%d",
      v112,
      v113,
      v114,
      v115,
      v116,
      v117,
      v118,
      v119,
      "wma_config_stats_ext_threshold",
      (unsigned int)v22[39],
      (unsigned int)v22[41],
      (unsigned int)v22[43],
      (unsigned int)v22[44]);
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: rx_ind=%d, rx_dur=%d, rx_probe=%d, rx_mgmt=%d",
      v120,
      v121,
      v122,
      v123,
      v124,
      v125,
      v126,
      v127,
      "wma_config_stats_ext_threshold",
      (unsigned int)v22[45],
      (unsigned int)v22[46],
      (unsigned int)v22[47],
      (unsigned int)v22[48]);
    qdf_trace_msg(
      0x36u,
      1u,
      "%s: WMA --> WMI_PDEV_SET_STATS_THRESHOLD_CMDID(0x%x), length=%d",
      v128,
      v129,
      v130,
      v131,
      v132,
      v133,
      v134,
      v135,
      "wma_config_stats_ext_threshold",
      16423,
      196);
    result = wmi_unified_cmd_send_fl(
               *a1,
               v21,
               0xC4u,
               0x4027u,
               "wma_config_stats_ext_threshold",
               0xD17u,
               v136,
               v137,
               v138,
               v139,
               v140,
               v141,
               v142,
               v143);
    if ( (_DWORD)result )
      return wmi_buf_free();
  }
  return result;
}
