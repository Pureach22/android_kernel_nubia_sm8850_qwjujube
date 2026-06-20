__int64 __fastcall wlan_objmgr_get_pdev_by_id_no_state(__int64 a1, char a2, unsigned int a3)
{
  __int64 v3; // x21
  unsigned __int64 StatusReg; // x8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x8

  if ( a2 )
    return 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 2816);
    v3 = *(_QWORD *)(a1 + 64);
    if ( !v3 )
      goto LABEL_8;
    goto LABEL_7;
  }
  raw_spin_lock_bh(a1 + 2816);
  *(_QWORD *)(a1 + 2824) |= 1uLL;
  v3 = *(_QWORD *)(a1 + 64);
  if ( v3 )
LABEL_7:
    wlan_objmgr_pdev_get_ref(v3, a3, v7, v8, v9, v10, v11, v12, v13, v14);
LABEL_8:
  v15 = *(_QWORD *)(a1 + 2824);
  if ( (v15 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 2824) = v15 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 2816);
  }
  else
  {
    raw_spin_unlock(a1 + 2816);
  }
  return v3;
}
