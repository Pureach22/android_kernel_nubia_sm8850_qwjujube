__int64 __fastcall wlan_hdd_request_pre_cac(__int64 *a1, unsigned int a2)
{
  unsigned __int64 StatusReg; // x8
  unsigned int *v5; // x8
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x1
  unsigned int *v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x8
  __int64 v25; // x22
  unsigned __int64 v26; // x24
  __int64 v27; // x23
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int *v44; // x8
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x8
  unsigned int v54; // w21
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 result; // x0
  int v72; // w26
  __int64 v73; // x0
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  const char *v82; // x2
  unsigned int v83; // w1
  __int64 adapter; // x0
  __int64 v85; // x27
  __int64 v86; // x23
  char is_dfs_for_freq; // w0
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  __int64 v96; // x4
  const char *v97; // x2
  __int64 v98; // x0
  unsigned int max_bw_by_phymode; // w0
  unsigned int v100; // w21
  __int64 adapter_by_iface_name; // x0
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  __int64 v110; // x21
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  __int64 v119; // x22
  unsigned __int8 *v120; // x20
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  __int64 intf_addr; // x0
  double v130; // d0
  double v131; // d1
  double v132; // d2
  double v133; // d3
  double v134; // d4
  double v135; // d5
  double v136; // d6
  double v137; // d7
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
  __int64 v154; // x0
  __int64 v155; // x23
  __int64 v156; // x24
  void *v157; // x0
  double v158; // d0
  double v159; // d1
  double v160; // d2
  double v161; // d3
  double v162; // d4
  double v163; // d5
  double v164; // d6
  double v165; // d7
  unsigned int v166; // w0
  int v167; // w8
  double v168; // d0
  double v169; // d1
  double v170; // d2
  double v171; // d3
  double v172; // d4
  double v173; // d5
  double v174; // d6
  double v175; // d7
  double v176; // d0
  double v177; // d1
  double v178; // d2
  double v179; // d3
  double v180; // d4
  double v181; // d5
  double v182; // d6
  double v183; // d7
  double v184; // d0
  double v185; // d1
  double v186; // d2
  double v187; // d3
  double v188; // d4
  double v189; // d5
  double v190; // d6
  double v191; // d7
  double v192; // d0
  double v193; // d1
  double v194; // d2
  double v195; // d3
  double v196; // d4
  double v197; // d5
  double v198; // d6
  double v199; // d7
  double v200; // d0
  double v201; // d1
  double v202; // d2
  double v203; // d3
  double v204; // d4
  double v205; // d5
  double v206; // d6
  double v207; // d7
  const char *v208; // x2
  int v209; // w22
  double v210; // d0
  double v211; // d1
  double v212; // d2
  double v213; // d3
  double v214; // d4
  double v215; // d5
  double v216; // d6
  double v217; // d7
  __int64 v218; // x0
  double v219; // d0
  double v220; // d1
  double v221; // d2
  double v222; // d3
  double v223; // d4
  double v224; // d5
  double v225; // d6
  double v226; // d7
  __int64 *v227; // [xsp+8h] [xbp-48h] BYREF
  __int64 v228; // [xsp+10h] [xbp-40h] BYREF
  int v229; // [xsp+1Ch] [xbp-34h] BYREF
  unsigned int v230; // [xsp+20h] [xbp-30h] BYREF
  unsigned int v231; // [xsp+24h] [xbp-2Ch] BYREF
  __int64 v232; // [xsp+28h] [xbp-28h] BYREF
  __int64 v233; // [xsp+30h] [xbp-20h]
  __int64 v234; // [xsp+38h] [xbp-18h]
  __int64 v235; // [xsp+40h] [xbp-10h]
  __int64 v236; // [xsp+48h] [xbp-8h]

  v236 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v227 = nullptr;
  v228 = 0;
  v232 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 4);
  }
  else
  {
    raw_spin_lock_bh(a1 + 4);
    a1[5] |= 1uLL;
  }
  hdd_get_front_adapter_no_lock((__int64)a1, &v232);
  if ( v232 )
  {
    hdd_adapter_dev_hold_debug(v232, 0x3Cu, v5, v6, v7, v8, v9, v10, v11, v12, v13);
    v14 = v232;
  }
  else
  {
    v14 = 0;
  }
  hdd_get_next_adapter_no_lock((__int64)a1, v14, &v228);
  if ( v228 )
    hdd_adapter_dev_hold_debug(v228, 0x3Cu, v15, v16, v17, v18, v19, v20, v21, v22, v23);
  v24 = a1[5];
  if ( (v24 & 1) != 0 )
  {
    a1[5] = v24 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 4);
    v25 = v232;
    if ( v232 )
      goto LABEL_12;
