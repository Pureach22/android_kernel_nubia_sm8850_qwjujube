__int64 __fastcall p2p_request_random_mac(
        __int64 a1,
        unsigned int a2,
        unsigned __int8 *a3,
        unsigned int a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v18; // x5
  __int64 v19; // x6
  __int64 v20; // x7
  int v21; // w8
  __int64 v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x24
  __int64 comp_private_obj; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  _BYTE *v41; // x25
  _BYTE *v42; // x26
  int v43; // w28
  unsigned int v44; // w27
  const char *v45; // x3
  const char *v47; // x3
  unsigned int *v48; // x8
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  unsigned int *v57; // x8
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  _QWORD *v74; // x0
  _BYTE *v75; // x26
  unsigned int *v76; // x8
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  __int64 v93; // x6
  __int64 v94; // x7
  int v95; // w8
  int v96; // w9
  unsigned int v97; // w8
  unsigned int *v98; // x8
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  const char *v115; // x2
  unsigned int v116; // w1
  _QWORD *v117; // x23
  _QWORD *v118; // x8
  _QWORD *v119; // x0
  unsigned int v120; // w23
  unsigned int *v121; // x8
  double v122; // d0
  double v123; // d1
  double v124; // d2
  double v125; // d3
  double v126; // d4
  double v127; // d5
  double v128; // d6
  double v129; // d7
  double v130; // d0
  double v131; // d1
  double v132; // d2
  double v133; // d3
  double v134; // d4
  double v135; // d5
  double v136; // d6
  double v137; // d7
  __int64 v138; // x7
  int v139; // w8
  int v140; // w9
  int v141; // w10
  __int64 v142; // x0
  __int64 v143; // x0
  __int64 v144; // x25
  __int64 v145; // x0
  double v146; // d0
  double v147; // d1
  double v148; // d2
  double v149; // d3
  double v150; // d4
  double v151; // d5
  double v152; // d6
  double v153; // d7
  __int64 v154; // x26
  __int64 v155; // x0
  double v156; // d0
  double v157; // d1
  double v158; // d2
  double v159; // d3
  double v160; // d4
  double v161; // d5
  double v162; // d6
  double v163; // d7
  unsigned int v164; // w0
  double v165; // d0
  double v166; // d1
  double v167; // d2
  double v168; // d3
  double v169; // d4
  double v170; // d5
  double v171; // d6
  double v172; // d7
  __int64 v173; // x4
  const char *v174; // x2
  double v175; // d0
  double v176; // d1
  double v177; // d2
  double v178; // d3
  double v179; // d4
  double v180; // d5
  double v181; // d6
  double v182; // d7
  unsigned int v183; // w0
  __int64 v184; // x19
  unsigned int *v185; // x8
  unsigned int v186; // w23
  double v187; // d0
  double v188; // d1
  double v189; // d2
  double v190; // d3
  double v191; // d4
  double v192; // d5
  double v193; // d6
  double v194; // d7
  __int64 v195; // x7
  int v196; // w8
  int v197; // w9
  int v198; // w10
  __int64 v199; // [xsp+0h] [xbp-20h]
  __int64 v200; // [xsp+0h] [xbp-20h]
  __int64 v201; // [xsp+8h] [xbp-18h]
  __int64 v202; // [xsp+8h] [xbp-18h]
  __int64 v203; // [xsp+10h] [xbp-10h]
  __int64 v204; // [xsp+10h] [xbp-10h]

  if ( a3 )
  {
    v18 = *a3;
    v19 = a3[1];
    v20 = a3[2];
    v21 = a3[5];
  }
  else
  {
    v20 = 0;
    v18 = 0;
    v19 = 0;
    v21 = 0;
  }
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: random_mac:vdev %d mac_addr:%02x:%02x:%02x:**:**:%02x rnd_cookie=%llu freq = %u",
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    "p2p_add_random_mac",
    a2,
    v18,
    v19,
    v20,
    v21,
    a5,
    a4);
  v22 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 15);
  if ( !v22 )
  {
    v45 = "p2p_add_random_mac";
LABEL_10:
    qdf_trace_msg(0x4Eu, 8u, "%s: vdev is null", v23, v24, v25, v26, v27, v28, v29, v30, v45);
    return 4;
  }
  v31 = v22;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v22, 5u);
  if ( !comp_private_obj )
  {
    v47 = "p2p_add_random_mac";
LABEL_12:
    qdf_trace_msg(0x4Eu, 8u, "%s: random_mac:p2p vdev object is NULL", v33, v34, v35, v36, v37, v38, v39, v40, v47);
    wlan_objmgr_vdev_release_ref(v31, 0xFu, v48, v49, v50, v51, v52, v53, v54, v55, v56);
    return 4;
  }
  v41 = (_BYTE *)comp_private_obj;
  raw_spin_lock(comp_private_obj + 24);
  v42 = v41 + 40;
  if ( v41[48] == 1 )
  {
    if ( !(unsigned int)qdf_mem_cmp(v41 + 49, a3, 6u) )
    {
      v97 = 0;
      goto LABEL_35;
    }
    v43 = 4;
    v44 = 1;
  }
  else
  {
    v44 = 0;
    v43 = 0;
  }
  if ( v41[264] == 1 )
  {
    v44 = v43;
    if ( !(unsigned int)qdf_mem_cmp(v41 + 265, a3, 6u) )
    {
      v97 = 1;
      goto LABEL_35;
    }
  }
  if ( (v41[480] & 1) != 0 )
  {
    if ( (unsigned int)qdf_mem_cmp(v41 + 481, a3, 6u) )
    {
      if ( (v41[696] & 1) != 0 )
        goto LABEL_19;
LABEL_25:
      if ( v44 == 4 )
        v44 = 3;
      goto LABEL_27;
    }
    v97 = 2;
LABEL_35:
    v117 = &v42[216 * v97 + 192];
    v118 = v117;
    do
    {
      v118 = (_QWORD *)*v118;
      if ( v118 == v117 )
        goto LABEL_39;
    }
    while ( v118[2] != a5 );
    if ( !v118 )
    {
LABEL_39:
      v119 = (_QWORD *)_qdf_mem_malloc(0x18u, "allocate_action_frame_cookie", 2260);
      if ( !v119 )
      {
        v120 = 0;
LABEL_43:
        raw_spin_unlock(v41 + 24);
        wlan_objmgr_vdev_release_ref(v31, 0xFu, v121, v122, v123, v124, v125, v126, v127, v128, v129);
        if ( a3 )
        {
          v138 = *a3;
          v139 = a3[1];
          v140 = a3[2];
          v141 = a3[5];
        }
        else
        {
          v140 = 0;
          v138 = 0;
          v139 = 0;
          v141 = 0;
        }
        LODWORD(v203) = v141;
        LODWORD(v201) = v140;
        LODWORD(v199) = v139;
        qdf_trace_msg(
          0x4Eu,
          8u,
          "%s: random_mac:append %d vdev %d freq %d %02x:%02x:%02x:**:**:%02x rnd_cookie %llu",
          v130,
          v131,
          v132,
          v133,
          v134,
          v135,
          v136,
          v137,
          "p2p_add_random_mac",
          v120,
          a2,
          a4,
          v138,
          v199,
          v201,
          v203,
          a5);
        if ( (v120 & 1) != 0 )
          return 0;
        v115 = "%s: random_mac:failed to append rnd_cookie";
        v116 = 8;
LABEL_48:
        qdf_trace_msg(0x4Eu, v116, v115, v107, v108, v109, v110, v111, v112, v113, v114, "p2p_add_random_mac");
        return 2;
      }
      v119[2] = a5;
      qdf_list_insert_front(v117, v119);
    }
    v120 = 1;
    goto LABEL_43;
  }
  if ( v44 == 4 )
    v44 = 2;
  if ( (v41[696] & 1) == 0 )
    goto LABEL_25;
