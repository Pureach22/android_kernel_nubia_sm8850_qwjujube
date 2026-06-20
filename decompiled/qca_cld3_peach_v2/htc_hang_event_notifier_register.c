__int64 __fastcall htc_hang_event_notifier_register(__int64 a1)
{
  qword_689B0 = a1;
  return qdf_hang_event_register_notifier(&htc_recovery_notifier);
}
