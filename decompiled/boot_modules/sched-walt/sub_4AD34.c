void __fastcall sub_4AD34(__int64 a1, __int64 a2, __int64 a3, unsigned int a4, __int64 a5, __int64 a6, __int64 a7)
{
  char v7; // w11
  unsigned int v8; // w19
  unsigned int v9; // w21
  unsigned __int64 v10; // x23
  unsigned __int64 StatusReg; // x20
  __int64 v12; // x0
  __int64 v13; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v12 = _traceiter_walt_newidle_balance(0, v8, v9, a4, v7 & 1, v10 > 0x7A120, a7);
    v13 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v13;
    if ( !v13 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v12);
  }
  JUMPOUT(0x4A9B8);
}
