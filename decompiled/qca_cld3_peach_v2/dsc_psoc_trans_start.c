__int64 __fastcall dsc_psoc_trans_start(__int64 *a1, __int64 a2)
{
  unsigned int v2; // w20
  __int64 *v5; // x22

  v2 = 4;
  if ( a1 && a2 )
  {
    _dsc_lock(a1[2]);
    if ( _dsc_trans_active_or_queued((_QWORD *)(a1[2] + 40)) )
    {
      v2 = 4;
    }
    else if ( _dsc_trans_active_or_queued(a1 + 6) )
    {
LABEL_9:
      v2 = 3;
    }
    else
    {
      v5 = a1 + 3;
      while ( 1 )
      {
        v5 = (__int64 *)*v5;
        if ( v5 == a1 + 3 )
          break;
        if ( _dsc_trans_active(v5 + 3) )
          goto LABEL_9;
      }
      v2 = _dsc_trans_start(a1 + 6, a2);
    }
    _dsc_unlock(a1[2]);
  }
  return v2;
}
