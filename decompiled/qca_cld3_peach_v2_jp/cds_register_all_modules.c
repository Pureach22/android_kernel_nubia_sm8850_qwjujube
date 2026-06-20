__int64 cds_register_all_modules()
{
  scheduler_register_wma_legacy_handler((__int64)wma_mc_process_handler);
  scheduler_register_sys_legacy_handler((__int64)sys_mc_process_handler);
  scheduler_register_module(55, (__int64)scheduler_timer_q_mq_handler);
  scheduler_register_module(73, (__int64)scheduler_target_if_mq_handler);
  scheduler_register_module(53, (__int64)pe_mc_process_handler);
  scheduler_register_module(52, (__int64)sme_mc_process_handler);
  scheduler_register_module(72, (__int64)scheduler_os_if_mq_handler);
  return scheduler_register_module(21, (__int64)scheduler_scan_mq_handler);
}
