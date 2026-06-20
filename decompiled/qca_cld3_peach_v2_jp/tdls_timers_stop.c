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
  __int64 v10; // x20
  __int64 v11; // x21
  __int64 result; // x0
  _QWORD *v13; // x1
  _QWORD v14[2]; // [xsp+0h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0, 8u, "%s: Stop TDLS timers", a2, a3, a4, a5, a6, a7, a8, a9, "tdls_timers_stop");
  qdf_mc_timer_stop_sync(a1 + 560);
  qdf_mc_timer_stop_sync(a1 + 392);
  v10 = 0;
  v11 = a1 + 8;
  v14[0] = 0;
  *(_DWORD *)(a1 + 764) = 0;
  do
  {
    for ( result = qdf_list_peek_front((_QWORD *)(v11 + 24 * v10), v14);
          !(_DWORD)result;
          result = qdf_list_peek_next((_QWORD *)(v11 + 24 * v10), v13, v14) )
    {
      v13 = (_QWORD *)v14[0];
      if ( *(_BYTE *)(v14[0] + 672LL) == 1 )
      {
        qdf_mc_timer_stop_sync(v14[0] + 504LL);
        v13 = (_QWORD *)v14[0];
      }
    }
    ++v10;
  }
  while ( v10 != 16 );
  _ReadStatusReg(SP_EL0);
  return result;
}
