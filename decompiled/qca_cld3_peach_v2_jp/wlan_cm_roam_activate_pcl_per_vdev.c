__int64 __fastcall wlan_cm_roam_activate_pcl_per_vdev(__int64 a1, __int64 a2, char a3)
{
  unsigned __int8 v4; // w19
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x21
  __int64 ext_hdl; // x0
  unsigned int *v16; // x8
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
  const char *v34; // x5
  unsigned int *v36; // x8
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7

  v4 = a2;
  v5 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 2);
  if ( !v5 )
    return qdf_trace_msg(
             0x68u,
             2u,
             "%s: vdev object is NULL",
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             "wlan_cm_roam_activate_pcl_per_vdev");
  v14 = v5;
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(v5, v6, v7, v8, v9, v10, v11, v12, v13);
  if ( ext_hdl )
  {
    v25 = ext_hdl;
    wlan_objmgr_vdev_release_ref(v14, 2u, v16, v17, v18, v19, v20, v21, v22, v23, v24);
    if ( (a3 & 1) != 0 )
      v34 = "VDEV";
    else
      v34 = "PDEV";
    *(_BYTE *)(v25 + 272) = a3 & 1;
    return qdf_trace_msg(
             0x68u,
             8u,
             "%s: CM_ROAM: vdev[%d] SET PCL cmd level - [%s]",
             v26,
             v27,
             v28,
             v29,
             v30,
             v31,
             v32,
             v33,
             "wlan_cm_roam_activate_pcl_per_vdev",
             v4,
             v34);
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
      "wlan_cm_roam_activate_pcl_per_vdev");
    return wlan_objmgr_vdev_release_ref(v14, 2u, v36, v37, v38, v39, v40, v41, v42, v43, v44);
  }
}
