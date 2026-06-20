__int64 __fastcall wlansap_set_channel_change_with_csa(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        char a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  _QWORD *context; // x0
  _BYTE *v21; // x8
  _QWORD *v22; // x21
  int v23; // w8
  unsigned int v24; // w24
  unsigned int v25; // w27
  unsigned int v26; // w28
  unsigned int v27; // w22
  unsigned __int16 reg_punc_bitmap; // w26
  char is_any_mode_active_on_band_along_with_session; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w10
  const char *v39; // x10
  const char *v40; // x2
  const char *v41; // x2
  __int64 result; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned int channel_state_for_pwrmode; // w0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  bool is_sta_sap_scc_allowed_on_dfs_chan; // w27
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  unsigned int v77; // w4
  int v78; // w8
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  int v87; // w22
  int v88; // w0
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  int v97; // w20
  unsigned int v98; // w0
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  unsigned int v107; // w19
  __int64 sap_ch_sw_info; // x0
  _DWORD *v109; // [xsp+40h] [xbp-30h]
  unsigned int v110; // [xsp+4Ch] [xbp-24h]
  __int64 v111; // [xsp+50h] [xbp-20h] BYREF
  __int64 v112; // [xsp+58h] [xbp-18h]
  __int64 v113; // [xsp+60h] [xbp-10h]
  __int64 v114; // [xsp+68h] [xbp-8h]

  v114 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v112 = 0;
  v113 = 0;
  v111 = 0;
  if ( !a1 )
  {
    v40 = "%s: Invalid SAP pointer";
LABEL_15:
    qdf_trace_msg(0x39u, 2u, v40, a7, a8, a9, a10, a11, a12, a13, a14, "wlansap_set_channel_change_with_csa");
LABEL_18:
    result = 5;
    goto LABEL_19;
  }
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a7, a8, a9, a10, a11, a12, a13, a14);
  if ( !context )
  {
    v40 = "%s: Invalid MAC context";
    goto LABEL_15;
  }
  v21 = *(_BYTE **)(a1 + 1544);
  v22 = context;
  if ( (v21 && *v21 || (policy_mgr_restrict_sap_on_unsafe_chan(context[2703]) & 1) != 0 || *(_DWORD *)(a1 + 732) != 2)
    && (policy_mgr_is_sap_freq_allowed(v22[2703], *(_DWORD *)(*(_QWORD *)(a1 + 16) + 16LL), a2) & 1) == 0 )
  {
    v41 = "%s: %u is unsafe channel freq";
LABEL_17:
    qdf_trace_msg(0x39u, 2u, v41, a7, a8, a9, a10, a11, a12, a13, a14, "wlansap_set_channel_change_with_csa", a2);
    goto LABEL_18;
  }
  v23 = *(_DWORD *)(a1 + 1484);
  v110 = a3;
  v24 = a5;
  if ( v23 == 0x4000 || v23 == 0x2000 )
    wlan_reg_set_create_punc_bitmap(a1 + 1500, 1);
  wlan_reg_set_channel_params_for_pwrmode(
    v22[2704],
    *(_DWORD *)a1,
    0,
    a1 + 1500,
    0,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    a14);
  v25 = *(_DWORD *)a1;
  v26 = *(_DWORD *)(a1 + 1512);
  v27 = *(_DWORD *)(a1 + 1500);
  v109 = (_DWORD *)(a1 + 1500);
  reg_punc_bitmap = wlan_reg_get_reg_punc_bitmap(a1 + 1500);
  is_any_mode_active_on_band_along_with_session = policy_mgr_is_any_mode_active_on_band_along_with_session(
                                                    v22[2703],
                                                    *(_BYTE *)(a1 + 12),
                                                    1u);
  v38 = *(_DWORD *)(a1 + 732) - 1;
  if ( v38 > 0xF )
    v39 = "UNKNOWN";
  else
    v39 = off_B08F70[v38];
  qdf_trace_msg(
    0x39u,
    8u,
    "SAP CSA: %d cfreq1 %d BW %d punct 0x%x ---> %d cfreq1 %d BW %d punc 0x%x conn on 5GHz:%d csa_reason %s(%d) strict %d vdev %d",
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v25,
    v26,
    v27,
    reg_punc_bitmap,
    a2,
    v110,
    a4,
    v24,
    is_any_mode_active_on_band_along_with_session & 1,
    v39,
    *(_DWORD *)(a1 + 732),
    a6 & 1,
    *(unsigned __int8 *)(a1 + 12));
  channel_state_for_pwrmode = wlan_reg_get_channel_state_for_pwrmode(
                                v22[2704],
                                a2,
                                0,
                                v43,
                                v44,
                                v45,
                                v46,
                                v47,
                                v48,
                                v49,
                                v50);
  if ( (channel_state_for_pwrmode & 0xFFFFFFFB) == 0 )
  {
    qdf_trace_msg(
      0x39u,
      8u,
      "invalid target freq %d state %d",
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      a2,
      channel_state_for_pwrmode);
    result = 4;
    goto LABEL_19;
  }
  is_sta_sap_scc_allowed_on_dfs_chan = policy_mgr_is_sta_sap_scc_allowed_on_dfs_chan(v22[2703]);
  LODWORD(v111) = a4;
  HIDWORD(v112) = v110;
  wlan_reg_set_input_punc_bitmap((__int64)&v111, v24);
  wlansap_get_csa_chanwidth_from_phymode(a1, a2, (__int64)&v111, v61, v62, v63, v64, v65, v66, v67, v68);
  if ( a4 != 9 )
  {
    if ( (unsigned int)v111 >= a4 )
      v77 = a4;
    else
      v77 = v111;
    LODWORD(v111) = v77;
    qdf_trace_msg(0x39u, 8u, "target ch_width %d to %d ", v69, v70, v71, v72, v73, v74, v75, v76, a4);
  }
  v78 = *(_DWORD *)(a1 + 1484);
  if ( v78 == 0x4000 || v78 == 0x2000 )
    wlan_reg_set_create_punc_bitmap((__int64)&v111, 1);
  wlan_reg_set_channel_params_for_pwrmode(v22[2704], a2, 0, (__int64)&v111, 0, v69, v70, v71, v72, v73, v74, v75, v76);
  if ( *(_DWORD *)a1 == a2 && *v109 == (_DWORD)v111 && *(_DWORD *)(a1 + 1512) == HIDWORD(v112) )
  {
    if ( v24 == (unsigned __int16)wlan_reg_get_reg_punc_bitmap((__int64)v109) )
    {
      qdf_trace_msg(
        0x39u,
        8u,
        "target freq and bw %d not changed",
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        (unsigned int)v111);
      goto LABEL_18;
    }
    v87 = 0;
  }
  else
  {
    v87 = 1;
  }
  if ( (wlan_mlme_check_chan_param_has_dfs(v22[2704], (__int64)&v111, a2, v79, v80, v81, v82, v83, v84, v85, v86) & 1) != 0
    && !(is_sta_sap_scc_allowed_on_dfs_chan
       | ((policy_mgr_is_any_mode_active_on_band_along_with_session(v22[2703], *(_BYTE *)(a1 + 12), 1u) & 1) == 0))
    && *(_DWORD *)(a1 + 732) != 10 )
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: Channel freq = %d is not valid in the currentregulatory domain, is_dfs %d",
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      "wlansap_set_channel_change_with_csa",
      a2,
      1);
    goto LABEL_18;
  }
  if ( (a6 & 1) == 0
    && (sme_validate_sap_channel_switch(
          v22,
          a2,
          *(unsigned int *)(a1 + 1484),
          *(unsigned __int8 *)(a1 + 1560),
          *(unsigned __int8 *)(a1 + 12))
      & 1) == 0 )
  {
    v41 = "%s: Channel freq switch to %u is not allowed due to concurrent channel interference";
    goto LABEL_17;
  }
  if ( *(_DWORD *)(a1 + 728) != 2 )
  {
    v40 = "%s: Failed to request Channel Change, since SAP is not in SAP_STARTED state";
    goto LABEL_15;
  }
  if ( (wlan_is_dnw_in_progress(v22[2704], *(unsigned __int8 *)(a1 + 12)) & 1) != 0 )
    wlan_dnw_handle_bss_stop(v22[2704], *(unsigned __int8 *)(a1 + 12));
  result = wlansap_set_chan_params_for_csa(v22, a1, a2, v110, a4, v24);
  if ( !(_DWORD)result )
  {
    v88 = policy_mgr_check_and_set_hw_mode_for_channel_switch(v22[2703], *(_BYTE *)(a1 + 12), a2, 8u);
    if ( v88 == 16 )
    {
      qdf_trace_msg(
        0x39u,
        2u,
        "%s: HW change required but failed to set hw mode",
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        v95,
        v96,
        "wlansap_set_channel_change_with_csa");
      result = 16;
      goto LABEL_19;
    }
    v97 = v88;
    v98 = policy_mgr_reset_chan_switch_complete_evt(v22[2703]);
    if ( v98 )
    {
      v107 = v98;
      policy_mgr_check_n_start_opportunistic_timer(v22[2703]);
      result = v107;
      goto LABEL_19;
    }
    sap_ch_sw_info = wlan_get_sap_ch_sw_info(*(_QWORD *)(a1 + 16), v99, v100, v101, v102, v103, v104, v105, v106);
    if ( sap_ch_sw_info )
    {
      *(_BYTE *)(sap_ch_sw_info + 8) = 1;
      *(_BYTE *)(a1 + 13) = 1;
      if ( v87 )
        sap_cac_reset_current_notify(a1);
      if ( v97 )
        sme_csa_restart(v22, *(unsigned __int8 *)(a1 + 12));
      else
        qdf_trace_msg(
          0x39u,
          4u,
          "%s: Channel change will continue after HW mode change",
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          a14,
          "wlansap_set_channel_change_with_csa");
      result = 0;
      goto LABEL_19;
    }
    v40 = "%s: Invalid channel info";
    goto LABEL_15;
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
