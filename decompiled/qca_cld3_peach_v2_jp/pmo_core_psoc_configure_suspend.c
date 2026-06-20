__int64 __fastcall pmo_core_psoc_configure_suspend(__int64 a1, char a2)
{
  __int64 comp_private_obj; // x20
  __int64 v5; // x0
  __int64 v6; // x22
  unsigned int *v7; // x8
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x0
  __int64 v17; // x22
  unsigned int *v18; // x8
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x0
  __int64 v28; // x22
  unsigned int *v29; // x8
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x0
  __int64 v39; // x22
  unsigned int *v40; // x8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x0
  __int64 v50; // x22
  unsigned int *v51; // x8
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 v60; // x0
  __int64 v61; // x22
  unsigned int *v62; // x8
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 hif_handle; // x0
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  __int64 target_info_handle; // x0
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  __int64 result; // x0
  unsigned __int64 v90; // x8
  __int64 v91; // x8
  unsigned __int64 v92; // x8
  __int64 v93; // x8
  unsigned __int64 v94; // x8
  __int64 v95; // x8
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v105; // x8
  __int64 v106; // x0
  __int64 v107; // x21
  unsigned __int64 v108; // x8
  __int64 v109; // x8
  int v110; // w22
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  int v119; // w25
  unsigned int v120; // w21
  unsigned __int64 v121; // x26
  double v122; // d0
  double v123; // d1
  double v124; // d2
  double v125; // d3
  double v126; // d4
  double v127; // d5
  double v128; // d6
  double v129; // d7
  unsigned int *v130; // x8
  unsigned int v131; // w8
  __int64 v132; // x0
  __int64 v133; // x28
  __int64 v134; // x0
  __int64 v135; // x27
  _BOOL4 v136; // w22
  unsigned __int8 *v137; // x22
  unsigned int v138; // w24
  double v139; // d0
  double v140; // d1
  double v141; // d2
  double v142; // d3
  double v143; // d4
  double v144; // d5
  double v145; // d6
  double v146; // d7
  int v147; // w27
  double v148; // d0
  double v149; // d1
  double v150; // d2
  double v151; // d3
  double v152; // d4
  double v153; // d5
  double v154; // d6
  double v155; // d7
  __int64 v156; // x8
  bool v157; // zf
  unsigned int v158; // w24
  __int64 v159; // x8
  __int64 v160; // x0
  unsigned __int8 *v161; // x22
  int v162; // w8
  unsigned int v163; // w23
  __int64 v164; // x2
  double v165; // d0
  double v166; // d1
  double v167; // d2
  double v168; // d3
  double v169; // d4
  double v170; // d5
  double v171; // d6
  double v172; // d7
  __int64 v173; // x0
  __int64 v174; // x24
  __int64 v175; // x8
  unsigned __int16 vdev_beacon_interval; // w0
  unsigned int v177; // w23
  double v178; // d0
  double v179; // d1
  double v180; // d2
  double v181; // d3
  double v182; // d4
  double v183; // d5
  double v184; // d6
  double v185; // d7
  unsigned int v186; // w8
  int v187; // w8
  int vdev_dtim_period; // w8
  double v189; // d0
  double v190; // d1
  double v191; // d2
  double v192; // d3
  double v193; // d4
  double v194; // d5
  double v195; // d6
  double v196; // d7
  __int64 v197; // [xsp+0h] [xbp-20h]
  unsigned int v198; // [xsp+Ch] [xbp-14h]
  unsigned int v199; // [xsp+10h] [xbp-10h]
  unsigned int v200; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v201; // [xsp+18h] [xbp-8h]

  v201 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  if ( (a2 & 1) != 0 )
  {
    v5 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, 0, 10);
    if ( v5 )
    {
      v6 = v5;
      pmo_register_action_frame_patterns(v5, 1);
      wlan_objmgr_vdev_release_ref(v6, 0xAu, v7, v8, v9, v10, v11, v12, v13, v14, v15);
    }
    v16 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, 1, 10);
    if ( v16 )
    {
      v17 = v16;
      pmo_register_action_frame_patterns(v16, 1);
      wlan_objmgr_vdev_release_ref(v17, 0xAu, v18, v19, v20, v21, v22, v23, v24, v25, v26);
    }
    v27 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, 2, 10);
    if ( v27 )
    {
      v28 = v27;
      pmo_register_action_frame_patterns(v27, 1);
      wlan_objmgr_vdev_release_ref(v28, 0xAu, v29, v30, v31, v32, v33, v34, v35, v36, v37);
    }
    v38 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, 3, 10);
    if ( v38 )
    {
      v39 = v38;
      pmo_register_action_frame_patterns(v38, 1);
      wlan_objmgr_vdev_release_ref(v39, 0xAu, v40, v41, v42, v43, v44, v45, v46, v47, v48);
    }
    v49 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, 4, 10);
    if ( v49 )
    {
      v50 = v49;
      pmo_register_action_frame_patterns(v49, 1);
      wlan_objmgr_vdev_release_ref(v50, 0xAu, v51, v52, v53, v54, v55, v56, v57, v58, v59);
    }
    v60 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, 5, 10);
    if ( v60 )
    {
      v61 = v60;
      pmo_register_action_frame_patterns(v60, 1);
      wlan_objmgr_vdev_release_ref(v61, 0xAu, v62, v63, v64, v65, v66, v67, v68, v69, v70);
    }
  }
  hif_handle = pmo_core_psoc_get_hif_handle(a1);
  if ( !hif_handle )
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: Invalid hif ctx",
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      "pmo_core_psoc_configure_suspend");
    result = 29;
    goto LABEL_39;
  }
  target_info_handle = hif_get_target_info_handle(hif_handle);
  if ( (a2 & 1) != 0 )
  {
    qdf_trace_msg(
      0x4Du,
      8u,
      "%s: WOW Suspend",
      v81,
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      "pmo_core_psoc_configure_suspend");
    pmo_core_apply_lphb(a1);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
      goto LABEL_25;
    goto LABEL_23;
  }
  if ( *(_DWORD *)(comp_private_obj + 52) != 2
    || *(_DWORD *)(target_info_handle + 4) != 27 && (pmo_core_is_wow_applicable(a1) & 1) == 0 )
  {
    qdf_trace_msg(
      0x4Du,
      8u,
      "%s: Non WOW PDEV Suspend",
      v81,
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      "pmo_core_psoc_configure_suspend");
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(comp_private_obj + 1040);
      v105 = *(_QWORD *)(comp_private_obj + 1048);
      *(_BYTE *)(comp_private_obj + 488) = 0;
      if ( (v105 & 1) == 0 )
      {
LABEL_44:
        raw_spin_unlock(comp_private_obj + 1040);
        goto LABEL_45;
      }
    }
    else
    {
      raw_spin_lock_bh(comp_private_obj + 1040);
      v105 = *(_QWORD *)(comp_private_obj + 1048) | 1LL;
      *(_QWORD *)(comp_private_obj + 1048) = v105;
      *(_BYTE *)(comp_private_obj + 488) = 0;
      if ( (v105 & 1) == 0 )
        goto LABEL_44;
    }
    *(_QWORD *)(comp_private_obj + 1048) = v105 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(comp_private_obj + 1040);
    goto LABEL_45;
  }
  qdf_trace_msg(0x4Du, 8u, "%s: WOW Suspend", v81, v82, v83, v84, v85, v86, v87, v88, "pmo_core_psoc_configure_suspend");
  pmo_core_apply_lphb(a1);
  pmo_core_configure_dynamic_wake_events(a1);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
  {
LABEL_25:
    raw_spin_lock(comp_private_obj + 1040);
    v91 = *(_QWORD *)(comp_private_obj + 1048);
    goto LABEL_26;
  }
