__int64 osif_driver_sync_assert_trans_protected()
{
  unsigned __int64 StatusReg; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(&_osif_driver_sync_lock);
  }
  else
  {
    raw_spin_lock_bh(&_osif_driver_sync_lock);
    qword_85AAB8 |= 1uLL;
  }
  if ( byte_85AAC9 == 1 )
    dsc_driver_assert_trans_protected(_osif_driver_sync);
  if ( (qword_85AAB8 & 1) == 0 )
    return raw_spin_unlock(&_osif_driver_sync_lock);
  qword_85AAB8 &= ~1uLL;
  return raw_spin_unlock_bh(&_osif_driver_sync_lock);
}
