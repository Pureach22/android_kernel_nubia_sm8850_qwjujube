__int64 __fastcall policy_mgr_is_restart_sap_required(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        int a4,
        unsigned int a5)
{
  __int64 context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w28
  __int64 v20; // x19
  char is_ll_lt_sap_restart_required; // w26
  const char *v22; // x2
  unsigned int v23; // w1
  __int64 v25; // x0
  unsigned int *v26; // x8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned __int8 v43; // w22
  char v44; // w26
  char v45; // w27
  bool v46; // w21
  bool is_24ghz_ch_freq; // w0
  bool is_sta_sap_scc_allowed_on_dfs_chan; // w27
  __int64 v49; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  bool v58; // w8
  int v59; // w21
  __int64 v60; // x22
  int *v61; // x24
  int v62; // w8
  unsigned int v63; // w27
  int v64; // w28
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  int v73; // w21
  __int64 v74; // x25
  char *v75; // x21
  unsigned int v76; // w2
  unsigned int user_config_sap_freq; // w27
  bool v78; // w0
  __int64 v79; // x5
  bool is_5ghz_ch_freq; // w0
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  bool v89; // w0
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  int v106; // w8
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  char is_chan_eligible_for_sap; // w0
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  const char *v124; // x2
  __int64 v125; // x4
  const char *v126; // x2
  unsigned int v127; // [xsp+Ch] [xbp-44h]
  unsigned int v128; // [xsp+10h] [xbp-40h]
  char v129; // [xsp+14h] [xbp-3Ch]
  bool v130; // [xsp+18h] [xbp-38h]
  unsigned int v131; // [xsp+1Ch] [xbp-34h]
  int v132; // [xsp+20h] [xbp-30h]
  int v133; // [xsp+24h] [xbp-2Ch]
  _QWORD v134[2]; // [xsp+28h] [xbp-28h] BYREF
  __int64 v135; // [xsp+38h] [xbp-18h]
  __int64 v136; // [xsp+40h] [xbp-10h]
  __int64 v137; // [xsp+48h] [xbp-8h]

  v137 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v135 = 0;
  v136 = 0;
  v134[0] = 0;
  v134[1] = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v22 = "%s: Invalid psoc";
    v23 = 2;
LABEL_9:
    qdf_trace_msg(0x4Fu, v23, v22, v11, v12, v13, v14, v15, v16, v17, v18, "policy_mgr_is_restart_sap_required");
LABEL_10:
    is_ll_lt_sap_restart_required = 0;
    goto LABEL_11;
  }
  v19 = (unsigned __int8)a2;
  v20 = context;
  if ( (policy_mgr_is_vdev_ll_lt_sap(a1, (unsigned __int8)a2) & 1) != 0 )
  {
    is_ll_lt_sap_restart_required = _policy_mgr_is_ll_lt_sap_restart_required(a1, "policy_mgr_is_restart_sap_required");
    goto LABEL_11;
  }
  if ( !a4 )
  {
    v22 = "%s: No scc required";
    v23 = 8;
    goto LABEL_9;
  }
  if ( (wlan_nan_is_disc_active(a1) & 1) != 0 )
  {
    is_ll_lt_sap_restart_required = (unsigned int)policy_mgr_get_sap_scc_freq_nan_present(a1) != a3;
    goto LABEL_11;
  }
  v25 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 24);
  if ( v25 )
    wlan_objmgr_vdev_release_ref(v25, 0x18u, v26, v27, v28, v29, v30, v31, v32, v33, v34);
  qdf_mutex_acquire(v20 + 56);
  v133 = a4;
  v131 = a2;
  if ( BYTE4(qword_81C458) == 1 )
  {
    if ( (_DWORD)qword_81C458 == (unsigned __int8)a2 )
    {
      if ( wlan_reg_is_5ghz_ch_freq(HIDWORD(pm_conc_connection_list)) )
      {
        v43 = 0;
        v44 = 0;
        v132 = 0;
        v45 = 1;
        v46 = (qword_81C458 & 0x6000000000000LL) != 0;
      }
      else
      {
        v46 = 0;
        v43 = 0;
        v44 = 0;
        v132 = 0;
        v45 = 1;
      }
    }
    else
    {
      v43 = HIDWORD(pm_conc_connection_list) != a3;
      v44 = HIDWORD(pm_conc_connection_list) == a3;
      v46 = 0;
      v45 = 0;
      v132 = !wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list));
    }
  }
  else
  {
    v46 = 0;
    v45 = 0;
    v43 = 0;
    v44 = 0;
    v132 = 0;
  }
  if ( BYTE4(qword_81C47C) == 1 )
  {
    if ( (_DWORD)qword_81C47C == v19 )
    {
      if ( wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_81C464)) && (qword_81C47C & 0x6000000000000LL) != 0 )
        v46 = 1;
      v45 = 1;
    }
    else
    {
      if ( HIDWORD(qword_81C464) == a3 )
        ++v44;
      else
        ++v43;
      v132 += !wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C464));
    }
  }
  if ( BYTE4(qword_81C4A0) == 1 )
  {
    if ( (_DWORD)qword_81C4A0 == v19 )
    {
      if ( wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_81C488)) && (qword_81C4A0 & 0x6000000000000LL) != 0 )
        v46 = 1;
      v45 = 1;
    }
    else
    {
      if ( HIDWORD(qword_81C488) == a3 )
        ++v44;
      else
        ++v43;
      v132 += !wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C488));
    }
  }
  if ( BYTE4(qword_81C4C4) == 1 )
  {
    if ( (_DWORD)qword_81C4C4 == v19 )
    {
      if ( wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_81C4AC)) && (qword_81C4C4 & 0x6000000000000LL) != 0 )
        v46 = 1;
      v45 = 1;
    }
    else
    {
      if ( HIDWORD(qword_81C4AC) == a3 )
        ++v44;
      else
        ++v43;
      v132 += !wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C4AC));
    }
  }
  if ( BYTE4(qword_81C4E8) != 1 )
  {
    if ( (v45 & 1) != 0 )
      goto LABEL_63;
    goto LABEL_66;
  }
  if ( (_DWORD)qword_81C4E8 == v19 )
  {
    if ( wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_81C4D0)) && (qword_81C4E8 & 0x6000000000000LL) != 0 )
      v46 = 1;
    goto LABEL_63;
  }
  if ( HIDWORD(qword_81C4D0) == a3 )
    ++v44;
  else
    ++v43;
  is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C4D0));
  if ( (v45 & 1) == 0 )
  {
LABEL_66:
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid vdev id: %d",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "policy_mgr_is_restart_sap_required",
      v19);
    qdf_mutex_release(v20 + 56);
    goto LABEL_10;
  }
  v132 += !is_24ghz_ch_freq;
