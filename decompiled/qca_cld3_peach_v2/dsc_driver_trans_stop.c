__int64 __fastcall dsc_driver_trans_stop(__int64 result)
{
  _QWORD *v1; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x8
  _QWORD *i; // x21
  _QWORD *j; // x23

  if ( result )
  {
    v1 = (_QWORD *)result;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(result);
    }
    else
    {
      raw_spin_lock_bh(result);
      v1[1] |= 1uLL;
    }
    _dsc_trans_stop(v1 + 5);
    if ( !_dsc_trans_trigger((__int64)(v1 + 5)) )
    {
      for ( i = (_QWORD *)v1[2]; i != v1 + 2; i = (_QWORD *)*i )
      {
        if ( !_dsc_trans_trigger((__int64)(i + 6)) )
        {
          for ( j = (_QWORD *)i[3]; j != i + 3; j = (_QWORD *)*j )
            _dsc_trans_trigger((__int64)(j + 3));
        }
      }
    }
    v3 = v1[1];
    if ( (v3 & 1) != 0 )
    {
      v1[1] = v3 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(v1);
    }
    else
    {
      return raw_spin_unlock(v1);
    }
  }
  return result;
}
