__int64 __fastcall dp_bus_bw_work_handler(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  __int64 v11; // x21
  __int64 context; // x22
  char driver_state; // w20
  unsigned int v14; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x4
  int v24; // w20
  const char *v25; // x2
  _BOOL8 v26; // x0
  __int64 v27; // x1
  int v28; // w8
  int v29; // w9
  int v30; // w8
  _DWORD *v31; // x8
  __int64 v32; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  void (*v49)(void); // x8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v51; // x9
  unsigned __int64 v52; // x9
  int v53; // w23
  unsigned __int64 v54; // x8
  __int64 v55; // x8
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  _QWORD *v64; // x8
  char v65; // w20
  __int64 v66; // x24
  __int64 v67; // x9
  __int64 v68; // x25
  unsigned __int64 v69; // x23
  __int64 vdev_by_user; // x0
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  _QWORD *v79; // x8
  __int64 v80; // x26
  int v81; // w9
  __int64 (__fastcall *v82)(__int64, __int64); // x9
  __int64 v83; // x1
  _QWORD *v84; // x20
  __int64 v85; // x0
  __int64 (__fastcall *v86)(__int64, __int64); // x9
  __int64 v87; // x1
  int v88; // w0
  __int64 v89; // x2
  _QWORD *v90; // x20
  void (__fastcall *v91)(__int64, __int64); // x9
  __int64 v92; // x1
  _QWORD *v93; // x24
  __int64 v94; // x25
  __int64 v95; // x0
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  __int64 v104; // x20
  __int64 v105; // x8
  __int64 (*v106)(void); // x8
  _DWORD *v107; // x8
  int v108; // w27
  unsigned int v109; // w13
  __int64 v110; // x0
  unsigned int v111; // w9
  __int64 v112; // x1
  __int64 v113; // x0
  __int64 v114; // x10
  __int64 v115; // x8
  __int64 v116; // x9
  __int64 (__fastcall *v117)(__int64, __int64, __int64, __int64); // x9
  __int64 v118; // x1
  __int64 v119; // x0
  __int64 v120; // x20
  int v121; // w0
  unsigned int v122; // w8
  unsigned int v123; // w27
  __int64 v124; // x20
  __int64 v125; // x20
  __int64 v126; // x8
  void (__fastcall *v127)(__int64, __int64); // x8
  __int64 v128; // x1
  _DWORD *v129; // x8
  __int64 v130; // x1
  _QWORD *v131; // x27
  __int64 v132; // x24
  unsigned int v133; // w8
  __int64 v134; // x9
  __int64 v135; // x20
  __int64 v136; // x0
  double v137; // d0
  double v138; // d1
  double v139; // d2
  double v140; // d3
  double v141; // d4
  double v142; // d5
  double v143; // d6
  double v144; // d7
  __int64 v145; // x8
  unsigned int (*v146)(void); // x8
  __int64 v147; // x27
  __int64 v148; // x28
  _QWORD *v149; // x25
  __int64 v150; // x9
  _QWORD *v151; // x0
  _QWORD *v152; // x0
  int v153; // w8
  _QWORD *v154; // x8
  __int64 v155; // x9
  _QWORD *v156; // x25
  _QWORD *v157; // x8
  __int64 v158; // x10
  __int64 v159; // x11
  __int64 v160; // x9
  __int64 v161; // x8
  __int64 v162; // x8
  __int64 v163; // x21
  __int64 v164; // x20
  __int64 v165; // x9
  __int64 v166; // x20
  __int64 v167; // [xsp+0h] [xbp-D0h]
  unsigned int v168; // [xsp+Ch] [xbp-C4h]
  __int64 v169; // [xsp+10h] [xbp-C0h]
  unsigned int v170; // [xsp+18h] [xbp-B8h]
  __int64 v171; // [xsp+20h] [xbp-B0h]
  __int64 v172; // [xsp+28h] [xbp-A8h]
  _QWORD *v173; // [xsp+30h] [xbp-A0h]
  __int64 v174; // [xsp+38h] [xbp-98h]
  __int64 v175; // [xsp+40h] [xbp-90h]
  __int64 v176; // [xsp+48h] [xbp-88h]
  __int64 v177; // [xsp+50h] [xbp-80h]
  __int64 v178; // [xsp+58h] [xbp-78h]
  __int64 v179; // [xsp+60h] [xbp-70h]
  __int64 v180; // [xsp+68h] [xbp-68h]
  __int64 v181; // [xsp+70h] [xbp-60h]
  __int64 v182; // [xsp+80h] [xbp-50h] BYREF
  __int64 v183; // [xsp+88h] [xbp-48h]
  __int64 v184; // [xsp+90h] [xbp-40h]
  __int64 v185; // [xsp+98h] [xbp-38h] BYREF
  __int64 v186; // [xsp+A0h] [xbp-30h] BYREF
  _QWORD *v187; // [xsp+A8h] [xbp-28h] BYREF
  _QWORD *v188; // [xsp+B0h] [xbp-20h] BYREF
  _QWORD v189[3]; // [xsp+B8h] [xbp-18h] BYREF

  v189[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    result = _qdf_op_protect();
    if ( !(_DWORD)result )
    {
      v11 = a1[47];
      v187 = nullptr;
      v188 = nullptr;
      v185 = 0;
      v186 = 0;
      v183 = 0;
      v184 = 0;
      v182 = 0;
      context = _cds_get_context(71, "__dp_bus_bw_work_handler");
      driver_state = cds_get_driver_state();
      v14 = cds_get_driver_state();
      v23 = v14;
      if ( (driver_state & 8) != 0 )
      {
        v25 = "%s: Recovery in progress; state:0x%x";
        goto LABEL_8;
      }
      v24 = v14 & 6;
      v23 = (unsigned int)cds_get_driver_state();
      if ( v24 )
      {
        v25 = "%s: Load/unload in progress; state:0x%x";
LABEL_8:
        qdf_trace_msg(0x45u, 5u, v25, v15, v16, v17, v18, v19, v20, v21, v22, "wlan_dp_validate_context", v23);
        goto LABEL_9;
      }
      if ( (v23 & 0x10) != 0 )
      {
        v23 = (unsigned int)cds_get_driver_state();
        v25 = "%s: Driver in bad state; state:0x%x";
        goto LABEL_8;
      }
      if ( (cds_is_fw_down() & 1) != 0 )
      {
        v23 = (unsigned int)cds_get_driver_state();
        v25 = "%s: FW is down; state:0x%x";
        goto LABEL_8;
      }
      if ( (a1[109] & 1) != 0 )
        goto LABEL_22;
      __isb(0xFu);
      StatusReg = _ReadStatusReg(CNTVCT_EL0);
      v51 = StatusReg - a1[111];
      if ( 10 * v51 >= v51 )
        v52 = 10 * v51 / 0xC0;
      else
        v52 = 10 * (v51 / 0xC0);
      if ( v52 )
      {
        v53 = *((_DWORD *)a1 + 22);
        v170 = v52;
        a1[111] = StatusReg;
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (v54 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v54 + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(v54 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(a1 + 33);
        }
        else
        {
          raw_spin_lock_bh(a1 + 33);
          a1[34] |= 1uLL;
        }
        dp_get_front_intf_no_lock(a1, &v188);
        dp_get_next_intf_no_lock(a1, v188, &v187);
        v55 = a1[34];
        if ( (v55 & 1) != 0 )
        {
          a1[34] = v55 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 33);
          v64 = v188;
          if ( !v188 )
            goto LABEL_196;
        }
        else
        {
          raw_spin_unlock(a1 + 33);
          v64 = v188;
          if ( !v188 )
            goto LABEL_196;
        }
        v65 = 0;
        v66 = 0;
        v67 = (unsigned int)(1000 * v53);
        v68 = 0;
        v171 = 0;
        v172 = 0;
        v69 = _ReadStatusReg(SP_EL0);
        v174 = 0;
        v175 = 0;
        v173 = nullptr;
        v169 = v67;
        while ( 1 )
        {
          vdev_by_user = _dp_objmgr_get_vdev_by_user(v64[458], 97, "__dp_bus_bw_work_handler");
          if ( !vdev_by_user )
            goto LABEL_174;
          v79 = v188;
          v80 = vdev_by_user;
          v81 = *((_DWORD *)v188 + 7);
          if ( (v81 | 2) == 2 )
          {
            if ( !wlan_cm_is_vdev_active(vdev_by_user, v71, v72, v73, v74, v75, v76, v77, v78) )
              goto LABEL_173;
            v79 = v188;
            v81 = *((_DWORD *)v188 + 7);
          }
          if ( (v81 | 2) != 3 )
            goto LABEL_45;
          v82 = (__int64 (__fastcall *)(__int64, __int64))a1[78];
          v83 = v79[7];
          if ( *((_DWORD *)v82 - 1) != 412937074 )
            __break(0x8229u);
          if ( (v82(v11, v83) & 1) != 0 )
          {
LABEL_45:
            if ( *((_BYTE *)a1 + 1188) == 1 )
            {
              v84 = v188;
              v85 = v188[7];
              v86 = *(__int64 (__fastcall **)(__int64, __int64))(*v188 + 488LL);
              v87 = *(unsigned int *)(*v188 + 1192LL);
              if ( *((_DWORD *)v86 - 1) != -1966193468 )
                __break(0x8229u);
              v88 = v86(v85, v87);
              if ( v88 )
              {
                if ( v88 == 11 )
                {
                  v89 = 0;
                  goto LABEL_52;
                }
              }
              else
              {
                v89 = 1;
LABEL_52:
                wlan_dp_rx_aggr_dis_req(v84, 1, v89);
              }
            }
            v90 = v188;
            v181 = v66;
            v180 = v68;
            if ( (v188[466] & 1) != 0 || (*((_BYTE *)v188 + 3729) & 1) != 0 )
            {
              if ( !*((_DWORD *)v188 + 896) )
              {
                qdf_trace_msg(
                  0x45u,
                  5u,
                  "%s: disable Rx aggregation",
                  v71,
                  v72,
                  v73,
                  v74,
                  v75,
                  v76,
                  v77,
                  v78,
                  "wlan_dp_dynamic_rx_aggregation_ctrl");
                *((_DWORD *)v90 + 896) = 1;
              }
            }
            else if ( *((_DWORD *)v188 + 896) )
            {
              qdf_trace_msg(
                0x45u,
                5u,
                "%s: enable Rx aggregation",
                v71,
                v72,
                v73,
                v74,
                v75,
                v76,
                v77,
                v78,
                "wlan_dp_dynamic_rx_aggregation_ctrl");
              *((_DWORD *)v90 + 896) = 0;
            }
            v178 = v188[362];
            v179 = v188[421];
            v176 = v188[420];
            v177 = v188[361];
            if ( *((_DWORD *)v188 + 7) || !wlan_cm_is_vdev_active(v80, v71, v72, v73, v74, v75, v76, v77, v78) )
              goto LABEL_100;
            v91 = (void (__fastcall *)(__int64, __int64))a1[70];
            v92 = v188[7];
            if ( *((_DWORD *)v91 - 1) != 1130147156 )
              __break(0x8229u);
            v91(v11, v92);
            v93 = v188;
            if ( !*((_BYTE *)v188 + 8) )
            {
LABEL_100:
              if ( !context )
                goto LABEL_114;
              goto LABEL_101;
            }
            v94 = v188[458];
            v95 = _cds_get_context(71, "dp_link_monitoring");
            v104 = v95;
            if ( v95
              && *(_QWORD *)v95
              && (v105 = *(_QWORD *)(*(_QWORD *)v95 + 64LL)) != 0
              && (v106 = *(__int64 (**)(void))(v105 + 312)) != nullptr )
            {
              if ( *((_DWORD *)v106 - 1) != 944657148 )
                __break(0x8228u);
              if ( (v106() & 1) != 0 )
                goto LABEL_100;
            }
            else
            {
              qdf_trace_msg(
                0x89u,
                8u,
                "%s: Invalid Instance:",
                v96,
                v97,
                v98,
                v99,
                v100,
                v101,
                v102,
                v103,
                "cdp_get_bus_lvl_high",
                v167);
            }
            v107 = (_DWORD *)a1[88];
            if ( !v107 )
              goto LABEL_100;
            v108 = *((unsigned __int8 *)v93 + 16);
            v109 = *((_DWORD *)v93 + 3);
            v110 = *a1;
            if ( *((_BYTE *)v93 + 16) )
            {
              v111 = v93[361] == v93[420] ? dp_link_monitoring_no_rx_times + 1 : 0;
              dp_link_monitoring_no_rx_times = v111;
              if ( v111 >= 0x32 )
              {
                v112 = *(unsigned __int8 *)(v94 + 24);
                dp_link_monitoring_no_rx_times = 0;
                if ( *(v107 - 1) != -1125204353 )
                  __break(0x8228u);
                ((void (__fastcall *)(__int64, __int64, _QWORD))v107)(v110, v112, 0);
                *((_BYTE *)v93 + 16) = 0;
                if ( !context )
                {
LABEL_114:
                  qdf_trace_msg(
                    0x89u,
                    2u,
                    "%s: Invalid SOC instance",
                    v71,
                    v72,
                    v73,
                    v74,
                    v75,
                    v76,
                    v77,
                    v78,
                    "cdp_process_ul_delay",
                    v167);
                  goto LABEL_115;
                }
LABEL_101:
                if ( !*(_QWORD *)context )
                  goto LABEL_114;
                v126 = *(_QWORD *)(*(_QWORD *)context + 32LL);
                if ( v126 )
                {
                  v127 = *(void (__fastcall **)(__int64, __int64))(v126 + 376);
                  if ( v127 )
                  {
                    v128 = *(unsigned __int8 *)(v188[458] + 24LL);
                    if ( *((_DWORD *)v127 - 1) != 261447488 )
                      __break(0x8228u);
                    v127(context, v128);
                  }
                }
LABEL_115:
                v131 = v188;
                v132 = 0;
                v133 = *((_DWORD *)v188 + 7);
                if ( v133 <= 0xB && ((1 << v133) & 0x80A) != 0 )
                {
                  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                    || (*(_DWORD *)(v69 + 16) & 0xF0000) != 0
                    || (*(_DWORD *)(v69 + 16) & 0xFF00) != 0 )
                  {
                    raw_spin_lock(v188 + 459);
                  }
                  else
                  {
                    raw_spin_lock_bh(v188 + 459);
                    v131[460] |= 1uLL;
                  }
                  dp_get_front_link_no_lock(v188, &v186);
                  dp_get_next_link_no_lock(v188, v186, &v185);
                  v134 = v188[460];
                  if ( (v134 & 1) != 0 )
                  {
                    v152 = v188 + 459;
                    v188[460] = v134 & 0xFFFFFFFFFFFFFFFELL;
                    raw_spin_unlock_bh(v152);
                    if ( v186 )
                      goto LABEL_123;
                  }
                  else
                  {
                    raw_spin_unlock(v188 + 459);
                    if ( v186 )
                    {
LABEL_123:
                      v132 = 0;
                      v135 = 0;
                      do
                      {
                        v136 = _cds_get_context(71, "__dp_bus_bw_work_handler");
                        if ( v136 && *(_QWORD *)v136 && (v145 = *(_QWORD *)(*(_QWORD *)v136 + 64LL)) != 0 )
                        {
                          v146 = *(unsigned int (**)(void))(v145 + 144);
                          if ( v146 )
                          {
                            if ( *((_DWORD *)v146 - 1) != -1253993452 )
                              __break(0x8228u);
                            if ( v146() )
                            {
                              v131 = v188;
                              goto LABEL_146;
                            }
                          }
                        }
                        else
                        {
                          qdf_trace_msg(
                            0x45u,
                            1u,
                            "%s invalid instance",
                            v137,
                            v138,
                            v139,
                            v140,
                            v141,
                            v142,
                            v143,
                            v144,
                            "cdp_get_intra_bss_fwd_pkts_count",
                            v167);
                        }
                        v148 = v183;
                        v147 = v184;
                        v149 = v188;
                        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                          || (*(_DWORD *)(v69 + 16) & 0xF0000) != 0
                          || (*(_DWORD *)(v69 + 16) & 0xFF00) != 0 )
                        {
                          raw_spin_lock(v188 + 459);
                        }
                        else
                        {
                          raw_spin_lock_bh(v149 + 459);
                          v149[460] |= 1uLL;
                        }
                        v186 = v185;
                        dp_get_next_link_no_lock(v188, v185, &v185);
                        v150 = v188[460];
                        if ( (v150 & 1) != 0 )
                        {
                          v151 = v188 + 459;
                          v188[460] = v150 & 0xFFFFFFFFFFFFFFFELL;
                          raw_spin_unlock_bh(v151);
                        }
                        else
                        {
                          raw_spin_unlock(v188 + 459);
                        }
                        v135 += v147;
                        v132 += v148;
                      }
                      while ( v186 );
                      v131 = v188;
                      v174 = v135 + v174 - v188[423];
                      v175 = v132 + v175 - v188[424];
                      goto LABEL_146;
                    }
                  }
                  v131 = v188;
                  v132 = 0;
                  v135 = 0;
                }
                else
                {
                  v135 = 0;
                }
LABEL_146:
                v153 = *((_DWORD *)v131 + 7);
                if ( v153 )
                {
                  if ( v153 == 1 )
                  {
                    v172 = v131[364];
                    v173 = v131;
                  }
                }
                else
                {
                  v171 = v131[364];
                }
                if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                  || (*(_DWORD *)(v69 + 16) & 0xF0000) != 0
                  || (*(_DWORD *)(v69 + 16) & 0xFF00) != 0 )
                {
                  raw_spin_lock(v131 + 459);
                }
                else
                {
                  raw_spin_lock_bh(v131 + 459);
                  v131[460] |= 1uLL;
                }
                dp_get_front_link_no_lock(v188, &v186);
                dp_get_next_link_no_lock(v188, v186, &v185);
                v154 = v188;
                v155 = v188[460];
                if ( (v155 & 1) != 0 )
                {
LABEL_155:
                  v154[460] = v155 & 0xFFFFFFFFFFFFFFFELL;
                  raw_spin_unlock_bh(v154 + 459);
                  goto LABEL_159;
                }
                while ( 1 )
                {
                  raw_spin_unlock(v154 + 459);
LABEL_159:
                  if ( !v186 )
                    break;
                  v156 = v188;
                  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                    || (*(_DWORD *)(v69 + 16) & 0xF0000) != 0
                    || (*(_DWORD *)(v69 + 16) & 0xFF00) != 0 )
                  {
                    raw_spin_lock(v188 + 459);
                  }
                  else
                  {
                    raw_spin_lock_bh(v156 + 459);
                    v156[460] |= 1uLL;
                  }
                  v186 = v185;
                  dp_get_next_link_no_lock(v188, v185, &v185);
                  v154 = v188;
                  v155 = v188[460];
                  if ( (v155 & 1) != 0 )
                    goto LABEL_155;
                }
                if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                  || (*(_DWORD *)(v69 + 16) & 0xF0000) != 0
                  || (*(_DWORD *)(v69 + 16) & 0xFF00) != 0 )
                {
                  raw_spin_lock(a1 + 129);
                }
                else
                {
                  raw_spin_lock_bh(a1 + 129);
                  a1[130] |= 1uLL;
                }
                v157 = v188;
                v158 = v188[361];
                v159 = v188[364];
                v160 = v188[362];
                v188[423] = v135;
                v157[420] = v158;
                v157[422] = v159;
                v157[421] = v160;
                v157[424] = v132;
                v161 = a1[130];
                v68 = v180 - v179 + v178;
                v66 = v181 - v176 + v177;
                if ( (v161 & 1) != 0 )
                {
                  a1[130] = v161 & 0xFFFFFFFFFFFFFFFELL;
                  raw_spin_unlock_bh(a1 + 129);
                }
                else
                {
                  raw_spin_unlock(a1 + 129);
                }
                v65 = 1;
                goto LABEL_173;
              }
            }
            v167 = v110;
            v168 = v109;
            v113 = _qdf_mem_malloc(0xE90u, "dp_link_monitoring", 1905);
            if ( !v113 )
              goto LABEL_100;
            v114 = v113;
            v115 = *(_QWORD *)(*(_QWORD *)(v94 + 40) + 120LL);
            if ( !v115 )
            {
              v125 = v113;
              qdf_trace_msg(
                0x45u,
                8u,
                "%s: Invalid bss peer",
                v71,
                v72,
                v73,
                v74,
                v75,
                v76,
                v77,
                v78,
                "dp_link_monitoring");
              _qdf_mem_free(v125);
              goto LABEL_100;
            }
            if ( v104 && *(_QWORD *)v104 )
            {
              v116 = *(_QWORD *)(*(_QWORD *)v104 + 32LL);
              if ( v116 )
              {
                v117 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(v116 + 144);
                if ( v117 )
                {
                  v118 = *(unsigned __int8 *)(v94 + 24);
                  v119 = v104;
                  v120 = v114;
                  if ( *((_DWORD *)v117 - 1) != -1642106733 )
                    __break(0x8229u);
                  v121 = v117(v119, v118, v115 + 48, v114);
                  v114 = v120;
                  if ( !v121 )
                  {
                    if ( !v168 )
                      goto LABEL_109;
                    v122 = *(_DWORD *)(v120 + 3452) / 0x3E8u;
                    if ( !v108 && v122 > v168 )
                    {
                      v123 = 1;
                      goto LABEL_110;
                    }
                    if ( v108 && v122 < v168 )
                    {
LABEL_109:
                      v123 = 0;
LABEL_110:
                      v129 = (_DWORD *)a1[88];
                      v130 = *(unsigned __int8 *)(v94 + 24);
                      if ( *(v129 - 1) != -1125204353 )
                        __break(0x8228u);
                      ((void (__fastcall *)(__int64, __int64, _QWORD))v129)(v167, v130, v123);
                      *((_BYTE *)v93 + 16) = v123;
                    }
                    _qdf_mem_free(v120);
                    if ( !context )
                      goto LABEL_114;
                    goto LABEL_101;
                  }
                }
              }
            }
            else
            {
              v124 = v113;
              qdf_trace_msg(
                0x89u,
                8u,
                "%s: Invalid Instance",
                v71,
                v72,
                v73,
                v74,
                v75,
                v76,
                v77,
                v78,
                "cdp_host_get_peer_stats",
                v167);
              v114 = v124;
            }
            _qdf_mem_free(v114);
            if ( !context )
              goto LABEL_114;
            goto LABEL_101;
          }
