__int64 __fastcall _osif_psoc_sync_op_start(__int64 a1, _QWORD *a2, __int64 a3)
{
  unsigned __int64 StatusReg; // x8
  unsigned int v7; // w23
  unsigned int v8; // w0

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
  *a2 = 0;
  v7 = -11;
  if ( byte_923CC8 == 1 && _osif_psoc_sync_arr == a1 )
  {
    v8 = dsc_psoc_op_start(qword_923CC0, a3);
    if ( v8 )
    {
      v7 = qdf_status_to_os_return(v8);
    }
    else
    {
      v7 = 0;
      *a2 = &_osif_psoc_sync_arr;
    }
  }
  if ( (qword_923CB0 & 1) != 0 )
  {
    qword_923CB0 &= ~1uLL;
    raw_spin_unlock_bh(&_osif_psoc_sync_lock);
  }
  else
  {
    raw_spin_unlock(&_osif_psoc_sync_lock);
  }
  return v7;
}
