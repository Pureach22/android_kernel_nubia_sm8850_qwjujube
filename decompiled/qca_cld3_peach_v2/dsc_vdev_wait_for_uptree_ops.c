__int64 __fastcall dsc_vdev_wait_for_uptree_ops(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x8
  __int64 v3; // x0

  if ( result )
  {
    v1 = result;
    _dsc_lock(*(_QWORD *)(*(_QWORD *)(result + 16) + 16LL));
    v2 = *(_QWORD *)(v1 + 16);
    if ( *(_DWORD *)(v2 + 80) )
    {
      qdf_event_reset(v2 + 88);
      _dsc_unlock(*(_QWORD *)(*(_QWORD *)(v1 + 16) + 16LL));
      qdf_wait_single_event(*(_QWORD *)(v1 + 16) + 88LL, 0);
    }
    else
    {
      _dsc_unlock(*(_QWORD *)(v2 + 16));
    }
    _dsc_lock(*(_QWORD *)(*(_QWORD *)(v1 + 16) + 16LL));
    v3 = *(_QWORD *)(*(_QWORD *)(v1 + 16) + 16LL);
    if ( *(_DWORD *)(v3 + 72) )
    {
      qdf_event_reset(v3 + 80);
      _dsc_unlock(*(_QWORD *)(*(_QWORD *)(v1 + 16) + 16LL));
      return qdf_wait_single_event(*(_QWORD *)(*(_QWORD *)(v1 + 16) + 16LL) + 80LL, 0);
    }
    else
    {
      return _dsc_unlock(v3);
    }
  }
  return result;
}
