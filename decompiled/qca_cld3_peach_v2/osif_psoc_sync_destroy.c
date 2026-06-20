__int64 __fastcall osif_psoc_sync_destroy(__int64 result)
{
  void *v1; // x20
  unsigned __int64 StatusReg; // x8

  if ( result )
  {
    v1 = (void *)result;
    dsc_psoc_destroy((_QWORD *)(result + 8));
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
    qdf_mem_set(v1, 0x18u, 0);
    if ( (qword_923CB0 & 1) != 0 )
    {
      qword_923CB0 &= ~1uLL;
      return raw_spin_unlock_bh(&_osif_psoc_sync_lock);
    }
    else
    {
      return raw_spin_unlock(&_osif_psoc_sync_lock);
    }
  }
  return result;
}
