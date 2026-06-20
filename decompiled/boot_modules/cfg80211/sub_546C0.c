void __fastcall sub_546C0(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v4; // x19
  __int64 v5; // x20
  unsigned int v6; // w21
  __int64 v7; // x22
  int v8; // w24
  unsigned __int64 StatusReg; // x25
  __int64 v10; // x0
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v10 = _traceiter_rdev_del_key(0, v4 + 992, v5, v6, a4, v8 == 1, v7);
    v13 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v13;
    if ( !v13 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v10, v11, v12);
  }
  JUMPOUT(0x54614);
}
