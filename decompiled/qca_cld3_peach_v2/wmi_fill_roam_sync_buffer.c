__int64 __fastcall wmi_fill_roam_sync_buffer(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        _QWORD *a11,
        unsigned __int16 *a12,
        unsigned int *a13)
{
  __int64 v17; // x25
  int v18; // w8
  __int64 v19; // x5
  int v20; // w9
  int v21; // w10
  int v22; // w11
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
  _DWORD *v39; // x24
  int v40; // w8
  unsigned __int16 v41; // w8
  int v42; // w9
  unsigned __int16 v43; // w8
  int v44; // w9
  __int64 v45; // x1
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 *v54; // x23
  __int64 v55; // x8
  __int64 v56; // x10
  __int64 v57; // x11
  char *v58; // x23
  void *v59; // x0
  char *v60; // x1
  _DWORD *v61; // x8
  _DWORD *v62; // x24
  unsigned __int8 v63; // w26
  unsigned int v64; // w23
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  __int64 v73; // x0
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  _DWORD *v82; // x23
  _DWORD *v83; // x23
  unsigned int v84; // w4
  size_t v85; // x2
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  unsigned int v94; // w4
  __int64 result; // x0
  unsigned __int8 sta_mlo_conn_max_num; // w0
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  unsigned int v105; // w4
  __int64 v106; // x25
  unsigned __int64 v107; // x26
  _DWORD *v108; // x27
  unsigned __int16 *v109; // x8
  int v110; // w13
  int v111; // w14
  int v112; // w11
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  int v121; // w4
  unsigned __int16 *v122; // x8
  int v123; // w5
  __int64 v124; // x11
  __int64 v125; // x12
  __int64 v126; // x13
  int v127; // w9
  int v128; // w10
  int v129; // w12
  int v130; // w13
  int v131; // w14
  int v132; // w15
  int v133; // w9
  int v134; // w10
  int v135; // w12
  unsigned int v136; // w8
  _DWORD *v137; // x21
  double v138; // d0
  double v139; // d1
  double v140; // d2
  double v141; // d3
  double v142; // d4
  double v143; // d5
  double v144; // d6
  double v145; // d7
  double v146; // d0
  double v147; // d1
  double v148; // d2
  double v149; // d3
  double v150; // d4
  double v151; // d5
  double v152; // d6
  double v153; // d7
  double v154; // d0
  double v155; // d1
  double v156; // d2
  double v157; // d3
  double v158; // d4
  double v159; // d5
  double v160; // d6
  double v161; // d7
  double v162; // d0
  double v163; // d1
  double v164; // d2
  double v165; // d3
  double v166; // d4
  double v167; // d5
  double v168; // d6
  double v169; // d7
  double v170; // d0
  double v171; // d1
  double v172; // d2
  double v173; // d3
  double v174; // d4
  double v175; // d5
  double v176; // d6
  double v177; // d7
  const char *v178; // x2
  __int64 v179; // [xsp+0h] [xbp-60h]
  __int64 v180; // [xsp+8h] [xbp-58h]
  __int64 v181; // [xsp+10h] [xbp-50h]
  __int64 v182; // [xsp+18h] [xbp-48h]
  __int64 v183; // [xsp+20h] [xbp-40h]
  __int64 v184; // [xsp+28h] [xbp-38h]
  __int64 v185; // [xsp+30h] [xbp-30h]
  __int64 v186; // [xsp+38h] [xbp-28h]
  __int64 v187; // [xsp+40h] [xbp-20h]
  char *v188; // [xsp+48h] [xbp-18h]
  __int64 v189; // [xsp+50h] [xbp-10h]
  __int64 v190; // [xsp+58h] [xbp-8h]

  v190 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  _cds_get_context(71, (__int64)"wmi_fill_roam_sync_buffer", a2, a3, a4, a5, a6, a7, a8, a9);
  v17 = *(_QWORD *)a13;
  v188 = nullptr;
  v189 = 0;
  v187 = 0;
  v18 = *(_DWORD *)(*(_QWORD *)a13 + 4LL);
  *((_BYTE *)a12 + 13) = v18;
  v19 = *(unsigned int *)(v17 + 8);
  *((_DWORD *)a12 + 14) = v19;
  v20 = *(_DWORD *)(v17 + 12);
  *((_BYTE *)a12 + 61) = v20;
  v21 = -*(unsigned __int8 *)(v17 + 16);
  *((_BYTE *)a12 + 60) = v21;
  v22 = *(_DWORD *)(v17 + 28);
  *((_BYTE *)a12 + 12) = v22;
  a12[7] = *(_DWORD *)(v17 + 20);
  *((_BYTE *)a12 + 16) = *(_WORD *)(v17 + 22);
  *((_BYTE *)a12 + 17) = *(_BYTE *)(v17 + 23);
  a12[9] = *(_DWORD *)(v17 + 24);
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: roamed_vdev_id %d auth_status %d roam_reason %d rssi %d is_beacon %d",
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    "wmi_fill_roam_sync_buffer",
    (unsigned __int8)v18,
    v19,
    (unsigned __int8)v20,
    (unsigned int)(char)v21,
    (unsigned __int8)v22);
  if ( *(_DWORD *)(v17 + 32) || *(_DWORD *)(v17 + 40) || *(_DWORD *)(v17 + 36) )
  {
    v39 = *(_DWORD **)a13;
    *a12 = 2816;
    v40 = v39[8];
    a12[1] = v40;
    qdf_mem_copy(a12 + 1408, *((const void **)a13 + 2), (unsigned __int16)v40);
    v41 = a12[1] + 2816;
    a12[2] = v41;
    v42 = v39[9];
    a12[3] = v42;
    qdf_mem_copy((char *)a12 + v41, *((const void **)a13 + 4), (unsigned __int16)v42);
    v43 = a12[1] + a12[3] + 2816;
    a12[4] = v43;
    v44 = v39[10];
    a12[5] = v44;
    qdf_mem_copy((char *)a12 + v43, *((const void **)a13 + 12), (unsigned __int16)v44);
    BYTE4(v189) = 0;
    LOBYTE(v187) = *((_BYTE *)a12 + 13);
    HIDWORD(v187) = a12[1];
    v188 = (char *)a12 + *a12;
    LODWORD(v189) = *((char *)a12 + 60);
    wlan_cm_add_all_link_probe_rsp_to_scan_db();
    v54 = *((__int64 **)a13 + 6);
    if ( v54 )
      goto LABEL_5;
LABEL_11:
    *((_DWORD *)a12 + 615) = 0;
    v58 = *((char **)a13 + 8);
    if ( v58 )
      goto LABEL_6;
    goto LABEL_12;
  }
  if ( !a11[110] )
  {
    v178 = "%s: LFR3: bcn_probe_rsp is NULL";
LABEL_64:
    qdf_trace_msg(0x31u, 2u, v178, v31, v32, v33, v34, v35, v36, v37, v38, "wmi_fill_roam_sync_buffer");
    goto LABEL_35;
  }
  if ( !a11[116] )
  {
    v178 = "%s: LFR3: reassoc_rsp is NULL";
    goto LABEL_64;
  }
  if ( !a11[114] )
  {
    v178 = "%s: LFR3: reassoc_req is NULL";
    goto LABEL_64;
  }
  wmi_fill_data_synch_frame_event(a11, a12);
  v54 = *((__int64 **)a13 + 6);
  if ( !v54 )
    goto LABEL_11;
