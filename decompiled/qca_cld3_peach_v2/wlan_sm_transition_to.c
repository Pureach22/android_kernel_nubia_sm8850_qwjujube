__int64 __fastcall wlan_sm_transition_to(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x21
  unsigned int v11; // w20
  __int64 result; // x0
  unsigned int v14; // w22
  const char *v15; // x6
  int v16; // w8
  unsigned int v17; // w10
  unsigned int v18; // w11
  unsigned int v19; // w8
  const char *v20; // x7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x20
  __int64 (__fastcall *v30)(_QWORD); // x8
  __int64 v31; // x0
  __int64 v32; // x20
  __int64 (__fastcall *v33)(_QWORD); // x8
  __int64 v34; // x0

  if ( !a1 )
    return qdf_trace_msg(0x67u, 2u, "%s: SM is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_sm_transition_to");
  v10 = *(_QWORD *)(a1 + 72);
  v11 = *(unsigned __int8 *)(a1 + 64);
  if ( *(_DWORD *)(a1 + 88) )
    return qdf_trace_msg(
             0x67u,
             1u,
             "%s: %s: can not call state transition from entry/exit routines",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "wlan_sm_transition_to",
             a1);
  v14 = a2;
  *(_DWORD *)(a1 + 88) = 1;
  if ( a2 > 0xC7u || *(unsigned __int8 *)(a1 + 65) <= (unsigned int)a2 )
    return qdf_trace_msg(
             0x67u,
             2u,
             "%s: %s: to state %d needs to be a valid state current_state=%d",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "wlan_sm_transition_to",
             a1,
             v11,
             a2);
  v15 = "IDLE";
  v16 = *(unsigned __int8 *)(v10 + 40LL * a2 + 1);
  v17 = *(unsigned __int8 *)(v10 + 40LL * v11 + 1);
  if ( v16 == 255 )
    v18 = a2;
  else
    v18 = *(unsigned __int8 *)(v10 + 40LL * a2 + 1);
  if ( v16 == 255 )
    v19 = 0;
  else
    v19 = a2;
  if ( v17 == 255 )
  {
    v17 = v11;
  }
  else if ( v11 )
  {
    v15 = *(const char **)(v10 + 40LL * v11 + 8);
  }
  if ( v19 )
    v20 = *(const char **)(v10 + 40LL * v19 + 8);
  else
    v20 = "IDLE";
  for ( result = qdf_trace_msg(
                   0x67u,
                   8u,
                   "%s: %s > %s, %s > %s",
                   a3,
                   a4,
                   a5,
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   a1,
                   *(_QWORD *)(v10 + 40LL * v17 + 8),
                   *(_QWORD *)(v10 + 40LL * v18 + 8),
                   v15,
                   v20); v11 != 255; v11 = *(unsigned __int8 *)(v29 + 1) )
  {
    v29 = v10 + 40LL * v11;
    v30 = *(__int64 (__fastcall **)(_QWORD))(v29 + 24);
    if ( v30 )
    {
      v31 = *(_QWORD *)(a1 + 80);
      if ( *((_DWORD *)v30 - 1) != 251140989 )
        __break(0x8228u);
      result = v30(v31);
    }
  }
  while ( 1 )
  {
    v32 = v10 + 40LL * v14;
    v33 = *(__int64 (__fastcall **)(_QWORD))(v32 + 16);
    if ( v33 )
    {
      v34 = *(_QWORD *)(a1 + 80);
      if ( *((_DWORD *)v33 - 1) != 251140989 )
        __break(0x8228u);
      result = v33(v34);
    }
    *(_BYTE *)(a1 + 64) = v14;
    v14 = *(unsigned __int8 *)(v32 + 2);
    if ( v14 == 255 )
      break;
    result = qdf_trace_msg(
               0x67u,
               8u,
               "%s: Initial sub state %s",
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               a1,
               *(_QWORD *)(v10 + 40LL * *(unsigned __int8 *)(v32 + 2) + 8));
  }
  *(_DWORD *)(a1 + 88) = 0;
  return result;
}
