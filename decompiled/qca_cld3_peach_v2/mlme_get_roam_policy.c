__int64 __fastcall mlme_get_roam_policy(__int64 a1, __int64 a2)
{
  unsigned __int8 v2; // w19
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  __int64 ext_hdl; // x0
  unsigned int *v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x21
  unsigned int *v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  v2 = a2;
  v3 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 67);
  if ( v3 )
  {
    v12 = v3;
    ext_hdl = wlan_vdev_mlme_get_ext_hdl(v3, v4, v5, v6, v7, v8, v9, v10, v11);
    if ( ext_hdl )
    {
      v23 = ext_hdl;
      wlan_objmgr_vdev_release_ref(v12, 0x43u, v14, v15, v16, v17, v18, v19, v20, v21, v22);
      return *(unsigned int *)(v23 + 168);
    }
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev%d: vdev legacy private object is NULL",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "mlme_get_roam_policy",
      v2);
    wlan_objmgr_vdev_release_ref(v12, 0x43u, v25, v26, v27, v28, v29, v30, v31, v32, v33);
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev%d: vdev object is NULL",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "mlme_get_roam_policy",
      v2);
  }
  return 0;
}
