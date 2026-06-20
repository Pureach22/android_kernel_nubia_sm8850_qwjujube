__int64 __fastcall dp_mon_register_feature_ops_2_0(
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
             "dp_mon_register_feature_ops_2_0",
             v9,
             v10);
  v11 = *(_QWORD *)(result + 20112);
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
             "dp_mon_register_feature_ops_2_0",
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
             "dp_mon_register_feature_ops_2_0",
             v9,
             v10);
  v12[24] = dp_config_debug_sniffer_0;
  v12[36] = 0;
  v12[37] = 0;
  v12[48] = dp_htt_ppdu_stats_detach;
  v12[49] = &dp_print_pdev_rx_mon_stats;
  v12[69] = 0;
  v12[54] = dp_lite_mon_get_filter_ucast_data;
  v12[55] = dp_lite_mon_get_filter_non_data;
  v12[38] = 0;
  v12[50] = dp_print_pdev_tx_monitor_stats_2_0;
  v12[51] = dp_config_enh_tx_monitor_2_0;
  v12[41] = 0;
  v12[52] = dp_peer_set_tx_capture_enabled_2_0;
  v12[53] = dp_mon_set_bsscolor;
  v12[43] = 0;
  v12[46] = dp_get_pdev_tx_capture_stats_2_0;
  v12[47] = dp_htt_ppdu_stats_attach;
  v12[128] = 0;
  v12[56] = dp_lite_mon_get_filter_mcast_data;
  v12[57] = dp_set_pktlog_wifi3;
  v12[75] = dp_mon_filter_setup_rx_pkt_log_full_2_0;
  v12[76] = dp_mon_filter_reset_rx_pkt_log_full_2_0;
  v12[77] = dp_mon_filter_setup_rx_pkt_log_lite_2_0;
  v12[78] = dp_mon_filter_reset_rx_pkt_log_lite_2_0;
  v12[79] = dp_mon_filter_setup_rx_pkt_log_cbf_2_0;
  v12[80] = dp_mon_filter_reset_rx_pktlog_cbf_2_0;
  v12[105] = dp_rx_mon_hdr_length_set;
  v12[106] = dp_rx_mon_packet_length_set;
  v12[104] = dp_rx_mon_enable_set;
  v12[107] = dp_rx_mon_word_mask_subscribe;
  v12[108] = dp_rx_mon_pkt_tlv_offset_subscribe;
  v12[109] = dp_rx_mon_enable_mpdu_logging;
  v12[58] = dp_vdev_set_monitor_mode_buf_rings_2_0;
  v12[110] = dp_rx_mon_enable_fpmo;
  v12[111] = dp_rx_mon_config_packet_type_subtype;
  v12[125] = dp_mon_rx_print_advanced_stats_2_0;
  v12[59] = dp_vdev_set_monitor_mode_rings_2_0;
  v12[60] = 0;
  v12[132] = dp_rx_mon_config_fcs_cap;
  return result;
}
