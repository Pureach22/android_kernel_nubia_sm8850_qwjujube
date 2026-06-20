__int64 __fastcall policy_mgr_allow_new_home_channel(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        int a4,
        char a5,
        unsigned int a6)
{
  __int64 comp_private_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x19
  char v22; // w22
  char is_sta_p2p_ndp_supported; // w0
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int v33; // w26
  unsigned int v34; // w27
  int v35; // w0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  char v44; // w0
  int v45; // w0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x21
  __int64 v55; // x21
  bool v56; // zf
  int v57; // w8
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x21
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 v75; // x21

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
  if ( comp_private_obj )
  {
    v21 = comp_private_obj;
    if ( (wlan_nan_is_sta_sap_nan_allowed(a1) & 1) != 0 )
    {
      if ( (a2 & 0xFFFFFFFE) != 4 )
      {
LABEL_9:
        v24 = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
        if ( v24 )
        {
          v33 = *(unsigned __int8 *)(v24 + 2200);
        }
        else
        {
          qdf_trace_msg(
            0x4Fu,
            2u,
            "%s: Invalid Context",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "policy_mgr_get_mcc_to_scc_switch_mode");
          v33 = 0;
        }
        qdf_mutex_acquire(v21 + 56);
        v34 = BYTE4(qword_81C458) == 1
           && (pm_conc_connection_list & 0xFFFFFFFE) != 4
           && wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list));
        if ( BYTE4(qword_81C47C) == 1 && (qword_81C464 & 0xFFFFFFFE) != 4 )
          v34 += wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C464));
        if ( BYTE4(qword_81C4A0) == 1 && (qword_81C488 & 0xFFFFFFFE) != 4 )
          v34 += wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C488));
        if ( BYTE4(qword_81C4C4) == 1 && (qword_81C4AC & 0xFFFFFFFE) != 4 )
          v34 += wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C4AC));
        if ( BYTE4(qword_81C4E8) == 1 && (qword_81C4D0 & 0xFFFFFFFE) != 4 )
          v34 += wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C4D0));
        v35 = policy_mgr_mode_specific_connection_count(a1, 5, 0);
        if ( v34 <= 2
          && v35
          && wlan_reg_is_24ghz_ch_freq(a3)
          && ((wlan_nan_is_sta_sap_nan_allowed(a1) & 1) != 0 || (wlan_nan_is_sta_p2p_ndp_supported(a1) & 1) != 0) )
        {
          qdf_mutex_release(v21 + 56);
          v22 = 1;
          return v22 & 1;
        }
        if ( a4 != 2 )
        {
          if ( a4 == 3 )
          {
            v44 = policy_mgr_allow_4th_new_freq(a1, a3, a2, a6);
LABEL_37:
            v22 = v44;
LABEL_80:
            qdf_mutex_release(v21 + 56);
            return v22 & 1;
          }
          if ( a4 == 1 && v33 == 5 && (a5 & 1) != 0 )
          {
            if ( (qword_81C458 & 0x6000000000000LL) != 0 )
            {
              v55 = jiffies;
              if ( policy_mgr_allow_new_home_channel___last_ticks_67 - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x4Fu,
                  8u,
                  "%s: Existing DFS connection, new 2-port DFS connection is not allowed",
                  v36,
                  v37,
                  v38,
                  v39,
                  v40,
                  v41,
                  v42,
                  v43,
                  "policy_mgr_allow_new_home_channel");
                v22 = 0;
                policy_mgr_allow_new_home_channel___last_ticks_67 = v55;
                goto LABEL_80;
              }
              goto LABEL_49;
            }
          }
          else if ( a4 != 1 )
          {
            goto LABEL_79;
          }
          if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) == 0 && (policy_mgr_is_interband_mcc_supported(a1) & 1) == 0 )
          {
            v56 = a2 == 5;
            v22 = 1;
            if ( v56 || (_DWORD)pm_conc_connection_list == 5 )
              goto LABEL_80;
            v44 = policy_mgr_2_freq_always_on_same_mac(a1, a3, HIDWORD(pm_conc_connection_list));
            goto LABEL_37;
          }
          goto LABEL_79;
        }
        v45 = policy_mgr_2_freq_always_on_same_mac(a1, HIDWORD(pm_conc_connection_list), HIDWORD(qword_81C464));
        if ( v33 == 5
          && (a5 & 1) != 0
          && ((qword_81C458 & 0x6000000000000LL) != 0 || (qword_81C47C & 0x6000000000000LL) != 0) )
        {
          v54 = jiffies;
          if ( policy_mgr_allow_new_home_channel___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x4Fu,
              8u,
              "%s: Existing DFS connection, new 3-port DFS connection is not allowed",
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              "policy_mgr_allow_new_home_channel");
            v22 = 0;
            policy_mgr_allow_new_home_channel___last_ticks = v54;
            goto LABEL_80;
          }
        }
        else
        {
          v56 = HIDWORD(pm_conc_connection_list) != HIDWORD(qword_81C464) || v33 == 5;
          v57 = v56;
          if ( (v57 & v45) != 1 )
          {
            if ( (v45 & 1) != 0 )
            {
              v44 = policy_mgr_allow_same_mac_same_freq(a1, a3, a2);
              goto LABEL_37;
            }
            goto LABEL_79;
          }
          if ( (_DWORD)pm_conc_connection_list == 5 && (_DWORD)qword_81C464 == 4
            || (_DWORD)pm_conc_connection_list == 4 && (_DWORD)qword_81C464 == 5 )
          {
            goto LABEL_79;
          }
          if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) == 0 && (policy_mgr_is_interband_mcc_supported(a1) & 1) != 0 )
          {
            v22 = 1;
            if ( HIDWORD(pm_conc_connection_list) == a3 || HIDWORD(qword_81C464) == a3 )
              goto LABEL_80;
            v66 = jiffies;
            if ( policy_mgr_allow_same_mac_diff_freq___last_ticks - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x4Fu,
                8u,
                "%s: don't allow 3rd home channel on same MAC",
                v58,
                v59,
                v60,
                v61,
                v62,
                v63,
                v64,
                v65,
                "policy_mgr_allow_same_mac_diff_freq");
              v22 = 0;
              policy_mgr_allow_same_mac_diff_freq___last_ticks = v66;
              goto LABEL_80;
            }
            goto LABEL_49;
          }
          if ( (policy_mgr_3_freq_always_on_same_mac(a1, a3, HIDWORD(pm_conc_connection_list), HIDWORD(qword_81C464)) & 1) == 0 )
          {
LABEL_79:
            v22 = 1;
            goto LABEL_80;
          }
          v75 = jiffies;
          if ( policy_mgr_allow_same_mac_diff_freq___last_ticks_180 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x4Fu,
              8u,
              "%s: don't allow 3rd home channel on same MAC",
              v67,
              v68,
              v69,
              v70,
              v71,
              v72,
              v73,
              v74,
              "policy_mgr_allow_same_mac_diff_freq");
            v22 = 0;
            policy_mgr_allow_same_mac_diff_freq___last_ticks_180 = v75;
            goto LABEL_80;
          }
        }
LABEL_49:
        v22 = 0;
        goto LABEL_80;
      }
    }
    else
    {
      is_sta_p2p_ndp_supported = wlan_nan_is_sta_p2p_ndp_supported(a1);
      if ( (a2 & 0xFFFFFFFE) != 4 || (is_sta_p2p_ndp_supported & 1) == 0 )
        goto LABEL_9;
    }
    v22 = 1;
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "policy_mgr_allow_new_home_channel");
    v22 = 0;
  }
  return v22 & 1;
}
