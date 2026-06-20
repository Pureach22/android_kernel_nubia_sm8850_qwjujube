__int64 __fastcall sysmon_start(__int64 a1)
{
  _UNKNOWN **i; // x23

  *(_DWORD *)(a1 + 344) = 0;
  mutex_lock(a1 + 64);
  *(_DWORD *)(a1 + 56) = 1;
  blocking_notifier_call_chain(&sysmon_notifiers, 0, a1);
  mutex_unlock(a1 + 64);
  mutex_lock(&sysmon_lock);
  for ( i = (_UNKNOWN **)sysmon_list; i != &sysmon_list; i = (_UNKNOWN **)*i )
  {
    mutex_lock(i - 6);
    if ( i - 14 != (_UNKNOWN **)a1 && *((_DWORD *)i - 14) == 1 )
      ((void (__fastcall *)(__int64, _UNKNOWN **))send_event)(a1, i - 14);
    mutex_unlock(i - 6);
  }
  mutex_unlock(&sysmon_lock);
  return 0;
}
