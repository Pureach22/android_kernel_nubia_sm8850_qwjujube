void __fastcall sub_B327C(__int64 a1)
{
  unsigned int v1; // w20
  __int64 v2; // x21
  __int64 v3; // x22
  unsigned __int64 StatusReg; // x23
  __int64 v5; // x0
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v5 = _traceiter_rdev_change_virtual_intf(0, a1 + 992, v3, v1);
    v8 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v8;
    if ( !v8 || (v6 = v3, v5 = v2, v7 = v1, !*(_QWORD *)(StatusReg + 16)) )
      preempt_schedule_notrace(v5, v6, v7);
  }
  JUMPOUT(0xB3178);
}
