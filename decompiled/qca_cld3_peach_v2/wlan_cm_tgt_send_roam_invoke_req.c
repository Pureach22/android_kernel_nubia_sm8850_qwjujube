__int64 __fastcall wlan_cm_tgt_send_roam_invoke_req(__int64 a1, unsigned __int8 *a2)
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
  __int64 (__fastcall *v16)(__int64, unsigned __int8 *); // x8
  unsigned int *v17; // x8
  unsigned int v18; // w21
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  const char *v27; // x2

  v3 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a2, 2);
  if ( !v3 )
    return 4;
  v12 = *(_QWORD *)(v3 + 216);
  v13 = v3;
  if ( !v12 || (v14 = *(_QWORD *)(v12 + 80)) == 0 )
  {
    v27 = "%s: psoc object is NULL";
LABEL_11:
    qdf_trace_msg(0x1Fu, 2u, v27, v4, v5, v6, v7, v8, v9, v10, v11, "wlan_cm_roam_get_tx_ops_from_vdev");
    goto LABEL_12;
  }
  ext_hdl = wlan_psoc_mlme_get_ext_hdl(v14);
  if ( !ext_hdl )
  {
    v27 = "%s: psoc legacy private object is NULL";
    goto LABEL_11;
  }
  v16 = *(__int64 (__fastcall **)(__int64, unsigned __int8 *))(ext_hdl + 7416);
  if ( v16 )
  {
    if ( *((_DWORD *)v16 - 1) != -1902629686 )
      __break(0x8228u);
    v18 = v16(v13, a2);
    if ( v18 )
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: CM_RSO: vdev %d fail to send roam invoke cmd",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "wlan_cm_tgt_send_roam_invoke_req",
        *a2);
    goto LABEL_13;
  }
LABEL_12:
  qdf_trace_msg(
    0x68u,
    2u,
    "%s: CM_RSO: vdev %d send_roam_invoke_cmd is NULL",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "wlan_cm_tgt_send_roam_invoke_req",
    *a2);
  v18 = 4;
LABEL_13:
  wlan_objmgr_vdev_release_ref(v13, 2u, v17, v19, v20, v21, v22, v23, v24, v25, v26);
  return v18;
}
