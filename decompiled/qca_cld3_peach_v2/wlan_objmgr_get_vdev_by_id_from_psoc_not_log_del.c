__int64 __fastcall wlan_objmgr_get_vdev_by_id_from_psoc_not_log_del(__int64 a1, unsigned __int8 a2, unsigned int a3)
{
  unsigned __int64 StatusReg; // x8
  __int64 v7; // x20
  __int64 v8; // x8

  if ( !a1 || *(unsigned __int16 *)(a1 + 54) <= (unsigned int)a2 )
    return 0;
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
  if ( a2 >= 6u )
  {
    __break(0x5512u);
    JUMPOUT(0x1C5D50);
  }
  v7 = *(_QWORD *)(a1 + 8LL * a2 + 72);
  if ( v7 )
  {
    if ( *(_DWORD *)(v7 + 1336) == 6 )
      v7 = 0;
    else
      wlan_objmgr_vdev_get_ref(v7, a3);
  }
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
  return v7;
}
