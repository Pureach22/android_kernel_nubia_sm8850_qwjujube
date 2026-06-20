__int64 __fastcall mlo_roam_is_internal_disconnect(
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
  __int64 v9; // x29
  __int64 v10; // x30
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x20
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // [xsp+8h] [xbp-18h]

  if ( (*(_BYTE *)(a1 + 60) & 2) == 0 )
    return 1;
  v39 = v10;
  if ( !wlan_cm_is_vdev_disconnecting(a1, a2, a3, a4, a5, a6, a7, a8, a9) )
    return 1;
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: Disconnect is ongoing on vdev %d",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "mlo_roam_is_internal_disconnect",
    *(unsigned __int8 *)(a1 + 168),
    v9,
    v39);
  v21 = _qdf_mem_malloc(0x18u, "mlo_roam_is_internal_disconnect", 1225);
  if ( v21 )
  {
    v30 = v21;
    if ( (wlan_cm_get_active_disconnect_req(a1, v21, v22, v23, v24, v25, v26, v27, v28, v29) & 1) != 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: Disconnect source %d",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "mlo_roam_is_internal_disconnect",
        *(unsigned int *)(v30 + 8));
      _qdf_mem_free(v30);
      return 1;
    }
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev: %d: Active disconnect not found",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "mlo_roam_is_internal_disconnect",
      *(unsigned __int8 *)(a1 + 168));
    _qdf_mem_free(v30);
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Malloc failed for disconnect req",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "mlo_roam_is_internal_disconnect");
  }
  return 0;
}
