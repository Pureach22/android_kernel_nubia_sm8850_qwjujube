__int64 *__fastcall osif_driver_sync_destroy(__int64 *result)
{
  __int64 *v1; // x20
  unsigned __int64 StatusReg; // x8

  if ( result )
  {
    v1 = result;
    dsc_driver_destroy(result);
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
    qdf_mem_set(v1, 0x10u, 0);
    if ( (qword_85AAB8 & 1) != 0 )
    {
      qword_85AAB8 &= ~1uLL;
      return (__int64 *)raw_spin_unlock_bh(&_osif_driver_sync_lock);
    }
    else
    {
      return (__int64 *)raw_spin_unlock(&_osif_driver_sync_lock);
    }
  }
  return result;
}
