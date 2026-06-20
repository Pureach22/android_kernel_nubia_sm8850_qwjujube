__int64 __fastcall ucfg_dp_update_intf_tx_block_mask(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x8
  __int64 result; // x0
  _QWORD *v5; // x8
  unsigned __int64 v6; // x20
  __int64 v7; // x8
  _QWORD *v8; // [xsp+8h] [xbp-18h] BYREF
  _QWORD *v9[2]; // [xsp+10h] [xbp-10h] BYREF

  v9[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = nullptr;
  v9[0] = nullptr;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 3672);
  }
  else
  {
    raw_spin_lock_bh(a1 + 3672);
    *(_QWORD *)(a1 + 3680) |= 1uLL;
  }
  dp_get_front_link_no_lock(a1, v9);
  dp_get_next_link_no_lock(a1, v9[0], &v8);
  v3 = *(_QWORD *)(a1 + 3680);
  if ( (v3 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 3680) = v3 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(a1 + 3672);
    v5 = v9[0];
    if ( !v9[0] )
      goto LABEL_21;
  }
  else
  {
    result = raw_spin_unlock(a1 + 3672);
    v5 = v9[0];
    if ( !v9[0] )
      goto LABEL_21;
  }
  v6 = _ReadStatusReg(SP_EL0);
  do
  {
    while ( 1 )
    {
      if ( !*((_DWORD *)v5 + 20) )
        *(_BYTE *)(a1 + 3580) = 0;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v6 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v6 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a1 + 3672);
      }
      else
      {
        raw_spin_lock_bh(a1 + 3672);
        *(_QWORD *)(a1 + 3680) |= 1uLL;
      }
      v9[0] = v8;
      dp_get_next_link_no_lock(a1, v8, &v8);
      v7 = *(_QWORD *)(a1 + 3680);
      if ( (v7 & 1) != 0 )
        break;
      result = raw_spin_unlock(a1 + 3672);
      v5 = v9[0];
      if ( !v9[0] )
        goto LABEL_21;
    }
    *(_QWORD *)(a1 + 3680) = v7 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(a1 + 3672);
    v5 = v9[0];
  }
  while ( v9[0] );
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
