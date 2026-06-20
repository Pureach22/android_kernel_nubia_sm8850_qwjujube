__int64 __fastcall wmi_stats_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned int **a10,
        int a11,
        __int64 a12)
{
  unsigned int *v12; // x22
  _DWORD *v15; // x24
  int v16; // w21
  unsigned int v17; // w25
  __int64 v18; // x23
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  _DWORD *v35; // x22
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
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
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  double v132; // d0
  double v133; // d1
  double v134; // d2
  double v135; // d3
  double v136; // d4
  double v137; // d5
  double v138; // d6
  double v139; // d7
  double v140; // d0
  double v141; // d1
  double v142; // d2
  double v143; // d3
  double v144; // d4
  double v145; // d5
  double v146; // d6
  double v147; // d7
  double v148; // d0
  double v149; // d1
  double v150; // d2
  double v151; // d3
  double v152; // d4
  double v153; // d5
  double v154; // d6
  double v155; // d7
  double v156; // d0
  double v157; // d1
  double v158; // d2
  double v159; // d3
  double v160; // d4
  double v161; // d5
  double v162; // d6
  double v163; // d7
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
  double v180; // d0
  double v181; // d1
  double v182; // d2
  double v183; // d3
  double v184; // d4
  double v185; // d5
  double v186; // d6
  double v187; // d7
  double v188; // d0
  double v189; // d1
  double v190; // d2
  double v191; // d3
  double v192; // d4
  double v193; // d5
  double v194; // d6
  double v195; // d7
  double v196; // d0
  double v197; // d1
  double v198; // d2
  double v199; // d3
  double v200; // d4
  double v201; // d5
  double v202; // d6
  double v203; // d7
  double v204; // d0
  double v205; // d1
  double v206; // d2
  double v207; // d3
  double v208; // d4
  double v209; // d5
  double v210; // d6
  double v211; // d7
  double v212; // d0
  double v213; // d1
  double v214; // d2
  double v215; // d3
  double v216; // d4
  double v217; // d5
  double v218; // d6
  double v219; // d7
  double v220; // d0
  double v221; // d1
  double v222; // d2
  double v223; // d3
  double v224; // d4
  double v225; // d5
  double v226; // d6
  double v227; // d7
  __int64 result; // x0
  _DWORD *v229; // x22
  double v230; // d0
  double v231; // d1
  double v232; // d2
  double v233; // d3
  double v234; // d4
  double v235; // d5
  double v236; // d6
  double v237; // d7
  unsigned int v238; // w8
  double v239; // d0
  double v240; // d1
  double v241; // d2
  double v242; // d3
  double v243; // d4
  double v244; // d5
  double v245; // d6
  double v246; // d7
  double v247; // d0
  double v248; // d1
  double v249; // d2
  double v250; // d3
  double v251; // d4
  double v252; // d5
  double v253; // d6
  double v254; // d7
  _DWORD *v255; // x8
  __int64 v256; // x20
  __int64 v257; // [xsp+0h] [xbp-10h]
  __int64 v258; // [xsp+8h] [xbp-8h]

  if ( a10 )
  {
    v12 = *a10;
    v18 = *(unsigned __int16 *)*a10;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Fixed param more %d req_id %d status %d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "wmi_stats_handler",
      (*a10)[2],
      (*a10)[1],
      (*a10)[3]);
    v15 = (unsigned int *)((char *)v12 + v18 + 4);
    v16 = a11 - (v18 + 4);
    *(_DWORD *)(a12 + 4) = v12[1];
    *(_DWORD *)(a12 + 8) = v12[3];
    v17 = HIWORD(*v15);
    LODWORD(v18) = (unsigned __int16)*v15;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: curr_tlv_len %d curr_tlv_tag %d rem_len %d",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "wmi_stats_handler",
      (unsigned int)v16,
      (unsigned __int16)*v15,
      v17);
    while ( 1 )
    {
      result = 0;
      if ( v17 < 0x10 || v16 < (unsigned int)v18 )
        break;
      if ( v17 == 18 )
      {
        v16 -= 4;
        if ( v16 < 1 )
          return 0;
        ++v15;
      }
      v17 = (unsigned __int16)HIWORD(*v15);
      v18 = (unsigned __int16)*v15;
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: curr_tlv_len %d curr_tlv_tag %d rem_len %d",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "wmi_stats_handler",
        (unsigned int)v16,
        v18,
        (unsigned __int16)HIWORD(*v15));
      if ( (_DWORD)v18 )
      {
        v17 = HIWORD(v15[1]);
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: tag_type %d",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "wmi_stats_extract_tag_struct",
          v17);
        switch ( v17 )
        {
          case 0x4B0u:
            v255 = *(_DWORD **)(a12 + 32);
            v255[1] = v15[2];
            v255[3] = v15[3];
            v255[5] = v15[4];
            v255[8] = v15[5];
            v255[2] = v15[6];
            v255[4] = v15[7];
            v255[6] = v15[8];
            v255[7] = v15[9];
            break;
          case 0x40Fu:
            v35 = *(_DWORD **)(a12 + 24);
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: BMISS stats struct found",
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              "wmi_bmiss_extract_stats_struct");
            v35[2] = v15[2];
            v35[3] = v15[3];
            v35[4] = v15[4];
            v35[5] = v15[5];
            v35[6] = v15[6];
            v35[7] = v15[7];
            v35[8] = v15[8];
            v35[9] = v15[9];
            v35[10] = v15[10];
            v35[11] = v15[11];
            v35[12] = v15[12];
            v35[13] = v15[13];
            v35[14] = v15[14];
            v35[15] = v15[15];
            v35[16] = v15[16];
            v35[17] = v15[17];
            v35[18] = v15[18];
            v35[19] = v15[19];
            v35[20] = v15[20];
            v35[21] = v15[21];
            v35[22] = v15[22];
            v35[23] = v15[23];
            v35[24] = v15[24];
            v35[25] = v15[25];
            v35[26] = v15[26];
            v35[27] = v15[27];
            v35[29] = v15[29];
            v35[30] = v15[30];
            v35[31] = v15[31];
            v35[32] = v15[32];
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: num_pre_bmiss = %u",
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              "wmi_extract_ctrl_path_bmiss_stats_tlv",
              (unsigned int)v15[2]);
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: num_first_bmiss = %u num_final_bmiss = %u, num_null_sent_in_first_bmiss = %u, num_null_failed_in_first_bmiss = %u",
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              "wmi_extract_ctrl_path_bmiss_stats_tlv",
              (unsigned int)v15[24],
              (unsigned int)v15[25],
              (unsigned int)v15[26],
              (unsigned int)v15[27]);
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: num_null_sent_in_final_bmiss %u null_fail_cnt_final_bmiss = %u rssi_sample_curr_index = %u",
              v52,
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              "wmi_extract_ctrl_path_bmiss_stats_tlv",
              (unsigned int)v15[28],
              (unsigned int)v15[29],
              (unsigned int)v15[23]);
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: rssi_sample-%u: rssi=%u",
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              "wmi_extract_ctrl_path_bmiss_stats_tlv",
              0,
              (unsigned int)v15[3]);
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: rssi_sample-%u: sampletime=%u",
              v68,
              v69,
              v70,
              v71,
              v72,
              v73,
              v74,
              v75,
              "wmi_extract_ctrl_path_bmiss_stats_tlv",
              0,
              (unsigned int)v15[4]);
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: rssi_sample-%u: rssi=%u",
              v76,
              v77,
              v78,
              v79,
              v80,
              v81,
              v82,
              v83,
              "wmi_extract_ctrl_path_bmiss_stats_tlv",
              1,
              (unsigned int)v15[5]);
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: rssi_sample-%u: sampletime=%u",
              v84,
              v85,
              v86,
              v87,
              v88,
              v89,
              v90,
              v91,
              "wmi_extract_ctrl_path_bmiss_stats_tlv",
              1,
              (unsigned int)v15[6]);
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: rssi_sample-%u: rssi=%u",
              v92,
              v93,
              v94,
              v95,
              v96,
              v97,
              v98,
              v99,
              "wmi_extract_ctrl_path_bmiss_stats_tlv",
              2,
              (unsigned int)v15[7]);
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: rssi_sample-%u: sampletime=%u",
              v100,
              v101,
              v102,
              v103,
              v104,
              v105,
              v106,
              v107,
              "wmi_extract_ctrl_path_bmiss_stats_tlv",
              2,
              (unsigned int)v15[8]);
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: rssi_sample-%u: rssi=%u",
              v108,
              v109,
              v110,
              v111,
              v112,
              v113,
              v114,
              v115,
              "wmi_extract_ctrl_path_bmiss_stats_tlv",
              3,
              (unsigned int)v15[9]);
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: rssi_sample-%u: sampletime=%u",
              v116,
              v117,
              v118,
              v119,
              v120,
              v121,
              v122,
              v123,
              "wmi_extract_ctrl_path_bmiss_stats_tlv",
              3,
              (unsigned int)v15[10]);
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: rssi_sample-%u: rssi=%u",
              v124,
              v125,
              v126,
              v127,
              v128,
              v129,
              v130,
              v131,
              "wmi_extract_ctrl_path_bmiss_stats_tlv",
              4,
              (unsigned int)v15[11]);
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: rssi_sample-%u: sampletime=%u",
              v132,
              v133,
              v134,
              v135,
              v136,
              v137,
              v138,
              v139,
              "wmi_extract_ctrl_path_bmiss_stats_tlv",
              4,
              (unsigned int)v15[12]);
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: rssi_sample-%u: rssi=%u",
              v140,
              v141,
              v142,
              v143,
              v144,
              v145,
              v146,
              v147,
              "wmi_extract_ctrl_path_bmiss_stats_tlv",
              5,
              (unsigned int)v15[13]);
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: rssi_sample-%u: sampletime=%u",
              v148,
              v149,
              v150,
              v151,
              v152,
              v153,
              v154,
              v155,
              "wmi_extract_ctrl_path_bmiss_stats_tlv",
              5,
              (unsigned int)v15[14]);
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: rssi_sample-%u: rssi=%u",
              v156,
              v157,
              v158,
              v159,
              v160,
              v161,
              v162,
              v163,
              "wmi_extract_ctrl_path_bmiss_stats_tlv",
              6,
              (unsigned int)v15[15]);
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: rssi_sample-%u: sampletime=%u",
              v164,
              v165,
              v166,
              v167,
              v168,
              v169,
              v170,
              v171,
              "wmi_extract_ctrl_path_bmiss_stats_tlv",
              6,
              (unsigned int)v15[16]);
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: rssi_sample-%u: rssi=%u",
              v172,
              v173,
              v174,
              v175,
              v176,
              v177,
              v178,
              v179,
              "wmi_extract_ctrl_path_bmiss_stats_tlv",
              7,
              (unsigned int)v15[17]);
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: rssi_sample-%u: sampletime=%u",
              v180,
              v181,
              v182,
              v183,
              v184,
              v185,
              v186,
              v187,
              "wmi_extract_ctrl_path_bmiss_stats_tlv",
              7,
              (unsigned int)v15[18]);
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: rssi_sample-%u: rssi=%u",
              v188,
              v189,
              v190,
              v191,
              v192,
              v193,
              v194,
              v195,
              "wmi_extract_ctrl_path_bmiss_stats_tlv",
              8,
              (unsigned int)v15[19]);
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: rssi_sample-%u: sampletime=%u",
              v196,
              v197,
              v198,
              v199,
              v200,
              v201,
              v202,
              v203,
              "wmi_extract_ctrl_path_bmiss_stats_tlv",
              8,
              (unsigned int)v15[20]);
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: rssi_sample-%u: rssi=%u",
              v204,
              v205,
              v206,
              v207,
              v208,
              v209,
              v210,
              v211,
              "wmi_extract_ctrl_path_bmiss_stats_tlv",
              9,
              (unsigned int)v15[21]);
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: rssi_sample-%u: sampletime=%u",
              v212,
              v213,
              v214,
              v215,
              v216,
              v217,
              v218,
              v219,
              "wmi_extract_ctrl_path_bmiss_stats_tlv",
              9,
              (unsigned int)v15[22]);
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: num_of_bmiss_sequences %u num_bitmask_wraparound = %u num_bcn_hist_lost = %u",
              v220,
              v221,
              v222,
              v223,
              v224,
              v225,
              v226,
              v227,
              "wmi_extract_ctrl_path_bmiss_stats_tlv",
              (unsigned int)v15[30],
              (unsigned int)v15[31],
              (unsigned int)v15[32]);
            break;
          case 0x3BBu:
            v229 = (_DWORD *)(*(_QWORD *)(a12 + 16) + 56LL * *(unsigned int *)(a12 + 12));
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: TWT stats struct found - num_twt_cp_stats %d",
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              "wmi_twt_extract_stats_struct");
            ++*(_DWORD *)(a12 + 12);
            v229[2] = v15[2];
            v238 = v15[3];
            if ( v238 >= 3 )
              v238 = 3;
            v229[3] = v238;
            v229[4] = v15[4];
            v229[5] = v15[5];
            v229[6] = v15[6];
            v229[7] = v15[7];
            v229[8] = v15[8];
            v229[9] = v15[9];
            v229[10] = v15[10];
            v229[11] = v15[11];
            v229[12] = v15[12];
            v229[13] = v15[13];
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: dialog_id = %u status = %u",
              v230,
              v231,
              v232,
              v233,
              v234,
              v235,
              v236,
              v237,
              "wmi_extract_ctrl_path_twt_stats_tlv",
              (unsigned int)v15[2],
              (unsigned int)v15[3]);
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: num_sp_cycles = %u avg_sp_dur_us = 0x%x, \t\t  min_sp_dur_us = 0x%x, max_sp_dur_us = 0x%x",
              v239,
              v240,
              v241,
              v242,
              v243,
              v244,
              v245,
              v246,
              "wmi_extract_ctrl_path_twt_stats_tlv",
              (unsigned int)v15[4],
              (unsigned int)v15[5],
              (unsigned int)v15[6],
              (unsigned int)v15[7]);
            LODWORD(v258) = v15[13];
            LODWORD(v257) = v15[12];
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: tx_mpdu_per_sp 0x%x, rx_mpdu_per_sp = 0x%x, \t\t  tx_bytes_per_sp = 0x%x, rx_bytes_per_sp = 0x%x, \t\t"
              "  avg_eosp_sp_dur_us = 0x%x, eosp_sp_count = 0x%x",
              v247,
              v248,
              v249,
              v250,
              v251,
              v252,
              v253,
              v254,
              "wmi_extract_ctrl_path_twt_stats_tlv",
              (unsigned int)v15[8],
              (unsigned int)v15[9],
              (unsigned int)v15[10],
              (unsigned int)v15[11],
              v257,
              v258);
            break;
        }
        v15 = (_DWORD *)((char *)v15 + v18 + 4);
        v16 -= v18 + 4;
      }
      if ( v16 <= 0 )
        return 0;
    }
  }
  else
  {
    v256 = jiffies;
    if ( wmi_stats_handler___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x31u, 2u, "%s: param_buf is NULL", a1, a2, a3, a4, a5, a6, a7, a8, "wmi_stats_handler");
      wmi_stats_handler___last_ticks = v256;
    }
    return 16;
  }
  return result;
}
