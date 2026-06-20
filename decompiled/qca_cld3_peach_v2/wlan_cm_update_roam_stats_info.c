__int64 __fastcall wlan_cm_update_roam_stats_info(__int64 a1, unsigned __int8 *a2, unsigned __int8 a3)
{
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
  __int64 v24; // x25
  __int64 v25; // x21
  __int64 v26; // x0
  __int64 v27; // x1
  __int64 v28; // x2
  __int64 v29; // x3
  __int64 v30; // x4
  __int64 v31; // x5
  int v32; // w28
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
  __int64 v96; // x26
  unsigned __int8 *v97; // x28
  _DWORD *v98; // x22
  int v99; // w6
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  unsigned __int8 *v108; // x8
  unsigned int v109; // w23
  unsigned int v110; // w24
  __int64 comp_private_obj; // x0
  double v112; // d0
  double v113; // d1
  double v114; // d2
  double v115; // d3
  double v116; // d4
  double v117; // d5
  double v118; // d6
  double v119; // d7
  _DWORD *v120; // x25
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  __int64 v137; // x4
  unsigned __int8 *v138; // x28
  unsigned int v139; // w8
  unsigned __int64 v140; // x23
  unsigned int v141; // w22
  __int64 v142; // x24
  __int64 v143; // x25
  int v144; // w8
  __int64 v145; // x27
  double v146; // d0
  double v147; // d1
  double v148; // d2
  double v149; // d3
  double v150; // d4
  double v151; // d5
  double v152; // d6
  double v153; // d7
  int v154; // w8
  int v155; // w9
  int v156; // w10
  int v157; // w11
  unsigned int v158; // w9
  unsigned int v159; // w8
  unsigned int v160; // w25
  __int64 v161; // x26
  unsigned __int8 *v162; // x23
  void *v163; // x0
  int v164; // w8
  int v165; // w4
  int v166; // w8
  int v167; // w8
  int v168; // w8
  __int64 v169; // [xsp+0h] [xbp-40h]
  __int64 v170; // [xsp+8h] [xbp-38h]
  __int64 v171; // [xsp+10h] [xbp-30h]
  __int64 v172; // [xsp+18h] [xbp-28h]
  __int64 v173; // [xsp+20h] [xbp-20h]
  int v174; // [xsp+28h] [xbp-18h]
  __int64 v175; // [xsp+30h] [xbp-10h]
  unsigned __int8 *v176; // [xsp+38h] [xbp-8h]

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
             *a2);
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
  v33 = &a2[208 * a3];
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
      v168 = *((_DWORD *)v34 + 5);
      if ( v168 == 2 )
      {
        cm_cp_stats_cstats_log_disassoc_evt(v14, *((unsigned int *)v34 + 6));
      }
      else if ( v168 == 1 )
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
    LODWORD(v169) = v88;
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
            v169);
  }
