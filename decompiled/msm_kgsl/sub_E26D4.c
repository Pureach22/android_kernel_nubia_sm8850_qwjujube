void __fastcall sub_E26D4(__int64 a1)
{
  unsigned int v1; // w21
  unsigned int v2; // w22
  unsigned int v3; // w23
  unsigned __int64 StatusReg; // x27
  __int64 v5; // x0
  __int64 v6; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v5 = _traceiter_adreno_syncobj_submitted(0, v1, v2, v3, a1);
    v6 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v6;
    if ( !v6 || !*(_QWORD *)(StatusReg + 16) )
    {
      preempt_schedule_notrace(v5);
      JUMPOUT(0xE25F8);
    }
  }
  JUMPOUT(0xE2638);
}
