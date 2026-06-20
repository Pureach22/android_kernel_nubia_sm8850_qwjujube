__int64 __fastcall mlme_wma_vdev_detach_post_cb(
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
  _BYTE v10[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v10[0] = *(_DWORD *)(a1 + 4);
    wma_vdev_detach_callback(v10);
    result = 0;
  }
  else
  {
    qdf_trace_msg(0x68u, 2u, "%s: Msg is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "mlme_wma_vdev_detach_post_cb");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
