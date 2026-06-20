__int64 __fastcall wlan_cm_tgt_send_disconnect_roam_params(__int64 a1, __int64 a2)
{
  unsigned __int8 v2; // w19
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x8
  __int64 v14; // x21
  __int64 v15; // x0
  __int64 ext_hdl; // x0
  unsigned int *v17; // x8
  __int64 v18; // x23
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 (*v27)(void); // x8
  __int64 v28; // x9
  __int64 result; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x4
  unsigned int v39; // w19
  const char *v40; // x2
  unsigned int *v41; // x8
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7

  v2 = a2;
  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 2);
  if ( !v4 )
    return 4;
  v13 = *(_QWORD *)(v4 + 152);
  v14 = v4;
  if ( !v13 || (v15 = *(_QWORD *)(v13 + 80)) == 0 )
  {
    v40 = "%s: psoc object is NULL";
LABEL_14:
    qdf_trace_msg(0x1Fu, 2u, v40, v5, v6, v7, v8, v9, v10, v11, v12, "wlan_cm_roam_get_tx_ops_from_vdev");
    wlan_objmgr_vdev_release_ref(v14, 2u, v41, v42, v43, v44, v45, v46, v47, v48, v49);
    goto LABEL_15;
  }
  ext_hdl = wlan_psoc_mlme_get_ext_hdl(v15);
  if ( !ext_hdl )
  {
    v40 = "%s: psoc legacy private object is NULL";
    goto LABEL_14;
  }
  v18 = ext_hdl;
  wlan_objmgr_vdev_release_ref(v14, 2u, v17, v5, v6, v7, v8, v9, v10, v11, v12);
  v27 = *(__int64 (**)(void))(v18 + 7296);
  if ( !v27 )
  {
LABEL_15:
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: CM_RSO: vdev %d send_roam_disconnect_params is NULL",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "wlan_cm_tgt_send_disconnect_roam_params",
      v2);
    return 4;
  }
  if ( !a1 || (v28 = *(_QWORD *)(a1 + 2800)) == 0 || !*(_QWORD *)(v28 + 16) )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: Invalid WMI handle",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "wlan_cm_tgt_send_disconnect_roam_params");
    return 4;
  }
  if ( *((_DWORD *)v27 - 1) != -802940237 )
    __break(0x8228u);
  result = v27();
  if ( (_DWORD)result )
  {
    v38 = v2;
    v39 = result;
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: CM_RSO: vdev %d failed to send disconnect params",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "wlan_cm_tgt_send_disconnect_roam_params",
      v38);
    return v39;
  }
  return result;
}
