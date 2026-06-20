__int64 qdf_spin_lock_bh()
{
  unsigned __int64 StatusReg; // x8
  __int64 result; // x0

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
    return raw_spin_lock(&_cfg_stores_lock);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    return raw_spin_lock(&_cfg_stores_lock);
  result = raw_spin_lock_bh(&_cfg_stores_lock);
  qword_75CAF0 |= 1uLL;
  return result;
}
