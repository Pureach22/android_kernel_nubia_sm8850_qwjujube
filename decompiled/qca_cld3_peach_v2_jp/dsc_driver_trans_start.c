__int64 __fastcall dsc_driver_trans_start(_QWORD *a1, __int64 a2)
{
  unsigned int v2; // w20
  unsigned __int64 StatusReg; // x8
  __int64 v6; // x8
  _QWORD *v8; // x22
  _QWORD *v9; // x24

  v2 = 4;
  if ( a1 && a2 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1);
    }
    else
    {
      raw_spin_lock_bh(a1);
      a1[1] |= 1uLL;
    }
    if ( !_dsc_trans_active_or_queued(a1 + 5) )
    {
      v8 = (_QWORD *)a1[2];
      if ( v8 == a1 + 2 )
      {
LABEL_18:
        v2 = _dsc_trans_start(a1 + 5, a2);
        v6 = a1[1];
        if ( (v6 & 1) == 0 )
          goto LABEL_9;
        goto LABEL_19;
      }
      while ( !_dsc_trans_active(v8 + 6) )
      {
        v9 = v8 + 3;
        while ( 1 )
        {
          v9 = (_QWORD *)*v9;
          if ( v9 == v8 + 3 )
            break;
          if ( _dsc_trans_active(v9 + 3) )
            goto LABEL_8;
        }
        v8 = (_QWORD *)*v8;
        if ( v8 == a1 + 2 )
          goto LABEL_18;
      }
    }
LABEL_8:
    v2 = 3;
    v6 = a1[1];
    if ( (v6 & 1) == 0 )
    {
LABEL_9:
      raw_spin_unlock(a1);
      return v2;
    }
LABEL_19:
    a1[1] = v6 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1);
  }
  return v2;
}
