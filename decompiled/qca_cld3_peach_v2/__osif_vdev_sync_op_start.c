__int64 __fastcall _osif_vdev_sync_op_start(__int64 a1, __int64 **a2, __int64 a3)
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
    qword_923DB0 |= 1uLL;
  }
  *a2 = nullptr;
  v7 = &_osif_vdev_sync_arr;
  if ( byte_923CE0 == 1 && _osif_vdev_sync_arr == a1 )
    goto LABEL_23;
  v7 = &qword_923CE8;
  if ( byte_923CF8 == 1 && qword_923CE8 == a1 )
    goto LABEL_23;
  v7 = &qword_923D00;
  if ( byte_923D10 == 1 && qword_923D00 == a1 )
    goto LABEL_23;
  if ( (v7 = &qword_923D18, byte_923D28 == 1) && qword_923D18 == a1
    || (v7 = &qword_923D30, byte_923D40 == 1) && qword_923D30 == a1
    || (v7 = &qword_923D48, byte_923D58 == 1) && qword_923D48 == a1
    || (v7 = &qword_923D60, byte_923D70 == 1) && qword_923D60 == a1
    || (v7 = &qword_923D78, byte_923D88 == 1) && qword_923D78 == a1
    || (v7 = &qword_923D90, v8 = -11, byte_923DA0 == 1) && qword_923D90 == a1 )
  {
LABEL_23:
    *a2 = v7;
    v9 = dsc_vdev_op_start(v7[1], a3);
    if ( v9 )
      v8 = qdf_status_to_os_return(v9);
    else
      v8 = 0;
  }
  if ( (qword_923DB0 & 1) != 0 )
  {
    qword_923DB0 &= ~1uLL;
    raw_spin_unlock_bh(&_osif_vdev_sync_lock);
  }
  else
  {
    raw_spin_unlock(&_osif_vdev_sync_lock);
  }
  return v8;
}
