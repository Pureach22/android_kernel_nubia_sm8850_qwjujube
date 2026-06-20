__int64 __fastcall wlan_objmgr_get_vdev_by_id_from_psoc_no_state(__int64 a1, unsigned __int8 a2, unsigned int a3)
{
  unsigned __int64 StatusReg; // x8
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x20
  __int64 v10; // x8

  if ( !a1 || *(unsigned __int16 *)(a1 + 54) <= (unsigned int)a2 )
    return 0;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    v7 = raw_spin_lock(a1 + 2816);
  }
  else
  {
    v7 = raw_spin_lock_bh(a1 + 2816);
    *(_QWORD *)(a1 + 2824) |= 1uLL;
  }
  if ( a2 < 6u )
  {
    v8 = a1 + 8LL * a2;
    v9 = *(_QWORD *)(v8 + 72);
    if ( v9 )
      wlan_objmgr_vdev_get_ref(*(_QWORD *)(v8 + 72), a3);
    v10 = *(_QWORD *)(a1 + 2824);
    if ( (v10 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 2824) = v10 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 2816);
    }
    else
    {
      raw_spin_unlock(a1 + 2816);
    }
    return v9;
  }
  __break(0x5512u);
  return wlan_objmgr_free_all_objects_per_psoc(v7);
}
