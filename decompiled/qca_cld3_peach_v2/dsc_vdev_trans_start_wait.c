__int64 __fastcall dsc_vdev_trans_start_wait(__int64 a1, __int64 a2)
{
  unsigned int v2; // w21
  _QWORD v6[10]; // [xsp+0h] [xbp-50h] BYREF

  v2 = 4;
  v6[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v6, 0, 72);
  if ( a1 && a2 )
  {
    _dsc_lock(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 16LL));
    if ( !_dsc_trans_active_or_queued((_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 16LL) + 40LL))
      && (qdf_is_recovering() & 1) == 0 )
    {
      if ( _dsc_trans_active_or_queued((_QWORD *)(*(_QWORD *)(a1 + 16) + 48LL)) )
      {
        if ( (qdf_is_driver_unloading() & 1) != 0 )
          v2 = 4;
        else
          v2 = 8;
        if ( (v2 & 0xFFFFFFFB) == 0 )
          goto LABEL_14;
LABEL_13:
        v2 = _dsc_trans_queue(a1 + 24, (__int64)v6, a2);
        if ( !v2 )
        {
          _dsc_unlock(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 16LL));
          v2 = _dsc_tran_wait(v6);
          goto LABEL_15;
        }
        goto LABEL_14;
      }
      if ( _dsc_trans_active_or_queued((_QWORD *)(a1 + 24)) )
        goto LABEL_13;
      v2 = _dsc_trans_start((_QWORD *)(a1 + 24), a2);
      if ( (v2 & 0xFFFFFFFB) != 0 )
        goto LABEL_13;
    }
LABEL_14:
    _dsc_unlock(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 16LL));
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return v2;
}
