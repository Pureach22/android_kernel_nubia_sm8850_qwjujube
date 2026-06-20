void __fastcall sub_E3774(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  unsigned int v7; // w19
  unsigned int v8; // w20
  unsigned int v9; // w23
  unsigned int v10; // w24
  unsigned int v11; // w26
  unsigned int v12; // w27
  unsigned __int64 StatusReg; // x21
  __int64 v14; // x0
  __int64 v15; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v14 = _traceiter_adreno_gpu_fault(0, v11, v12, v7, v8, v9, a7, v10);
    v15 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v15;
    if ( !v15 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v14);
  }
  JUMPOUT(0xE3498);
}
