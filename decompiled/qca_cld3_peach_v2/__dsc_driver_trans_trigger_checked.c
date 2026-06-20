bool __fastcall _dsc_driver_trans_trigger_checked(__int64 a1)
{
  _QWORD *v4; // x21
  _QWORD *v5; // x23

  if ( _dsc_trans_queued(a1 + 40) )
  {
    if ( !_dsc_trans_active((_QWORD *)(a1 + 40)) )
    {
      v4 = *(_QWORD **)(a1 + 16);
      if ( v4 == (_QWORD *)(a1 + 16) )
        return _dsc_trans_trigger(a1 + 40);
      while ( !_dsc_trans_active(v4 + 6) )
      {
        v5 = v4 + 3;
        while ( 1 )
        {
          v5 = (_QWORD *)*v5;
          if ( v5 == v4 + 3 )
            break;
          if ( _dsc_trans_active(v5 + 3) )
            return 1;
        }
        v4 = (_QWORD *)*v4;
        if ( v4 == (_QWORD *)(a1 + 16) )
          return _dsc_trans_trigger(a1 + 40);
      }
    }
    return 1;
  }
  else
  {
    return 0;
  }
}
