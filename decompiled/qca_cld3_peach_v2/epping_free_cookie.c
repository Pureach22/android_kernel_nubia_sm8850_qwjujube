__int64 __fastcall epping_free_cookie(__int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  int v5; // w9
  __int64 v6; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 456);
  }
  else
  {
    raw_spin_lock_bh(a1 + 456);
    *(_QWORD *)(a1 + 464) |= 1uLL;
  }
  *(_QWORD *)(a2 + 112) = *(_QWORD *)(a1 + 408);
  v5 = *(_DWORD *)(a1 + 416);
  v6 = *(_QWORD *)(a1 + 464);
  *(_QWORD *)(a1 + 408) = a2;
  *(_DWORD *)(a1 + 416) = v5 + 1;
  if ( (v6 & 1) == 0 )
    return raw_spin_unlock(a1 + 456);
  *(_QWORD *)(a1 + 464) = v6 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(a1 + 456);
}
