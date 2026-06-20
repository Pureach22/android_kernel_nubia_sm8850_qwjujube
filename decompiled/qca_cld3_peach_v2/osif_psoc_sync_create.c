__int64 __fastcall osif_psoc_sync_create(__int64 **a1)
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
    raw_spin_lock(&_osif_psoc_sync_lock);
  }
  else
  {
    raw_spin_lock_bh(&_osif_psoc_sync_lock);
    qword_923CB0 |= 1uLL;
  }
  v3 = byte_923CC8;
  if ( (byte_923CC8 & 1) != 0 )
  {
    v4 = nullptr;
  }
  else
  {
    v4 = &_osif_psoc_sync_arr;
    byte_923CC8 = 1;
  }
  if ( (qword_923CB0 & 1) != 0 )
  {
    qword_923CB0 &= ~1uLL;
    raw_spin_unlock_bh(&_osif_psoc_sync_lock);
    if ( (v3 & 1) != 0 )
      return 4294967284LL;
  }
  else
  {
    raw_spin_unlock(&_osif_psoc_sync_lock);
    if ( (v3 & 1) != 0 )
      return 4294967284LL;
  }
  result = osif_driver_sync_dsc_psoc_create(v4 + 1);
  if ( (_DWORD)result )
  {
    v6 = result;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v7 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v7 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v7 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(&_osif_psoc_sync_lock);
    }
    else
    {
      raw_spin_lock_bh(&_osif_psoc_sync_lock);
      qword_923CB0 |= 1uLL;
    }
    qdf_mem_set(v4, 0x18u, 0);
    if ( (qword_923CB0 & 1) != 0 )
    {
      qword_923CB0 &= ~1uLL;
      raw_spin_unlock_bh(&_osif_psoc_sync_lock);
    }
    else
    {
      raw_spin_unlock(&_osif_psoc_sync_lock);
    }
    return qdf_status_to_os_return(v6);
  }
  else
  {
    *a1 = v4;
  }
  return result;
}