LABEL_19:
  if ( !(unsigned int)qdf_mem_cmp(v41 + 697, a3, 6u) )
  {
    v97 = 3;
    goto LABEL_35;
  }
  if ( v44 == 4 )
  {
    raw_spin_unlock(v41 + 24);
    wlan_objmgr_vdev_release_ref(v31, 0xFu, v57, v58, v59, v60, v61, v62, v63, v64, v65);
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: random_mac:Reached the limit of Max random addresses",
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      "p2p_add_random_mac");
    return 1;
  }
LABEL_27:
  v74 = (_QWORD *)_qdf_mem_malloc(0x18u, "allocate_action_frame_cookie", 2260);
  if ( !v74 )
  {
    raw_spin_unlock(v41 + 24);
    wlan_objmgr_vdev_release_ref(v31, 0xFu, v98, v99, v100, v101, v102, v103, v104, v105, v106);
    v115 = "%s: random_mac:failed to alloc rnd cookie";
    v116 = 2;
    goto LABEL_48;
  }
  v74[2] = a5;
  v75 = &v42[216 * v44];
  qdf_list_insert_front((_QWORD *)v75 + 24, v74);
  qdf_mem_copy(v75 + 9, a3, 6u);
  *((_DWORD *)v75 + 4) = a4;
  v75[8] = 1;
  raw_spin_unlock(v41 + 24);
  wlan_objmgr_vdev_release_ref(v31, 0xFu, v76, v77, v78, v79, v80, v81, v82, v83, v84);
  if ( a3 )
  {
    v93 = *a3;
    v94 = a3[1];
    v95 = a3[2];
    v96 = a3[5];
  }
  else
  {
    v95 = 0;
    v93 = 0;
    v94 = 0;
    v96 = 0;
  }
  LODWORD(v201) = v96;
  LODWORD(v199) = v95;
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: random_mac:add vdev %d freq %d %02x:%02x:%02x:**:**:%02x rnd_cookie %llu",
    v85,
    v86,
    v87,
    v88,
    v89,
    v90,
    v91,
    v92,
    "p2p_add_random_mac",
    a2,
    a4,
    v93,
    v94,
    v199,
    v201,
    a5);
  v142 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 15);
  if ( !v142 )
  {
    v45 = "p2p_request_random_mac";
    goto LABEL_10;
  }
  v31 = v142;
  v143 = wlan_objmgr_vdev_get_comp_private_obj(v142, 5u);
  if ( !v143 )
  {
    v47 = "p2p_request_random_mac";
    goto LABEL_12;
  }
  v144 = v143;
  v145 = osif_request_alloc(p2p_set_rand_mac_params);
  if ( !v145 )
  {
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: Request allocation failure",
      v146,
      v147,
      v148,
      v149,
      v150,
      v151,
      v152,
      v153,
      "p2p_set_rand_mac");
    goto LABEL_61;
  }
  v154 = v145;
  v155 = osif_request_cookie(v145);
  v164 = p2p_set_mac_filter(
           a1,
           a2,
           a3,
           a4,
           1,
           (__int64)p2p_set_mac_filter_callback,
           v155,
           v156,
           v157,
           v158,
           v159,
           v160,
           v161,
           v162,
           v163);
  if ( v164 )
  {
    v173 = v164;
    v174 = "%s: random_mac:set mac filter failure %d";
LABEL_60:
    qdf_trace_msg(0x4Eu, 2u, v174, v165, v166, v167, v168, v169, v170, v171, v172, "p2p_set_rand_mac", v173);
    osif_request_put(v154);
    goto LABEL_61;
  }
  v183 = osif_request_wait_for_response(v154);
  if ( v183 )
  {
    v173 = v183;
    v174 = "%s: random_mac:timeout for set mac filter %d";
    goto LABEL_60;
  }
  v186 = *(unsigned __int8 *)osif_request_priv(v154);
  if ( a3 )
  {
    v195 = *a3;
    v196 = a3[1];
    v197 = a3[2];
    v198 = a3[5];
  }
  else
  {
    v197 = 0;
    v195 = 0;
    v196 = 0;
    v198 = 0;
  }
  LODWORD(v204) = v198;
  LODWORD(v202) = v197;
  LODWORD(v200) = v196;
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: random_mac:vdev %d freq %d result %d %02x:%02x:%02x:**:**:%02x rnd_cookie %llu",
    v187,
    v188,
    v189,
    v190,
    v191,
    v192,
    v193,
    v194,
    "p2p_set_rand_mac",
    a2,
    a4,
    v186,
    v195,
    v200,
    v202,
    v204,
    a5);
  osif_request_put(v154);
  if ( (v186 & 1) != 0 )
    goto LABEL_71;
