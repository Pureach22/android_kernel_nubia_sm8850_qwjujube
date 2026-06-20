__int64 __fastcall hdd_dcs_cb(
        __int64 a1,
        unsigned int *a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v11; // w8
  const char *v12; // x2
  const char *v13; // x3
  __int64 result; // x0
  char v18; // w21
  unsigned int ll_lt_sap_freq; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  bool is_force_scc; // w0
  unsigned int v29; // w20
  bool v30; // w21
  char is_sta_gc_active_on_mac; // w0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  int v40; // w22
  __int64 link_info_by_vdev; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x19
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  unsigned int *v59; // x23
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // x21
  __int64 v69; // x22
  __int64 v70; // x0
  __int64 v71; // x20
  unsigned int usable_channel; // w0
  __int64 v73; // x4
  const char *v74; // x2
  unsigned int v75; // w1
  __int64 v76; // x0
  __int64 v77; // x0
  __int64 v78; // x0
  __int64 v79; // x0
  __int64 v80; // x9
  __int64 v81; // x8
  int *v82; // x11
  int v83; // t1
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  unsigned __int16 rand_from_lst_for_freq; // w0
  unsigned int v101; // w22
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  unsigned __int16 v110; // w0
  __int64 v111; // x9
  unsigned int v112; // w23
  unsigned int v113; // [xsp+Ch] [xbp-F4h] BYREF
  __int64 v114; // [xsp+10h] [xbp-F0h] BYREF
  __int64 v115; // [xsp+18h] [xbp-E8h] BYREF
  int v116; // [xsp+20h] [xbp-E0h] BYREF
  __int64 v117; // [xsp+28h] [xbp-D8h] BYREF
  __int64 v118; // [xsp+30h] [xbp-D0h]
  __int64 (__fastcall *v119)(); // [xsp+38h] [xbp-C8h]
  __int64 v120; // [xsp+40h] [xbp-C0h]
  __int64 v121; // [xsp+48h] [xbp-B8h]
  __int64 v122; // [xsp+50h] [xbp-B0h]
  __int64 v123; // [xsp+58h] [xbp-A8h]
  __int64 v124; // [xsp+60h] [xbp-A0h]
  __int64 v125; // [xsp+68h] [xbp-98h]
  __int64 v126; // [xsp+70h] [xbp-90h]
  __int64 v127; // [xsp+78h] [xbp-88h]
  __int64 v128; // [xsp+80h] [xbp-80h]
  __int64 v129; // [xsp+88h] [xbp-78h]
  __int64 v130; // [xsp+90h] [xbp-70h]
  __int64 v131; // [xsp+98h] [xbp-68h]
  __int64 v132; // [xsp+A0h] [xbp-60h]
  __int64 v133; // [xsp+A8h] [xbp-58h]
  __int64 v134; // [xsp+B0h] [xbp-50h]
  __int64 v135; // [xsp+B8h] [xbp-48h]
  __int64 v136; // [xsp+C0h] [xbp-40h]
  __int64 v137; // [xsp+C8h] [xbp-38h]
  __int64 v138; // [xsp+D0h] [xbp-30h]
  __int64 v139; // [xsp+D8h] [xbp-28h]
  __int64 v140; // [xsp+E0h] [xbp-20h]
  __int64 v141; // [xsp+E8h] [xbp-18h]
  int v142; // [xsp+F0h] [xbp-10h]
  __int64 v143; // [xsp+F8h] [xbp-8h]

  v143 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *((unsigned __int8 *)a2 + 5);
  v116 = 0;
  v114 = 0;
  v115 = 0;
  if ( v11 == 1 )
  {
    v12 = "%s: CW interference mitigation is not supported";
    v13 = "hdd_dcs_cb";
LABEL_3:
    result = qdf_trace_msg(0x33u, 8u, v12, a4, a5, a6, a7, a8, a9, a10, a11, v13);
    goto LABEL_46;
  }
  if ( policy_mgr_is_vdev_ll_lt_sap(a1, *((unsigned __int8 *)a2 + 4)) )
  {
    v18 = *((_BYTE *)a2 + 4);
    v119 = nullptr;
    v120 = 0;
    v117 = 0;
    v118 = 0;
    ll_lt_sap_freq = policy_mgr_get_ll_lt_sap_freq(a1);
    if ( ll_lt_sap_freq )
    {
      wlan_ll_lt_store_to_avoid_list_and_flush_old(a1, ll_lt_sap_freq, 1);
      LOBYTE(v117) = v18;
      HIDWORD(v117) = wlan_ll_lt_sap_bearer_switch_get_id(a1);
      v118 = 0x400000000LL;
      v119 = hdd_ll_lt_sap_acs_start_bearer_switch_requester_cb;
      v121 = a3;
      result = wlan_ll_lt_sap_switch_bearer_to_ble(a1, &v117);
      goto LABEL_46;
    }
    v12 = "%s: ll_lt_sap is not resent";
    v13 = "hdd_switch_bearer_to_ble_on_ll_lt_sap_acs_start";
    goto LABEL_3;
  }
  if ( policy_mgr_is_force_scc(a1) && (policy_mgr_is_sta_gc_active_on_mac(a1, *a2) & 1) != 0 )
  {
    ucfg_config_dcs_event_data(a1, *a2, 1, v20, v21, v22, v23, v24, v25, v26, v27);
    is_force_scc = policy_mgr_is_force_scc(a1);
    v29 = *a2;
    v30 = is_force_scc;
    is_sta_gc_active_on_mac = policy_mgr_is_sta_gc_active_on_mac(a1, v29);
    result = qdf_trace_msg(
               0x33u,
               8u,
               "%s: force scc %d, mac id %d sta gc count %d",
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               v38,
               v39,
               "hdd_dcs_cb",
               v30,
               v29,
               is_sta_gc_active_on_mac & 1);
    goto LABEL_46;
  }
  result = policy_mgr_get_sap_go_count_on_mac(a1, &v114, *a2);
  if ( !(_DWORD)result )
    goto LABEL_46;
  v40 = result;
  link_info_by_vdev = hdd_get_link_info_by_vdev(a3, v114);
  if ( !link_info_by_vdev )
  {
    v59 = (unsigned int *)&v114;
    goto LABEL_20;
  }
  v50 = link_info_by_vdev;
  result = wlansap_dcs_is_wlan_interference_mitigation_enabled(
             *(_QWORD *)(link_info_by_vdev + 272),
             v42,
             v43,
             v44,
             v45,
             v46,
             v47,
             v48,
             v49);
  if ( (result & 1) != 0 )
  {
    v59 = (unsigned int *)&v114;
    goto LABEL_14;
  }
  if ( v40 == 1 )
    goto LABEL_46;
  v59 = (unsigned int *)&v114 + 1;
  v76 = hdd_get_link_info_by_vdev(a3, SHIDWORD(v114));
  if ( !v76 )
    goto LABEL_20;
  v50 = v76;
  result = wlansap_dcs_is_wlan_interference_mitigation_enabled(
             *(_QWORD *)(v76 + 272),
             v42,
             v43,
             v44,
             v45,
             v46,
             v47,
             v48,
             v49);
  if ( (result & 1) != 0 )
    goto LABEL_14;
  if ( v40 == 2 )
    goto LABEL_46;
  v59 = (unsigned int *)&v115;
  v77 = hdd_get_link_info_by_vdev(a3, v115);
  if ( !v77 )
    goto LABEL_20;
  v50 = v77;
  result = wlansap_dcs_is_wlan_interference_mitigation_enabled(
             *(_QWORD *)(v77 + 272),
             v42,
             v43,
             v44,
             v45,
             v46,
             v47,
             v48,
             v49);
  if ( (result & 1) != 0 )
    goto LABEL_14;
  if ( v40 == 3 )
    goto LABEL_46;
  v59 = (unsigned int *)&v115 + 1;
  v78 = hdd_get_link_info_by_vdev(a3, SHIDWORD(v115));
  if ( !v78 )
    goto LABEL_20;
  v50 = v78;
  result = wlansap_dcs_is_wlan_interference_mitigation_enabled(
             *(_QWORD *)(v78 + 272),
             v42,
             v43,
             v44,
             v45,
             v46,
             v47,
             v48,
             v49);
  if ( (result & 1) != 0 )
    goto LABEL_14;
  if ( v40 == 4 )
    goto LABEL_46;
  v59 = (unsigned int *)&v116;
  v79 = hdd_get_link_info_by_vdev(a3, v116);
  if ( !v79 )
  {
LABEL_20:
    result = qdf_trace_msg(
               0x33u,
               2u,
               "%s: vdev_id %u does not exist with host",
               v42,
               v43,
               v44,
               v45,
               v46,
               v47,
               v48,
               v49,
               "hdd_dcs_cb",
               *v59);
    goto LABEL_46;
  }
  v50 = v79;
  result = wlansap_dcs_is_wlan_interference_mitigation_enabled(
             *(_QWORD *)(v79 + 272),
             v42,
             v43,
             v44,
             v45,
             v46,
             v47,
             v48,
             v49);
  if ( (result & 1) == 0 )
  {
    if ( v40 == 5 )
      goto LABEL_46;
    goto LABEL_34;
  }
LABEL_14:
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: DCS triggers ACS on vdev_id=%u, mac_id=%u",
    v51,
    v52,
    v53,
    v54,
    v55,
    v56,
    v57,
    v58,
    "hdd_dcs_cb",
    *v59,
    *a2);
  if ( !(unsigned int)wlan_mlme_get_ap_policy(*(_QWORD *)(v50 + 32), v60, v61, v62, v63, v64, v65, v66, v67) )
  {
LABEL_45:
    result = wlan_hdd_cfg80211_start_acs(v50);
    goto LABEL_46;
  }
  v68 = *(_QWORD *)(v50 + 32);
  v69 = *(_QWORD *)(a3 + 8);
  v142 = 0;
  v140 = 0;
  v141 = 0;
  v138 = 0;
  v139 = 0;
  v136 = 0;
  v137 = 0;
  v134 = 0;
  v135 = 0;
  v132 = 0;
  v133 = 0;
  v130 = 0;
  v131 = 0;
  v128 = 0;
  v129 = 0;
  v126 = 0;
  v127 = 0;
  v124 = 0;
  v125 = 0;
  v122 = 0;
  v123 = 0;
  v120 = 0;
  v121 = 0;
  v118 = 0;
  v119 = nullptr;
  v117 = 0;
  v113 = 0;
  v70 = _qdf_mem_malloc(0x990u, "hdd_dcs_select_random_chan", 203);
  if ( !v70 )
  {
LABEL_35:
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: res_msg invalid",
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      "hdd_dcs_select_random_chan");
    goto LABEL_45;
  }
  v71 = v70;
  usable_channel = wlan_reg_get_usable_channel(v69, 0x800000004uLL, 0, v70, &v113, 0);
  if ( usable_channel )
  {
    v73 = usable_channel;
    v74 = "%s: get usable channel failed %d";
    v75 = 2;
LABEL_43:
    qdf_trace_msg(0x33u, v75, v74, v51, v52, v53, v54, v55, v56, v57, v58, "hdd_dcs_select_random_chan", v73);
LABEL_44:
    _qdf_mem_free(v71);
    goto LABEL_45;
  }
  if ( v113 )
  {
    v80 = 2LL * v113;
    v81 = 0;
    v82 = (int *)v71;
    while ( v81 != 204 )
    {
      v83 = *v82;
      v82 += 6;
      *(_WORD *)((char *)&v117 + v81) = v83;
      v81 += 2;
      if ( v80 == v81 )
        goto LABEL_40;
    }
LABEL_34:
    __break(0x5512u);
    goto LABEL_35;
  }
