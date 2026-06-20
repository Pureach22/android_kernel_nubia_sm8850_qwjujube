__int64 __fastcall rmnet_shs_form_hash(
        int a1,
        unsigned int a2,
        unsigned int a3,
        char a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  unsigned int v7; // w8
  unsigned int v8; // w8
  unsigned __int64 StatusReg; // x19
  __int64 v11; // x0
  __int64 v12; // x8

  if ( !a2 )
  {
    v8 = 0;
    ++qword_1A3E0;
    return v8;
  }
  if ( a2 > 7 )
  {
    v8 = 0;
LABEL_7:
    if ( a4 )
      return v8 & 0xFFF00000 | 0x77777;
    return v8;
  }
  v7 = (a2 - 1) >> 1;
  if ( v7 != 4 )
  {
    v8 = a3 & 0xFFFFFF | ((((a2 & 1) + a1) * dword_144D0[v7]) << 28);
    goto LABEL_7;
  }
  __break(1u);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v11 = _traceiter_rmnet_shs_low(0, 6, 26, 4, a3, a6, a7, 0);
    v12 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v12;
    if ( !v12 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v11);
  }
  return 4;
}
