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
  __int64 v19; // x19
  char is_ll_lt_sap_restart_required; // w0
  const char *v21; // x2
  unsigned int v22; // w1
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int *v33; // x8
  __int64 v34; // x26
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned __int8 v43; // w26
  unsigned __int8 v44; // w28
  char v45; // w27
  char v46; // w8
  char v47; // w8
  char v48; // w8
  char v49; // w8
  bool is_24ghz_ch_freq; // w0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  bool is_sta_sap_scc_allowed_on_dfs_chan; // w28
  __int64 v60; // x26
  int *v61; // x27
  int v62; // w8
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  char *v71; // x27
  unsigned int v72; // w2
  unsigned int user_config_sap_freq; // w28
  bool v74; // w0
  __int64 v75; // x5
  bool is_5ghz_ch_freq; // w0
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  bool v85; // w0
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  int v102; // w8
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  char is_restart_sap_required_with_mlo_sta; // w20
  const char *v120; // x2
  __int64 v121; // x4
  const char *v122; // x2
  __int64 v123; // [xsp+0h] [xbp-40h]
  char is_mlo_vdev; // [xsp+4h] [xbp-3Ch]
  __int64 v125; // [xsp+8h] [xbp-38h]
  char v126; // [xsp+8h] [xbp-38h]
  _QWORD v127[2]; // [xsp+10h] [xbp-30h] BYREF
  __int64 v128; // [xsp+20h] [xbp-20h]
  __int64 v129; // [xsp+28h] [xbp-18h]
  __int64 v130; // [xsp+30h] [xbp-10h]
  __int64 v131; // [xsp+38h] [xbp-8h]

  v131 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v129 = 0;
  v130 = 0;
  v127[1] = 0;
  v128 = 0;
  v127[0] = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v21 = "%s: Invalid psoc";
    v22 = 2;
LABEL_9:
    qdf_trace_msg(0x4Fu, v22, v21, v11, v12, v13, v14, v15, v16, v17, v18, "policy_mgr_is_restart_sap_required");
LABEL_10:
    is_ll_lt_sap_restart_required = 0;
    goto LABEL_11;
  }
  v19 = context;
  if ( (policy_mgr_is_vdev_ll_lt_sap(a1, (unsigned __int8)a2) & 1) != 0 )
  {
    is_ll_lt_sap_restart_required = _policy_mgr_is_ll_lt_sap_restart_required(a1, "policy_mgr_is_restart_sap_required");
    goto LABEL_11;
  }
  if ( !a4 )
  {
    v21 = "%s: No scc required";
    v22 = 8;
    goto LABEL_9;
  }
  if ( (wlan_nan_is_disc_active(a1) & 1) != 0 )
  {
    is_ll_lt_sap_restart_required = (unsigned int)policy_mgr_get_sap_scc_freq_nan_present(a1) != a3;
    goto LABEL_11;
  }
  v24 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 24);
  if ( v24 )
  {
    v33 = (unsigned int *)*(unsigned int *)(v24 + 16);
    if ( (_DWORD)v33 == 1 )
    {
      v34 = v24;
      is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(v24, v25, v26, v27, v28, v29, v30, v31, v32);
      v24 = v34;
    }
    else
    {
      is_mlo_vdev = 0;
    }
    wlan_objmgr_vdev_release_ref(v24, 0x18u, v33, v25, v26, v27, v28, v29, v30, v31, v32);
  }
  else
  {
    is_mlo_vdev = 0;
  }
  qdf_mutex_acquire(v19 + 56);
  if ( BYTE4(qword_8D4F00) == 1 )
  {
    if ( (_DWORD)qword_8D4F00 == (unsigned __int8)a2 )
    {
      if ( wlan_reg_is_5ghz_ch_freq(HIDWORD(pm_conc_connection_list)) )
      {
        v43 = 0;
        v44 = 0;
        v45 = 1;
        v125 = (qword_8D4F00 & 0x6000000000000LL) != 0;
      }
      else
      {
        v125 = 0;
        v43 = 0;
        v44 = 0;
        v45 = 1;
      }
    }
    else
    {
      v43 = HIDWORD(pm_conc_connection_list) != a3;
      v44 = HIDWORD(pm_conc_connection_list) == a3;
      v45 = 0;
      LOBYTE(v125) = 0;
      HIDWORD(v125) = !wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list));
    }
  }
  else
  {
    v125 = 0;
    v45 = 0;
    v43 = 0;
    v44 = 0;
  }
  if ( BYTE4(qword_8D4F24) == 1 )
  {
    if ( (_DWORD)qword_8D4F24 == (unsigned __int8)a2 )
    {
      if ( wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_8D4F0C)) )
      {
        v46 = v125;
        if ( (qword_8D4F24 & 0x6000000000000LL) != 0 )
          v46 = 1;
        LOBYTE(v125) = v46;
      }
      v45 = 1;
    }
    else
    {
      if ( HIDWORD(qword_8D4F0C) == a3 )
        ++v44;
      else
        ++v43;
      HIDWORD(v125) += !wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F0C));
    }
  }
  if ( BYTE4(qword_8D4F48) == 1 )
  {
    if ( (_DWORD)qword_8D4F48 == (unsigned __int8)a2 )
    {
      if ( wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_8D4F30)) )
      {
        v47 = v125;
        if ( (qword_8D4F48 & 0x6000000000000LL) != 0 )
          v47 = 1;
        LOBYTE(v125) = v47;
      }
      v45 = 1;
    }
    else
    {
      if ( HIDWORD(qword_8D4F30) == a3 )
        ++v44;
      else
        ++v43;
      HIDWORD(v125) += !wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F30));
    }
  }
  if ( BYTE4(qword_8D4F6C) == 1 )
  {
    if ( (_DWORD)qword_8D4F6C == (unsigned __int8)a2 )
    {
      if ( wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_8D4F54)) )
      {
        v48 = v125;
        if ( (qword_8D4F6C & 0x6000000000000LL) != 0 )
          v48 = 1;
        LOBYTE(v125) = v48;
      }
      v45 = 1;
    }
    else
    {
      if ( HIDWORD(qword_8D4F54) == a3 )
        ++v44;
      else
        ++v43;
      HIDWORD(v125) += !wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F54));
    }
  }
  if ( BYTE4(qword_8D4F90) != 1 )
  {
    if ( (v45 & 1) != 0 )
      goto LABEL_71;
LABEL_75:
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
      (unsigned __int8)a2);
