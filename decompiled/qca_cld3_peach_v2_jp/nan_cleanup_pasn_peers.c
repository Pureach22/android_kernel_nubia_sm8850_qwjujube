__int64 __fastcall nan_cleanup_pasn_peers(__int64 a1)
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
  unsigned int v12; // w20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 comp_private_obj; // x0
  unsigned int *v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7

  v2 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_opmode_from_psoc)(a1, 16, 20);
  if ( v2 )
  {
    v11 = v2;
    qdf_trace_msg(
      0x53u,
      8u,
      "%s: Iterate and delete PASN peers",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "nan_cleanup_pasn_peers");
    v12 = wlan_objmgr_iterate_obj_list(a1, 3, nan_delete_objmgr_pasn_peer, v11, 0, 0x14u);
    if ( v12 )
      qdf_trace_msg(
        0x53u,
        2u,
        "%s: Delete objmgr peers failed",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "nan_cleanup_pasn_peers");
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v11, 0xFu);
    if ( comp_private_obj )
      *(_BYTE *)(comp_private_obj + 105) = 0;
    wlan_objmgr_vdev_release_ref(v11, 0x14u, v22, v23, v24, v25, v26, v27, v28, v29, v30);
  }
  else
  {
    qdf_trace_msg(0x53u, 2u, "%s: vdev is null", v3, v4, v5, v6, v7, v8, v9, v10, "nan_cleanup_pasn_peers");
    return 29;
  }
  return v12;
}
