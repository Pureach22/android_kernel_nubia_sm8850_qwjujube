__int64 __fastcall mlme_get_rso_pending_disable_req_bitmap(__int64 a1, __int64 a2)
{
  unsigned __int8 v2; // w20
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  __int64 ext_hdl; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w21
  unsigned int *v23; // x8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int *v32; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7

  v2 = a2;
  v3 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 67);
  if ( !v3 )
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: vdev object is NULL",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "mlme_get_rso_pending_disable_req_bitmap");
    return 0;
  }
  v12 = v3;
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(v3, v4, v5, v6, v7, v8, v9, v10, v11);
  if ( !ext_hdl )
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: vdev legacy private object is NULL",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "mlme_get_rso_pending_disable_req_bitmap");
    wlan_objmgr_vdev_release_ref(v12, 0x43u, v32, v33, v34, v35, v36, v37, v38, v39, v40);
    return 0;
  }
  v22 = *(unsigned __int8 *)(ext_hdl + 157);
  qdf_trace_msg(
    0x1Fu,
    8u,
    "%s: vdev[%d] rso_disable req bitmap[0x%x]",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "mlme_get_rso_pending_disable_req_bitmap",
    v2,
    *(unsigned __int8 *)(ext_hdl + 157));
  wlan_objmgr_vdev_release_ref(v12, 0x43u, v23, v24, v25, v26, v27, v28, v29, v30, v31);
  return v22;
}
