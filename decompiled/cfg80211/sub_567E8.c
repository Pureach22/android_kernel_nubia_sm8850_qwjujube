void __fastcall sub_567E8(
        unsigned int a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        char a10)
{
  __int64 v10; // x20
  unsigned __int64 StatusReg; // x23
  __int64 v12; // x1
  __int64 v14; // x0
  __int64 v15; // x1
  __int64 v16; // x2
  __int64 v17; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    v12 = v10 + 992;
    ++*(_DWORD *)(StatusReg + 16);
    v14 = _traceiter_rdev_return_int_mpath_info(0, v12, a1, &a10);
    v17 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v17;
    if ( !v17 || (v14 = a1, !*(_QWORD *)(StatusReg + 16)) )
      preempt_schedule_notrace(v14, v15, v16);
  }
  JUMPOUT(0x566C0);
}
