__int64 __fastcall mlo_roam_update_connected_links(__int64 a1, __int64 a2)
{
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x21
  char single_link_mlo_roaming; // w22
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int *v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 result; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  _QWORD *v43; // x9
  __int64 v44; // x8
  __int64 v45; // x10
  __int64 v46; // x9

  mlo_clear_connected_links_bmap((_QWORD *)a1);
  v4 = *(_QWORD *)(a1 + 216);
  if ( v4 )
    v5 = *(_QWORD *)(v4 + 80);
  else
    v5 = 0;
  v6 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
         v5,
         *(unsigned __int8 *)(a1 + 168),
         1);
  if ( !v6 )
  {
    qdf_trace_msg(0x8Fu, 2u, "%s: VDEV is null", v7, v8, v9, v10, v11, v12, v13, v14, "mlo_get_single_link_ml_roaming");
    return mlo_update_connected_links_bmap(
             *(_QWORD *)(a1 + 1360),
             (unsigned __int8 *)(a2 + 160),
             v35,
             v36,
             v37,
             v38,
             v39,
             v40,
             v41,
             v42);
  }
  v15 = v6;
  single_link_mlo_roaming = mlme_get_single_link_mlo_roaming(v6, v7, v8, v9, v10, v11, v12, v13, v14);
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: MLO:is_single_link_ml_roaming %d",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "mlo_get_single_link_ml_roaming",
    single_link_mlo_roaming & 1);
  result = wlan_objmgr_vdev_release_ref(v15, 1u, v25, v26, v27, v28, v29, v30, v31, v32, v33);
  if ( (single_link_mlo_roaming & 1) == 0 )
    return mlo_update_connected_links_bmap(
             *(_QWORD *)(a1 + 1360),
             (unsigned __int8 *)(a2 + 160),
             v35,
             v36,
             v37,
             v38,
             v39,
             v40,
             v41,
             v42);
  v43 = *(_QWORD **)(a1 + 1360);
  if ( v43 )
  {
    v44 = v43[278];
    if ( v44 )
    {
      v45 = v43[3];
      if ( v45 && v45 == a1 )
        *(_QWORD *)(v44 + 8) |= 1uLL;
      v46 = v43[4];
      if ( v46 )
      {
        if ( v46 == a1 )
          *(_QWORD *)(v44 + 8) |= 2uLL;
      }
    }
  }
  return result;
}
