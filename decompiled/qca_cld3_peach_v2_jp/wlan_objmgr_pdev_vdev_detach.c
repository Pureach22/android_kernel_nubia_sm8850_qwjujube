__int64 __fastcall wlan_objmgr_pdev_vdev_detach(__int64 a1, _QWORD *a2)
{
  unsigned __int64 StatusReg; // x8
  char v5; // w8
  __int64 v6; // x9
  unsigned int *v7; // x8
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v17; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(a1 + 1240);
      *(_QWORD *)(a1 + 1248) |= 1uLL;
      v5 = *(_BYTE *)(a1 + 41);
      if ( v5 )
        goto LABEL_5;
LABEL_12:
      v17 = *(_QWORD *)(a1 + 1248);
      if ( (v17 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 1248) = v17 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 1240);
      }
      else
      {
        raw_spin_unlock(a1 + 1240);
      }
      return 16;
    }
  }
  raw_spin_lock(a1 + 1240);
  v5 = *(_BYTE *)(a1 + 41);
  if ( !v5 )
    goto LABEL_12;
LABEL_5:
  if ( a2 )
  {
    qdf_list_remove_node(a1 + 48, a2);
    v5 = *(_BYTE *)(a1 + 41);
  }
  v6 = *(_QWORD *)(a1 + 1248);
  *(_BYTE *)(a1 + 41) = v5 - 1;
  if ( (v6 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 1248) = v6 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 1240);
  }
  else
  {
    raw_spin_unlock(a1 + 1240);
  }
  wlan_objmgr_pdev_release_ref(a1, 0, v7, v8, v9, v10, v11, v12, v13, v14, v15);
  return 0;
}
