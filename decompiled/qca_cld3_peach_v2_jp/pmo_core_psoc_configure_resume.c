__int64 __fastcall pmo_core_psoc_configure_resume(__int64 a1, char a2)
{
  __int64 v4; // x0
  __int64 v5; // x21
  unsigned int *v6; // x8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x0
  __int64 v16; // x21
  unsigned int *v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x0
  __int64 v27; // x21
  unsigned int *v28; // x8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x0
  __int64 v38; // x21
  unsigned int *v39; // x8
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x0
  __int64 v49; // x21
  unsigned int *v50; // x8
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x0
  __int64 v60; // x21
  unsigned int *v61; // x8
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  unsigned __int64 v70; // x8
  __int64 v71; // x20
  __int64 v72; // x8
  __int64 result; // x0
  __int64 v74; // x0
  __int64 v75; // x21
  unsigned __int64 v76; // x8
  __int64 v77; // x8
  int v78; // w20
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  int v87; // w19
  __int64 v88; // x20
  unsigned int v89; // w21
  const char *v90; // x27
  const char *v91; // x23
  unsigned int v92; // w8
  __int64 v93; // x0
  __int64 v94; // x28
  __int64 v95; // x0
  __int64 v96; // x26
  _BOOL4 v97; // w24
  __int64 v98; // x8
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  int v107; // w8
  const char *v108; // x20
  const char *v109; // x23
  unsigned int v110; // w27
  __int64 v111; // x0
  __int64 v112; // x24
  __int64 v113; // x8
  int v114; // w22
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  __int64 v123; // x2
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  __int64 v132; // x0
  __int64 v133; // x27
  __int64 v134; // x8
  int v135; // w22
  unsigned int *v136; // x8
  double v137; // d0
  double v138; // d1
  double v139; // d2
  double v140; // d3
  double v141; // d4
  double v142; // d5
  double v143; // d6
  double v144; // d7
  unsigned int v145; // w24
  double v146; // d0
  double v147; // d1
  double v148; // d2
  double v149; // d3
  double v150; // d4
  double v151; // d5
  double v152; // d6
  double v153; // d7
  __int64 comp_private_obj; // [xsp+8h] [xbp-28h]
  unsigned __int64 StatusReg; // [xsp+10h] [xbp-20h]
  __int64 v156; // [xsp+18h] [xbp-18h]
  unsigned int v157; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v158; // [xsp+28h] [xbp-8h]

  v158 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  v156 = a1;
  if ( (a2 & 1) == 0 )
  {
    v74 = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
    if ( !v74 )
      goto LABEL_31;
    v75 = v74;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v76 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v76 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v76 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v74 + 1040);
      v77 = *(_QWORD *)(v75 + 1048);
      v78 = *(unsigned __int8 *)(v75 + 956);
      if ( (v77 & 1) == 0 )
        goto LABEL_25;
    }
    else
    {
      raw_spin_lock_bh(v74 + 1040);
      v77 = *(_QWORD *)(v75 + 1048) | 1LL;
      *(_QWORD *)(v75 + 1048) = v77;
      v78 = *(unsigned __int8 *)(v75 + 956);
      if ( (v77 & 1) == 0 )
      {
LABEL_25:
        raw_spin_unlock(v75 + 1040);
        if ( v78 )
        {
LABEL_26:
          qdf_trace_msg(
            0x4Du,
            8u,
            "%s: listen interval offload support is enabled",
            v79,
            v80,
            v81,
            v82,
            v83,
            v84,
            v85,
            v86,
            "pmo_core_set_resume_dtim");
          v87 = 1;
LABEL_32:
          v88 = v156;
          v89 = 0;
          v90 = "%s: enter";
          v91 = "pmo_configure_vdev_resume_params";
          StatusReg = _ReadStatusReg(SP_EL0);
          while ( 1 )
          {
            v93 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v88, v89, 10);
            if ( v93 )
              break;
LABEL_34:
            v92 = (unsigned __int8)v89++;
            if ( v92 >= 5 )
              goto LABEL_14;
          }
          v94 = v93;
          v95 = wlan_objmgr_vdev_get_comp_private_obj(v93, 4u);
          v96 = v95;
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v95 + 1056);
            if ( (*(_BYTE *)(v96 + 1040) & 1) != 0 )
            {
LABEL_40:
              v97 = 1;
              goto LABEL_43;
            }
          }
          else
          {
            raw_spin_lock_bh(v95 + 1056);
            *(_QWORD *)(v96 + 1064) |= 1uLL;
            if ( (*(_BYTE *)(v96 + 1040) & 1) != 0 )
              goto LABEL_40;
          }
          v97 = *(_DWORD *)(v96 + 1044) != 0;
