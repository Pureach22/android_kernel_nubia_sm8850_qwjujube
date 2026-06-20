void __fastcall sub_16B614(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned __int64 StatusReg; // x19
  __int64 v5; // x0
  __int64 v6; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v5 = _traceiter_cam_log_event(0, (__int64)"CDM_START", (__int64)"CDM_START_IRQ", a4, 0);
    v6 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v6;
    if ( !v6 || !*(_QWORD *)(StatusReg + 16) )
    {
      preempt_schedule_notrace(v5);
      JUMPOUT(0x16B4A8);
    }
  }
  JUMPOUT(0x16B4E8);
}
