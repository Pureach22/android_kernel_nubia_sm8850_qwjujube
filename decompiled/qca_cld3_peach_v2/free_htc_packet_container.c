__int64 __fastcall free_htc_packet_container(__int64 a1, _QWORD *a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x8
  __int64 v6; // x8

  *a2 = 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 2976);
    v5 = *(_QWORD *)(a1 + 3072);
    if ( v5 )
      goto LABEL_5;
LABEL_9:
    *(_QWORD *)(a1 + 3072) = a2;
    a2[1] = 0;
    v6 = *(_QWORD *)(a1 + 2984);
    if ( (v6 & 1) == 0 )
      return raw_spin_unlock(a1 + 2976);
LABEL_10:
    *(_QWORD *)(a1 + 2984) = v6 & 0xFFFFFFFFFFFFFFFELL;
    return raw_spin_unlock_bh(a1 + 2976);
  }
  raw_spin_lock_bh(a1 + 2976);
  *(_QWORD *)(a1 + 2984) |= 1uLL;
  v5 = *(_QWORD *)(a1 + 3072);
  if ( !v5 )
    goto LABEL_9;
LABEL_5:
  a2[1] = v5;
  *(_QWORD *)(a1 + 3072) = a2;
  v6 = *(_QWORD *)(a1 + 2984);
  if ( (v6 & 1) != 0 )
    goto LABEL_10;
  return raw_spin_unlock(a1 + 2976);
}
