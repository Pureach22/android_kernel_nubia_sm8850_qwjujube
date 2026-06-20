__int64 wmi_hang_event_notifier_unregister()
{
  return qdf_hang_event_unregister_notifier((__int64)&wmi_recovery_notifier);
}
