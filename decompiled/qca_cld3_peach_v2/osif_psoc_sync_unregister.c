__int64 *__fastcall osif_psoc_sync_unregister(__int64 *a1)
{
  __int64 *v1; // x20
  unsigned __int64 StatusReg; // x8
  int v3; // w9

  v1 = a1;
  if ( a1 )
  {
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
    v3 = (unsigned __int8)byte_923CC8 & (_osif_psoc_sync_arr == (_QWORD)v1);
    if ( ((unsigned __int8)byte_923CC8 & (_osif_psoc_sync_arr == (_QWORD)v1)) != 0 )
      v1 = &_osif_psoc_sync_arr;
    else
      v1 = nullptr;
    if ( v3 == 1 )
      _osif_psoc_sync_arr = 0;
    if ( (qword_923CB0 & 1) != 0 )
    {
      qword_923CB0 &= ~1uLL;
      raw_spin_unlock_bh(&_osif_psoc_sync_lock);
    }
    else
    {
      raw_spin_unlock(&_osif_psoc_sync_lock);
    }
  }
  return v1;
}
