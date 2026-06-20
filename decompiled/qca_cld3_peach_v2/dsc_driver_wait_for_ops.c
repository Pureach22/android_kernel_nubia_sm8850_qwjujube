__int64 __fastcall dsc_driver_wait_for_ops(__int64 result)
{
  __int64 v1; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x8
  _QWORD *v4; // x19
  _QWORD *v5; // x20
  _QWORD *v6; // t1
  _QWORD *i; // x21
  _QWORD *v8; // x23
  __int64 v9; // x8
  _QWORD *v10; // t1
  _QWORD *v11; // t1

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
    if ( !_dsc_trans_active_or_queued((_QWORD *)(v1 + 40)) )
    {
      for ( i = *(_QWORD **)(v1 + 16); i != (_QWORD *)(v1 + 16); i = (_QWORD *)*i )
      {
        if ( _dsc_trans_active(i + 6) )
          break;
        v8 = i + 3;
        while ( 1 )
        {
          v8 = (_QWORD *)*v8;
          if ( v8 == i + 3 )
            break;
          if ( _dsc_trans_active(v8 + 3) )
            goto LABEL_7;
        }
      }
    }
LABEL_7:
    if ( *(_DWORD *)(v1 + 72) )
    {
      qdf_event_reset(v1 + 80);
      v3 = *(_QWORD *)(v1 + 8);
      if ( (v3 & 1) != 0 )
      {
        *(_QWORD *)(v1 + 8) = v3 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v1);
      }
      else
      {
        raw_spin_unlock(v1);
      }
      result = qdf_wait_single_event(v1 + 80, 0);
      v6 = *(_QWORD **)(v1 + 16);
      v4 = (_QWORD *)(v1 + 16);
      v5 = v6;
    }
    else
    {
      v9 = *(_QWORD *)(v1 + 8);
      if ( (v9 & 1) != 0 )
      {
        *(_QWORD *)(v1 + 8) = v9 & 0xFFFFFFFFFFFFFFFELL;
        result = raw_spin_unlock_bh(v1);
        v11 = *(_QWORD **)(v1 + 16);
        v4 = (_QWORD *)(v1 + 16);
        v5 = v11;
      }
      else
      {
        result = raw_spin_unlock(v1);
        v10 = *(_QWORD **)(v1 + 16);
        v4 = (_QWORD *)(v1 + 16);
        v5 = v10;
      }
    }
    while ( v5 != v4 )
    {
      result = dsc_psoc_wait_for_ops(v5);
      v5 = (_QWORD *)*v5;
    }
  }
  return result;
}
