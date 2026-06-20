void __fastcall sub_4DAC8(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x29
  unsigned __int64 StatusReg; // x19
  __int64 v5; // x1
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x0
  __int64 v9; // x9

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v3 + 24) = a1;
    v5 = *(_QWORD *)(v3 + 24);
    *(_QWORD *)(v3 - 8) = a3;
    _traceiter_cfg80211_rx_spurious_frame(0, v5);
    v7 = *(_QWORD *)(v3 - 8);
    v8 = *(_QWORD *)(v3 + 24);
    v9 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v9;
    if ( !v9 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v8, v6, v7);
  }
  JUMPOUT(0x4DA1C);
}
