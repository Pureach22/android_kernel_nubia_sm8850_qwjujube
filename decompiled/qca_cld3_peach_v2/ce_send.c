__int64 __fastcall ce_send(
        __int64 *a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int a7)
{
  _QWORD *v9; // x20
  __int64 v10; // x27
  unsigned __int64 StatusReg; // x8
  _DWORD *v17; // x8
  unsigned int v18; // w0
  __int64 v19; // x8
  unsigned int v20; // w21

  v9 = a1 + 21;
  v10 = *a1;
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
  v17 = *(_DWORD **)(*(_QWORD *)(v10 + 30696) + 24LL);
  if ( *(v17 - 1) != -1792364938 )
    __break(0x8228u);
  v18 = ((__int64 (__fastcall *)(__int64 *, __int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD))v17)(
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
