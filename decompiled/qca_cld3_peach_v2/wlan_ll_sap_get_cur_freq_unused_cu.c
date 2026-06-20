__int64 __fastcall wlan_ll_sap_get_cur_freq_unused_cu(__int64 a1, __int64 a2)
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
  __int64 comp_private_obj; // x0
  unsigned int *v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w19
  unsigned int *v24; // x8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  v2 = a2;
  v3 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 105);
  if ( !v3 )
  {
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: vdev %d is null",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "ll_sap_get_cur_freq_unused_cu",
      v2);
    return 0;
  }
  v12 = v3;
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v3, 0x34u);
  if ( !comp_private_obj )
  {
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: ll_sap obj null ref by vdev: %u",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "ll_sap_get_cur_freq_unused_cu",
      v2);
    wlan_objmgr_vdev_release_ref(v12, 0x69u, v24, v25, v26, v27, v28, v29, v30, v31, v32);
    return 0;
  }
  v23 = *(_DWORD *)(comp_private_obj + 32);
  wlan_objmgr_vdev_release_ref(v12, 0x69u, v14, v15, v16, v17, v18, v19, v20, v21, v22);
  return v23;
}
