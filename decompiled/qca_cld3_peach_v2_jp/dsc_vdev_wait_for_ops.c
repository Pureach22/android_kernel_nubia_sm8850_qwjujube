__int64 __fastcall dsc_vdev_wait_for_ops(__int64 result)
{
  __int64 v1; // x19

  if ( result )
  {
    v1 = result;
    _dsc_lock(*(_QWORD *)(*(_QWORD *)(result + 16) + 16LL));
    if ( *(_DWORD *)(v1 + 56) )
    {
      qdf_event_reset(v1 + 64);
      _dsc_unlock(*(_QWORD *)(*(_QWORD *)(v1 + 16) + 16LL));
      return qdf_wait_single_event(v1 + 64, 0);
    }
    else
    {
      return _dsc_unlock(*(_QWORD *)(*(_QWORD *)(v1 + 16) + 16LL));
    }
  }
  return result;
}
