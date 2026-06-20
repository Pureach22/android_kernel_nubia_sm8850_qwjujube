__int64 __usercall cfg80211_ch_switch_started_notify@<X0>(
        __int64 a1@<X0>,
        __int64 a2@<X1>,
        int a3@<W2>,
        __int64 a4@<X3>,
        int a5@<W4>,
        unsigned __int8 a6@<W5>,
        __int64 a7@<X8>)
{
  __int64 v7; // x9
  __int64 v8; // x29
  __int64 *v9; // x11
  __int64 v10; // x10
  __int64 v11; // x11
  unsigned __int64 StatusReg; // x19
  __int64 v14; // x0
  __int64 v15; // x1
  __int64 v16; // x2
  __int64 v17; // x11
  __int64 v18; // [xsp+48h] [xbp+28h]
  unsigned __int8 v19; // [xsp+50h] [xbp+30h]

  v9 = *(__int64 **)(a1 + 992);
  v10 = *v9;
  if ( *v9 )
  {
    a6 = a4;
    LOBYTE(a7) = a3;
    v7 = a1;
    a4 = a2;
    if ( a3 && !*((_WORD *)v9 + 736) )
    {
      __break(0x800u);
      v11 = *((unsigned __int16 *)v9 + 736);
      if ( !v11 )
        return nl80211_ch_switch_notify(v10 - 992, v7, a7, a4, 0x6Eu, a6, a5 & 1);
    }
    else
    {
      v11 = *((unsigned __int16 *)v9 + 736);
      if ( !v11 )
        return nl80211_ch_switch_notify(v10 - 992, v7, a7, a4, 0x6Eu, a6, a5 & 1);
    }
    if ( ((1LL << a3) & v11) == 0 )
      __break(0x800u);
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
      *(_QWORD *)(v8 - 8) = a4;
      *(_QWORD *)(v8 + 24) = a7;
      v19 = a6;
      *(_DWORD *)(v8 - 12) = a5;
      v18 = v7;
      v14 = _traceiter_cfg80211_ch_switch_started_notify(0, v7, a4, a7);
      v10 = 0;
      v7 = v18;
      a4 = *(_QWORD *)(v8 - 8);
      a5 = *(_DWORD *)(v8 - 12);
      a7 = *(_QWORD *)(v8 + 24);
      a6 = v19;
      v17 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v17;
      if ( !v17 || !*(_QWORD *)(StatusReg + 16) )
      {
        preempt_schedule_notrace(v14, v15, v16);
        v10 = 0;
        v7 = v18;
        a4 = *(_QWORD *)(v8 - 8);
        a5 = *(_DWORD *)(v8 - 12);
        a7 = *(_QWORD *)(v8 + 24);
        a6 = v19;
      }
    }
  }
  return nl80211_ch_switch_notify(v10 - 992, v7, a7, a4, 0x6Eu, a6, a5 & 1);
}
