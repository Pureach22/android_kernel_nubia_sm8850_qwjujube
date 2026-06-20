__int64 __fastcall _osif_vdev_sync_trans_start(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 StatusReg; // x8
  __int64 *v7; // x8
  unsigned int v8; // w23
  unsigned int v9; // w0

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
  *(_QWORD *)a2 = 0;
  v7 = &_osif_vdev_sync_arr;
  if ( byte_85AB08 == 1 && _osif_vdev_sync_arr == a1
    || (v7 = &qword_85AB10, byte_85AB20 == 1) && qword_85AB10 == a1
    || (v7 = &qword_85AB28, byte_85AB38 == 1) && qword_85AB28 == a1
    || (v7 = &qword_85AB40, byte_85AB50 == 1) && qword_85AB40 == a1
    || (v7 = &qword_85AB58, byte_85AB68 == 1) && qword_85AB58 == a1
    || (v7 = &qword_85AB70, v8 = -11, byte_85AB80 == 1) && qword_85AB70 == a1 )
  {
    *(_QWORD *)a2 = v7;
    v9 = dsc_vdev_trans_start(v7[1], a3);
    if ( v9 )
      v8 = qdf_status_to_os_return(v9);
    else
      v8 = 0;
  }
  if ( (qword_85AB90 & 1) != 0 )
  {
    qword_85AB90 &= ~1uLL;
    raw_spin_unlock_bh(&_osif_vdev_sync_lock);
    if ( v8 )
      return v8;
    goto LABEL_22;
  }
  raw_spin_unlock(&_osif_vdev_sync_lock);
  if ( !v8 )
  {
LABEL_22:
    dsc_vdev_wait_for_ops(*(_QWORD *)(*(_QWORD *)a2 + 8LL));
    dsc_vdev_wait_for_uptree_ops(*(_QWORD *)(*(_QWORD *)a2 + 8LL));
  }
  return v8;
}
