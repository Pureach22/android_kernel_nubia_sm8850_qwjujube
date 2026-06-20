__int64 __fastcall sysmon_prepare(__int64 a1)
{
  mutex_lock(a1 + 64);
  *(_DWORD *)(a1 + 56) = 0;
  blocking_notifier_call_chain(&sysmon_notifiers, 0, a1);
  mutex_unlock(a1 + 64);
  return 0;
}
