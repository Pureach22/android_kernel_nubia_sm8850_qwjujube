__int64 __fastcall wlan_objmgr_psoc_pdev_detach(__int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  char v6; // w8
  char v7; // w9
  __int64 v8; // x8
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7

  if ( *(_BYTE *)(a2 + 40) )
    return 16;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 2816);
  }
  else
  {
    raw_spin_lock_bh(a1 + 2816);
    *(_QWORD *)(a1 + 2824) |= 1uLL;
  }
  v6 = *(_BYTE *)(a1 + 50);
  v7 = *(_BYTE *)(a1 + 49);
  *(_QWORD *)(a1 + 64) = 0;
  *(_BYTE *)(a1 + 50) = v6 & 0xFE;
  *(_BYTE *)(a1 + 49) = v7 - 1;
  *(_BYTE *)(a2 + 40) = -1;
  v8 = *(_QWORD *)(a1 + 2824);
  if ( (v8 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 2824) = v8 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 2816);
  }
  else
  {
    raw_spin_unlock(a1 + 2816);
  }
  wlan_objmgr_psoc_release_ref(a1, 0, v9, v10, v11, v12, v13, v14, v15, v16);
  return 0;
}
