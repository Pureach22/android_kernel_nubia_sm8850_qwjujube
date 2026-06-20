__int64 __fastcall wlan_cm_tgt_send_roam_full_scan_6ghz_on_disc(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned __int8 v4; // w20
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x8
  __int64 v15; // x19
  __int64 v16; // x0
  __int64 ext_hdl; // x0
  _DWORD *v18; // x8
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

  v4 = a2;
  v5 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 2);
  if ( !v5 )
    return 4;
  v14 = *(_QWORD *)(v5 + 152);
  v15 = v5;
  if ( !v14 || (v16 = *(_QWORD *)(v14 + 80)) == 0 )
  {
    v29 = "%s: psoc object is NULL";
LABEL_11:
    qdf_trace_msg(0x1Fu, 2u, v29, v6, v7, v8, v9, v10, v11, v12, v13, "wlan_cm_roam_get_tx_ops_from_vdev");
    goto LABEL_12;
  }
  ext_hdl = wlan_psoc_mlme_get_ext_hdl(v16);
  if ( !ext_hdl )
  {
    v29 = "%s: psoc legacy private object is NULL";
    goto LABEL_11;
  }
  v18 = *(_DWORD **)(ext_hdl + 7240);
  if ( v18 )
  {
    if ( *(v18 - 1) != -988222069 )
      __break(0x8228u);
    v20 = ((__int64 (__fastcall *)(__int64, _QWORD))v18)(v15, a3);
    if ( v20 )
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: vdev %d fail to send inclusion of 6 GHz channels",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "wlan_cm_tgt_send_roam_full_scan_6ghz_on_disc",
        v4);
    goto LABEL_13;
  }
LABEL_12:
  qdf_trace_msg(
    0x68u,
    2u,
    "%s: vdev %d send_roam_full_scan_6ghz_on_disc is NULL",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "wlan_cm_tgt_send_roam_full_scan_6ghz_on_disc",
    v4);
  v20 = 4;
LABEL_13:
  wlan_objmgr_vdev_release_ref(v15, 2u, v19, v21, v22, v23, v24, v25, v26, v27, v28);
  return v20;
}
