__int64 __fastcall dsc_driver_trans_start_wait(_QWORD *a1, __int64 a2)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned int v6; // w0
  __int64 v7; // x8
  unsigned int v8; // w20
  _QWORD *v9; // x22
  _QWORD *v10; // x24
  __int64 v11; // x8
  _QWORD v12[10]; // [xsp+0h] [xbp-50h] BYREF

  result = 4;
  v12[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v12, 0, 72);
  if ( !a1 || !a2 )
    goto LABEL_24;
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
    v9 = (_QWORD *)a1[2];
    if ( v9 == a1 + 2 )
    {
LABEL_19:
      v6 = _dsc_trans_start(a1 + 5, a2);
      if ( !v6 )
        goto LABEL_9;
    }
    else
    {
      while ( !_dsc_trans_active(v9 + 6) )
      {
        v10 = v9 + 3;
        while ( 1 )
        {
          v10 = (_QWORD *)*v10;
          if ( v10 == v9 + 3 )
            break;
          if ( _dsc_trans_active(v10 + 3) )
            goto LABEL_8;
        }
        v9 = (_QWORD *)*v9;
        if ( v9 == a1 + 2 )
          goto LABEL_19;
      }
    }
  }
LABEL_8:
  v6 = _dsc_trans_queue((__int64)(a1 + 5), (__int64)v12, a2);
  if ( v6 )
  {
LABEL_9:
    v7 = a1[1];
    v8 = v6;
    if ( (v7 & 1) != 0 )
    {
      a1[1] = v7 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1);
    }
    else
    {
      raw_spin_unlock(a1);
    }
    result = v8;
    goto LABEL_24;
  }
  v11 = a1[1];
  if ( (v11 & 1) != 0 )
  {
    a1[1] = v11 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1);
  }
  else
  {
    raw_spin_unlock(a1);
  }
  result = _dsc_tran_wait(v12);
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