LABEL_31:
    result = _osif_vdev_sync_create_and_trans(a1[12], &v227, (__int64)"wlan_hdd_start_pre_cac_trans");
    if ( (_DWORD)result )
      goto LABEL_46;
    v72 = 1;
LABEL_33:
    v73 = *a1;
    LODWORD(v228) = 0;
    v234 = 0;
    v235 = 0;
    v232 = 0;
    v233 = 0;
    v229 = 0;
    if ( (policy_mgr_is_hw_dbs_capable(v73) & 1) == 0 )
    {
      v82 = "%s: Pre CAC is not supported on non-dbs platforms";
      v83 = 8;
LABEL_42:
      qdf_trace_msg(0x33u, v83, v82, v74, v75, v76, v77, v78, v79, v80, v81, "__wlan_hdd_request_pre_cac");
LABEL_43:
      osif_vdev_sync_trans_stop((__int64)v227);
      if ( v72 )
        osif_vdev_sync_destroy((__int64)v227);
      result = 4294967274LL;
      goto LABEL_46;
    }
    if ( (unsigned int)policy_mgr_get_connection_count(*a1) >= 2 )
    {
      v82 = "%s: pre cac not allowed in concurrency";
LABEL_41:
      v83 = 2;
      goto LABEL_42;
    }
    adapter = hdd_get_adapter((__int64)a1, 1);
    if ( !adapter )
    {
      v82 = "%s: unable to get SAP adapter";
      goto LABEL_41;
    }
    v85 = *(_QWORD *)(adapter + 52824);
    if ( *(_DWORD *)(v85 + 2348) )
    {
      v82 = "%s: pre cac not allowed during CSA";
      goto LABEL_41;
    }
    v86 = a1[2];
    is_dfs_for_freq = wlan_reg_is_dfs_for_freq(a1[1], *(_DWORD *)(v85 + 2152), v74, v75, v76, v77, v78, v79, v80, v81);
    v96 = *(unsigned int *)(v85 + 2152);
    if ( (is_dfs_for_freq & 1) != 0 )
    {
      v97 = "%s: SAP is already on DFS channel:%d";
LABEL_57:
      qdf_trace_msg(0x33u, 2u, v97, v88, v89, v90, v91, v92, v93, v94, v95, "__wlan_hdd_request_pre_cac", v96);
      goto LABEL_43;
    }
    if ( !wlan_reg_is_24ghz_ch_freq(v96) )
    {
      v96 = *(unsigned int *)(v85 + 2152);
      v97 = "%s: pre CAC allowed only when SAP is in 2.4GHz:%d";
      goto LABEL_57;
    }
    v98 = *(_QWORD *)(v85 + 272);
    v231 = 0;
    max_bw_by_phymode = wlansap_get_max_bw_by_phymode(v98, v88, v89, v90, v91, v92, v93, v94, v95);
    if ( max_bw_by_phymode >= 2 )
      v100 = 2;
    else
      v100 = max_bw_by_phymode;
    v230 = v100;
    if ( a2 )
    {
      qdf_mem_set(&v232, 0x20u, 0);
      if ( (unsigned int)wlan_set_def_pre_cac_chan(a1, a2, &v232, &v231, &v230) )
      {
        v97 = "%s: failed to set pre_cac channel %d";
        v96 = a2;
        goto LABEL_57;
      }
      v100 = v230;
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: channel: %d bw: %d",
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      v94,
      v95,
      "__wlan_hdd_request_pre_cac",
      a2,
      v100);
    if ( (unsigned int)ucfg_pre_cac_validate_and_get_freq(a1[1], a2, (unsigned int *)&v228, v100) )
    {
      v82 = "%s: can't validate pre-cac channel";
      goto LABEL_41;
    }
    adapter_by_iface_name = hdd_get_adapter_by_iface_name((__int64)a1, "precac");
    if ( adapter_by_iface_name )
    {
      v110 = adapter_by_iface_name;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: pre cac SAP adapter is present",
        v102,
        v103,
        v104,
        v105,
        v106,
        v107,
        v108,
        v109,
        "__wlan_hdd_request_pre_cac");
      v119 = *(_QWORD *)(v110 + 52824);
      if ( (*(_QWORD *)(v119 + 4416) & 1) != 0 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: pre cac is on-going",
          v111,
          v112,
          v113,
          v114,
          v115,
          v116,
          v117,
          v118,
          "__wlan_hdd_request_pre_cac");
        v110 = 0;
        if ( !v72 )
          goto LABEL_72;
        goto LABEL_71;
      }
      v120 = nullptr;
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: starting pre cac SAP  adapter",
        v102,
        v103,
        v104,
        v105,
        v106,
        v107,
        v108,
        v109,
        "__wlan_hdd_request_pre_cac");
      intf_addr = wlan_hdd_get_intf_addr((__int64)a1, 1, v121, v122, v123, v124, v125, v126, v127, v128);
      if ( !intf_addr )
      {
        v82 = "%s: can't add virtual intf: Not getting valid mac addr";
        goto LABEL_41;
      }
      v120 = (unsigned __int8 *)intf_addr;
      v229 = 520;
      if ( !(unsigned int)rtnl_trylock(intf_addr)
        || (v110 = hdd_open_adapter(a1, 1u, "precac", v120, 0, 1, &v229, v130, v131, v132, v133, v134, v135, v136, v137),
            rtnl_unlock(v110),
            !v110) )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: error opening the pre cac adapter",
          v130,
          v131,
          v132,
          v133,
          v134,
          v135,
          v136,
          v137,
          "__wlan_hdd_request_pre_cac");
