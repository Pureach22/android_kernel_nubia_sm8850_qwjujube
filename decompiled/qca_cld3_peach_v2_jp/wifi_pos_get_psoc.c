__int64 wifi_pos_get_psoc()
{
  unsigned __int64 StatusReg; // x8
  __int64 v1; // x8
  __int64 v2; // x20

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(&psoc_ptr_lock);
    v1 = qword_865268;
  }
  else
  {
    raw_spin_lock_bh(&psoc_ptr_lock);
    v1 = qword_865268 | 1;
    qword_865268 |= 1uLL;
  }
  v2 = wifi_pos_psoc_obj;
  if ( (v1 & 1) != 0 )
  {
    qword_865268 = v1 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(&psoc_ptr_lock);
  }
  else
  {
    raw_spin_unlock(&psoc_ptr_lock);
  }
  return v2;
}
