__int64 __fastcall target_if_register_regulatory_tx_ops(_QWORD *a1)
{
  a1[107] = tgt_if_regulatory_register_master_list_handler;
  a1[108] = tgt_if_regulatory_unregister_master_list_handler;
  a1[109] = tgt_if_regulatory_register_master_list_ext_handler;
  a1[110] = tgt_if_regulatory_unregister_master_list_ext_handler;
  a1[128] = tgt_if_regulatory_register_c2c_detect_event_handler;
  a1[129] = tgt_if_regulatory_unregister_c2c_detect_event_handler;
  a1[112] = tgt_if_regulatory_set_country_code;
  a1[114] = tgt_if_regulatory_register_11d_new_cc_handler;
  a1[115] = tgt_if_regulatory_unregister_11d_new_cc_handler;
  a1[116] = tgt_if_regulatory_start_11d_scan;
  a1[117] = tgt_if_regulatory_stop_11d_scan;
  a1[118] = tgt_if_regulatory_is_there_serv_ready_extn;
  a1[119] = tgt_if_regulatory_set_user_country_code;
  a1[120] = tgt_if_regulatory_register_ch_avoid_event_handler;
  a1[121] = tgt_if_regulatory_unregister_ch_avoid_event_handler;
  a1[122] = tgt_if_regulatory_send_ctl_info;
  a1[123] = tgt_if_regulatory_get_phy_id_from_pdev_id;
  a1[124] = tgt_if_regulatory_get_pdev_id_from_phy_id;
  a1[125] = tgt_if_regulatory_set_tpc_power;
  a1[130] = tgt_if_reg_is_chip_11be_cap;
  a1[131] = tgt_if_regulatory_register_rate2power_table_update_handler;
  a1[132] = tgt_if_regulatory_unregister_rate2power_table_update_handler;
  a1[136] = tgt_if_regulatory_txpb_send_dma_addr;
  a1[137] = tgt_if_regulatory_txpb_send_inference_cmd;
  a1[138] = tgt_if_reg_txpb_register_event_handler;
  a1[113] = 0;
  a1[139] = tgt_if_reg_txpb_unregister_event_handler;
  a1[111] = 0;
  a1[127] = 0;
  a1[126] = 0;
  a1[133] = 0;
  a1[134] = 0;
  a1[135] = 0;
  return 0;
}
