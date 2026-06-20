__int64 __fastcall ucfg_pmo_get_moddtim_user_enable(__int64 a1)
{
  __int64 comp_private_obj; // x0
  __int64 v2; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v4; // x8
  unsigned int v5; // w20

  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
  v2 = comp_private_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(comp_private_obj + 1056);
      v4 = *(_QWORD *)(v2 + 1064) | 1LL;
      *(_QWORD *)(v2 + 1064) = v4;
      v5 = *(unsigned __int8 *)(v2 + 1040);
      if ( (v4 & 1) == 0 )
        goto LABEL_5;
LABEL_8:
      *(_QWORD *)(v2 + 1064) = v4 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v2 + 1056);
      return v5;
    }
  }
  raw_spin_lock(comp_private_obj + 1056);
  v4 = *(_QWORD *)(v2 + 1064);
  v5 = *(unsigned __int8 *)(v2 + 1040);
  if ( (v4 & 1) != 0 )
    goto LABEL_8;
LABEL_5:
  raw_spin_unlock(v2 + 1056);
  return v5;
}
