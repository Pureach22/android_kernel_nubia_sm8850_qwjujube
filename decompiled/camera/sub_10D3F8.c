void __fastcall sub_10D3F8(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x20
  unsigned int v5; // w21
  unsigned __int64 StatusReg; // x22
  __int64 v7; // x0
  __int64 v8; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v7 = _traceiter_cam_log_event(0, "ClkRegBusOpsProfile: crm_write_pwr_states (name, time taken in usec)", v4, a4);
    v8 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v8;
    if ( !v8 || (v7 = v5, !*(_QWORD *)(StatusReg + 16)) )
      preempt_schedule_notrace(v7);
  }
  JUMPOUT(0x10D358);
}
