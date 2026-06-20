__int64 __fastcall dp_mon_add_desc_list_to_free_list(__int64 a1, _QWORD *a2, _QWORD **a3, __int64 a4)
{
  unsigned __int64 StatusReg; // x8
  __int64 v8; // x9
  __int64 v9; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a4 + 24);
  }
  else
  {
    raw_spin_lock_bh(a4 + 24);
    *(_QWORD *)(a4 + 32) |= 1uLL;
  }
  v8 = *(_QWORD *)(a4 + 16);
  *(_QWORD *)(a4 + 16) = *a2;
  **a3 = v8;
  *a3 = nullptr;
  *a2 = 0;
  v9 = *(_QWORD *)(a4 + 32);
  if ( (v9 & 1) == 0 )
    return raw_spin_unlock(a4 + 24);
  *(_QWORD *)(a4 + 32) = v9 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(a4 + 24);
}
