__int64 __fastcall cfg80211_tx_mgmt_expired(
        _QWORD *a1,
        __int64 a2,
        _QWORD *a3,
        __int64 a4,
        _QWORD *a5,
        __int64 a6,
        __int64 a7)
{
  __int64 v7; // x29
  __int64 v8; // x8
  unsigned __int64 StatusReg; // x19
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 v13; // x9
  _QWORD *v14; // [xsp+40h] [xbp+20h]
  unsigned int v15; // [xsp+4Ch] [xbp+2Ch]

  v8 = *a1;
  if ( *a1 )
  {
    a7 = (unsigned int)a4;
    a5 = a3;
    a3 = a1;
    a4 = a2;
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
      *(_QWORD *)(v7 + 24) = a3;
      *(_QWORD *)(v7 - 8) = a4;
      v15 = a7;
      v14 = a5;
      v11 = _traceiter_cfg80211_tx_mgmt_expired(0, a3, a4, a5);
      v8 = 0;
      a4 = *(_QWORD *)(v7 - 8);
      a3 = *(_QWORD **)(v7 + 24);
      a5 = v14;
      a7 = v15;
      v13 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v13;
      if ( !v13 || !*(_QWORD *)(StatusReg + 16) )
      {
        preempt_schedule_notrace(v11, v12, a3);
        v8 = 0;
        a4 = *(_QWORD *)(v7 - 8);
        a3 = *(_QWORD **)(v7 + 24);
        a5 = v14;
        a7 = v15;
      }
    }
  }
  return ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, __int64, _QWORD *, _QWORD, __int64))nl80211_send_remain_on_chan_event)(
           67,
           v8 - 992,
           a3,
           a4,
           a5,
           0,
           a7);
}
