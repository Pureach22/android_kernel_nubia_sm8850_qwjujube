void __fastcall sub_A578C(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w20
  unsigned int v4; // w22
  unsigned int v5; // w23
  __int64 v6; // x24
  unsigned int v7; // w25
  unsigned __int64 StatusReg; // x19
  __int64 v9; // x0
  __int64 v10; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v9 = _traceiter_adreno_gpu_fault(0, a2, a3, v3, v4, v5, v6, v7);
    v10 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v10;
    if ( !v10 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v9);
  }
  JUMPOUT(0xA5550);
}
