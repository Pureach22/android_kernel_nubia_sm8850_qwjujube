__int64 __fastcall dsc_driver_assert_trans_protected(__int64 result)
{
  __int64 v1; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x8

  if ( result )
  {
    v1 = result;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(result);
    }
    else
    {
      raw_spin_lock_bh(result);
      *(_QWORD *)(v1 + 8) |= 1uLL;
    }
    _dsc_trans_active((_QWORD *)(v1 + 40));
    v3 = *(_QWORD *)(v1 + 8);
    if ( (v3 & 1) != 0 )
    {
      *(_QWORD *)(v1 + 8) = v3 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(v1);
    }
    else
    {
      return raw_spin_unlock(v1);
    }
  }
  return result;
}
