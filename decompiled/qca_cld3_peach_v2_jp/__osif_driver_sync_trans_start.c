__int64 __fastcall _osif_driver_sync_trans_start(_QWORD *a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  unsigned int v5; // w0
  unsigned int v6; // w21

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(&_osif_driver_sync_lock);
  }
  else
  {
    raw_spin_lock_bh(&_osif_driver_sync_lock);
    qword_85AAB8 |= 1uLL;
  }
  *a1 = 0;
  if ( byte_85AAC9 == 1 )
  {
    v5 = dsc_driver_trans_start((_QWORD *)_osif_driver_sync, a2);
    if ( v5 )
    {
      v6 = qdf_status_to_os_return(v5);
    }
    else
    {
      v6 = 0;
      *a1 = &_osif_driver_sync;
    }
  }
  else
  {
    v6 = -11;
  }
  if ( (qword_85AAB8 & 1) != 0 )
  {
    qword_85AAB8 &= ~1uLL;
    raw_spin_unlock_bh(&_osif_driver_sync_lock);
  }
  else
  {
    raw_spin_unlock(&_osif_driver_sync_lock);
  }
  return v6;
}
