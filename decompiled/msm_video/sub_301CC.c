void __fastcall sub_301CC(unsigned int a1)
{
  unsigned int v1; // w19
  unsigned int v2; // w20
  unsigned int v3; // w21
  unsigned __int64 StatusReg; // x22
  __int64 v6; // x0
  __int64 v7; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v6 = _traceiter_venus_hfi_var_done(0, 0, v1, v2, v3);
    v7 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v7;
    if ( !v7 || (v6 = a1, !*(_QWORD *)(StatusReg + 16)) )
      preempt_schedule_notrace(v6);
  }
  JUMPOUT(0x301AC);
}
