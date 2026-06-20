__int64 __fastcall ucfg_pmo_set_moddtim_user_enable(__int64 a1, char a2)
{
  char v2; // w20
  __int64 comp_private_obj; // x0
  __int64 v4; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v6; // x8

  v2 = a2 & 1;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
  v4 = comp_private_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(comp_private_obj + 1056);
      v6 = *(_QWORD *)(v4 + 1064) | 1LL;
      *(_QWORD *)(v4 + 1064) = v6;
      *(_BYTE *)(v4 + 1040) = v2;
      if ( (v6 & 1) == 0 )
        return raw_spin_unlock(v4 + 1056);
LABEL_8:
      *(_QWORD *)(v4 + 1064) = v6 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(v4 + 1056);
    }
  }
  raw_spin_lock(comp_private_obj + 1056);
  v6 = *(_QWORD *)(v4 + 1064);
  *(_BYTE *)(v4 + 1040) = v2;
  if ( (v6 & 1) != 0 )
    goto LABEL_8;
  return raw_spin_unlock(v4 + 1056);
}
