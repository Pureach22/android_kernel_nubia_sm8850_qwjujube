__int64 __fastcall pmo_vdev_object_destroyed_notification(__int64 a1)
{
  __int64 comp_private_obj; // x19
  unsigned int v3; // w20
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
  v3 = wlan_objmgr_vdev_component_obj_detach(a1, 4u, comp_private_obj);
  if ( v3 )
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: Failed to detach vdev_ctx with vdev",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "pmo_vdev_object_destroyed_notification");
  _qdf_mem_free(comp_private_obj);
  return v3;
}