LABEL_63:
  if ( v43 >= 2u && !v44 )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: sap vdev %d has chan %d diff with %d exsting conn",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "policy_mgr_is_restart_sap_required",
      v19,
      a3,
      v43);
    qdf_mutex_release(v20 + 56);
    is_ll_lt_sap_restart_required = 1;
    goto LABEL_11;
  }
  is_sta_sap_scc_allowed_on_dfs_chan = policy_mgr_is_sta_sap_scc_allowed_on_dfs_chan(a1);
  v49 = policy_mgr_get_context(a1);
  if ( v49 )
  {
    v129 = *(_BYTE *)(v49 + 2214);
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: pm_ctx is NULL",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "policy_mgr_get_sta_sap_scc_allowed_on_indoor_chnl");
    v129 = 0;
  }
  v58 = !v46;
  v59 = v133;
  v60 = 0;
  is_ll_lt_sap_restart_required = 0;
  v127 = v19;
  v128 = a5;
  v130 = is_sta_sap_scc_allowed_on_dfs_chan || v58;
  while ( 1 )
  {
    v61 = (int *)((char *)&pm_conc_connection_list + v60);
    if ( *((_BYTE *)&pm_conc_connection_list + v60 + 28) != 1 )
      goto LABEL_73;
    v62 = *v61;
    if ( v59 == 4 && v62 == 3 )
    {
      if ( *(_DWORD *)((char *)&pm_conc_connection_list + v60 + 24) == v19 )
        goto LABEL_73;
      v63 = *(_DWORD *)((char *)&pm_conc_connection_list + v60 + 4);
      v64 = policy_mgr_2_freq_same_mac_in_dbs(a1, a3, v63);
      if ( (v64 & 1) != 0 )
        v73 = policy_mgr_2_freq_same_mac_in_sbs(a1, a3, v63);
      else
        v73 = 1;
      v74 = jiffies;
      if ( policy_mgr_2_freq_always_on_same_mac___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: freq1 %d freq2 %d: Same mac:: DBS:%d SBS:%d",
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          "policy_mgr_2_freq_always_on_same_mac",
          a3,
          v63,
          v64 & 1,
          v73 & 1);
        policy_mgr_2_freq_always_on_same_mac___last_ticks = v74;
      }
      if ( (v64 & v73 & 1) != 0 )
      {
        v124 = "%s: SAP:%d and GO:%d on same mac. Restart SAP ";
        goto LABEL_120;
      }
      v19 = v127;
      a5 = v128;
      v62 = *v61;
      v59 = v133;
    }
    if ( (v62 | 2) != 2 )
      goto LABEL_73;
    v75 = (char *)&pm_conc_connection_list + v60;
    v76 = *(_DWORD *)((char *)&pm_conc_connection_list + v60 + 4);
    if ( v76 != a3 && (policy_mgr_are_2_freq_on_same_mac(a1, a3, v76) & 1) != 0 )
    {
      v124 = "%s: SAP:%d and STA:%d on same mac. Restart SAP ";
LABEL_120:
      v125 = a3;
LABEL_121:
      qdf_trace_msg(0x4Fu, 8u, v124, v65, v66, v67, v68, v69, v70, v71, v72, "policy_mgr_is_restart_sap_required", v125);
      goto LABEL_124;
    }
    if ( !(unsigned int)wlan_get_chan_by_vdev_id(a1, *((unsigned int *)v75 + 6), v134)
      && (_DWORD)v136 == 7
      && HIDWORD(v135) != a5 )
    {
      v124 = "%s: 320M CCFS2 %d conc %d";
      v125 = a5;
      goto LABEL_121;
    }
    if ( *((_DWORD *)v75 + 1) == a3 && !v130 )
    {
      v126 = "%s: Move SAP out of DFS ch:%d";
      goto LABEL_123;
    }
    if ( !((*((_DWORD *)v75 + 1) != a3) | v129 & 1) && (wlan_reg_is_freq_indoor() & 1) != 0 )
    {
      v126 = "%s: Move SAP out of indoor ch:%d";
LABEL_123:
      qdf_trace_msg(0x4Fu, 8u, v126, v65, v66, v67, v68, v69, v70, v71, v72, "policy_mgr_is_restart_sap_required", a3);
LABEL_124:
      is_ll_lt_sap_restart_required = 1;
      goto LABEL_125;
    }
    user_config_sap_freq = policy_mgr_get_user_config_sap_freq(a1, v131);
    if ( *((_DWORD *)v75 + 1) != a3 )
      break;
