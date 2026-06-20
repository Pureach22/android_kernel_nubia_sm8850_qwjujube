__int64 __fastcall osif_driver_sync_dsc_psoc_create(_QWORD *a1)
{
  unsigned __int64 StatusReg; // x8
  unsigned int v3; // w20

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
    v3 = dsc_psoc_create(_osif_driver_sync, a1);
  else
    v3 = 4;
  if ( (qword_85AAB8 & 1) != 0 )
  {
    qword_85AAB8 &= ~1uLL;
    raw_spin_unlock_bh(&_osif_driver_sync_lock);
  }
  else
  {
    raw_spin_unlock(&_osif_driver_sync_lock);
  }
  return v3;
}
