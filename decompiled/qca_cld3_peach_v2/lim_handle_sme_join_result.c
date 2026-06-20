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
  double updated; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x9
  _QWORD *v37; // x10
  __int64 v38; // x8
  __int64 v39; // x11
  __int64 v40; // x10
  __int64 v41; // [xsp+0h] [xbp-10h] BYREF
  __int64 v42; // [xsp+8h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v41 = 0;
  if ( a4 )
  {
    if ( a2 )
    {
      v13 = *(_WORD *)(a4 + 8);
      v14 = *(_QWORD *)(a4 + 16);
      HIDWORD(v41) = a2;
      LOWORD(v41) = a3;
      WORD1(v41) = v13;
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
      result = wlan_vdev_mlme_sm_deliver_evt(v23, v24, 8u, (__int64)&v41, v15, v16, v17, v18, v19, v20, v21, v22);
    }
    else
    {
      if ( (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(a4 + 16), a5, a6, a7, a8, a9, a10, a11, a12) & 1) != 0 )
      {
        v36 = *(_QWORD *)(a4 + 16);
        v37 = *(_QWORD **)(v36 + 1360);
        if ( v37 )
        {
          v38 = v37[278];
          if ( v38 )
          {
            v39 = v37[3];
            if ( v39 && v39 == v36 )
              *(_QWORD *)(v38 + 8) |= 1uLL;
            v40 = v37[4];
            if ( v40 && v40 == v36 )
              *(_QWORD *)(v38 + 8) |= 2uLL;
          }
        }
        updated = mlo_update_connected_links_bmap(*(_QWORD *)(*(_QWORD *)(a4 + 16) + 1360LL), a4 + 10696);
      }
      wlan_vdev_mlme_sm_deliver_evt(*(_QWORD *)(a4 + 16), 7u, 0, 0, updated, v29, v30, v31, v32, v33, v34, v35);
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
               v41,
               v42);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
