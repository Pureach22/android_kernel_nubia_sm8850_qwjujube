__int64 __fastcall target_if_scan_tx_ops_register(_QWORD *a1)
{
  a1[7] = target_if_scan_start;
  a1[8] = target_if_scan_cancel;
  a1[9] = target_if_pno_start;
  a1[10] = target_if_pno_stop;
  a1[11] = target_if_obss_scan_disable;
  a1[12] = target_if_scan_register_event_handler;
  a1[13] = target_if_scan_unregister_event_handler;
  a1[15] = target_if_is_platform_eht_capable;
  a1[16] = target_if_scan_request_cached_scan_report;
  a1[17] = target_if_scan_get_cached_scan_report_fw_cap;
  return 0;
}
