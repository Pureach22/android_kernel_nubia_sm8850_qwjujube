__int64 __fastcall osif_vdev_sync_assert_trans_protected(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 *v3; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(&_osif_vdev_sync_lock);
  }
  else
  {
    raw_spin_lock_bh(&_osif_vdev_sync_lock);
    qword_923DB0 |= 1uLL;
  }
  v3 = &_osif_vdev_sync_arr;
  if ( byte_923CE0 == 1 && _osif_vdev_sync_arr == a1 )
    goto LABEL_23;
  v3 = &qword_923CE8;
  if ( byte_923CF8 == 1 && qword_923CE8 == a1 )
    goto LABEL_23;
  if ( (v3 = &qword_923D00, byte_923D10 == 1) && qword_923D00 == a1
    || (v3 = &qword_923D18, byte_923D28 == 1) && qword_923D18 == a1
    || (v3 = &qword_923D30, byte_923D40 == 1) && qword_923D30 == a1
    || (v3 = &qword_923D48, byte_923D58 == 1) && qword_923D48 == a1
    || (v3 = &qword_923D60, byte_923D70 == 1) && qword_923D60 == a1
    || (v3 = &qword_923D78, byte_923D88 == 1) && qword_923D78 == a1
    || (v3 = &qword_923D90, byte_923DA0 == 1) && qword_923D90 == a1 )
  {
LABEL_23:
    dsc_vdev_assert_trans_protected(v3[1]);
  }
  if ( (qword_923DB0 & 1) == 0 )
    return raw_spin_unlock(&_osif_vdev_sync_lock);
  qword_923DB0 &= ~1uLL;
  return raw_spin_unlock_bh(&_osif_vdev_sync_lock);
}
