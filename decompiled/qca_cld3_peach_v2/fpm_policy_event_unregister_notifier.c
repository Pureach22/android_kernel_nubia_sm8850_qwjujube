__int64 __fastcall fpm_policy_event_unregister_notifier(__int64 a1, __int64 a2)
{
  return qdf_unregister_atomic_notifier_chain(*(_QWORD *)(a1 + 3712) + 88LL, a2);
}
