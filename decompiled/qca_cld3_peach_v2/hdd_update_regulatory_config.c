__int64 __fastcall hdd_update_regulatory_config(__int64 *a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  char coex_unsafe_chan_nb_user_prefer; // w0
  __int64 v37; // x8
  char coex_unsafe_chan_reg_disable; // w0
  __int64 v39; // x8
  char sta_sap_scc_on_indoor_chnl; // w0
  __int64 v41; // x8
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  _QWORD v60[5]; // [xsp+0h] [xbp-80h] BYREF
  __int64 v61; // [xsp+28h] [xbp-58h]
  __int64 v62; // [xsp+30h] [xbp-50h]
  __int64 v63; // [xsp+38h] [xbp-48h]
  __int64 v64; // [xsp+40h] [xbp-40h]
  __int64 v65; // [xsp+48h] [xbp-38h] BYREF
  unsigned __int8 v66[4]; // [xsp+54h] [xbp-2Ch] BYREF
  _BYTE v67[4]; // [xsp+58h] [xbp-28h] BYREF
  _BYTE v68[4]; // [xsp+5Ch] [xbp-24h] BYREF
  _BYTE v69[4]; // [xsp+60h] [xbp-20h] BYREF
  _BYTE v70[4]; // [xsp+64h] [xbp-1Ch] BYREF
  int v71; // [xsp+68h] [xbp-18h] BYREF
  _BYTE v72[4]; // [xsp+6Ch] [xbp-14h] BYREF
  int v73; // [xsp+70h] [xbp-10h] BYREF
  _BYTE v74[4]; // [xsp+74h] [xbp-Ch] BYREF
  __int64 v75; // [xsp+78h] [xbp-8h]

  v75 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v64 = 0;
  v65 = 0;
  v62 = 0;
  v63 = 0;
  v61 = 0;
  v74[0] = 0;
  LODWORD(v60[0]) = 0;
  v73 = 0;
  v72[0] = 0;
  v71 = 0;
  v70[0] = 0;
  v69[0] = 0;
  v68[0] = 0;
  v66[0] = 1;
  v67[0] = 0;
  if ( (unsigned int)wlan_mlme_get_band_capability(v2, v60) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to get MLME band cap, defaulting to BAND_ALL",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "reg_program_config_vars");
  if ( (unsigned int)ucfg_policy_mgr_get_indoor_chnl_marking(*a1, v74) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: can't get indoor channel marking, using default",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "reg_program_config_vars");
  if ( (unsigned int)wlan_mlme_is_11d_enabled(*a1, v67) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Invalid 11d_enable flag",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "reg_program_config_vars");
  v27 = *a1;
  LODWORD(v61) = v67[0];
  ucfg_mlme_get_nol_across_regdmn(v27, v67);
  v28 = *a1;
  BYTE3(v65) = v67[0];
  ucfg_mlme_get_scan_11d_interval(v28, &v73);
  v29 = *a1;
  HIDWORD(v61) = v73;
  wlan_mlme_get_sap_country_priority(v29, v68);
  v30 = *a1;
  LODWORD(v62) = v68[0];
  wlan_scan_cfg_get_dfs_chan_scan_allowed(v30, v66);
  v31 = *a1;
  LODWORD(v63) = v66[0];
  ucfg_mlme_get_indoor_channel_support(v31, v72);
  v32 = *a1;
  HIDWORD(v63) = v72[0];
  LODWORD(v64) = v74[0];
  HIDWORD(v62) = v60[0];
  ucfg_mlme_get_restart_beaconing_on_ch_avoid(v32, &v71);
  v33 = *a1;
  HIDWORD(v64) = v71;
  ucfg_mlme_get_etsi_srd_chan_in_master_mode(v33, v70);
  v34 = *a1;
  LOBYTE(v65) = v70[0];
  ucfg_mlme_get_11d_in_world_mode(v34, (_BYTE *)&v65 + 1);
  ucfg_mlme_get_5dot9_ghz_chan_in_master_mode(*a1, v69);
  v35 = *a1;
  BYTE2(v65) = v69[0];
  coex_unsafe_chan_nb_user_prefer = ucfg_mlme_get_coex_unsafe_chan_nb_user_prefer(v35);
  v37 = *a1;
  BYTE4(v65) = coex_unsafe_chan_nb_user_prefer & 1;
  coex_unsafe_chan_reg_disable = ucfg_mlme_get_coex_unsafe_chan_reg_disable(v37);
  v39 = *a1;
  BYTE5(v65) = coex_unsafe_chan_reg_disable & 1;
  sta_sap_scc_on_indoor_chnl = ucfg_policy_mgr_get_sta_sap_scc_on_indoor_chnl(v39);
  v41 = *a1;
  BYTE6(v65) = sta_sap_scc_on_indoor_chnl & 1;
  HIBYTE(v65) = ucfg_p2p_get_indoor_ch_support(v41, v42, v43, v44, v45, v46, v47, v48, v49) & 1;
  v50 = *a1;
  v60[2] = v63;
  v60[3] = v64;
  v60[4] = v65;
  v60[0] = v61;
  v60[1] = v62;
  ucfg_reg_set_config_vars(v50, v60, v51, v52, v53, v54, v55, v56, v57, v58);
  _ReadStatusReg(SP_EL0);
  return 0;
}
