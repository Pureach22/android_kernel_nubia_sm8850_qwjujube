__int64 __fastcall dsc_psoc_trans_stop(__int64 result)
{
  __int64 *v1; // x19
  bool v2; // w8
  _QWORD *v3; // x0
  __int64 *i; // x21

  if ( result )
  {
    v1 = (__int64 *)result;
    _dsc_lock(*(_QWORD *)(result + 16));
    v2 = _dsc_trans_active(v1 + 6);
    v3 = v1 + 6;
    if ( !v2 )
      v3 = (_QWORD *)(v1[2] + 40);
    _dsc_trans_stop(v3);
    if ( !_dsc_driver_trans_trigger_checked(v1[2]) && !_dsc_trans_trigger((__int64)(v1 + 6)) )
    {
      for ( i = (__int64 *)v1[3]; i != v1 + 3; i = (__int64 *)*i )
        _dsc_trans_trigger((__int64)(i + 3));
    }
    return _dsc_unlock(v1[2]);
  }
  return result;
}
