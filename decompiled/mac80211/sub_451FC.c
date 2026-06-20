void __fastcall sub_451FC(__int64 a1, __int64 a2, int a3, unsigned int a4)
{
  __int64 v4; // x29
  unsigned __int64 StatusReg; // x19
  __int64 v6; // x1
  __int64 v7; // x0
  __int64 v8; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v4 + 24) = a1;
    *(_QWORD *)(v4 - 8) = a2;
    v6 = *(_QWORD *)(v4 + 24);
    *(_DWORD *)(v4 - 12) = a3;
    _traceiter_drv_change_vif_links(0, v6, *(_QWORD *)(v4 - 8), *(unsigned int *)(v4 - 12), a4);
    v7 = *(_QWORD *)(v4 + 24);
    v8 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v8;
    if ( !v8 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v7);
  }
  JUMPOUT(0x45148);
}
