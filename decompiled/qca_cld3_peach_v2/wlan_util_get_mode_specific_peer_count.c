__int64 __fastcall wlan_util_get_mode_specific_peer_count(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 StatusReg; // x8
  unsigned int v6; // w8
  __int64 v7; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a2 + 1344);
  }
  else
  {
    raw_spin_lock_bh(a2 + 1344);
    *(_QWORD *)(a2 + 1352) |= 1uLL;
  }
  if ( *(_DWORD *)(a2 + 16) == *(_DWORD *)a3 )
  {
    v6 = *(unsigned __int16 *)(a2 + 224);
    if ( v6 >= 2 )
      *(_WORD *)(a3 + 4) = v6 + *(_WORD *)(a3 + 4) - 1;
  }
  v7 = *(_QWORD *)(a2 + 1352);
  if ( (v7 & 1) == 0 )
    return raw_spin_unlock(a2 + 1344);
  *(_QWORD *)(a2 + 1352) = v7 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(a2 + 1344);
}
