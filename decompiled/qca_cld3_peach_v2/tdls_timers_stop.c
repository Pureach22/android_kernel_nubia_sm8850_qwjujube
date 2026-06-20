__int64 __fastcall tdls_timers_stop(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x20
  __int64 v19; // x21
  __int64 result; // x0
  _QWORD *v21; // x1
  _QWORD v22[2]; // [xsp+0h] [xbp-10h] BYREF

  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0, 8u, "%s: Stop TDLS timers", a2, a3, a4, a5, a6, a7, a8, a9, "tdls_timers_stop");
  if ( (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)a1, v10, v11, v12, v13, v14, v15, v16, v17) & 1) == 0 )
    qdf_mc_timer_stop_sync(a1 + 560);
  qdf_mc_timer_stop_sync(a1 + 392);
  v18 = 0;
  v19 = a1 + 8;
  v22[0] = 0;
  *(_DWORD *)(a1 + 764) = 0;
  do
  {
    for ( result = qdf_list_peek_front((_QWORD *)(v19 + 24 * v18), v22);
          !(_DWORD)result;
          result = qdf_list_peek_next((_QWORD *)(v19 + 24 * v18), v21, v22) )
    {
      v21 = (_QWORD *)v22[0];
      if ( *(_BYTE *)(v22[0] + 672LL) == 1 )
      {
        qdf_mc_timer_stop_sync(v22[0] + 504LL);
        v21 = (_QWORD *)v22[0];
      }
    }
    ++v18;
  }
  while ( v18 != 16 );
  _ReadStatusReg(SP_EL0);
  return result;
}
