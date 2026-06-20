_QWORD *__fastcall target_if_cfr_tx_ops_register(_QWORD *result)
{
  result[48] = target_if_cfr_init_pdev;
  result[49] = target_if_cfr_deinit_pdev;
  result[50] = target_if_cfr_enable_cfr_timer;
  result[51] = target_if_cfr_start_capture;
  result[52] = target_if_cfr_stop_capture;
  result[53] = target_if_cfr_config_rcc;
  result[54] = target_if_cfr_start_lut_age_timer;
  result[55] = target_if_cfr_stop_lut_age_timer;
  result[56] = target_if_cfr_default_ta_ra_config;
  result[57] = target_if_cfr_dump_lut_enh;
  result[58] = target_if_cfr_rx_tlv_process;
  result[59] = target_if_cfr_update_global_cfg;
  result[60] = target_if_cfr_subscribe_ppdu_desc;
  return result;
}
