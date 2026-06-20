__int64 __fastcall mlme_get_roam_trigger_bitmap(__int64 a1, __int64 a2)
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
  unsigned int v22; // w20
  unsigned int *v23; // x8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  v2 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 67);
  if ( !v2 )
  {
    qdf_trace_msg(0x1Fu, 2u, "%s: vdev object is NULL", v3, v4, v5, v6, v7, v8, v9, v10, "mlme_get_roam_trigger_bitmap");
    return 0;
  }
  v11 = v2;
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(v2, v3, v4, v5, v6, v7, v8, v9, v10);
  if ( !ext_hdl )
  {
    qdf_trace_msg(
      0x1Fu,
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
      "mlme_get_roam_trigger_bitmap");
    wlan_objmgr_vdev_release_ref(v11, 0x43u, v23, v24, v25, v26, v27, v28, v29, v30, v31);
    return 0;
  }
  v22 = *(_DWORD *)(ext_hdl + 160);
  wlan_objmgr_vdev_release_ref(v11, 0x43u, v13, v14, v15, v16, v17, v18, v19, v20, v21);
  return v22;
}
