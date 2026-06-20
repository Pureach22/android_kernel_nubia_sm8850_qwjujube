__int64 __fastcall wlan_cm_update_roam_stats_info(__int64 a1, unsigned __int8 *a2, unsigned __int8 a3)
{
  unsigned __int8 *v3; // x25
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
  __int64 ext_hdl; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x21
  __int64 v25; // x26
  __int64 v26; // x0
  __int64 v27; // x1
  __int64 v28; // x2
  __int64 v29; // x3
  __int64 v30; // x4
  __int64 v31; // x5
  int v32; // w27
  unsigned __int8 *v33; // x23
  unsigned __int8 *v34; // x23
  int v35; // t1
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x24
  int v54; // w22
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  const char *v63; // x2
  __int64 v64; // x4
  __int64 v65; // x5
  __int64 v66; // x6
  unsigned int *v68; // x8
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  const char *v85; // x2
  __int64 v86; // x4
  unsigned __int8 v87; // w5
  int v88; // w8
  __int64 v89; // x4
  unsigned __int8 v90; // w9
  unsigned __int8 v91; // w10
  __int64 v92; // x7
  unsigned __int8 *v93; // x22
  unsigned int v94; // w11
  __int64 v95; // x8
  __int64 v96; // x20
  __int64 v97; // x21
  unsigned __int8 *v98; // x26
  _DWORD *v99; // x27
  int v100; // w6
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  unsigned __int8 *v109; // x8
  unsigned int v110; // w23
  unsigned int v111; // w24
  __int64 comp_private_obj; // x0
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  _DWORD *v121; // x25
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
  __int64 v138; // x4
  unsigned int v139; // w8
  __int64 v140; // x26
  unsigned __int64 v141; // x23
  unsigned int v142; // w22
  unsigned __int8 *v143; // x24
  __int64 v144; // x27
  unsigned __int8 *v145; // x20
  int v146; // w8
  __int64 v147; // x28
  double v148; // d0
  double v149; // d1
  double v150; // d2
  double v151; // d3
  double v152; // d4
  double v153; // d5
  double v154; // d6
  double v155; // d7
  int v156; // w8
  int v157; // w9
  int v158; // w10
  int v159; // w11
  unsigned int v160; // w9
  unsigned int v161; // w8
  unsigned int v162; // w20
  __int64 v163; // x21
  unsigned __int8 *v164; // x23
  void *v165; // x0
  int v166; // w8
  int v167; // w4
  int v168; // w8
  int v169; // w8
  int v170; // w8
  __int64 v171; // [xsp+0h] [xbp-50h]
  __int64 v172; // [xsp+8h] [xbp-48h]
  __int64 v173; // [xsp+10h] [xbp-40h]
  __int64 v174; // [xsp+18h] [xbp-38h]
  int v175; // [xsp+20h] [xbp-30h]
  __int64 v176; // [xsp+28h] [xbp-28h]
  __int64 v177; // [xsp+30h] [xbp-20h]
  unsigned __int8 *v178; // [xsp+38h] [xbp-18h]
  unsigned __int8 *v179; // [xsp+40h] [xbp-10h]
  unsigned __int8 *v180; // [xsp+48h] [xbp-8h]

  v3 = a2;
  v5 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a2, 1);
  if ( !v5 )
    return qdf_trace_msg(
             0x68u,
             2u,
             "%s: vdev%d: vdev object is NULL",
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             "wlan_cm_update_roam_stats_info",
             *v3);
  v14 = v5;
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(v5, v6, v7, v8, v9, v10, v11, v12, v13);
  if ( !ext_hdl )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev legacy private object is NULL",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "wlan_cm_update_roam_stats_info");
    return wlan_objmgr_vdev_release_ref(v14, 1u, v68, v69, v70, v71, v72, v73, v74, v75, v76);
  }
  v24 = ext_hdl + 20480;
  v25 = ext_hdl;
  if ( !*(_DWORD *)(ext_hdl + 23600) )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: Enhanced roam stats not supported",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "wlan_cm_update_roam_stats_info");
    return wlan_objmgr_vdev_release_ref(v14, 1u, v68, v69, v70, v71, v72, v73, v74, v75, v76);
  }
  if ( !*(_QWORD *)(ext_hdl + 23592) )
    return qdf_trace_msg(
             0x68u,
             2u,
             "%s: enhance_roam_info buffer is NULL",
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             "wlan_cm_update_roam_stats_info");
  v26 = qdf_mutex_acquire(ext_hdl + 23608);
  if ( a3 >= 5u )
    goto LABEL_127;
  v32 = a3;
  v33 = &v3[208 * a3];
  v35 = v33[4];
  v34 = v33 + 4;
  if ( v35 != 1 )
    goto LABEL_121;
  qdf_mem_set((void *)(*(_QWORD *)(v25 + 23592) + 1840LL * *(unsigned int *)(v24 + 3124)), 0x730u, 0);
  v44 = wlan_vdev_mlme_get_ext_hdl(v14, v36, v37, v38, v39, v40, v41, v42, v43);
  if ( !v44 )
  {
    v26 = qdf_trace_msg(
            0x68u,
            2u,
            "%s: null mlme priv",
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            "wlan_cm_update_roam_trigger_info");
    goto LABEL_48;
  }
  v53 = *(_QWORD *)(v44 + 23592) + 1840LL * *(unsigned int *)(v44 + 23604);
  *(_QWORD *)v53 = *((unsigned int *)v34 + 4);
  v54 = *((_DWORD *)v34 + 1);
  *(_DWORD *)(v53 + 8) = v54;
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: roam trigger info: timestamp:%llu, reason:%u,index:%u",
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    "wlan_cm_update_roam_trigger_info");
  if ( v54 <= 7 )
  {
    if ( v54 <= 3 )
    {
      if ( v54 != 1 )
      {
        if ( v54 == 2 )
        {
          v63 = "%s: roam bmiss: final:%u, consecutive:%u, qos:%u";
          *(_DWORD *)(v53 + 12) = *((_DWORD *)v34 + 5);
          *(_DWORD *)(v53 + 16) = *((_DWORD *)v34 + 6);
          *(_BYTE *)(v53 + 20) = v34[28] != 0;
          v64 = *((unsigned int *)v34 + 5);
          v65 = *((unsigned int *)v34 + 6);
          v66 = v34[28];
        }
        else
        {
          if ( v54 != 3 )
            goto LABEL_43;
          v63 = "%s: roam low rssi: rssi:%d, rssi_th:%d, rx_linkspeed:%u";
          *(_BYTE *)(v53 + 12) = v34[20];
          *(_BYTE *)(v53 + 13) = v34[21];
          *(_BYTE *)(v53 + 14) = v34[22] != 0;
          v64 = v34[20];
          v65 = v34[21];
          v66 = v34[22];
        }
        goto LABEL_38;
      }
      v87 = v34[21];
      v85 = "%s: roam per: rx:%u, tx:%u";
      goto LABEL_35;
    }
    if ( v54 == 4 )
    {
      v85 = "%s: roam better rssi: cu_rssi:%d, hi_rssi_th:%d";
      *(_BYTE *)(v53 + 12) = v34[20];
      v87 = v34[21];
LABEL_35:
      *(_BYTE *)(v53 + 13) = v87;
      v86 = v34[20];
      goto LABEL_42;
    }
    if ( v54 != 5 )
    {
      if ( v54 != 7 )
        goto LABEL_43;
      v63 = "%s: roam dense: rx_tput:%u, tx_tput:%u, roamable %u";
      *(_DWORD *)(v53 + 12) = *((_DWORD *)v34 + 5);
      *(_DWORD *)(v53 + 16) = *((_DWORD *)v34 + 6);
      v66 = v34[28];
      *(_BYTE *)(v53 + 20) = v66;
      v64 = *((unsigned int *)v34 + 5);
      v65 = *((unsigned int *)v34 + 6);
      goto LABEL_38;
    }
    v86 = *((unsigned int *)v34 + 5);
    v85 = "%s: roam periodic: periodic_timer:%u";
LABEL_41:
    *(_DWORD *)(v53 + 12) = v86;
    goto LABEL_42;
  }
  if ( v54 <= 11 )
  {
    if ( v54 == 8 )
    {
      v63 = "%s: roam background: rssi:%d, datarssi:%d, rssi_th %d";
      *(_BYTE *)(v53 + 12) = v34[20];
      *(_BYTE *)(v53 + 13) = v34[21];
      v66 = v34[22];
      *(_BYTE *)(v53 + 14) = v66;
      v64 = v34[20];
      v65 = v34[21];
LABEL_38:
      qdf_trace_msg(
        0x68u,
        8u,
        v63,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        "wlan_cm_update_roam_trigger_info",
        v64,
        v65,
        v66);
      goto LABEL_43;
    }
    if ( v54 != 9 )
    {
      if ( v54 == 10 )
      {
        *(_BYTE *)(v53 + 12) = *((_DWORD *)v34 + 6);
        *(_DWORD *)(v53 + 16) = *((_DWORD *)v34 + 7);
        *(_DWORD *)(v53 + 20) = *((_DWORD *)v34 + 8);
        *(_BYTE *)(v53 + 24) = *((_DWORD *)v34 + 9);
        *(_BYTE *)(v53 + 25) = *((_DWORD *)v34 + 10);
        *(_DWORD *)(v53 + 28) = *((_DWORD *)v34 + 11);
        *(_DWORD *)(v53 + 32) = *((_DWORD *)v34 + 12);
        *(_BYTE *)(v53 + 36) = v34[52];
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: roam btm: %u %u %u %u %u %u %u %u",
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          "wlan_cm_update_roam_trigger_info",
          *((unsigned int *)v34 + 6),
          *((unsigned int *)v34 + 7),
          *((unsigned int *)v34 + 8),
          *((unsigned int *)v34 + 9),
          *((_DWORD *)v34 + 10),
          *((_DWORD *)v34 + 11),
          *((_DWORD *)v34 + 12),
          *((unsigned __int16 *)v34 + 26));
      }
      goto LABEL_43;
    }
    v86 = *((unsigned int *)v34 + 5);
    v85 = "%s: roam force: invoke_reason:%u";
    goto LABEL_41;
  }
  switch ( v54 )
  {
    case 12:
      v85 = "%s: roam bss_load: cu_load:%u";
      *(_BYTE *)(v53 + 12) = *((_DWORD *)v34 + 5);
      v86 = *((unsigned int *)v34 + 5);
      goto LABEL_42;
    case 13:
      *(_BYTE *)(v53 + 12) = *((_DWORD *)v34 + 5);
      *(_WORD *)(v53 + 14) = *((_DWORD *)v34 + 6);
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: roam disconnection: type:%u reason:%u",
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        "wlan_cm_update_roam_trigger_info",
        *((unsigned int *)v34 + 5),
        *((unsigned int *)v34 + 6));
      v170 = *((_DWORD *)v34 + 5);
      if ( v170 == 2 )
      {
        cm_cp_stats_cstats_log_disassoc_evt(v14, *((unsigned int *)v34 + 6));
      }
      else if ( v170 == 1 )
      {
        cm_cp_stats_cstats_log_deauth_evt(v14, *((unsigned int *)v34 + 6));
      }
      break;
    case 15:
      v85 = "%s: roam tx_failures: kickout_th:%u kickout_reason:%u";
      *(_DWORD *)(v53 + 12) = *((_DWORD *)v34 + 5);
      *(_DWORD *)(v53 + 16) = *((_DWORD *)v34 + 6);
      v86 = *((unsigned int *)v34 + 5);
