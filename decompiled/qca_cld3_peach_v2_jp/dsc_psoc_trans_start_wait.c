__int64 __fastcall dsc_psoc_trans_start_wait(__int64 *a1, __int64 a2)
{
  __int64 result; // x0
  int v5; // w0
  __int64 *v6; // x22
  __int64 v7; // x8
  unsigned int v8; // w19
  _QWORD v9[10]; // [xsp+0h] [xbp-50h] BYREF

  result = 4;
  v9[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v9, 0, 72);
  if ( a1 && a2 )
  {
    _dsc_lock(a1[2]);
    if ( _dsc_trans_active_or_queued((_QWORD *)(a1[2] + 40)) )
    {
      v5 = 4;
    }
    else
    {
      if ( _dsc_trans_active_or_queued(a1 + 6) )
        goto LABEL_11;
      v6 = a1 + 3;
      while ( 1 )
      {
        v6 = (__int64 *)*v6;
        if ( v6 == a1 + 3 )
          break;
        if ( _dsc_trans_active(v6 + 3) )
          goto LABEL_11;
      }
      v5 = _dsc_trans_start(a1 + 6, a2);
      if ( (v5 & 0xFFFFFFFB) != 0 )
      {
LABEL_11:
        v5 = _dsc_trans_queue((__int64)(a1 + 6), (__int64)v9, a2);
        if ( !v5 )
        {
          _dsc_unlock(a1[2]);
          result = _dsc_tran_wait(v9);
          goto LABEL_13;
        }
      }
    }
    v7 = a1[2];
    v8 = v5;
    _dsc_unlock(v7);
    result = v8;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
