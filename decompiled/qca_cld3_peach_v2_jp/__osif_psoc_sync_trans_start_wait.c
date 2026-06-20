__int64 __fastcall _osif_psoc_sync_trans_start_wait(__int64 a1, _QWORD *a2, __int64 a3)
{
  unsigned __int64 StatusReg; // x8
  __int64 v7; // x8
  int v8; // w22
  __int64 result; // x0

  *a2 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(&_osif_psoc_sync_lock);
    v7 = qword_85AAD8;
  }
  else
  {
    raw_spin_lock_bh(&_osif_psoc_sync_lock);
    v7 = qword_85AAD8 | 1;
    qword_85AAD8 |= 1uLL;
  }
  if ( _osif_psoc_sync_arr == a1 )
    v8 = (unsigned __int8)byte_85AAF0;
  else
    v8 = 0;
  if ( (v7 & 1) == 0 )
  {
    raw_spin_unlock(&_osif_psoc_sync_lock);
    if ( v8 )
      goto LABEL_10;
    return 4294967285LL;
  }
  qword_85AAD8 = v7 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(&_osif_psoc_sync_lock);
  if ( !v8 )
    return 4294967285LL;
LABEL_10:
  result = dsc_psoc_trans_start_wait((__int64 *)qword_85AAE8, a3);
  if ( (_DWORD)result )
    return qdf_status_to_os_return(result);
  *a2 = &_osif_psoc_sync_arr;
  return result;
}
