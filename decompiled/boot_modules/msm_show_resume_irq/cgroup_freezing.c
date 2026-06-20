__int64 __fastcall cgroup_freezing(__int64 a1)
{
  __int64 lock; // x0

  lock = _rcu_read_lock();
  LODWORD(a1) = (*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 2872) + 40LL) + 216LL) & 0xE) != 0;
  _rcu_read_unlock(lock);
  return (unsigned int)a1;
}
