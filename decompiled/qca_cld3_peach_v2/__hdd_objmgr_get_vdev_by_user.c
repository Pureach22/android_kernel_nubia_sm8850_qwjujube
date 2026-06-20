__int64 __fastcall _hdd_objmgr_get_vdev_by_user(__int64 a1, unsigned int a2, __int64 a3)
{
  unsigned __int64 StatusReg; // x8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x22
  __int64 v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 16);
    v15 = *(_QWORD *)(a1 + 32);
    if ( !v15 )
      goto LABEL_7;
  }
  else
  {
    raw_spin_lock_bh(a1 + 16);
    *(_QWORD *)(a1 + 24) |= 1uLL;
    v15 = *(_QWORD *)(a1 + 32);
    if ( !v15 )
      goto LABEL_7;
  }
  if ( (unsigned int)wlan_objmgr_vdev_try_get_ref(v15, a2, v7, v8, v9, v10, v11, v12, v13, v14) )
    v15 = 0;
LABEL_7:
  v16 = *(_QWORD *)(a1 + 24);
  if ( (v16 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 24) = v16 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 16);
    if ( v15 )
      return v15;
    goto LABEL_9;
  }
  raw_spin_unlock(a1 + 16);
  if ( !v15 )
LABEL_9:
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: VDEV is NULL (via %s, id %d)",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "__hdd_objmgr_get_vdev_by_user",
      a3,
      a2);
  return v15;
}
