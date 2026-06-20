__int64 __fastcall wlan_pmo_get_ps_params(__int64 a1, _QWORD *a2)
{
  __int64 comp_private_obj; // x0
  __int64 v4; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v6; // x8

  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
  if ( !comp_private_obj )
    return 29;
  v4 = comp_private_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(comp_private_obj + 1056);
  }
  else
  {
    raw_spin_lock_bh(comp_private_obj + 1056);
    *(_QWORD *)(v4 + 1064) |= 1uLL;
  }
  *a2 = *(_QWORD *)(v4 + 1016);
  v6 = *(_QWORD *)(v4 + 1064);
  if ( (v6 & 1) != 0 )
  {
    *(_QWORD *)(v4 + 1064) = v6 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v4 + 1056);
  }
  else
  {
    raw_spin_unlock(v4 + 1056);
  }
  return 0;
}
