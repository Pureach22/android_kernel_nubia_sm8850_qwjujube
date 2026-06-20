__int64 __fastcall epping_alloc_cookie(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x20
  int v4; // w9
  __int64 v5; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 456);
    v3 = *(_QWORD *)(a1 + 408);
    if ( !v3 )
      goto LABEL_6;
    goto LABEL_5;
  }
  raw_spin_lock_bh(a1 + 456);
  *(_QWORD *)(a1 + 464) |= 1uLL;
  v3 = *(_QWORD *)(a1 + 408);
  if ( v3 )
  {
LABEL_5:
    v4 = *(_DWORD *)(a1 + 416);
    *(_QWORD *)(a1 + 408) = *(_QWORD *)(v3 + 112);
    *(_DWORD *)(a1 + 416) = v4 - 1;
  }
LABEL_6:
  v5 = *(_QWORD *)(a1 + 464);
  if ( (v5 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 464) = v5 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 456);
  }
  else
  {
    raw_spin_unlock(a1 + 456);
  }
  return v3;
}
