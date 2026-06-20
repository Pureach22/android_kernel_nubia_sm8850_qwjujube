void __fastcall sub_267938(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5, unsigned int a6)
{
  unsigned int v6; // w26
  __int64 v7; // x29
  unsigned __int64 StatusReg; // x19
  __int64 v9; // x0
  __int64 v10; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    _traceiter_cam_cci_burst(0, a2, v6, *(_DWORD *)(v7 - 36), (__int64)"thirq_cnt", a6);
    v9 = *(_QWORD *)(v7 - 32);
    v10 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v10;
    if ( !v10 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v9);
  }
  JUMPOUT(0x267420);
}
