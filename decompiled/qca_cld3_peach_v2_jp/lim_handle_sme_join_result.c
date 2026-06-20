__int64 __fastcall lim_handle_sme_join_result(
        __int64 a1,
        int a2,
        unsigned int a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int16 v13; // w8
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x0
  unsigned int v24; // w1
  __int64 result; // x0
  __int64 v28; // [xsp+0h] [xbp-10h] BYREF
  __int64 v29; // [xsp+8h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = 0;
  if ( a4 )
  {
    if ( a2 )
    {
      v13 = *(_WORD *)(a4 + 8);
      v14 = *(_QWORD *)(a4 + 16);
      HIDWORD(v28) = a2;
      LOWORD(v28) = a3;
      WORD1(v28) = v13;
      mlme_set_connection_fail(v14, 1, a5, a6, a7, a8, a9, a10, a11, a12);
      v23 = *(_QWORD *)(a4 + 16);
      if ( *(_DWORD *)(v23 + 24) == 7 )
      {
        mlme_set_vdev_start_failed(v23, 1, v15, v16, v17, v18, v19, v20, v21, v22);
        v23 = *(_QWORD *)(a4 + 16);
        v24 = 5;
      }
      else
      {
        v24 = 13;
      }
      result = wlan_vdev_mlme_sm_deliver_evt(v23, v24, 8u, (__int64)&v28, v15, v16, v17, v18, v19, v20, v21, v22);
    }
    else
    {
      wlan_vdev_mlme_sm_deliver_evt(*(_QWORD *)(a4 + 16), 7u, 0, 0, a5, a6, a7, a8, a9, a10, a11, a12);
      result = lim_send_sme_join_reassoc_rsp(a1, 0, 0, a3, a4, *(unsigned __int8 *)(a4 + 10));
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: session is NULL",
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               a12,
               "lim_handle_sme_join_result",
               v28,
               v29);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
