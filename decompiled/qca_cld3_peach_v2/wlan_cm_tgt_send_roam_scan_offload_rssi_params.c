__int64 __fastcall wlan_cm_tgt_send_roam_scan_offload_rssi_params(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  unsigned int v11; // w19
  __int64 v13; // x0
  __int64 ext_hdl; // x0
  __int64 (__fastcall *v16)(__int64, __int64); // x8
  __int64 result; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w20
  const char *v27; // x2
  unsigned int *v28; // x8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7

  v10 = *(_QWORD *)(a1 + 216);
  v11 = *(unsigned __int8 *)(a1 + 168);
  if ( !v10 || (v13 = *(_QWORD *)(v10 + 80)) == 0 )
  {
    v27 = "%s: psoc object is NULL";
LABEL_10:
    qdf_trace_msg(0x1Fu, 2u, v27, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_cm_roam_get_tx_ops_from_vdev");
    goto LABEL_11;
  }
  ext_hdl = wlan_psoc_mlme_get_ext_hdl(v13);
  if ( !ext_hdl )
  {
    v27 = "%s: psoc legacy private object is NULL";
    goto LABEL_10;
  }
  v16 = *(__int64 (__fastcall **)(__int64, __int64))(ext_hdl + 7472);
  if ( !v16 )
  {
LABEL_11:
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d send_roam_scan_offload_rssi_params is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_cm_tgt_send_roam_scan_offload_rssi_params",
      v11);
    wlan_objmgr_vdev_release_ref(a1, 2u, v28, v29, v30, v31, v32, v33, v34, v35, v36);
    return 4;
  }
  if ( *((_DWORD *)v16 - 1) != -1833417913 )
    __break(0x8228u);
  result = v16(a1, a2);
  if ( (_DWORD)result )
  {
    v26 = result;
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: vdev %d fail to send roam scan offload RSSI params",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "wlan_cm_tgt_send_roam_scan_offload_rssi_params",
      v11);
    return v26;
  }
  return result;
}
