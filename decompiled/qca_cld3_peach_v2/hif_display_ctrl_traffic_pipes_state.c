__int64 __fastcall hif_display_ctrl_traffic_pipes_state(
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
  __int64 v10; // x8
  unsigned int *v11; // x9
  unsigned int v12; // w8
  int v13; // w10
  unsigned int v14; // w9
  __int64 v15; // x4
  __int64 v16; // x5
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x8
  unsigned int *v26; // x9
  unsigned int v27; // w8
  int v28; // w10
  unsigned int v29; // w9
  __int64 v30; // x4
  __int64 v31; // x5

  v10 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 496) + 152LL) + 80LL);
  v11 = *(unsigned int **)(v10 + 128);
  v13 = *(_DWORD *)(v10 + 116);
  v12 = *(_DWORD *)(v10 + 120);
  v14 = *v11;
  if ( v13 )
    v15 = v14;
  else
    v15 = v12;
  if ( v13 )
    v16 = v12;
  else
    v16 = v14;
  qdf_trace_msg(
    0x3Du,
    5u,
    "%s: CE-2 Dest status ring current snapshot HP:%u TP:%u",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "hif_display_ctrl_traffic_pipes_state",
    v15,
    v16);
  v25 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 504) + 136LL) + 80LL);
  v26 = *(unsigned int **)(v25 + 128);
  v28 = *(_DWORD *)(v25 + 116);
  v27 = *(_DWORD *)(v25 + 120);
  v29 = *v26;
  if ( v28 )
    v30 = v29;
  else
    v30 = v27;
  if ( v28 )
    v31 = v27;
  else
    v31 = v29;
  return qdf_trace_msg(
           0x3Du,
           5u,
           "%s: CE-3 Source ring current snapshot HP:%u TP:%u",
           v17,
           v18,
           v19,
           v20,
           v21,
           v22,
           v23,
           v24,
           "hif_display_ctrl_traffic_pipes_state",
           v30,
           v31);
}
