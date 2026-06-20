__int64 __fastcall ucfg_pmo_psoc_update_dp_handle(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v6; // x8

  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  if ( result )
  {
    v4 = result;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(result + 1040);
      v6 = *(_QWORD *)(v4 + 1048);
      *(_QWORD *)(v4 + 960) = a2;
      if ( (v6 & 1) == 0 )
        return raw_spin_unlock(v4 + 1040);
    }
    else
    {
      raw_spin_lock_bh(result + 1040);
      v6 = *(_QWORD *)(v4 + 1048) | 1LL;
      *(_QWORD *)(v4 + 1048) = v6;
      *(_QWORD *)(v4 + 960) = a2;
      if ( (v6 & 1) == 0 )
        return raw_spin_unlock(v4 + 1040);
    }
    *(_QWORD *)(v4 + 1048) = v6 & 0xFFFFFFFFFFFFFFFELL;
    return raw_spin_unlock_bh(v4 + 1040);
  }
  return result;
}
