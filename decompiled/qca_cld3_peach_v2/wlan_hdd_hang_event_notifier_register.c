__int64 __fastcall wlan_hdd_hang_event_notifier_register(__int64 a1)
{
  qword_68990 = a1;
  return qdf_hang_event_register_notifier(&hdd_recovery_notifier);
}