LABEL_42:
      qdf_trace_msg(0x68u, 8u, v85, v55, v56, v57, v58, v59, v60, v61, v62, "wlan_cm_update_roam_trigger_info", v86);
      break;
  }
LABEL_43:
  *(_DWORD *)(v53 + 48) = *((_DWORD *)v34 + 49);
  *(_BYTE *)(v53 + 52) = *((_DWORD *)v34 + 50);
  v26 = qdf_trace_msg(
          0x68u,
          8u,
          "%s: roam trigger info: scan_type:%u,status:%u",
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          "wlan_cm_update_roam_trigger_info",
          *((unsigned int *)v34 + 49),
          *((unsigned int *)v34 + 50));
  if ( *(_BYTE *)(v53 + 52) )
  {
    v88 = *((_DWORD *)v34 + 51);
    *(_DWORD *)(v53 + 56) = v88;
    v89 = *((unsigned int *)v34 + 47);
    if ( (_DWORD)v89 )
    {
      *(_DWORD *)(v53 + 40) = v89;
      v90 = v34[192];
      *(_BYTE *)(v53 + 44) = v90;
      v91 = v34[193];
      *(_BYTE *)(v53 + 45) = v91;
      v92 = v34[194] != 0;
      *(_BYTE *)(v53 + 46) = v92;
    }
    else
    {
      v89 = *(unsigned int *)(v53 + 40);
      v90 = *(_BYTE *)(v53 + 44);
      v91 = *(_BYTE *)(v53 + 45);
      v92 = *(unsigned __int8 *)(v53 + 46);
    }
    LODWORD(v171) = v88;
    v26 = qdf_trace_msg(
            0x68u,
            8u,
            "%s: abort:reason:%u,rssi:%d,rssit:%d,status:%u,fail:%u",
            v77,
            v78,
            v79,
            v80,
            v81,
            v82,
            v83,
            v84,
            "wlan_cm_update_roam_trigger_info",
            v89,
            (unsigned int)(char)v90,
            (unsigned int)(char)v91,
            v92,
            v171);
  }