LABEL_48:
  v174 = v32;
  v93 = &a2[680 * v32];
  v175 = v24;
  v176 = v93;
  if ( v93[1044] != 1 )
    goto LABEL_69;
  v26 = wlan_vdev_mlme_get_ext_hdl(v14, v77, v78, v79, v80, v81, v82, v83, v84);
  if ( v26 )
  {
    v94 = *(_DWORD *)(v26 + 23604);
    v95 = *(_QWORD *)(v26 + 23592);
    *(_BYTE *)(v95 + 1840LL * v94 + 64) = v93[1050];
    if ( !*((_WORD *)v93 + 525) )
      goto LABEL_69;
    v173 = v95 + 1840LL * v94;
    v96 = 0;
    v97 = &a2[680 * v32];
    v98 = (_DWORD *)(v173 + 76);
    while ( 1 )
    {
      if ( v96 == 38 )
        goto LABEL_127;
      v108 = &v97[2 * v96];
      *((_WORD *)v98 - 4) = *((_WORD *)v108 + 530);
      *(v98 - 1) = v97[v96 + 1676];
      v109 = *((unsigned __int16 *)v108 + 530);
      v110 = v97[v96 + 1676];
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(*(_QWORD *)(v14 + 216) + 80LL), 3u);
      if ( !comp_private_obj )
        break;
      v120 = (_DWORD *)comp_private_obj;
      if ( !wlan_reg_is_24ghz_ch_freq(v109) )
      {
        if ( wlan_reg_is_5ghz_ch_freq(v109) )
        {
          if ( v110 == 2 )
            v99 = v120[408];
          else
            v99 = v120[400];
          goto LABEL_53;
        }
        if ( wlan_reg_is_6ghz_chan_freq(v109) )
        {
          if ( v110 == 2 )
            v99 = v120[405];
          else
            v99 = v120[404];
          goto LABEL_53;
        }
        goto LABEL_61;
      }
      v99 = v120[402];
LABEL_53:
      *v98 = v99;
      v98 += 3;
      v26 = qdf_trace_msg(
              0x68u,
              8u,
              "%s: freq %u dwell_type %u dwell_time:%u",
              v121,
              v122,
              v123,
              v124,
              v125,
              v126,
              v127,
              v128,
              "wlan_cm_update_roam_scan_info",
              v109,
              v110);
      if ( ++v96 >= (unsigned __int64)*((unsigned __int16 *)v176 + 525) )
      {
        v137 = *(unsigned __int8 *)(v173 + 64);
        *(_DWORD *)(v173 + 524) = *((_DWORD *)v176 + 429) - *(_DWORD *)v173;
        v26 = qdf_trace_msg(
                0x68u,
                8u,
                "%s: roam scan:chn_num:%u,com:%u,total_time:%u,index:%u",
                v100,
                v101,
                v102,
                v103,
                v104,
                v105,
                v106,
                v107,
                "wlan_cm_update_roam_scan_info",
                v137,
                *((unsigned int *)v176 + 429));
        v32 = v174;
        goto LABEL_69;
      }
    }
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v112,
      v113,
      v114,
      v115,
      v116,
      v117,
      v118,
      v119,
      "wlan_psoc_get_scan_obj_fl",
      "wlan_pdev_get_scan_obj",
      764);
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: scan_obj is NULL",
      v129,
      v130,
      v131,
      v132,
      v133,
      v134,
      v135,
      v136,
      "wlan_cm_get_roam_chn_dwell_time");
