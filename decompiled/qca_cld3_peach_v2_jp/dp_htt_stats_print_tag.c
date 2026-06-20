__int64 __fastcall dp_htt_stats_print_tag(__int64 result, char a2, __int64 a3)
{
  __int64 v3; // x19

  switch ( a2 )
  {
    case 0:
      result = dp_print_tx_pdev_stats_cmn_tlv(a3);
      break;
    case 1:
      result = dp_print_tx_pdev_stats_urrn_tlv_v(a3);
      break;
    case 2:
      result = dp_print_tx_pdev_stats_sifs_tlv_v(a3);
      break;
    case 3:
      result = dp_print_tx_pdev_stats_flush_tlv_v(a3);
      break;
    case 4:
      result = dp_print_tx_pdev_stats_phy_err_tlv_v(a3);
      break;
    case 5:
      result = dp_print_stats_string_tlv(a3);
      break;
    case 6:
      result = dp_print_tx_hwq_stats_cmn_tlv(a3);
      break;
    case 7:
      result = dp_print_tx_hwq_difs_latency_stats_tlv_v(a3);
      break;
    case 8:
      result = dp_print_tx_hwq_cmd_result_stats_tlv_v(a3);
      break;
    case 9:
      result = dp_print_tx_hwq_cmd_stall_stats_tlv_v(a3);
      break;
    case 10:
      result = dp_print_tx_hwq_fes_result_stats_tlv_v(a3);
      break;
    case 11:
      result = dp_print_tx_tqm_gen_mpdu_stats_tlv_v(a3);
      break;
    case 12:
      result = dp_print_tx_tqm_list_mpdu_stats_tlv_v(a3);
      break;
    case 13:
      result = dp_print_tx_tqm_list_mpdu_cnt_tlv_v(a3);
      break;
    case 14:
      result = dp_print_tx_tqm_cmn_stats_tlv(a3);
      break;
    case 15:
      result = dp_print_tx_tqm_pdev_stats_tlv_v(a3);
      break;
    case 16:
      result = dp_print_tx_tqm_cmdq_status_tlv(a3);
      break;
    case 17:
      result = dp_print_tx_de_eapol_packets_stats_tlv(a3);
      break;
    case 18:
      result = dp_print_tx_de_classify_failed_stats_tlv(a3);
      break;
    case 19:
      result = dp_print_tx_de_classify_stats_tlv(a3);
      break;
    case 20:
      result = dp_print_tx_de_classify_status_stats_tlv(a3);
      break;
    case 21:
      result = dp_print_tx_de_enqueue_packets_stats_tlv(a3);
      break;
    case 22:
      result = dp_print_tx_de_enqueue_discard_stats_tlv(a3);
      break;
    case 23:
      result = dp_print_tx_de_cmn_stats_tlv(a3);
      break;
    case 24:
      result = dp_print_ring_if_stats_tlv(a3);
      break;
    case 25:
      result = dp_print_tx_pdev_mu_mimo_sch_stats_tlv(a3);
      break;
    case 26:
      result = dp_print_sfm_cmn_tlv(a3);
      break;
    case 27:
      result = dp_print_sring_stats_tlv(a3);
      break;
    case 28:
      result = dp_print_rx_pdev_fw_stats_tlv(a3);
      break;
    case 29:
      result = dp_print_rx_pdev_fw_ring_mpdu_err_tlv_v(a3);
      break;
    case 30:
      result = dp_print_rx_pdev_fw_mpdu_drop_tlv_v(a3);
      break;
    case 31:
      result = dp_print_rx_soc_fw_stats_tlv(a3);
      break;
    case 32:
      result = dp_print_rx_soc_fw_refill_ring_empty_tlv_v(a3);
      break;
    case 33:
      result = dp_print_rx_soc_fw_refill_ring_num_refill_tlv_v(a3);
      break;
    case 34:
      result = dp_print_tx_pdev_rate_stats_tlv(a3);
      break;
    case 35:
      result = dp_print_rx_pdev_rate_stats_tlv(result, a3);
      break;
    case 36:
      result = dp_print_tx_pdev_stats_sched_per_txq_tlv(a3);
      break;
    case 37:
      result = dp_print_stats_tx_sched_cmn_tlv(a3);
      break;
    case 39:
      result = dp_print_sched_txq_cmd_posted_tlv_v(a3);
      break;
    case 40:
      result = dp_print_ring_if_cmn_tlv(a3);
      break;
    case 41:
      result = dp_print_sfm_client_user_tlv_v(a3);
      break;
    case 42:
      result = dp_print_sfm_client_tlv(a3);
      break;
    case 43:
      result = dp_print_tx_tqm_error_stats_tlv(a3);
      break;
    case 44:
      result = dp_print_sched_txq_cmd_reaped_tlv_v(a3);
      break;
    case 45:
      result = dp_print_sring_cmn_tlv(a3);
      break;
    case 46:
      result = dp_print_tx_selfgen_ac_err_stats_tlv(a3);
      break;
    case 47:
      result = dp_print_tx_selfgen_cmn_stats_tlv(a3);
      break;
    case 48:
      result = dp_print_tx_selfgen_ac_stats_tlv(a3);
      break;
    case 49:
      result = dp_print_tx_selfgen_ax_stats_tlv(a3);
      break;
    case 50:
      result = dp_print_tx_selfgen_ax_err_stats_tlv(a3);
      break;
    case 51:
      result = dp_print_tx_hwq_mu_mimo_sch_stats_tlv(a3);
      break;
    case 52:
      result = dp_print_tx_hwq_mu_mimo_mpdu_stats_tlv(a3);
      break;
    case 53:
      result = dp_print_tx_hwq_mu_mimo_cmn_stats_tlv(a3);
      break;
    case 54:
      result = dp_print_hw_stats_intr_misc_tlv(a3);
      break;
    case 55:
      result = dp_print_hw_stats_wd_timeout_tlv(a3);
      break;
    case 56:
      result = dp_print_hw_stats_pdev_errs_tlv(a3);
      break;
    case 57:
      result = dp_print_counter_tlv(a3);
      break;
    case 58:
      result = dp_print_tx_tid_stats_tlv(a3);
      break;
    case 59:
      result = dp_print_rx_tid_stats_tlv(a3);
      break;
    case 60:
      result = dp_print_peer_stats_cmn_tlv(a3);
      break;
    case 61:
      result = dp_print_peer_details_tlv(a3);
      break;
    case 62:
      result = dp_print_tx_peer_rate_stats_tlv(a3);
      break;
    case 63:
      result = dp_print_rx_peer_rate_stats_tlv(a3);
      break;
    case 64:
      result = dp_print_msdu_flow_stats_tlv(a3);
      break;
    case 65:
      result = dp_print_tx_de_compl_stats_tlv(a3);
      break;
    case 68:
      result = dp_print_rx_pdev_fw_stats_phy_err_tlv(a3);
      break;
    case 69:
      result = dp_print_tx_tid_stats_v1_tlv(a3);
      break;
    case 74:
      result = dp_print_tx_pdev_mu_mimo_mpdu_stats_tlv(a3);
      break;
    case 77:
      v3 = result;
      result = dp_print_rx_soc_fw_refill_ring_num_rxdma_err_tlv(a3);
      *(_DWORD *)(v3 + 504) = result;
      break;
    case 78:
      result = dp_print_rx_soc_fw_refill_ring_num_reo_err_tlv(a3);
      break;
    case 79:
      result = dp_print_rx_reo_debug_stats_tlv(a3);
      break;
    case 80:
      result = dp_print_tx_sounding_stats_tlv(a3);
      break;
    case 103:
      result = dp_print_rx_pdev_rate_ext_stats_tlv(a3);
      break;
    case 121:
      result = dp_print_phy_counters_tlv(a3);
      break;
    case -119:
      result = dp_print_tx_selfgen_be_err_stats_tlv(a3);
      break;
    case -118:
      result = dp_print_tx_selfgen_be_stats_tlv(a3);
      break;
    default:
      return result;
  }
  return result;
}