LABEL_48:
  v177 = v25;
  v93 = &v3[680 * v32];
  v175 = v32;
  v176 = v24;
  v178 = v3;
  v179 = v93;
  if ( v93[1044] != 1 )
    goto LABEL_69;
  v26 = wlan_vdev_mlme_get_ext_hdl(v14, v77, v78, v79, v80, v81, v82, v83, v84);
  if ( v26 )
  {
    v94 = *(_DWORD *)(v26 + 23604);
    v95 = *(_QWORD *)(v26 + 23592);
    v96 = v95 + 1840LL * v94;
    *(_BYTE *)(v96 + 64) = v93[1050];
    if ( !*((_WORD *)v93 + 525) )
      goto LABEL_69;
    v97 = 0;
    v98 = &v3[680 * v32];
    v99 = (_DWORD *)(v95 + 1840LL * v94 + 76);
    while ( 1 )
    {
      if ( v97 == 38 )
        goto LABEL_127;
      v109 = &v98[2 * v97];
      *((_WORD *)v99 - 4) = *((_WORD *)v109 + 530);
      *(v99 - 1) = v98[v97 + 1676];
      v110 = *((unsigned __int16 *)v109 + 530);
      v111 = v98[v97 + 1676];
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(*(_QWORD *)(v14 + 152) + 80LL), 3u);
      if ( !comp_private_obj )
        break;
      v121 = (_DWORD *)comp_private_obj;
      if ( !wlan_reg_is_24ghz_ch_freq(v110) )
      {
        if ( wlan_reg_is_5ghz_ch_freq(v110) )
        {
          if ( v111 == 2 )
            v100 = v121[408];
          else
            v100 = v121[400];
          goto LABEL_53;
        }
        if ( wlan_reg_is_6ghz_chan_freq(v110) )
        {
          if ( v111 == 2 )
            v100 = v121[405];
          else
            v100 = v121[404];
          goto LABEL_53;
        }
        goto LABEL_61;
      }
      v100 = v121[402];
LABEL_53:
      *v99 = v100;
      v99 += 3;
      v26 = qdf_trace_msg(
              0x68u,
              8u,
              "%s: freq %u dwell_type %u dwell_time:%u",
              v122,
              v123,
              v124,
              v125,
              v126,
              v127,
              v128,
              v129,
              "wlan_cm_update_roam_scan_info",
              v110,
              v111);
      if ( ++v97 >= (unsigned __int64)*((unsigned __int16 *)v93 + 525) )
      {
        v138 = *(unsigned __int8 *)(v96 + 64);
        *(_DWORD *)(v96 + 524) = *((_DWORD *)v93 + 429) - *(_DWORD *)v96;
        v26 = qdf_trace_msg(
                0x68u,
                8u,
                "%s: roam scan:chn_num:%u,com:%u,total_time:%u,index:%u",
                v101,
                v102,
                v103,
                v104,
                v105,
                v106,
                v107,
                v108,
                "wlan_cm_update_roam_scan_info",
                v138,
                *((unsigned int *)v93 + 429));
        v3 = v178;
        v32 = v175;
        goto LABEL_69;
      }
    }
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v113,
      v114,
      v115,
      v116,
      v117,
      v118,
      v119,
      v120,
      "wlan_psoc_get_scan_obj_fl",
      "wlan_pdev_get_scan_obj",
      764);
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: scan_obj is NULL",
      v130,
      v131,
      v132,
      v133,
      v134,
      v135,
      v136,
      v137,
      "wlan_cm_get_roam_chn_dwell_time");
