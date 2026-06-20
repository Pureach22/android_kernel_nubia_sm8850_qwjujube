void __fastcall sub_805F4(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x29
  unsigned __int64 StatusReg; // x19
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x1
  __int64 v9; // x0
  __int64 v10; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v4 + 24) = a1;
    *(_QWORD *)(v4 - 8) = a2;
    v6 = *(_QWORD *)(v4 + 24);
    v7 = *(_QWORD *)(v4 - 8);
    *(_QWORD *)(v4 - 16) = a4;
    _traceiter_cfg80211_inform_bss_frame(0, v6, v7, a3, *(_QWORD *)(v4 - 16));
    v8 = *(_QWORD *)(v4 - 8);
    v9 = *(_QWORD *)(v4 + 24);
    v10 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v10;
    if ( !v10 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v9, v8, a3);
  }
  JUMPOUT(0x804CC);
}
