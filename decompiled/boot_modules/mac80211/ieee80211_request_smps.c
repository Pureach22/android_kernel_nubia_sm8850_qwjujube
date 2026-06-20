_DWORD *__fastcall ieee80211_request_smps(_DWORD *result, __int64 a2, unsigned int a3)
{
  _DWORD *v4; // x20
  unsigned __int64 v5; // x21
  __int64 lock; // x0
  __int64 v7; // x1
  __int64 v8; // x8
  __int64 v9; // x9
  unsigned __int64 StatusReg; // x22
  char *v11; // x2
  __int64 v12; // x20
  __int64 v13; // x9

  if ( *result != 2 )
  {
    __break(0x800u);
    return result;
  }
  v4 = result;
  v5 = (unsigned int)a2;
  lock = _rcu_read_lock(result, a2);
  if ( (unsigned int)v5 >= 0x10 )
  {
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      v11 = (char *)v4 + v9;
      v12 = v8;
      ++*(_DWORD *)(StatusReg + 16);
      lock = _traceiter_api_request_smps(0, v7, v11, v8, a3);
      v13 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v13;
      if ( !v13 || (v8 = v12, !*(_QWORD *)(StatusReg + 16)) )
      {
        lock = preempt_schedule_notrace(lock);
        v8 = v12;
      }
    }
    goto LABEL_5;
  }
  v8 = *(_QWORD *)&v4[2 * (unsigned int)v5 - 38];
  if ( v8 )
  {
    v5 = (unsigned __int64)(v4 - 776);
LABEL_5:
    if ( *(_DWORD *)(v8 + 548) != a3 )
    {
      *(_DWORD *)(v8 + 548) = a3;
      lock = wiphy_work_queue(*(_QWORD *)(*(_QWORD *)v5 + 72LL), v8 + 792);
    }
    return (_DWORD *)_rcu_read_unlock(lock);
  }
  __break(0x800u);
  return (_DWORD *)_rcu_read_unlock(lock);
}
