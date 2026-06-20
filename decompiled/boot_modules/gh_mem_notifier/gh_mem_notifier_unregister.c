__int64 __fastcall gh_mem_notifier_unregister(__int64 result)
{
  _QWORD *v1; // x19

  if ( result )
  {
    v1 = (_QWORD *)result;
    mutex_lock(&mem_notifier_entries_lock);
    *v1 = 0;
    v1[1] = 0;
    return mutex_unlock(&mem_notifier_entries_lock);
  }
  return result;
}
