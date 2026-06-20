__int64 __fastcall allocate_htc_packet_container(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x20
  __int64 v4; // x8
  __int64 v5; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(a1 + 2976);
      *(_QWORD *)(a1 + 2984) |= 1uLL;
      v3 = *(_QWORD *)(a1 + 3072);
      if ( v3 )
        goto LABEL_5;
LABEL_10:
      v5 = *(_QWORD *)(a1 + 2984);
      if ( (v5 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 2984) = v5 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 2976);
      }
      else
      {
        raw_spin_unlock(a1 + 2976);
      }
      return v3;
    }
  }
  raw_spin_lock(a1 + 2976);
  v3 = *(_QWORD *)(a1 + 3072);
  if ( !v3 )
    goto LABEL_10;
LABEL_5:
  v4 = *(_QWORD *)(a1 + 2984);
  *(_QWORD *)(a1 + 3072) = *(_QWORD *)(v3 + 8);
  if ( (v4 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 2984) = v4 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 2976);
  }
  else
  {
    raw_spin_unlock(a1 + 2976);
  }
  *(_QWORD *)(v3 + 8) = 0;
  return v3;
}
