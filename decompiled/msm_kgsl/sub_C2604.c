void sub_C2604()
{
  unsigned int v0; // w19
  unsigned int v1; // w21
  unsigned int v2; // w22
  unsigned int v3; // w23
  unsigned int v4; // w24
  unsigned int v5; // w25
  __int64 v6; // x28
  unsigned __int64 StatusReg; // x20
  __int64 v8; // x0
  __int64 v9; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v8 = _traceiter_adreno_gpu_fault(0, v0, v1, v2, v3, v4, v6, v5);
    v9 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v9;
    if ( !v9 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v8);
  }
  JUMPOUT(0xC2108);
}
