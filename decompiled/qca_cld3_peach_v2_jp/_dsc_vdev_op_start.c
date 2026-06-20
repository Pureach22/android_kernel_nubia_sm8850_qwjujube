__int64 __fastcall dsc_vdev_op_start(__int64 a1, __int64 a2)
{
  unsigned int v2; // w20

  v2 = 4;
  if ( a1 && a2 )
  {
    _dsc_lock(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 16LL));
    if ( _dsc_trans_active_or_queued((_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 16LL) + 40LL))
      || (qdf_is_recovering() & 1) != 0 )
    {
      v2 = 4;
    }
    else if ( _dsc_trans_active_or_queued((_QWORD *)(*(_QWORD *)(a1 + 16) + 48LL)) )
    {
      if ( (qdf_is_driver_unloading() & 1) != 0 )
        v2 = 4;
      else
        v2 = 8;
    }
    else if ( _dsc_trans_active_or_queued((_QWORD *)(a1 + 24)) )
    {
      v2 = 8;
    }
    else
    {
      v2 = _dsc_ops_insert((_DWORD *)(a1 + 56));
    }
    _dsc_unlock(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 16LL));
  }
  return v2;
}
