__int64 __fastcall dsc_psoc_assert_trans_protected(__int64 result)
{
  __int64 v1; // x19

  if ( result )
  {
    v1 = result;
    _dsc_lock(*(_QWORD *)(result + 16));
    if ( !_dsc_trans_active((_QWORD *)(v1 + 48)) )
      _dsc_trans_active((_QWORD *)(*(_QWORD *)(v1 + 16) + 40LL));
    return _dsc_unlock(*(_QWORD *)(v1 + 16));
  }
  return result;
}
