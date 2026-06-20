__int64 hdd_scan_context_init()
{
  cds_register_scan_flush_recovery_callback(hdd_scan_flush_cds_recovery_handler);
  return 0;
}
