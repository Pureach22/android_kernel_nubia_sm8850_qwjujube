void __fastcall sub_267890(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        unsigned int a6,
        unsigned int a7)
{
  unsigned int v7; // w27
  unsigned int v8; // w28
  __int64 v9; // x29
  unsigned __int64 StatusReg; // x20
  __int64 v11; // x0
  __int64 v12; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v9 - 32) = a1;
    _traceiter_cam_cci_burst(0, a7, v7, v8, (__int64)"cci burst write START for sid", a6);
    v11 = *(_QWORD *)(v9 - 32);
    v12 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v12;
    if ( !v12 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v11);
  }
  JUMPOUT(0x266CC8);
}
