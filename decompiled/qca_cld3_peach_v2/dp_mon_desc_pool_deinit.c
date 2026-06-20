__int64 __fastcall dp_mon_desc_pool_deinit(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 24);
    v3 = *(_QWORD *)(a1 + 32);
  }
  else
  {
    raw_spin_lock_bh(a1 + 24);
    v3 = *(_QWORD *)(a1 + 32) | 1LL;
    *(_QWORD *)(a1 + 32) = v3;
  }
  *(_QWORD *)(a1 + 16) = 0;
  *(_DWORD *)a1 = 0;
  if ( (v3 & 1) == 0 )
    return raw_spin_unlock(a1 + 24);
  *(_QWORD *)(a1 + 32) = v3 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(a1 + 24);
}