LABEL_95:
        wlan_hdd_release_intf_addr((__int64)a1, v120, v176, v177, v178, v179, v180, v181, v182, v183);
        goto LABEL_43;
      }
      v119 = *(_QWORD *)(v110 + 52824);
    }
    sap_clear_global_dfs_param(v86, *(_QWORD *)(v119 + 272));
    if ( (unsigned int)hdd_start_adapter(v110, v138, v139, v140, v141, v142, v143, v144, v145) )
    {
      v154 = qdf_trace_msg(
               0x33u,
               2u,
               "%s: error starting the pre cac adapter",
               v146,
               v147,
               v148,
               v149,
               v150,
               v151,
               v152,
               v153,
               "__wlan_hdd_request_pre_cac");
      goto LABEL_92;
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: preparing for start ap/bss on the pre cac adapter",
      v146,
      v147,
      v148,
      v149,
      v150,
      v151,
      v152,
      v153,
      "__wlan_hdd_request_pre_cac");
    v155 = a1[3];
    v156 = *(_QWORD *)(v110 + 32);
    v157 = (void *)_qdf_mem_malloc(0x38u, "__wlan_hdd_request_pre_cac", 370);
    *(_QWORD *)(v119 + 2160) = v157;
    if ( !v157 )
      goto LABEL_91;
    qdf_mem_copy(v157, *(const void **)(v85 + 2160), 0x38u);
    *(_DWORD *)(v119 + 1268) = *(_DWORD *)(v85 + 1268);
    *(_DWORD *)(v119 + 744) = *(_DWORD *)(v85 + 744);
    v166 = wlansap_get_max_bw_by_phymode(*(_QWORD *)(v85 + 272), v158, v159, v160, v161, v162, v163, v164, v165);
    if ( v166 >= 2 )
      v167 = 2;
    else
      v167 = v166;
    v230 = v167;
    qdf_mem_set(&v232, 0x20u, 0);
    if ( (unsigned int)wlan_set_def_pre_cac_chan(a1, (unsigned int)v228, &v232, &v231, &v230) )
    {
      v154 = qdf_trace_msg(
               0x33u,
               2u,
               "%s: error set pre_cac channel %d",
               v168,
               v169,
               v170,
               v171,
               v172,
               v173,
               v174,
               v175,
               "__wlan_hdd_request_pre_cac",
               (unsigned int)v228);
      goto LABEL_92;
    }
    *(_DWORD *)(v119 + 744) = hdd_map_nl_chan_width((unsigned int)v233);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: existing ap phymode:%d pre cac ch_width:%d freq:%d",
      v184,
      v185,
      v186,
      v187,
      v188,
      v189,
      v190,
      v191,
      "__wlan_hdd_request_pre_cac",
      *(unsigned int *)(v85 + 320),
      v230,
      (unsigned int)v228);
    if ( (unsigned int)policy_mgr_update_and_wait_for_connection_update(
                         *a1,
                         *(_BYTE *)(v85 + 8),
                         v228,
                         9u,
                         v192,
                         v193,
                         v194,
                         v195,
                         v196,
                         v197,
                         v198,
                         v199) )
    {
      v208 = "%s: error in moving to DBS mode";
LABEL_90:
      qdf_trace_msg(0x33u, 2u, v208, v200, v201, v202, v203, v204, v205, v206, v207, "__wlan_hdd_request_pre_cac");
LABEL_91:
      *(_BYTE *)(v110 + 52797) = 1;
      hdd_stop_adapter(a1, v110);
      v154 = _qdf_mem_free(*(_QWORD *)(v119 + 2160));
      *(_QWORD *)(v119 + 2160) = 0;
LABEL_92:
      v209 = rtnl_trylock(v154);
      v218 = hdd_close_adapter(a1, v110, 1, v210, v211, v212, v213, v214, v215, v216, v217);
      if ( v209 )
        rtnl_unlock(v218);
      if ( !v120 )
        goto LABEL_43;
      goto LABEL_95;
    }
    if ( (unsigned int)wlan_hdd_set_channel(
                         v119,
                         v200,
                         v201,
                         v202,
                         v203,
                         v204,
                         v205,
                         v206,
                         v207,
                         v155,
                         v156,
                         (unsigned int *)&v232,
                         v231) )
    {
      v208 = "%s: failed to set channel";
      goto LABEL_90;
    }
    if ( (unsigned int)wlan_hdd_cfg80211_start_bss(
                         v119,
                         v200,
                         v201,
                         v202,
                         v203,
                         v204,
                         v205,
                         v206,
                         v207,
                         0,
                         "pre_cac_ssid",
                         12,
                         0,
                         0) )
    {
      v208 = "%s: start bss failed";
      goto LABEL_90;
    }
    if ( (unsigned int)ucfg_pre_cac_set_status(*(_QWORD *)(v119 + 32), 1) )
    {
      v208 = "%s: failed to set pre cac status";
      goto LABEL_90;
    }
    ucfg_pre_cac_clear_work(*a1);
    ucfg_pre_cac_set_freq_before_pre_cac(*(_QWORD *)(v85 + 32), *(_DWORD *)(v85 + 2152));
    ucfg_pre_cac_set_freq(*(_QWORD *)(v85 + 32), v228);
    ucfg_pre_cac_adapter_set(*(_QWORD *)(v119 + 32), 1, v219, v220, v221, v222, v223, v224, v225, v226);
    if ( !v72 )
    {
LABEL_72:
      osif_vdev_sync_trans_stop((__int64)v227);
      result = 0;
      goto LABEL_46;
    }
