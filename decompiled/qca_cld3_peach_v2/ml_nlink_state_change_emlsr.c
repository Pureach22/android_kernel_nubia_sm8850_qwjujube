__int64 __fastcall ml_nlink_state_change_emlsr(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x23
  unsigned int *v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x24
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x25
  unsigned int legacy_conn_info; // w24
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
  int _5ghz_social_ch_freq; // w0
  int _24ghz_social_ch_freq; // w0
  __int64 v70; // x8
  unsigned int v71; // w26
  unsigned int v72; // w27
  __int64 v73; // x25
  __int64 mcc_to_scc_switch_mode; // x0
  __int64 v75; // x1
  __int64 v76; // x2
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  unsigned int v85; // w24
  __int16 *v86; // x8
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  __int64 v95; // x24
  __int64 v96; // x8
  char v97; // w10
  char v98; // w11
  __int16 v99; // w9
  unsigned int updated; // w0
  unsigned int *v101; // x8
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  unsigned int v110; // w19
  __int64 result; // x0
  int v112; // w27
  unsigned int v113; // w24
  __int64 v114; // x25
  int v115; // w9
  int v116; // w26
  unsigned int v117; // w26
  unsigned int hc_id; // w0
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  const char *v127; // x2
  unsigned int v128; // w27
  unsigned int v129; // w0
  __int64 *v130; // x25
  unsigned int v131; // w28
  _QWORD *v132; // x8
  __int64 v133; // x8
  __int64 v134; // x9
  unsigned int *v135; // x8
  __int64 v136; // x28
  unsigned int *v137; // x27
  unsigned int *v138; // x28
  unsigned int v139; // t1
  __int64 v140; // x0
  unsigned int *v141; // x8
  int v142; // w24
  char *v143; // x24
  unsigned int rd_type; // w0
  double v145; // d0
  double v146; // d1
  double v147; // d2
  double v148; // d3
  double v149; // d4
  double v150; // d5
  double v151; // d6
  double v152; // d7
  char v153; // w9
  char *v154; // x25
  const char *v155; // x28
  const char *v156; // x24
  double v157; // d0
  double v158; // d1
  double v159; // d2
  double v160; // d3
  double v161; // d4
  double v162; // d5
  double v163; // d6
  double v164; // d7
  unsigned int v165; // w24
  int v166; // w25
  double v167; // d0
  double v168; // d1
  double v169; // d2
  double v170; // d3
  double v171; // d4
  double v172; // d5
  double v173; // d6
  double v174; // d7
  unsigned int v175; // w4
  char v176; // w25
  unsigned int v177; // w5
  bool v178; // cc
  __int64 v179; // [xsp+0h] [xbp-120h]
  __int64 v180; // [xsp+8h] [xbp-118h]
  __int64 v181; // [xsp+18h] [xbp-108h]
  __int64 v182; // [xsp+20h] [xbp-100h]
  __int64 v183; // [xsp+20h] [xbp-100h]
  int v184; // [xsp+28h] [xbp-F8h]
  char *v185; // [xsp+28h] [xbp-F8h]
  _QWORD v186[2]; // [xsp+30h] [xbp-F0h] BYREF
  __int16 v187; // [xsp+40h] [xbp-E0h]
  __int64 v188; // [xsp+48h] [xbp-D8h] BYREF
  __int64 v189; // [xsp+50h] [xbp-D0h]
  __int16 v190; // [xsp+58h] [xbp-C8h]
  __int64 v191; // [xsp+60h] [xbp-C0h] BYREF
  __int64 v192; // [xsp+68h] [xbp-B8h]
  __int16 v193; // [xsp+70h] [xbp-B0h]
  unsigned int v194; // [xsp+78h] [xbp-A8h] BYREF
  _BYTE v195[4]; // [xsp+7Ch] [xbp-A4h] BYREF
  __int64 v196; // [xsp+80h] [xbp-A0h] BYREF
  int v197; // [xsp+88h] [xbp-98h] BYREF
  char v198; // [xsp+8Ch] [xbp-94h]
  __int16 v199; // [xsp+90h] [xbp-90h] BYREF
  char v200; // [xsp+92h] [xbp-8Eh] BYREF
  __int16 v201; // [xsp+94h] [xbp-8Ch] BYREF
  char v202; // [xsp+96h] [xbp-8Ah]
  unsigned int v203; // [xsp+98h] [xbp-88h] BYREF
  unsigned int v204; // [xsp+9Ch] [xbp-84h] BYREF
  __int64 v205; // [xsp+A0h] [xbp-80h] BYREF
  __int64 v206; // [xsp+A8h] [xbp-78h]
  __int64 v207; // [xsp+B0h] [xbp-70h]
  __int64 v208; // [xsp+B8h] [xbp-68h]
  __int64 v209; // [xsp+C0h] [xbp-60h]
  _QWORD v210[2]; // [xsp+C8h] [xbp-58h] BYREF
  int v211; // [xsp+D8h] [xbp-48h]
  __int64 v212; // [xsp+E0h] [xbp-40h] BYREF
  __int64 v213; // [xsp+E8h] [xbp-38h]
  int v214; // [xsp+F0h] [xbp-30h]
  __int64 v215; // [xsp+F8h] [xbp-28h] BYREF
  __int64 v216; // [xsp+100h] [xbp-20h] BYREF
  int v217; // [xsp+108h] [xbp-18h]
  __int64 v218; // [xsp+110h] [xbp-10h]

  v218 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v193 = 0;
  v191 = 0;
  v192 = 0;
  v190 = 0;
  v188 = 0;
  v189 = 0;
  v187 = 0;
  v186[0] = 0;
  v186[1] = 0;
  LOBYTE(v210[0]) = 0;
  LOBYTE(v216) = 0;
  BYTE4(v212) = 0;
  LODWORD(v212) = 0;
  LODWORD(v207) = 0;
  v205 = 0;
  v206 = 0;
  policy_mgr_get_ml_sta_info_psoc(a1, v210, &v216, (__int64)&v212, (__int64)&v205, nullptr, 0, 0);
  if ( (unsigned int)LOBYTE(v210[0]) - 6 < 0xFFFFFFFB )
    goto LABEL_49;
  v6 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
         a1,
         (unsigned __int8)v212,
         90);
  if ( !v6 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: invalid vdev for id %d",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "ml_nlink_get_affect_ml_sta",
      (unsigned __int8)v212);
