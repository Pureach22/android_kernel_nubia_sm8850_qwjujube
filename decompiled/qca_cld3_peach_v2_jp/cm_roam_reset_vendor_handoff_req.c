__int64 __fastcall cm_roam_reset_vendor_handoff_req(__int64 a1, __int64 a2)
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
  __int64 v22; // x21
  unsigned int *v23; // x8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  v2 = a2;
  v3 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 77);
  if ( !v3 )
    return qdf_trace_msg(
             0x68u,
             2u,
             "%s: get vdev failed",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "cm_roam_reset_vendor_handoff_req");
  v12 = v3;
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(v3, v4, v5, v6, v7, v8, v9, v10, v11);
  if ( ext_hdl )
  {
    v22 = ext_hdl;
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: vdev: %d Reset vendor handoff req",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "cm_roam_reset_vendor_handoff_req",
      v2);
    *(_BYTE *)(v22 + 288) = 0;
    *(_QWORD *)(v22 + 280) = 0;
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: unable to set mlme_priv is NULL",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "cm_roam_reset_vendor_handoff_req");
  }
  return wlan_objmgr_vdev_release_ref(v12, 0x4Du, v23, v24, v25, v26, v27, v28, v29, v30, v31);
}
