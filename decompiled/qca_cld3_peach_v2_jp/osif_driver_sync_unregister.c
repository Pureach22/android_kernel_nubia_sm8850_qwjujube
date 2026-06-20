__int64 *osif_driver_sync_unregister()
{
  unsigned __int64 StatusReg; // x8
  int v1; // w20

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
  v1 = (unsigned __int8)byte_85AAC9;
  if ( byte_85AAC9 == 1 )
    byte_85AAC9 = 0;
  if ( (qword_85AAB8 & 1) != 0 )
  {
    qword_85AAB8 &= ~1uLL;
    raw_spin_unlock_bh(&_osif_driver_sync_lock);
  }
  else
  {
    raw_spin_unlock(&_osif_driver_sync_lock);
  }
  if ( v1 )
    return &_osif_driver_sync;
  else
    return nullptr;
}
