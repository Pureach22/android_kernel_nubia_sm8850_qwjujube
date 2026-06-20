__int64 wlan_logging_wait_for_flush_log_completion()
{
  qdf_event_reset((__int64)&unk_826D10);
  return qdf_wait_for_event_completion((__int64)&unk_826D10, 0xBB8u);
}
