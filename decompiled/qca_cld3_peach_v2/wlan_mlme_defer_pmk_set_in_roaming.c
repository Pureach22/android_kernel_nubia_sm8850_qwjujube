__int64 __fastcall wlan_mlme_defer_pmk_set_in_roaming(__int64 a1, unsigned int a2, char a3)
{
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x22
  __int64 ext_hdl; // x0
  unsigned int *v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  int v26; // w23
  __int64 v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x20
  __int64 v37; // x0
  unsigned int *v38; // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  unsigned int *v47; // x8
  __int64 v48; // x0
  const char *v49; // x2
  unsigned int v50; // w0

  if ( (a3 & 1) != 0 )
  {
    result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 67);
    if ( !result )
      return result;
    v15 = result;
    ext_hdl = wlan_vdev_mlme_get_ext_hdl(result, v7, v8, v9, v10, v11, v12, v13, v14);
    if ( !ext_hdl )
    {
      qdf_trace_msg(
        0x1Fu,
        2u,
        "%s: vdev legacy private object is NULL",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "mlme_get_roam_state");
      v48 = v15;
      return wlan_objmgr_vdev_release_ref(v48, 0x43u, v47, v39, v40, v41, v42, v43, v44, v45, v46);
    }
    v26 = *(_DWORD *)(ext_hdl + 152);
    result = wlan_objmgr_vdev_release_ref(v15, 0x43u, v17, v18, v19, v20, v21, v22, v23, v24, v25);
    if ( v26 != 5 )
      return result;
  }
  v27 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 67);
  if ( !v27 )
  {
    v49 = "%s: get vdev failed";
    v50 = 104;
    return qdf_trace_msg(v50, 2u, v49, v28, v29, v30, v31, v32, v33, v34, v35, "wlan_mlme_defer_pmk_set_in_roaming");
  }
  v36 = v27;
  v37 = wlan_vdev_mlme_get_ext_hdl(v27, v28, v29, v30, v31, v32, v33, v34, v35);
  if ( !v37 )
  {
    wlan_objmgr_vdev_release_ref(v36, 0x43u, v38, v39, v40, v41, v42, v43, v44, v45, v46);
    v49 = "%s: vdev legacy private object is NULL";
    v50 = 31;
    return qdf_trace_msg(v50, 2u, v49, v28, v29, v30, v31, v32, v33, v34, v35, "wlan_mlme_defer_pmk_set_in_roaming");
  }
  v47 = (unsigned int *)(a3 & 1);
  *(_BYTE *)(v37 + 264) = a3 & 1;
  v48 = v36;
  return wlan_objmgr_vdev_release_ref(v48, 0x43u, v47, v39, v40, v41, v42, v43, v44, v45, v46);
}
