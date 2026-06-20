__int64 __fastcall dsc_driver_op_start(__int64 a1, __int64 a2)
{
  unsigned int v2; // w20
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x8
  _QWORD *v7; // x22
  _QWORD *v8; // x24

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
      *(_QWORD *)(a1 + 8) |= 1uLL;
    }
    if ( !_dsc_trans_active_or_queued((_QWORD *)(a1 + 40)) )
    {
      v7 = *(_QWORD **)(a1 + 16);
      if ( v7 == (_QWORD *)(a1 + 16) )
      {
LABEL_18:
        v2 = _dsc_ops_insert((_DWORD *)(a1 + 72));
        v5 = *(_QWORD *)(a1 + 8);
        if ( (v5 & 1) == 0 )
          goto LABEL_9;
        goto LABEL_19;
      }
      while ( !_dsc_trans_active(v7 + 6) )
      {
        v8 = v7 + 3;
        while ( 1 )
        {
          v8 = (_QWORD *)*v8;
          if ( v8 == v7 + 3 )
            break;
          if ( _dsc_trans_active(v8 + 3) )
            goto LABEL_8;
        }
        v7 = (_QWORD *)*v7;
        if ( v7 == (_QWORD *)(a1 + 16) )
          goto LABEL_18;
      }
    }
LABEL_8:
    v2 = 3;
    v5 = *(_QWORD *)(a1 + 8);
    if ( (v5 & 1) == 0 )
    {
LABEL_9:
      raw_spin_unlock(a1);
      return v2;
    }
LABEL_19:
    *(_QWORD *)(a1 + 8) = v5 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1);
  }
  return v2;
}
