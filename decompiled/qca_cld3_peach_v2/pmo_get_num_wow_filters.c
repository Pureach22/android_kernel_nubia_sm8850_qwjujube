__int64 __fastcall pmo_get_num_wow_filters(__int64 a1)
{
  __int64 comp_private_obj; // x0
  __int64 v2; // x19
  unsigned __int64 StatusReg; // x8
  unsigned __int8 v4; // w20
  unsigned __int8 v6; // w21
  __int64 v7; // x8

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  if ( !comp_private_obj )
    return 32;
  v2 = comp_private_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(comp_private_obj + 1040);
  }
  else
  {
    raw_spin_lock_bh(comp_private_obj + 1040);
    *(_QWORD *)(v2 + 1048) |= 1uLL;
  }
  if ( *(_BYTE *)(v2 + 1) == 1 )
    v4 = *(_BYTE *)(v2 + 952);
  else
    v4 = 0;
  if ( *(_BYTE *)(v2 + 10) == 1 )
    v6 = *(_BYTE *)(v2 + 954);
  else
    v6 = 0;
  v7 = *(_QWORD *)(v2 + 1048);
  if ( (v7 & 1) != 0 )
  {
    *(_QWORD *)(v2 + 1048) = v7 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v2 + 1040);
  }
  else
  {
    raw_spin_unlock(v2 + 1040);
  }
  if ( ((v4 | v6) & 1) != 0 )
    return 12;
  else
    return 32;
}
