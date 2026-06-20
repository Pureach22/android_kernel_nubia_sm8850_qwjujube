__int64 __fastcall wlan_objmgr_get_pdev_by_id(__int64 a1, char a2, unsigned int a3)
{
  __int64 v3; // x20
  unsigned __int64 StatusReg; // x8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x21
  __int64 v16; // x8

  if ( !a2 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 2816);
      v15 = *(_QWORD *)(a1 + 64);
      if ( v15 )
        goto LABEL_7;
    }
    else
    {
      raw_spin_lock_bh(a1 + 2816);
      *(_QWORD *)(a1 + 2824) |= 1uLL;
      v15 = *(_QWORD *)(a1 + 64);
      if ( v15 )
      {
LABEL_7:
        if ( (unsigned int)wlan_objmgr_pdev_try_get_ref(v15, a3, v7, v8, v9, v10, v11, v12, v13, v14) )
          v3 = 0;
        else
          v3 = v15;
        v16 = *(_QWORD *)(a1 + 2824);
        if ( (v16 & 1) == 0 )
          goto LABEL_11;
        goto LABEL_15;
      }
    }
    v3 = 0;
    v16 = *(_QWORD *)(a1 + 2824);
    if ( (v16 & 1) == 0 )
    {
LABEL_11:
      raw_spin_unlock(a1 + 2816);
      return v3;
    }
LABEL_15:
    *(_QWORD *)(a1 + 2824) = v16 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 2816);
    return v3;
  }
  return 0;
}