LABEL_49:
    result = 0;
LABEL_50:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v15 = v6;
  if ( (ml_nlink_all_links_ready_for_state_change(a1, v6, a3) & 1) == 0 )
  {
    wlan_objmgr_vdev_release_ref(v15, 0x5Au, v16, v17, v18, v19, v20, v21, v22, v23, v24);
LABEL_48:
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: exit no force state change",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "ml_nlink_state_change_emlsr");
    goto LABEL_49;
  }
  v25 = *(_QWORD *)(v15 + 1360);
  if ( v25 && *(_QWORD *)(v25 + 2224) )
  {
    qdf_mutex_acquire(v25 + 1656);
    qdf_mem_copy(v186, (const void *)(*(_QWORD *)(v25 + 2224) + 1348LL), 0x12u);
    qdf_mutex_release(v25 + 1656);
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: mlo_ctx or sta_ctx null",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "ml_nlink_get_curr_force_state");
  }
  LODWORD(v215) = 0;
  BYTE4(v210[0]) = 0;
  LODWORD(v210[0]) = 0;
  v214 = 0;
  v212 = 0;
  v213 = 0;
  BYTE4(v216) = 0;
  LODWORD(v216) = 0;
  v208 = 0;
  v209 = 0;
  v206 = 0;
  v207 = 0;
  v205 = 0;
  ml_nlink_get_link_info(
    a1,
    v15,
    0x12u,
    5u,
    &v205,
    (unsigned int *)&v212,
    (unsigned __int8 *)v210,
    &v216,
    &v197,
    (unsigned int *)&v215);
  if ( (_DWORD)v215 )
  {
    WORD1(v191) = v215;
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: AP removed link 0x%x",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "ml_nlink_handle_removal_links");
  }
  v42 = *(_QWORD *)(v15 + 216);
  v198 = 0;
  v197 = 0;
  v214 = 0;
  v212 = 0;
  v213 = 0;
  v211 = 0;
  v210[0] = 0;
  v210[1] = 0;
  legacy_conn_info = policy_mgr_get_legacy_conn_info(a1, (__int64)&v197, (__int64)&v212, (__int64)v210, 5u);
  if ( wlan_nan_is_disc_active(a1, v44, v45, v46, v47, v48, v49, v50, v51) && (unsigned __int8)legacy_conn_info <= 1u )
  {
    if ( (unsigned int)wlan_nan_get_5ghz_social_ch_freq(v42, v52, v53, v54, v55, v56, v57, v58, v59) )
    {
      _5ghz_social_ch_freq = wlan_nan_get_5ghz_social_ch_freq(v42, v60, v61, v62, v63, v64, v65, v66, v67);
      if ( (unsigned __int8)legacy_conn_info > 5u )
        goto LABEL_136;
      *((_DWORD *)&v212 + (unsigned __int8)legacy_conn_info) = _5ghz_social_ch_freq;
      *((_DWORD *)v210 + (unsigned __int8)legacy_conn_info) = 5;
      if ( (_BYTE)legacy_conn_info )
      {
        legacy_conn_info = 2;
LABEL_31:
        if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) == 0 )
          goto LABEL_37;
        if ( LODWORD(v210[0]) < 4 || LODWORD(v210[0]) == 5 )
        {
          ml_nlink_handle_legacy_intf_3_ports(a1, v15, &v188, 1, legacy_conn_info, &v197, &v212, v210);
          ml_nlink_handle_standby_link_3_ports(a1, v15, &v188, legacy_conn_info, &v212);
          goto LABEL_35;
        }
LABEL_36:
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: unexpected legacy intf mode %d",
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          "ml_nlink_handle_legacy_intf_emlsr");
LABEL_37:
        WORD1(v191) |= WORD1(v188);
        if ( (_BYTE)v189 && (unsigned __int8)v189 >= (unsigned int)(unsigned __int8)v192 )
        {
          LOBYTE(v192) = v189;
          WORD1(v192) = WORD1(v189);
        }
        ml_nlink_handle_dynamic_inactive(a1, v15, v186, &v191);
        v95 = *(_QWORD *)(v15 + 1360);
        if ( v95 && *(_QWORD *)(v95 + 2224) )
        {
          qdf_mutex_acquire(v95 + 1656);
          v96 = *(_QWORD *)(v95 + 2224);
          v97 = BYTE4(v191);
          v98 = v192;
          *(_DWORD *)(v96 + 1376) = v191;
          v99 = WORD1(v192);
          *(_DWORD *)(v96 + 1372) = a2;
          *(_BYTE *)(v96 + 1380) = v97;
          *(_BYTE *)(v96 + 1384) = v98;
          *(_WORD *)(v96 + 1386) = v99;
          qdf_mutex_release(v95 + 1656);
        }
        else
        {
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: mlo_ctx or sta_ctx null",
            v87,
            v88,
            v89,
            v90,
            v91,
            v92,
            v93,
            v94,
            "ml_nlink_update_concurrency_link_request");
        }
        ml_nlink_handle_all_link_request(a1, v15, &v191);
        updated = ml_nlink_update_force_command_target(a1, v15);
        if ( !updated )
          updated = ml_nlink_update_non_force_disallow_bitmap(a1, v15, a3, a2, 0);
        v110 = updated;
        wlan_objmgr_vdev_release_ref(v15, 0x5Au, v101, v102, v103, v104, v105, v106, v107, v108, v109);
        if ( v110 == 24 )
        {
          qdf_trace_msg(
            0x8Fu,
            8u,
            "%s: exit pending force state change",
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            "ml_nlink_state_change_emlsr");
          result = 24;
          goto LABEL_50;
        }
        if ( v110 )
        {
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: exit err %d state change",
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            "ml_nlink_state_change_emlsr",
            v110);
          result = v110;
          goto LABEL_50;
        }
        goto LABEL_48;
      }
      legacy_conn_info = 1;
    }
    if ( (unsigned int)wlan_nan_get_24ghz_social_ch_freq(v42, v60, v61, v62, v63, v64, v65, v66, v67) )
    {
      _24ghz_social_ch_freq = wlan_nan_get_24ghz_social_ch_freq(v42, v52, v53, v54, v55, v56, v57, v58, v59);
      v70 = (unsigned __int8)legacy_conn_info++;
      *((_DWORD *)&v212 + v70) = _24ghz_social_ch_freq;
      *((_DWORD *)v210 + v70) = 5;
    }
  }
  if ( !(_BYTE)legacy_conn_info )
    goto LABEL_37;
  if ( (unsigned __int8)legacy_conn_info != 1 )
    goto LABEL_31;
  if ( LODWORD(v210[0]) > 3 )
    goto LABEL_36;
  if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) == 0 )
  {
    v112 = v212;
    v113 = v210[0];
    BYTE4(v196) = 0;
    LODWORD(v215) = 0;
    BYTE2(v204) = 0;
    LOWORD(v204) = 0;
    v217 = 0;
    v216 = 0;
    BYTE2(v203) = 0;
    LOWORD(v203) = 0;
    v206 = 0;
    v207 = 0;
    v205 = 0;
    ml_nlink_get_link_info(
      a1,
      v15,
      1u,
      3u,
      &v205,
      (unsigned int *)&v216,
      (unsigned __int8 *)&v204,
      &v203,
      (_BYTE *)&v196 + 4,
      (unsigned int *)&v215);
    v114 = BYTE4(v196);
    if ( BYTE4(v196) < 2u )
      goto LABEL_35;
    if ( v113 - 2 >= 2 && v113 )
    {
      if ( v113 != 1 )
      {
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: unexpected legacy intf mode %d",
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          v83,
          v84,
          "ml_nlink_handle_comm_intf_non_dbs",
          v113);
        goto LABEL_35;
      }
      mcc_to_scc_switch_mode = policy_mgr_get_mcc_to_scc_switch_mode(a1);
      if ( (unsigned int)(v114 - 4) >= 0xFFFFFFFD )
      {
        v115 = 1 << v203;
        v184 = mcc_to_scc_switch_mode;
        if ( (_DWORD)v216 == v112 )
          v115 = 0;
        if ( HIDWORD(v216) == v112 )
          v116 = v115;
        else
          v116 = (1 << SBYTE1(v203)) | v115;
        if ( (_DWORD)v114 != 2 && v217 != v112 )
          v116 |= 1 << SBYTE2(v203);
        if ( ((unsigned int)v215 & ~v116) == 0 )
        {
          v116 = 0;
          v137 = &v203;
          v138 = &v204;
          do
          {
            v139 = *(unsigned __int8 *)v138;
            v138 = (unsigned int *)((char *)v138 + 1);
            v140 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                     a1,
                     v139,
                     90);
            if ( !v140
              || (v142 = *(_DWORD *)(v140 + 60),
                  wlan_objmgr_vdev_release_ref(v140, 0x5Au, v141, v77, v78, v79, v80, v81, v82, v83, v84),
                  (v142 & 2) != 0) )
            {
              v116 |= 1 << *(_BYTE *)v137;
            }
            --v114;
            v137 = (unsigned int *)((char *)v137 + 1);
          }
          while ( v114 );
        }
        if ( v116 && v184 != 6 )
          WORD1(v188) = v116;
        goto LABEL_35;
      }
      goto LABEL_137;
    }
