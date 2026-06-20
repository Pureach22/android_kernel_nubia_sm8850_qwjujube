void hdd_scan_context_destroy()
{
  cds_unregister_scan_flush_recovery_callback();
}