LABEL_23:
  v90 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v90 + 16) & 0xF0000) != 0 || (*(_DWORD *)(v90 + 16) & 0xFF00) != 0 )
    goto LABEL_25;
  raw_spin_lock_bh(comp_private_obj + 1040);
  v91 = *(_QWORD *)(comp_private_obj + 1048) | 1LL;
  *(_QWORD *)(comp_private_obj + 1048) = v91;
LABEL_26:
  *(_BYTE *)(comp_private_obj + 488) = 1;
  if ( (v91 & 1) != 0 )
  {
    *(_QWORD *)(comp_private_obj + 1048) = v91 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(comp_private_obj + 1040);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
      goto LABEL_30;
  }
  else
  {
    raw_spin_unlock(comp_private_obj + 1040);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
      goto LABEL_30;
  }
  v92 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v92 + 16) & 0xF0000) != 0 || (*(_DWORD *)(v92 + 16) & 0xFF00) != 0 )
  {
LABEL_30:
    raw_spin_lock(comp_private_obj + 1040);
    v93 = *(_QWORD *)(comp_private_obj + 1048);
    *(_BYTE *)(comp_private_obj + 489) = 0;
    if ( (v93 & 1) == 0 )
      goto LABEL_31;
    goto LABEL_58;
  }
  raw_spin_lock_bh(comp_private_obj + 1040);
  v93 = *(_QWORD *)(comp_private_obj + 1048) | 1LL;
  *(_QWORD *)(comp_private_obj + 1048) = v93;
  *(_BYTE *)(comp_private_obj + 489) = 0;
  if ( (v93 & 1) == 0 )
  {
LABEL_31:
    raw_spin_unlock(comp_private_obj + 1040);
    if ( (a2 & 1) != 0 )
      goto LABEL_32;
LABEL_45:
    v106 = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
    if ( !v106 )
      goto LABEL_62;
    v107 = v106;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v108 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v108 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v108 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v106 + 1040);
      v109 = *(_QWORD *)(v107 + 1048);
      v110 = *(unsigned __int8 *)(v107 + 956);
      if ( (v109 & 1) == 0 )
        goto LABEL_50;
    }
    else
    {
      raw_spin_lock_bh(v106 + 1040);
      v109 = *(_QWORD *)(v107 + 1048) | 1LL;
      *(_QWORD *)(v107 + 1048) = v109;
      v110 = *(unsigned __int8 *)(v107 + 956);
      if ( (v109 & 1) == 0 )
      {
LABEL_50:
        raw_spin_unlock(v107 + 1040);
        if ( v110 )
        {
LABEL_51:
          qdf_trace_msg(
            0x4Du,
            8u,
            "%s: listen interval offload support is enabled",
            v111,
            v112,
            v113,
            v114,
            v115,
            v116,
            v117,
            v118,
            "pmo_core_set_suspend_dtim");
          v119 = 1;
LABEL_63:
          v120 = 0;
          v121 = _ReadStatusReg(SP_EL0);
          while ( 1 )
          {
            v132 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                     a1,
                     v120,
                     10);
            if ( !v132 )
              goto LABEL_67;
            v133 = v132;
            if ( !(unsigned int)wlan_vdev_is_up() )
              break;
LABEL_66:
            wlan_objmgr_vdev_release_ref(v133, 0xAu, v130, v122, v123, v124, v125, v126, v127, v128, v129);
LABEL_67:
            v131 = (unsigned __int8)v120++;
            if ( v131 >= 5 )
              goto LABEL_32;
          }
          v134 = wlan_objmgr_vdev_get_comp_private_obj(v133, 4u);
          v135 = v134;
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(v121 + 16) & 0xF0000) != 0
            || (*(_DWORD *)(v121 + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v134 + 1056);
            if ( (*(_BYTE *)(v135 + 1040) & 1) != 0 )
            {
LABEL_74:
              v136 = 1;
              goto LABEL_86;
            }
          }
          else
          {
            raw_spin_lock_bh(v134 + 1056);
            *(_QWORD *)(v135 + 1064) |= 1uLL;
            if ( (*(_BYTE *)(v135 + 1040) & 1) != 0 )
              goto LABEL_74;
          }
          v136 = *(_DWORD *)(v135 + 1044) != 0;
LABEL_86:
          v156 = *(_QWORD *)(v135 + 1064);
          if ( (v156 & 1) != 0 )
          {
            *(_QWORD *)(v135 + 1064) = v156 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v135 + 1056);
            if ( ((v119 | v136) & 1) != 0 )
              goto LABEL_65;
          }
          else
          {
            raw_spin_unlock(v135 + 1056);
            if ( ((v119 | v136) & 1) != 0 )
              goto LABEL_65;
          }
          v157 = (*(_DWORD *)(v133 + 16) & 0xFFFFFFFD) == 0;
          v200 = 1;
          if ( v157 )
          {
            v158 = *(unsigned __int8 *)(v133 + 104);
            if ( (unsigned __int8)pmo_core_get_vdev_dtim_period(v133) )
            {
              v159 = *(_QWORD *)(v133 + 152);
              if ( v159 )
                v160 = *(_QWORD *)(v159 + 80);
              else
                v160 = 0;
              v161 = *(unsigned __int8 **)v135;
              v162 = *(unsigned __int8 *)(*(_QWORD *)v135 + 25LL);
              if ( *(_BYTE *)(*(_QWORD *)v135 + 25LL) || (v162 = v161[26]) != 0 )
              {
                v163 = 0;
              }
              else if ( v161[28] && v161[29] )
              {
                vdev_beacon_interval = pmo_core_get_vdev_beacon_interval(v133);
                if ( vdev_beacon_interval < 0x64u )
                  v177 = 1;
                else
                  v177 = vdev_beacon_interval / 0x64u;
                v163 = v177 * (unsigned __int8)pmo_core_get_vdev_dtim_period(v133);
                if ( !v163 )
                {
                  qdf_trace_msg(
                    0x4Du,
                    2u,
                    "%s: Invalid dtim period",
                    v178,
                    v179,
                    v180,
                    v181,
                    v182,
                    v183,
                    v184,
                    v185,
                    "pmo_core_calculate_listen_interval");
                  qdf_trace_msg(
                    0x4Du,
                    8u,
                    "%s: Fail to calculate listen interval",
                    v189,
                    v190,
                    v191,
                    v192,
                    v193,
                    v194,
                    v195,
                    v196,
                    "pmo_core_set_vdev_suspend_dtim");
                  v164 = 1;
                  goto LABEL_99;
                }
                v186 = v161[29];
                if ( v163 > v186 )
                  v187 = 1;
                else
                  v187 = v186 / v163;
                v198 = v187;
                v199 = v161[28];
                vdev_dtim_period = (unsigned __int8)pmo_core_get_vdev_dtim_period(v133);
                if ( v198 >= v199 )
                  v162 = vdev_dtim_period * v199;
                else
                  v162 = v198 * vdev_dtim_period;
              }
              else
              {
                if ( !(unsigned int)wlan_mlme_get_listen_interval(v160, &v200) )
                {
                  v163 = 0;
                  goto LABEL_98;
                }
                qdf_trace_msg(
                  0x4Du,
                  2u,
                  "%s: Failed to get value for listen interval",
                  v122,
                  v123,
                  v124,
                  v125,
                  v126,
                  v127,
                  v128,
                  v129,
                  "pmo_core_calculate_listen_interval");
                v163 = 0;
                v162 = 1;
              }
              v200 = v162;
LABEL_98:
              LODWORD(v197) = v163;
              qdf_trace_msg(
                0x4Du,
                4u,
                "%s: sta dynamic dtim %d teles dtim %d sta mod dtim %d sta_max_li_mod_dtim %d max_dtim %d",
                v122,
                v123,
                v124,
                v125,
                v126,
                v127,
                v128,
                v129,
                "pmo_core_calculate_listen_interval",
                v161[25],
                v161[26],
                v161[28],
                v161[29],
                v197);
              v164 = v200;
LABEL_99:
              if ( (unsigned int)pmo_tgt_vdev_update_param_req(v133, 0, v164) )
                qdf_trace_msg(
                  0x4Du,
                  8u,
                  "%s: Failed to Set Listen Interval vdevId %d",
                  v165,
                  v166,
                  v167,
                  v168,
                  v169,
                  v170,
                  v171,
                  v172,
                  "pmo_core_set_vdev_suspend_dtim",
                  v158);
              qdf_trace_msg(
                0x4Du,
                8u,
                "%s: Set Listen Interval vdevId %d Listen Intv %d",
                v165,
                v166,
                v167,
                v168,
                v169,
                v170,
                v171,
                v172,
                "pmo_core_set_vdev_suspend_dtim",
                v158,
                v200);
              v173 = wlan_objmgr_vdev_get_comp_private_obj(v133, 4u);
              v174 = v173;
              if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                || (*(_DWORD *)(v121 + 16) & 0xF0000) != 0
                || (*(_DWORD *)(v121 + 16) & 0xFF00) != 0 )
              {
                raw_spin_lock(v173 + 1056);
                v175 = *(_QWORD *)(v174 + 1064);
              }
              else
              {
                raw_spin_lock_bh(v173 + 1056);
                v175 = *(_QWORD *)(v174 + 1064) | 1LL;
                *(_QWORD *)(v174 + 1064) = v175;
              }
              *(_BYTE *)(v174 + 1048) = 1;
              if ( (v175 & 1) != 0 )
              {
                *(_QWORD *)(v174 + 1064) = v175 & 0xFFFFFFFFFFFFFFFELL;
                raw_spin_unlock_bh(v174 + 1056);
              }
              else
              {
                raw_spin_unlock(v174 + 1056);
              }
            }
          }
