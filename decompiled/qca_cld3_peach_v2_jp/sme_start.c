__int64 __fastcall sme_start(__int64 a1)
{
  unsigned int v2; // w0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int v11; // w20
  const char *v12; // x2
  __int64 v13; // x0
  unsigned int v14; // w0
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  _QWORD v25[9]; // [xsp+0h] [xbp-70h] BYREF
  _QWORD v26[5]; // [xsp+48h] [xbp-28h] BYREF

  v26[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = csr_start();
  if ( v2 )
  {
    v11 = v2;
    v12 = "%s: csr_start failed status: %d";
LABEL_5:
    qdf_trace_msg(0x34u, 2u, v12, v3, v4, v5, v6, v7, v8, v9, v10, "sme_start", v11);
    goto LABEL_6;
  }
  v13 = *(_QWORD *)(a1 + 21552);
  v25[2] = sme_pdev_set_hw_mode;
  v25[3] = sme_nss_update_request;
  v25[0] = sme_get_vdev_type_nss;
  v25[1] = sme_soc_set_dual_mac_config;
  v25[4] = sme_change_mcc_beacon_interval;
  v25[5] = sme_start_roaming;
  v25[6] = sme_stop_roaming;
  v25[7] = sme_change_sap_csa_count;
  v25[8] = sme_sap_update_ch_width;
  v14 = policy_mgr_register_sme_cb(v13, v25);
  if ( v14 )
  {
    v11 = v14;
    v12 = "%s: Failed to register sme cb with Policy Manager: %d";
    goto LABEL_5;
  }
  v16 = *(_QWORD *)(a1 + 21552);
  v26[0] = sme_get_oper_chan_freq;
  v26[1] = 0;
  v26[2] = sme_get_oper_ch_width;
  v26[3] = sme_get_sec20chan_freq_mhz;
  spectral_register_legacy_cb(v16, v26);
  *(_DWORD *)(a1 + 12768) = 1;
  v11 = rrm_start(a1);
  if ( v11 )
    qdf_trace_msg(0x34u, 2u, "%s: Failed to start RRM", v17, v18, v19, v20, v21, v22, v23, v24, "sme_start");
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return v11;
}
