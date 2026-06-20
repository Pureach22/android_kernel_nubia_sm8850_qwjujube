__int64 __fastcall wlan_vdev_mlme_ser_pdev_csa_restart(
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
  __int64 v11; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  __int64 v21; // [xsp+0h] [xbp-10h] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  BYTE4(v21) = 0;
  LOBYTE(v21) = 0;
  if ( a1 && (v10 = *(_QWORD *)(a1 + 32)) != 0 )
  {
    if ( (wlan_ser_is_vdev_queue_enabled(v10) & 1) != 0 )
    {
      v11 = *(_QWORD *)(*(_QWORD *)(a1 + 32) + 152LL);
      wlan_objmgr_pdev_iterate_obj_list(
        v11,
        2,
        (void (__fastcall *)(__int64, __int64, __int64))wlan_mlme_cancel_pending_csa_restart,
        (__int64)&v21 + 4,
        0,
        0x2Eu);
      wlan_objmgr_pdev_iterate_obj_list(
        v11,
        2,
        (void (__fastcall *)(__int64, __int64, __int64))wlan_mlme_check_pdev_restart,
        (__int64)&v21,
        0,
        0x2Eu);
      if ( (v21 & 1) != 0 )
      {
        result = 6;
      }
      else
      {
        LODWORD(result) = wlan_serialization_request((unsigned int *)a1, v12, v13, v14, v15, v16, v17, v18, v19);
        if ( (BYTE4(v21) & ((_DWORD)result == 0)) != 0 )
          result = 5;
        else
          result = (unsigned int)result;
      }
    }
    else
    {
      result = 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Null input",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_vdev_mlme_ser_pdev_csa_restart",
      v21,
      v22);
    result = 6;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