LABEL_5:
  *((_DWORD *)a12 + 16) = *((_DWORD *)v54 + 1);
  *((_DWORD *)a12 + 615) = wlan_cm_fw_to_host_phymode(v54[2] & 0x3F, v45);
  v55 = *v54;
  v56 = v54[1];
  v57 = v54[2];
  *((_DWORD *)a12 + 622) = *((_DWORD *)v54 + 6);
  *((_QWORD *)a12 + 308) = v55;
  *((_QWORD *)a12 + 310) = v57;
  *((_QWORD *)a12 + 309) = v56;
  v58 = *((char **)a13 + 8);
  if ( v58 )
  {
LABEL_6:
    *((_BYTE *)a12 + 100) = 16;
    qdf_mem_copy(a12 + 34, v58 + 4, 0x10u);
    *((_DWORD *)a12 + 26) = 16;
    qdf_mem_copy(a12 + 54, v58 + 20, 0x10u);
    v59 = a12 + 130;
    v60 = v58 + 36;
    goto LABEL_22;
  }
LABEL_12:
  v61 = *((_DWORD **)a13 + 20);
  if ( !v61 )
    goto LABEL_23;
  v62 = v61 + 1;
  if ( v61[27] )
    v63 = v61[27];
  else
    v63 = 24;
  if ( v61[28] )
    v64 = (unsigned __int8)v61[28];
  else
    v64 = 32;
  *((_BYTE *)a12 + 100) = v63;
  qdf_mem_copy(a12 + 34, v61 + 1, v63);
  *((_DWORD *)a12 + 26) = v64;
  if ( v63 > 0x68u )
    goto LABEL_65;
  qdf_mem_copy(a12 + 54, (char *)v62 + v63, v64);
  if ( v64 > 0x68 )
    goto LABEL_65;
  v59 = a12 + 130;
  v60 = (char *)v62 + v64 + v63;
