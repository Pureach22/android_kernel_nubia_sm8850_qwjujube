__int64 __fastcall hif_exec_tasklet_fn(_QWORD *a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x20
  __int64 v4; // x2
  __int64 v5; // x0
  __int64 (__fastcall *v6)(__int64, __int64, __int64); // x8
  _QWORD *v7; // t2
  unsigned int v8; // w0
  _DWORD *v9; // x8
  __int64 result; // x0
  __int64 (__fastcall *v12)(_QWORD); // x8
  unsigned int v18; // w10
  unsigned __int64 v21; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = a1[1];
  v4 = *(unsigned int *)(StatusReg + 40);
  v7 = a1 + 31;
  v5 = a1[31];
  v6 = (__int64 (__fastcall *)(__int64, __int64, __int64))v7[1];
  if ( *((_DWORD *)v6 - 1) != -4250500 )
    __break(0x8228u);
  v8 = v6(v5, 0xFFFF, v4);
  v9 = (_DWORD *)a1[33];
  if ( *(v9 - 1) != -1537295330 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(_QWORD *, _QWORD))v9)(a1, v8);
  if ( (result & 1) != 0 )
  {
    _X8 = (unsigned int *)(v3 + 676);
    __asm { PRFM            #0x11, [X8] }
    do
      v18 = __ldxr(_X8);
    while ( __stxr(v18 - 1, _X8) );
    v12 = (__int64 (__fastcall *)(_QWORD))a1[34];
    if ( *((_DWORD *)v12 - 1) != -836874276 )
      __break(0x8228u);
    return v12(a1);
  }
  else
  {
    _X9 = a1 + 434;
    __asm { PRFM            #0x11, [X9] }
    do
      v21 = __ldxr(_X9);
    while ( __stlxr(v21 | 1, _X9) );
    __dmb(0xBu);
    if ( (v21 & 1) == 0 )
      return _tasklet_schedule(a1 + 433);
  }
  return result;
}
