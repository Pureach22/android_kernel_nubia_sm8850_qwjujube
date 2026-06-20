__int64 __fastcall wlan_cm_get_roam_offload_ssid(__int64 a1, __int64 a2, void *a3, _BYTE *a4)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  __int64 ext_hdl; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x22
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int *v34; // x8

  v6 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 77);
  if ( !v6 )
    return qdf_trace_msg(
             0x68u,
             2u,
             "%s: VDEV is NULL",
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             v14,
             "wlan_cm_get_roam_offload_ssid");
  v15 = v6;
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(v6, v7, v8, v9, v10, v11, v12, v13, v14);
  if ( ext_hdl )
  {
    v25 = ext_hdl;
    qdf_mem_copy(a3, (const void *)(ext_hdl + 297), *(unsigned __int8 *)(ext_hdl + 296));
    v34 = (unsigned int *)*(unsigned __int8 *)(v25 + 296);
    *a4 = (_BYTE)v34;
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev legacy private object is NULL",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "wlan_cm_get_roam_offload_ssid");
  }
  return wlan_objmgr_vdev_release_ref(v15, 0x4Du, v34, v26, v27, v28, v29, v30, v31, v32, v33);
}