LABEL_22:
  qdf_mem_copy(v59, v60, 8u);
LABEL_23:
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: ROAM_SYNC kek_len %d kck_len %d",
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    "wmi_fill_roam_sync_buffer",
    *((unsigned int *)a12 + 26),
    *((unsigned __int8 *)a12 + 100));
  v73 = *((_QWORD *)a13 + 14);
  if ( v73 )
  {
    wmi_extract_pdev_hw_mode_trans_ind(v73, *((_QWORD *)a13 + 16), a13[58], *((_QWORD *)a13 + 28), a12 + 154);
    *((_BYTE *)a12 + 306) = 1;
    v82 = *((_DWORD **)a13 + 18);
    if ( !v82 )
      goto LABEL_25;
LABEL_28:
    v84 = v82[3];
    if ( v84 > 0x40 || v82[20] >= 0x41u )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Invalid kek_len %d or pmk_len %d",
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        v80,
        v81,
        "wmi_fill_roam_sync_buffer");
      goto LABEL_35;
    }
    *((_DWORD *)a12 + 26) = v84;
    qdf_mem_copy(a12 + 54, v82 + 4, (unsigned int)v82[3]);
    v85 = (unsigned int)v82[20];
    *((_DWORD *)a12 + 43) = v85;
    qdf_mem_copy(a12 + 88, v82 + 21, v85);
    qdf_mem_copy(a12 + 120, v82 + 37, 0x10u);
    *((_BYTE *)a12 + 256) = v82[1] != 0;
    a12[129] = v82[2];
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Update ERP Seq Num %d, Next ERP Seq Num %d KEK len %d",
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      "wmi_fill_roam_sync_buffer");
    v83 = *((_DWORD **)a13 + 22);
    if ( !v83 )
      goto LABEL_37;
LABEL_31:
    v94 = v83[1];
    if ( !v94 )
      goto LABEL_37;
    if ( v94 < 0x41 )
    {
      *((_DWORD *)a12 + 43) = v94;
      qdf_mem_copy(a12 + 88, v83 + 2, (unsigned int)v83[1]);
      qdf_mem_copy(a12 + 120, v83 + 18, 0x10u);
      goto LABEL_37;
    }
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid pmk_len %d",
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      "wmi_fill_roam_sync_buffer");
LABEL_35:
    wlan_cm_free_roam_synch_frame_ind((__int64)a11);
    result = 16;
    goto LABEL_60;
  }
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: hw_mode transition fixed param is NULL",
    v65,
    v66,
    v67,
    v68,
    v69,
    v70,
    v71,
    v72,
    "wmi_fill_roam_sync_buffer");
  v82 = *((_DWORD **)a13 + 18);
  if ( v82 )
    goto LABEL_28;
LABEL_25:
  v83 = *((_DWORD **)a13 + 22);
  if ( v83 )
    goto LABEL_31;
