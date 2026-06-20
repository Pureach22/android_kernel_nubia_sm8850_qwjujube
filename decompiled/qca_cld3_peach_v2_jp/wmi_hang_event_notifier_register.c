__int64 __fastcall wmi_hang_event_notifier_register(__int64 a1)
{
  qword_67E30 = a1;
  return qdf_hang_event_register_notifier((__int64)&wmi_recovery_notifier);
}
