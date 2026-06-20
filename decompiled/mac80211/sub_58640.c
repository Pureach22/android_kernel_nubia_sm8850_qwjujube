void __fastcall sub_58640(int a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x21
  __int64 v4; // x29
  unsigned __int64 StatusReg; // x22
  unsigned __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  v6 = *(unsigned int *)(StatusReg + 40);
  *(_DWORD *)(v4 - 4) = a1;
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + ((v6 >> 3) & 0x1FFFFFF8)) >> v6) & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v7 = _traceiter_drv_neg_ttlm_res(0, v3, v1, *(unsigned int *)(v4 - 4), v2);
    v8 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v8;
    if ( !v8 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v7);
  }
  JUMPOUT(0x585A0);
}
