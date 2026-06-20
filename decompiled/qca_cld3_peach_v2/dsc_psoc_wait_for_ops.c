__int64 __fastcall dsc_psoc_wait_for_ops(__int64 result)
{
  __int64 v1; // x19
  _QWORD *v2; // x19
  _QWORD *v3; // x20
  _QWORD *v4; // t1
  _QWORD *v5; // t1

  if ( result )
  {
    v1 = result;
    _dsc_lock(*(_QWORD *)(result + 16));
    if ( *(_DWORD *)(v1 + 80) )
    {
      qdf_event_reset(v1 + 88);
      _dsc_unlock(*(_QWORD *)(v1 + 16));
      result = qdf_wait_single_event(v1 + 88, 0);
      v4 = *(_QWORD **)(v1 + 24);
      v2 = (_QWORD *)(v1 + 24);
      v3 = v4;
    }
    else
    {
      result = _dsc_unlock(*(_QWORD *)(v1 + 16));
      v5 = *(_QWORD **)(v1 + 24);
      v2 = (_QWORD *)(v1 + 24);
      v3 = v5;
    }
    while ( v3 != v2 )
    {
      result = dsc_vdev_wait_for_ops(v3);
      v3 = (_QWORD *)*v3;
    }
  }
  return result;
}
