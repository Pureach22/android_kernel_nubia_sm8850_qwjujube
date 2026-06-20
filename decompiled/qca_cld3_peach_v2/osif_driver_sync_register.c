__int64 __fastcall osif_driver_sync_register(__int64 result)
{
  __int64 v1; // x20
  unsigned __int64 StatusReg; // x8

  if ( result )
  {
    v1 = result;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(&_osif_driver_sync_lock);
    }
    else
    {
      raw_spin_lock_bh(&_osif_driver_sync_lock);
      qword_923C90 |= 1uLL;
    }
    *(_BYTE *)(v1 + 9) = 1;
    if ( (qword_923C90 & 1) != 0 )
    {
      qword_923C90 &= ~1uLL;
      return raw_spin_unlock_bh(&_osif_driver_sync_lock);
    }
    else
    {
      return raw_spin_unlock(&_osif_driver_sync_lock);
    }
  }
  return result;
}
