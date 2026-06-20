__int64 __fastcall pmo_core_is_wow_applicable(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x0
  __int64 v11; // x20
  unsigned int *v12; // x8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int is_up; // w21
  unsigned int *v22; // x8
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
  const char *v39; // x2
  unsigned int v40; // w1
  __int64 v42; // x0
  __int64 v43; // x20
  unsigned int *v44; // x8
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  int v53; // w21
  unsigned int *v54; // x8
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x0
  __int64 v64; // x20
  unsigned int *v65; // x8
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  int v74; // w21
  unsigned int *v75; // x8
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  __int64 v84; // x0
  __int64 v85; // x20
  unsigned int *v86; // x8
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  int v95; // w21
  unsigned int *v96; // x8
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  __int64 v105; // x0
  __int64 v106; // x20
  unsigned int *v107; // x8
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  int v116; // w21
  unsigned int *v117; // x8
  double v118; // d0
  double v119; // d1
  double v120; // d2
  double v121; // d3
  double v122; // d4
  double v123; // d5
  double v124; // d6
  double v125; // d7
  __int64 v126; // x0
  __int64 v127; // x20
  unsigned int *v128; // x8
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  int v137; // w21
  unsigned int *v138; // x8
  double v139; // d0
  double v140; // d1
  double v141; // d2
  double v142; // d3
  double v143; // d4
  double v144; // d5
  double v145; // d6
  double v146; // d7
  const char *v147; // x2
  unsigned int v148; // w1
  unsigned int v149; // w21
  unsigned __int64 StatusReg; // x23
  __int64 v151; // x0
  __int64 v152; // x20
  double v153; // d0
  double v154; // d1
  double v155; // d2
  double v156; // d3
  double v157; // d4
  double v158; // d5
  double v159; // d6
  double v160; // d7
  __int64 comp_private_obj; // x0
  __int64 v162; // x22
  __int64 v163; // x8
  int v164; // w24
  unsigned int *v165; // x8
  const char *v166; // x2
  unsigned int *v167; // x8
  double v168; // d0
  double v169; // d1
  double v170; // d2
  double v171; // d3
  double v172; // d4
  double v173; // d5
  double v174; // d6
  double v175; // d7

  if ( !a1 )
  {
    v39 = "%s: psoc is null";
    v40 = 2;
LABEL_7:
    qdf_trace_msg(0x4Du, v40, v39, a2, a3, a4, a5, a6, a7, a8, a9, "pmo_core_is_wow_applicable");
    return 0;
  }
  v10 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, 0, 10);
  if ( v10 )
  {
    v11 = v10;
    if ( (pmo_is_vdev_in_beaconning_mode(*(_DWORD *)(v10 + 16)) & 1) != 0 )
    {
      is_up = wlan_vdev_is_up();
      wlan_objmgr_vdev_release_ref(v11, 0xAu, v22, v23, v24, v25, v26, v27, v28, v29, v30);
      if ( !is_up )
        goto LABEL_32;
    }
    else
    {
      wlan_objmgr_vdev_release_ref(v11, 0xAu, v12, v13, v14, v15, v16, v17, v18, v19, v20);
    }
  }
  v42 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, 1, 10);
  if ( v42 )
  {
    v43 = v42;
    if ( (pmo_is_vdev_in_beaconning_mode(*(_DWORD *)(v42 + 16)) & 1) != 0 )
    {
      v53 = wlan_vdev_is_up();
      wlan_objmgr_vdev_release_ref(v43, 0xAu, v54, v55, v56, v57, v58, v59, v60, v61, v62);
      if ( !v53 )
        goto LABEL_32;
    }
    else
    {
      wlan_objmgr_vdev_release_ref(v43, 0xAu, v44, v45, v46, v47, v48, v49, v50, v51, v52);
    }
  }
  v63 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, 2, 10);
  if ( v63 )
  {
    v64 = v63;
    if ( (pmo_is_vdev_in_beaconning_mode(*(_DWORD *)(v63 + 16)) & 1) != 0 )
    {
      v74 = wlan_vdev_is_up();
      wlan_objmgr_vdev_release_ref(v64, 0xAu, v75, v76, v77, v78, v79, v80, v81, v82, v83);
      if ( !v74 )
        goto LABEL_32;
    }
    else
    {
      wlan_objmgr_vdev_release_ref(v64, 0xAu, v65, v66, v67, v68, v69, v70, v71, v72, v73);
    }
  }
  v84 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, 3, 10);
  if ( v84 )
  {
    v85 = v84;
    if ( (pmo_is_vdev_in_beaconning_mode(*(_DWORD *)(v84 + 16)) & 1) != 0 )
    {
      v95 = wlan_vdev_is_up();
      wlan_objmgr_vdev_release_ref(v85, 0xAu, v96, v97, v98, v99, v100, v101, v102, v103, v104);
      if ( !v95 )
        goto LABEL_32;
    }
    else
    {
      wlan_objmgr_vdev_release_ref(v85, 0xAu, v86, v87, v88, v89, v90, v91, v92, v93, v94);
    }
  }
  v105 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, 4, 10);
  if ( v105 )
  {
    v106 = v105;
    if ( (pmo_is_vdev_in_beaconning_mode(*(_DWORD *)(v105 + 16)) & 1) != 0 )
    {
      v116 = wlan_vdev_is_up();
      wlan_objmgr_vdev_release_ref(v106, 0xAu, v117, v118, v119, v120, v121, v122, v123, v124, v125);
      if ( !v116 )
        goto LABEL_32;
    }
    else
    {
      wlan_objmgr_vdev_release_ref(v106, 0xAu, v107, v108, v109, v110, v111, v112, v113, v114, v115);
    }
  }
  v126 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, 5, 10);
  if ( v126 )
  {
    v127 = v126;
    if ( (pmo_is_vdev_in_beaconning_mode(*(_DWORD *)(v126 + 16)) & 1) != 0 )
    {
      v137 = wlan_vdev_is_up();
      wlan_objmgr_vdev_release_ref(v127, 0xAu, v138, v139, v140, v141, v142, v143, v144, v145, v146);
      if ( !v137 )
      {
LABEL_32:
        v147 = "%s: one of vdev is in beaconning mode, enabling wow";
LABEL_36:
        v148 = 8;
LABEL_37:
        qdf_trace_msg(0x4Du, v148, v147, v31, v32, v33, v34, v35, v36, v37, v38, "pmo_core_is_wow_applicable");
        return 1;
      }
    }
    else
    {
      wlan_objmgr_vdev_release_ref(v127, 0xAu, v128, v129, v130, v131, v132, v133, v134, v135, v136);
    }
  }
  if ( (wlan_reg_is_11d_scan_inprogress(a1) & 1) != 0 )
  {
    v147 = "%s: 11d scan is in progress, enabling wow";
    goto LABEL_36;
  }
  if ( *(_BYTE *)(wlan_objmgr_psoc_get_comp_private_obj(a1, 4u) + 23) == 1 )
  {
    v147 = "%s: lpass enabled, enabling wow";
    v148 = 4;
    goto LABEL_37;
  }
  if ( (cfg_nan_get_enable(a1) & 1) != 0 )
  {
    v147 = "%s: nan enabled, enabling wow";
    goto LABEL_36;
  }
  v149 = 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v151 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v149, 10);
    if ( v151 )
      break;
