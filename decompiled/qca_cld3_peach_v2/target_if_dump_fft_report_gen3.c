__int64 __fastcall target_if_dump_fft_report_gen3(
        __int64 result,
        unsigned int a2,
        unsigned int *a3,
        unsigned int *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x19
  __int64 v13; // x28
  unsigned int v14; // w26
  unsigned __int64 v17; // x24
  unsigned __int64 v18; // x23
  size_t v19; // x21
  __int64 v20; // x20
  int v21; // w9
  char v22; // w9
  unsigned __int64 v23; // x8
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
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
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
  int v88; // w8
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
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
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  double v137; // d0
  double v138; // d1
  double v139; // d2
  double v140; // d3
  double v141; // d4
  double v142; // d5
  double v143; // d6
  double v144; // d7
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
  double v161; // d0
  double v162; // d1
  double v163; // d2
  double v164; // d3
  double v165; // d4
  double v166; // d5
  double v167; // d6
  double v168; // d7
  double v169; // d0
  double v170; // d1
  double v171; // d2
  double v172; // d3
  double v173; // d4
  double v174; // d5
  double v175; // d6
  double v176; // d7
  double v177; // d0
  double v178; // d1
  double v179; // d2
  double v180; // d3
  double v181; // d4
  double v182; // d5
  double v183; // d6
  double v184; // d7
  __int64 v185; // x22
  double v186; // d0
  double v187; // d1
  double v188; // d2
  double v189; // d3
  double v190; // d4
  double v191; // d5
  double v192; // d6
  double v193; // d7
  __int64 v194; // x20
  __int64 v195; // x20
  double v196; // d0
  double v197; // d1
  double v198; // d2
  double v199; // d3
  double v200; // d4
  double v201; // d5
  double v202; // d6
  double v203; // d7
  unsigned __int64 v204; // [xsp+8h] [xbp-18h]
  int v205; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v206; // [xsp+18h] [xbp-8h]

  v206 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    v12 = result;
    v13 = result + 80LL * a2;
    if ( *(_WORD *)(v13 + 676) )
    {
      v14 = a3[1];
      v17 = 4LL * (unsigned __int16)v14;
      v18 = v17 - *(unsigned __int8 *)(result + 1397);
      if ( (unsigned __int8)*(_WORD *)(v13 + 676) == 1 && *(_BYTE *)(result + 1345) )
      {
        v19 = 0;
      }
      else
      {
        v21 = *(_DWORD *)(result + 1348);
        if ( v21 == 1 )
        {
          v22 = 1;
          if ( *(_BYTE *)(result + 1346) )
            v22 = 2;
          v19 = v18 >> v22;
        }
        else
        {
          v19 = v17 - *(unsigned __int8 *)(result + 1397);
          if ( v21 == 2 )
            v19 = v18 >> 2;
        }
        if ( (unsigned __int8)*(_WORD *)(v13 + 676) == 2 )
          v19 >>= *(_BYTE *)(result + 1344) != 0;
      }
      if ( *(_WORD *)(v13 + 676) == 2 )
      {
        if ( *(_BYTE *)(result + 1344) )
          v23 = v18 >> 1;
        else
          v23 = 0;
        v204 = v23;
      }
      else
      {
        v204 = 0;
      }
      qdf_trace_msg(
        0x56u,
        8u,
        "%s: Spectral FFT Report",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "target_if_dump_fft_report_gen3");
      qdf_trace_msg(
        0x56u,
        8u,
        "%s: fft_timestamp = 0x%x",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "target_if_dump_fft_report_gen3",
        *a3);
      qdf_trace_msg(
        0x56u,
        8u,
        "%s: fft_hdr_length = %zu(32 bit words)",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "target_if_dump_fft_report_gen3",
        v17 >> 2);
      qdf_trace_msg(
        0x56u,
        8u,
        "%s: fft_hdr_tag = 0x%x",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "target_if_dump_fft_report_gen3",
        BYTE2(v14));
      qdf_trace_msg(
        0x56u,
        8u,
        "%s: fft_hdr_sig = 0x%x",
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        "target_if_dump_fft_report_gen3",
        HIBYTE(v14));
      qdf_trace_msg(
        0x56u,
        8u,
        "%s: Length field in search fft report is %zu(0x%zx) bytes",
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        "target_if_dump_fft_report_gen3",
        v17,
        v17);
      qdf_trace_msg(
        0x56u,
        8u,
        "%s: Total length of search fft report is %zu(0x%zx) bytes",
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        "target_if_dump_fft_report_gen3",
        v17 + 8,
        v17 + 8);
      qdf_trace_msg(
        0x56u,
        8u,
        "%s: Target reported fftbins in report is %zu(0x%zx)",
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        "target_if_dump_fft_report_gen3",
        v18,
        v18);
      v88 = *(unsigned __int16 *)(v13 + 676);
      if ( v88 == 2 )
      {
        if ( *(_BYTE *)(v12 + 1344) )
          qdf_trace_msg(
            0x56u,
            8u,
            "%s: FW fftbins actually transferred (in-band report mode) %zu(0x%zx)",
            v80,
            v81,
            v82,
            v83,
            v84,
            v85,
            v86,
            v87,
            "target_if_dump_fft_report_gen3",
            v204,
            v204);
      }
      else if ( v88 == 1 && *(_BYTE *)(v12 + 1345) )
      {
        qdf_trace_msg(
          0x56u,
          8u,
          "%s: WAR: Considering number of FFT bins as 0",
          v80,
          v81,
          v82,
          v83,
          v84,
          v85,
          v86,
          v87,
          "target_if_dump_fft_report_gen3");
      }
      qdf_trace_msg(
        0x56u,
        8u,
        "%s: Actual number of fftbins in report is %zu(0x%zx)",
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        v87,
        "target_if_dump_fft_report_gen3",
        v19,
        v19);
      qdf_trace_msg(
        0x56u,
        8u,
        "%s: fft_detector_id = %u",
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        v95,
        v96,
        "target_if_dump_fft_report_gen3",
        a4[3]);
      qdf_trace_msg(
        0x56u,
        8u,
        "%s: fft_num = %u",
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        "target_if_dump_fft_report_gen3",
        a4[4]);
      qdf_trace_msg(
        0x56u,
        8u,
        "%s: fft_radar_check = %u",
        v105,
        v106,
        v107,
        v108,
        v109,
        v110,
        v111,
        v112,
        "target_if_dump_fft_report_gen3",
        a4[5]);
      qdf_trace_msg(
        0x56u,
        8u,
        "%s: fft_peak_sidx = %d",
        v113,
        v114,
        v115,
        v116,
        v117,
        v118,
        v119,
        v120,
        "target_if_dump_fft_report_gen3",
        a4[6]);
      qdf_trace_msg(
        0x56u,
        8u,
        "%s: fft_chn_idx = %u",
        v121,
        v122,
        v123,
        v124,
        v125,
        v126,
        v127,
        v128,
        "target_if_dump_fft_report_gen3",
        a4[7]);
      qdf_trace_msg(
        0x56u,
        8u,
        "%s: fft_base_pwr_db = %u",
        v129,
        v130,
        v131,
        v132,
        v133,
        v134,
        v135,
        v136,
        "target_if_dump_fft_report_gen3",
        a4[8]);
      qdf_trace_msg(
        0x56u,
        8u,
        "%s: fft_total_gain_db = %u",
        v137,
        v138,
        v139,
        v140,
        v141,
        v142,
        v143,
        v144,
        "target_if_dump_fft_report_gen3",
        a4[9]);
      qdf_trace_msg(
        0x56u,
        8u,
        "%s: fft_num_str_bins_ib = %u",
        v145,
        v146,
        v147,
        v148,
        v149,
        v150,
        v151,
        v152,
        "target_if_dump_fft_report_gen3",
        a4[10]);
      qdf_trace_msg(
        0x56u,
        8u,
        "%s: fft_peak_mag = %d",
        v153,
        v154,
        v155,
        v156,
        v157,
        v158,
        v159,
        v160,
        "target_if_dump_fft_report_gen3",
        a4[11]);
      qdf_trace_msg(
        0x56u,
        8u,
        "%s: fft_avgpwr_db = %u",
        v161,
        v162,
        v163,
        v164,
        v165,
        v166,
        v167,
        v168,
        "target_if_dump_fft_report_gen3",
        a4[12]);
      result = qdf_trace_msg(
                 0x56u,
                 8u,
                 "%s: fft_relpwr_db = %u",
                 v169,
                 v170,
                 v171,
                 v172,
                 v173,
                 v174,
                 v175,
                 v176,
                 "target_if_dump_fft_report_gen3",
                 a4[13]);
      if ( v19 )
      {
        result = _qdf_mem_malloc(v19, "target_if_dump_fft_report_gen3", 2539);
        if ( result )
        {
          v185 = result;
          if ( (unsigned int)target_if_spectral_copy_fft_bins(
                               v12,
                               a3 + 6,
                               result,
                               v19,
                               &v205,
                               *(_WORD *)(v13 + 674),
                               v177,
                               v178,
                               v179,
                               v180,
                               v181,
                               v182,
                               v183,
                               v184) )
          {
            v194 = jiffies;
            if ( target_if_dump_fft_report_gen3___last_ticks_154 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x56u,
                2u,
                "%s: Unable to populate FFT bins",
                v186,
                v187,
                v188,
                v189,
                v190,
                v191,
                v192,
                v193,
                "target_if_dump_fft_report_gen3");
              target_if_dump_fft_report_gen3___last_ticks_154 = v194;
            }
          }
          else
          {
            qdf_trace_msg(
              0x56u,
              8u,
              "%s: FFT bin buffer size = %zu",
              v186,
              v187,
              v188,
              v189,
              v190,
              v191,
              v192,
              v193,
              "target_if_dump_fft_report_gen3",
              v19);
            qdf_trace_msg(
              0x56u,
              8u,
              "%s: FFT bins:",
              v196,
              v197,
              v198,
              v199,
              v200,
              v201,
              v202,
              v203,
              "target_if_dump_fft_report_gen3");
            target_if_spectral_hexdump(v185, (unsigned int)v19);
          }
          result = _qdf_mem_free(v185);
        }
        else
        {
          v195 = jiffies;
          if ( target_if_dump_fft_report_gen3___last_ticks_152 - jiffies + 125 < 0 )
          {
            result = qdf_trace_msg(
                       0x56u,
                       2u,
                       "%s: memory allocation failed",
                       v177,
                       v178,
                       v179,
                       v180,
                       v181,
                       v182,
                       v183,
                       v184,
                       "target_if_dump_fft_report_gen3");
            target_if_dump_fft_report_gen3___last_ticks_152 = v195;
          }
        }
      }
    }
  }
  else
  {
    v20 = jiffies;
    if ( target_if_dump_fft_report_gen3___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x56u,
                 2u,
                 "%s: spectral pointer is null.",
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 a12,
                 "target_if_dump_fft_report_gen3");
      target_if_dump_fft_report_gen3___last_ticks = v20;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
