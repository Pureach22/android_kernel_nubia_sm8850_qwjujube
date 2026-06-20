__int64 __fastcall osif_twt_work_handler(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *v9; // x8
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 *v21; // [xsp+0h] [xbp-10h] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = nullptr;
  if ( result )
  {
    v9 = *(__int64 **)(result + 608);
    if ( v9 )
    {
      v10 = *v9;
      if ( v10 )
      {
        v11 = *(_QWORD *)(v10 + 32);
        if ( v11 )
        {
          v12 = result;
          result = _osif_vdev_sync_op_start(v11, &v21, (__int64)"osif_twt_work_handler");
          if ( !(_DWORD)result )
          {
            _osif_twt_work_handler(v12, v13, v14, v15, v16, v17, v18, v19, v20);
            result = _osif_vdev_sync_op_stop((__int64)v21, (__int64)"osif_twt_work_handler");
          }
        }
      }
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x48u,
               2u,
               "%s: vdev is null",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "osif_twt_work_handler",
               v21,
               v22);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
