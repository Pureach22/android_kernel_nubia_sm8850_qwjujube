_QWORD *__fastcall dp_mon_register_lpc_ops_1_0(_QWORD *result)
{
  result[1] = 0;
  result[2] = dp_mon_soc_attach_2_0;
  result[42] = 0;
  result[3] = 0;
  result[4] = dp_mon_soc_detach_2_0;
  result[5] = 0;
  result[6] = dp_mon_soc_init_2_0;
  result[7] = 0;
  result[8] = dp_mon_soc_deinit_2_0;
  result[26] = &dp_mon_htt_srng_setup_1_0;
  result[27] = &dp_mon_pdev_htt_srng_setup_2_0;
  result[28] = dp_mon_soc_htt_srng_setup_2_0;
  result[86] = dp_mon_rings_alloc_1_0;
  result[88] = dp_mon_rings_free_1_0;
  result[90] = dp_mon_rings_init_1_0;
  result[92] = dp_mon_rings_deinit_1_0;
  result[87] = &dp_pdev_mon_rings_alloc_2_0;
  result[89] = dp_pdev_mon_rings_free_2_0;
  result[91] = &dp_pdev_mon_rings_init_2_0;
  result[93] = dp_pdev_mon_rings_deinit_2_0;
  result[73] = dp_mon_filter_setup_local_pkt_capture_tx;
  result[74] = dp_mon_filter_reset_local_pkt_capture_tx;
  result[82] = dp_tx_mon_filter_update_2_0;
  result[105] = dp_rx_mon_hdr_length_set;
  result[39] = dp_tx_ppdu_stats_attach_2_0;
  result[40] = dp_tx_ppdu_stats_detach_2_0;
  return result;
}
