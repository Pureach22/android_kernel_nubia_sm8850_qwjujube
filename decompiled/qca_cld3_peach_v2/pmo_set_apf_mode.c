__int64 __fastcall pmo_set_apf_mode(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 comp_private_obj; // x0
  __int64 v7; // x22
  unsigned __int64 StatusReg; // x8
  __int64 v9; // x8

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  if ( comp_private_obj )
  {
    v7 = comp_private_obj;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(comp_private_obj + 1040);
      v9 = *(_QWORD *)(v7 + 1048);
      *(_DWORD *)(v7 + 76) = a2;
      if ( (v9 & 1) == 0 )
      {
LABEL_6:
        raw_spin_unlock(v7 + 1040);
        return pmo_tgt_set_apf_mode_req(a1, a2, a3);
      }
    }
    else
    {
      raw_spin_lock_bh(comp_private_obj + 1040);
      v9 = *(_QWORD *)(v7 + 1048) | 1LL;
      *(_QWORD *)(v7 + 1048) = v9;
      *(_DWORD *)(v7 + 76) = a2;
      if ( (v9 & 1) == 0 )
        goto LABEL_6;
    }
    *(_QWORD *)(v7 + 1048) = v9 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v7 + 1040);
  }
  return pmo_tgt_set_apf_mode_req(a1, a2, a3);
}