LABEL_134:
    ml_nlink_handle_mcc_links(a1, v15, &v188);
    goto LABEL_35;
  }
  v71 = v212;
  v72 = (unsigned __int8)v197;
  v73 = LODWORD(v210[0]);
  v196 = 0;
  v203 = v212;
  v195[0] = 0;
  v194 = 0;
  v202 = 0;
  v201 = 0;
  v217 = 0;
  v216 = 0;
  v200 = 0;
  v199 = 0;
  v206 = 0;
  v207 = 0;
  v205 = 0;
  mcc_to_scc_switch_mode = ml_nlink_get_link_info(
                             a1,
                             v15,
                             1u,
                             3u,
                             &v205,
                             (unsigned int *)&v216,
                             (unsigned __int8 *)&v201,
                             &v199,
                             v195,
                             &v194);
  v85 = v195[0];
  if ( v195[0] < 2u )
    goto LABEL_35;
  if ( (unsigned int)v73 >= 2 )
  {
    if ( (unsigned int)(v73 - 2) > 1 )
    {
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: unexpected legacy intf mode %d",
        v77,
        v78,
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        "ml_nlink_handle_comm_intf_emlsr",
        (unsigned int)v73);
      goto LABEL_35;
    }
    mcc_to_scc_switch_mode = policy_mgr_is_vdev_high_tput_or_low_latency(a1, v72);
    if ( (mcc_to_scc_switch_mode & 1) == 0 )
    {
      v215 = 0;
      v204 = 0;
      if ( (policy_mgr_is_ml_sta_links_in_mcc(a1, (__int64)&v216, (__int64)&v201, (__int64)&v199, v85, &v204) & 1) == 0 )
        goto LABEL_35;
      v130 = (__int64 *)((char *)&v215 + 4);
      qdf_mem_set(&v215, 8u, 0);
      if ( ((v204 >> v199) & 1) != 0 )
      {
        LODWORD(v215) = v216;
        if ( ((v204 >> SHIBYTE(v199)) & 1) != 0 )
        {
          HIDWORD(v215) = HIDWORD(v216);
          goto LABEL_133;
        }
      }
      else
      {
        if ( ((v204 >> SHIBYTE(v199)) & 1) == 0 )
        {
          v153 = 0;
          v130 = &v215;
LABEL_128:
          if ( v85 == 2 )
            goto LABEL_133;
          if ( ((v204 >> v200) & 1) != 0 )
          {
            if ( v85 == 3 )
              v153 = 1;
            *(_DWORD *)v130 = v217;
            if ( (v153 & 1) != 0 )
            {
LABEL_133:
              if ( (ml_nlink_is_support_emlsr_with_freq(a1, &v215, v71) & 1) != 0 )
                goto LABEL_35;
              goto LABEL_134;
            }
          }
          else if ( v85 == 3 )
          {
            goto LABEL_133;
          }
LABEL_136:
          __break(1u);
        }
        LODWORD(v215) = HIDWORD(v216);
      }
      v153 = 1;
      goto LABEL_128;
    }
  }
  if ( (_DWORD)v216 == v71 )
  {
    v86 = &v199;
LABEL_72:
    v117 = 1 << *(_BYTE *)v86;
    goto LABEL_73;
  }
  if ( HIDWORD(v216) == v71 )
  {
    v86 = (__int16 *)((char *)&v199 + 1);
    goto LABEL_72;
  }
  if ( v85 != 2 )
  {
    if ( v217 == v71 )
    {
      v86 = (__int16 *)&v200;
      goto LABEL_72;
    }
    if ( v85 != 3 )
      goto LABEL_137;
  }
  v117 = 0;
