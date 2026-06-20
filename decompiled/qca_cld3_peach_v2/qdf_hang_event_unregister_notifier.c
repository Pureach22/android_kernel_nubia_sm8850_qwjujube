__int64 __fastcall qdf_hang_event_unregister_notifier(__int64 a1)
{
  return qdf_unregister_atomic_notifier_chain(&qdf_hang_event_notif_head, a1);
}
