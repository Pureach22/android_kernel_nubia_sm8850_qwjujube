__int64 __fastcall cm_roam_stats_event_handler(__int64 a1, unsigned __int8 *a2)
{
  unsigned __int8 *v4; // x23
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int *v14; // x8
  __int64 v15; // x21
  unsigned __int64 v16; // x22
  unsigned __int8 *v17; // x27
  unsigned __int8 *v18; // x23
  unsigned int v19; // w8
  __int64 v20; // x28
  unsigned __int8 *v21; // x26
  unsigned int v22; // w8
  unsigned int v23; // w8
  unsigned int v24; // w24
  int v25; // w9
  char v26; // w10
  unsigned __int64 StatusReg; // x8
  __int64 v28; // x9
  unsigned __int8 *v29; // x25
  __int64 v30; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x24
  int v40; // w8
  unsigned int *v41; // x8
  char v42; // w26
  int v43; // w8
  char v44; // w9
  unsigned __int64 v45; // x9
  __int16 v46; // w8
  __int64 v47; // x9
  int v48; // w10
  __int64 v49; // x10
  _BOOL8 v50; // x5
  unsigned __int8 *v51; // x2
  __int64 v52; // x24
  int v53; // w8
  unsigned int v54; // w0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x25
  unsigned __int8 *v64; // x8
  __int64 v65; // x24
  __int64 v66; // x8
  __int64 v67; // x25
  unsigned int v68; // w24
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  __int64 v77; // x26
  unsigned int v78; // w8
  __int64 v79; // x10
  __int64 v80; // x10
  __int64 v81; // x11
  _WORD *v82; // x12
  unsigned __int8 *v83; // x11
  __int64 v84; // x13
  int v85; // w14
  unsigned __int8 v86; // w10
  unsigned __int8 v87; // w9
  unsigned int v88; // w12
  __int16 v89; // w14
  int v90; // w15
  unsigned __int8 v91; // w16
  unsigned __int8 v92; // w10
  unsigned __int8 v93; // w17
  unsigned int v94; // w11
  unsigned int v95; // w13
  int v96; // w8
  unsigned int v97; // w8
  unsigned int v98; // w1
  unsigned __int8 *v99; // x24
  int v100; // w8
  char v101; // w9
  unsigned __int64 v102; // x8
  __int64 v103; // x9
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  __int64 v112; // x24
  int v113; // w8
  unsigned int v114; // w0
  unsigned int v115; // w25
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  __int64 v124; // x26
  unsigned __int8 *v125; // x8
  __int64 v126; // x24
  __int64 v127; // x8
  __int64 v128; // x25
  unsigned int v129; // w24
  double v130; // d0
  double v131; // d1
  double v132; // d2
  double v133; // d3
  double v134; // d4
  double v135; // d5
  double v136; // d6
  double v137; // d7
  __int64 v138; // x26
  unsigned int v139; // w21
  double v140; // d0
  double v141; // d1
  double v142; // d2
  double v143; // d3
  double v144; // d4
  double v145; // d5
  double v146; // d6
  double v147; // d7
  _BYTE *v148; // x21
  int v149; // w8
  unsigned int v150; // w0
  unsigned int v151; // w22
  double v152; // d0
  double v153; // d1
  double v154; // d2
  double v155; // d3
  double v156; // d4
  double v157; // d5
  double v158; // d6
  double v159; // d7
  __int64 v160; // x24
  unsigned int v161; // w8
  int v162; // w25
  __int64 v163; // x26
  unsigned int v164; // w8
  __int64 v165; // x21
  unsigned int v166; // w23
  double v167; // d0
  double v168; // d1
  double v169; // d2
  double v170; // d3
  double v171; // d4
  double v172; // d5
  double v173; // d6
  double v174; // d7
  __int64 v175; // x22
  __int64 v177; // [xsp+0h] [xbp-1E0h]
  __int64 v178; // [xsp+8h] [xbp-1D8h]
  __int64 v179; // [xsp+10h] [xbp-1D0h]
  unsigned int v180; // [xsp+2Ch] [xbp-1B4h]
  int v181; // [xsp+38h] [xbp-1A8h]
  unsigned __int8 *v182; // [xsp+40h] [xbp-1A0h]
  unsigned __int8 *v183; // [xsp+48h] [xbp-198h]
  unsigned __int8 *v184; // [xsp+50h] [xbp-190h]
  unsigned __int8 *v185; // [xsp+58h] [xbp-188h]
  unsigned __int8 *v186; // [xsp+60h] [xbp-180h]
  unsigned __int8 *v187; // [xsp+78h] [xbp-168h]
  _WORD s[152]; // [xsp+80h] [xbp-160h] BYREF
  char v189; // [xsp+1B0h] [xbp-30h]
  char v190[8]; // [xsp+1B8h] [xbp-28h] BYREF
  __int64 v191; // [xsp+1C0h] [xbp-20h]
  __int64 v192; // [xsp+1C8h] [xbp-18h]
  __int64 v193; // [xsp+1D0h] [xbp-10h]

  v193 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v4 = a2 + 36864;
    v5 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a2, 77);
    if ( v5 )
    {
      v14 = (unsigned int *)a2[1];
      v15 = v5;
      if ( a2[1] )
      {
        v187 = a2 + 1044;
        v16 = 0;
        v181 = 0;
        v182 = a2 + 37024;
        v185 = a2 + 4444;
        v17 = a2 + 1062;
        v18 = a2 + 1060;
        v184 = a2 + 4584;
        v186 = a2 + 37964;
        v183 = a2 + 38124;
        while ( 1 )
        {
          if ( v16 == 5 )
            goto LABEL_139;
          v20 = (__int64)&a2[208 * v16 + 4];
          if ( *(_BYTE *)v20 != 1 )
            goto LABEL_85;
          v21 = &v187[680 * v16];
          if ( v21 && *v21 == 1 && (v22 = *((unsigned __int16 *)v21 + 1), v22 <= 4) )
            v23 = 0x1Au >> v22;
          else
            LOBYTE(v23) = 0;
          v24 = v23 & 1;
          s[21] = 0;
          *(_QWORD *)&s[17] = 0;
          v25 = *(_DWORD *)(v15 + 16);
          *(_DWORD *)s = 3145740;
          v26 = *(_BYTE *)(v15 + 168);
          LOBYTE(s[2]) = v25;
          HIBYTE(s[2]) = v26;
          *(_QWORD *)&s[3] = qdf_get_time_of_the_day_us();
          __isb(0xFu);
          StatusReg = _ReadStatusReg(CNTVCT_EL0);
          v28 = *(_QWORD *)(v20 + 4);
          *(_QWORD *)&s[7] = StatusReg;
          LOBYTE(s[22]) = v24;
          *(_QWORD *)&s[11] = v28;
          LODWORD(v28) = *(_DWORD *)(v20 + 16);
          *(_DWORD *)&s[15] = *(_DWORD *)(v20 + 12);
          LODWORD(StatusReg) = *(_DWORD *)(v20 + 188);
          *(_DWORD *)&s[19] = v28;
          LOBYTE(v28) = *(_BYTE *)(v20 + 192);
          *(_DWORD *)((char *)&s[22] + 1) = StatusReg;
          LOWORD(StatusReg) = *(_WORD *)(v20 + 193);
          HIBYTE(s[24]) = v28;
          s[25] = StatusReg;
          wlan_cp_stats_cstats_write_to_buff(0, s, 52);
          v29 = &v182[188 * v16];
          if ( *(_DWORD *)(v20 + 4) != 10 )
          {
            cm_roam_stats_print_trigger_info(a1, &v182[188 * v16], v20, v21, *a2, v24);
            if ( *v21 == 1 )
            {
              cm_roam_stats_print_scan_info(a1, v21, *a2, *(unsigned int *)(v20 + 4), *(unsigned int *)(v20 + 16));
              memset(&s[15], 0, 0x112u);
              if ( *((unsigned __int16 *)v21 + 2) < 9u || *((unsigned __int16 *)v21 + 3) <= 0x26u )
              {
                v43 = *(_DWORD *)(v15 + 16);
                *(_DWORD *)s = 19726349;
                v44 = *(_BYTE *)(v15 + 168);
                LOBYTE(s[2]) = v43;
                HIBYTE(s[2]) = v44;
                *(_QWORD *)&s[3] = qdf_get_time_of_the_day_us();
                __isb(0xFu);
                v45 = _ReadStatusReg(CNTVCT_EL0);
                v46 = *((_WORD *)v21 + 2);
                *(_QWORD *)&s[7] = v45;
                v47 = *((unsigned __int16 *)v21 + 3);
                v48 = *((_DWORD *)v21 + 168);
                s[13] = v46;
                s[14] = v47;
                *(_DWORD *)&s[11] = v48;
                if ( (_DWORD)v47 )
                {
                  if ( (unsigned int)v47 >= 3 )
                  {
                    v79 = v47 - 1;
                    if ( (unsigned __int64)(v47 - 1) >= 0x26 )
                      v79 = 38;
                    v80 = v79 + 1;
                    v81 = v80 & 1;
                    if ( (v80 & 1) == 0 )
                      v81 = 2;
                    v82 = &s[16];
                    v49 = v80 - v81;
                    v83 = v17;
                    v84 = v49;
                    do
                    {
                      v85 = *(_DWORD *)(v83 - 2);
                      v84 -= 2;
                      v83 += 4;
                      *(_DWORD *)(v82 - 1) = v85;
                      v82 += 2;
                    }
                    while ( v84 );
                  }
                  else
                  {
                    v49 = 0;
                  }
                  while ( v49 != 38 )
                  {
                    s[v49 + 15] = *(_WORD *)&v18[2 * v49];
                    if ( v47 == ++v49 )
                      goto LABEL_71;
                  }
LABEL_139:
                  __break(0x5512u);
                }
LABEL_71:
                v189 = v24;
                if ( (_BYTE)v46 )
                {
                  v86 = v21[97];
                  v87 = v21[98];
                  v88 = *((_DWORD *)v21 + 29);
                  v89 = *((_WORD *)v21 + 52);
                  LOBYTE(s[54]) = v21[99];
                  v90 = *((_DWORD *)v21 + 27);
                  v91 = v21[148];
                  LOBYTE(s[53]) = v86;
                  v92 = v21[102];
                  v93 = v21[96];
                  HIBYTE(s[53]) = v87;
                  HIBYTE(s[54]) = v92;
                  v94 = *((_DWORD *)v21 + 31);
                  v95 = *((_DWORD *)v21 + 32);
                  *(_DWORD *)&s[57] = v88;
                  s[61] = v89;
                  *(_DWORD *)&s[55] = v94;
                  *(_DWORD *)&s[59] = v95;
                  s[62] = v90;
                  LOBYTE(s[63]) = v91;
                  HIBYTE(s[63]) = v93;
                  if ( (unsigned __int8)v46 != 1 )
                  {
                    HIBYTE(s[53]) = v87;
                    HIBYTE(s[54]) = v92;
                    *(_DWORD *)&s[66] = v94;
                    *(_QWORD *)&s[68] = __PAIR64__(v95, v88);
                    s[72] = v89;
                    s[73] = v90;
                    LOBYTE(s[74]) = v91;
                    HIBYTE(s[74]) = v93;
                    if ( (unsigned __int8)v46 != 2 )
                    {
                      HIBYTE(s[53]) = v87;
                      HIBYTE(s[54]) = v92;
                      *(_DWORD *)&s[77] = v94;
                      *(_DWORD *)&s[79] = v88;
                      *(_DWORD *)&s[81] = v95;
                      s[83] = v89;
                      s[84] = v90;
                      LOBYTE(s[85]) = v91;
                      HIBYTE(s[85]) = v93;
                      if ( (unsigned __int8)v46 != 3 )
                      {
                        HIBYTE(s[53]) = v87;
                        HIBYTE(s[54]) = v92;
                        *(_QWORD *)&s[88] = __PAIR64__(v88, v94);
                        *(_DWORD *)&s[92] = v95;
                        s[94] = v89;
                        s[95] = v90;
                        LOBYTE(s[96]) = v91;
                        HIBYTE(s[96]) = v93;
                        if ( (unsigned __int8)v46 != 4 )
                        {
                          HIBYTE(s[53]) = v87;
                          HIBYTE(s[54]) = v92;
                          *(_DWORD *)&s[99] = v94;
                          *(_DWORD *)&s[101] = v88;
                          *(_DWORD *)&s[103] = v95;
                          s[105] = v89;
                          s[106] = v90;
                          LOBYTE(s[107]) = v91;
                          HIBYTE(s[107]) = v93;
                          if ( (unsigned __int8)v46 != 5 )
                          {
                            HIBYTE(s[53]) = v87;
                            HIBYTE(s[54]) = v92;
                            *(_DWORD *)&s[110] = v94;
                            *(_QWORD *)&s[112] = __PAIR64__(v95, v88);
                            s[116] = v89;
                            s[117] = v90;
                            LOBYTE(s[118]) = v91;
                            HIBYTE(s[118]) = v93;
                            if ( (unsigned __int8)v46 != 6 )
                            {
                              HIBYTE(s[53]) = v87;
                              HIBYTE(s[54]) = v92;
                              *(_DWORD *)&s[121] = v94;
                              *(_DWORD *)&s[123] = v88;
                              *(_DWORD *)&s[125] = v95;
                              s[127] = v89;
                              s[128] = v90;
                              LOBYTE(s[129]) = v91;
                              HIBYTE(s[129]) = v93;
                              if ( (unsigned __int8)v46 != 7 )
                              {
                                HIBYTE(s[53]) = v87;
                                HIBYTE(s[54]) = v92;
                                *(_QWORD *)&s[132] = __PAIR64__(v88, v94);
                                *(_DWORD *)&s[136] = v95;
                                s[138] = v89;
                                s[139] = v90;
                                LOBYTE(s[140]) = v91;
                                HIBYTE(s[140]) = v93;
                                if ( (unsigned __int8)v46 != 8 )
                                {
                                  HIBYTE(s[53]) = v87;
                                  HIBYTE(s[54]) = v92;
                                  *(_DWORD *)&s[143] = v94;
                                  *(_DWORD *)&s[145] = v88;
                                  *(_DWORD *)&s[147] = v95;
                                  s[149] = v89;
                                  s[150] = v90;
                                  LOBYTE(s[151]) = v91;
                                  HIBYTE(s[151]) = v93;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
                wlan_cp_stats_cstats_write_to_buff(0, s, 305);
              }
              v96 = *(_DWORD *)(v20 + 4);
              if ( v96 == 5 || v96 == 3 )
              {
                v97 = *((_DWORD *)v21 + 3);
                v98 = *a2;
                memset(&s[4], 0, 24);
                *(_QWORD *)s = v97;
                wlan_cm_roam_cfg_set_value(a1, v98, 0xEu, (unsigned int *)s);
              }
            }
LABEL_85:
            v99 = &v185[28 * v16];
            if ( *v99 == 1 )
            {
              cm_roam_stats_print_roam_result(a1, v20, &v185[28 * v16], &v187[680 * v16], *a2);
              *(_DWORD *)((char *)&s[20] + 1) = 0;
              *(_DWORD *)&s[19] = 0;
              v100 = *(_DWORD *)(v15 + 16);
              *(_DWORD *)s = 2949134;
              v101 = *(_BYTE *)(v15 + 168);
              LOBYTE(s[2]) = v100;
              HIBYTE(s[2]) = v101;
              *(_QWORD *)&s[3] = qdf_get_time_of_the_day_us();
              __isb(0xFu);
              v102 = _ReadStatusReg(CNTVCT_EL0);
              v103 = *(_QWORD *)(v99 + 4);
              *(_QWORD *)&s[7] = v102;
              *(_QWORD *)&s[13] = v103;
              LODWORD(v103) = *((_DWORD *)v99 + 4);
              *(_DWORD *)&s[17] = *((_DWORD *)v99 + 3);
              LOBYTE(v102) = v99[20];
              *(_DWORD *)((char *)&s[22] + 1) = v103;
              LOWORD(v103) = *(_WORD *)(v99 + 21);
              LOBYTE(s[11]) = v102;
              LOBYTE(v102) = v99[25];
              *(_WORD *)((char *)&s[11] + 1) = v103;
              HIBYTE(s[12]) = v102;
              wlan_cp_stats_cstats_write_to_buff(0, s, 49);
            }
            if ( v184[6488 * v16] )
              cm_roam_print_frame_info(a1, v15);
            wlan_cm_update_roam_stats_info(a1, a2, (unsigned int)v16);
            v112 = (__int64)&v186[32 * v16];
            if ( *(_BYTE *)v112 == 1 && *(_BYTE *)v20 == 1 )
            {
              v113 = *(_DWORD *)(v20 + 4);
              if ( v113 == 17 || v113 == 10 )
              {
                v114 = *(_DWORD *)(v112 + 20);
                v115 = *a2;
                memset(s, 0, 24);
                mlme_get_converted_timestamp(v114, (char *)s);
                v124 = jiffies;
                if ( cm_roam_stats_print_btm_rsp_info___last_ticks - jiffies + 125 < 0 )
                {
                  LODWORD(v179) = *(unsigned __int8 *)(v112 + 13);
                  LODWORD(v178) = *(unsigned __int8 *)(v112 + 10);
                  LODWORD(v177) = *(unsigned __int8 *)(v112 + 9);
                  qdf_trace_msg(
                    0x68u,
                    4u,
                    "%s [BTM RSP]:VDEV[%d], Status:%d, VSIE reason:%d, BSSID: %02x:%02x:%02x:**:**:%02x",
                    v116,
                    v117,
                    v118,
                    v119,
                    v120,
                    v121,
                    v122,
                    v123,
                    s,
                    v115,
                    *(unsigned int *)(v112 + 4),
                    *(unsigned int *)(v112 + 16),
                    *(unsigned __int8 *)(v112 + 8),
                    v177,
                    v178,
                    v179);
                  cm_roam_stats_print_btm_rsp_info___last_ticks = v124;
                }
                cm_roam_btm_resp_event((_DWORD *)v20, v112, v115, 0, v116, v117, v118, v119, v120, v121, v122, v123);
              }
            }
            v125 = &v183[20 * v16];
            if ( *v125 == 1 )
            {
              v126 = jiffies;
              if ( cm_roam_stats_print_roam_initial_info___last_ticks - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x68u,
                  4u,
                  "[ROAM INIT INFO]: VDEV[%d], roam_full_scan_count: %d, rssi_th: %d, cu_th: %d, fw_cancel_timer_bitmap: %d",
                  v104,
                  v105,
                  v106,
                  v107,
                  v108,
                  v109,
                  v110,
                  v111,
                  *a2,
                  *((unsigned int *)v125 + 1),
                  *((unsigned int *)v125 + 2),
                  *((unsigned int *)v125 + 3),
                  *((unsigned int *)v125 + 4));
                cm_roam_stats_print_roam_initial_info___last_ticks = v126;
              }
            }
            v127 = *((_QWORD *)a2 + 4778);
            if ( v127 )
            {
              if ( v16 < a2[2] )
              {
                v128 = v127 + 20 * v16;
                if ( *(_BYTE *)v128 == 1 )
                {
                  if ( (unsigned int)(*(_DWORD *)(v128 + 8) - 1) <= 1 )
                  {
                    v191 = 0;
                    v192 = 0;
                    v129 = *a2;
                    *(_QWORD *)v190 = 0;
                    mlme_get_converted_timestamp(*(_DWORD *)(v128 + 4), v190);
                    v138 = jiffies;
                    if ( cm_roam_stats_process_roam_msg_info___last_ticks - jiffies + 125 < 0 )
                    {
                      qdf_trace_msg(
                        0x68u,
                        4u,
                        "%s [ROAM MSG INFO]: VDEV[%d] %s, Current rssi: %d dbm, next_rssi_threshold: %d dbm",
                        v130,
                        v131,
                        v132,
                        v133,
                        v134,
                        v135,
                        v136,
                        v137,
                        v190,
                        v129,
                        "Roam RSSI TH Reset",
                        *(unsigned int *)(v128 + 12),
                        *(unsigned int *)(v128 + 16));
                      cm_roam_stats_process_roam_msg_info___last_ticks = v138;
                    }
                    v19 = *(_DWORD *)(v128 + 16);
                    memset(&s[4], 0, 24);
                    *(_QWORD *)s = v19;
                    wlan_cm_roam_cfg_set_value(a1, v129, 0xEu, (unsigned int *)s);
                  }
                  ++v181;
                }
              }
            }
            ((void (__fastcall *)(__int64, _QWORD, __int64, unsigned __int8 *, _QWORD, _QWORD, _QWORD))cm_report_roam_rt_stats)(
              a1,
              *a2,
              2,
              a2,
              0,
              (unsigned int)v16,
              0);
            goto LABEL_8;
          }
          if ( *v29 == 1 )
            cm_roam_stats_print_11kv_info(a1, &v182[188 * v16], *a2);
          v30 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a2, 77);
          if ( v30 )
            break;
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: vdev: %d vdev not found",
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            "cm_roam_handle_btm_stats",
            *a2);
LABEL_61:
          if ( *(_BYTE *)(v20 + 1) == 1 )
            wlan_cm_update_roam_stats_info(a1, a2, (unsigned int)v16);
LABEL_8:
          v14 = (unsigned int *)a2[1];
          ++v16;
          v17 += 680;
          v18 += 680;
          if ( v16 >= (unsigned __int64)v14 )
            goto LABEL_108;
        }
        v39 = v30;
        if ( *v21 == 1 )
        {
          v40 = *((unsigned __int16 *)v21 + 1);
          if ( v40 == 2 )
          {
            cm_roam_btm_req_event((__int64)v29, v20 + 20, v20, *a2, 0);
            v42 = 1;
LABEL_41:
            wlan_objmgr_vdev_release_ref(v39, 0x4Du, v41, v31, v32, v33, v34, v35, v36, v37, v38);
            v52 = (__int64)&v186[32 * v16];
            if ( *(_BYTE *)v52 == 1 && *(_BYTE *)v20 == 1 )
            {
              v53 = *(_DWORD *)(v20 + 4);
              if ( v53 == 17 || v53 == 10 )
              {
                v54 = *(_DWORD *)(v52 + 20);
                v180 = *a2;
                memset(s, 0, 24);
                mlme_get_converted_timestamp(v54, (char *)s);
                v63 = jiffies;
                if ( cm_roam_stats_print_btm_rsp_info___last_ticks - jiffies + 125 < 0 )
                {
                  LODWORD(v179) = *(unsigned __int8 *)(v52 + 13);
                  LODWORD(v178) = *(unsigned __int8 *)(v52 + 10);
                  LODWORD(v177) = *(unsigned __int8 *)(v52 + 9);
                  qdf_trace_msg(
                    0x68u,
                    4u,
                    "%s [BTM RSP]:VDEV[%d], Status:%d, VSIE reason:%d, BSSID: %02x:%02x:%02x:**:**:%02x",
                    v55,
                    v56,
                    v57,
                    v58,
                    v59,
                    v60,
                    v61,
                    v62,
                    s,
                    v180,
                    *(unsigned int *)(v52 + 4),
                    *(unsigned int *)(v52 + 16),
                    *(unsigned __int8 *)(v52 + 8),
                    v177,
                    v178,
                    v179);
                  cm_roam_stats_print_btm_rsp_info___last_ticks = v63;
                }
                cm_roam_btm_resp_event((_DWORD *)v20, v52, v180, 0, v55, v56, v57, v58, v59, v60, v61, v62);
              }
            }
            if ( (v42 & 1) == 0 )
            {
              v64 = &v183[20 * v16];
              if ( *v64 == 1 )
              {
                v65 = jiffies;
                if ( cm_roam_stats_print_roam_initial_info___last_ticks - jiffies + 125 < 0 )
                {
                  qdf_trace_msg(
                    0x68u,
                    4u,
                    "[ROAM INIT INFO]: VDEV[%d], roam_full_scan_count: %d, rssi_th: %d, cu_th: %d, fw_cancel_timer_bitmap: %d",
                    v6,
                    v7,
                    v8,
                    v9,
                    v10,
                    v11,
                    v12,
                    v13,
                    *a2,
                    *((unsigned int *)v64 + 1),
                    *((unsigned int *)v64 + 2),
                    *((unsigned int *)v64 + 3),
                    *((unsigned int *)v64 + 4));
                  cm_roam_stats_print_roam_initial_info___last_ticks = v65;
                }
              }
              v66 = *((_QWORD *)a2 + 4778);
              if ( v66 )
              {
                v67 = v66 + 20 * v16;
                if ( *(_BYTE *)v67 == 1 && v16 < a2[2] )
                {
                  if ( (unsigned int)(*(_DWORD *)(v67 + 8) - 1) <= 1 )
                  {
                    v191 = 0;
                    v192 = 0;
                    v68 = *a2;
                    *(_QWORD *)v190 = 0;
                    mlme_get_converted_timestamp(*(_DWORD *)(v67 + 4), v190);
                    v77 = jiffies;
                    if ( cm_roam_stats_process_roam_msg_info___last_ticks - jiffies + 125 < 0 )
                    {
                      qdf_trace_msg(
                        0x68u,
                        4u,
                        "%s [ROAM MSG INFO]: VDEV[%d] %s, Current rssi: %d dbm, next_rssi_threshold: %d dbm",
                        v69,
                        v70,
                        v71,
                        v72,
                        v73,
                        v74,
                        v75,
                        v76,
                        v190,
                        v68,
                        "Roam RSSI TH Reset",
                        *(unsigned int *)(v67 + 12),
                        *(unsigned int *)(v67 + 16));
                      cm_roam_stats_process_roam_msg_info___last_ticks = v77;
                    }
                    v78 = *(_DWORD *)(v67 + 16);
                    memset(&s[4], 0, 24);
                    *(_QWORD *)s = v78;
                    wlan_cm_roam_cfg_set_value(a1, v68, 0xEu, (unsigned int *)s);
                  }
                  ++v181;
                }
              }
              ((void (__fastcall *)(__int64, _QWORD, __int64, unsigned __int8 *, _QWORD, _QWORD, _QWORD))cm_report_roam_rt_stats)(
                a1,
                *a2,
                2,
                a2,
                0,
                (unsigned int)v16,
                0);
            }
            goto LABEL_61;
          }
          if ( (*(_BYTE *)v20 & 1) != 0 )
          {
            v50 = v40 != 0;
LABEL_34:
            cm_roam_stats_print_trigger_info(a1, v29, v20, v21, *a2, v50);
            if ( *v21 == 1 )
              cm_roam_stats_print_scan_info(a1, v21, *a2, *(unsigned int *)(v20 + 4), *(unsigned int *)(v20 + 16));
          }
        }
        else if ( (*(_BYTE *)v20 & 1) != 0 )
        {
          v50 = 0;
          goto LABEL_34;
        }
        if ( v185[28 * v16] == 1 )
          cm_roam_stats_print_roam_result(a1, v20, &v185[28 * v16], v21, *a2);
        v51 = &v184[6488 * v16];
        v41 = (unsigned int *)*v51;
        if ( *v51 )
          cm_roam_print_frame_info(a1, v39);
        v42 = 0;
        goto LABEL_41;
      }
      LOBYTE(v181) = 0;
LABEL_108:
      wlan_objmgr_vdev_release_ref(v15, 0x4Du, v14, v6, v7, v8, v9, v10, v11, v12, v13);
      v4 = a2 + 36864;
      if ( !a2[1] )
      {
        if ( a2[37024] == 1 )
          cm_roam_stats_print_11kv_info(a1, a2 + 37024, *a2);
        v148 = a2 + 4;
        if ( a2[4] == 1 )
        {
          v149 = *((_DWORD *)a2 + 2);
          if ( v149 == 17 || v149 == 10 )
            cm_roam_btm_req_event((__int64)(a2 + 37024), (__int64)(a2 + 24), (__int64)(a2 + 4), *a2, v149 == 17);
        }
        if ( a2[1044] == 1 && *v148 == 1 )
          cm_roam_stats_print_scan_info(a1, a2 + 1044, *a2, *((unsigned int *)a2 + 2), *((unsigned int *)a2 + 5));
        if ( a2[37964] == 1 )
        {
          v150 = *((_DWORD *)a2 + 9496);
          v151 = *a2;
          memset(s, 0, 24);
          mlme_get_converted_timestamp(v150, (char *)s);
          v160 = jiffies;
          if ( cm_roam_stats_print_btm_rsp_info___last_ticks - jiffies + 125 < 0 )
          {
            LODWORD(v179) = a2[37977];
            LODWORD(v178) = a2[37974];
            LODWORD(v177) = a2[37973];
            qdf_trace_msg(
              0x68u,
              4u,
              "%s [BTM RSP]:VDEV[%d], Status:%d, VSIE reason:%d, BSSID: %02x:%02x:%02x:**:**:%02x",
              v152,
              v153,
              v154,
              v155,
              v156,
              v157,
              v158,
              v159,
              s,
              v151,
              *((unsigned int *)a2 + 9492),
              *((unsigned int *)a2 + 9495),
              a2[37972],
              v177,
              v178,
              v179);
            cm_roam_stats_print_btm_rsp_info___last_ticks = v160;
          }
          cm_roam_btm_resp_event(
            (_DWORD *)a2 + 1,
            (__int64)(a2 + 37964),
            v151,
            0,
            v152,
            v153,
            v154,
            v155,
            v156,
            v157,
            v158,
            v159);
        }
        if ( *v148 == 1 && *((_DWORD *)a2 + 2) == 17 )
          cm_roam_btm_resp_event((_DWORD *)a2 + 1, 0, *a2, 1, v140, v141, v142, v143, v144, v145, v146, v147);
      }
      if ( *((_QWORD *)a2 + 4778) )
      {
        v161 = a2[2];
        v139 = 0;
        if ( !a2[2] || v161 == (unsigned __int8)v181 )
          goto LABEL_137;
        if ( v161 > (unsigned __int8)v181 )
        {
          v162 = 0;
          v163 = 20LL * (unsigned __int8)v181;
          do
          {
            v165 = *((_QWORD *)v4 + 170);
            if ( *(_BYTE *)(v165 + v163) == 1 && (unsigned int)(*(_DWORD *)(v165 + v163 + 8) - 1) <= 1 )
            {
              v191 = 0;
              v192 = 0;
              v166 = *a2;
              *(_QWORD *)v190 = 0;
              mlme_get_converted_timestamp(*(_DWORD *)(v165 + v163 + 4), v190);
              v175 = jiffies;
              if ( cm_roam_stats_process_roam_msg_info___last_ticks - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x68u,
                  4u,
                  "%s [ROAM MSG INFO]: VDEV[%d] %s, Current rssi: %d dbm, next_rssi_threshold: %d dbm",
                  v167,
                  v168,
                  v169,
                  v170,
                  v171,
                  v172,
                  v173,
                  v174,
                  v190,
                  v166,
                  "Roam RSSI TH Reset",
                  *(unsigned int *)(v165 + v163 + 12),
                  *(unsigned int *)(v165 + v163 + 16));
                cm_roam_stats_process_roam_msg_info___last_ticks = v175;
              }
              v164 = *(_DWORD *)(v165 + v163 + 16);
              memset(&s[4], 0, 24);
              *(_QWORD *)s = v164;
              wlan_cm_roam_cfg_set_value(a1, v166, 0xEu, (unsigned int *)s);
              LOBYTE(v161) = a2[2];
              v4 = a2 + 36864;
            }
            ++v162;
            v163 += 20;
          }
          while ( (unsigned __int8)v161 - (unsigned __int8)v181 > (unsigned __int8)v162 );
        }
      }
      v139 = 0;
    }
    else
    {
      v139 = 16;
    }
LABEL_137:
    wlan_clear_sae_auth_logs_cache(a1, *a2);
    _qdf_mem_free(*((_QWORD *)v4 + 170));
    _qdf_mem_free((__int64)a2);
    goto LABEL_138;
  }
  v139 = 16;
LABEL_138:
  _ReadStatusReg(SP_EL0);
  return v139;
}