LABEL_43:
          v98 = *(_QWORD *)(v96 + 1064);
          if ( (v98 & 1) != 0 )
          {
            *(_QWORD *)(v96 + 1064) = v98 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v96 + 1056);
            if ( ((v87 | v97) & 1) != 0 )
              goto LABEL_62;
          }
          else
          {
            raw_spin_unlock(v96 + 1056);
            if ( ((v87 | v97) & 1) != 0 )
            {
LABEL_62:
              v135 = *(_DWORD *)(v94 + 16);
              qdf_trace_msg(0x4Du, 8u, v90, v99, v100, v101, v102, v103, v104, v105, v106, v91);
              if ( (v135 & 0xFFFFFFFD) == 0 )
              {
                v145 = *(unsigned __int8 *)(v94 + 104);
                if ( (unsigned int)pmo_tgt_send_vdev_sta_ps_param(v94, 3, *(unsigned __int16 *)(v96 + 1020)) )
                  qdf_trace_msg(
                    0x4Du,
                    2u,
                    "%s: Failed to Set inactivity timeout vdevId %d",
                    v146,
                    v147,
                    v148,
                    v149,
                    v150,
                    v151,
                    v152,
                    v153,
                    v91,
                    v145);
                if ( (unsigned int)pmo_tgt_send_vdev_sta_ps_param(v94, 9, *(unsigned __int16 *)(v96 + 1022)) )
                  qdf_trace_msg(
                    0x4Du,
                    2u,
                    "%s: Failed to Set wow spec wake interval vdevId %d",
                    v137,
                    v138,
                    v139,
                    v140,
                    v141,
                    v142,
                    v143,
                    v144,
                    v91,
                    v145);
              }
              wlan_objmgr_vdev_release_ref(v94, 0xAu, v136, v137, v138, v139, v140, v141, v142, v143, v144);
              goto LABEL_34;
            }
          }
          v107 = *(_DWORD *)(v94 + 16);
          v108 = v91;
          v109 = v90;
          v157 = 0;
          if ( (v107 & 0xFFFFFFFD) != 0 )
            goto LABEL_61;
          v110 = *(unsigned __int8 *)(v94 + 104);
          v111 = wlan_objmgr_vdev_get_comp_private_obj(v94, 4u);
          v112 = v111;
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v111 + 1056);
            v113 = *(_QWORD *)(v112 + 1064);
            v114 = *(unsigned __int8 *)(v112 + 1048);
            if ( (v113 & 1) == 0 )
              goto LABEL_50;
          }
          else
          {
            raw_spin_lock_bh(v111 + 1056);
            v113 = *(_QWORD *)(v112 + 1064) | 1LL;
            *(_QWORD *)(v112 + 1064) = v113;
            v114 = *(unsigned __int8 *)(v112 + 1048);
            if ( (v113 & 1) == 0 )
            {
LABEL_50:
              raw_spin_unlock(v112 + 1056);
              if ( v114 )
                goto LABEL_51;
LABEL_61:
              v90 = v109;
              v91 = v108;
              v88 = v156;
              goto LABEL_62;
            }
          }
          *(_QWORD *)(v112 + 1064) = v113 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v112 + 1056);
          if ( !v114 )
            goto LABEL_61;
