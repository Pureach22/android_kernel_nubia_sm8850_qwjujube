__int64 *__fastcall osif_vdev_sync_unregister(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 *v3; // x8
  __int64 *v4; // x21

  if ( !a1 )
    return nullptr;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(&_osif_vdev_sync_lock);
  }
  else
  {
    raw_spin_lock_bh(&_osif_vdev_sync_lock);
    qword_85AB90 |= 1uLL;
  }
  v3 = &_osif_vdev_sync_arr;
  if ( byte_85AB08 == 1 && _osif_vdev_sync_arr == a1
    || (v3 = &qword_85AB10, byte_85AB20 == 1) && qword_85AB10 == a1
    || (v3 = &qword_85AB28, byte_85AB38 == 1) && qword_85AB28 == a1
    || (v3 = &qword_85AB40, byte_85AB50 == 1) && qword_85AB40 == a1
    || (v3 = &qword_85AB58, byte_85AB68 == 1) && qword_85AB58 == a1
    || (v3 = &qword_85AB70, v4 = nullptr, byte_85AB80 == 1) && qword_85AB70 == a1 )
  {
    v4 = v3;
    *v3 = 0;
  }
  if ( (qword_85AB90 & 1) != 0 )
  {
    qword_85AB90 &= ~1uLL;
    raw_spin_unlock_bh(&_osif_vdev_sync_lock);
  }
  else
  {
    raw_spin_unlock(&_osif_vdev_sync_lock);
  }
  return v4;
}
