void __fastcall sub_57DAC(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        char a11)
{
  __int64 v11; // x19
  __int64 v12; // x20
  unsigned __int64 StatusReg; // x21
  __int64 updated; // x0
  __int64 v15; // x1
  __int64 v16; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    updated = _traceiter_rdev_update_mesh_config(0, v12 + 992, v11, a3, &a11);
    v16 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v16;
    if ( !v16 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(updated, v15, a3);
  }
  JUMPOUT(0x57CD4);
}