LABEL_40:
  hdd_remove_vlp_depriority_channels(v69, (__int64)&v117, &v113, v51, v52, v53, v54, v55, v56, v57, v58);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: channel count %d for band %d",
    v84,
    v85,
    v86,
    v87,
    v88,
    v89,
    v90,
    v91,
    "hdd_dcs_select_random_chan",
    v113,
    2);
  rand_from_lst_for_freq = wlan_get_rand_from_lst_for_freq((__int64)&v117, v113, v92, v93, v94, v95, v96, v97, v98, v99);
  if ( !rand_from_lst_for_freq
    || (v101 = rand_from_lst_for_freq,
        rand_from_lst_for_freq > (unsigned int)(unsigned __int16)wlan_reg_max_6ghz_chan_freq()) )
  {
    v110 = wlan_reg_max_6ghz_chan_freq();
    v74 = "%s: ch freq gt max 6g freq %d";
    v73 = v110;
    v75 = 8;
    goto LABEL_43;
  }
  if ( !(_WORD)v113 )
    goto LABEL_44;
  v111 = 0;
  while ( *(_DWORD *)(v71 + v111) != v101 )
  {
    v111 += 24;
    if ( 24LL * (unsigned __int16)v113 == v111 )
      goto LABEL_44;
  }
  v112 = *(_DWORD *)(v71 + v111 + 12);
  if ( v112 >= 8 )
    goto LABEL_44;
  if ( v112 >= 4 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: restrict max bw to 160",
      v102,
      v103,
      v104,
      v105,
      v106,
      v107,
      v108,
      v109,
      "hdd_dcs_select_random_chan");
    v112 = 3;
  }
  _qdf_mem_free(v71);
  result = ucfg_dcs_switch_chan(v68, v101, v112);
  if ( (_DWORD)result )
    goto LABEL_45;
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
