__int64 __fastcall target_if_mlo_register_tx_ops(
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
  __int64 v9; // x29
  __int64 v10; // x30

  if ( a1 )
  {
    a1[248] = target_if_mlo_register_event_handler;
    a1[249] = target_if_mlo_unregister_event_handler;
    a1[250] = target_if_mlo_link_set_active;
    a1[253] = target_if_mlo_send_tid_to_link_mapping;
    a1[254] = target_if_mlo_send_link_removal_cmd;
    a1[251] = target_if_request_ml_link_state_info;
    a1[252] = target_if_send_link_set_bss_params_cmd;
    a1[255] = target_if_mlo_send_vdev_pause;
    a1[256] = target_if_send_mlo_link_switch_cnf_cmd;
    a1[257] = target_if_send_mlo_link_recfg_complete_cmd;
    a1[259] = target_if_send_ttlm_complete_cmd;
    a1[260] = target_if_mlo_send_wsi_link_info_cmd;
    a1[258] = target_if_send_link_reconfig_req_cmd;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: lmac tx ops is NULL!",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_mlo_register_tx_ops",
      v9,
      v10);
    return 4;
  }
}