LABEL_37:
  sta_mlo_conn_max_num = wlan_mlme_get_sta_mlo_conn_max_num(**(_QWORD **)(a1 + 760));
  v105 = a13[50];
  if ( !v105 )
  {
LABEL_51:
    v136 = a13[54];
    if ( !v136 )
      goto LABEL_58;
    if ( v136 >= 4 )
    {
      LOBYTE(v136) = 3;
      a13[54] = 3;
    }
    *((_BYTE *)a12 + 2656) = v136;
    v137 = *((_DWORD **)a13 + 26);
    *((_DWORD *)a12 + 665) = v137[1];
    *((_DWORD *)a12 + 666) = v137[2];
    *((_DWORD *)a12 + 667) = v137[3];
    qdf_mem_copy(a12 + 1336, v137 + 4, 8u);
    qdf_mem_copy(a12 + 1340, v137 + 6, 0x20u);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: link_id: %u key_idx: %u key_cipher: %u",
      v138,
      v139,
      v140,
      v141,
      v142,
      v143,
      v144,
      v145,
      "wmi_fill_roam_mlo_info",
      *((unsigned int *)a12 + 665),
      *((unsigned int *)a12 + 666),
      *((unsigned int *)a12 + 667));
    if ( *((unsigned __int8 *)a12 + 2656) < 2u )
      goto LABEL_58;
    *((_DWORD *)a12 + 678) = v137[19];
    *((_DWORD *)a12 + 679) = v137[20];
    *((_DWORD *)a12 + 680) = v137[21];
    qdf_mem_copy(a12 + 1362, v137 + 22, 8u);
    qdf_mem_copy(a12 + 1366, v137 + 24, 0x20u);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: link_id: %u key_idx: %u key_cipher: %u",
      v146,
      v147,
      v148,
      v149,
      v150,
      v151,
      v152,
      v153,
      "wmi_fill_roam_mlo_info",
      *((unsigned int *)a12 + 678),
      *((unsigned int *)a12 + 679),
      *((unsigned int *)a12 + 680));
    if ( *((unsigned __int8 *)a12 + 2656) < 3u )
      goto LABEL_58;
    *((_DWORD *)a12 + 691) = v137[37];
    *((_DWORD *)a12 + 692) = v137[38];
    *((_DWORD *)a12 + 693) = v137[39];
    qdf_mem_copy(a12 + 1388, v137 + 40, 8u);
    qdf_mem_copy(a12 + 1392, v137 + 42, 0x20u);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: link_id: %u key_idx: %u key_cipher: %u",
      v154,
      v155,
      v156,
      v157,
      v158,
      v159,
      v160,
      v161,
      "wmi_fill_roam_mlo_info",
      *((unsigned int *)a12 + 691),
      *((unsigned int *)a12 + 692),
      *((unsigned int *)a12 + 693));
    if ( *((unsigned __int8 *)a12 + 2656) < 4u
      || (*((_DWORD *)a12 + 704) = v137[55],
          *((_DWORD *)a12 + 705) = v137[56],
          *((_DWORD *)a12 + 706) = v137[57],
          qdf_mem_copy(a12 + 1414, v137 + 58, 8u),
          qdf_mem_copy(a12 + 1418, v137 + 60, 0x20u),
          qdf_trace_msg(
            0x31u,
            8u,
            "%s: link_id: %u key_idx: %u key_cipher: %u",
            v162,
            v163,
            v164,
            v165,
            v166,
            v167,
            v168,
            v169,
            "wmi_fill_roam_mlo_info",
            *((unsigned int *)a12 + 704),
            *((unsigned int *)a12 + 705),
            *((unsigned int *)a12 + 706)),
          *((unsigned __int8 *)a12 + 2656) <= 4u) )
    {
LABEL_58:
      wlan_cm_free_roam_synch_frame_ind((__int64)a11);
      result = 0;
      goto LABEL_60;
    }
