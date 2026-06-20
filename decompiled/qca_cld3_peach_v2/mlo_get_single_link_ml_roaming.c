__int64 __fastcall mlo_get_single_link_ml_roaming(__int64 a1, __int64 a2)
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
  __int64 v11; // x20
  char single_link_mlo_roaming; // w19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int *v21; // x8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  v2 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 1);
  if ( v2 )
  {
    v11 = v2;
    single_link_mlo_roaming = mlme_get_single_link_mlo_roaming(v2, v3, v4, v5, v6, v7, v8, v9, v10);
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: MLO:is_single_link_ml_roaming %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "mlo_get_single_link_ml_roaming",
      single_link_mlo_roaming & 1);
    wlan_objmgr_vdev_release_ref(v11, 1u, v21, v22, v23, v24, v25, v26, v27, v28, v29);
  }
  else
  {
    qdf_trace_msg(0x8Fu, 2u, "%s: VDEV is null", v3, v4, v5, v6, v7, v8, v9, v10, "mlo_get_single_link_ml_roaming");
    single_link_mlo_roaming = 0;
  }
  return single_link_mlo_roaming & 1;
}
