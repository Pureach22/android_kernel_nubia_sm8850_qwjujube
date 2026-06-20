__int64 __fastcall wma_mon_mlme_vdev_stop_send(
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
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  unsigned int v20; // w21
  unsigned int v21; // w20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  context = _cds_get_context(54, (__int64)"wma_mon_mlme_vdev_stop_send", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    v19 = *(_QWORD *)(a1 + 504);
    v20 = *(unsigned __int8 *)(v19 + 104);
    v21 = wma_send_vdev_stop_to_fw((__int64)context, *(_BYTE *)(v19 + 104), v11, v12, v13, v14, v15, v16, v17, v18);
    if ( v21 )
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to send vdev stop cmd: vdev %d",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "wma_mon_mlme_vdev_stop_send",
        v20);
    wlan_vdev_mlme_sm_deliver_evt(*(_QWORD *)(a1 + 504), 0x1Au, 0, 0, v22, v23, v24, v25, v26, v27, v28, v29);
  }
  else
  {
    return 4;
  }
  return v21;
}
