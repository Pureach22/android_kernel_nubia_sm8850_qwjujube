__int64 __fastcall qdf_hang_event_notifier_call(__int64 a1, __int64 a2)
{
  return qdf_atomic_notfier_call(&qdf_hang_event_notif_head, a1, a2);
}
