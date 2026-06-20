__int64 __fastcall hdd_set_roam_with_control_config(__int64 *a1, __int64 a2, unsigned int a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  _QWORD *link_info_by_vdev; // x0
  _QWORD *v23; // x21
  __int64 result; // x0
  const char *v25; // x2
  _WORD *v26; // x2
  unsigned int v27; // w1
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  int updated; // w22
  __int64 v37; // x22
  const char *v38; // x2
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  unsigned int v47; // w23
  unsigned int v48; // w22
  unsigned int v49; // w22
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned int handoff_param; // w0
  unsigned int v59; // w23
  unsigned int v60; // w0
  __int64 v61; // x2
  __int64 *v62; // x0
  __int64 v63; // x1
  __int64 v64; // x3
  unsigned int v65; // w8
  _WORD *v66; // x23
  unsigned __int16 *v67; // x2
  __int64 v68; // x3
  unsigned int v69; // w9
  unsigned int v70; // w8
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  const char *v87; // x2
  unsigned int v88; // w1
  _BOOL4 v89; // w8
  __int64 *v90; // x10
  __int64 *v91; // x10
  int v92; // w24
  int v93; // w8
  int v94; // w23
  int v95; // w8
  int v96; // w25
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  unsigned int v105; // w23
  __int64 v106; // x22
  int v107; // w23
  __int64 v108; // x21
  unsigned int v109; // w21
  const char *v110; // x2
  const char *v111; // x4
  const char *v112; // x4
  const char *v113; // x4
  __int64 v114; // x4
  unsigned __int16 *v115; // x9
  unsigned int v116; // w10
  unsigned int v117; // w8
  unsigned __int16 *v118; // x11
  int v119; // w12
  unsigned int v120; // w13
  __int64 v121; // x13
  __int64 v122; // x8
  unsigned int v123; // w12
  bool v124; // cc
  _BOOL4 v125; // w23
  unsigned int v126; // w21
  double v127; // d0
  double v128; // d1
  double v129; // d2
  double v130; // d3
  double v131; // d4
  double v132; // d5
  double v133; // d6
  double v134; // d7
  __int64 v135; // [xsp+8h] [xbp-2F8h] BYREF
  __int64 v136; // [xsp+10h] [xbp-2F0h] BYREF
  __int64 v137; // [xsp+18h] [xbp-2E8h]
  _QWORD s[40]; // [xsp+20h] [xbp-2E0h] BYREF
  _QWORD v139[48]; // [xsp+160h] [xbp-1A0h] BYREF
  __int64 v140; // [xsp+2E0h] [xbp-20h] BYREF
  _WORD *v141; // [xsp+2E8h] [xbp-18h]
  __int64 v142; // [xsp+2F0h] [xbp-10h]
  __int64 v143; // [xsp+2F8h] [xbp-8h]

  v143 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v136 = 0;
  v137 = 0;
  v135 = 0;
  qdf_trace_msg(0x33u, 8u, "%s: enter", v6, v7, v8, v9, v10, v11, v12, v13, "hdd_set_roam_with_control_config");
  if ( !*(_QWORD *)(a2 + 176) )
  {
    v25 = "%s: Attribute CONTROL_CONFIG is not present";
LABEL_10:
    v27 = 2;
LABEL_11:
    qdf_trace_msg(0x33u, v27, v25, v14, v15, v16, v17, v18, v19, v20, v21, "hdd_set_roam_with_control_config");
LABEL_12:
    result = 4294967274LL;
    goto LABEL_13;
  }
  link_info_by_vdev = (_QWORD *)hdd_get_link_info_by_vdev(a1);
  if ( link_info_by_vdev )
  {
    v23 = link_info_by_vdev;
    if ( !(unsigned int)_hdd_validate_adapter(*link_info_by_vdev, "hdd_set_roam_with_control_config") )
    {
      v26 = *(_WORD **)(a2 + 176);
      if ( ((__int16)v26[1] & 0x80000000) == 0 )
      {
        do_trace_netlink_extack("NLA_F_NESTED is missing");
LABEL_9:
        v25 = "%s: nla_parse failed";
        goto LABEL_10;
      }
      if ( (unsigned int)_nla_parse(s, 39, v26 + 2, (unsigned __int16)(*v26 - 4), &roam_control_policy, 31, 0) )
        goto LABEL_9;
      if ( !s[4] )
      {
        updated = 0;
        goto LABEL_23;
      }
      v141 = nullptr;
      v142 = 0;
      v140 = 0;
      memset(v139, 0, sizeof(v139));
      if ( *(__int16 *)(s[4] + 2LL) < 0 )
      {
        v37 = a1[2];
        if ( !(unsigned int)_nla_parse(
                              &v140,
                              2,
                              s[4] + 4LL,
                              (unsigned __int16)(*(_WORD *)s[4] - 4),
                              &roam_scan_freq_list_scheme_policy,
                              31,
                              0) )
        {
          if ( v141 && v142 )
          {
            if ( (unsigned int)(*(_DWORD *)(v142 + 4) - 3) > 0xFFFFFFFD )
            {
              v115 = v141 + 2;
              v116 = (unsigned __int16)(*v141 - 4);
              if ( v116 >= 4 )
              {
                v117 = 0;
                v118 = v141 + 2;
                v119 = (unsigned __int16)(*v141 - 4);
                do
                {
                  v120 = *v118;
                  if ( v120 < 4 || v119 < v120 )
                    break;
                  if ( v117 >= 0x60 )
                  {
                    qdf_trace_msg(
                      0x33u,
                      2u,
                      "%s: number of channels (%d) supported exceeded max (%d)",
                      v28,
                      v29,
                      v30,
                      v31,
                      v32,
                      v33,
                      v34,
                      v35,
                      "hdd_send_roam_scan_channel_freq_list_to_sme",
                      96,
                      96);
                    goto LABEL_21;
                  }
                  ++v117;
                  v121 = (v120 + 3) & 0x1FFFC;
                  v119 -= v121;
                  v118 = (unsigned __int16 *)((char *)v118 + v121);
                }
                while ( v119 > 3 );
                v122 = 0;
                do
                {
                  v123 = *v115;
                  if ( v123 < 4 || v116 < v123 )
                    break;
                  if ( v123 != 8 )
                  {
                    v38 = "%s: len is not correct for frequency %d";
                    goto LABEL_20;
                  }
                  if ( v122 == 96 )
                  {
                    __break(0x5512u);
LABEL_209:
                    __break(1u);
                    return hdd_clear_roam_control_config();
                  }
                  if ( (v122 & 0x3FFFFFFFFFFFFFFFLL) == 0x60 )
                    goto LABEL_209;
                  v124 = (int)v116 <= 11;
                  v116 -= 8;
                  *((_DWORD *)v139 + v122) = *((_DWORD *)v115 + 1);
                  v115 += 4;
                  ++v122;
                }
                while ( !v124 );
              }
              updated = sme_update_roam_scan_freq_list(v37, a3, v139);
              if ( !updated )
              {
LABEL_23:
                if ( s[1] )
                {
                  if ( !s[7] )
                    goto LABEL_34;
                  v47 = *(unsigned __int8 *)(s[1] + 4LL);
                  v48 = *(_DWORD *)(s[7] + 4LL);
                  if ( *(_BYTE *)(s[1] + 4LL) )
                    goto LABEL_32;
                }
                else
                {
                  if ( !s[7] )
                    goto LABEL_34;
                  v48 = *(_DWORD *)(s[7] + 4LL);
                }
                if ( (unsigned int)sme_set_roam_cfg_rt_params_enabled(a1[2], a3, 1) )
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: failed to set roam_cfg_rt_params_enabled",
                    v14,
                    v15,
                    v16,
                    v17,
                    v18,
                    v19,
                    v20,
                    v21,
                    "hdd_set_roam_with_control_config");
                v47 = 0;
LABEL_32:
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: Received roam trigger bitmap: 0x%x",
                  v14,
                  v15,
                  v16,
                  v17,
                  v18,
                  v19,
                  v20,
                  v21,
                  "hdd_set_roam_with_control_config",
                  v48);
                updated = hdd_send_roam_triggers_to_sme(a1, a3, v48, v47);
                if ( updated )
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: failed to config roam triggers",
                    v14,
                    v15,
                    v16,
                    v17,
                    v18,
                    v19,
                    v20,
                    v21,
                    "hdd_set_roam_with_control_config");
LABEL_34:
                if ( s[1] )
                {
                  v49 = *(unsigned __int8 *)(s[1] + 4LL);
                  if ( *(_BYTE *)(s[1] + 4LL) )
                  {
                    if ( (ucfg_cm_roam_is_vendor_handoff_control_enable(*a1) & 1) != 0 )
                    {
                      handoff_param = hdd_cm_get_handoff_param(*a1, a3, 0xFFFFFFFFLL);
                      if ( handoff_param )
                      {
                        v59 = handoff_param;
                        qdf_trace_msg(
                          0x33u,
                          2u,
                          "%s: failed to get vendor handoff params",
                          v50,
                          v51,
                          v52,
                          v53,
                          v54,
                          v55,
                          v56,
                          v57,
                          "hdd_set_roam_with_control_config");
                        v60 = v59;
LABEL_39:
                        result = qdf_status_to_os_return(v60);
                        goto LABEL_13;
                      }
                    }
                    qdf_trace_msg(
                      0x33u,
                      8u,
                      "%s: Parse and send roam control to FW: %s",
                      v50,
                      v51,
                      v52,
                      v53,
                      v54,
                      v55,
                      v56,
                      v57,
                      "hdd_set_roam_with_control_config",
                      "Enable");
                    wlan_mlme_reinit_real_time_roam_parms();
                  }
                  else
                  {
                    qdf_trace_msg(
                      0x33u,
                      8u,
                      "%s: Parse and send roam control to FW: %s",
                      v14,
                      v15,
                      v16,
                      v17,
                      v18,
                      v19,
                      v20,
                      v21,
                      "hdd_set_roam_with_control_config",
                      "Disable");
                  }
                  updated = sme_set_roam_config_enable(a1[2], a3, v49);
                  if ( updated )
                    qdf_trace_msg(
                      0x33u,
                      2u,
                      "%s: failed to enable/disable roam control config",
                      v14,
                      v15,
                      v16,
                      v17,
                      v18,
                      v19,
                      v20,
                      v21,
                      "hdd_set_roam_with_control_config");
                  if ( s[5] )
                  {
                    updated = hdd_send_roam_scan_period_to_sme(a1, a3, *(unsigned int *)(s[5] + 4LL), 1);
                    if ( updated )
                      qdf_trace_msg(
                        0x33u,
                        2u,
                        "%s: failed to send scan period to firmware",
                        v14,
                        v15,
                        v16,
                        v17,
                        v18,
                        v19,
                        v20,
                        v21,
                        "hdd_set_roam_with_control_config");
                  }
                  if ( s[6] )
                  {
                    v61 = *(unsigned int *)(s[6] + 4LL);
                    v62 = a1;
                    v63 = a3;
                    v64 = 1;
LABEL_54:
                    updated = hdd_send_roam_full_scan_period_to_sme(v62, v63, v61, v64);
                    if ( updated )
                      qdf_trace_msg(
                        0x33u,
                        2u,
                        "%s: failed to config full scan period",
                        v14,
                        v15,
                        v16,
                        v17,
                        v18,
                        v19,
                        v20,
                        v21,
                        "hdd_set_roam_with_control_config");
                  }
                }
                else
                {
                  if ( s[5] )
                  {
                    updated = hdd_send_roam_scan_period_to_sme(a1, a3, *(unsigned int *)(s[5] + 4LL), 0);
                    if ( updated )
                      qdf_trace_msg(
                        0x33u,
                        2u,
                        "%s: failed to send scan period to firmware",
                        v14,
                        v15,
                        v16,
                        v17,
                        v18,
                        v19,
                        v20,
                        v21,
                        "hdd_set_roam_with_control_config");
                  }
                  if ( s[6] )
                  {
                    v61 = *(unsigned int *)(s[6] + 4LL);
                    v62 = a1;
                    v63 = a3;
                    v64 = 0;
                    goto LABEL_54;
                  }
                }
                if ( s[13] )
                {
                  v65 = *(_DWORD *)(s[13] + 4LL);
                  updated = wlan_cm_update_roam_scan_scheme_bitmap(
                              *a1,
                              a3,
                              (16 * v65) & 0x400
                            | (unsigned __int8)(2 * (v65 & 7))
                            | (((v65 >> 7) & 1) << 12) & 0xFFFF1DFF
                            | (((v65 >> 8) & 1) << 9) & 0xFFFF1FFF
                            | (((v65 >> 9) & 7) << 13)
                            | (v65 >> 4) & 0x100);
                }
                v66 = (_WORD *)s[8];
                if ( !s[8] )
                {
LABEL_75:
                  v89 = s[9] != 0;
                  if ( s[9] )
                    LODWORD(v135) = *(_DWORD *)(s[9] + 4LL);
                  if ( s[10] )
                  {
                    HIDWORD(v135) = *(_DWORD *)(s[10] + 4LL);
                    v89 = 1;
                  }
                  if ( s[11] )
                  {
                    LODWORD(v136) = *(_DWORD *)(s[11] + 4LL);
                    v89 = 1;
                  }
                  if ( s[14] )
                  {
                    LODWORD(v136) = *(_DWORD *)(s[14] + 4LL);
                    v89 = 1;
                  }
                  if ( s[15] )
                    v90 = (__int64 *)(s[15] + 4LL);
                  else
                    v90 = &v136;
                  if ( s[15] )
                    v89 = 1;
                  HIDWORD(v136) = *(_DWORD *)v90;
                  if ( s[16] )
                    v91 = (__int64 *)(s[16] + 4LL);
                  else
                    v91 = &v136;
                  if ( s[16] )
                    v92 = 1;
                  else
                    v92 = v89;
                  LODWORD(v137) = *(_DWORD *)v91;
                  if ( s[12] )
                  {
                    v93 = *(_DWORD *)(s[12] + 4LL);
                    v92 = 1;
                  }
                  else
                  {
                    v93 = 2;
                  }
                  HIDWORD(v137) = v93;
                  if ( s[17] )
                  {
                    v94 = *(_DWORD *)(s[17] + 4LL);
                    if ( v94 )
                      v95 = 0;
                    else
                      v95 = 7;
                    v96 = v95 | (*(_DWORD *)(s[17] + 4LL) >> 1) & 1 | (2 * (*(_DWORD *)(s[17] + 4LL) & 1));
                    if ( (wlan_reg_is_6ghz_supported(*a1, v14, v15, v16, v17, v18, v19, v20, v21) & 1) != 0 )
                    {
                      v105 = v96 | v94 & 4;
                    }
                    else
                    {
                      qdf_trace_msg(
                        0x33u,
                        8u,
                        "%s: Driver doesn't support 6ghz",
                        v97,
                        v98,
                        v99,
                        v100,
                        v101,
                        v102,
                        v103,
                        v104,
                        "wlan_vendor_bitmap_to_reg_wifi_band_bitmap");
                      v105 = v96 & 3;
                    }
                    qdf_trace_msg(
                      0x33u,
                      8u,
                      "%s: [ROAM BAND] set roam band mask:%d",
                      v97,
                      v98,
                      v99,
                      v100,
                      v101,
                      v102,
                      v103,
                      v104,
                      "hdd_set_roam_with_control_config",
                      v105);
                    if ( !v105 )
                    {
                      v25 = "%s: Invalid roam BAND_MASK";
                      goto LABEL_113;
                    }
                    wlan_cm_set_roam_band_bitmask(*a1, a3, v105);
                    if ( (cm_roam_is_change_in_band_allowed(*a1, a3, v105) & 1) != 0 )
                    {
                      sme_stop_roaming(a1[2], a3, 48, 32);
                      policy_mgr_set_pcl_for_existing_combo(*a1, 0, a3);
                      sme_start_roaming(a1[2], a3, 43, 32);
                    }
                  }
                  if ( s[24] )
                  {
                    v106 = *a1;
                    v107 = *(unsigned __int16 *)(s[24] + 4LL);
                    v108 = v23[4];
                    if ( (wlan_cm_is_linkspeed_roam_trigger_supported(*a1, v14, v15, v16, v17, v18, v19, v20, v21) & 1) != 0 )
                    {
                      if ( v107 )
                      {
                        dp_ucfg_enable_link_monitoring(v14, v15, v16, v17, v18, v19, v20, v21, v106, v108, v107);
                      }
                      else
                      {
                        dp_ucfg_disable_link_monitoring(v14, v15, v16, v17, v18, v19, v20, v21, v106, v108);
                        wlan_hdd_link_speed_update(v106, *(unsigned __int8 *)(v108 + 104), 0);
                      }
                      updated = 0;
                    }
                    else
                    {
                      updated = 11;
                    }
                  }
                  if ( v92 )
                  {
                    wlan_cm_roam_set_vendor_btm_params(*a1, &v135);
                    sme_send_vendor_btm_params(a1[2], a3);
                  }
                  if ( s[25] )
                  {
                    v109 = *(unsigned __int16 *)(s[25] + 4LL);
                    if ( (unsigned __int16)(v109 - 1001) <= 0xFC2Au )
                    {
                      v110 = "%s: Invalid roam HO delay value: %d";
LABEL_151:
                      v114 = v109;
                      goto LABEL_185;
                    }
                    qdf_trace_msg(
                      0x33u,
                      8u,
                      "%s: Received roam HO delay value: %d",
                      v14,
                      v15,
                      v16,
                      v17,
                      v18,
                      v19,
                      v20,
                      v21,
                      "hdd_set_roam_with_control_config",
                      *(unsigned __int16 *)(s[25] + 4LL));
                    updated = ucfg_cm_roam_send_ho_delay_config(a1[1], a3, v109);
                    if ( updated )
                      qdf_trace_msg(
                        0x33u,
                        2u,
                        "%s: failed to set hand-off delay",
                        v14,
                        v15,
                        v16,
                        v17,
                        v18,
                        v19,
                        v20,
                        v21,
                        "hdd_set_roam_with_control_config");
                  }
                  if ( s[26] )
                  {
                    v109 = *(unsigned __int8 *)(s[26] + 4LL);
                    if ( v109 >= 2 )
                    {
                      v110 = "%s: Invalid value %d to exclude partial scan freq";
                      goto LABEL_151;
                    }
                    if ( *(_BYTE *)(s[26] + 4LL) )
                      v111 = "Exclude";
                    else
                      v111 = "Include";
                    qdf_trace_msg(
                      0x33u,
                      8u,
                      "%s: %s partial scan channels in roam full scan",
                      v14,
                      v15,
                      v16,
                      v17,
                      v18,
                      v19,
                      v20,
                      v21,
                      "hdd_set_roam_with_control_config",
                      v111);
                    updated = ucfg_cm_exclude_rm_partial_scan_freq(a1[1], a3, v109);
                    if ( updated )
                      qdf_trace_msg(
                        0x33u,
                        2u,
                        "%s: Fail to exclude roam partial scan channels",
                        v14,
                        v15,
                        v16,
                        v17,
                        v18,
                        v19,
                        v20,
                        v21,
                        "hdd_set_roam_with_control_config");
                  }
                  if ( s[27] )
                  {
                    v109 = *(unsigned __int8 *)(s[27] + 4LL);
                    if ( v109 >= 2 )
                    {
                      v110 = "%s: Invalid value %d to decide inclusion of 6 GHz channels";
                      goto LABEL_151;
                    }
                    if ( *(_BYTE *)(s[27] + 4LL) )
                      v112 = "prior discovery";
                    else
                      v112 = "default";
                    qdf_trace_msg(
                      0x33u,
                      8u,
                      "%s: Include 6 GHz channels in roam full scan by %s",
                      v14,
                      v15,
                      v16,
                      v17,
                      v18,
                      v19,
                      v20,
                      v21,
                      "hdd_set_roam_with_control_config",
                      v112);
                    updated = ucfg_cm_roam_full_scan_6ghz_on_disc(a1[1], a3, v109);
                    if ( updated )
                      qdf_trace_msg(
                        0x33u,
                        2u,
                        "%s: Fail to decide inclusion of 6 GHz channels",
                        v14,
                        v15,
                        v16,
                        v17,
                        v18,
                        v19,
                        v20,
                        v21,
                        "hdd_set_roam_with_control_config");
                  }
                  if ( !s[31] )
                  {
LABEL_148:
                    if ( s[32] )
                    {
                      v114 = *(unsigned __int8 *)(s[32] + 4LL);
                      v110 = "%s: 2.4GHz band weight value %d is out of range";
LABEL_185:
                      qdf_trace_msg(
                        0x33u,
                        2u,
                        v110,
                        v14,
                        v15,
                        v16,
                        v17,
                        v18,
                        v19,
                        v20,
                        v21,
                        "hdd_set_roam_with_control_config",
                        v114);
                      goto LABEL_12;
                    }
                    if ( s[33] )
                    {
                      v114 = *(unsigned __int8 *)(s[33] + 4LL);
                      v110 = "%s: 5GHz band weight value %d is out of range";
                      goto LABEL_185;
                    }
                    if ( s[34] )
                    {
                      v114 = *(unsigned __int8 *)(s[34] + 4LL);
                      v110 = "%s: 6GHz band weight value %d is out of range";
                      goto LABEL_185;
                    }
                    v125 = s[36] != 0;
                    if ( s[36] )
                    {
                      v109 = *(unsigned __int8 *)(s[36] + 4LL);
                      if ( v109 >= 0x65 )
                      {
                        v110 = "%s: Roam rescan rssi diff value %d out of range";
                        goto LABEL_151;
                      }
                      qdf_trace_msg(
                        0x33u,
                        8u,
                        "%s: Received roam rescan rssi diff value: %d",
                        v14,
                        v15,
                        v16,
                        v17,
                        v18,
                        v19,
                        v20,
                        v21,
                        "hdd_set_roam_with_control_config",
                        *(unsigned __int8 *)(s[36] + 4LL));
                      updated = sme_set_roam_rescan_rssi_diff(a1[2], a3, v109);
                      if ( updated )
                        qdf_trace_msg(
                          0x33u,
                          2u,
                          "%s: Failed to set roam rescan rssi diff value",
                          v14,
                          v15,
                          v16,
                          v17,
                          v18,
                          v19,
                          v20,
                          v21,
                          "hdd_set_roam_with_control_config");
                    }
                    if ( s[37] )
                    {
                      v114 = *(unsigned int *)(s[37] + 4LL);
                      v110 = "%s: Roam scan period value %d out of range";
                      goto LABEL_185;
                    }
                    if ( s[35] )
                    {
                      v109 = *(unsigned __int8 *)(s[35] + 4LL);
                      if ( v109 >= 0x65 )
                      {
                        v110 = "%s: Roam score delta value %d out of range";
                        goto LABEL_151;
                      }
                      qdf_trace_msg(
                        0x33u,
                        8u,
                        "%s: Received roam score delta value: %d",
                        v14,
                        v15,
                        v16,
                        v17,
                        v18,
                        v19,
                        v20,
                        v21,
                        "hdd_set_roam_with_control_config",
                        *(unsigned __int8 *)(s[35] + 4LL));
                      updated = sme_set_roam_score_delta_value(a1[2], a3, v109);
                      if ( updated )
                        qdf_trace_msg(
                          0x33u,
                          2u,
                          "%s: Failed to set roam score delta value",
                          v14,
                          v15,
                          v16,
                          v17,
                          v18,
                          v19,
                          v20,
                          v21,
                          "hdd_set_roam_with_control_config");
                      v125 = 1;
                    }
                    if ( s[38] )
                    {
                      v109 = *(_DWORD *)(s[38] + 4LL);
                      if ( v109 >= 0x65 )
                      {
                        v110 = "%s: Min roam score delta value %d out of range";
                        goto LABEL_151;
                      }
                      qdf_trace_msg(
                        0x33u,
                        8u,
                        "%s: Received min roam score delta value: %d",
                        v14,
                        v15,
                        v16,
                        v17,
                        v18,
                        v19,
                        v20,
                        v21,
                        "hdd_set_roam_with_control_config",
                        v109);
                      updated = sme_set_min_roam_score_delta_value(a1[2], a3, v109);
                      if ( updated )
                        qdf_trace_msg(
                          0x33u,
                          2u,
                          "%s: Failed to set min roam score delta value",
                          v14,
                          v15,
                          v16,
                          v17,
                          v18,
                          v19,
                          v20,
                          v21,
                          "hdd_set_roam_with_control_config");
                      v125 = 1;
                    }
                    if ( s[39] )
                    {
                      v126 = *(_DWORD *)(s[39] + 4LL);
                      qdf_trace_msg(
                        0x33u,
                        8u,
                        "%s: Received reconnect_disallow_period value: %d",
                        v14,
                        v15,
                        v16,
                        v17,
                        v18,
                        v19,
                        v20,
                        v21,
                        "hdd_set_roam_with_control_config",
                        v126);
                      updated = sme_set_reconnect_disallow_period_value(a1[2], a3, v126);
                      if ( updated )
                        qdf_trace_msg(
                          0x33u,
                          2u,
                          "%s: Failed to set reconnect_disallow_period",
                          v127,
                          v128,
                          v129,
                          v130,
                          v131,
                          v132,
                          v133,
                          v134,
                          "hdd_set_roam_with_control_config");
                    }
                    else if ( !v125 )
                    {
LABEL_207:
                      v60 = updated;
                      goto LABEL_39;
                    }
                    wlan_roam_update_cfg(*a1, a3, 4u);
                    goto LABEL_207;
                  }
                  v109 = *(unsigned __int8 *)(s[31] + 4LL);
                  if ( v109 >= 0x29 )
                  {
                    v110 = "%s: High RSSI offset value %d is out of range";
                    goto LABEL_151;
                  }
                  if ( *(_BYTE *)(s[31] + 4LL) )
                    v113 = "Enable";
                  else
                    v113 = "Disable";
                  qdf_trace_msg(
                    0x33u,
                    8u,
                    "%s: %s roam scan high RSSI with offset: %d for vdev %d",
                    v14,
                    v15,
                    v16,
                    v17,
                    v18,
                    v19,
                    v20,
                    v21,
                    "hdd_set_roam_with_control_config",
                    v113,
                    *(unsigned __int8 *)(s[31] + 4LL),
                    (unsigned __int8)a3);
                  if ( v109 || (unsigned __int8)wlan_cm_get_roam_scan_high_rssi_offset(*a1) )
                  {
                    updated = cm_set_roam_scan_high_rssi_offset(*a1, a3, v109);
                    if ( updated )
                      qdf_trace_msg(
                        0x33u,
                        2u,
                        "%s: Fail to set roam scan high RSSI offset for vdev %d",
                        v14,
                        v15,
                        v16,
                        v17,
                        v18,
                        v19,
                        v20,
                        v21,
                        "hdd_set_roam_with_control_config",
                        (unsigned __int8)a3);
                    goto LABEL_148;
                  }
                  v25 = "%s: Roam scan high RSSI is already disabled";
LABEL_113:
                  v27 = 8;
                  goto LABEL_11;
                }
                memset(v139, 0, 72);
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: Received Command to Set candidate selection criteria ",
                  v14,
                  v15,
                  v16,
                  v17,
                  v18,
                  v19,
                  v20,
                  v21,
                  "hdd_send_roam_cand_sel_criteria_to_sme");
                v67 = v66 + 2;
                v68 = (unsigned __int16)(*v66 - 4);
                if ( (unsigned int)v68 < 4 )
                {
                  v70 = 1;
                }
                else
                {
                  v69 = *v67;
                  v70 = 1;
                  if ( v69 >= 4 && v69 <= (unsigned int)v68 )
                  {
                    if ( ((__int16)v66[1] & 0x80000000) == 0 )
                    {
                      do_trace_netlink_extack("NLA_F_NESTED is missing");
LABEL_72:
                      v87 = "%s: nla_parse failed";
                      v88 = 2;
LABEL_73:
                      qdf_trace_msg(
                        0x33u,
                        v88,
                        v87,
                        v71,
                        v72,
                        v73,
                        v74,
                        v75,
                        v76,
                        v77,
                        v78,
                        "hdd_send_roam_cand_sel_criteria_to_sme");
                      updated = 4;
LABEL_74:
                      qdf_trace_msg(
                        0x33u,
                        2u,
                        "%s: failed to set candidate selection criteria",
                        v79,
                        v80,
                        v81,
                        v82,
                        v83,
                        v84,
                        v85,
                        v86,
                        "hdd_set_roam_with_control_config");
                      goto LABEL_75;
                    }
                    if ( (unsigned int)_nla_parse(v139, 8, v67, v68, &roam_scan_cand_sel_policy, 31, 0) )
                      goto LABEL_72;
                    if ( !v139[1] || *(_BYTE *)(v139[1] + 4LL) != 100 )
                    {
                      v87 = "%s: Ignore the candidate selection criteria";
                      v88 = 8;
                      goto LABEL_73;
                    }
                    v70 = 0;
                  }
                }
                updated = sme_modify_roam_cand_sel_criteria(a1[2], a3, v70);
                if ( !updated )
                  goto LABEL_75;
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Failed to disable scoring",
                  v14,
                  v15,
                  v16,
                  v17,
                  v18,
                  v19,
                  v20,
                  v21,
                  "hdd_send_roam_cand_sel_criteria_to_sme");
                goto LABEL_74;
              }
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: Failed to update channel list information",
                v14,
                v15,
                v16,
                v17,
                v18,
                v19,
                v20,
                v21,
                "hdd_send_roam_scan_channel_freq_list_to_sme");
LABEL_22:
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: failed to config roam control",
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                v45,
                v46,
                "hdd_set_roam_with_control_config");
              goto LABEL_23;
            }
            v38 = "%s: Invalid freq list type received: %u";
          }
          else
          {
            v38 = "%s: ROAM_CONTROL_SCAN_FREQ_LIST or type are not present";
          }
LABEL_20:
          qdf_trace_msg(
            0x33u,
            2u,
            v38,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "hdd_send_roam_scan_channel_freq_list_to_sme");
LABEL_21:
          updated = 4;
          goto LABEL_22;
        }
      }
      else
      {
        do_trace_netlink_extack("NLA_F_NESTED is missing");
      }
      v38 = "%s: nla_parse failed";
      goto LABEL_20;
    }
  }
  result = 16;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
