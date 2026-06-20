_QWORD *__fastcall target_if_sptrl_register_tx_ops(_QWORD *result)
{
  result[61] = target_if_pdev_spectral_init;
  result[62] = target_if_pdev_spectral_deinit;
  result[63] = target_if_psoc_spectral_init;
  result[64] = target_if_psoc_spectral_deinit;
  result[65] = target_if_set_spectral_config;
  result[66] = target_if_get_spectral_config;
  result[67] = target_if_start_spectral_scan;
  result[68] = target_if_stop_spectral_scan;
  result[69] = target_if_is_spectral_active;
  result[70] = target_if_is_spectral_enabled;
  result[71] = target_if_set_debug_level;
  result[72] = target_if_get_debug_level;
  result[73] = target_if_get_spectral_capinfo;
  result[74] = target_if_get_spectral_diagstats;
  result[75] = target_if_register_spectral_wmi_ops;
  result[76] = target_if_register_spectral_tgt_ops;
  result[77] = target_if_register_buffer_cb;
  result[78] = target_if_use_broadcast;
  result[79] = target_if_deregister_buffer_cb;
  result[80] = target_if_process_spectral_report;
  result[82] = target_if_spectral_direct_dma_support;
  result[85] = target_if_spectral_register_events;
  result[86] = target_if_spectral_unregister_events;
  result[87] = target_if_spectral_init_pdev_feature_caps;
  return result;
}
