__int64 __fastcall wlan_vdev_restart_progress(__int64 a1, __int64 a2, _BYTE *a3)
{
  unsigned __int64 StatusReg; // x8
  __int64 v6; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a2 + 1272);
  }
  else
  {
    raw_spin_lock_bh(a2 + 1272);
    *(_QWORD *)(a2 + 1280) |= 1uLL;
  }
  if ( !(unsigned int)wlan_vdev_is_restart_progress(a2) )
    *a3 = 1;
  v6 = *(_QWORD *)(a2 + 1280);
  if ( (v6 & 1) == 0 )
    return raw_spin_unlock(a2 + 1272);
  *(_QWORD *)(a2 + 1280) = v6 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(a2 + 1272);
}
