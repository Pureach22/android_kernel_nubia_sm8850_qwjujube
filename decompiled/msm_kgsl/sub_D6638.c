void __fastcall sub_D6638(__int64 a1)
{
  unsigned int v1; // w22
  unsigned int v2; // w23
  unsigned __int64 StatusReg; // x24
  __int64 reply; // x0
  __int64 v5; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    reply = _traceiter_adreno_syncobj_query_reply(0, v1, v2, a1);
    v5 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v5;
    if ( !v5 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(reply);
  }
  JUMPOUT(0xD656C);
}
