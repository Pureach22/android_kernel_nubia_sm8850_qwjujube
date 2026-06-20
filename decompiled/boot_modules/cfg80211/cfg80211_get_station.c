__int64 __fastcall cfg80211_get_station(__int64 a1, __int64 a2, void *s)
{
  void *v3; // x20
  __int64 v4; // x21
  __int64 v5; // x22
  __int64 v6; // x23
  __int64 *v7; // x8
  __int64 v8; // x19
  __int64 (__fastcall *v9)(__int64, __int64, __int64, void *); // x8
  unsigned int v10; // w21
  unsigned __int64 StatusReg; // x24
  __int64 station; // x0
  __int64 v14; // x1
  __int64 v15; // x2
  __int64 v16; // x8

  v7 = *(__int64 **)(a1 + 992);
  if ( !v7 )
    return 4294967201LL;
  v8 = *v7;
  if ( !*v7 )
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      station = _traceiter_rdev_get_station(0, 0, v4, v5);
      v16 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v16;
      if ( !v16 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(station, v14, v15);
    }
    goto LABEL_5;
  }
  v6 = v8 - 992;
  if ( !*(_QWORD *)(*(_QWORD *)(v8 - 992) + 160LL) )
    return 4294967201LL;
  v3 = s;
  v4 = a1;
  v5 = a2;
  memset(s, 0, 0x108u);
  mutex_lock(v8);
LABEL_5:
  v9 = *(__int64 (__fastcall **)(__int64, __int64, __int64, void *))(*(_QWORD *)v6 + 160LL);
  if ( *((_DWORD *)v9 - 1) != -689929514 )
    __break(0x8228u);
  v10 = v9(v8, v4, v5, v3);
  mutex_unlock(v8);
  return v10;
}
