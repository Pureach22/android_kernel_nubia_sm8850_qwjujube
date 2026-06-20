__int64 __fastcall cm_roam_stats_event_handler(__int64 a1, unsigned __int8 *a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int *v13; // x8
  __int64 v14; // x21
  unsigned __int64 v15; // x22
  unsigned __int8 *v16; // x27
  unsigned __int8 *v17; // x23
  unsigned int v18; // w8
  __int64 v19; // x28
  unsigned __int8 *v20; // x26
  unsigned int v21; // w8
  unsigned int v22; // w8
  unsigned int v23; // w24
  int v24; // w9
  char v25; // w10
  unsigned __int64 StatusReg; // x8
  __int64 v27; // x9
  unsigned __int8 *v28; // x25
  __int64 v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x24
  int v39; // w8
  unsigned int *v40; // x8
  char v41; // w26
  int v42; // w8
  char v43; // w9
  unsigned __int64 v44; // x9
  __int16 v45; // w8
  __int64 v46; // x9
  int v47; // w10
  __int64 v48; // x10
  _BOOL8 v49; // x5
  unsigned __int8 *v50; // x2
  __int64 v51; // x24
  int v52; // w8
  unsigned int v53; // w0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x25
  unsigned __int8 *v63; // x8
  __int64 v64; // x24
  __int64 v65; // x8
  __int64 v66; // x25
  unsigned int v67; // w24
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  __int64 v76; // x26
  unsigned int v77; // w8
  __int64 v78; // x10
  __int64 v79; // x10
  __int64 v80; // x11
  _WORD *v81; // x12
  unsigned __int8 *v82; // x11
  __int64 v83; // x13
  int v84; // w14
  unsigned __int8 v85; // w10
  unsigned __int8 v86; // w9
  unsigned int v87; // w12
  __int16 v88; // w14
  int v89; // w15
  unsigned __int8 v90; // w16
  unsigned __int8 v91; // w10
  unsigned __int8 v92; // w17
  unsigned int v93; // w11
  unsigned int v94; // w13
  int v95; // w8
  unsigned int v96; // w8
  unsigned int v97; // w1
  unsigned __int8 *v98; // x24
  int v99; // w8
  char v100; // w9
  unsigned __int64 v101; // x8
  __int64 v102; // x9
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  __int64 v111; // x24
  int v112; // w8
  unsigned int v113; // w0
  unsigned int v114; // w25
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  __int64 v123; // x26
  unsigned __int8 *v124; // x8
  __int64 v125; // x24
  __int64 v126; // x8
  __int64 v127; // x25
  unsigned int v128; // w24
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  __int64 v137; // x26
  unsigned int v138; // w21
  double v139; // d0
  double v140; // d1
  double v141; // d2
  double v142; // d3
  double v143; // d4
  double v144; // d5
  double v145; // d6
  double v146; // d7
  _BYTE *v147; // x21
  int v148; // w8
  unsigned int v149; // w0
  unsigned int v150; // w22
  double v151; // d0
  double v152; // d1
  double v153; // d2
  double v154; // d3
  double v155; // d4
  double v156; // d5
  double v157; // d6
  double v158; // d7
  __int64 v159; // x25
  unsigned int v160; // w8
  int v161; // w25
  __int64 v162; // x26
  unsigned int v163; // w8
  __int64 v164; // x21
  unsigned int v165; // w23
  double v166; // d0
  double v167; // d1
  double v168; // d2
  double v169; // d3
  double v170; // d4
  double v171; // d5
  double v172; // d6
  double v173; // d7
  __int64 v174; // x22
  __int64 v176; // [xsp+0h] [xbp-1E0h]
  __int64 v177; // [xsp+8h] [xbp-1D8h]
  __int64 v178; // [xsp+10h] [xbp-1D0h]
  unsigned int v179; // [xsp+34h] [xbp-1ACh]
  int v180; // [xsp+40h] [xbp-1A0h]
  unsigned __int8 *v181; // [xsp+48h] [xbp-198h]
  unsigned __int8 *v182; // [xsp+50h] [xbp-190h]
  unsigned __int8 *v183; // [xsp+58h] [xbp-188h]
  unsigned __int8 *v184; // [xsp+60h] [xbp-180h]
  unsigned __int8 *v185; // [xsp+68h] [xbp-178h]
  unsigned __int8 *v186; // [xsp+78h] [xbp-168h]
  _WORD s[152]; // [xsp+80h] [xbp-160h] BYREF
  char v188; // [xsp+1B0h] [xbp-30h]
  char v189[8]; // [xsp+1B8h] [xbp-28h] BYREF
  __int64 v190; // [xsp+1C0h] [xbp-20h]
  __int64 v191; // [xsp+1C8h] [xbp-18h]
  __int64 v192; // [xsp+1D0h] [xbp-10h]

  v192 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v4 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a2, 77);
    if ( v4 )
    {
      v13 = (unsigned int *)a2[1];
      v14 = v4;
      if ( a2[1] )
      {
        v186 = a2 + 1044;
        v15 = 0;
        v180 = 0;
        v181 = a2 + 15404;
        v184 = a2 + 4444;
        v16 = a2 + 1062;
        v17 = a2 + 1060;
        v183 = a2 + 4584;
        v185 = a2 + 16344;
        v182 = a2 + 16504;
        while ( 1 )
        {
          if ( v15 == 5 )
            goto LABEL_140;
          v19 = (__int64)&a2[208 * v15 + 4];
          if ( *(_BYTE *)v19 == 1 )
          {
            v20 = &v186[680 * v15];
            if ( v20 && *v20 == 1 && (v21 = *((unsigned __int16 *)v20 + 1), v21 <= 4) )
              v22 = 0x1Au >> v21;
            else
              LOBYTE(v22) = 0;
            v23 = v22 & 1;
            s[21] = 0;
            *(_QWORD *)&s[17] = 0;
            v24 = *(_DWORD *)(v14 + 16);
            *(_DWORD *)s = 3145740;
            v25 = *(_BYTE *)(v14 + 104);
            LOBYTE(s[2]) = v24;
            HIBYTE(s[2]) = v25;
            *(_QWORD *)&s[3] = qdf_get_time_of_the_day_us();
            __isb(0xFu);
            StatusReg = _ReadStatusReg(CNTVCT_EL0);
            v27 = *(_QWORD *)(v19 + 4);
            *(_QWORD *)&s[7] = StatusReg;
            LOBYTE(s[22]) = v23;
            *(_QWORD *)&s[11] = v27;
            LODWORD(v27) = *(_DWORD *)(v19 + 16);
            *(_DWORD *)&s[15] = *(_DWORD *)(v19 + 12);
            LODWORD(StatusReg) = *(_DWORD *)(v19 + 188);
            *(_DWORD *)&s[19] = v27;
            LOBYTE(v27) = *(_BYTE *)(v19 + 192);
            *(_DWORD *)((char *)&s[22] + 1) = StatusReg;
            LOWORD(StatusReg) = *(_WORD *)(v19 + 193);
            HIBYTE(s[24]) = v27;
            s[25] = StatusReg;
            wlan_cp_stats_cstats_write_to_buff(0, s, 52);
            v28 = &v181[188 * v15];
            if ( *(_DWORD *)(v19 + 4) == 10 )
            {
              if ( *v28 == 1 )
                cm_roam_stats_print_11kv_info(a1, &v181[188 * v15], *a2);
              v29 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                      a1,
                      *a2,
                      77);
              if ( v29 )
              {
                v38 = v29;
                if ( *v20 == 1 )
                {
                  v39 = *((unsigned __int16 *)v20 + 1);
                  if ( v39 == 2 )
                  {
                    cm_roam_btm_req_event((__int64)v28, v19 + 20, v19, *a2, 0);
                    v41 = 1;
                    goto LABEL_41;
                  }
                  if ( (*(_BYTE *)v19 & 1) != 0 )
                  {
                    v49 = v39 != 0;
                    goto LABEL_34;
                  }
                }
                else if ( (*(_BYTE *)v19 & 1) != 0 )
                {
                  v49 = 0;
LABEL_34:
                  cm_roam_stats_print_trigger_info(a1, v28, v19, v20, *a2, v49);
                  if ( *v20 == 1 )
                    cm_roam_stats_print_scan_info(a1, v20, *a2, *(unsigned int *)(v19 + 4), *(unsigned int *)(v19 + 16));
                }
                if ( v184[28 * v15] == 1 )
                  cm_roam_stats_print_roam_result(a1, v19, &v184[28 * v15], v20, *a2);
                v50 = &v183[2164 * v15];
                v40 = (unsigned int *)*v50;
                if ( *v50 )
                  cm_roam_print_frame_info(a1, v38);
                v41 = 0;
LABEL_41:
                wlan_objmgr_vdev_release_ref(v38, 0x4Du, v40, v30, v31, v32, v33, v34, v35, v36, v37);
                v51 = (__int64)&v185[32 * v15];
                if ( *(_BYTE *)v51 == 1 && *(_BYTE *)v19 == 1 )
                {
                  v52 = *(_DWORD *)(v19 + 4);
                  if ( v52 == 17 || v52 == 10 )
                  {
                    v53 = *(_DWORD *)(v51 + 20);
                    v179 = *a2;
                    memset(s, 0, 24);
                    mlme_get_converted_timestamp(v53, (char *)s);
                    v62 = jiffies;
                    if ( cm_roam_stats_print_btm_rsp_info___last_ticks - jiffies + 125 < 0 )
                    {
                      LODWORD(v178) = *(unsigned __int8 *)(v51 + 13);
                      LODWORD(v177) = *(unsigned __int8 *)(v51 + 10);
                      LODWORD(v176) = *(unsigned __int8 *)(v51 + 9);
                      qdf_trace_msg(
                        0x68u,
                        4u,
                        "%s [BTM RSP]:VDEV[%d], Status:%d, VSIE reason:%d, BSSID: %02x:%02x:%02x:**:**:%02x",
                        v54,
                        v55,
                        v56,
                        v57,
                        v58,
                        v59,
                        v60,
                        v61,
                        s,
                        v179,
                        *(unsigned int *)(v51 + 4),
                        *(unsigned int *)(v51 + 16),
                        *(unsigned __int8 *)(v51 + 8),
                        v176,
                        v177,
                        v178);
                      cm_roam_stats_print_btm_rsp_info___last_ticks = v62;
                    }
                    cm_roam_btm_resp_event((_DWORD *)v19, v51, v179, 0, v54, v55, v56, v57, v58, v59, v60, v61);
                  }
                }
                if ( (v41 & 1) == 0 )
                {
                  v63 = &v182[20 * v15];
                  if ( *v63 == 1 )
                  {
                    v64 = jiffies;
                    if ( cm_roam_stats_print_roam_initial_info___last_ticks - jiffies + 125 < 0 )
                    {
                      qdf_trace_msg(
                        0x68u,
                        4u,
                        "[ROAM INIT INFO]: VDEV[%d], roam_full_scan_count: %d, rssi_th: %d, cu_th: %d, fw_cancel_timer_bitmap: %d",
                        v5,
                        v6,
                        v7,
                        v8,
                        v9,
                        v10,
                        v11,
                        v12,
                        *a2,
                        *((unsigned int *)v63 + 1),
                        *((unsigned int *)v63 + 2),
                        *((unsigned int *)v63 + 3),
                        *((unsigned int *)v63 + 4));
                      cm_roam_stats_print_roam_initial_info___last_ticks = v64;
                    }
                  }
                  v65 = *((_QWORD *)a2 + 2076);
                  if ( v65 )
                  {
                    v66 = v65 + 20 * v15;
                    if ( *(_BYTE *)v66 == 1 && v15 < a2[2] )
                    {
                      if ( (unsigned int)(*(_DWORD *)(v66 + 8) - 1) <= 1 )
                      {
                        v190 = 0;
                        v191 = 0;
                        v67 = *a2;
                        *(_QWORD *)v189 = 0;
                        mlme_get_converted_timestamp(*(_DWORD *)(v66 + 4), v189);
                        v76 = jiffies;
                        if ( cm_roam_stats_process_roam_msg_info___last_ticks - jiffies + 125 < 0 )
                        {
                          qdf_trace_msg(
                            0x68u,
                            4u,
                            "%s [ROAM MSG INFO]: VDEV[%d] %s, Current rssi: %d dbm, next_rssi_threshold: %d dbm",
                            v68,
                            v69,
                            v70,
                            v71,
                            v72,
                            v73,
                            v74,
                            v75,
                            v189,
                            v67,
                            "Roam RSSI TH Reset",
                            *(unsigned int *)(v66 + 12),
                            *(unsigned int *)(v66 + 16));
                          cm_roam_stats_process_roam_msg_info___last_ticks = v76;
                        }
                        v77 = *(_DWORD *)(v66 + 16);
                        memset(&s[4], 0, 24);
                        *(_QWORD *)s = v77;
                        wlan_cm_roam_cfg_set_value(a1, v67, 0xEu, (unsigned int *)s);
                      }
                      ++v180;
                    }
                  }
                  ((void (__fastcall *)(__int64, _QWORD, __int64, unsigned __int8 *, _QWORD, _QWORD, _QWORD))cm_report_roam_rt_stats)(
                    a1,
                    *a2,
                    2,
                    a2,
                    0,
                    (unsigned int)v15,
                    0);
                }
              }
              else
              {
                qdf_trace_msg(
                  0x68u,
                  2u,
                  "%s: vdev: %d vdev not found",
                  v30,
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  "cm_roam_handle_btm_stats",
                  *a2);
              }
              if ( *(_BYTE *)(v19 + 1) == 1 )
                wlan_cm_update_roam_stats_info(a1, a2, (unsigned int)v15);
              goto LABEL_8;
            }
            cm_roam_stats_print_trigger_info(a1, &v181[188 * v15], v19, v20, *a2, v23);
            if ( *v20 == 1 )
            {
              cm_roam_stats_print_scan_info(a1, v20, *a2, *(unsigned int *)(v19 + 4), *(unsigned int *)(v19 + 16));
              memset(&s[15], 0, 0x112u);
              if ( *((unsigned __int16 *)v20 + 2) < 9u || *((unsigned __int16 *)v20 + 3) <= 0x26u )
              {
                v42 = *(_DWORD *)(v14 + 16);
                *(_DWORD *)s = 19726349;
                v43 = *(_BYTE *)(v14 + 104);
                LOBYTE(s[2]) = v42;
                HIBYTE(s[2]) = v43;
                *(_QWORD *)&s[3] = qdf_get_time_of_the_day_us();
                __isb(0xFu);
                v44 = _ReadStatusReg(CNTVCT_EL0);
                v45 = *((_WORD *)v20 + 2);
                *(_QWORD *)&s[7] = v44;
                v46 = *((unsigned __int16 *)v20 + 3);
                v47 = *((_DWORD *)v20 + 168);
                s[13] = v45;
                s[14] = v46;
                *(_DWORD *)&s[11] = v47;
                if ( (_DWORD)v46 )
                {
                  if ( (unsigned int)v46 >= 3 )
                  {
                    v78 = v46 - 1;
                    if ( (unsigned __int64)(v46 - 1) >= 0x26 )
                      v78 = 38;
                    v79 = v78 + 1;
                    v80 = v79 & 1;
                    if ( (v79 & 1) == 0 )
                      v80 = 2;
                    v81 = &s[16];
                    v48 = v79 - v80;
                    v82 = v16;
                    v83 = v48;
                    do
                    {
                      v84 = *(_DWORD *)(v82 - 2);
                      v83 -= 2;
                      v82 += 4;
                      *(_DWORD *)(v81 - 1) = v84;
                      v81 += 2;
                    }
                    while ( v83 );
                  }
                  else
                  {
                    v48 = 0;
                  }
                  while ( v48 != 38 )
                  {
                    s[v48 + 15] = *(_WORD *)&v17[2 * v48];
                    if ( v46 == ++v48 )
                      goto LABEL_71;
                  }
LABEL_140:
                  __break(0x5512u);
                }
LABEL_71:
                v188 = v23;
                if ( (_BYTE)v45 )
                {
                  v85 = v20[97];
                  v86 = v20[98];
                  v87 = *((_DWORD *)v20 + 29);
                  v88 = *((_WORD *)v20 + 52);
                  LOBYTE(s[54]) = v20[99];
                  v89 = *((_DWORD *)v20 + 27);
                  v90 = v20[148];
                  LOBYTE(s[53]) = v85;
                  v91 = v20[102];
                  v92 = v20[96];
                  HIBYTE(s[53]) = v86;
                  HIBYTE(s[54]) = v91;
                  v93 = *((_DWORD *)v20 + 31);
                  v94 = *((_DWORD *)v20 + 32);
                  *(_DWORD *)&s[57] = v87;
                  s[61] = v88;
                  *(_DWORD *)&s[55] = v93;
                  *(_DWORD *)&s[59] = v94;
                  s[62] = v89;
                  LOBYTE(s[63]) = v90;
                  HIBYTE(s[63]) = v92;
                  if ( (unsigned __int8)v45 != 1 )
                  {
                    HIBYTE(s[53]) = v86;
                    HIBYTE(s[54]) = v91;
                    *(_DWORD *)&s[66] = v93;
                    *(_QWORD *)&s[68] = __PAIR64__(v94, v87);
                    s[72] = v88;
                    s[73] = v89;
                    LOBYTE(s[74]) = v90;
                    HIBYTE(s[74]) = v92;
                    if ( (unsigned __int8)v45 != 2 )
                    {
                      HIBYTE(s[53]) = v86;
                      HIBYTE(s[54]) = v91;
                      *(_DWORD *)&s[77] = v93;
                      *(_DWORD *)&s[79] = v87;
                      *(_DWORD *)&s[81] = v94;
                      s[83] = v88;
                      s[84] = v89;
                      LOBYTE(s[85]) = v90;
                      HIBYTE(s[85]) = v92;
                      if ( (unsigned __int8)v45 != 3 )
                      {
                        HIBYTE(s[53]) = v86;
                        HIBYTE(s[54]) = v91;
                        *(_QWORD *)&s[88] = __PAIR64__(v87, v93);
                        *(_DWORD *)&s[92] = v94;
                        s[94] = v88;
                        s[95] = v89;
                        LOBYTE(s[96]) = v90;
                        HIBYTE(s[96]) = v92;
                        if ( (unsigned __int8)v45 != 4 )
                        {
                          HIBYTE(s[53]) = v86;
                          HIBYTE(s[54]) = v91;
                          *(_DWORD *)&s[99] = v93;
                          *(_DWORD *)&s[101] = v87;
                          *(_DWORD *)&s[103] = v94;
                          s[105] = v88;
                          s[106] = v89;
                          LOBYTE(s[107]) = v90;
                          HIBYTE(s[107]) = v92;
                          if ( (unsigned __int8)v45 != 5 )
                          {
                            HIBYTE(s[53]) = v86;
                            HIBYTE(s[54]) = v91;
                            *(_DWORD *)&s[110] = v93;
                            *(_QWORD *)&s[112] = __PAIR64__(v94, v87);
                            s[116] = v88;
                            s[117] = v89;
                            LOBYTE(s[118]) = v90;
                            HIBYTE(s[118]) = v92;
                            if ( (unsigned __int8)v45 != 6 )
                            {
                              HIBYTE(s[53]) = v86;
                              HIBYTE(s[54]) = v91;
                              *(_DWORD *)&s[121] = v93;
                              *(_DWORD *)&s[123] = v87;
                              *(_DWORD *)&s[125] = v94;
                              s[127] = v88;
                              s[128] = v89;
                              LOBYTE(s[129]) = v90;
                              HIBYTE(s[129]) = v92;
                              if ( (unsigned __int8)v45 != 7 )
                              {
                                HIBYTE(s[53]) = v86;
                                HIBYTE(s[54]) = v91;
                                *(_QWORD *)&s[132] = __PAIR64__(v87, v93);
                                *(_DWORD *)&s[136] = v94;
                                s[138] = v88;
                                s[139] = v89;
                                LOBYTE(s[140]) = v90;
                                HIBYTE(s[140]) = v92;
                                if ( (unsigned __int8)v45 != 8 )
                                {
                                  HIBYTE(s[53]) = v86;
                                  HIBYTE(s[54]) = v91;
                                  *(_DWORD *)&s[143] = v93;
                                  *(_DWORD *)&s[145] = v87;
                                  *(_DWORD *)&s[147] = v94;
                                  s[149] = v88;
                                  s[150] = v89;
                                  LOBYTE(s[151]) = v90;
                                  HIBYTE(s[151]) = v92;
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
              v95 = *(_DWORD *)(v19 + 4);
              if ( v95 == 5 || v95 == 3 )
              {
                v96 = *((_DWORD *)v20 + 3);
                v97 = *a2;
                memset(&s[4], 0, 24);
                *(_QWORD *)s = v96;
                wlan_cm_roam_cfg_set_value(a1, v97, 0xEu, (unsigned int *)s);
              }
            }
          }
          v98 = &v184[28 * v15];
          if ( *v98 == 1 )
          {
            cm_roam_stats_print_roam_result(a1, v19, &v184[28 * v15], &v186[680 * v15], *a2);
            *(_DWORD *)((char *)&s[20] + 1) = 0;
            *(_DWORD *)&s[19] = 0;
            v99 = *(_DWORD *)(v14 + 16);
            *(_DWORD *)s = 2949134;
            v100 = *(_BYTE *)(v14 + 104);
            LOBYTE(s[2]) = v99;
            HIBYTE(s[2]) = v100;
            *(_QWORD *)&s[3] = qdf_get_time_of_the_day_us();
            __isb(0xFu);
            v101 = _ReadStatusReg(CNTVCT_EL0);
            v102 = *(_QWORD *)(v98 + 4);
            *(_QWORD *)&s[7] = v101;
            *(_QWORD *)&s[13] = v102;
            LODWORD(v102) = *((_DWORD *)v98 + 4);
            *(_DWORD *)&s[17] = *((_DWORD *)v98 + 3);
            LOBYTE(v101) = v98[20];
            *(_DWORD *)((char *)&s[22] + 1) = v102;
            LOWORD(v102) = *(_WORD *)(v98 + 21);
            LOBYTE(s[11]) = v101;
            LOBYTE(v101) = v98[25];
            *(_WORD *)((char *)&s[11] + 1) = v102;
            HIBYTE(s[12]) = v101;
            wlan_cp_stats_cstats_write_to_buff(0, s, 49);
          }
          if ( v183[2164 * v15] )
            cm_roam_print_frame_info(a1, v14);
          wlan_cm_update_roam_stats_info(a1, a2, (unsigned int)v15);
          v111 = (__int64)&v185[32 * v15];
          if ( *(_BYTE *)v111 == 1 && *(_BYTE *)v19 == 1 )
          {
            v112 = *(_DWORD *)(v19 + 4);
            if ( v112 == 17 || v112 == 10 )
            {
              v113 = *(_DWORD *)(v111 + 20);
              v114 = *a2;
              memset(s, 0, 24);
              mlme_get_converted_timestamp(v113, (char *)s);
              v123 = jiffies;
              if ( cm_roam_stats_print_btm_rsp_info___last_ticks - jiffies + 125 < 0 )
              {
                LODWORD(v178) = *(unsigned __int8 *)(v111 + 13);
                LODWORD(v177) = *(unsigned __int8 *)(v111 + 10);
                LODWORD(v176) = *(unsigned __int8 *)(v111 + 9);
                qdf_trace_msg(
                  0x68u,
                  4u,
                  "%s [BTM RSP]:VDEV[%d], Status:%d, VSIE reason:%d, BSSID: %02x:%02x:%02x:**:**:%02x",
                  v115,
                  v116,
                  v117,
                  v118,
                  v119,
                  v120,
                  v121,
                  v122,
                  s,
                  v114,
                  *(unsigned int *)(v111 + 4),
                  *(unsigned int *)(v111 + 16),
                  *(unsigned __int8 *)(v111 + 8),
                  v176,
                  v177,
                  v178);
                cm_roam_stats_print_btm_rsp_info___last_ticks = v123;
              }
              cm_roam_btm_resp_event((_DWORD *)v19, v111, v114, 0, v115, v116, v117, v118, v119, v120, v121, v122);
            }
          }
          v124 = &v182[20 * v15];
          if ( *v124 == 1 && (v125 = jiffies, cm_roam_stats_print_roam_initial_info___last_ticks - jiffies + 125 < 0) )
          {
            qdf_trace_msg(
              0x68u,
              4u,
              "[ROAM INIT INFO]: VDEV[%d], roam_full_scan_count: %d, rssi_th: %d, cu_th: %d, fw_cancel_timer_bitmap: %d",
              v103,
              v104,
              v105,
              v106,
              v107,
              v108,
              v109,
              v110,
              *a2,
              *((unsigned int *)v124 + 1),
              *((unsigned int *)v124 + 2),
              *((unsigned int *)v124 + 3),
              *((unsigned int *)v124 + 4));
            cm_roam_stats_print_roam_initial_info___last_ticks = v125;
            v126 = *((_QWORD *)a2 + 2076);
            if ( v126 )
            {
LABEL_99:
              if ( v15 < a2[2] )
              {
                v127 = v126 + 20 * v15;
                if ( *(_BYTE *)v127 == 1 )
                {
                  if ( (unsigned int)(*(_DWORD *)(v127 + 8) - 1) <= 1 )
                  {
                    v190 = 0;
                    v191 = 0;
                    v128 = *a2;
                    *(_QWORD *)v189 = 0;
                    mlme_get_converted_timestamp(*(_DWORD *)(v127 + 4), v189);
                    v137 = jiffies;
                    if ( cm_roam_stats_process_roam_msg_info___last_ticks - jiffies + 125 < 0 )
                    {
                      qdf_trace_msg(
                        0x68u,
                        4u,
                        "%s [ROAM MSG INFO]: VDEV[%d] %s, Current rssi: %d dbm, next_rssi_threshold: %d dbm",
                        v129,
                        v130,
                        v131,
                        v132,
                        v133,
                        v134,
                        v135,
                        v136,
                        v189,
                        v128,
                        "Roam RSSI TH Reset",
                        *(unsigned int *)(v127 + 12),
                        *(unsigned int *)(v127 + 16));
                      cm_roam_stats_process_roam_msg_info___last_ticks = v137;
                    }
                    v18 = *(_DWORD *)(v127 + 16);
                    memset(&s[4], 0, 24);
                    *(_QWORD *)s = v18;
                    wlan_cm_roam_cfg_set_value(a1, v128, 0xEu, (unsigned int *)s);
                  }
                  ++v180;
                }
              }
            }
          }
          else
          {
            v126 = *((_QWORD *)a2 + 2076);
            if ( v126 )
              goto LABEL_99;
          }
          ((void (__fastcall *)(__int64, _QWORD, __int64, unsigned __int8 *, _QWORD, _QWORD, _QWORD))cm_report_roam_rt_stats)(
            a1,
            *a2,
            2,
            a2,
            0,
            (unsigned int)v15,
            0);
LABEL_8:
          v13 = (unsigned int *)a2[1];
          ++v15;
          v16 += 680;
          v17 += 680;
          if ( v15 >= (unsigned __int64)v13 )
            goto LABEL_109;
        }
      }
      LOBYTE(v180) = 0;
LABEL_109:
      wlan_objmgr_vdev_release_ref(v14, 0x4Du, v13, v5, v6, v7, v8, v9, v10, v11, v12);
      if ( !a2[1] )
      {
        if ( a2[15404] == 1 )
          cm_roam_stats_print_11kv_info(a1, a2 + 15404, *a2);
        v147 = a2 + 4;
        if ( a2[4] == 1 )
        {
          v148 = *((_DWORD *)a2 + 2);
          if ( v148 == 17 || v148 == 10 )
            cm_roam_btm_req_event((__int64)(a2 + 15404), (__int64)(a2 + 24), (__int64)(a2 + 4), *a2, v148 == 17);
        }
        if ( a2[1044] == 1 && *v147 == 1 )
          cm_roam_stats_print_scan_info(a1, a2 + 1044, *a2, *((unsigned int *)a2 + 2), *((unsigned int *)a2 + 5));
        if ( a2[16344] == 1 )
        {
          v149 = *((_DWORD *)a2 + 4091);
          v150 = *a2;
          memset(s, 0, 24);
          mlme_get_converted_timestamp(v149, (char *)s);
          v159 = jiffies;
          if ( cm_roam_stats_print_btm_rsp_info___last_ticks - jiffies + 125 < 0 )
          {
            LODWORD(v178) = a2[16357];
            LODWORD(v177) = a2[16354];
            LODWORD(v176) = a2[16353];
            qdf_trace_msg(
              0x68u,
              4u,
              "%s [BTM RSP]:VDEV[%d], Status:%d, VSIE reason:%d, BSSID: %02x:%02x:%02x:**:**:%02x",
              v151,
              v152,
              v153,
              v154,
              v155,
              v156,
              v157,
              v158,
              s,
              v150,
              *((unsigned int *)a2 + 4087),
              *((unsigned int *)a2 + 4090),
              a2[16352],
              v176,
              v177,
              v178);
            cm_roam_stats_print_btm_rsp_info___last_ticks = v159;
          }
          cm_roam_btm_resp_event(
            (_DWORD *)a2 + 1,
            (__int64)(a2 + 16344),
            v150,
            0,
            v151,
            v152,
            v153,
            v154,
            v155,
            v156,
            v157,
            v158);
        }
        if ( *v147 == 1 && *((_DWORD *)a2 + 2) == 17 )
          cm_roam_btm_resp_event((_DWORD *)a2 + 1, 0, *a2, 1, v139, v140, v141, v142, v143, v144, v145, v146);
      }
      if ( *((_QWORD *)a2 + 2076) )
      {
        v160 = a2[2];
        v138 = 0;
        if ( !a2[2] || v160 == (unsigned __int8)v180 )
          goto LABEL_138;
        if ( v160 > (unsigned __int8)v180 )
        {
          v161 = 0;
          v162 = 20LL * (unsigned __int8)v180;
          do
          {
            v164 = *((_QWORD *)a2 + 2076);
            if ( *(_BYTE *)(v164 + v162) == 1 && (unsigned int)(*(_DWORD *)(v164 + v162 + 8) - 1) <= 1 )
            {
              v190 = 0;
              v191 = 0;
              v165 = *a2;
              *(_QWORD *)v189 = 0;
              mlme_get_converted_timestamp(*(_DWORD *)(v164 + v162 + 4), v189);
              v174 = jiffies;
              if ( cm_roam_stats_process_roam_msg_info___last_ticks - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x68u,
                  4u,
                  "%s [ROAM MSG INFO]: VDEV[%d] %s, Current rssi: %d dbm, next_rssi_threshold: %d dbm",
                  v166,
                  v167,
                  v168,
                  v169,
                  v170,
                  v171,
                  v172,
                  v173,
                  v189,
                  v165,
                  "Roam RSSI TH Reset",
                  *(unsigned int *)(v164 + v162 + 12),
                  *(unsigned int *)(v164 + v162 + 16));
                cm_roam_stats_process_roam_msg_info___last_ticks = v174;
              }
              v163 = *(_DWORD *)(v164 + v162 + 16);
              memset(&s[4], 0, 24);
              *(_QWORD *)s = v163;
              wlan_cm_roam_cfg_set_value(a1, v165, 0xEu, (unsigned int *)s);
              LOBYTE(v160) = a2[2];
            }
            ++v161;
            v162 += 20;
          }
          while ( (unsigned __int8)v160 - (unsigned __int8)v180 > (unsigned __int8)v161 );
        }
      }
      v138 = 0;
    }
    else
    {
      v138 = 16;
    }
LABEL_138:
    wlan_clear_sae_auth_logs_cache(a1, *a2);
    _qdf_mem_free(*((_QWORD *)a2 + 2076));
    _qdf_mem_free((__int64)a2);
    goto LABEL_139;
  }
  v138 = 16;
LABEL_139:
  _ReadStatusReg(SP_EL0);
  return v138;
}
