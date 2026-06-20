void __fastcall sub_9AF4(unsigned int a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x19
  unsigned __int64 StatusReg; // x20
  __int64 v6; // x1
  __int64 v8; // x0
  __int64 v9; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    v6 = v4 + 92;
    ++*(_DWORD *)(StatusReg + 16);
    v8 = _traceiter_bw_hwmon_update(0, v6, a3, a4);
    v9 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v9;
    if ( !v9 || (v8 = a1, !*(_QWORD *)(StatusReg + 16)) )
      preempt_schedule_notrace(v8);
  }
  JUMPOUT(0x99F0);
}
