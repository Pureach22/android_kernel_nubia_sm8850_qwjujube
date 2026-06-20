void __usercall sub_6EA34(__int64 a1@<X1>, __int64 a2@<X2>, __int64 a3@<X8>)
{
  __int64 v3; // x9
  __int64 v4; // x19
  __int64 v5; // x29
  unsigned __int64 StatusReg; // x20
  __int64 v7; // x0
  __int64 v8; // x2
  __int64 v9; // x1
  __int64 v10; // x10

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v5 - 8) = a1;
    v7 = _traceiter_rdev_probe_mesh_link(0, v4 + 992, *(_QWORD *)(v5 - 8), a2, v3, a3);
    v9 = *(_QWORD *)(v5 - 8);
    v10 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v10;
    if ( !v10 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v7, v9, v8);
  }
  JUMPOUT(0x6E9EC);
}
