__int64 __fastcall hdd_configure_cds(__int64 *a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  const char *v12; // x2
  int v13; // w21
  int v14; // w8
  _DWORD *v15; // x9
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v24; // w8
  int v25; // w9
  _DWORD *v26; // x10
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 result; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  const char *v44; // x2
  unsigned int v45; // w1
  __int64 v46; // x0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  _DWORD *v55; // x20
  int v56; // w9
  __int64 v57; // x0
  int auto_power_fail_mode; // w0
  __int64 v59; // x8
  int v60; // w8
  __int64 v61; // x3
  char v62[4]; // [xsp+8h] [xbp-98h] BYREF
  char v63[4]; // [xsp+Ch] [xbp-94h] BYREF
  __int64 (__fastcall *v64)(); // [xsp+10h] [xbp-90h] BYREF
  __int64 (__fastcall *v65)(char); // [xsp+18h] [xbp-88h]
  __int64 (__fastcall *v66)(); // [xsp+20h] [xbp-80h]
  __int64 (__fastcall *v67)(); // [xsp+28h] [xbp-78h]
  __int64 (__fastcall *v68)(); // [xsp+30h] [xbp-70h]
  __int64 (__fastcall *v69)(); // [xsp+38h] [xbp-68h]
  unsigned __int16 v70[2]; // [xsp+40h] [xbp-60h] BYREF
  unsigned __int16 v71; // [xsp+44h] [xbp-5Ch] BYREF
  char v72[4]; // [xsp+48h] [xbp-58h] BYREF
  char v73[4]; // [xsp+4Ch] [xbp-54h] BYREF
  char v74[4]; // [xsp+50h] [xbp-50h] BYREF
  char v75[4]; // [xsp+54h] [xbp-4Ch] BYREF
  _QWORD v76[9]; // [xsp+58h] [xbp-48h] BYREF

  v76[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[2];
  v3 = *a1;
  v75[0] = 0;
  v74[0] = 0;
  v73[0] = 0;
  v72[0] = 0;
  v71 = 0;
  v70[0] = 0;
  v68 = nullptr;
  v69 = nullptr;
  v66 = nullptr;
  v67 = nullptr;
  v64 = nullptr;
  v65 = nullptr;
  v63[0] = 0;
  v62[0] = 0;
  memset(v76, 0, 64);
  if ( !(unsigned int)ucfg_policy_mgr_get_force_1x1(v3, v72) )
  {
    if ( v72[0] )
    {
      v13 = 1;
      v76[0] = 0x100000094LL;
    }
    else
    {
      v13 = 0;
    }
    sme_set_chip_pwr_save_fail_cb(v2, hdd_chip_pwr_save_fail_detected_cb);
    if ( (unsigned int)ucfg_get_max_mpdus_inampdu(*a1, v73) )
    {
      v12 = "%s: Failed to get max mpdus in ampdu value";
      goto LABEL_40;
    }
    v14 = (unsigned __int8)v73[0];
    if ( v73[0] )
    {
      v15 = &v76[v13++];
      *v15 = 138;
      v15[1] = v14;
    }
    if ( (unsigned int)ucfg_get_enable_rts_sifsbursting(*a1, v75) )
    {
      v12 = "%s: Failed to get rts sifs bursting value";
      goto LABEL_40;
    }
    if ( v75[0] == 1 )
      v76[v13++] = 0x100000089LL;
    wlan_mlme_get_sap_get_peer_info(*a1, v63);
    if ( v63[0] == 1 )
      v76[v13++] = 0x10000008BLL;
    if ( (unsigned int)wlan_mlme_get_num_11b_tx_chains(*a1, &v71) )
    {
      v12 = "%s: Failed to get num_11b_tx_chains";
      goto LABEL_40;
    }
    if ( (unsigned int)wlan_mlme_get_num_11ag_tx_chains(*a1, v70) )
    {
      v12 = "%s: Failed to get num_11ag_tx_chains";
      goto LABEL_40;
    }
    if ( (unsigned int)wlan_mlme_get_vht_mimo_cap(*a1, v62) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: unable to get vht_enable2x2",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "hdd_configure_cds");
    v24 = v71;
    if ( v62[0] )
    {
      v25 = v70[0];
    }
    else
    {
      if ( v71 >= 2u )
      {
        v24 = 1;
        v71 = 1;
      }
      v25 = v70[0];
      if ( v70[0] >= 2u )
      {
        v25 = 1;
        v70[0] = 1;
      }
    }
    v26 = &v76[v13];
    *v26 = 150;
    v26[1] = v24 | (v25 << 16);
    if ( (unsigned int)sme_send_multi_pdev_vdev_set_params(0, 0, v76, (unsigned int)(v13 + 1)) )
    {
      v12 = "%s: Failed to send 1st set of pdev params";
      goto LABEL_40;
    }
    if ( (ucfg_reg_is_regdb_offloaded(*a1, v4, v5, v6, v7, v8, v9, v10, v11) & 1) == 0 )
      ucfg_reg_program_default_cc(a1[1], *((_DWORD *)a1 + 152), v27, v28, v29, v30, v31, v32, v33, v34);
    if ( (unsigned int)hdd_pre_enable_configure(a1) )
    {
      v12 = "%s: Failed to pre-configure cds";
      goto LABEL_40;
    }
    if ( curr_con_mode == 5 )
    {
      ipa_disable_register_cb();
    }
    else if ( (unsigned int)ipa_register_is_ipa_ready(a1[1]) )
    {
      v12 = "%s: ipa_register_is_ipa_ready failed";
      goto LABEL_40;
    }
    if ( (unsigned int)cds_enable(*a1, v4, v5, v6, v7, v8, v9, v10, v11) )
    {
      v12 = "%s: cds_enable failed";
      goto LABEL_40;
    }
    if ( (unsigned int)hdd_post_cds_enable_config(a1) )
    {
      v44 = "%s: hdd_post_cds_enable_config failed";
    }
    else
    {
      if ( !(unsigned int)hdd_register_bcn_cb(a1) )
      {
        if ( (unsigned int)hdd_features_init(a1) )
          goto LABEL_49;
        if ( (a1[889] & 1) == 0 && ucfg_dp_is_ol_enabled(*a1) )
          v64 = hdd_disable_rx_ol_in_concurrency;
        v46 = a1[1];
        v65 = ucfg_dp_set_rx_mode_rps;
        v66 = hdd_ipa_set_mcc_mode;
        v67 = hdd_v2_flow_pool_map;
        v68 = hdd_v2_flow_pool_unmap;
        if ( (ucfg_ipa_set_perf_level_bw_enabled(v46) & 1) != 0 )
          v69 = hdd_ipa_set_perf_level_bw;
        if ( (unsigned int)policy_mgr_register_dp_cb(*a1, &v64) )
        {
          v44 = "%s: Failed to register DP cb with Policy Manager";
        }
        else
        {
          if ( !(unsigned int)policy_mgr_register_mode_change_cb(*a1, (__int64)&wlan_hdd_send_mode_change_event) )
          {
            if ( (unsigned int)hdd_green_ap_enable_egap(a1) )
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: enhance green ap is not enabled",
                v47,
                v48,
                v49,
                v50,
                v51,
                v52,
                v53,
                v54,
                "hdd_configure_cds");
            hdd_register_green_ap_callback(a1[1]);
            v55 = &v76[v13 + 1];
            v56 = ucfg_fwol_get_gcmp_enable(*a1) & 1;
            v57 = *a1;
            *v55 = 156;
            v55[1] = v56;
            auto_power_fail_mode = ucfg_pmo_get_auto_power_fail_mode(v57);
            v59 = *a1;
            v55[2] = 153;
            v55[3] = auto_power_fail_mode;
            if ( (unsigned int)ucfg_get_enable_phy_reg_retention(v59, v74) )
              goto LABEL_41;
            v60 = (unsigned __int8)v74[0];
            if ( v74[0] )
            {
              v61 = 3;
              v55[4] = 140;
              v55[5] = v60;
            }
            else
            {
              v61 = 2;
            }
            if ( !(unsigned int)sme_send_multi_pdev_vdev_set_params(0, 0, v55, v61) )
            {
              wlan_hdd_hang_event_notifier_register(a1);
              result = 0;
              goto LABEL_42;
            }
            v12 = "%s: failed to send 2nd set of pdev set params";
            goto LABEL_40;
          }
          v44 = "%s: Failed to register mode change cb with Policy Manager";
        }
        v45 = 8;
LABEL_48:
        qdf_trace_msg(0x33u, v45, v44, v36, v37, v38, v39, v40, v41, v42, v43, "hdd_configure_cds");
LABEL_49:
        cds_disable(*a1);
        goto LABEL_41;
      }
      v44 = "%s: hdd_register_bcn_cb failed";
    }
    v45 = 2;
    goto LABEL_48;
  }
  v12 = "%s: Failed to get force 1x1 value";
LABEL_40:
  qdf_trace_msg(0x33u, 2u, v12, v4, v5, v6, v7, v8, v9, v10, v11, "hdd_configure_cds");
LABEL_41:
  result = 4294967274LL;
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return result;
}
