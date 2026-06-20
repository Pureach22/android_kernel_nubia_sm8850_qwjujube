__int64 __fastcall wlan_get_self_macaddr_from_vdev_id(__int64 a1, __int64 a2, unsigned int a3, void *a4)
{
  __int64 v6; // x0
  __int64 v7; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v9; // x8
  unsigned int *v10; // x8
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  v6 = ((__int64 (*)(void))wlan_objmgr_get_vdev_by_id_from_psoc)();
  if ( !v6 )
    return 16;
  v7 = v6;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v6 + 1344);
  }
  else
  {
    raw_spin_lock_bh(v6 + 1344);
    *(_QWORD *)(v7 + 1352) |= 1uLL;
  }
  qdf_mem_copy(a4, (const void *)(v7 + 74), 6u);
  v9 = *(_QWORD *)(v7 + 1352);
  if ( (v9 & 1) != 0 )
  {
    *(_QWORD *)(v7 + 1352) = v9 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v7 + 1344);
  }
  else
  {
    raw_spin_unlock(v7 + 1344);
  }
  wlan_objmgr_vdev_release_ref(v7, a3, v10, v11, v12, v13, v14, v15, v16, v17, v18);
  return 0;
}
