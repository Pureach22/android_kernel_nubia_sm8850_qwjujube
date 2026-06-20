__int64 __fastcall target_if_p2p_register_tx_ops(
        _QWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0

  if ( !a1 )
    return qdf_trace_msg(
             0x49u,
             2u,
             "%s: lmac tx_ops is null",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "target_if_p2p_register_tx_ops");
  a1[18] = target_if_p2p_set_ps;
  a1[23] = target_if_p2p_set_noa;
  a1[24] = target_if_p2p_register_noa_event_handler;
  a1[25] = target_if_p2p_unregister_noa_event_handler;
  a1[26] = target_if_p2p_register_macaddr_rx_filter_evt_handler;
  a1[27] = target_if_p2p_set_mac_addr_rx_filter_cmd;
  result = target_if_mcc_quota_register_tx_ops();
  a1[19] = target_if_p2p_lo_start;
  a1[20] = target_if_p2p_lo_stop;
  a1[21] = target_if_p2p_register_lo_event_handler;
  a1[22] = target_if_p2p_unregister_lo_event_handler;
  a1[28] = target_if_p2p_unreg_assist_dfs_group_bmiss_evt_handler;
  a1[29] = target_if_p2p_reg_assist_dfs_group_bmiss_evt_handler;
  a1[30] = target_if_p2p_send_ap_assist_dfs_group_params;
  return result;
}