LABEL_65:
    __break(0x5512u);
  }
  if ( v105 <= sta_mlo_conn_max_num && v105 <= 3 )
  {
    *((_BYTE *)a12 + 2497) = v105;
    v106 = 0;
    v107 = 0;
    v108 = (_DWORD *)(*((_QWORD *)a13 + 24) + 56LL);
    while ( 1 )
    {
      if ( v106 == 104 )
        goto LABEL_65;
      v121 = *(v108 - 12);
      v122 = &a12[v106];
      *((_DWORD *)v122 + 625) = 255;
      *((_DWORD *)v122 + 626) = v121;
      if ( *(v108 - 13) == -1 )
        v123 = 255;
      else
        v123 = *(v108 - 13);
      *((_DWORD *)v122 + 625) = v123;
      v124 = *(_QWORD *)(v108 - 7);
      v125 = *(_QWORD *)(v108 - 11);
      v126 = *(_QWORD *)(v108 - 9);
      *((_DWORD *)v122 + 633) = *(v108 - 5);
      *(_QWORD *)&a12[v106 + 1258] = v126;
      *(_QWORD *)&a12[v106 + 1262] = v124;
      *(_QWORD *)&a12[v106 + 1254] = v125;
      *((_DWORD *)v122 + 634) = *(v108 - 4);
      *((_BYTE *)v122 + 2540) = *(v108 - 3);
      v127 = *(v108 - 3);
      *((_BYTE *)v122 + 2541) = BYTE1(v127);
      v128 = *(v108 - 3);
      *((_BYTE *)v122 + 2542) = BYTE2(v128);
      *((_BYTE *)v122 + 2543) = *((_BYTE *)v108 - 9);
      *((_BYTE *)v122 + 2544) = *(v108 - 2);
      v129 = *(v108 - 2);
      *((_BYTE *)v122 + 2545) = BYTE1(v129);
      v112 = *(v108 - 1);
      *((_BYTE *)v122 + 2546) = v112;
      v130 = *(v108 - 1);
      *((_BYTE *)v122 + 2547) = BYTE1(v130);
      v131 = *(v108 - 1);
      *((_BYTE *)v122 + 2548) = BYTE2(v131);
      *((_BYTE *)v122 + 2549) = *((_BYTE *)v108 - 1);
      *((_BYTE *)v122 + 2550) = *v108;
      v132 = *v108;
      *((_BYTE *)v122 + 2551) = BYTE1(*v108);
      if ( v122 == (unsigned __int16 *)-2540LL )
      {
        v134 = 0;
        v133 = 0;
        v135 = 0;
      }
      else
      {
        v133 = BYTE1(v127);
        v134 = BYTE2(v128);
        v135 = BYTE1(v129);
        v109 = v122 + 1273;
        if ( !v109 )
        {
          v110 = 0;
          v112 = 0;
          v111 = 0;
          goto LABEL_42;
        }
      }
      LODWORD(v109) = BYTE1(v130);
      v110 = BYTE2(v131);
      v111 = BYTE1(v132);
      v112 = (unsigned __int8)v112;
LABEL_42:
      LODWORD(v185) = v111;
      LODWORD(v184) = v110;
      LODWORD(v183) = (_DWORD)v109;
      LODWORD(v182) = v112;
      LODWORD(v181) = v135;
      LODWORD(v180) = v134;
      LODWORD(v179) = v133;
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: link_id: %u vdev_id: %u flags: 0x%x addr: %02x:%02x:%02x:**:**:%02x self_addr:%02x:%02x:%02x:**:**:%02x",
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        "wmi_fill_roam_mlo_info",
        v179,
        v180,
        v181,
        v182,
        v183,
        v184,
        v185,
        v186,
        v187,
        v188,
        v189,
        v190);
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: channel: %u mhz center_freq1: %u center_freq2: %u",
        v113,
        v114,
        v115,
        v116,
        v117,
        v118,
        v119,
        v120,
        "wmi_fill_roam_mlo_info",
        *(unsigned int *)&a12[v106 + 1256],
        *(unsigned int *)&a12[v106 + 1258],
        *(unsigned int *)&a12[v106 + 1260]);
      ++v107;
      v108 += 15;
      v106 += 26;
      if ( v107 >= *((unsigned __int8 *)a12 + 2497) )
        goto LABEL_51;
    }
  }
  qdf_trace_msg(
    0x31u,
    2u,
    "%s: Number of links %d exceeded max vdev supported %d",
    v97,
    v98,
    v99,
    v100,
    v101,
    v102,
    v103,
    v104,
    "wmi_fill_roam_mlo_info");
  qdf_trace_msg(
    0x31u,
    2u,
    "%s: Failed to fill roam mlo info",
    v170,
    v171,
    v172,
    v173,
    v174,
    v175,
    v176,
    v177,
    "wmi_fill_roam_sync_buffer");
  result = 4;
LABEL_60:
  _ReadStatusReg(SP_EL0);
  return result;
}
