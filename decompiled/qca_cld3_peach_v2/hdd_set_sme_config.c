__int64 __fastcall hdd_set_sme_config(__int64 *a1)
{
  __int64 v2; // x19
  unsigned int *v3; // x24
  __int64 v4; // x0
  __int64 psoc_ext_obj_fl; // x0
  __int64 v6; // x22
  __int64 v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x23
  __int64 v17; // x20
  unsigned int v18; // w8
  unsigned int updated; // w19
  int v20; // w8
  char v21; // w8
  const char *power_usage; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v31; // x23
  char v32; // w8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  char is_6ghz_supported; // w0
  const char *v51; // x23
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  bool is_disconect_after_roam_fail; // w0
  __int64 v61; // x0
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  const char *v70; // x2
  int v71; // w8
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  __int64 v80; // x0
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  const char *v89; // x2
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
  char v107[4]; // [xsp+Ch] [xbp-34h] BYREF
  int v108; // [xsp+10h] [xbp-30h] BYREF
  char v109[4]; // [xsp+14h] [xbp-2Ch] BYREF
  char v110[4]; // [xsp+18h] [xbp-28h] BYREF
  char v111[4]; // [xsp+1Ch] [xbp-24h] BYREF
  unsigned int v112; // [xsp+20h] [xbp-20h] BYREF
  _BYTE v113[4]; // [xsp+24h] [xbp-1Ch] BYREF
  _BYTE v114[4]; // [xsp+28h] [xbp-18h] BYREF
  _BYTE v115[4]; // [xsp+2Ch] [xbp-14h] BYREF
  _BYTE v116[4]; // [xsp+30h] [xbp-10h] BYREF
  _BYTE v117[4]; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v118; // [xsp+38h] [xbp-8h]

  v118 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[2];
  v3 = (unsigned int *)a1[13];
  v4 = *a1;
  v110[0] = 0;
  v109[0] = 1;
  v108 = 0;
  v107[0] = 0;
  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(v4);
  if ( !psoc_ext_obj_fl )
  {
    updated = 4;
    goto LABEL_57;
  }
  v6 = psoc_ext_obj_fl;
  v7 = _qdf_mem_malloc(0x4E4u, "hdd_set_sme_config", 978);
  if ( !v7 )
  {
    updated = 2;
    goto LABEL_57;
  }
  v16 = *v3;
  v17 = v7;
  if ( cds_is_sub_20_mhz_enabled(v8, v9, v10, v11, v12, v13, v14, v15) )
  {
    v18 = 1;
  }
  else if ( (unsigned int)v16 > 0xE )
  {
    v18 = 16;
  }
  else
  {
    v18 = dword_AF7544[v16];
  }
  *(_DWORD *)(v17 + 8) = v18;
  if ( *v3 <= 7 && ((1 << *v3) & 0xAE) != 0 )
  {
    v20 = 0;
    *(_DWORD *)v17 = 0;
  }
  else
  {
    ucfg_mlme_get_channel_bonding_24ghz(*a1, &v108);
    *(_DWORD *)v17 = v108;
    ucfg_mlme_get_channel_bonding_5ghz(*a1, &v108);
    v20 = v108;
  }
  *(_DWORD *)(v17 + 4) = v20;
  *(_BYTE *)(v17 + 1233) = 1;
  *(_BYTE *)(v17 + 21) = 0;
  *(_DWORD *)(v17 + 12) = 40;
  wlan_scan_cfg_get_dfs_chan_scan_allowed(*a1, v109);
  v21 = v109[0];
  *(_BYTE *)(v17 + 28) = 0;
  v112 = 0;
  *(_BYTE *)(v17 + 1232) = v21;
  power_usage = (const char *)wlan_mlme_get_power_usage(*a1);
  if ( power_usage )
  {
    v31 = power_usage;
    if ( !strcmp(power_usage, "Min") )
    {
      wlan_mlme_get_bmps_min_listen_interval(*a1, (int *)&v112);
    }
    else if ( !strcmp(v31, "Max") )
    {
      wlan_mlme_get_bmps_max_listen_interval(*a1, (int *)&v112);
    }
    if ( v112 )
      wlan_mlme_set_sap_listen_interval(*a1, v112);
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: invalid power usage",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "hdd_set_power_save_offload_config");
  }
  ucfg_mlme_is_ese_enabled(*a1, v107);
  if ( v107[0] == 1 )
    ucfg_mlme_set_fast_transition_enabled(*a1, 1);
  ucfg_mlme_is_roam_scan_offload_enabled(*a1, v110);
  if ( (v110[0] & 1) == 0 )
    ucfg_mlme_set_fast_roam_in_concurrency_enabled(*a1, 0);
  v32 = *((_BYTE *)a1 + 852);
  v112 = 0;
  *(_BYTE *)(v17 + 1239) = v32;
  ucfg_mlme_get_fine_time_meas_cap(*a1, (int *)&v112);
  ucfg_wifi_pos_set_ftm_cap(*a1, v112);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: fine time meas capability - Enabled: %04x",
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    "hdd_set_fine_time_meas_cap",
    v112);
  v41 = *a1;
  LOBYTE(v112) = 1;
  ucfg_mlme_get_oem_6g_supported(v41, (char *)&v112);
  is_6ghz_supported = wlan_reg_is_6ghz_supported(*a1, v42, v43, v44, v45, v46, v47, v48, v49);
  if ( v112 & 1 | ((is_6ghz_supported & 1) == 0) )
    v51 = "Disabled";
  else
    v51 = "Enabled";
  ucfg_wifi_pos_set_oem_6g_supported(*a1, v112 & 1 | ((is_6ghz_supported & 1) == 0));
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: oem 6g support is - %s",
    v52,
    v53,
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    "hdd_set_oem_6g_supported",
    v51);
  cds_set_multicast_logging(*(unsigned __int8 *)(a1[13] + 29));
  *(_DWORD *)(v6 + 2716) = 1;
  *(_BYTE *)(v6 + 2720) = 0;
  is_disconect_after_roam_fail = ucfg_dp_is_disconect_after_roam_fail(*a1);
  v117[0] = 0;
  *(_BYTE *)(v6 + 2764) = is_disconect_after_roam_fail;
  v61 = *a1;
  v116[0] = 0;
  v115[0] = 0;
  v114[0] = 0;
  v113[0] = 0;
  v112 = 0;
  v111[0] = 0;
  if ( (unsigned int)wlan_mlme_get_80211e_is_enabled(v61, v111) )
  {
    v70 = "%s: Get b80211e_enabled failed";
  }
  else
  {
    *(_BYTE *)(v17 + 20) = v111[0];
    if ( (unsigned int)wlan_mlme_get_wmm_mode(*a1, v117) )
    {
      v70 = "%s: Get wmm_mode failed";
    }
    else
    {
      v71 = 2 * (v117[0] == 2);
      if ( v117[0] == 1 )
        v71 = 1;
      *(_DWORD *)(v17 + 16) = v71;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: wmm_mode=%d 802_11e_enabled=%d",
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        "hdd_set_sme_cfgs_related_to_mlme");
      if ( (unsigned int)wlan_mlme_get_mcc_feature(*a1, v116) )
      {
        v70 = "%s: ucfg_mlme_get_mcc_feature fail, use def";
      }
      else
      {
        *(_BYTE *)(v17 + 22) = v116[0];
        if ( (unsigned int)wlan_mlme_get_mcc_rts_cts_prot(*a1, v114) )
        {
          v70 = "%s: ucfg_mlme_get_mcc_rts_cts_prot fail, use def";
        }
        else
        {
          *(_BYTE *)(v17 + 23) = v114[0] != 0;
          if ( (unsigned int)wlan_mlme_get_mcc_bcast_prob_resp(*a1, v113) )
          {
            v70 = "%s: ucfg_mlme_get_mcc_bcast_prob_resp fail, use def";
          }
          else
          {
            *(_BYTE *)(v17 + 24) = v113[0] != 0;
            if ( (unsigned int)wlan_mlme_get_sta_miracast_mcc_rest_time(*a1, &v112) )
            {
              v70 = "%s: ucfg_mlme_get_sta_miracast_mcc_rest_time, use def";
            }
            else
            {
              *(_DWORD *)(v17 + 1240) = v112;
              if ( !(unsigned int)wlan_mlme_get_sap_mcc_chnl_avoid(*a1, v115) )
                goto LABEL_46;
              v70 = "%s: ucfg_mlme_get_sap_mcc_chnl_avoid, use def";
            }
          }
        }
      }
    }
  }
  qdf_trace_msg(0x33u, 2u, v70, v62, v63, v64, v65, v66, v67, v68, v69, "hdd_set_sme_cfgs_related_to_mlme");
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: hdd_set_sme_cfgs_related_to_mlme() fail: %d",
    v72,
    v73,
    v74,
    v75,
    v76,
    v77,
    v78,
    v79,
    "hdd_set_sme_config",
    16);
