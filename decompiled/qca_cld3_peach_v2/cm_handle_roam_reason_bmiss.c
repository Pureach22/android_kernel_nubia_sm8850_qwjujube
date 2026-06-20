__int64 *__fastcall cm_handle_roam_reason_bmiss(
        unsigned __int8 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 *result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 *v21; // x21
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7

  result = _cds_get_context(54, (__int64)"wma_handle_roam_reason_bmiss", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( result )
  {
    v21 = result;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Beacon Miss for vdevid %x",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wma_handle_roam_reason_bmiss",
      a1);
    mlme_set_hb_ap_rssi(*(_QWORD *)(v21[65] + 488LL * a1), a2, v22, v23, v24, v25, v26, v27, v28, v29);
    wma_beacon_miss_handler(v21, a1, a2, v30, v31, v32, v33, v34, v35, v36, v37);
    return (__int64 *)wma_sta_kickout_event(0, a1, nullptr);
  }
  return result;
}
