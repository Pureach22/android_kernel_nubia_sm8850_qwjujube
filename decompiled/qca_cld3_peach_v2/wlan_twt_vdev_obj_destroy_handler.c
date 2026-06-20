__int64 __fastcall wlan_twt_vdev_obj_destroy_handler(__int64 a1)
{
  unsigned int v2; // w0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int v11; // w19
  __int64 comp_private_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  v2 = mlme_twt_vdev_destroy_notification();
  if ( v2 )
  {
    v11 = v2;
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: vdev destroy notification failed",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wlan_twt_vdev_obj_destroy_handler");
  }
  else
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Cu);
    if ( comp_private_obj )
    {
      v21 = comp_private_obj;
      v11 = wlan_objmgr_vdev_component_obj_detach(a1, 0x2Cu, comp_private_obj);
      if ( v11 )
        qdf_trace_msg(
          0x96u,
          2u,
          "%s: Failed to detach twt vdev priv object",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "wlan_twt_vdev_obj_destroy_handler");
      _qdf_mem_free(v21);
    }
    else
    {
      qdf_trace_msg(
        0x96u,
        2u,
        "%s: Failed to get twt obj in vdev",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "wlan_twt_vdev_obj_destroy_handler");
      return 16;
    }
  }
  return v11;
}
