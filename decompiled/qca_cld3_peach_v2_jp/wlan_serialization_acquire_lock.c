__int64 __fastcall wlan_serialization_acquire_lock(__int64 a1)
{
  unsigned __int64 StatusReg; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1);
  }
  else
  {
    raw_spin_lock_bh(a1);
    *(_QWORD *)(a1 + 8) |= 1uLL;
  }
  return 0;
}
