__int64 __fastcall wlan_cm_tgt_send_roam_vendor_handoff_config(__int64 a1, unsigned int *a2)
{
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x8
  __int64 v13; // x19
  __int64 v14; // x0
  __int64 ext_hdl; // x0
  __int64 (__fastcall *v16)(__int64, __int64, __int64); // x8
  __int64 v17; // x1
  __int64 v18; // x2
  unsigned int *v19; // x8
  unsigned int v20; // w21
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  const char *v29; // x2

  v3 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a2, 2);
  if ( !v3 )
    return 4;
  v12 = *(_QWORD *)(v3 + 216);
  v13 = v3;
  if ( !v12 || (v14 = *(_QWORD *)(v12 + 80)) == 0 )
  {
    v29 = "%s: psoc object is NULL";
LABEL_11:
    qdf_trace_msg(0x1Fu, 2u, v29, v4, v5, v6, v7, v8, v9, v10, v11, "wlan_cm_roam_get_tx_ops_from_vdev");
    goto LABEL_12;
  }
  ext_hdl = wlan_psoc_mlme_get_ext_hdl(v14);
  if ( !ext_hdl )
  {
    v29 = "%s: psoc legacy private object is NULL";
    goto LABEL_11;
  }
  v16 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(ext_hdl + 7488);
  if ( v16 )
  {
    v17 = *a2;
    v18 = a2[1];
    if ( *((_DWORD *)v16 - 1) != 1382977098 )
      __break(0x8228u);
    v20 = v16(v13, v17, v18);
    if ( v20 )
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: vdev %d fail to send roam vendor handoff config",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "wlan_cm_tgt_send_roam_vendor_handoff_config",
        *a2);
    goto LABEL_13;
  }
LABEL_12:
  qdf_trace_msg(
    0x68u,
    2u,
    "%s: vdev %d send_roam_vendor_handoff_config is NULL",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "wlan_cm_tgt_send_roam_vendor_handoff_config",
    *a2);
  v20 = 4;
LABEL_13:
  wlan_objmgr_vdev_release_ref(v13, 2u, v19, v21, v22, v23, v24, v25, v26, v27, v28);
  return v20;
}
