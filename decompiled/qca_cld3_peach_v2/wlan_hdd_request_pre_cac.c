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
  __int64 v98; // x1
  __int64 v99; // x2
  __int64 v100; // x3
  __int64 v101; // x0
  unsigned int max_bw_by_phymode; // w0
  unsigned int v103; // w21
  __int64 adapter_by_iface_name; // x0
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  _DWORD *v113; // x21
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  __int64 v122; // x22
  unsigned __int8 *v123; // x20
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  __int64 intf_addr; // x0
  double v133; // d0
  double v134; // d1
  double v135; // d2
  double v136; // d3
  double v137; // d4
  double v138; // d5
  double v139; // d6
  double v140; // d7
  double v141; // d0
  double v142; // d1
  double v143; // d2
  double v144; // d3
  double v145; // d4
  double v146; // d5
  double v147; // d6
  double v148; // d7
  double v149; // d0
  double v150; // d1
  double v151; // d2
  double v152; // d3
  double v153; // d4
  double v154; // d5
  double v155; // d6
  double v156; // d7
  __int64 v157; // x0
  __int64 v158; // x23
  __int64 v159; // x24
  void *v160; // x0
  __int64 v161; // x1
  __int64 v162; // x2
  __int64 v163; // x3
  double v164; // d0
  double v165; // d1
  double v166; // d2
  double v167; // d3
  double v168; // d4
  double v169; // d5
  double v170; // d6
  double v171; // d7
  unsigned int v172; // w0
  int v173; // w8
  double v174; // d0
  double v175; // d1
  double v176; // d2
  double v177; // d3
  double v178; // d4
  double v179; // d5
  double v180; // d6
  double v181; // d7
  double v182; // d0
  double v183; // d1
  double v184; // d2
  double v185; // d3
  double v186; // d4
  double v187; // d5
  double v188; // d6
  double v189; // d7
  double v190; // d0
  double v191; // d1
  double v192; // d2
  double v193; // d3
  double v194; // d4
  double v195; // d5
  double v196; // d6
  double v197; // d7
  double v198; // d0
  double v199; // d1
  double v200; // d2
  double v201; // d3
  double v202; // d4
  double v203; // d5
  double v204; // d6
  double v205; // d7
  double v206; // d0
  double v207; // d1
  double v208; // d2
  double v209; // d3
  double v210; // d4
  double v211; // d5
  double v212; // d6
  double v213; // d7
  const char *v214; // x2
  int v215; // w22
  double v216; // d0
  double v217; // d1
  double v218; // d2
  double v219; // d3
  double v220; // d4
  double v221; // d5
  double v222; // d6
  double v223; // d7
  __int64 v224; // x0
  double v225; // d0
  double v226; // d1
  double v227; // d2
  double v228; // d3
  double v229; // d4
  double v230; // d5
  double v231; // d6
  double v232; // d7
  __int64 *v233; // [xsp+8h] [xbp-48h] BYREF
  __int64 v234; // [xsp+10h] [xbp-40h] BYREF
  int v235; // [xsp+1Ch] [xbp-34h] BYREF
  unsigned int v236; // [xsp+20h] [xbp-30h] BYREF
  unsigned int v237; // [xsp+24h] [xbp-2Ch] BYREF
  __int64 v238; // [xsp+28h] [xbp-28h] BYREF
  __int64 v239; // [xsp+30h] [xbp-20h]
  __int64 v240; // [xsp+38h] [xbp-18h]
  __int64 v241; // [xsp+40h] [xbp-10h]
  __int64 v242; // [xsp+48h] [xbp-8h]

  v242 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v233 = nullptr;
  v234 = 0;
  v238 = 0;
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
  hdd_get_front_adapter_no_lock((__int64)a1, &v238);
  if ( v238 )
  {
    hdd_adapter_dev_hold_debug(v238, 0x3Cu, v5, v6, v7, v8, v9, v10, v11, v12, v13);
    v14 = v238;
  }
  else
  {
    v14 = 0;
  }
  hdd_get_next_adapter_no_lock((__int64)a1, v14, &v234);
  if ( v234 )
    hdd_adapter_dev_hold_debug(v234, 0x3Cu, v15, v16, v17, v18, v19, v20, v21, v22, v23);
  v24 = a1[5];
  if ( (v24 & 1) != 0 )
  {
    a1[5] = v24 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 4);
    v25 = v238;
    if ( v238 )
      goto LABEL_12;
