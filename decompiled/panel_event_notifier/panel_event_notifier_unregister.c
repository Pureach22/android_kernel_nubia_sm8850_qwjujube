__int64 __fastcall panel_event_notifier_unregister(__int64 result)
{
  __int64 v1; // x19

  if ( result )
  {
    v1 = result;
    mutex_lock(&panel_event_notifier_entries_lock);
    *(_DWORD *)(v1 + 24) = 0;
    *(_QWORD *)(v1 + 8) = 0;
    *(_QWORD *)(v1 + 16) = 0;
    *(_QWORD *)v1 = 0;
    return mutex_unlock(&panel_event_notifier_entries_lock);
  }
  return result;
}
