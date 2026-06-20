__int64 __fastcall p2p_vdev_obj_destroy_notification(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v9; // w19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 comp_private_obj; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  _QWORD *v28; // x19
  unsigned int v29; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w19
  __int64 v40; // x0

  if ( a1 )
  {
    v9 = *(_DWORD *)(a1 + 16);
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: vdev mode:%d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "p2p_vdev_obj_destroy_notification",
      v9);
    if ( v9 <= 7 && ((1 << v9) & 0x8D) != 0 )
    {
      comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 5u);
      if ( comp_private_obj )
      {
        v28 = (_QWORD *)comp_private_obj;
        p2p_deinit_random_mac_vdev(comp_private_obj);
        *v28 = 0;
        v29 = wlan_objmgr_vdev_component_obj_detach(a1, 5u, (__int64)v28);
        if ( v29 )
        {
          v38 = v29;
          qdf_trace_msg(
            0x4Eu,
            2u,
            "%s: Failed to detach p2p component, %d",
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            "p2p_vdev_obj_destroy_notification",
            v29);
          return v38;
        }
        qdf_trace_msg(
          0x4Eu,
          8u,
          "%s: destroy p2p vdev object, p2p vdev obj:%pK, noa info:%pK",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "p2p_vdev_obj_destroy_notification",
          v28,
          v28[1]);
        v40 = v28[1];
        if ( v40 )
          _qdf_mem_free(v40);
        _qdf_mem_free((__int64)v28);
      }
      else
      {
        qdf_trace_msg(
          0x4Eu,
          8u,
          "%s: p2p vdev object is NULL",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "p2p_vdev_obj_destroy_notification");
      }
    }
    else
    {
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: no p2p vdev private object for mode %d",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "p2p_vdev_obj_destroy_notification",
        v9);
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: vdev context passed is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "p2p_vdev_obj_destroy_notification");
    return 4;
  }
}