LABEL_61:
    v99 = 0;
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
  v138 = &a2[6488 * v32];
  v139 = v138[4584];
  if ( v138[4584] )
  {
    v140 = 0;
    v141 = 0;
    v142 = *(_QWORD *)(v25 + 23592) + 1840LL * *(unsigned int *)(v175 + 3124);
    v143 = (__int64)&a2[6488 * v174 + 4593];
    while ( 1 )
    {
      if ( v140 == 55 )
        goto LABEL_127;
      v158 = *(unsigned __int8 *)(v143 + 12);
      if ( v158 <= 0x30 && ((1LL << v158) & 0x100010000001ELL) != 0 )
        break;
      if ( v158 == 176 )
        break;
LABEL_75:
      ++v140;
      v143 += 120;
      if ( v140 >= v139 )
        goto LABEL_106;
    }
    if ( v141 > 0x35 )
      goto LABEL_106;
    if ( v140 == 54 )
      goto LABEL_127;
    if ( *(unsigned __int8 *)(v143 + 12) <= 4u )
    {
      if ( *(unsigned __int8 *)(v143 + 12) > 2u )
      {
        if ( v158 == 3 )
          v144 = 5;
        else
          v144 = 6;
LABEL_72:
        v145 = v142 + 24LL * v141;
        *(_DWORD *)(v145 + 544) = v144;
        *(_QWORD *)(v145 + 552) = *(unsigned int *)(v143 + 7);
        *(_DWORD *)(v145 + 548) = *(unsigned __int16 *)(v143 + 23);
        qdf_mem_copy((void *)(v145 + 560), (const void *)v143, 6u);
        if ( v145 == -560 )
        {
          v156 = 0;
          v154 = 0;
          v155 = 0;
          v157 = 0;
        }
        else
        {
          v154 = *(unsigned __int8 *)(v145 + 560);
          v155 = *(unsigned __int8 *)(v145 + 561);
          v156 = *(unsigned __int8 *)(v145 + 562);
          v157 = *(unsigned __int8 *)(v145 + 565);
        }
        LODWORD(v172) = v157;
        LODWORD(v171) = v156;
        LODWORD(v170) = v155;
        LODWORD(v169) = v154;
        v26 = qdf_trace_msg(
                0x68u,
                8u,
                "%s: frame:idx:%u subtype:%x time:%llu status:%u AP BSSID%02x:%02x:%02x:**:**:%02x",
                v146,
                v147,
                v148,
                v149,
                v150,
                v151,
                v152,
                v153,
                "wlan_cm_update_roam_frame_info",
                v141++,
                *(unsigned int *)(v145 + 544),
                *(_QWORD *)(v145 + 552),
                *(unsigned int *)(v145 + 548),
                v169,
                v170,
                v171,
                v172);
        v139 = v138[4584];
        goto LABEL_75;
      }
      if ( v158 == 1 )
      {
        v144 = 3;
        goto LABEL_72;
      }
      if ( v158 == 2 )
      {
        v144 = 4;
        goto LABEL_72;
      }
    }
    else if ( *(unsigned __int8 *)(v143 + 12) <= 0x1Fu )
    {
      if ( v158 == 5 )
      {
        v144 = 7;
        goto LABEL_72;
      }
      if ( v158 == 6 )
      {
        v144 = 8;
        goto LABEL_72;
      }
    }
    else
    {
      switch ( v158 )
      {
        case 0x20u:
          v144 = 10;
          goto LABEL_72;
        case 0x30u:
          v144 = 2;
          goto LABEL_72;
        case 0xB0u:
          if ( *(_BYTE *)(v143 + 13) )
            v144 = 1;
          else
            v144 = 9;
          goto LABEL_72;
      }
    }
    v144 = 9;
    goto LABEL_72;
  }
LABEL_106:
  if ( v176[1044] != 1 || (v159 = *((unsigned __int16 *)v176 + 524), !*((_WORD *)v176 + 524)) )
  {
LABEL_117:
    a2[3] = 1;
    mlme_cm_osif_roam_rt_stats();
    v166 = *(_DWORD *)(v175 + 3124);
    if ( v166 + 1 == *(_DWORD *)(v175 + 3120) )
      v167 = 0;
    else
      v167 = v166 + 1;
    *(_DWORD *)(v175 + 3124) = v167;
LABEL_121:
    qdf_mutex_release(v25 + 23608);
    return wlan_objmgr_vdev_release_ref(v14, 1u, v68, v69, v70, v71, v72, v73, v74, v75, v76);
  }
  if ( v159 < 0xB )
  {
    v160 = v159 - 1;
    v161 = *(_QWORD *)(v25 + 23592) + 1840LL * *(unsigned __int16 *)(v175 + 3124);
    v162 = &a2[680 * v174 + 1141 + 60 * (unsigned __int16)(v159 - 1)];
    while ( 1 )
    {
      v165 = *(v162 - 1);
      if ( v165 == 2 )
      {
        v163 = (void *)(v161 + 534);
      }
      else
      {
        if ( v165 != 1 )
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
        v163 = (void *)(v161 + 528);
      }
      qdf_mem_copy(v163, v162, 6u);
LABEL_112:
      v164 = (__int16)v160;
      v162 -= 60;
      --v160;
      if ( v164 <= 0 )
        goto LABEL_117;
    }
  }
LABEL_127:
  __break(0x5512u);
  return cm_roam_stats_print_trigger_info(v26, v27, v28, v29, v30, v31);
}
