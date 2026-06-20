__int64 __fastcall dp_rx_desc_pool_deinit(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned __int64 StatusReg; // x8
  _DWORD *v7; // x8
  __int64 v8; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a2 + 56);
  }
  else
  {
    raw_spin_lock_bh(a2 + 56);
    *(_QWORD *)(a2 + 64) |= 1uLL;
  }
  *(_QWORD *)(a2 + 48) = 0;
  *(_DWORD *)a2 = 0;
  *(_BYTE *)(a2 + 77) = 0;
  _qdf_frag_cache_drain(a2 + 80);
  v7 = *(_DWORD **)(a1 + 1376);
  if ( *(v7 - 1) != 1736598477 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, __int64, _QWORD))v7)(a1, a2, a3);
  v8 = *(_QWORD *)(a2 + 64);
  if ( (v8 & 1) == 0 )
    return raw_spin_unlock(a2 + 56);
  *(_QWORD *)(a2 + 64) = v8 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(a2 + 56);
}
