__int64 __fastcall ucfg_pmo_get_wow_bus_suspend(__int64 a1)
{
  __int64 comp_private_obj; // x0
  __int64 v2; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v4; // x8
  unsigned int v5; // w20

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  if ( !comp_private_obj )
    return 0;
  v2 = comp_private_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(comp_private_obj + 1040);
      v4 = *(_QWORD *)(v2 + 1048) | 1LL;
      *(_QWORD *)(v2 + 1048) = v4;
      v5 = *(unsigned __int8 *)(v2 + 490);
      if ( (v4 & 1) == 0 )
        goto LABEL_6;
LABEL_10:
      *(_QWORD *)(v2 + 1048) = v4 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v2 + 1040);
      return v5;
    }
  }
  raw_spin_lock(comp_private_obj + 1040);
  v4 = *(_QWORD *)(v2 + 1048);
  v5 = *(unsigned __int8 *)(v2 + 490);
  if ( (v4 & 1) != 0 )
    goto LABEL_10;
LABEL_6:
  raw_spin_unlock(v2 + 1040);
  return v5;
}
