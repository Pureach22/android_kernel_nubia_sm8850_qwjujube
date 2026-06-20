__int64 __fastcall tdls_peer_idle_timers_destroy(
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
  __int64 v9; // x22
  __int64 v10; // x23
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _QWORD *v20; // x1
  __int64 v21; // x25
  _QWORD v22[2]; // [xsp+0h] [xbp-10h] BYREF

  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22[0] = 0;
  if ( a1 )
  {
    v9 = 0;
    v10 = a1 + 8;
    do
    {
      for ( result = qdf_list_peek_front((_QWORD *)(v10 + 24 * v9), v22);
            !(_DWORD)result;
            result = qdf_list_peek_next((_QWORD *)(v10 + 24 * v9), v20, v22) )
      {
        v20 = (_QWORD *)v22[0];
        if ( v22[0] && *(_BYTE *)(v22[0] + 672LL) == 1 )
        {
          v21 = v22[0];
          qdf_trace_msg(
            0,
            8u,
            "%s: %02x:%02x:%02x:**:**:%02x: destroy  idle timer ",
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            "tdls_peer_idle_timers_destroy",
            *(unsigned __int8 *)(v22[0] + 24LL),
            *(unsigned __int8 *)(v22[0] + 25LL),
            *(unsigned __int8 *)(v22[0] + 26LL),
            *(unsigned __int8 *)(v22[0] + 29LL));
          qdf_mc_timer_stop(v21 + 504);
          qdf_mc_timer_destroy(v21 + 504);
          v20 = (_QWORD *)v22[0];
        }
      }
      ++v9;
    }
    while ( v9 != 16 );
  }
  else
  {
    result = qdf_trace_msg(
               0,
               2u,
               "%s: NULL tdls vdev object",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "tdls_peer_idle_timers_destroy");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