LABEL_31:
    result = _osif_vdev_sync_create_and_trans(a1[12], &v233, (__int64)"wlan_hdd_start_pre_cac_trans");
    if ( (_DWORD)result )
      goto LABEL_46;
    v72 = 1;
LABEL_33:
    v73 = *a1;
    LODWORD(v234) = 0;
    v240 = 0;
    v241 = 0;
    v238 = 0;
    v239 = 0;
    v235 = 0;
    if ( (policy_mgr_is_hw_dbs_capable(v73) & 1) == 0 )
    {
      v82 = "%s: Pre CAC is not supported on non-dbs platforms";
      v83 = 8;
LABEL_42:
      qdf_trace_msg(0x33u, v83, v82, v74, v75, v76, v77, v78, v79, v80, v81, "__wlan_hdd_request_pre_cac");
LABEL_43:
      osif_vdev_sync_trans_stop((__int64)v233);
      if ( v72 )
        osif_vdev_sync_destroy((__int64)v233);
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
    v85 = *(_QWORD *)(adapter + 52832);
    if ( *(_DWORD *)(v85 + 2620) )
    {
      v82 = "%s: pre cac not allowed during CSA";
      goto LABEL_41;
    }
    v86 = a1[2];
    is_dfs_for_freq = wlan_reg_is_dfs_for_freq(a1[1], *(_DWORD *)(v85 + 2424), v74, v75, v76, v77, v78, v79, v80, v81);
    v96 = *(unsigned int *)(v85 + 2424);
    if ( (is_dfs_for_freq & 1) != 0 )
    {
      v97 = "%s: SAP is already on DFS channel:%d";
LABEL_57:
      qdf_trace_msg(0x33u, 2u, v97, v88, v89, v90, v91, v92, v93, v94, v95, "__wlan_hdd_request_pre_cac", v96);
      goto LABEL_43;
    }
    if ( !wlan_reg_is_24ghz_ch_freq(v96) )
    {
      v96 = *(unsigned int *)(v85 + 2424);
      v97 = "%s: pre CAC allowed only when SAP is in 2.4GHz:%d";
      goto LABEL_57;
    }
    v101 = *(_QWORD *)(v85 + 272);
    v237 = 0;
    max_bw_by_phymode = wlansap_get_max_bw_by_phymode(v101, v98, v99, v100, v88, v89, v90, v91, v92, v93, v94, v95);
    if ( max_bw_by_phymode >= 2 )
      v103 = 2;
    else
      v103 = max_bw_by_phymode;
    v236 = v103;
    if ( a2 )
    {
      qdf_mem_set(&v238, 0x20u, 0);
      if ( (unsigned int)wlan_set_def_pre_cac_chan(a1, a2, &v238, &v237, &v236) )
      {
        v97 = "%s: failed to set pre_cac channel %d";
        v96 = a2;
        goto LABEL_57;
      }
      v103 = v236;
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
      v103);
    if ( (unsigned int)ucfg_pre_cac_validate_and_get_freq(a1[1], a2, (unsigned int *)&v234, v103) )
    {
      v82 = "%s: can't validate pre-cac channel";
      goto LABEL_41;
    }
    adapter_by_iface_name = hdd_get_adapter_by_iface_name((__int64)a1, "precac");
    if ( adapter_by_iface_name )
    {
      v113 = (_DWORD *)adapter_by_iface_name;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: pre cac SAP adapter is present",
        v105,
        v106,
        v107,
        v108,
        v109,
        v110,
        v111,
        v112,
        "__wlan_hdd_request_pre_cac");
      v122 = *((_QWORD *)v113 + 6604);
      if ( (*(_QWORD *)(v122 + 5968) & 1) != 0 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: pre cac is on-going",
          v114,
          v115,
          v116,
          v117,
          v118,
          v119,
          v120,
          v121,
          "__wlan_hdd_request_pre_cac");
        v113 = nullptr;
        if ( !v72 )
          goto LABEL_72;
        goto LABEL_71;
      }
      v123 = nullptr;
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: starting pre cac SAP  adapter",
        v105,
        v106,
        v107,
        v108,
        v109,
        v110,
        v111,
        v112,
        "__wlan_hdd_request_pre_cac");
      intf_addr = wlan_hdd_get_intf_addr((__int64)a1, 1, v124, v125, v126, v127, v128, v129, v130, v131);
      if ( !intf_addr )
      {
        v82 = "%s: can't add virtual intf: Not getting valid mac addr";
        goto LABEL_41;
      }
      v123 = (unsigned __int8 *)intf_addr;
      v235 = 520;
      if ( !(unsigned int)rtnl_trylock(intf_addr)
        || (v113 = hdd_open_adapter(a1, 1u, "precac", v123, 0, 1, &v235, v133, v134, v135, v136, v137, v138, v139, v140),
            rtnl_unlock(v113),
            !v113) )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: error opening the pre cac adapter",
          v133,
          v134,
          v135,
          v136,
          v137,
          v138,
          v139,
          v140,
          "__wlan_hdd_request_pre_cac");
