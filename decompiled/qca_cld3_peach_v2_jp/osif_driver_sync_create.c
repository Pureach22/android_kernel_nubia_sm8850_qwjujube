__int64 __fastcall osif_driver_sync_create(__int64 **a1)
{
  unsigned __int64 StatusReg; // x8
  char v3; // w21
  __int64 *v4; // x20
  __int64 result; // x0
  unsigned int v6; // w21
  unsigned __int64 v7; // x8

  if ( !a1 )
    return 4294967274LL;
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
  v3 = byte_85AAC8;
  if ( (byte_85AAC8 & 1) != 0 )
  {
    v4 = nullptr;
  }
  else
  {
    v4 = &_osif_driver_sync;
    byte_85AAC8 = 1;
  }
  if ( (qword_85AAB8 & 1) != 0 )
  {
    qword_85AAB8 &= ~1uLL;
    raw_spin_unlock_bh(&_osif_driver_sync_lock);
    if ( (v3 & 1) != 0 )
      return 4294967284LL;
  }
  else
  {
    raw_spin_unlock(&_osif_driver_sync_lock);
    if ( (v3 & 1) != 0 )
      return 4294967284LL;
  }
  result = dsc_driver_create(v4);
  if ( (_DWORD)result )
  {
    v6 = result;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v7 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v7 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v7 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(&_osif_driver_sync_lock);
    }
    else
    {
      raw_spin_lock_bh(&_osif_driver_sync_lock);
      qword_85AAB8 |= 1uLL;
    }
    qdf_mem_set(v4, 0x10u, 0);
    if ( (qword_85AAB8 & 1) != 0 )
    {
      qword_85AAB8 &= ~1uLL;
      raw_spin_unlock_bh(&_osif_driver_sync_lock);
    }
    else
    {
      raw_spin_unlock(&_osif_driver_sync_lock);
    }
    return qdf_status_to_os_return(v6);
  }
  else
  {
    *a1 = v4;
  }
  return result;
}
