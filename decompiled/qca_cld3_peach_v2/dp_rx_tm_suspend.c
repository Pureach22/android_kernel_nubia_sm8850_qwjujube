__int64 __fastcall dp_rx_tm_suspend(
        unsigned __int8 *a1,
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
  unsigned int v10; // w8
  unsigned __int64 i; // x20
  __int64 v13; // x9
  __int64 v14; // x8
  __int64 v15; // x20
  unsigned __int8 *v16; // x24
  unsigned int v17; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x4
  int v27; // w8
  const char *v28; // x5
  unsigned int v29; // w23
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w8
  unsigned __int64 v39; // x20
  __int64 v40; // x8
  __int64 v41; // x1

  if ( *((_DWORD *)a1 + 4) == 3 )
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: already in suspend state! Ignoring.",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "dp_rx_tm_suspend");
    return 4;
  }
  v10 = *a1;
  *((_DWORD *)a1 + 4) = 2;
  if ( !v10 )
    goto LABEL_14;
  for ( i = 0; i < v10; ++i )
  {
    v13 = *(_QWORD *)(*((_QWORD *)a1 + 3) + 8 * i);
    if ( v13 )
    {
      qdf_event_reset(v13 + 96);
      qdf_event_reset(*(_QWORD *)(*((_QWORD *)a1 + 3) + 8 * i) + 56LL);
      v14 = *(_QWORD *)(*((_QWORD *)a1 + 3) + 8 * i);
      *(_QWORD *)(v14 + 424) |= 4uLL;
      _wake_up(*(_QWORD *)(*((_QWORD *)a1 + 3) + 8 * i) + 1136LL, 1, 1, 0);
      v10 = *a1;
    }
  }
  if ( !v10 )
  {
LABEL_14:
    result = 0;
    v27 = 3;
    goto LABEL_15;
  }
  v15 = 0;
  while ( 1 )
  {
    v16 = *(unsigned __int8 **)(*((_QWORD *)a1 + 3) + 8 * v15);
    if ( v16 )
      break;
LABEL_10:
    if ( ++v15 >= (unsigned __int64)v10 )
      goto LABEL_14;
  }
  qdf_trace_msg(0x45u, 8u, "%s: thread %d", a2, a3, a4, a5, a6, a7, a8, a9, "dp_rx_tm_suspend", (unsigned int)v15);
  v17 = qdf_wait_single_event((__int64)(v16 + 56), 0x7D0u);
  v26 = *v16;
  if ( !v17 )
  {
    qdf_trace_msg(0x45u, 8u, "%s: thread:%d suspended", v18, v19, v20, v21, v22, v23, v24, v25, "dp_rx_tm_suspend", v26);
    v10 = *a1;
    goto LABEL_10;
  }
  if ( v17 == 15 )
    v28 = "timeout out";
  else
    v28 = "failed";
  v29 = v17;
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: thread:%d %s(%d) while waiting for suspend",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "dp_rx_tm_suspend",
    v26,
    v28);
  if ( (*((_DWORD *)a1 + 4) & 0xFFFFFFFE) == 2 )
  {
    v38 = *a1;
    result = v29;
    if ( *a1 )
    {
      v39 = 0;
      do
      {
        if ( *(_QWORD *)(*((_QWORD *)a1 + 3) + 8 * v39) )
        {
          qdf_trace_msg(
            0x45u,
            8u,
            "%s: calling thread %d to resume",
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            "dp_rx_tm_resume",
            (unsigned int)v39);
          v40 = *(_QWORD *)(*((_QWORD *)a1 + 3) + 8 * v39);
          *(_QWORD *)(v40 + 424) &= ~4uLL;
          qdf_event_set(*(_QWORD *)(*((_QWORD *)a1 + 3) + 8 * v39) + 96LL, v41);
          v38 = *a1;
          result = v29;
        }
        ++v39;
      }
      while ( v39 < v38 );
    }
    v27 = 1;
LABEL_15:
    *((_DWORD *)a1 + 4) = v27;
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: resume callback received w/o suspend! Ignoring.",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "dp_rx_tm_resume");
    return v29;
  }
  return result;
}
