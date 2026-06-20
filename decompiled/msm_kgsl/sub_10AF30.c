void __fastcall sub_10AF30(__int64 a1)
{
  __int64 v1; // x29
  unsigned __int64 StatusReg; // x19
  unsigned __int64 v3; // x8
  __int64 v4; // x8
  __int64 v5; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(unsigned int *)(StatusReg + 40);
  *(_QWORD *)(v1 + 24) = a1;
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask + ((v3 >> 3) & 0x1FFFFFF8)) >> v3) & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    _traceiter_kgsl_bus(0, *(_QWORD *)(v1 + 24), 1);
    v4 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v4;
    if ( v4 )
    {
      v5 = *(_QWORD *)(v1 + 24);
      if ( *(_QWORD *)(StatusReg + 16) )
        goto LABEL_8;
    }
    else
    {
      v5 = *(_QWORD *)(v1 + 24);
    }
    *(_QWORD *)(v1 + 24) = v5;
    preempt_schedule_notrace(v5);
  }
LABEL_8:
  JUMPOUT(0x10AF1C);
}
