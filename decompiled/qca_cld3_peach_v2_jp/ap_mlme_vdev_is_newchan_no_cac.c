__int64 __fastcall ap_mlme_vdev_is_newchan_no_cac(
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
  __int64 ext_hdl; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  int v19; // w20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7

  ext_hdl = wlan_vdev_mlme_get_ext_hdl(*(_QWORD *)(a1 + 504), a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !ext_hdl )
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: vdev legacy private object is NULL",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "mlme_get_cac_required");
    qdf_trace_msg(
      0x1Fu,
      8u,
      "%s: vdev id = %d cac_required %d",
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      "ap_mlme_vdev_is_newchan_no_cac",
      *(unsigned __int8 *)(*(_QWORD *)(a1 + 504) + 104LL),
      0);
    return 0;
  }
  v19 = *(unsigned __int8 *)(ext_hdl + 4);
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: vdev id = %d cac_required %d",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "ap_mlme_vdev_is_newchan_no_cac",
    *(unsigned __int8 *)(*(_QWORD *)(a1 + 504) + 104LL),
    *(unsigned __int8 *)(ext_hdl + 4));
  if ( v19 != 1 )
    return 0;
  v28 = wlan_vdev_mlme_get_ext_hdl(*(_QWORD *)(a1 + 504), v20, v21, v22, v23, v24, v25, v26, v27);
  if ( v28 )
    *(_BYTE *)(v28 + 4) = 0;
  else
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: vdev legacy private object is NULL",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "mlme_set_cac_required");
  return 16;
}
