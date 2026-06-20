__int64 __fastcall qti_amoled_ecm_remove(__int64 a1)
{
  __int64 result; // x0

  result = *(_QWORD *)(*(_QWORD *)(a1 + 168) + 208LL);
  if ( result )
    return panel_event_notifier_unregister();
  return result;
}
