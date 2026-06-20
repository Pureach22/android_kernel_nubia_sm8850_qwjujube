void __fastcall sub_B2D6C(unsigned int a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x20
  __int64 v4; // x0
  __int64 v5; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v4 = _traceiter_ipa3_napi_poll_entry(0, a2);
    v5 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v5;
    if ( !v5 || (v4 = a1, !*(_QWORD *)(StatusReg + 16)) )
      preempt_schedule_notrace(v4);
  }
  JUMPOUT(0xB2804);
}
