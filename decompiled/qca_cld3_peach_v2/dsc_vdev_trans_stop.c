__int64 __fastcall dsc_vdev_trans_stop(__int64 result)
{
  __int64 v1; // x19

  if ( result )
  {
    v1 = result;
    _dsc_lock(*(_QWORD *)(*(_QWORD *)(result + 16) + 16LL));
    _dsc_trans_stop((_QWORD *)(v1 + 24));
    if ( !_dsc_driver_trans_trigger_checked(*(_QWORD *)(*(_QWORD *)(v1 + 16) + 16LL))
      && !_dsc_psoc_trans_trigger_checked(*(_QWORD **)(v1 + 16)) )
    {
      _dsc_trans_trigger(v1 + 24);
    }
    return _dsc_unlock(*(_QWORD *)(*(_QWORD *)(v1 + 16) + 16LL));
  }
  return result;
}