LABEL_51:
          if ( (unsigned int)wlan_mlme_get_listen_interval(v156, &v157) )
          {
            qdf_trace_msg(
              0x4Du,
              2u,
              "%s: Failed to get value for listen interval",
              v115,
              v116,
              v117,
              v118,
              v119,
              v120,
              v121,
              v122,
              "pmo_core_set_vdev_resume_dtim");
            v123 = 1;
            v157 = 1;
          }
          else
          {
            v123 = v157;
          }
          if ( (unsigned int)pmo_tgt_vdev_update_param_req(v94, 0, v123) )
            qdf_trace_msg(
              0x4Du,
              2u,
              "%s: Failed to Set Listen Interval vdevId %d",
              v124,
              v125,
              v126,
              v127,
              v128,
              v129,
              v130,
              v131,
              "pmo_core_set_vdev_resume_dtim",
              v110);
          qdf_trace_msg(
            0x4Du,
            8u,
            "%s: Set Listen Interval vdevId %d Listen Intv %d",
            v124,
            v125,
            v126,
            v127,
            v128,
            v129,
            v130,
            v131,
            "pmo_core_set_vdev_resume_dtim",
            v110,
            v157);
          v132 = wlan_objmgr_vdev_get_comp_private_obj(v94, 4u);
          v133 = v132;
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v132 + 1056);
            v134 = *(_QWORD *)(v133 + 1064);
            *(_BYTE *)(v133 + 1048) = 0;
            if ( (v134 & 1) == 0 )
            {
LABEL_60:
              raw_spin_unlock(v133 + 1056);
              goto LABEL_61;
            }
          }
          else
          {
            raw_spin_lock_bh(v132 + 1056);
            v134 = *(_QWORD *)(v133 + 1064) | 1LL;
            *(_QWORD *)(v133 + 1064) = v134;
            *(_BYTE *)(v133 + 1048) = 0;
            if ( (v134 & 1) == 0 )
              goto LABEL_60;
          }
          *(_QWORD *)(v133 + 1064) = v134 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v133 + 1056);
          goto LABEL_61;
        }
LABEL_31:
        v87 = 0;
        goto LABEL_32;
      }
    }
    *(_QWORD *)(v75 + 1048) = v77 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v75 + 1040);
    if ( v78 )
      goto LABEL_26;
    goto LABEL_31;
  }
  v4 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, 0, 10);
  if ( v4 )
  {
    v5 = v4;
    pmo_clear_action_frame_patterns(v4);
    wlan_objmgr_vdev_release_ref(v5, 0xAu, v6, v7, v8, v9, v10, v11, v12, v13, v14);
  }
  v15 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, 1, 10);
  if ( v15 )
  {
    v16 = v15;
    pmo_clear_action_frame_patterns(v15);
    wlan_objmgr_vdev_release_ref(v16, 0xAu, v17, v18, v19, v20, v21, v22, v23, v24, v25);
  }
  v26 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, 2, 10);
  if ( v26 )
  {
    v27 = v26;
    pmo_clear_action_frame_patterns(v26);
    wlan_objmgr_vdev_release_ref(v27, 0xAu, v28, v29, v30, v31, v32, v33, v34, v35, v36);
  }
  v37 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, 3, 10);
  if ( v37 )
  {
    v38 = v37;
    pmo_clear_action_frame_patterns(v37);
    wlan_objmgr_vdev_release_ref(v38, 0xAu, v39, v40, v41, v42, v43, v44, v45, v46, v47);
  }
  v48 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, 4, 10);
  if ( v48 )
  {
    v49 = v48;
    pmo_clear_action_frame_patterns(v48);
    wlan_objmgr_vdev_release_ref(v49, 0xAu, v50, v51, v52, v53, v54, v55, v56, v57, v58);
  }
  v59 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, 5, 10);
  if ( v59 )
  {
    v60 = v59;
    pmo_clear_action_frame_patterns(v59);
    wlan_objmgr_vdev_release_ref(v60, 0xAu, v61, v62, v63, v64, v65, v66, v67, v68, v69);
  }
LABEL_14:
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    v70 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v70 + 16) & 0xF0000) == 0 && (*(_DWORD *)(v70 + 16) & 0xFF00) == 0 )
    {
      v71 = comp_private_obj;
      raw_spin_lock_bh(comp_private_obj + 1040);
      v72 = *(_QWORD *)(comp_private_obj + 1048) | 1LL;
      *(_QWORD *)(comp_private_obj + 1048) = v72;
      *(_BYTE *)(comp_private_obj + 490) = 0;
      if ( (v72 & 1) == 0 )
        goto LABEL_18;
LABEL_28:
      *(_QWORD *)(v71 + 1048) = v72 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v71 + 1040);
      goto LABEL_19;
    }
  }
  v71 = comp_private_obj;
  raw_spin_lock(comp_private_obj + 1040);
  v72 = *(_QWORD *)(comp_private_obj + 1048);
  *(_BYTE *)(comp_private_obj + 490) = 0;
  if ( (v72 & 1) != 0 )
    goto LABEL_28;
LABEL_18:
  raw_spin_unlock(v71 + 1040);
LABEL_19:
  pmo_tgt_psoc_update_wow_bus_suspend_state(v156, 0);
  result = pmo_unpause_all_vdev(v156, v71);
  _ReadStatusReg(SP_EL0);
  return result;
}
