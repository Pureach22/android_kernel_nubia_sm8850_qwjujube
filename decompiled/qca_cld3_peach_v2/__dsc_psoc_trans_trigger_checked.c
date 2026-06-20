bool __fastcall _dsc_psoc_trans_trigger_checked(_QWORD *a1)
{
  _QWORD *v3; // x21

  if ( qdf_list_empty(a1 + 7) )
  {
    return 0;
  }
  else if ( _dsc_trans_active_or_queued((_QWORD *)(a1[2] + 40LL)) || _dsc_trans_active(a1 + 6) )
  {
    return 1;
  }
  else
  {
    v3 = a1 + 3;
    while ( 1 )
    {
      v3 = (_QWORD *)*v3;
      if ( v3 == a1 + 3 )
        break;
      if ( _dsc_trans_active(v3 + 3) )
        return 1;
    }
    return _dsc_trans_trigger((__int64)(a1 + 6));
  }
}
