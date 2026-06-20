__int64 __fastcall cfg80211_sched_scan_stopped_locked(__int64 result, __int64 a2)
{
  _QWORD *v2; // x19
  _QWORD *v3; // x8
  _QWORD *v4; // x9
  unsigned __int64 StatusReg; // x21
  __int64 v6; // x20
  __int64 v7; // x2
  __int64 v8; // x8

  if ( !result )
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      v6 = a2;
      ++*(_DWORD *)(StatusReg + 16);
      result = _traceiter_cfg80211_sched_scan_stopped(0, 0, a2);
      v8 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v8;
      if ( !v8 || (result = 0, a2 = v6, !*(_QWORD *)(StatusReg + 16)) )
      {
        preempt_schedule_notrace(result, a2, v7);
        result = 0;
        a2 = v6;
      }
    }
  }
  v2 = (_QWORD *)(result - 744);
  while ( 1 )
  {
    v2 = (_QWORD *)*v2;
    if ( v2 == (_QWORD *)(result - 744) )
      break;
    if ( *(v2 - 21) == a2 )
    {
      if ( v2 != &_ksymtab_cfg80211_cac_event )
      {
        nl80211_send_sched_scan(v2 - 21, 0x4Eu);
        v3 = (_QWORD *)v2[1];
        if ( (_QWORD *)*v3 == v2 && (v4 = (_QWORD *)*v2, *(_QWORD **)(*v2 + 8LL) == v2) )
        {
          v4[1] = v3;
          *v3 = v4;
        }
        else
        {
          _list_del_entry_valid_or_report(v2);
        }
        v2[1] = 0xDEAD000000000122LL;
        return kvfree_call_rcu(v2 - 3, v2 - 21);
      }
      return result;
    }
  }
  return result;
}