LABEL_61:
    v100 = 0;
    goto LABEL_53;
  }
  v26 = qdf_trace_msg(
          0x68u,
          2u,
          "%s: vdev legacy private object is NULL",
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          v83,
          v84,
          "wlan_cm_update_roam_scan_info");
LABEL_69:
  v180 = &v3[2164 * v32];
  v139 = v180[4584];
  if ( v180[4584] )
  {
    v140 = 0;
    v141 = 0;
    v142 = 0;
    v143 = &v178[2164 * v175];
    v144 = *(_QWORD *)(v177 + 23592) + 1840LL * *(unsigned int *)(v176 + 3124);
    v145 = v143 + 4601;
    while ( 1 )
    {
      if ( v140 == 2200 )
        goto LABEL_127;
      v160 = v145[v140];
      if ( v160 <= 0x30 && ((1LL << v160) & 0x100010000001ELL) != 0 )
        break;
      if ( v160 == 176 )
        break;
LABEL_75:
      ++v141;
      v140 += 40;
      if ( v141 >= v139 )
        goto LABEL_106;
    }
    if ( v142 > 0x35 )
      goto LABEL_106;
    if ( v140 == 2160 )
      goto LABEL_127;
    if ( v145[v140] <= 4u )
    {
      if ( v145[v140] > 2u )
      {
        if ( v160 == 3 )
          v146 = 5;
        else
          v146 = 6;
LABEL_72:
        v147 = v144 + 24LL * v142;
        *(_DWORD *)(v147 + 544) = v146;
        *(_QWORD *)(v147 + 552) = *(unsigned int *)&v143[v140 + 4596];
        *(_DWORD *)(v147 + 548) = *(unsigned __int16 *)&v143[v140 + 4612];
        qdf_mem_copy((void *)(v147 + 560), &v143[v140 + 4589], 6u);
        if ( v147 == -560 )
        {
          v158 = 0;
          v156 = 0;
          v157 = 0;
          v159 = 0;
        }
        else
        {
          v156 = *(unsigned __int8 *)(v147 + 560);
          v157 = *(unsigned __int8 *)(v147 + 561);
          v158 = *(unsigned __int8 *)(v147 + 562);
          v159 = *(unsigned __int8 *)(v147 + 565);
        }
        LODWORD(v174) = v159;
        LODWORD(v173) = v158;
        LODWORD(v172) = v157;
        LODWORD(v171) = v156;
        v26 = qdf_trace_msg(
                0x68u,
                8u,
                "%s: frame:idx:%u subtype:%x time:%llu status:%u AP BSSID%02x:%02x:%02x:**:**:%02x",
                v148,
                v149,
                v150,
                v151,
                v152,
                v153,
                v154,
                v155,
                "wlan_cm_update_roam_frame_info",
                v142++,
                *(unsigned int *)(v147 + 544),
                *(_QWORD *)(v147 + 552),
                *(unsigned int *)(v147 + 548),
                v171,
                v172,
                v173,
                v174);
        v139 = v180[4584];
        goto LABEL_75;
      }
      if ( v160 == 1 )
      {
        v146 = 3;
        goto LABEL_72;
      }
      if ( v160 == 2 )
      {
        v146 = 4;
        goto LABEL_72;
      }
    }
    else if ( v145[v140] <= 0x1Fu )
    {
      if ( v160 == 5 )
      {
        v146 = 7;
        goto LABEL_72;
      }
      if ( v160 == 6 )
      {
        v146 = 8;
        goto LABEL_72;
      }
    }
    else
    {
      switch ( v160 )
      {
        case 0x20u:
          v146 = 10;
          goto LABEL_72;
        case 0x30u:
          v146 = 2;
          goto LABEL_72;
        case 0xB0u:
          if ( v145[v140 + 1] )
            v146 = 1;
          else
            v146 = 9;
          goto LABEL_72;
      }
    }
    v146 = 9;
    goto LABEL_72;
  }
