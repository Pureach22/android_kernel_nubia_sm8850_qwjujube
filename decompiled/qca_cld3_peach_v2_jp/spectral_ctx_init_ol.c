_QWORD *__fastcall spectral_ctx_init_ol(
        _QWORD *result,
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

  if ( !result )
    return (_QWORD *)qdf_trace_msg(
                       0x56u,
                       2u,
                       "%s: spectral context is null!",
                       a2,
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       "spectral_ctx_init_ol",
                       v9,
                       v10);
  result[6] = tgt_spectral_control;
  result[8] = tgt_pdev_spectral_init;
  result[9] = tgt_pdev_spectral_deinit;
  result[10] = tgt_psoc_spectral_init;
  result[11] = tgt_psoc_spectral_deinit;
  result[12] = tgt_set_spectral_config;
  result[13] = tgt_get_spectral_config;
  result[14] = tgt_start_spectral_scan;
  result[15] = tgt_stop_spectral_scan;
  result[16] = tgt_is_spectral_active;
  result[17] = tgt_is_spectral_enabled;
  result[18] = tgt_set_debug_level;
  result[19] = tgt_get_debug_level;
  result[20] = tgt_get_spectral_capinfo;
  result[21] = tgt_get_spectral_diagstats;
  result[22] = tgt_register_spectral_wmi_ops;
  result[23] = tgt_register_spectral_tgt_ops;
  result[24] = tgt_spectral_register_buffer_cb;
  result[25] = tgt_spectral_use_broadcast;
  result[26] = tgt_spectral_deregister_buffer_cb;
  result[27] = tgt_spectral_process_report;
  result[29] = ucfg_spectral_scan_complete_event;
  return result;
}
