__int64 __fastcall dp_mon_register_feature_ops_1_0(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x29
  __int64 v10; // x30
  __int64 v11; // x8
  _QWORD *v12; // x8

  if ( !result )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: mon_ops is NULL, feature ops registration failed",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "dp_mon_register_feature_ops_1_0",
             v9,
             v10);
  v11 = *(_QWORD *)(result + 20056);
  if ( !v11 )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: mon_ops is NULL, feature ops registration failed",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "dp_mon_register_feature_ops_1_0",
             v9,
             v10);
  v12 = *(_QWORD **)(v11 + 416);
  if ( !v12 )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: mon_ops is NULL, feature ops registration failed",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "dp_mon_register_feature_ops_1_0",
             v9,
             v10);
  v12[24] = dp_config_debug_sniffer;
  v12[38] = 0;
  v12[36] = dp_mon_peer_tx_init;
  v12[37] = dp_mon_peer_tx_cleanup;
  v12[41] = 0;
  v12[47] = dp_htt_ppdu_stats_attach;
  v12[48] = dp_htt_ppdu_stats_detach;
  v12[43] = 0;
  v12[53] = dp_mon_set_bsscolor;
  v12[54] = dp_pdev_get_filter_ucast_data;
  v12[51] = 0;
  v12[52] = 0;
  v12[55] = dp_pdev_get_filter_non_data;
  v12[56] = dp_pdev_get_filter_mcast_data;
  v12[69] = dp_mon_neighbour_peer_add_ast;
  v12[49] = &dp_print_pdev_rx_mon_stats;
  v12[50] = 0;
  v12[70] = dp_mon_set_reset_mon_mac_filter_1_0;
  v12[75] = dp_mon_filter_setup_rx_pkt_log_full_1_0;
  v12[76] = dp_mon_filter_reset_rx_pkt_log_full_1_0;
  v12[77] = dp_mon_filter_setup_rx_pkt_log_lite_1_0;
  v12[78] = dp_mon_filter_reset_rx_pkt_log_lite_1_0;
  v12[79] = dp_mon_filter_setup_rx_pkt_log_cbf_1_0;
  v12[80] = dp_mon_filter_reset_rx_pktlog_cbf_1_0;
  v12[104] = 0;
  v12[57] = dp_set_pktlog_wifi3;
  v12[58] = &dp_vdev_set_monitor_mode_buf_rings;
  v12[106] = 0;
  v12[59] = &dp_vdev_set_monitor_mode_rings;
  v12[60] = dp_neighbour_peers_detach;
  v12[128] = dp_mon_mac_filter_set;
  v12[107] = 0;
  v12[108] = 0;
  v12[109] = 0;
  v12[110] = 0;
  v12[111] = 0;
  v12[125] = 0;
  v12[132] = dp_rx_mon_config_fcs_cap;
  return result;
}
