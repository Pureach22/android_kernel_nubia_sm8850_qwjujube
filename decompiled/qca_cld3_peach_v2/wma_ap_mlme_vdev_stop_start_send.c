__int64 __fastcall wma_ap_mlme_vdev_stop_start_send(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        unsigned __int8 *a12)
{
  __int64 *context; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 *v22; // x20
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7

  context = _cds_get_context(54, (__int64)"wma_ap_mlme_vdev_stop_start_send", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !context )
    return 4;
  v22 = context;
  if ( (unsigned int)wma_send_vdev_stop_to_fw((__int64)context, *a12, v14, v15, v16, v17, v18, v19, v20, v21) )
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to send vdev stop for vdev id %d",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "wma_ap_mlme_vdev_stop_start_send",
      *a12);
  wma_remove_bss_peer_on_failure(v22, *a12, v23, v24, v25, v26, v27, v28, v29, v30);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Sending add bss rsp to umac(vdev %d status %d)",
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    "wma_vdev_send_start_resp",
    *a12,
    *((unsigned int *)a12 + 1));
  lim_handle_add_bss_rsp(v22[2], a12, v39, v40, v41, v42, v43, v44, v45, v46);
  return 0;
}
