__int64 __fastcall wlan_green_ap_check_mode(__int64 a1, __int64 a2, _BYTE *a3)
{
  unsigned __int64 StatusReg; // x8
  unsigned int v6; // w8
  __int64 v7; // x8

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
  v6 = *(_DWORD *)(a2 + 16);
  if ( v6 > 6 || ((1 << v6) & 0x43) == 0 )
  {
    *a3 = 1;
    v7 = *(_QWORD *)(a2 + 1280);
    if ( (v7 & 1) == 0 )
      return raw_spin_unlock(a2 + 1272);
LABEL_11:
    *(_QWORD *)(a2 + 1280) = v7 & 0xFFFFFFFFFFFFFFFELL;
    return raw_spin_unlock_bh(a2 + 1272);
  }
  v7 = *(_QWORD *)(a2 + 1280);
  if ( (v7 & 1) != 0 )
    goto LABEL_11;
  return raw_spin_unlock(a2 + 1272);
}
