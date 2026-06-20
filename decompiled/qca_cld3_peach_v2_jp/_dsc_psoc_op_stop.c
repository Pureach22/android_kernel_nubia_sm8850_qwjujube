__int64 __fastcall dsc_psoc_op_stop(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x1

  if ( result && a2 )
  {
    v2 = result;
    _dsc_lock(*(_QWORD *)(result + 16));
    if ( _dsc_ops_remove((int *)(v2 + 80)) )
      qdf_event_set_all(v2 + 88, v3);
    return _dsc_unlock(*(_QWORD *)(v2 + 16));
  }
  return result;
}
