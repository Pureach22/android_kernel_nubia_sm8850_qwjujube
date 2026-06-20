__int64 __fastcall htc_send_complete_check_cleanup(__int64 a1)
{
  __int64 v1; // x8
  unsigned __int64 StatusReg; // x9
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x8
  unsigned __int64 v7; // x9
  __int64 v8; // x8
  __int64 v9; // x9
  __int64 v11; // x20
  __int64 v12; // x20

  v1 = *(_QWORD *)(a1 + 280);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v1 + 2992);
    if ( !*(_DWORD *)(a1 + 200) )
      goto LABEL_6;
    goto LABEL_5;
  }
  v11 = v1;
  raw_spin_lock_bh(v1 + 2992);
  *(_QWORD *)(v11 + 3000) |= 1uLL;
  if ( *(_DWORD *)(a1 + 200) )
LABEL_5:
    *(_DWORD *)(a1 + 200) = 0;
LABEL_6:
  v4 = *(_QWORD *)(a1 + 280);
  v5 = *(_QWORD *)(v4 + 3000);
  if ( (v5 & 1) != 0 )
  {
    *(_QWORD *)(v4 + 3000) = v5 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v4 + 2992);
  }
  else
  {
    raw_spin_unlock(v4 + 2992);
  }
  hif_send_complete_check(**(_QWORD **)(a1 + 280), *(unsigned __int8 *)(a1 + 136), 1);
  v6 = *(_QWORD *)(a1 + 280);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v7 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v7 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v7 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v6 + 2992);
    if ( !*(_DWORD *)(a1 + 204) )
      goto LABEL_14;
  }
  else
  {
    v12 = v6;
    raw_spin_lock_bh(v6 + 2992);
    *(_QWORD *)(v12 + 3000) |= 1uLL;
    if ( !*(_DWORD *)(a1 + 204) )
      goto LABEL_14;
  }
  if ( !*(_DWORD *)(a1 + 200) )
    *(_DWORD *)(a1 + 200) = 1;
LABEL_14:
  v8 = *(_QWORD *)(a1 + 280);
  v9 = *(_QWORD *)(v8 + 3000);
  if ( (v9 & 1) == 0 )
    return raw_spin_unlock(v8 + 2992);
  *(_QWORD *)(v8 + 3000) = v9 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(v8 + 2992);
}
