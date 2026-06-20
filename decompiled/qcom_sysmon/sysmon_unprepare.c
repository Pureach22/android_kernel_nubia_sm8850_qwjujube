__int64 __fastcall sysmon_unprepare(__int64 a1)
{
  mutex_lock(a1 + 64);
  *(_DWORD *)(a1 + 56) = 3;
  blocking_notifier_call_chain(&sysmon_notifiers, 0, a1);
  return mutex_unlock(a1 + 64);
}