LABEL_46:
  v80 = *a1;
  LOBYTE(v112) = 0;
  v117[0] = 0;
  v116[0] = 0;
  v115[0] = 0;
  v114[0] = 0;
  v113[0] = 0;
  if ( (unsigned int)ucfg_policy_mgr_get_mcc_scc_switch(v80, &v112) )
  {
    v89 = "%s: can't get mcc to scc switch";
  }
  else
  {
    *(_BYTE *)(v17 + 1234) = v112;
    if ( (unsigned int)ucfg_policy_mgr_get_conc_rule1(*a1, v115) )
    {
      v89 = "%s: can't get conc rule1";
    }
    else
    {
      *(_BYTE *)(v17 + 1236) = v115[0];
      if ( (unsigned int)ucfg_policy_mgr_get_conc_rule2(*a1, v114)
        || (*(_BYTE *)(v17 + 1237) = v114[0], (unsigned int)ucfg_policy_mgr_get_sta_cxn_5g_band(*a1, v113)) )
      {
        v89 = "%s: can't get conc rule2";
      }
      else
      {
        *(_BYTE *)(v17 + 1238) = v113[0];
        if ( (unsigned int)ucfg_policy_mgr_get_force_1x1(*a1, v117) )
        {
          v89 = "%s: can't get force 1x1 flag";
        }
        else
        {
          *(_DWORD *)(v17 + 1244) = v117[0];
          if ( !(unsigned int)ucfg_policy_mgr_get_allow_mcc_go_diff_bi(*a1, v116) )
          {
            *(_BYTE *)(v17 + 25) = v116[0];
            goto LABEL_54;
          }
          v89 = "%s: can't get allow mcc go diff BI flag";
        }
      }
    }
  }
  qdf_trace_msg(0x33u, 2u, v89, v81, v82, v83, v84, v85, v86, v87, v88, "hdd_set_sme_cfgs_related_to_plcy_mgr");
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: hdd_set_sme_cfgs_related_to_plcy_mgr fail: %d",
    v90,
    v91,
    v92,
    v93,
    v94,
    v95,
    v96,
    v97,
    "hdd_set_sme_config",
    16);
LABEL_54:
  qdf_trace_msg(0x33u, 8u, "%s: dot11Mode=%d", v81, v82, v83, v84, v85, v86, v87, v88, "hdd_set_sme_config", *v3);
  updated = sme_update_config(v2, v17);
  if ( updated )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: sme_update_config() failure: %d",
      v98,
      v99,
      v100,
      v101,
      v102,
      v103,
      v104,
      v105,
      "hdd_set_sme_config",
      updated);
  _qdf_mem_free(v17);
LABEL_57:
  _ReadStatusReg(SP_EL0);
  return updated;
}
