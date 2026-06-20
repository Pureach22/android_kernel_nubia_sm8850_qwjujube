__int64 __fastcall target_if_register_tx_ops(_QWORD *a1)
{
  void (__fastcall *v2)(_QWORD *); // x8
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  target_if_register_afc_tx_ops();
  target_if_register_regulatory_tx_ops(a1);
  v2 = (void (__fastcall *)(_QWORD *))wlan_lmac_if_umac_tx_ops_register;
  if ( *((_DWORD *)wlan_lmac_if_umac_tx_ops_register - 1) != -1972930274 )
    __break(0x8228u);
  v2(a1);
  target_if_scan_tx_ops_register(a1);
  target_if_cfr_tx_ops_register(a1);
  target_if_wifi_pos_register_tx_ops(a1);
  target_if_register_dfs_tx_ops(a1);
  target_if_spatial_reuse_register_tx_ops(a1);
  target_if_tdls_register_tx_ops(a1);
  if ( a1 )
  {
    a1[208] = target_is_tgt_type_ar900b;
    a1[209] = target_is_tgt_type_qca9984;
    a1[210] = target_is_tgt_type_qca9888;
    a1[211] = target_is_tgt_type_adrastea;
    a1[212] = target_is_tgt_type_qcn9000;
    a1[213] = target_is_tgt_type_qcn6122;
    a1[214] = target_is_tgt_type_qcn9160;
    a1[216] = target_is_tgt_type_qcn6432;
    a1[215] = target_is_tgt_type_qcn7605;
    a1[217] = lmac_get_tgt_type;
    a1[218] = lmac_get_tgt_version;
    a1[219] = lmac_get_tgt_revision;
  }
  else
  {
    qdf_trace_msg(0x49u, 2u, "%s: invalid tx_ops", v3, v4, v5, v6, v7, v8, v9, v10, "target_if_target_tx_ops_register");
  }
  target_if_register_green_ap_tx_ops(a1);
  target_if_ftm_register_tx_ops(a1);
  target_if_cp_stats_register_tx_ops(a1);
  target_if_dcs_register_tx_ops(a1);
  target_if_crypto_register_tx_ops(a1);
  target_if_vdev_mgr_register_tx_ops(a1);
  target_if_coex_register_tx_ops(a1);
  target_if_gpio_register_tx_ops(a1);
  target_if_ipa_register_tx_ops(a1);
  target_if_twt_register_tx_ops(a1);
  target_if_dbam_register_tx_ops(a1);
  target_if_coap_register_tx_ops(a1);
  target_if_sptrl_register_tx_ops(a1);
  target_if_direct_buf_rx_register_tx_ops(a1);
  target_if_p2p_register_tx_ops(a1);
  return 0;
}
