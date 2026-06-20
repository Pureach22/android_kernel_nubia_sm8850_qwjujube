__int64 __fastcall pre_cac_vdev_destroy_notification(__int64 a1)
{
  __int64 comp_private_obj; // x0
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
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Du);
  if ( comp_private_obj )
  {
    v11 = comp_private_obj;
    v12 = wlan_objmgr_vdev_component_obj_detach(a1, 0x2Du, comp_private_obj);
    if ( v12 )
      qdf_trace_msg(
        0x98u,
        2u,
        "%s: Failed to detach priv with vdev",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "pre_cac_vdev_destroy_notification");
    _qdf_mem_free(v11);
  }
  else
  {
    qdf_trace_msg(
      0x98u,
      2u,
      "%s:%u: vdev id: %d, vdev_priv is NULL",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "pre_cac_vdev_destroy_notification",
      510,
      *(unsigned __int8 *)(a1 + 168));
    qdf_trace_msg(
      0x98u,
      2u,
      "%s: vdev priv is NULL",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "pre_cac_vdev_destroy_notification");
    return 16;
  }
  return v12;
}
