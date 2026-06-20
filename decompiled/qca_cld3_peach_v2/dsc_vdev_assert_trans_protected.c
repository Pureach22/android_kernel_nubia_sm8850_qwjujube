__int64 __fastcall dsc_vdev_assert_trans_protected(__int64 result)
{
  __int64 v1; // x19

  if ( result )
  {
    v1 = result;
    _dsc_lock(*(_QWORD *)(*(_QWORD *)(result + 16) + 16LL));
    if ( !_dsc_trans_active((_QWORD *)(v1 + 24)) && !_dsc_trans_active((_QWORD *)(*(_QWORD *)(v1 + 16) + 48LL)) )
      _dsc_trans_active((_QWORD *)(*(_QWORD *)(*(_QWORD *)(v1 + 16) + 16LL) + 40LL));
    return _dsc_unlock(*(_QWORD *)(*(_QWORD *)(v1 + 16) + 16LL));
  }
  return result;
}
