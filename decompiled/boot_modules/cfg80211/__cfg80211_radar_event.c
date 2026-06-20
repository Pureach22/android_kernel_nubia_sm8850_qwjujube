__int64 __fastcall _cfg80211_radar_event(__int64 a1, __int64 *a2, char a3, unsigned int a4)
{
  __int64 v4; // x19
  __int64 *v5; // x20
  unsigned int v6; // w21
  char v7; // w22
  __int64 v8; // x8
  __int64 v9; // x10
  __int64 v10; // x11
  unsigned __int64 StatusReg; // x23
  __int64 v13; // x0
  __int64 v14; // x1
  __int64 v15; // x2
  __int64 v16; // x8

  if ( a1 )
  {
    v6 = a4;
    v7 = a3;
    v4 = a1;
    v5 = a2;
  }
  else
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v13 = _traceiter_cfg80211_radar_event(0, v4, v5, v7 & 1);
      v16 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v16;
      if ( !v16 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v13, v14, v15);
    }
  }
  cfg80211_set_dfs_state(v4, (__int64)v5, 1);
  if ( (v7 & 1) != 0 )
    queue_work_on(32, cfg80211_wq, v4 - 376);
  cancel_delayed_work(v4 - 624);
  queue_delayed_work_on(32, cfg80211_wq, v4 - 624, 0);
  ((void (__fastcall *)(__int64, __int64 *, _QWORD, _QWORD, _QWORD))nl80211_radar_notify)(v4 - 992, v5, 0, 0, v6);
  v8 = v5[3];
  v9 = *v5;
  v10 = v5[1];
  *(_QWORD *)(v4 - 224) = v5[2];
  *(_QWORD *)(v4 - 216) = v8;
  *(_QWORD *)(v4 - 240) = v9;
  *(_QWORD *)(v4 - 232) = v10;
  return queue_work_on(32, cfg80211_wq, v4 - 208);
}