LABEL_173:
          _dp_objmgr_put_vdev_by_user(v80, 97, "__dp_bus_bw_work_handler");
LABEL_174:
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(v69 + 16) & 0xF0000) != 0
            || (*(_DWORD *)(v69 + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(a1 + 33);
          }
          else
          {
            raw_spin_lock_bh(a1 + 33);
            a1[34] |= 1uLL;
          }
          v188 = v187;
          dp_get_next_intf_no_lock(a1, v187, &v187);
          v162 = a1[34];
          if ( (v162 & 1) != 0 )
          {
            a1[34] = v162 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a1 + 33);
            v64 = v188;
            if ( !v188 )
            {
LABEL_187:
              if ( (v65 & 1) != 0 )
              {
                v163 = v174 + v68;
                v164 = v175 + v66;
                ucfg_ipa_update_tx_stats(a1[1], v171, v172);
                if ( (ucfg_ipa_is_fw_wdi_activated(*a1) & 1) != 0 )
                {
                  ucfg_ipa_uc_stat_query(a1[1], (char *)&v182 + 4, &v182);
                  v163 += HIDWORD(v182);
                  v164 += (unsigned int)v182;
                  ucfg_ipa_set_perf_level(a1[1], v163, v164);
                  ucfg_ipa_uc_stat_request(a1[1], 2);
                }
                if ( v173 )
                {
                  v165 = *(__int64 *)((char *)&qword_B44 + (_QWORD)v173 + 4) + (unsigned int)v182;
                  *(__int64 *)((char *)&qword_B50 + (_QWORD)v173) += HIDWORD(v182);
                  *(__int64 *)((char *)&qword_B44 + (_QWORD)v173 + 4) = v165;
                }
                dp_pld_request_bus_bandwidth(
                  a1,
                  v163 * v169 / (unsigned __int64)v170,
                  v164 * v169 / (unsigned __int64)v170);
                goto LABEL_22;
              }
LABEL_196:
              qdf_trace_msg(
                0x45u,
                2u,
                "%s: bus bandwidth timer running in disconnected state",
                v56,
                v57,
                v58,
                v59,
                v60,
                v61,
                v62,
                v63,
                "__dp_bus_bw_work_handler",
                v167);
LABEL_9:
              v26 = qdf_periodic_work_stop_async((__int64)(a1 + 112));
              v28 = *((_DWORD *)a1 + 25);
              v189[0] = 0x200000000LL;
              if ( v28 )
              {
                v29 = *((unsigned __int8 *)a1 + 124);
                v30 = *((unsigned __int8 *)a1 + 104);
                *((_DWORD *)a1 + 262) = 0;
                LODWORD(v189[0]) = v30;
                if ( v29 == 1 )
                {
                  v31 = (_DWORD *)a1[69];
                  v32 = *a1;
                  if ( *(v31 - 1) != 1848957961 )
                    __break(0x8228u);
                  ((void (__fastcall *)(__int64, _QWORD *, __int64))v31)(v32, v189, 1);
                }
                else if ( (unsigned int)cds_get_radio_index(v26, v27) == -22 )
                {
                  qdf_trace_msg(
                    0x45u,
                    2u,
                    "%s: Invalid radio index",
                    v33,
                    v34,
                    v35,
                    v36,
                    v37,
                    v38,
                    v39,
                    v40,
                    "wlan_dp_update_tcp_rx_param");
                }
                else
                {
                  v49 = (void (*)(void))a1[68];
                  if ( *((_DWORD *)v49 - 1) != -1162056974 )
                    __break(0x8228u);
                  v49();
                }
              }
              goto LABEL_22;
            }
          }
          else
          {
            raw_spin_unlock(a1 + 33);
            v64 = v188;
            if ( !v188 )
              goto LABEL_187;
          }
        }
      }
      v166 = jiffies;
      if ( _dp_bus_bw_work_handler___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: diff_us can't be 0 which will be used as divisor",
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          "__dp_bus_bw_work_handler");
        _dp_bus_bw_work_handler___last_ticks = v166;
      }
LABEL_22:
      result = _qdf_op_unprotect();
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x45u,
               2u,
               "%s: Unable to get DP context",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "dp_bus_bw_work_handler");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
