__int64 __fastcall wlansap_get_chan_band_restrict(
        unsigned int *a1,
        int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x20
  const char *v30; // x2
  unsigned int v31; // w0
  unsigned int v32; // w23
  unsigned int v33; // w21
  unsigned int v34; // w22
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  bool is_enable_in_secondary_list_for_freq; // w0
  unsigned int v44; // w24
  bool v45; // w25
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  unsigned int v70; // w5
  unsigned int _2g_first_safe_chan_freq; // w21
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  unsigned int v80; // w1
  bool is_disable_in_secondary_list_for_freq; // w0
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  unsigned int v90; // w22
  unsigned int alternate_channel_for_sap; // w0
  __int64 v92; // x9
  const char *v93; // x2
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  unsigned int v110; // w5
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  __int64 v127; // x0
  unsigned int v128; // w1
  unsigned int *v129; // x22
  __int64 v130; // x2
  unsigned int v131; // w19
  unsigned int v132; // w9
  double v133; // d0
  double v134; // d1
  double v135; // d2
  double v136; // d3
  double v137; // d4
  double v138; // d5
  double v139; // d6
  double v140; // d7
  unsigned int v141; // w20
  int v142; // w8
  _BOOL4 v143; // [xsp+8h] [xbp-28h]
  __int64 v144; // [xsp+10h] [xbp-20h] BYREF
  __int64 v145; // [xsp+18h] [xbp-18h]
  _QWORD v146[2]; // [xsp+20h] [xbp-10h] BYREF

  v146[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v146[0] = 0;
  v144 = 0;
  v145 = 0;
  if ( !a1 )
  {
    v30 = "%s: sap_ctx NULL parameter";
    goto LABEL_9;
  }
  if ( !a2 )
  {
    v30 = "%s: csa_reason is NULL";
    goto LABEL_9;
  }
  if ( (cds_get_driver_state(a3, a4, a5, a6, a7, a8, a9, a10) & 8) != 0 )
  {
LABEL_10:
    result = 0;
    goto LABEL_11;
  }
  result = (__int64)_cds_get_context(
                      53,
                      (__int64)"wlansap_get_chan_band_restrict",
                      v12,
                      v13,
                      v14,
                      v15,
                      v16,
                      v17,
                      v18,
                      v19);
  if ( result )
  {
    v29 = result;
    if ( (unsigned int)ucfg_reg_get_band(
                         *(_QWORD *)(result + 21560),
                         (_DWORD *)v146 + 1,
                         v21,
                         v22,
                         v23,
                         v24,
                         v25,
                         v26,
                         v27,
                         v28) )
    {
      v30 = "%s: Failed to get current band config";
LABEL_9:
      qdf_trace_msg(0x39u, 2u, v30, a3, a4, a5, a6, a7, a8, a9, a10, "wlansap_get_chan_band_restrict");
      goto LABEL_10;
    }
    policy_mgr_get_sta_sap_scc_allowed_on_indoor_chnl(*(_QWORD *)(v29 + 21552));
    v31 = wlan_reg_freq_to_band(*a1);
    v32 = *a1;
    v33 = v31;
    v34 = HIDWORD(v146[0]);
    is_enable_in_secondary_list_for_freq = wlan_reg_is_enable_in_secondary_list_for_freq(
                                             *(_QWORD *)(v29 + 21560),
                                             *a1,
                                             v35,
                                             v36,
                                             v37,
                                             v38,
                                             v39,
                                             v40,
                                             v41,
                                             v42);
    v44 = a1[379];
    v45 = is_enable_in_secondary_list_for_freq;
    v143 = wlan_reg_is_enable_in_secondary_list_for_freq(
             *(_QWORD *)(v29 + 21560),
             v44,
             v46,
             v47,
             v48,
             v49,
             v50,
             v51,
             v52,
             v53);
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: SAP/Go current band: %d, pdev band capability: %d, cur freq %d (is valid %d), prev freq %d (is valid %d)",
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      "wlansap_get_chan_band_restrict",
      v33,
      v34,
      v32,
      v45,
      v44,
      v143,
      v144,
      v145);
    if ( v33 == 1 && HIDWORD(v146[0]) == 1 )
    {
      v70 = a1[375];
      a1[379] = *a1;
      a1[380] = v70;
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: Save chan info before switch: %d, width: %d",
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        "wlansap_get_chan_band_restrict");
      _2g_first_safe_chan_freq = wlansap_get_2g_first_safe_chan_freq((__int64)a1);
      if ( !_2g_first_safe_chan_freq )
      {
        qdf_trace_msg(
          0x39u,
          8u,
          "%s: use default chan 6",
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          "wlansap_get_chan_band_restrict");
        _2g_first_safe_chan_freq = 2437;
      }
      goto LABEL_37;
    }
    if ( !v33 && (v146[0] & 0x200000000LL) != 0 && (v80 = a1[379]) != 0 )
    {
      is_disable_in_secondary_list_for_freq = wlan_reg_is_disable_in_secondary_list_for_freq(
                                                *(_QWORD *)(v29 + 21560),
                                                v80,
                                                v62,
                                                v63,
                                                v64,
                                                v65,
                                                v66,
                                                v67,
                                                v68,
                                                v69);
      _2g_first_safe_chan_freq = a1[379];
      if ( !is_disable_in_secondary_list_for_freq )
      {
        v93 = "%s: Restore chan freq: %d";
        goto LABEL_36;
      }
      v90 = wlan_reg_freq_to_band(_2g_first_safe_chan_freq);
      alternate_channel_for_sap = policy_mgr_get_alternate_channel_for_sap(
                                    *(_QWORD *)(v29 + 21552),
                                    *((unsigned __int8 *)a1 + 12),
                                    *a1,
                                    v90);
      if ( !alternate_channel_for_sap )
      {
        qdf_trace_msg(
          0x39u,
          8u,
          "%s: Did not get valid freq for band %d remain on same channel",
          v82,
          v83,
          v84,
          v85,
          v86,
          v87,
          v88,
          v89,
          "wlansap_get_chan_band_restrict",
          v90);
        goto LABEL_10;
      }
      _2g_first_safe_chan_freq = alternate_channel_for_sap;
    }
    else
    {
      v92 = *((_QWORD *)a1 + 192);
      if ( !v92 || *(_BYTE *)(v92 + 41) != 1 )
      {
        if ( wlan_reg_is_disable_in_secondary_list_for_freq(
               *(_QWORD *)(v29 + 21560),
               *a1,
               v62,
               v63,
               v64,
               v65,
               v66,
               v67,
               v68,
               v69)
          && (utils_dfs_is_freq_in_nol(*(_QWORD *)(v29 + 21560), *a1) & 1) == 0 )
        {
          qdf_trace_msg(
            0x39u,
            8u,
            "%s: channel is disabled",
            v94,
            v95,
            v96,
            v97,
            v98,
            v99,
            v100,
            v101,
            "wlansap_get_chan_band_restrict");
          v142 = 11;
        }
        else
        {
          if ( (wlan_reg_is_passive_for_freq(*(_QWORD *)(v29 + 21560), *a1, v94, v95, v96, v97, v98, v99, v100, v101) & 1) != 0 )
          {
            v110 = a1[375];
            a1[379] = *a1;
            a1[380] = v110;
            qdf_trace_msg(
              0x39u,
              8u,
              "%s: Save chan info before switch: %d, width: %d",
              v102,
              v103,
              v104,
              v105,
              v106,
              v107,
              v108,
              v109,
              "wlansap_get_chan_band_restrict");
            qdf_trace_msg(
              0x39u,
              8u,
              "%s: channel is passive",
              v111,
              v112,
              v113,
              v114,
              v115,
              v116,
              v117,
              v118,
              "wlansap_get_chan_band_restrict");
            *a2 = 12;
            result = wlansap_get_safe_channel_from_pcl_for_sap((__int64)a1);
            goto LABEL_11;
          }
          if ( (policy_mgr_is_sap_freq_allowed(*(_QWORD *)(v29 + 21552), *(_DWORD *)(*((_QWORD *)a1 + 2) + 16LL), *a1)
              & 1) != 0 )
          {
            if ( v33 != 2
              || (wlan_reg_get_keep_6ghz_sta_cli_connection(
                    *(_QWORD *)(v29 + 21560),
                    v119,
                    v120,
                    v121,
                    v122,
                    v123,
                    v124,
                    v125,
                    v126)
                & 1) == 0
              || (v127 = *(_QWORD *)(v29 + 21560),
                  v128 = *a1,
                  LODWORD(v144) = a1[375],
                  wlan_reg_set_channel_params_for_pwrmode(
                    v127,
                    v128,
                    0,
                    (__int64)&v144,
                    0,
                    v119,
                    v120,
                    v121,
                    v122,
                    v123,
                    v124,
                    v125,
                    v126),
                  a1[375] == (_DWORD)v144) )
            {
              qdf_trace_msg(
                0x39u,
                8u,
                "%s: No need switch SAP/Go channel",
                v119,
                v120,
                v121,
                v122,
                v123,
                v124,
                v125,
                v126,
                "wlansap_get_chan_band_restrict");
              result = *a1;
              goto LABEL_11;
            }
            qdf_trace_msg(
              0x39u,
              8u,
              "%s: Bonded 6GHz channels are disabled",
              v119,
              v120,
              v121,
              v122,
              v123,
              v124,
              v125,
              v126,
              "wlansap_get_chan_band_restrict");
            v142 = 9;
          }
          else
          {
            qdf_trace_msg(
              0x39u,
              8u,
              "%s: channel is unsafe",
              v119,
              v120,
              v121,
              v122,
              v123,
              v124,
              v125,
              v126,
              "wlansap_get_chan_band_restrict");
            v142 = 6;
          }
        }
        *a2 = v142;
        result = wlansap_get_safe_channel_from_pcl_and_acs_range((__int64)a1, 0);
        goto LABEL_11;
      }
      wlansap_get_valid_freq(*(_QWORD *)(v29 + 21552), a1, v146);
      _2g_first_safe_chan_freq = v146[0];
      if ( !LODWORD(v146[0]) )
        goto LABEL_10;
    }
    v93 = "%s: restart SAP on freq %d";
LABEL_36:
    qdf_trace_msg(
      0x39u,
      8u,
      v93,
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      "wlansap_get_chan_band_restrict",
      _2g_first_safe_chan_freq);
LABEL_37:
    v129 = a1;
    *a2 = 9;
    v130 = a1[371];
    v131 = *(unsigned __int8 *)(*((_QWORD *)a1 + 2) + 104LL);
    v132 = (unsigned __int16)sme_check_concurrent_channel_overlap(v29, _2g_first_safe_chan_freq, v130);
    if ( v132 )
      v141 = v132;
    else
      v141 = _2g_first_safe_chan_freq;
    if ( v141 == *v129 )
    {
      result = 0;
      *a2 = 0;
      goto LABEL_11;
    }
    if ( v141 )
    {
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: vdev: %d, CSA target freq: %d",
        v133,
        v134,
        v135,
        v136,
        v137,
        v138,
        v139,
        v140,
        "wlansap_get_chan_band_restrict",
        v131,
        v141);
      result = v141;
      goto LABEL_11;
    }
    goto LABEL_10;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
