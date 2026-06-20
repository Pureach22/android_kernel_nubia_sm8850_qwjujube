__int64 __fastcall wlan_sm_dispatch(
        __int64 a1,
        unsigned int a2,
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
  unsigned int v12; // w22
  __int64 v13; // x8
  unsigned int v14; // w20
  int v17; // w9
  unsigned int v18; // w10
  unsigned int v19; // w9
  __int64 v21; // x11
  const char *v22; // x11
  unsigned int v23; // w23
  __int64 v24; // x24
  const char *v25; // x5
  const char *v26; // x6
  __int64 v27; // x0
  _DWORD *v28; // x8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7

  if ( !a1 )
  {
    qdf_trace_msg(0x67u, 2u, "%s: SM is NULL", a5, a6, a7, a8, a9, a10, a11, a12, "wlan_sm_dispatch");
    return 16;
  }
  v12 = *(unsigned __int8 *)(a1 + 64);
  v13 = *(_QWORD *)(a1 + 72);
  v14 = (unsigned __int16)a2;
  v17 = *(unsigned __int8 *)(v13 + 40LL * *(unsigned __int8 *)(a1 + 64) + 1);
  if ( v17 == 255 )
    v18 = *(unsigned __int8 *)(a1 + 64);
  else
    v18 = *(unsigned __int8 *)(v13 + 40LL * *(unsigned __int8 *)(a1 + 64) + 1);
  if ( v17 == 255 )
    v19 = 0;
  else
    v19 = *(unsigned __int8 *)(a1 + 64);
  if ( (unsigned __int16)a2 == 255 )
  {
    qdf_trace_msg(0x67u, 2u, "%s: %s: invalid event %d", a5, a6, a7, a8, a9, a10, a11, a12, "wlan_sm_dispatch", a1, 255);
    return 16;
  }
  v21 = *(_QWORD *)(a1 + 96);
  *(_BYTE *)(a1 + 66) = a2;
  if ( v21 )
  {
    if ( *(_DWORD *)(a1 + 104) <= (unsigned int)(unsigned __int16)a2 )
      v22 = nullptr;
    else
      v22 = *(const char **)(v21 + 8LL * (unsigned __int16)a2);
    v23 = a3;
    v24 = a4;
    if ( v19 )
      v25 = *(const char **)(v13 + 40LL * v19 + 8);
    else
      v25 = "IDLE";
    if ( v22 )
      v26 = v22;
    else
      v26 = "UNKNOWN_EVENT";
    qdf_trace_msg(
      0x67u,
      8u,
      "%s: %s-%s, %s",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a1,
      *(_QWORD *)(v13 + 40LL * v18 + 8),
      v25,
      v26);
    if ( v12 == 255 )
      return 0;
  }
  else
  {
    v23 = a3;
    v24 = a4;
    qdf_trace_msg(
      0x67u,
      8u,
      "%s: %s ev [%d]",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a1,
      *(_QWORD *)(v13 + 40LL * v12 + 8),
      (unsigned __int16)a2);
    if ( v12 == 255 )
      return 0;
  }
  v27 = *(_QWORD *)(a1 + 80);
  v28 = *(_DWORD **)(*(_QWORD *)(a1 + 72) + 40LL * v12 + 32);
  if ( *(v28 - 1) != -1873402603 )
    __break(0x8228u);
  if ( (((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, __int64))v28)(v27, a2, v23, v24) & 1) != 0 )
    return 0;
  qdf_trace_msg(
    0x67u,
    4u,
    "%s: event %d not handled in state %s",
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    a1,
    v14,
    *(_QWORD *)(*(_QWORD *)(a1 + 72) + 40LL * *(unsigned __int8 *)(a1 + 64) + 8));
  return 4;
}
