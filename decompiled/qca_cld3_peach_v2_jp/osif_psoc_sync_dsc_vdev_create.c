__int64 __fastcall osif_psoc_sync_dsc_vdev_create(__int64 a1, __int64 *a2)
{
  unsigned __int64 StatusReg; // x8
  unsigned int v5; // w22

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(&_osif_psoc_sync_lock);
  }
  else
  {
    raw_spin_lock_bh(&_osif_psoc_sync_lock);
    qword_85AAD8 |= 1uLL;
  }
  v5 = 4;
  if ( byte_85AAF0 == 1 && _osif_psoc_sync_arr == a1 )
    v5 = dsc_vdev_create(qword_85AAE8, a2);
  if ( (qword_85AAD8 & 1) != 0 )
  {
    qword_85AAD8 &= ~1uLL;
    raw_spin_unlock_bh(&_osif_psoc_sync_lock);
  }
  else
  {
    raw_spin_unlock(&_osif_psoc_sync_lock);
  }
  return v5;
}
