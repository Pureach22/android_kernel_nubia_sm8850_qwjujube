void *__fastcall cds_register_scan_flush_recovery_callback(void *result)
{
  cds_scan_flush_recovery_callback = result;
  return result;
}