LABEL_73:
  hc_id = get_hc_id(a1, v85, (unsigned int *)&v216);
  if ( hc_id >= 0x11 )
  {
    v127 = "%s: invalid ml_link_hc_id";
LABEL_77:
    qdf_trace_msg(0x8Fu, 8u, v127, v119, v120, v121, v122, v123, v124, v125, v126, "ml_nlink_handle_comm_intf_emlsr");
    goto LABEL_35;
  }
  v128 = hc_id;
  v129 = get_hc_id(a1, 1u, &v203);
  if ( v129 >= 0xA )
  {
    v127 = "%s: invalid non_ml_hc_id";
    goto LABEL_77;
  }
  v131 = v129;
  mcc_to_scc_switch_mode = policy_mgr_get_rd_type(a1);
  if ( (unsigned int)(v73 - 2) >= 2 && (_DWORD)v73 )
  {
    if ( (unsigned int)mcc_to_scc_switch_mode < 5 )
    {
      v132 = &sap_tbl;
LABEL_93:
      v133 = v132[(unsigned int)mcc_to_scc_switch_mode];
      if ( !v133 )
      {
        v143 = off_B32E38[v73];
        rd_type = policy_mgr_get_rd_type(a1);
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: unable to get force inactive tbl for %s rd %d",
          v145,
          v146,
          v147,
          v148,
          v149,
          v150,
          v151,
          v152,
          "ml_nlink_handle_comm_intf_emlsr",
          v143,
          rd_type);
        goto LABEL_35;
      }
      v134 = 8LL * v131;
      v135 = (unsigned int *)(v133 + 80LL * v128 + v134);
      v136 = *v135;
      v181 = v135[1];
      v182 = v134;
      hc_id_2_link_bitmap(a1, v85, &v216, &v199, (unsigned int)v136, (char *)&v196 + 4);
      hc_id_2_link_bitmap(a1, v85, &v216, &v199, (unsigned int)v181, &v196);
      v185 = off_B32E38[v73];
      v154 = off_B32E90[v128];
      v183 = *(__int64 *)((char *)off_B32F50 + v182);
      if ( (unsigned int)v136 > 0x10 )
        v155 = "Unknown";
      else
        v155 = off_B32E90[v136];
      if ( (unsigned int)v181 > 0x10 )
        v156 = "Unknown";
      else
        v156 = off_B32E90[v181];
      LODWORD(v180) = policy_mgr_get_rd_type(a1);
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: ml %s legacy %s %s inactive mcc %s inactive num %s rd %d",
        v157,
        v158,
        v159,
        v160,
        v161,
        v162,
        v163,
        v164,
        "ml_nlink_handle_comm_intf_emlsr",
        v154,
        v183,
        v185,
        v155,
        v156,
        v180);
      v165 = v196;
      v166 = HIDWORD(v196);
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: scc link 0x%x force_inactive_bitmap 0x%x force_inactive_num_bitmap 0x%x",
        v167,
        v168,
        v169,
        v170,
        v171,
        v172,
        v173,
        v174,
        "ml_nlink_handle_comm_intf_emlsr",
        v117,
        HIDWORD(v196),
        (unsigned int)v196);
      if ( v166 && (v194 & ~(v166 & ~v117)) != 0 )
        WORD1(v188) = v166 & ~(_WORD)v117;
      if ( v165 )
      {
        v175 = 0;
        v176 = 0;
        v177 = v165;
        while ( 1 )
        {
          if ( (v177 & 1) != 0 )
          {
            if ( v175 >= 0xF )
            {
              qdf_trace_msg(
                0x8Fu,
                2u,
                "%s: linkid invalid %d 0x%x",
                v77,
                v78,
                v79,
                v80,
                v81,
                v82,
                v83,
                v84,
                "convert_link_bitmap_to_link_ids");
LABEL_124:
              if ( (v176 & 0xFE) != 0 )
              {
                WORD1(v189) = v165;
                LOBYTE(v189) = v176 - 1;
              }
              else
              {
                LOBYTE(v189) = 0;
              }
              break;
            }
            ++v176;
          }
          v178 = v177 > 1;
          ++v175;
          v177 >>= 1;
          if ( !v178 )
            goto LABEL_124;
        }
      }
LABEL_35:
      LODWORD(v180) = HIWORD(v188);
      LODWORD(v179) = BYTE4(v188);
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: inactive 0x%x active 0x%x inact num %d 0x%x act num %d 0x%x dyn 0x%x",
        v77,
        v78,
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        "ml_nlink_handle_legacy_intf_emlsr",
        WORD1(v188),
        (unsigned __int16)v188,
        (unsigned __int8)v189,
        WORD1(v189),
        v179,
        v180,
        WORD2(v189));
      goto LABEL_37;
    }
  }
  else if ( (unsigned int)mcc_to_scc_switch_mode <= 4 )
  {
    v132 = &sta_p2p_tbl;
    goto LABEL_93;
  }
LABEL_137:
  __break(0x5512u);
  return ml_nlink_all_links_ready_for_state_change(mcc_to_scc_switch_mode, v75, v76);
}
