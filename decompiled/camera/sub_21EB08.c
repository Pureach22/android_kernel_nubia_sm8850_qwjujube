void __fastcall sub_21EB08(unsigned int a1, __int64 a2, __int64 a3)
{
  unsigned __int64 StatusReg; // x21
  __int64 v5; // x0
  __int64 v6; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v5 = _traceiter_cam_context_state(0, (__int64)"ISP", a3);
    v6 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v6;
    if ( !v6 || (v5 = a1, !*(_QWORD *)(StatusReg + 16)) )
      preempt_schedule_notrace(v5);
  }
  JUMPOUT(0x21E8F4);
}
