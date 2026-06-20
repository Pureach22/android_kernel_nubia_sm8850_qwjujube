__int64 __fastcall wlan_cm_tgt_send_roam_abort_req(__int64 a1, __int64 a2)
{
  unsigned int v2; // w20
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
  _DWORD *v16; // x8
  unsigned int *v17; // x8
  unsigned int v18; // w21
  const char *v19; // x2
  const char *v20; // x2

  v2 = a2;
  v3 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 2);
  if ( !v3 )
    return 4;
  v12 = *(_QWORD *)(v3 + 216);
  v13 = v3;
  if ( !v12 || (v14 = *(_QWORD *)(v12 + 80)) == 0 )
  {
    v20 = "%s: psoc object is NULL";
LABEL_11:
    qdf_trace_msg(0x1Fu, 2u, v20, v4, v5, v6, v7, v8, v9, v10, v11, "wlan_cm_roam_get_tx_ops_from_vdev");
    goto LABEL_12;
  }
  ext_hdl = wlan_psoc_mlme_get_ext_hdl(v14);
  if ( !ext_hdl )
  {
    v20 = "%s: psoc legacy private object is NULL";
    goto LABEL_11;
  }
  v16 = *(_DWORD **)(ext_hdl + 7384);
  if ( !v16 )
  {
LABEL_12:
    v18 = 4;
    v19 = "%s: CM_RSO: vdev %d send_roam_abort is NULL";
    goto LABEL_13;
  }
  if ( *(v16 - 1) != -988222069 )
    __break(0x8228u);
  v18 = ((__int64 (__fastcall *)(__int64, _QWORD))v16)(v13, v2);
  if ( !v18 )
    goto LABEL_14;
  v19 = "%s: CM_RSO: vdev %d fail to send roam abort";
LABEL_13:
  qdf_trace_msg(
    0x68u,
    2u,
    v19,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "wlan_cm_tgt_send_roam_abort_req",
    (unsigned __int8)v2);
LABEL_14:
  wlan_objmgr_vdev_release_ref(v13, 2u, v17, v4, v5, v6, v7, v8, v9, v10, v11);
  return v18;
}