LABEL_71:
    osif_vdev_sync_register(*(_QWORD *)(v110 + 32), v227);
    goto LABEL_72;
  }
  raw_spin_unlock(a1 + 4);
  v25 = v232;
  if ( !v232 )
    goto LABEL_31;
LABEL_12:
  v26 = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v27 = *(_QWORD *)(v25 + 32);
    if ( !strcmp((const char *)(v27 + 296), "precac") )
      break;
    hdd_adapter_dev_put_debug(v25, 0x3Cu, v28, v29, v30, v31, v32, v33, v34, v35);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v26 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v26 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 4);
    }
    else
    {
      raw_spin_lock_bh(a1 + 4);
      a1[5] |= 1uLL;
    }
    v232 = v228;
    hdd_get_next_adapter_no_lock((__int64)a1, v228, &v228);
    hdd_validate_next_adapter(&v232, &v228, 0x3Cu, v36, v37, v38, v39, v40, v41, v42, v43);
    if ( v228 )
      hdd_adapter_dev_hold_debug(v228, 0x3Cu, v44, v45, v46, v47, v48, v49, v50, v51, v52);
    v53 = a1[5];
    if ( (v53 & 1) != 0 )
    {
      a1[5] = v53 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 4);
      v25 = v232;
      if ( !v232 )
        goto LABEL_31;
    }
    else
    {
      raw_spin_unlock(a1 + 4);
      v25 = v232;
      if ( !v232 )
        goto LABEL_31;
    }
  }
  v54 = _osif_vdev_sync_trans_start(v27, (__int64)&v227, (__int64)"wlan_hdd_start_pre_cac_trans");
  hdd_adapter_dev_put_debug(v232, 0x3Cu, v55, v56, v57, v58, v59, v60, v61, v62);
  if ( v228 )
    hdd_adapter_dev_put_debug(v228, 0x3Cu, v63, v64, v65, v66, v67, v68, v69, v70);
  result = v54;
  if ( !v54 )
  {
    v72 = 0;
    goto LABEL_33;
  }
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
