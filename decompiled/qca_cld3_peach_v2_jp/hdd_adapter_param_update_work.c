__int64 __fastcall hdd_adapter_param_update_work(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v34; // w8
  unsigned int v35; // w8
  _QWORD v36[2]; // [xsp+0h] [xbp-10h] BYREF

  v36[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = (__int64)_cds_get_context(51, (__int64)"hdd_adapter_param_update_work", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
  {
    v36[0] = 0;
    _X9 = (unsigned int *)(result + 6848);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v34 = __ldxr(_X9);
      v35 = v34 + 1;
    }
    while ( __stlxr(v35, _X9) );
    __dmb(0xBu);
    v19 = result + 16LL * (v35 & 3);
    *(_QWORD *)(v19 + 6864) = 0xFF00000001LL;
    __isb(0xFu);
    *(_QWORD *)(v19 + 6856) = _ReadStatusReg(CNTVCT_EL0);
    result = _hdd_validate_adapter(a1, (__int64)"hdd_adapter_param_update_work", v11, v12, v13, v14, v15, v16, v17, v18);
    if ( !(_DWORD)result )
    {
      result = _osif_vdev_sync_op_start(*(_QWORD *)(a1 + 32), v36, "hdd_adapter_param_update_work");
      if ( !(_DWORD)result )
      {
        if ( hdd_cm_is_vdev_associated(*(_DWORD **)(a1 + 52824)) )
          hdd_netdev_update_features(a1, v20, v21, v22, v23, v24, v25, v26, v27);
        result = _osif_vdev_sync_op_stop(v36[0], "hdd_adapter_param_update_work");
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
