__int64 __fastcall hdd_get_next_adapter(__int64 a1, __int64 a2, _QWORD *a3)
{
  unsigned __int64 StatusReg; // x8
  unsigned int v7; // w0
  __int64 v8; // x8
  unsigned int v9; // w21
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11[0] = 0;
  *a3 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 32);
  }
  else
  {
    raw_spin_lock_bh(a1 + 32);
    *(_QWORD *)(a1 + 40) |= 1uLL;
  }
  v7 = qdf_list_peek_next((_QWORD *)(a1 + 48), (_QWORD *)(a2 + 8), v11);
  v8 = *(_QWORD *)(a1 + 40);
  v9 = v7;
  if ( (v8 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 40) = v8 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 32);
    if ( v9 )
      goto LABEL_8;
    goto LABEL_7;
  }
  raw_spin_unlock(a1 + 32);
  if ( !v9 )
LABEL_7:
    *a3 = v11[0] - 8LL;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return v9;
}
