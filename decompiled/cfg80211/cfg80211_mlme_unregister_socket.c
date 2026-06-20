__int64 __fastcall cfg80211_mlme_unregister_socket(_QWORD *a1, int a2)
{
  _QWORD *v2; // x19
  int v3; // w20
  __int64 v4; // x22
  __int64 v5; // x21
  _QWORD *v6; // x0
  _QWORD *v7; // x9
  __int64 v8; // x1
  _QWORD *v9; // x27
  _QWORD *v10; // x8
  __int64 result; // x0
  _DWORD *v12; // x8
  unsigned __int64 StatusReg; // x23
  __int64 v14; // x0
  __int64 v15; // x1
  __int64 v16; // x2
  __int64 v17; // x8

  v5 = *a1;
  if ( !*a1 )
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v14 = _traceiter_rdev_crit_proto_stop(0, 0, v2);
      v17 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v17;
      if ( !v17 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v14, v15, v16);
    }
    goto LABEL_14;
  }
  v2 = a1;
  v3 = a2;
  raw_spin_lock_bh(v5 - 80);
  v6 = (_QWORD *)v2[6];
  if ( v6 != v2 + 6 )
  {
    do
    {
      v9 = (_QWORD *)*v6;
      if ( *((_DWORD *)v6 + 6) == v3 )
      {
        v10 = (_QWORD *)v6[1];
        if ( (_QWORD *)*v10 == v6 && (_QWORD *)v9[1] == v6 )
        {
          v9[1] = v10;
          *v10 = v9;
        }
        else
        {
          _list_del_entry_valid_or_report(v6);
          v6 = v7;
        }
        *v6 = 0xDEAD000000000100LL;
        v6[1] = 0xDEAD000000000122LL;
        kfree(v6);
        v8 = system_wq;
        *((_BYTE *)v2 + 64) |= 1u;
        queue_work_on(32, v8, v5 - 112);
      }
      v6 = v9;
    }
    while ( v9 != v2 + 6 );
  }
  result = raw_spin_unlock_bh(v5 - 80);
  if ( v3 && *(_DWORD *)(v5 - 344) == v3 )
  {
    v4 = v5 - 992;
    *(_DWORD *)(v5 - 344) = 0;
LABEL_14:
    v12 = *(_DWORD **)(*(_QWORD *)v4 + 712LL);
    if ( *(v12 - 1) != 1366774891 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, _QWORD *))v12)(v5, v2);
  }
  if ( *((_DWORD *)v2 + 43) == v3 )
    *((_DWORD *)v2 + 43) = 0;
  return result;
}
