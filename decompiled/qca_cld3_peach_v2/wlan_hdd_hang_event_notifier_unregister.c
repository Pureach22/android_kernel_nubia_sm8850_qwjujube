__int64 wlan_hdd_hang_event_notifier_unregister()
{
  return qdf_hang_event_unregister_notifier(&hdd_recovery_notifier);
}
