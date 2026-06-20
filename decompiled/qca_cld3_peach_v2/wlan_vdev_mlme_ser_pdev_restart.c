__int64 __fastcall wlan_vdev_mlme_ser_pdev_restart(
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
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  _BYTE v20[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20[0] = 0;
  if ( a1 && (v10 = *(_QWORD *)(a1 + 32)) != 0 )
  {
    if ( (wlan_ser_is_vdev_queue_enabled(v10) & 1) != 0 )
    {
      wlan_objmgr_pdev_iterate_obj_list(
        *(_QWORD *)(*(_QWORD *)(a1 + 32) + 216LL),
        2,
        (void (__fastcall *)(__int64, __int64, __int64))wlan_mlme_restart_pdev_iter_cb,
        (__int64)v20,
        0,
        0x2Eu);
      if ( v20[0] )
        result = 5;
      else
        result = wlan_serialization_request((unsigned int *)a1, v11, v12, v13, v14, v15, v16, v17, v18);
    }
    else
    {
      result = 4;
    }
  }
  else
  {
    qdf_trace_msg(0x68u, 2u, "%s: Null input", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_vdev_mlme_ser_pdev_restart");
    result = 6;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
