__int64 __fastcall htt_htc_pkt_free(__int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 120);
  }
  else
  {
    raw_spin_lock_bh(a1 + 120);
    *(_QWORD *)(a1 + 128) |= 1uLL;
  }
  *(_DWORD *)(a2 + 120) = 0;
  *(_QWORD *)a2 = *(_QWORD *)(a1 + 72);
  v5 = *(_QWORD *)(a1 + 128);
  *(_QWORD *)(a1 + 72) = a2;
  if ( (v5 & 1) == 0 )
    return raw_spin_unlock(a1 + 120);
  *(_QWORD *)(a1 + 128) = v5 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(a1 + 120);
}