LABEL_61:
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: random mac: failed to set rand mac address",
    v175,
    v176,
    v177,
    v178,
    v179,
    v180,
    v181,
    v182,
    "p2p_request_random_mac");
  raw_spin_lock(v144 + 24);
  if ( !(unsigned int)qdf_mem_cmp((const void *)(v144 + 49), a3, 6u) )
  {
    v184 = v144 + 40;
    goto LABEL_69;
  }
  if ( !(unsigned int)qdf_mem_cmp((const void *)(v144 + 265), a3, 6u) )
  {
    v184 = v144 + 256;
    goto LABEL_69;
  }
  if ( !(unsigned int)qdf_mem_cmp((const void *)(v144 + 481), a3, 6u) )
  {
    v184 = v144 + 472;
    goto LABEL_69;
  }
  if ( !(unsigned int)qdf_mem_cmp((const void *)(v144 + 697), a3, 6u) )
  {
    v184 = v144 + 688;
LABEL_69:
    raw_spin_unlock(v144 + 24);
    p2p_mac_clear_timeout(v184);
    raw_spin_lock(v144 + 24);
  }
  raw_spin_unlock(v144 + 24);
LABEL_71:
  wlan_objmgr_vdev_release_ref(v31, 0xFu, v185, v175, v176, v177, v178, v179, v180, v181, v182);
  return 0;
}
