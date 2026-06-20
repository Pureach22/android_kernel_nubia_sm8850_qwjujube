__int64 __fastcall wlan_vdev_get_peer_sta_count(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 *v11; // x23
  unsigned int v12; // w20
  __int64 *v13; // x24
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8

  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 1272);
  }
  else
  {
    raw_spin_lock_bh(a1 + 1272);
    *(_QWORD *)(a1 + 1280) |= 1uLL;
  }
  v11 = *(__int64 **)(a1 + 128);
  if ( v11 != (__int64 *)(a1 + 128) )
  {
    v12 = 0;
    do
    {
      v13 = (__int64 *)*v11;
      wlan_objmgr_peer_get_ref((__int64)(v11 - 2), 0, v3, v4, v5, v6, v7, v8, v9, v10);
      if ( *((_DWORD *)v11 + 13) == 4 )
        ++v12;
      wlan_objmgr_peer_release_ref((__int64)(v11 - 2), 0, v14, v15, v16, v17, v18, v19, v20, v21);
      v11 = v13;
    }
    while ( v13 != (__int64 *)(a1 + 128) );
    v22 = *(_QWORD *)(a1 + 1280);
    if ( (v22 & 1) == 0 )
      goto LABEL_11;
LABEL_14:
    *(_QWORD *)(a1 + 1280) = v22 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 1272);
    return v12;
  }
  v12 = 0;
  v22 = *(_QWORD *)(a1 + 1280);
  if ( (v22 & 1) != 0 )
    goto LABEL_14;
LABEL_11:
  raw_spin_unlock(a1 + 1272);
  return v12;
}
