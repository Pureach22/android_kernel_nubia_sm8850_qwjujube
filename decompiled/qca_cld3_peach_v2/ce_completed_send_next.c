__int64 __fastcall ce_completed_send_next(
        _QWORD *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  _QWORD *v10; // x20
  __int64 v15; // x21
  unsigned __int64 StatusReg; // x8
  _DWORD *v19; // x8
  unsigned int v20; // w0
  __int64 v21; // x8
  unsigned int v22; // w21

  v10 = a1 + 21;
  v15 = *(_QWORD *)(*a1 + 30696LL);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 21);
  }
  else
  {
    raw_spin_lock_bh(a1 + 21);
    a1[22] |= 1uLL;
  }
  v19 = *(_DWORD **)(v15 + 80);
  if ( *(v19 - 1) != -988321398 )
    __break(0x8228u);
  v20 = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64))v19)(
          a1,
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9);
  v21 = a1[22];
  v22 = v20;
  if ( (v21 & 1) != 0 )
  {
    a1[22] = v21 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v10);
  }
  else
  {
    raw_spin_unlock(v10);
  }
  return v22;
}
