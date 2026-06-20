__int64 __fastcall hal_reo_send_cmd_be(
        __int64 a1,
        __int64 a2,
        int a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v15; // x22
  unsigned __int8 v16; // w8
  unsigned int v17; // w10
  unsigned int v18; // w11
  __int64 v19; // x9
  __int64 v20; // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x20
  __int64 v31; // x8
  unsigned int v32; // w9
  __int64 v33; // x10
  __int64 v34; // x22
  __int64 v35; // x10
  __int64 v36; // x11
  unsigned __int64 v37; // x8
  unsigned __int64 v38; // x8
  unsigned __int64 v39; // x8
  unsigned __int64 v40; // x8
  unsigned __int64 v41; // x8
  unsigned __int64 v42; // x8
  unsigned __int64 v43; // x8
  unsigned __int64 v44; // x8
  unsigned __int64 v45; // x8
  unsigned __int64 v46; // x8
  unsigned __int64 v47; // x8
  unsigned __int64 v48; // x8
  unsigned __int64 v49; // x8
  unsigned __int64 v50; // x8
  unsigned __int64 v51; // x8
  unsigned __int64 v52; // x8
  unsigned __int64 v53; // x8
  unsigned __int64 v54; // x8
  unsigned __int64 v55; // x8
  unsigned __int64 v56; // x8
  unsigned __int64 v57; // x8
  unsigned __int64 v58; // x8
  unsigned __int64 v59; // x8
  unsigned __int64 v60; // x8
  unsigned __int64 v61; // x8
  unsigned __int64 v62; // x8
  unsigned __int64 v63; // x8
  unsigned __int64 v64; // x8
  unsigned __int64 v65; // x8
  unsigned __int64 v66; // x8
  unsigned __int64 v67; // x8
  unsigned __int64 v68; // x8
  unsigned __int64 v69; // x8
  unsigned __int64 v70; // x8
  unsigned __int64 v71; // x8
  unsigned __int64 v72; // x8
  unsigned __int64 v73; // x8
  __int64 v74; // x9
  unsigned __int64 v75; // x11
  unsigned __int64 v76; // x9
  unsigned __int64 v77; // x8
  unsigned __int64 v78; // x8
  unsigned __int64 v79; // x8
  unsigned __int64 v80; // x8
  unsigned __int64 v81; // x8
  __int64 v82; // x8
  __int128 v83; // t2
  __int64 v84; // x8
  __int64 v85; // x8
  unsigned int v86; // w9
  __int64 v87; // x10
  __int64 v88; // x8
  unsigned __int64 v89; // x8
  unsigned __int64 v90; // x8
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  __int64 v99; // x8
  unsigned int v100; // w9
  __int64 v101; // x10
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  __int64 v110; // x8
  unsigned __int64 v111; // x8
  __int64 v112; // x8
  unsigned int v113; // w9
  __int64 v114; // x10
  __int64 v115; // x8
  unsigned __int64 v116; // x8
  unsigned __int64 v117; // x8
  __int64 v118; // x8
  unsigned int v119; // w9
  __int64 v120; // x10
  unsigned __int64 v121; // x9
  unsigned __int64 v122; // x9
  __int64 v123; // x8
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  __int64 v132; // x20
  __int64 v133; // x8
  double v134; // d0
  double v135; // d1
  double v136; // d2
  double v137; // d3
  double v138; // d4
  double v139; // d5
  double v140; // d6
  double v141; // d7
  __int64 v142; // x20
  __int64 v143; // x8
  double v144; // d0
  double v145; // d1
  double v146; // d2
  double v147; // d3
  double v148; // d4
  double v149; // d5
  double v150; // d6
  double v151; // d7
  __int64 v152; // x20
  __int64 v153; // x8
  double v154; // d0
  double v155; // d1
  double v156; // d2
  double v157; // d3
  double v158; // d4
  double v159; // d5
  double v160; // d6
  double v161; // d7
  __int64 v162; // x20
  __int64 v163; // x8
  double v164; // d0
  double v165; // d1
  double v166; // d2
  double v167; // d3
  double v168; // d4
  double v169; // d5
  double v170; // d6
  double v171; // d7
  __int64 v172; // x20
  __int64 v173; // x23
  unsigned __int8 v174; // w8
  unsigned int v175; // w9
  unsigned int v176; // w11
  unsigned int v177; // w10
  __int64 v178; // x8
  unsigned int v179; // w9
  __int64 v180; // x10
  __int64 v181; // x8
  unsigned __int64 v182; // x8
  __int64 v183; // x9
  unsigned __int64 v184; // x8
  unsigned __int64 v185; // x8
  unsigned __int64 v186; // x8
  unsigned __int64 v187; // x8
  __int64 v188; // x8
  __int64 v189; // x8
  __int64 v190; // x8
  double v191; // d0
  double v192; // d1
  double v193; // d2
  double v194; // d3
  double v195; // d4
  double v196; // d5
  double v197; // d6
  double v198; // d7

  v15 = a1 + 73728;
  if ( a3 > 2 )
  {
    switch ( a3 )
    {
      case 3:
        hal_srng_access_start_0(a1, a2);
        if ( !*(_DWORD *)(a4 + 12) )
        {
          v174 = *(_BYTE *)(v15 + 320) & -*(_BYTE *)(v15 + 320) & 0xF;
          if ( !v174 )
            goto LABEL_74;
          v175 = 0;
          do
          {
            v176 = v174;
            v174 >>= 1;
            v177 = v175++;
          }
          while ( v176 > 1 );
          if ( v177 >= 4 )
          {
LABEL_74:
            if ( a2 )
            {
              if ( (*(_DWORD *)(a2 + 76) & 0x80000000) != 0 )
                **(_DWORD **)(a2 + 144) = *(_DWORD *)(a2 + 120);
              else
                hal_delayed_reg_write(a1, a2, *(_QWORD *)(a2 + 144), *(unsigned int *)(a2 + 120));
              v190 = *(_QWORD *)(a2 + 88);
              if ( (v190 & 1) != 0 )
              {
                *(_QWORD *)(a2 + 88) = v190 & 0xFFFFFFFFFFFFFFFELL;
                raw_spin_unlock_bh(a2 + 80);
              }
              else
              {
                raw_spin_unlock(a2 + 80);
              }
            }
            else
            {
              qdf_trace_msg(
                0x38u,
                2u,
                "%s: Error: Invalid hal_ring\n",
                v91,
                v92,
                v93,
                v94,
                v95,
                v96,
                v97,
                v98,
                "hal_srng_access_end");
            }
            qdf_trace_msg(
              0x38u,
              2u,
              "%s: No blocking resource to unblock!",
              v191,
              v192,
              v193,
              v194,
              v195,
              v196,
              v197,
              v198,
              "hal_reo_cmd_unblock_cache_be");
            return 4294967280LL;
          }
        }
        v99 = *(unsigned int *)(a2 + 120);
        v100 = (unsigned int)(*(_DWORD *)(a2 + 44) + v99) % *(_DWORD *)(a2 + 36);
        if ( v100 == *(_DWORD *)(a2 + 136)
          || (v101 = *(_QWORD *)(a2 + 16),
              *(_DWORD *)(a2 + 120) = v100,
              *(_DWORD *)(a2 + 124) = v100,
              (v34 = v101 + 4 * v99) == 0) )
        {
          v163 = *(_QWORD *)(a2 + 88);
          if ( (v163 & 1) != 0 )
          {
            *(_QWORD *)(a2 + 88) = v163 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a2 + 80);
          }
          else
          {
            raw_spin_unlock(a2 + 80);
          }
          v172 = jiffies;
          if ( hal_reo_cmd_unblock_cache_be___last_ticks - jiffies + 125 >= 0 )
            return 4294967280LL;
          qdf_trace_msg(
            0x46u,
            3u,
            "%s: Out of cmd ring entries",
            v164,
            v165,
            v166,
            v167,
            v168,
            v169,
            v170,
            v171,
            "hal_reo_cmd_unblock_cache_be");
          hal_reo_cmd_unblock_cache_be___last_ticks = v172;
          return 4294967280LL;
        }
        *(_DWORD *)v34 = *(_DWORD *)v34 & 0xFFC00001 | 0x9238;
        qdf_mem_set((void *)(v34 + 8), 0x20u, 0);
        v110 = *(_QWORD *)(v34 + 8);
        *(_DWORD *)(v34 + 4) = *(_DWORD *)(v34 + 4) & 0xFFFEFFFF | ((*(_BYTE *)a4 & 1) << 16);
        v111 = v110 & 0xFFFFFFFFFFFFFFFELL | *(_DWORD *)(a4 + 12) & 1;
        *(_QWORD *)(v34 + 8) = v111;
        if ( !*(_DWORD *)(a4 + 12) )
          *(_QWORD *)(v34 + 8) = v111 & 0xFFFFFFFFFFFFFFF9LL | (2LL * (*(_BYTE *)(a4 + 16) & 3));
        if ( a2 )
        {
          if ( (*(_DWORD *)(a2 + 76) & 0x80000000) != 0 )
            **(_DWORD **)(a2 + 144) = *(_DWORD *)(a2 + 120);
          else
            hal_delayed_reg_write(a1, a2, *(_QWORD *)(a2 + 144), *(unsigned int *)(a2 + 120));
          v189 = *(_QWORD *)(a2 + 88);
          if ( (v189 & 1) == 0 )
            goto LABEL_91;
          goto LABEL_99;
        }
        break;
      case 4:
        hal_srng_access_start_0(a1, a2);
        v118 = *(unsigned int *)(a2 + 120);
        v119 = (unsigned int)(*(_DWORD *)(a2 + 44) + v118) % *(_DWORD *)(a2 + 36);
        if ( v119 == *(_DWORD *)(a2 + 136)
          || (v120 = *(_QWORD *)(a2 + 16),
              *(_DWORD *)(a2 + 120) = v119,
              *(_DWORD *)(a2 + 124) = v119,
              (v34 = v120 + 4 * v118) == 0) )
        {
          v153 = *(_QWORD *)(a2 + 88);
          if ( (v153 & 1) != 0 )
          {
            *(_QWORD *)(a2 + 88) = v153 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a2 + 80);
          }
          else
          {
            raw_spin_unlock(a2 + 80);
          }
          v162 = jiffies;
          if ( hal_reo_cmd_flush_timeout_list_be___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x46u,
              3u,
              "%s: Out of cmd ring entries",
              v154,
              v155,
              v156,
              v157,
              v158,
              v159,
              v160,
              v161,
              "hal_reo_cmd_flush_timeout_list_be");
            hal_reo_cmd_flush_timeout_list_be___last_ticks = v162;
            return 4294967280LL;
          }
          return 4294967280LL;
        }
        *(_DWORD *)v34 = *(_DWORD *)v34 & 0xFFC00001 | 0x9262;
        qdf_mem_set((void *)(v34 + 8), 0x20u, 0);
        *(_DWORD *)(v34 + 4) = *(_DWORD *)(v34 + 4) & 0xFFFEFFFF | ((*(_BYTE *)a4 & 1) << 16);
        v121 = *(_QWORD *)(v34 + 8) & 0xFFFFFFFFFFFFFFFCLL | *(_BYTE *)(a4 + 12) & 3;
        *(_QWORD *)(v34 + 8) = v121;
        v122 = v121 & 0xFFFF0000FFFFFFFFLL | ((unsigned __int64)*(unsigned __int16 *)(a4 + 14) << 32);
        *(_QWORD *)(v34 + 8) = v122;
        *(_QWORD *)(v34 + 8) = v122 & 0xFFFFFFFFFFFFLL | ((unsigned __int64)*(unsigned __int16 *)(a4 + 16) << 48);
        if ( a2 )
        {
          if ( (*(_DWORD *)(a2 + 76) & 0x80000000) != 0 )
            **(_DWORD **)(a2 + 144) = *(_DWORD *)(a2 + 120);
          else
            hal_delayed_reg_write(a1, a2, *(_QWORD *)(a2 + 144), *(unsigned int *)(a2 + 120));
          v189 = *(_QWORD *)(a2 + 88);
          if ( (v189 & 1) == 0 )
          {
LABEL_91:
            raw_spin_unlock(a2 + 80);
            return *(unsigned __int16 *)(v34 + 4);
          }
LABEL_99:
          *(_QWORD *)(a2 + 88) = v189 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a2 + 80);
          return *(unsigned __int16 *)(v34 + 4);
        }
        break;
      case 5:
        hal_srng_access_start_0(a1, a2);
        v31 = *(unsigned int *)(a2 + 120);
        v32 = (unsigned int)(*(_DWORD *)(a2 + 44) + v31) % *(_DWORD *)(a2 + 36);
        if ( v32 == *(_DWORD *)(a2 + 136)
          || (v33 = *(_QWORD *)(a2 + 16),
              *(_DWORD *)(a2 + 120) = v32,
              *(_DWORD *)(a2 + 124) = v32,
              (v34 = v33 + 4 * v31) == 0) )
        {
          v133 = *(_QWORD *)(a2 + 88);
          if ( (v133 & 1) != 0 )
          {
            *(_QWORD *)(a2 + 88) = v133 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a2 + 80);
          }
          else
          {
            raw_spin_unlock(a2 + 80);
          }
          v142 = jiffies;
          if ( hal_reo_cmd_update_rx_queue_be___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x46u,
              3u,
              "%s: Out of cmd ring entries",
              v134,
              v135,
              v136,
              v137,
              v138,
              v139,
              v140,
              v141,
              "hal_reo_cmd_update_rx_queue_be");
            hal_reo_cmd_update_rx_queue_be___last_ticks = v142;
            return 4294967280LL;
          }
          return 4294967280LL;
        }
        *(_DWORD *)v34 = *(_DWORD *)v34 & 0xFFC00001 | 0x92A6;
        qdf_mem_set((void *)(v34 + 8), 0x20u, 0);
        v35 = *(_QWORD *)(v34 + 8);
        v36 = *(_QWORD *)(v34 + 16);
        *(_DWORD *)(v34 + 4) = *(_DWORD *)(v34 + 4) & 0xFFFEFFFF | ((*(_BYTE *)a4 & 1) << 16);
        v37 = v35 & 0xFFFFFF0000000000LL
            | *(unsigned int *)(a4 + 4)
            | ((unsigned __int64)*(unsigned __int8 *)(a4 + 8) << 32);
        *(_QWORD *)(v34 + 8) = v37;
        v38 = v37 & 0xFFFFFEFFFFFFFFFFLL | ((*(_QWORD *)(a4 + 12) & 1LL) << 40);
        *(_QWORD *)(v34 + 8) = v38;
        v39 = v38 & 0xFFFFFDFFFFFFFFFFLL | (((*(_QWORD *)(a4 + 12) >> 1) & 1LL) << 41);
        *(_QWORD *)(v34 + 8) = v39;
        v40 = v39 & 0xFFFFFBFFFFFFFFFFLL | (((*(_QWORD *)(a4 + 12) >> 2) & 1LL) << 42);
        *(_QWORD *)(v34 + 8) = v40;
        v41 = v40 & 0xFFFFF7FFFFFFFFFFLL | (((*(_QWORD *)(a4 + 12) >> 3) & 1LL) << 43);
        *(_QWORD *)(v34 + 8) = v41;
        v42 = v41 & 0xFFFFEFFFFFFFFFFFLL | (((*(_QWORD *)(a4 + 12) >> 4) & 1LL) << 44);
        *(_QWORD *)(v34 + 8) = v42;
        v43 = v42 & 0xFFFFDFFFFFFFFFFFLL | (((*(_QWORD *)(a4 + 12) >> 5) & 1LL) << 45);
        *(_QWORD *)(v34 + 8) = v43;
        v44 = v43 & 0xFFFFBFFFFFFFFFFFLL | (((*(_QWORD *)(a4 + 12) >> 6) & 1LL) << 46);
        *(_QWORD *)(v34 + 8) = v44;
        v45 = v44 & 0xFFFF7FFFFFFFFFFFLL | (((*(_QWORD *)(a4 + 12) >> 7) & 1LL) << 47);
        *(_QWORD *)(v34 + 8) = v45;
        v46 = v45 & 0xFFFEFFFFFFFFFFFFLL | (((*(_QWORD *)(a4 + 12) >> 8) & 1LL) << 48);
        *(_QWORD *)(v34 + 8) = v46;
        v47 = v46 & 0xFFFDFFFFFFFFFFFFLL | (((*(_QWORD *)(a4 + 12) >> 9) & 1LL) << 49);
        *(_QWORD *)(v34 + 8) = v47;
        v48 = v47 & 0xFFFBFFFFFFFFFFFFLL | (((*(_QWORD *)(a4 + 12) >> 10) & 1LL) << 50);
        *(_QWORD *)(v34 + 8) = v48;
        v49 = v48 & 0xFFF7FFFFFFFFFFFFLL | (((*(_QWORD *)(a4 + 12) >> 11) & 1LL) << 51);
        *(_QWORD *)(v34 + 8) = v49;
        v50 = v49 & 0xFFEFFFFFFFFFFFFFLL | (((*(_QWORD *)(a4 + 12) >> 12) & 1LL) << 52);
        *(_QWORD *)(v34 + 8) = v50;
        v51 = v50 & 0xFFDFFFFFFFFFFFFFLL | (((*(_QWORD *)(a4 + 12) >> 13) & 1LL) << 53);
        *(_QWORD *)(v34 + 8) = v51;
        v52 = v51 & 0xFFBFFFFFFFFFFFFFLL | (((*(_QWORD *)(a4 + 12) >> 14) & 1LL) << 54);
        *(_QWORD *)(v34 + 8) = v52;
        v53 = v52 & 0xFF7FFFFFFFFFFFFFLL | (((*(_QWORD *)(a4 + 12) >> 15) & 1LL) << 55);
        *(_QWORD *)(v34 + 8) = v53;
        v54 = v53 & 0xFEFFFFFFFFFFFFFFLL | (((*(_QWORD *)(a4 + 12) >> 16) & 1LL) << 56);
        *(_QWORD *)(v34 + 8) = v54;
        v55 = v54 & 0xFDFFFFFFFFFFFFFFLL | (((*(_QWORD *)(a4 + 12) >> 17) & 1LL) << 57);
        *(_QWORD *)(v34 + 8) = v55;
        v56 = v55 & 0xFBFFFFFFFFFFFFFFLL | (((*(_QWORD *)(a4 + 12) >> 18) & 1LL) << 58);
        *(_QWORD *)(v34 + 8) = v56;
        v57 = v56 & 0xF7FFFFFFFFFFFFFFLL | (((*(_QWORD *)(a4 + 12) >> 19) & 1LL) << 59);
        *(_QWORD *)(v34 + 8) = v57;
        v58 = v57 & 0xDFFFFFFFFFFFFFFFLL | (((*(_QWORD *)(a4 + 12) >> 21) & 1LL) << 61);
        *(_QWORD *)(v34 + 8) = v58;
        *(_QWORD *)(v34 + 8) = v58 & 0xBFFFFFFFFFFFFFFFLL | (((*(_QWORD *)(a4 + 12) >> 22) & 1LL) << 62);
        v59 = v36 & 0xFFFFFFFFFFFF0000LL | *(unsigned __int16 *)(a4 + 16);
        *(_QWORD *)(v34 + 16) = v59;
        v60 = v59 & 0xFFFFFFFFFFFEFFFFLL | ((HIWORD(*(_QWORD *)(a4 + 12)) & 1LL) << 16);
        *(_QWORD *)(v34 + 16) = v60;
        v61 = v60 & 0xFFFFFFFFFFF9FFFFLL | ((((unsigned __int64)*(unsigned int *)(a4 + 16) >> 17) & 3) << 17);
        *(_QWORD *)(v34 + 16) = v61;
        v62 = v61 & 0xFFFFFFFFFFF7FFFFLL | (((*(_QWORD *)(a4 + 12) >> 51) & 1LL) << 19);
        *(_QWORD *)(v34 + 16) = v62;
        v63 = v62 & 0xFFFFFFFFFFEFFFFFLL | (((*(_QWORD *)(a4 + 12) >> 52) & 1LL) << 20);
        *(_QWORD *)(v34 + 16) = v63;
        v64 = v63 & 0xFFFFFFFFFF9FFFFFLL | ((((unsigned __int64)*(unsigned int *)(a4 + 16) >> 21) & 3) << 21);
        *(_QWORD *)(v34 + 16) = v64;
        v65 = v64 & 0xFFFFFFFFFF7FFFFFLL | (((*(_QWORD *)(a4 + 12) >> 55) & 1LL) << 23);
        *(_QWORD *)(v34 + 16) = v65;
        v66 = v65 & 0xFFFFFFFFFDFFFFFFLL | (((*(_QWORD *)(a4 + 12) >> 57) & 1LL) << 25);
        *(_QWORD *)(v34 + 16) = v66;
        v67 = v66 & 0xFFFFFFFFFEFFFFFFLL | ((HIBYTE(*(_QWORD *)(a4 + 12)) & 1LL) << 24);
        *(_QWORD *)(v34 + 16) = v67;
        v68 = v67 & 0xFFFFFFFFFBFFFFFFLL | (((*(_QWORD *)(a4 + 12) >> 58) & 1LL) << 26);
        *(_QWORD *)(v34 + 16) = v68;
        v69 = v68 & 0xFFFFFFFFF7FFFFFFLL | (((*(_QWORD *)(a4 + 12) >> 59) & 1LL) << 27);
        *(_QWORD *)(v34 + 16) = v69;
        v70 = v69 & 0xFFFFFFFFEFFFFFFFLL | (((*(_QWORD *)(a4 + 12) >> 60) & 1LL) << 28);
        *(_QWORD *)(v34 + 16) = v70;
        v71 = v70 & 0xFFFFFFFFDFFFFFFFLL | (((*(_QWORD *)(a4 + 12) >> 61) & 1LL) << 29);
        *(_QWORD *)(v34 + 16) = v71;
        v72 = v71 & 0xFFFFFFFFBFFFFFFFLL | (((*(_QWORD *)(a4 + 12) >> 62) & 1LL) << 30);
        *(_QWORD *)(v34 + 16) = v72;
        v73 = v72 & 0xFFFFFFFF7FFFFFFFLL | (*(_QWORD *)(a4 + 12) >> 63 << 31);
        *(_QWORD *)(v34 + 16) = v73;
        v74 = *(_QWORD *)(a4 + 20);
        if ( (v74 & 0x7FFF) != 0 )
          v75 = *(_QWORD *)(a4 + 20);
        else
          v75 = v74 + 1;
        v76 = v74 & 0xFFFFFFFFFFFF8000LL | 2;
        if ( (v75 & 0x7FFF) != 1 )
          v76 = v75;
        if ( (*(_QWORD *)(a4 + 20) & 0x7FFFLL) == 0 || (v75 & 0x7FFF) == 1 )
        {
          *(_QWORD *)(a4 + 20) = v76;
          v73 = *(_QWORD *)(v34 + 16);
        }
        v77 = v73 & 0xFFFFFC00FFFFFFFFLL | (((((v76 << 32) + 0x3FF00000000LL) >> 32) & 0x3FF) << 32);
        *(_QWORD *)(v34 + 16) = v77;
        v78 = v77 & 0xFFFFF3FFFFFFFFFFLL | (((*(_QWORD *)(a4 + 20) >> 15) & 3LL) << 42);
        *(_QWORD *)(v34 + 16) = v78;
        v79 = v78 & 0xFFFFEFFFFFFFFFFFLL | (((*(_QWORD *)(a4 + 20) >> 17) & 1LL) << 44);
        *(_QWORD *)(v34 + 16) = v79;
        v80 = v79 & 0xFE001FFFFFFFFFFFLL | (((*(_QWORD *)(a4 + 20) >> 18) & 0xFFFLL) << 45);
        *(_QWORD *)(v34 + 16) = v80;
        v81 = v80 & 0xFDFFFFFFFFFFFFFFLL | (((*(_QWORD *)(a4 + 20) >> 30) & 1LL) << 57);
        *(_QWORD *)(v34 + 16) = v81;
        *(_QWORD *)(v34 + 16) = v81 & 0xFBFFFFFFFFFFFFFFLL | (((*(_QWORD *)(a4 + 20) >> 31) & 1LL) << 58);
        v82 = *(_QWORD *)(a4 + 20);
        *(_DWORD *)(v34 + 24) = HIDWORD(v82);
        *((_QWORD *)&v83 + 1) = *(_QWORD *)(a4 + 28);
        *(_QWORD *)&v83 = v82;
        *(_QWORD *)(v34 + 24) = v83 >> 32;
        v84 = *(_QWORD *)(a4 + 28);
        *(_DWORD *)(v34 + 32) = HIDWORD(v84);
        *((_QWORD *)&v83 + 1) = *(unsigned int *)(a4 + 36);
        *(_QWORD *)&v83 = v84;
        *(_QWORD *)(v34 + 32) = v83 >> 32;
        goto LABEL_85;
      default:
        goto LABEL_39;
    }
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Error: Invalid hal_ring\n",
      v102,
      v103,
      v104,
      v105,
      v106,
      v107,
      v108,
      v109,
      "hal_srng_access_end");
    return *(unsigned __int16 *)(v34 + 4);
  }
  if ( !a3 )
  {
    hal_srng_access_start_0(a1, a2);
    v85 = *(unsigned int *)(a2 + 120);
    v86 = (unsigned int)(*(_DWORD *)(a2 + 44) + v85) % *(_DWORD *)(a2 + 36);
    if ( v86 == *(_DWORD *)(a2 + 136)
      || (v87 = *(_QWORD *)(a2 + 16),
          *(_DWORD *)(a2 + 120) = v86,
          *(_DWORD *)(a2 + 124) = v86,
          (v34 = v87 + 4 * v85) == 0) )
    {
      v123 = *(_QWORD *)(a2 + 88);
      if ( (v123 & 1) != 0 )
      {
        *(_QWORD *)(a2 + 88) = v123 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a2 + 80);
      }
      else
      {
        raw_spin_unlock(a2 + 80);
      }
      v132 = jiffies;
      if ( hal_reo_cmd_queue_stats_be___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x46u,
          3u,
          "%s: Out of cmd ring entries",
          v124,
          v125,
          v126,
          v127,
          v128,
          v129,
          v130,
          v131,
          "hal_reo_cmd_queue_stats_be");
        hal_reo_cmd_queue_stats_be___last_ticks = v132;
        return 4294967280LL;
      }
      return 4294967280LL;
    }
    *(_DWORD *)v34 = *(_DWORD *)v34 & 0xFFC00001 | 0x9232;
    qdf_mem_set((void *)(v34 + 8), 0x20u, 0);
    v88 = *(_QWORD *)(v34 + 8);
    *(_DWORD *)(v34 + 4) = *(_DWORD *)(v34 + 4) & 0xFFFEFFFF | ((*(_BYTE *)a4 & 1) << 16);
    v89 = v88 & 0xFFFFFF0000000000LL
        | *(unsigned int *)(a4 + 4)
        | ((unsigned __int64)*(unsigned __int8 *)(a4 + 8) << 32);
    *(_QWORD *)(v34 + 8) = v89;
    v90 = v89 & 0xFFFFFEFFFFFFFFFFLL | ((unsigned __int64)(*(_BYTE *)(a4 + 12) & 1) << 40);
    goto LABEL_84;
  }
  if ( a3 == 1 )
  {
    hal_srng_access_start_0(a1, a2);
    v112 = *(unsigned int *)(a2 + 120);
    v113 = (unsigned int)(*(_DWORD *)(a2 + 44) + v112) % *(_DWORD *)(a2 + 36);
    if ( v113 == *(_DWORD *)(a2 + 136)
      || (v114 = *(_QWORD *)(a2 + 16),
          *(_DWORD *)(a2 + 120) = v113,
          *(_DWORD *)(a2 + 124) = v113,
          (v34 = v114 + 4 * v112) == 0) )
    {
      v143 = *(_QWORD *)(a2 + 88);
      if ( (v143 & 1) != 0 )
      {
        *(_QWORD *)(a2 + 88) = v143 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a2 + 80);
      }
      else
      {
        raw_spin_unlock(a2 + 80);
      }
      v152 = jiffies;
      if ( hal_reo_cmd_flush_queue_be___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x46u,
          3u,
          "%s: Out of cmd ring entries",
          v144,
          v145,
          v146,
          v147,
          v148,
          v149,
          v150,
          v151,
          "hal_reo_cmd_flush_queue_be");
        hal_reo_cmd_flush_queue_be___last_ticks = v152;
        return 4294967280LL;
      }
      return 4294967280LL;
    }
    *(_DWORD *)v34 = *(_DWORD *)v34 & 0xFFC00001 | 0x9234;
    qdf_mem_set((void *)(v34 + 8), 0x20u, 0);
    v115 = *(_QWORD *)(v34 + 8);
    *(_DWORD *)(v34 + 4) = *(_DWORD *)(v34 + 4) & 0xFFFEFFFF | ((*(_BYTE *)a4 & 1) << 16);
    v116 = v115 & 0xFFFFFF0000000000LL
         | *(unsigned int *)(a4 + 4)
         | ((unsigned __int64)*(unsigned __int8 *)(a4 + 8) << 32);
    *(_QWORD *)(v34 + 8) = v116;
    v117 = v116 & 0xFFFFFEFFFFFFFFFFLL | ((unsigned __int64)(*(_BYTE *)(a4 + 12) & 1) << 40);
    *(_QWORD *)(v34 + 8) = v117;
    if ( *(_BYTE *)(a4 + 12) == 1 )
      *(_QWORD *)(v34 + 8) = v117 & 0xFFFFF9FFFFFFFFFFLL | ((unsigned __int64)(*(_BYTE *)(a4 + 13) & 3) << 41);
    goto LABEL_85;
  }
  if ( a3 != 2 )
  {
LABEL_39:
    qdf_trace_msg(
      0x46u,
      2u,
      "%s: Invalid REO command type: %d",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "hal_reo_send_cmd_be");
    return 4294967274LL;
  }
  hal_srng_access_start_0(a1, a2);
  if ( *(_BYTE *)(a4 + 16) == 1 )
  {
    v16 = (*(_BYTE *)(v15 + 320) + 1) & ~*(_BYTE *)(v15 + 320) & 0xF;
    if ( !v16 )
      goto LABEL_10;
    v17 = 0;
    do
    {
      v18 = v16;
      v16 >>= 1;
      v19 = v17++;
    }
    while ( v18 > 1 );
    if ( (unsigned int)v19 >= 4 )
    {
LABEL_10:
      v20 = *(_QWORD *)(a2 + 88);
      if ( (v20 & 1) != 0 )
      {
        *(_QWORD *)(a2 + 88) = v20 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a2 + 80);
      }
      else
      {
        raw_spin_unlock(a2 + 80);
      }
      v29 = jiffies;
      if ( hal_reo_cmd_flush_cache_be___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x46u,
          3u,
          "%s: No blocking resource available!",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "hal_reo_cmd_flush_cache_be");
        hal_reo_cmd_flush_cache_be___last_ticks = v29;
        return 4294967280LL;
      }
      return 4294967280LL;
    }
    v173 = v19 << 42;
    *(_BYTE *)(v15 + 321) = v19;
  }
  else
  {
    v173 = 0;
  }
  v178 = *(unsigned int *)(a2 + 120);
  v179 = (unsigned int)(*(_DWORD *)(a2 + 44) + v178) % *(_DWORD *)(a2 + 36);
  if ( v179 != *(_DWORD *)(a2 + 136) )
  {
    v180 = *(_QWORD *)(a2 + 16);
    *(_DWORD *)(a2 + 120) = v179;
    *(_DWORD *)(a2 + 124) = v179;
    v34 = v180 + 4 * v178;
    if ( v34 )
    {
      *(_DWORD *)v34 = *(_DWORD *)v34 & 0xFFC00001 | 0x9236;
      qdf_mem_set((void *)(v34 + 8), 0x20u, 0);
      v181 = *(_QWORD *)(v34 + 8);
      *(_DWORD *)(v34 + 4) = *(_DWORD *)(v34 + 4) & 0xFFFEFFFF | ((*(_BYTE *)a4 & 1) << 16);
      v182 = v181 & 0xFFFFFF0000000000LL
           | *(unsigned int *)(a4 + 4)
           | ((unsigned __int64)*(unsigned __int8 *)(a4 + 8) << 32);
      *(_QWORD *)(v34 + 8) = v182;
      *(_QWORD *)(v34 + 8) = v182 & 0xFFFFFEFFFFFFFFFFLL | ((unsigned __int64)(*(_BYTE *)(a4 + 12) & 1) << 40);
      *(_BYTE *)(a4 + 13) = 0;
      v183 = *(_QWORD *)(v34 + 8);
      v184 = v183 & 0xFFFFFDFFFFFFFFFFLL;
      *(_QWORD *)(v34 + 8) = v183 & 0xFFFFFDFFFFFFFFFFLL;
      if ( *(_BYTE *)(a4 + 16) == 1 )
      {
        v184 = v183 & 0xFFFFF1FFFFFFFFFFLL | v173;
        *(_QWORD *)(v34 + 8) = v184;
      }
      v185 = v184 & 0xFFFFEFFFFFFFFFFFLL | ((unsigned __int64)(*(_BYTE *)(a4 + 15) & 1) << 44);
      *(_QWORD *)(v34 + 8) = v185;
      v186 = v185 & 0xFFFF7FFFFFFFFFFFLL | ((unsigned __int64)(*(_BYTE *)(a4 + 18) & 1) << 47);
      *(_QWORD *)(v34 + 8) = v186;
      v187 = v186 & 0xFFFFDFFFFFFFFFFFLL | ((unsigned __int64)(*(_BYTE *)(a4 + 16) & 1) << 45);
      *(_QWORD *)(v34 + 8) = v187;
      v90 = v187 & 0xFFFFBFFFFFFFFFFFLL | ((unsigned __int64)(*(_BYTE *)(a4 + 17) & 1) << 46);
LABEL_84:
      *(_QWORD *)(v34 + 8) = v90;
LABEL_85:
      hal_srng_rtpm_access_end(a1, a2, 1);
      return *(unsigned __int16 *)(v34 + 4);
    }
  }
  v188 = *(_QWORD *)(a2 + 88);
  if ( (v188 & 1) != 0 )
  {
    *(_QWORD *)(a2 + 88) = v188 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a2 + 80);
  }
  else
  {
    raw_spin_unlock(a2 + 80);
  }
  hal_srng_dump(a2);
  return 4294967280LL;
}
