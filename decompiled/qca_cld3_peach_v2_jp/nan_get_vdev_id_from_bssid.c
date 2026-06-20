__int64 __fastcall nan_get_vdev_id_from_bssid(__int64 a1, const void *a2, unsigned int a3)
{
  unsigned int v5; // w21
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
  _QWORD *v17; // x22
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int *v26; // x8
  _QWORD *v27[2]; // [xsp+0h] [xbp-10h] BYREF

  v27[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)qdf_mem_cmp(a2, &unk_889D37, 4u) )
  {
    v5 = 255;
    goto LABEL_10;
  }
  v27[0] = nullptr;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 1240);
  }
  else
  {
    raw_spin_lock_bh(a1 + 1240);
    *(_QWORD *)(a1 + 1248) |= 1uLL;
  }
  if ( (unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 48), v27) )
  {
LABEL_8:
    v5 = 255;
    v15 = *(_QWORD *)(a1 + 1248);
    if ( (v15 & 1) != 0 )
      goto LABEL_16;
    goto LABEL_9;
  }
  while ( 1 )
  {
    v17 = v27[0];
    if ( !(unsigned int)wlan_objmgr_vdev_try_get_ref((__int64)v27[0], a3, v7, v8, v9, v10, v11, v12, v13, v14) )
      break;
LABEL_11:
    if ( (unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 48), v27[0], v27) )
      goto LABEL_8;
  }
  v26 = (unsigned int *)*((unsigned int *)v17 + 4);
  if ( (_DWORD)v26 != 16 )
  {
    wlan_objmgr_vdev_release_ref((__int64)v17, a3, v26, v18, v19, v20, v21, v22, v23, v24, v25);
    goto LABEL_11;
  }
  v5 = *((unsigned __int8 *)v17 + 104);
  wlan_objmgr_vdev_release_ref((__int64)v17, a3, v26, v18, v19, v20, v21, v22, v23, v24, v25);
  v15 = *(_QWORD *)(a1 + 1248);
  if ( (v15 & 1) != 0 )
  {
LABEL_16:
    *(_QWORD *)(a1 + 1248) = v15 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 1240);
    goto LABEL_10;
  }
LABEL_9:
  raw_spin_unlock(a1 + 1240);
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return v5;
}
