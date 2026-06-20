__int64 __fastcall ap_mlme_start_continue(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 ext_hdl; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7

  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: vdev id = %d ",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "ap_mlme_start_continue",
    *(unsigned __int8 *)(*(_QWORD *)(a1 + 504) + 104LL));
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(*(_QWORD *)(a1 + 504), v14, v15, v16, v17, v18, v19, v20, v21);
  if ( ext_hdl )
    *(_BYTE *)(ext_hdl + 24458) = 1;
  else
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: vdev legacy private object is NULL",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "mlme_set_notify_co_located_ap_update_rnr");
  return wma_ap_mlme_vdev_start_continue(a1, a2, a3);
}
