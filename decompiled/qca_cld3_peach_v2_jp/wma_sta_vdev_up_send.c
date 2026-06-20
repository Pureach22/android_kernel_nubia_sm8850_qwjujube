__int64 __fastcall wma_sta_vdev_up_send(
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
  __int64 *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 *v19; // x19
  unsigned int v20; // w20
  __int64 v21; // x22
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  context = _cds_get_context(54, (__int64)"wma_sta_vdev_up_send", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
    return 4;
  v19 = context;
  v20 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 504) + 104LL);
  v21 = context[65] + 488LL * *(unsigned __int8 *)(*(_QWORD *)(a1 + 504) + 104LL);
  *(_WORD *)(a1 + 42) = *(_WORD *)(v21 + 208);
  if ( (unsigned int)vdev_mgr_up_send(a1, v11, v12, v13, v14, v15, v16, v17, v18) )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to send vdev up cmd: vdev %d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "wma_sta_vdev_up_send",
      v20);
  }
  else
  {
    wma_set_vdev_mgmt_rate(v22, v23, v24, v25, v26, v27, v28, v29);
    if ( *(_BYTE *)(v21 + 352) == 1 )
      wma_add_beacon_filter(v19, (unsigned int *)(v21 + 284));
  }
  return 0;
}
