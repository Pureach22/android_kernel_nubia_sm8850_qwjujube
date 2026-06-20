__int64 __fastcall osif_psoc_sync_trans_resume(__int64 a1, _QWORD *a2)
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
  *a2 = 0;
  v5 = -11;
  if ( byte_85AAF0 == 1 && _osif_psoc_sync_arr == a1 )
  {
    dsc_psoc_assert_trans_protected(qword_85AAE8);
    v5 = 0;
    *a2 = &_osif_psoc_sync_arr;
  }
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