LABEL_105:
    if ( v133 == 4 && wlan_reg_is_24ghz_ch_freq(a3) && user_config_sap_freq )
    {
      v106 = *((_DWORD *)v75 + 1);
      if ( v106 != a3 || v132 )
        goto LABEL_112;
      if ( wlan_reg_is_24ghz_ch_freq(user_config_sap_freq) )
      {
        v106 = *((_DWORD *)v75 + 1);
LABEL_112:
        if ( v106 != a3 && wlan_reg_is_6ghz_chan_freq(user_config_sap_freq) )
        {
          is_chan_eligible_for_sap = policy_mgr_is_chan_eligible_for_sap(
                                       v20,
                                       *((unsigned int *)v75 + 6),
                                       *((unsigned int *)v75 + 1));
          v59 = 4;
          if ( (is_chan_eligible_for_sap & 1) != 0 )
          {
            qdf_trace_msg(
              0x4Fu,
              8u,
              "%s: Move SAP to STA 6 GHz channel",
              v116,
              v117,
              v118,
              v119,
              v120,
              v121,
              v122,
              v123,
              "policy_mgr_is_restart_sap_required");
            is_ll_lt_sap_restart_required = 1;
          }
          goto LABEL_73;
        }
        goto LABEL_72;
      }
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: SAP move to user configure %d from %d",
        v107,
        v108,
        v109,
        v110,
        v111,
        v112,
        v113,
        v114,
        "policy_mgr_is_restart_sap_required",
        user_config_sap_freq,
        a3);
      is_ll_lt_sap_restart_required = 1;
    }
LABEL_72:
    v59 = v133;
LABEL_73:
    v60 += 36;
    if ( v60 == 180 )
      goto LABEL_125;
  }
  v78 = wlan_reg_is_24ghz_ch_freq(a3);
  LODWORD(v79) = *((_DWORD *)v75 + 1);
  if ( !v78 || (is_5ghz_ch_freq = wlan_reg_is_5ghz_ch_freq(v79), LODWORD(v79) = *((_DWORD *)v75 + 1), !is_5ghz_ch_freq) )
  {
LABEL_100:
    if ( (_DWORD)v79 != a3
      && wlan_reg_is_24ghz_ch_freq(v79)
      && wlan_reg_is_5ghz_ch_freq(a3)
      && (policy_mgr_is_sap_go_interface_allowed_on_indoor(*(_QWORD *)(v20 + 8), v131, a3) & 1) == 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: SAP in indoor freq: sta:%d sap:%d",
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        v105,
        "policy_mgr_is_restart_sap_required",
        *((unsigned int *)v75 + 1),
        a3);
      is_ll_lt_sap_restart_required = 1;
    }
    goto LABEL_105;
  }
  if ( (wlan_reg_is_dfs_for_freq(*(_QWORD *)(v20 + 8), v79, v81, v82, v83, v84, v85, v86, v87, v88) & 1) != 0 )
  {
    LODWORD(v79) = *((_DWORD *)v75 + 1);
    goto LABEL_100;
  }
  v89 = wlan_reg_is_5ghz_ch_freq(user_config_sap_freq);
  v79 = *((unsigned int *)v75 + 1);
  if ( !v89 )
    goto LABEL_100;
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: Move SAP from:%d to STA ch:%d  (sap start freq:%d)",
    v90,
    v91,
    v92,
    v93,
    v94,
    v95,
    v96,
    v97,
    "policy_mgr_is_restart_sap_required",
    a3,
    v79,
    user_config_sap_freq);
  is_ll_lt_sap_restart_required = wlan_reg_is_freq_indoor() ^ 1 | v129;
LABEL_125:
  qdf_mutex_release(v20 + 56);
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return is_ll_lt_sap_restart_required & 1;
}