LABEL_76:
    qdf_mutex_release(v19 + 56);
    goto LABEL_10;
  }
  if ( (_DWORD)qword_8D4F90 == (unsigned __int8)a2 )
  {
    if ( wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_8D4F78)) )
    {
      v49 = v125;
      if ( (qword_8D4F90 & 0x6000000000000LL) != 0 )
        v49 = 1;
      LOBYTE(v125) = v49;
    }
    goto LABEL_71;
  }
  if ( HIDWORD(qword_8D4F78) == a3 )
    ++v44;
  else
    ++v43;
  is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_8D4F78));
  if ( (v45 & 1) == 0 )
    goto LABEL_75;
  HIDWORD(v125) += !is_24ghz_ch_freq;
LABEL_71:
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
      (unsigned __int8)a2,
      a3,
      v43);
LABEL_74:
    qdf_mutex_release(v19 + 56);
    is_ll_lt_sap_restart_required = 1;
    goto LABEL_11;
  }
  if ( (is_mlo_vdev & 1) != 0 )
  {
    if ( wlan_reg_is_24ghz_ch_freq(a3) && HIDWORD(v125) >= 3 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: %d connections present in 5/6g band, move 2g sap",
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        "policy_mgr_is_restart_sap_required",
        HIDWORD(v125));
      goto LABEL_74;
    }
    if ( v44 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: %d number of SCC on freq:%d",
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        "policy_mgr_is_restart_sap_required",
        v44,
        a3);
      goto LABEL_76;
    }
  }
  is_sta_sap_scc_allowed_on_dfs_chan = policy_mgr_is_sta_sap_scc_allowed_on_dfs_chan(a1);
  v60 = 0;
  LODWORD(v123) = 0;
  HIDWORD(v123) = policy_mgr_get_sta_sap_scc_allowed_on_indoor_chnl(a1);
  v126 = is_sta_sap_scc_allowed_on_dfs_chan | v125 ^ 1;
  while ( 1 )
  {
    v61 = (int *)((char *)&pm_conc_connection_list + v60);
    if ( *((_BYTE *)&pm_conc_connection_list + v60 + 28) != 1 )
      goto LABEL_84;
    v62 = *v61;
    if ( a4 == 4 && v62 == 3 )
    {
      if ( *(_DWORD *)((char *)&pm_conc_connection_list + v60 + 24) == (unsigned __int8)a2 )
        goto LABEL_84;
      if ( (policy_mgr_2_freq_always_on_same_mac(a1, a3, *(unsigned int *)((char *)&pm_conc_connection_list + v60 + 4))
          & 1) != 0 )
      {
        v120 = "%s: SAP:%d and GO:%d on same mac. Restart SAP ";
        goto LABEL_129;
      }
      v62 = *v61;
    }
    if ( (v62 | 2) != 2 )
      goto LABEL_84;
    v71 = (char *)&pm_conc_connection_list + v60;
    v72 = *(_DWORD *)((char *)&pm_conc_connection_list + v60 + 4);
    if ( v72 != a3 && (policy_mgr_are_2_freq_on_same_mac(a1, a3, v72) & 1) != 0 )
    {
      v120 = "%s: SAP:%d and STA:%d on same mac. Restart SAP ";
LABEL_129:
      v121 = a3;
LABEL_130:
      qdf_trace_msg(
        0x4Fu,
        8u,
        v120,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        "policy_mgr_is_restart_sap_required",
        v121,
        v123);
      goto LABEL_133;
    }
    if ( !(unsigned int)wlan_get_chan_by_vdev_id(a1, *((unsigned int *)v71 + 6), v127)
      && (_DWORD)v129 == 7
      && HIDWORD(v128) != a5 )
    {
      v120 = "%s: 320M CCFS2 %d conc %d";
      v121 = a5;
      goto LABEL_130;
    }
    if ( !((*((_DWORD *)v71 + 1) != a3) | v126 & 1) )
    {
      v122 = "%s: Move SAP out of DFS ch:%d";
      goto LABEL_132;
    }
    if ( !((*((_DWORD *)v71 + 1) != a3) | BYTE4(v123) & 1) && (wlan_reg_is_freq_indoor() & 1) != 0 )
      break;
    user_config_sap_freq = policy_mgr_get_user_config_sap_freq(a1, a2);
    if ( *((_DWORD *)v71 + 1) != a3 )
    {
      v74 = wlan_reg_is_24ghz_ch_freq(a3);
      LODWORD(v75) = *((_DWORD *)v71 + 1);
      if ( v74 )
      {
        is_5ghz_ch_freq = wlan_reg_is_5ghz_ch_freq(v75);
        LODWORD(v75) = *((_DWORD *)v71 + 1);
        if ( is_5ghz_ch_freq )
        {
          if ( (wlan_reg_is_dfs_for_freq(*(_QWORD *)(v19 + 8), v75, v77, v78, v79, v80, v81, v82, v83, v84) & 1) != 0 )
          {
            LODWORD(v75) = *((_DWORD *)v71 + 1);
          }
          else
          {
            v85 = wlan_reg_is_5ghz_ch_freq(user_config_sap_freq);
            v75 = *((unsigned int *)v71 + 1);
            if ( v85 )
            {
              qdf_trace_msg(
                0x4Fu,
                8u,
                "%s: Move SAP from:%d to STA ch:%d  (sap start freq:%d)",
                v86,
                v87,
                v88,
                v89,
                v90,
                v91,
                v92,
                v93,
                "policy_mgr_is_restart_sap_required",
                a3,
                v75,
                user_config_sap_freq);
              if ( BYTE4(v123) & 1 | ((wlan_reg_is_freq_indoor() & 1) == 0) )
                goto LABEL_133;
              goto LABEL_124;
            }
          }
        }
      }
      if ( (_DWORD)v75 != a3
        && wlan_reg_is_24ghz_ch_freq(v75)
        && wlan_reg_is_5ghz_ch_freq(a3)
        && (policy_mgr_is_sap_go_interface_allowed_on_indoor(*(_QWORD *)(v19 + 8), a2, a3) & 1) == 0 )
      {
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: SAP in indoor freq: sta:%d sap:%d",
          v94,
          v95,
          v96,
          v97,
          v98,
          v99,
          v100,
          v101,
          "policy_mgr_is_restart_sap_required",
          *((unsigned int *)v71 + 1),
          a3);
        LODWORD(v123) = 1;
      }
    }
    if ( a4 == 4 && wlan_reg_is_24ghz_ch_freq(a3) && user_config_sap_freq )
    {
      v102 = *((_DWORD *)v71 + 1);
      if ( v102 != a3 || HIDWORD(v125) )
        goto LABEL_118;
      if ( wlan_reg_is_24ghz_ch_freq(user_config_sap_freq) )
      {
        v102 = *((_DWORD *)v71 + 1);
LABEL_118:
        if ( v102 != a3
          && wlan_reg_is_6ghz_chan_freq(user_config_sap_freq)
          && (policy_mgr_is_chan_eligible_for_sap(v19, *((unsigned int *)v71 + 6), *((unsigned int *)v71 + 1)) & 1) != 0 )
        {
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: Move SAP to STA 6 GHz channel",
            v111,
            v112,
            v113,
            v114,
            v115,
            v116,
            v117,
            v118,
            "policy_mgr_is_restart_sap_required");
          LODWORD(v123) = 1;
        }
        goto LABEL_84;
      }
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: SAP move to user configure %d from %d",
        v103,
        v104,
        v105,
        v106,
        v107,
        v108,
        v109,
        v110,
        "policy_mgr_is_restart_sap_required",
        user_config_sap_freq,
        a3);
      LODWORD(v123) = 1;
    }
LABEL_84:
    v60 += 36;
    if ( v60 == 180 )
    {
      if ( (v123 & 1) != 0 )
        goto LABEL_133;
LABEL_124:
      is_restart_sap_required_with_mlo_sta = policy_mgr_is_restart_sap_required_with_mlo_sta(a1, a3);
      goto LABEL_134;
    }
  }
  v122 = "%s: Move SAP out of indoor ch:%d";
LABEL_132:
  qdf_trace_msg(0x4Fu, 8u, v122, v63, v64, v65, v66, v67, v68, v69, v70, "policy_mgr_is_restart_sap_required", a3, v123);
LABEL_133:
  is_restart_sap_required_with_mlo_sta = 1;
LABEL_134:
  qdf_mutex_release(v19 + 56);
  is_ll_lt_sap_restart_required = is_restart_sap_required_with_mlo_sta;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return is_ll_lt_sap_restart_required & 1;
}
