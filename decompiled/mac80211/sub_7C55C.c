void __fastcall sub_7C55C(__int64 a1, __int64 a2, __int64 a3, unsigned int a4, __int64 a5, unsigned int a6)
{
  unsigned int v6; // w21
  unsigned int v7; // w22
  __int64 v8; // x25
  __int64 v9; // x26
  unsigned __int64 StatusReg; // x19
  __int64 v11; // x0
  __int64 v12; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v11 = _traceiter_drv_release_buffered_frames(0, v9, v8 + 2688, v7, a4, v6, a6);
    v12 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v12;
    if ( !v12 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v11);
  }
  JUMPOUT(0x7C390);
}