LABEL_65:
          v130 = (unsigned int *)*(unsigned int *)(v133 + 16);
          if ( ((unsigned int)v130 & 0xFFFFFFFD) == 0 )
          {
            v137 = *(unsigned __int8 **)v135;
            v138 = *(unsigned __int8 *)(v133 + 104);
            if ( (unsigned int)pmo_tgt_send_vdev_sta_ps_param(v133, 3, *(unsigned __int8 *)(*(_QWORD *)v135 + 66LL)) )
              qdf_trace_msg(
                0x4Du,
                2u,
                "%s: Failed to Set wow inactivity timeout vdevId %d",
                v139,
                v140,
                v141,
                v142,
                v143,
                v144,
                v145,
                v146,
                "pmo_configure_vdev_suspend_params",
                v138);
            v147 = pmo_tgt_send_vdev_sta_ps_param(v133, 9, v137[67]);
            if ( v147 )
              qdf_trace_msg(
                0x4Du,
                2u,
                "%s: Failed to Set wow spec wake interval vdevId %d",
                v148,
                v149,
                v150,
                v151,
                v152,
                v153,
                v154,
                v155,
                "pmo_configure_vdev_suspend_params",
                v138);
            if ( v137[80] * (0xC8u / v137[66]) )
              v147 = pmo_tgt_send_vdev_sta_ps_param(v133, 8, v137[66]);
            if ( v147 )
              qdf_trace_msg(
                0x4Du,
                2u,
                "%s: Failed to Set ito repeat count vdevId %d",
                v148,
                v149,
                v150,
                v151,
                v152,
                v153,
                v154,
                v155,
                "pmo_configure_vdev_suspend_params",
                v138);
            qdf_trace_msg(
              0x4Du,
              8u,
              "%s: exit",
              v148,
              v149,
              v150,
              v151,
              v152,
              v153,
              v154,
              v155,
              "pmo_configure_vdev_suspend_params");
          }
          goto LABEL_66;
        }
