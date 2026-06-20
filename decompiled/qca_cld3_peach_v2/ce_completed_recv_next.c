__int64 __fastcall ce_completed_recv_next(
        _QWORD *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  _QWORD *v9; // x20
  __int64 v14; // x27
  unsigned __int64 StatusReg; // x8
  _DWORD *v17; // x8
  unsigned int v18; // w0
  __int64 v19; // x8
  unsigned int v20; // w21

  v9 = a1 + 21;
  v14 = *(_QWORD *)(*a1 + 30696LL);
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
  v17 = *(_DWORD **)(v14 + 72);
  if ( *(v17 - 1) != -852198487 )
    __break(0x8228u);
  v18 = ((__int64 (__fastcall *)(_QWORD *, __int64, __int64, __int64, __int64, __int64, __int64))v17)(
          a1,
          a2,
          a3,
          a4,
          a5,
          a6,
          a7);
  v19 = a1[22];
  v20 = v18;
  if ( (v19 & 1) != 0 )
  {
    a1[22] = v19 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v9);
  }
  else
  {
    raw_spin_unlock(v9);
  }
  return v20;
}
