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
  _QWORD *v22; // x20
  unsigned int v23; // w24
  unsigned int v24; // w27
  unsigned int v25; // w28
  unsigned int v26; // w22
  unsigned __int16 reg_punc_bitmap; // w26
  char is_any_mode_active_on_band_along_with_session; // w0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w10
  const char *v38; // x10
  const char *v39; // x2
  const char *v40; // x2
  __int64 result; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int channel_state_for_pwrmode; // w0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  bool is_sta_sap_scc_allowed_on_dfs_chan; // w27
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  unsigned int v76; // w4
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  int v85; // w22
  int v86; // w0
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  int v95; // w21
  unsigned int v96; // w0
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  unsigned int v105; // w19
  __int64 sap_ch_sw_info; // x0
  unsigned int v107; // [xsp+54h] [xbp-1Ch]
  unsigned int v108; // [xsp+58h] [xbp-18h] BYREF
  __int64 v109; // [xsp+5Ch] [xbp-14h]
  unsigned int v110; // [xsp+64h] [xbp-Ch]
  __int64 v111; // [xsp+68h] [xbp-8h]

  v111 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v109 = 0;
  if ( !a1 )
  {
    v39 = "%s: Invalid SAP pointer";
LABEL_12:
    qdf_trace_msg(0x39u, 2u, v39, a7, a8, a9, a10, a11, a12, a13, a14, "wlansap_set_channel_change_with_csa");
LABEL_15:
    result = 5;
    goto LABEL_16;
  }
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a7, a8, a9, a10, a11, a12, a13, a14);
  if ( !context )
  {
    v39 = "%s: Invalid MAC context";
    goto LABEL_12;
  }
  v21 = *(_BYTE **)(a1 + 1536);
  v22 = context;
  if ( (v21 && *v21 || (policy_mgr_restrict_sap_on_unsafe_chan(context[2694]) & 1) != 0 || *(_DWORD *)(a1 + 732) != 2)
    && (policy_mgr_is_sap_freq_allowed(v22[2694], *(_DWORD *)(*(_QWORD *)(a1 + 16) + 16LL), a2) & 1) == 0 )
  {
    v40 = "%s: %u is unsafe channel freq";
LABEL_14:
    qdf_trace_msg(0x39u, 2u, v40, a7, a8, a9, a10, a11, a12, a13, a14, "wlansap_set_channel_change_with_csa", a2);
    goto LABEL_15;
  }
  v107 = a3;
  v23 = a5;
  wlan_reg_set_channel_params_for_pwrmode(
    v22[2695],
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
  v24 = *(_DWORD *)a1;
  v25 = *(_DWORD *)(a1 + 1512);
  v26 = *(_DWORD *)(a1 + 1500);
  reg_punc_bitmap = wlan_reg_get_reg_punc_bitmap();
  is_any_mode_active_on_band_along_with_session = policy_mgr_is_any_mode_active_on_band_along_with_session(
                                                    v22[2694],
                                                    *(_BYTE *)(a1 + 12),
                                                    1u);
  v37 = *(_DWORD *)(a1 + 732) - 1;
  if ( v37 > 0xF )
    v38 = "UNKNOWN";
  else
    v38 = off_A16E78[v37];
  qdf_trace_msg(
    0x39u,
    8u,
    "SAP CSA: %d cfreq1 %d BW %d punct 0x%x ---> %d cfreq1 %d BW %d punc 0x%x conn on 5GHz:%d csa_reason %s(%d) strict %d vdev %d",
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v24,
    v25,
    v26,
    reg_punc_bitmap,
    a2,
    v107,
    a4,
    v23,
    is_any_mode_active_on_band_along_with_session & 1,
    v38,
    *(_DWORD *)(a1 + 732),
    a6 & 1,
    *(unsigned __int8 *)(a1 + 12));
  channel_state_for_pwrmode = wlan_reg_get_channel_state_for_pwrmode(
                                v22[2695],
                                a2,
                                0,
                                v42,
                                v43,
                                v44,
                                v45,
                                v46,
                                v47,
                                v48,
                                v49);
  if ( (channel_state_for_pwrmode & 0xFFFFFFFB) == 0 )
  {
    qdf_trace_msg(
      0x39u,
      8u,
      "invalid target freq %d state %d",
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      a2,
      channel_state_for_pwrmode);
    result = 4;
    goto LABEL_16;
  }
  is_sta_sap_scc_allowed_on_dfs_chan = policy_mgr_is_sta_sap_scc_allowed_on_dfs_chan(v22[2694]);
  v108 = a4;
  v110 = v107;
  wlan_reg_set_input_punc_bitmap();
  wlansap_get_csa_chanwidth_from_phymode(a1, a2, (__int64)&v108, v60, v61, v62, v63, v64, v65, v66, v67);
  if ( a4 != 9 )
  {
    if ( v108 >= a4 )
      v76 = a4;
    else
      v76 = v108;
    v108 = v76;
    qdf_trace_msg(0x39u, 8u, "target ch_width %d to %d ", v68, v69, v70, v71, v72, v73, v74, v75, a4);
  }
  wlan_reg_set_channel_params_for_pwrmode(v22[2695], a2, 0, (__int64)&v108, 0, v68, v69, v70, v71, v72, v73, v74, v75);
  if ( *(_DWORD *)a1 == a2 && *(_DWORD *)(a1 + 1500) == v108 && *(_DWORD *)(a1 + 1512) == v110 )
  {
    if ( v23 == (unsigned __int16)wlan_reg_get_reg_punc_bitmap() )
    {
      qdf_trace_msg(0x39u, 8u, "target freq and bw %d not changed", v77, v78, v79, v80, v81, v82, v83, v84, v108);
      goto LABEL_15;
    }
    v85 = 0;
  }
  else
  {
    v85 = 1;
  }
  if ( (wlan_mlme_check_chan_param_has_dfs(v22[2695], &v108, a2, v77, v78, v79, v80, v81, v82, v83, v84) & 1) != 0
    && !(is_sta_sap_scc_allowed_on_dfs_chan
       | ((policy_mgr_is_any_mode_active_on_band_along_with_session(v22[2694], *(_BYTE *)(a1 + 12), 1u) & 1) == 0))
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
    goto LABEL_15;
  }
  if ( (a6 & 1) == 0
    && (sme_validate_sap_channel_switch(
          v22,
          a2,
          *(unsigned int *)(a1 + 1484),
          *(unsigned __int8 *)(a1 + 1552),
          *(unsigned __int8 *)(a1 + 12))
      & 1) == 0 )
  {
    v40 = "%s: Channel freq switch to %u is not allowed due to concurrent channel interference";
    goto LABEL_14;
  }
  if ( *(_DWORD *)(a1 + 728) != 2 )
  {
    v39 = "%s: Failed to request Channel Change, since SAP is not in SAP_STARTED state";
    goto LABEL_12;
  }
  if ( (wlan_is_dnw_in_progress(v22[2695], *(unsigned __int8 *)(a1 + 12)) & 1) != 0 )
    wlan_dnw_handle_bss_stop(v22[2695], *(unsigned __int8 *)(a1 + 12));
  result = wlansap_set_chan_params_for_csa(v22, a1, a2, v107, a4, v23);
  if ( !(_DWORD)result )
  {
    v86 = policy_mgr_check_and_set_hw_mode_for_channel_switch(v22[2694], *(_BYTE *)(a1 + 12), a2, 8u);
    if ( v86 == 16 )
    {
      qdf_trace_msg(
        0x39u,
        2u,
        "%s: HW change required but failed to set hw mode",
        v87,
        v88,
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        "wlansap_set_channel_change_with_csa");
      result = 16;
      goto LABEL_16;
    }
    v95 = v86;
    v96 = policy_mgr_reset_chan_switch_complete_evt(v22[2694]);
    if ( v96 )
    {
      v105 = v96;
      policy_mgr_check_n_start_opportunistic_timer(v22[2694]);
      result = v105;
      goto LABEL_16;
    }
    sap_ch_sw_info = wlan_get_sap_ch_sw_info(*(_QWORD *)(a1 + 16), v97, v98, v99, v100, v101, v102, v103, v104);
    if ( sap_ch_sw_info )
    {
      *(_BYTE *)(sap_ch_sw_info + 8) = 1;
      *(_BYTE *)(a1 + 13) = 1;
      if ( v85 )
        sap_cac_reset_current_notify(a1);
      if ( v95 )
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
      goto LABEL_16;
    }
    v39 = "%s: Invalid channel info";
    goto LABEL_12;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