LABEL_62:
        v119 = 0;
        goto LABEL_63;
      }
    }
    *(_QWORD *)(v107 + 1048) = v109 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v107 + 1040);
    if ( v110 )
      goto LABEL_51;
    goto LABEL_62;
  }
LABEL_58:
  *(_QWORD *)(comp_private_obj + 1048) = v93 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(comp_private_obj + 1040);
  if ( (a2 & 1) == 0 )
    goto LABEL_45;
LABEL_32:
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v94 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v94 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v94 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(comp_private_obj + 1040);
    v95 = *(_QWORD *)(comp_private_obj + 1048);
  }
  else
  {
    raw_spin_lock_bh(comp_private_obj + 1040);
    v95 = *(_QWORD *)(comp_private_obj + 1048) | 1LL;
    *(_QWORD *)(comp_private_obj + 1048) = v95;
  }
  *(_BYTE *)(comp_private_obj + 490) = 1;
  if ( (v95 & 1) != 0 )
  {
    *(_QWORD *)(comp_private_obj + 1048) = v95 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(comp_private_obj + 1040);
  }
  else
  {
    raw_spin_unlock(comp_private_obj + 1040);
  }
  pmo_tgt_psoc_update_wow_bus_suspend_state(a1, 1);
  qdf_trace_msg(0x4Du, 8u, "%s: exit", v96, v97, v98, v99, v100, v101, v102, v103, "pmo_core_psoc_configure_suspend");
  result = 0;
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return result;
}