LABEL_95:
        wlan_hdd_release_intf_addr((__int64)a1, v123, v182, v183, v184, v185, v186, v187, v188, v189);
        goto LABEL_43;
      }
      v122 = *((_QWORD *)v113 + 6604);
    }
    sap_clear_global_dfs_param(v86, *(_QWORD *)(v122 + 272));
    if ( (unsigned int)hdd_start_adapter((__int64)v113, v141, v142, v143, v144, v145, v146, v147, v148) )
    {
      v157 = qdf_trace_msg(
               0x33u,
               2u,
               "%s: error starting the pre cac adapter",
               v149,
               v150,
               v151,
               v152,
               v153,
               v154,
               v155,
               v156,
               "__wlan_hdd_request_pre_cac");
      goto LABEL_92;
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: preparing for start ap/bss on the pre cac adapter",
      v149,
      v150,
      v151,
      v152,
      v153,
      v154,
      v155,
      v156,
      "__wlan_hdd_request_pre_cac");
    v158 = a1[3];
    v159 = *((_QWORD *)v113 + 4);
    v160 = (void *)_qdf_mem_malloc(0x38u, "__wlan_hdd_request_pre_cac", 370);
    *(_QWORD *)(v122 + 2432) = v160;
    if ( !v160 )
      goto LABEL_91;
    qdf_mem_copy(v160, *(const void **)(v85 + 2432), 0x38u);
    *(_DWORD *)(v122 + 1276) = *(_DWORD *)(v85 + 1276);
    *(_DWORD *)(v122 + 752) = *(_DWORD *)(v85 + 752);
    v172 = wlansap_get_max_bw_by_phymode(
             *(_QWORD *)(v85 + 272),
             v161,
             v162,
             v163,
             v164,
             v165,
             v166,
             v167,
             v168,
             v169,
             v170,
             v171);
    if ( v172 >= 2 )
      v173 = 2;
    else
      v173 = v172;
    v236 = v173;
    qdf_mem_set(&v238, 0x20u, 0);
    if ( (unsigned int)wlan_set_def_pre_cac_chan(a1, (unsigned int)v234, &v238, &v237, &v236) )
    {
      v157 = qdf_trace_msg(
               0x33u,
               2u,
               "%s: error set pre_cac channel %d",
               v174,
               v175,
               v176,
               v177,
               v178,
               v179,
               v180,
               v181,
               "__wlan_hdd_request_pre_cac",
               (unsigned int)v234);
      goto LABEL_92;
    }
    *(_DWORD *)(v122 + 752) = hdd_map_nl_chan_width(v239);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: existing ap phymode:%d pre cac ch_width:%d freq:%d",
      v190,
      v191,
      v192,
      v193,
      v194,
      v195,
      v196,
      v197,
      "__wlan_hdd_request_pre_cac",
      *(unsigned int *)(v85 + 320),
      v236,
      (unsigned int)v234);
    if ( (unsigned int)policy_mgr_update_and_wait_for_connection_update(
                         *a1,
                         *(_BYTE *)(v85 + 8),
                         v234,
                         9u,
                         v198,
                         v199,
                         v200,
                         v201,
                         v202,
                         v203,
                         v204,
                         v205) )
    {
      v214 = "%s: error in moving to DBS mode";
LABEL_90:
      qdf_trace_msg(0x33u, 2u, v214, v206, v207, v208, v209, v210, v211, v212, v213, "__wlan_hdd_request_pre_cac");
LABEL_91:
      *((_BYTE *)v113 + 52797) = 1;
      hdd_stop_adapter(a1, (__int64)v113);
      v157 = _qdf_mem_free(*(_QWORD *)(v122 + 2432));
      *(_QWORD *)(v122 + 2432) = 0;
LABEL_92:
      v215 = rtnl_trylock(v157);
      v224 = hdd_close_adapter(a1, (__int64)v113, 1, v216, v217, v218, v219, v220, v221, v222, v223);
      if ( v215 )
        rtnl_unlock(v224);
      if ( !v123 )
        goto LABEL_43;
      goto LABEL_95;
    }
    if ( (unsigned int)wlan_hdd_set_channel(
                         v122,
                         v206,
                         v207,
                         v208,
                         v209,
                         v210,
                         v211,
                         v212,
                         v213,
                         v158,
                         v159,
                         (unsigned int *)&v238,
                         v237) )
    {
      v214 = "%s: failed to set channel";
      goto LABEL_90;
    }
    if ( (unsigned int)wlan_hdd_cfg80211_start_bss(
                         v122,
                         v206,
                         v207,
                         v208,
                         v209,
                         v210,
                         v211,
                         v212,
                         v213,
                         0,
                         "pre_cac_ssid",
                         12,
                         0,
                         0) )
    {
      v214 = "%s: start bss failed";
      goto LABEL_90;
    }
    if ( (unsigned int)ucfg_pre_cac_set_status(*(_QWORD *)(v122 + 32), 1) )
    {
      v214 = "%s: failed to set pre cac status";
      goto LABEL_90;
    }
    ucfg_pre_cac_clear_work(*a1);
    ucfg_pre_cac_set_freq_before_pre_cac(*(_QWORD *)(v85 + 32), *(_DWORD *)(v85 + 2424));
    ucfg_pre_cac_set_freq(*(_QWORD *)(v85 + 32), v234);
    ucfg_pre_cac_adapter_set(*(_QWORD *)(v122 + 32), 1, v225, v226, v227, v228, v229, v230, v231, v232);
    if ( !v72 )
    {
LABEL_72:
      osif_vdev_sync_trans_stop((__int64)v233);
      result = 0;
      goto LABEL_46;
    }
