__int64 __fastcall get_vlan(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x1
  __int64 v5; // x2
  __int64 v6; // x8
  __int64 v7; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v9; // x9
  unsigned int *v10; // x9
  unsigned int v11; // w12
  __int64 v12; // x9
  unsigned int v13; // w8
  bool v14; // cc
  int v15; // w8
  bool v16; // zf

  if ( !*(_QWORD *)(*(_QWORD *)(a1 + 32) + 160LL) )
    return 0;
  result = dev_get_by_index(*(_QWORD *)(a1 + 40));
  if ( !result )
    return -19;
  v6 = *(_QWORD *)(result + 992);
  if ( v6
    && *(_QWORD *)v6 == a2 + 992
    && ((v13 = *(_DWORD *)(v6 + 8), v14 = v13 > 9, v15 = (1 << v13) & 0x218, !v14) ? (v16 = v15 == 0) : (v16 = 1), !v16) )
  {
    if ( (*(_QWORD *)(result + 168) & 1) != 0 )
      return result;
    v7 = -100;
  }
  else
  {
    v7 = -22;
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  ++*(_DWORD *)(StatusReg + 16);
  v9 = *(_QWORD *)(result + 1320);
  v10 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v9);
  do
    v11 = __ldxr(v10);
  while ( __stxr(v11 - 1, v10) );
  v12 = *(_QWORD *)(StatusReg + 16) - 1LL;
  *(_DWORD *)(StatusReg + 16) = v12;
  if ( !v12 || !*(_QWORD *)(StatusReg + 16) )
    preempt_schedule_notrace(result, v4, v5);
  return v7;
}
