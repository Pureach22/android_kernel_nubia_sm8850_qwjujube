__int64 __fastcall dp_intf_get_next_deflink_candidate(__int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x22
  _QWORD *v6; // x24
  __int64 v7; // x8
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned __int64 v16; // x23
  __int64 v17; // x8
  _QWORD *v18; // x21
  char v19; // w0
  _QWORD *v20; // x1
  _QWORD v22[2]; // [xsp+0h] [xbp-10h] BYREF

  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
  v22[0] = 0;
  if ( (unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 3688), v22) )
  {
    v5 = 0;
    goto LABEL_7;
  }
  v5 = v22[0];
  if ( !v22[0] )
  {
LABEL_7:
    v6 = nullptr;
    v7 = *(_QWORD *)(a1 + 3680);
    if ( (v7 & 1) == 0 )
      goto LABEL_8;
LABEL_31:
    *(_QWORD *)(a1 + 3680) = v7 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 3672);
    if ( v5 )
      goto LABEL_9;
    goto LABEL_32;
  }
  v20 = (_QWORD *)v22[0];
  v22[0] = 0;
  if ( (unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 3688), v20, v22) )
    v6 = nullptr;
  else
    v6 = (_QWORD *)v22[0];
  v7 = *(_QWORD *)(a1 + 3680);
  if ( (v7 & 1) != 0 )
    goto LABEL_31;
LABEL_8:
  raw_spin_unlock(a1 + 3672);
  if ( v5 )
  {
LABEL_9:
    v16 = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v18 = v6;
      v19 = is_dp_link_valid(v5, v8, v9, v10, v11, v12, v13, v14, v15);
      if ( v5 != a2 && (v19 & 1) != 0 )
        break;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (*(_DWORD *)(v16 + 16) & 0xF0000) != 0
        || (*(_DWORD *)(v16 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a1 + 3672);
        if ( v6 )
          goto LABEL_18;
LABEL_10:
        v6 = nullptr;
        v17 = *(_QWORD *)(a1 + 3680);
        if ( (v17 & 1) == 0 )
          goto LABEL_11;
LABEL_22:
        *(_QWORD *)(a1 + 3680) = v17 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 3672);
        v5 = (__int64)v18;
        if ( !v18 )
          break;
      }
      else
      {
        raw_spin_lock_bh(a1 + 3672);
        *(_QWORD *)(a1 + 3680) |= 1uLL;
        if ( !v6 )
          goto LABEL_10;
LABEL_18:
        v22[0] = 0;
        if ( (unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 3688), v6, v22) )
          v6 = nullptr;
        else
          v6 = (_QWORD *)v22[0];
        v17 = *(_QWORD *)(a1 + 3680);
        if ( (v17 & 1) != 0 )
          goto LABEL_22;
LABEL_11:
        raw_spin_unlock(a1 + 3672);
        v5 = (__int64)v18;
        if ( !v18 )
          break;
      }
    }
  }
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return v5;
}
