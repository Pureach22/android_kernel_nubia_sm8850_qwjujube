__int64 __fastcall dp_txrx_peer_attach_add(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 StatusReg; // x8
  int v7; // w8
  __int64 v8; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 13256);
  }
  else
  {
    raw_spin_lock_bh(a1 + 13256);
    *(_QWORD *)(a1 + 13264) |= 1uLL;
  }
  *(_QWORD *)a2 = a3;
  *(_BYTE *)(a3 + 88) = *(_BYTE *)(a3 + 88) & 0xFD | (2 * (*(_BYTE *)(a2 + 120) & 1));
  v7 = *(unsigned __int16 *)(a2 + 16);
  if ( v7 != 0xFFFF )
    *(_WORD *)(a3 + 8) = v7;
  v8 = *(_QWORD *)(a1 + 13264);
  if ( (v8 & 1) == 0 )
    return raw_spin_unlock(a1 + 13256);
  *(_QWORD *)(a1 + 13264) = v8 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(a1 + 13256);
}
