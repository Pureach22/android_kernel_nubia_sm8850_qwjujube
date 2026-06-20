__int64 __usercall cfg80211_michael_mic_failure@<X0>(
        __int64 a1@<X0>,
        __int64 a2@<X1>,
        __int64 a3@<X2>,
        __int64 a4@<X3>,
        __int64 a5@<X4>,
        __int64 a6@<X5>,
        __int64 a7@<X6>,
        __int64 a8@<X8>)
{
  __int64 v8; // x29
  __int64 v9; // x9
  unsigned __int64 StatusReg; // x19
  __int64 v12; // x0
  __int64 v13; // x1
  __int64 v14; // x10
  unsigned int v15; // [xsp+5Ch] [xbp+2Ch]
  __int64 v16; // [xsp+60h] [xbp+30h]

  v9 = **(_QWORD **)(a1 + 992);
  if ( v9 )
  {
    a7 = (unsigned int)a6;
    a6 = a5;
    a5 = (unsigned int)a4;
    a8 = a1;
    a4 = (unsigned int)a3;
    a3 = a2;
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
      *(_DWORD *)(v8 - 8) = a5;
      *(_DWORD *)(v8 - 4) = a4;
      *(_QWORD *)(v8 + 24) = a3;
      *(_QWORD *)(v8 - 16) = a6;
      v15 = a7;
      v16 = a8;
      v12 = _traceiter_cfg80211_michael_mic_failure(0, a8);
      a8 = v16;
      v9 = 0;
      a3 = *(_QWORD *)(v8 + 24);
      a5 = *(unsigned int *)(v8 - 8);
      a4 = *(unsigned int *)(v8 - 4);
      a6 = *(_QWORD *)(v8 - 16);
      a7 = v15;
      v14 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v14;
      if ( !v14 || !*(_QWORD *)(StatusReg + 16) )
      {
        preempt_schedule_notrace(v12, v13, a3);
        a8 = v16;
        v9 = 0;
        a3 = *(_QWORD *)(v8 + 24);
        a5 = *(unsigned int *)(v8 - 8);
        a4 = *(unsigned int *)(v8 - 4);
        a6 = *(_QWORD *)(v8 - 16);
        a7 = v15;
      }
    }
  }
  return nl80211_michael_mic_failure(v9 - 992, a8, a3, a4, a5, a6, a7);
}
