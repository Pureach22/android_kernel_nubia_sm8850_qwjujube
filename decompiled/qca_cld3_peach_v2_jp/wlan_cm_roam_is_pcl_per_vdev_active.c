__int64 __fastcall wlan_cm_roam_is_pcl_per_vdev_active(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  __int64 ext_hdl; // x0
  unsigned int *v13; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x20
  char v23; // w8
  unsigned int *v24; // x8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  v2 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 2);
  if ( !v2 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev object is NULL",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wlan_cm_roam_is_pcl_per_vdev_active");
LABEL_6:
    v23 = 0;
    return v23 & 1;
  }
  v11 = v2;
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(v2, v3, v4, v5, v6, v7, v8, v9, v10);
  if ( !ext_hdl )
  {
    qdf_trace_msg(
      0x68u,
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
      "wlan_cm_roam_is_pcl_per_vdev_active");
    wlan_objmgr_vdev_release_ref(v11, 2u, v24, v25, v26, v27, v28, v29, v30, v31, v32);
    goto LABEL_6;
  }
  v22 = ext_hdl;
  wlan_objmgr_vdev_release_ref(v11, 2u, v13, v14, v15, v16, v17, v18, v19, v20, v21);
  v23 = *(_BYTE *)(v22 + 272);
  return v23 & 1;
}
