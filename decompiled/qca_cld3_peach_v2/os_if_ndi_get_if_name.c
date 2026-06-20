__int64 __fastcall os_if_ndi_get_if_name(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x20
  __int64 v4; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 1344);
    v3 = *(_QWORD *)(a1 + 680);
    if ( v3 )
      goto LABEL_5;
LABEL_13:
    v4 = *(_QWORD *)(a1 + 1352);
    if ( (v4 & 1) != 0 )
      goto LABEL_10;
    goto LABEL_14;
  }
  raw_spin_lock_bh(a1 + 1344);
  *(_QWORD *)(a1 + 1352) |= 1uLL;
  v3 = *(_QWORD *)(a1 + 680);
  if ( !v3 )
    goto LABEL_13;
LABEL_5:
  v4 = *(_QWORD *)(a1 + 1352);
  if ( !*(_QWORD *)v3 )
  {
    if ( (v4 & 1) != 0 )
    {
LABEL_10:
      *(_QWORD *)(a1 + 1352) = v4 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1344);
      return 0;
    }
LABEL_14:
    raw_spin_unlock(a1 + 1344);
    return 0;
  }
  if ( (v4 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 1352) = v4 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 1344);
  }
  else
  {
    raw_spin_unlock(a1 + 1344);
  }
  return *(_QWORD *)(*(_QWORD *)v3 + 32LL) + 296LL;
}
