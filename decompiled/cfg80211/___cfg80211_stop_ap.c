__int64 __fastcall __cfg80211_stop_ap(__int64 a1, __int64 a2, unsigned int a3, char a4)
{
  unsigned int v4; // w20
  __int64 v5; // x22
  __int64 v6; // x23
  char v7; // w24
  __int64 v8; // x25
  __int64 v9; // x19
  int v10; // w8
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 (__fastcall *v13)(_QWORD); // x8
  __int64 v14; // x2
  unsigned int v15; // w21
  char v16; // w8
  __int64 v17; // x0
  _DWORD *v18; // x8
  unsigned __int64 StatusReg; // x21
  __int64 v21; // x1
  __int64 v22; // x2
  __int64 v23; // x8

  if ( !*(_QWORD *)(*(_QWORD *)a1 + 128LL) )
    return 4294967201LL;
  v9 = *(_QWORD *)(a2 + 992);
  v10 = *(_DWORD *)(v9 + 8);
  if ( v10 != 9 && v10 != 3 )
    return 4294967201LL;
  if ( a3 >= 0xF )
  {
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      a1 = _traceiter_rdev_stop_ap(0, a1 + 992, v5, v4);
      v23 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v23;
      if ( !v23 || (v21 = v5, v22 = v4, a1 = v6, !*(_QWORD *)(StatusReg + 16)) )
      {
        preempt_schedule_notrace(a1, v21, v22);
        a1 = v6;
      }
    }
  }
  else
  {
    v8 = v9 + 72LL * a3;
    if ( !*(_DWORD *)(v8 + 400) )
      return 4294967294LL;
    v7 = a4;
    v6 = a1;
    v4 = a3;
    v5 = a2;
  }
  v11 = *(_QWORD *)a1;
  v12 = a1 + 992;
  v13 = *(__int64 (__fastcall **)(_QWORD))(v11 + 128);
  if ( *((_DWORD *)v13 - 1) != -405557830 )
    __break(0x8228u);
  v15 = v13(v12);
  if ( !v15 )
  {
    *(_DWORD *)(v9 + 100) = 0;
    v16 = v7;
    *(_DWORD *)(v8 + 400) = 0;
    v17 = v6;
    *(_QWORD *)(v8 + 408) = 0;
    *(_QWORD *)(v8 + 416) = 0;
    *(_QWORD *)(v8 + 424) = 0;
    *(_QWORD *)(v8 + 432) = 0;
    *(_BYTE *)(v9 + 344) = 0;
    if ( *(_QWORD *)(*(_QWORD *)v6 + 736LL) )
    {
      v18 = *(_DWORD **)(*(_QWORD *)v6 + 736LL);
      if ( *(v18 - 1) != -824243271 )
        __break(0x8228u);
      v14 = ((unsigned int (__fastcall *)(__int64, __int64, _QWORD))v18)(v6 + 992, v5, 0);
      v17 = v6;
      v16 = v7;
    }
    if ( (v16 & 1) != 0 )
    {
      ((void (__fastcall *)(__int64, _QWORD, __int64))nl80211_send_ap_stopped)(v9, v4, v14);
      v17 = v6;
    }
    cfg80211_sched_dfs_chan_update(v17);
  }
  queue_work_on(32, system_wq, &cfg80211_disconnect_work);
  return v15;
}
