__int64 __fastcall dsc_driver_op_stop(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v4; // x1
  __int64 v5; // x8

  if ( result && a2 )
  {
    v2 = result;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(result);
    }
    else
    {
      raw_spin_lock_bh(result);
      *(_QWORD *)(v2 + 8) |= 1uLL;
    }
    if ( _dsc_ops_remove((int *)(v2 + 72)) )
      qdf_event_set_all(v2 + 80, v4);
    v5 = *(_QWORD *)(v2 + 8);
    if ( (v5 & 1) != 0 )
    {
      *(_QWORD *)(v2 + 8) = v5 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(v2);
    }
    else
    {
      return raw_spin_unlock(v2);
    }
  }
  return result;
}