LABEL_106:
  v25 = v177;
  if ( v179[1044] != 1 || (v161 = *((unsigned __int16 *)v179 + 524), !*((_WORD *)v179 + 524)) )
  {
LABEL_117:
    v178[3] = 1;
    mlme_cm_osif_roam_rt_stats();
    v168 = *(_DWORD *)(v176 + 3124);
    if ( v168 + 1 == *(_DWORD *)(v176 + 3120) )
      v169 = 0;
    else
      v169 = v168 + 1;
    *(_DWORD *)(v176 + 3124) = v169;
LABEL_121:
    qdf_mutex_release(v25 + 23608);
    return wlan_objmgr_vdev_release_ref(v14, 1u, v68, v69, v70, v71, v72, v73, v74, v75, v76);
  }
  if ( v161 < 0xB )
  {
    v162 = v161 - 1;
    v163 = *(_QWORD *)(v177 + 23592) + 1840LL * *(unsigned __int16 *)(v176 + 3124);
    v164 = &v178[680 * v175 + 1141 + 60 * (unsigned __int16)(v161 - 1)];
    while ( 1 )
    {
      v167 = *(v164 - 1);
      if ( v167 == 2 )
      {
        v165 = (void *)(v163 + 534);
      }
      else
      {
        if ( v167 != 1 )
        {
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: unknown type:%u of AP",
            v77,
            v78,
            v79,
            v80,
            v81,
            v82,
            v83,
            v84,
            "wlan_cm_update_roam_bssid");
          goto LABEL_112;
        }
        v165 = (void *)(v163 + 528);
      }
      qdf_mem_copy(v165, v164, 6u);
LABEL_112:
      v166 = (__int16)v162;
      v164 -= 60;
      --v162;
      if ( v166 <= 0 )
        goto LABEL_117;
    }
  }
LABEL_127:
  __break(0x5512u);
  return cm_roam_stats_print_trigger_info(v26, v27, v28, v29, v30, v31);
}
