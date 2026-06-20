__int64 __fastcall hdd_remove_adapter(__int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  unsigned int v5; // w0
  __int64 v6; // x8
  unsigned int v7; // w20

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
  v5 = qdf_list_remove_node(a1 + 48, (_QWORD *)(a2 + 8));
  v6 = *(_QWORD *)(a1 + 40);
  v7 = v5;
  if ( (v6 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 40) = v6 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 32);
  }
  else
  {
    raw_spin_unlock(a1 + 32);
  }
  return v7;
}
