__int64 htc_hang_event_notifier_unregister()
{
  return qdf_hang_event_unregister_notifier(&htc_recovery_notifier);
}
