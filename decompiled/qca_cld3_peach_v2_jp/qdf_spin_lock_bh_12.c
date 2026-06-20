__int64 __fastcall qdf_spin_lock_bh_12(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 result; // x0

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
    return raw_spin_lock(a1);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    return raw_spin_lock(a1);
  result = raw_spin_lock_bh(a1);
  *(_QWORD *)(a1 + 8) |= 1uLL;
  return result;
}
