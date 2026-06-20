__int64 __fastcall qdf_hang_event_register_notifier(__int64 a1)
{
  return qdf_register_atomic_notifier_chain(&qdf_hang_event_notif_head, a1);
}
