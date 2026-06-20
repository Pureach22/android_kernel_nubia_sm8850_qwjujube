__int64 __fastcall dp_sap_p2p_update_mid_high_tput(__int64 a1, unsigned __int64 a2)
{
  __int64 result; // x0
  unsigned __int64 v4; // x8
  unsigned __int64 StatusReg; // x8
  __int64 v6; // x8
  __int64 v7; // x8
  unsigned __int64 v8; // x20
  __int64 v9; // x8
  __int64 v10; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v11[2]; // [xsp+10h] [xbp-10h] BYREF

  result = 0;
  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned int *)(a1 + 72);
  v10 = 0;
  v11[0] = 0;
  if ( !(_DWORD)v4 || v4 >= a2 )
    goto LABEL_24;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 264);
  }
  else
  {
    raw_spin_lock_bh(a1 + 264);
    *(_QWORD *)(a1 + 272) |= 1uLL;
  }
  dp_get_front_intf_no_lock(a1, v11);
  dp_get_next_intf_no_lock(a1, v11[0], &v10);
  v6 = *(_QWORD *)(a1 + 272);
  if ( (v6 & 1) == 0 )
  {
    raw_spin_unlock(a1 + 264);
    v7 = v11[0];
    if ( v11[0] )
      goto LABEL_9;
LABEL_23:
    result = 0;
    goto LABEL_24;
  }
  *(_QWORD *)(a1 + 272) = v6 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(a1 + 264);
  v7 = v11[0];
  if ( !v11[0] )
    goto LABEL_23;
LABEL_9:
  v8 = _ReadStatusReg(SP_EL0);
  while ( (*(_DWORD *)(v7 + 28) | 2) != 3 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(v8 + 16) & 0xF0000) != 0
      || (*(_DWORD *)(v8 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 264);
    }
    else
    {
      raw_spin_lock_bh(a1 + 264);
      *(_QWORD *)(a1 + 272) |= 1uLL;
    }
    v11[0] = v10;
    dp_get_next_intf_no_lock(a1, v10, &v10);
    v9 = *(_QWORD *)(a1 + 272);
    if ( (v9 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 272) = v9 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 264);
      v7 = v11[0];
      if ( !v11[0] )
        goto LABEL_23;
    }
    else
    {
      raw_spin_unlock(a1 + 264);
      v7 = v11[0];
      if ( !v11[0] )
        goto LABEL_23;
    }
  }
  result = 1;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