LABEL_44:
    if ( ++v149 == 6 )
    {
      v39 = "%s: All vdev are in disconnected state\nand pno/extscan is not in progress, skipping wow";
      v40 = 8;
      goto LABEL_7;
    }
  }
  v152 = v151;
  if ( !(unsigned int)wlan_vdev_is_up() )
  {
    v166 = "%s: STA is connected, enabling wow";
    goto LABEL_61;
  }
  if ( (ucfg_scan_get_pno_in_progress(v152) & 1) != 0 )
  {
    v166 = "%s: NLO is in progress, enabling wow";
    goto LABEL_61;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v152, 4u);
  v162 = comp_private_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(comp_private_obj + 1056);
    v163 = *(_QWORD *)(v162 + 1064);
    v164 = *(unsigned __int8 *)(v162 + 1033);
    if ( (v163 & 1) == 0 )
      goto LABEL_52;
  }
  else
  {
    raw_spin_lock_bh(comp_private_obj + 1056);
    v163 = *(_QWORD *)(v162 + 1064) | 1LL;
    *(_QWORD *)(v162 + 1064) = v163;
    v164 = *(unsigned __int8 *)(v162 + 1033);
    if ( (v163 & 1) == 0 )
    {
LABEL_52:
      raw_spin_unlock(v162 + 1056);
      if ( v164 )
        goto LABEL_57;
      goto LABEL_53;
    }
  }
  *(_QWORD *)(v162 + 1064) = v163 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(v162 + 1056);
  if ( v164 )
  {
LABEL_57:
    v166 = "%s: P2P LO is in progress, enabling wow";
LABEL_61:
    qdf_trace_msg(0x4Du, 8u, v166, v153, v154, v155, v156, v157, v158, v159, v160, "pmo_core_is_wow_applicable");
    goto LABEL_63;
  }
LABEL_53:
  v165 = (unsigned int *)*(unsigned int *)(v152 + 16);
  if ( (_DWORD)v165 != 11 )
  {
    wlan_objmgr_vdev_release_ref(v152, 0xAu, v165, v153, v154, v155, v156, v157, v158, v159, v160);
    goto LABEL_44;
  }
  qdf_trace_msg(
    0x4Du,
    8u,
    "%s: vdev %d is in NAN data mode, enabling wow",
    v153,
    v154,
    v155,
    v156,
    v157,
    v158,
    v159,
    v160,
    "pmo_core_is_wow_applicable",
    v149);
LABEL_63:
  wlan_objmgr_vdev_release_ref(v152, 0xAu, v167, v168, v169, v170, v171, v172, v173, v174, v175);
  return 1;
}