LABEL_71:
    osif_vdev_sync_register(*((_QWORD *)v113 + 4), v233);
    goto LABEL_72;
  }
  raw_spin_unlock(a1 + 4);
  v25 = v238;
  if ( !v238 )
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
    v238 = v234;
    hdd_get_next_adapter_no_lock((__int64)a1, v234, &v234);
    hdd_validate_next_adapter(&v238, &v234, 0x3Cu, v36, v37, v38, v39, v40, v41, v42, v43);
    if ( v234 )
      hdd_adapter_dev_hold_debug(v234, 0x3Cu, v44, v45, v46, v47, v48, v49, v50, v51, v52);
    v53 = a1[5];
    if ( (v53 & 1) != 0 )
    {
      a1[5] = v53 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 4);
      v25 = v238;
      if ( !v238 )
        goto LABEL_31;
    }
    else
    {
      raw_spin_unlock(a1 + 4);
      v25 = v238;
      if ( !v238 )
        goto LABEL_31;
    }
  }
  v54 = _osif_vdev_sync_trans_start(v27, (__int64)&v233, (__int64)"wlan_hdd_start_pre_cac_trans");
  hdd_adapter_dev_put_debug(v238, 0x3Cu, v55, v56, v57, v58, v59, v60, v61, v62);
  if ( v234 )
    hdd_adapter_dev_put_debug(v234, 0x3Cu, v63, v64, v65, v66, v67, v68, v69, v70);
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
