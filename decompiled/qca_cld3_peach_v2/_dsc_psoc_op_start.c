__int64 __fastcall dsc_psoc_op_start(__int64 a1, __int64 a2)
{
  unsigned int v2; // w20
  _QWORD *v4; // x22

  v2 = 4;
  if ( a1 && a2 )
  {
    _dsc_lock(*(_QWORD *)(a1 + 16));
    if ( _dsc_trans_active_or_queued((_QWORD *)(*(_QWORD *)(a1 + 16) + 40LL)) )
    {
      v2 = 4;
    }
    else if ( _dsc_trans_active_or_queued((_QWORD *)(a1 + 48)) )
    {
LABEL_9:
      v2 = 3;
    }
    else
    {
      v4 = (_QWORD *)(a1 + 24);
      while ( 1 )
      {
        v4 = (_QWORD *)*v4;
        if ( v4 == (_QWORD *)(a1 + 24) )
          break;
        if ( _dsc_trans_active(v4 + 3) )
          goto LABEL_9;
      }
      v2 = _dsc_ops_insert((_DWORD *)(a1 + 80));
    }
    _dsc_unlock(*(_QWORD *)(a1 + 16));
  }
  return v2;
}
