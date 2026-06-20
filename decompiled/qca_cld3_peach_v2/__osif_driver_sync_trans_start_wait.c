__int64 __fastcall _osif_driver_sync_trans_start_wait(_QWORD *a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x8
  int v6; // w22
  __int64 result; // x0

  *a1 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(&_osif_driver_sync_lock);
    v5 = qword_923C90;
  }
  else
  {
    raw_spin_lock_bh(&_osif_driver_sync_lock);
    v5 = qword_923C90 | 1;
    qword_923C90 |= 1uLL;
  }
  v6 = (unsigned __int8)byte_923CA1;
  if ( (v5 & 1) == 0 )
  {
    raw_spin_unlock(&_osif_driver_sync_lock);
    if ( v6 )
      goto LABEL_7;
    return 4294967285LL;
  }
  qword_923C90 = v5 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(&_osif_driver_sync_lock);
  if ( !v6 )
    return 4294967285LL;
LABEL_7:
  result = dsc_driver_trans_start_wait((_QWORD *)_osif_driver_sync, a2);
  if ( (_DWORD)result )
    return qdf_status_to_os_return(result);
  *a1 = &_osif_driver_sync;
  return result;
}
