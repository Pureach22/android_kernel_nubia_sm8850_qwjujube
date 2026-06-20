__int64 __fastcall osif_psoc_sync_assert_trans_protected(__int64 a1)
{
  unsigned __int64 StatusReg; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(&_osif_psoc_sync_lock);
  }
  else
  {
    raw_spin_lock_bh(&_osif_psoc_sync_lock);
    qword_923CB0 |= 1uLL;
  }
  if ( byte_923CC8 == 1 && _osif_psoc_sync_arr == a1 )
    dsc_psoc_assert_trans_protected(qword_923CC0);
  if ( (qword_923CB0 & 1) == 0 )
    return raw_spin_unlock(&_osif_psoc_sync_lock);
  qword_923CB0 &= ~1uLL;
  return raw_spin_unlock_bh(&_osif_psoc_sync_lock);
}
