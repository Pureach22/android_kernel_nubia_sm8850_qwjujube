__int64 __fastcall p2p_vdev_obj_create_notification(
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
  unsigned int v9; // w20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x0
  __int64 v20; // x20
  unsigned int v21; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w19
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7

  if ( !a1 )
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
      "p2p_vdev_obj_create_notification");
    return 4;
  }
  v9 = *(_DWORD *)(a1 + 16);
  qdf_trace_msg(0x4Eu, 8u, "%s: vdev mode:%d", a2, a3, a4, a5, a6, a7, a8, a9, "p2p_vdev_obj_create_notification", v9);
  if ( v9 <= 7 && ((1 << v9) & 0x8D) != 0 )
  {
    v19 = _qdf_mem_malloc(0x430u, "p2p_vdev_obj_create_notification", 225);
    if ( !v19 )
      return 2;
    v20 = v19;
    *(_QWORD *)v19 = a1;
    *(_BYTE *)(v19 + 16) = 1;
    *(_WORD *)(v19 + 18) = 0;
    p2p_init_random_mac_vdev();
    qdf_mem_copy((void *)(v20 + 952), (const void *)(a1 + 74), 6u);
    v21 = wlan_objmgr_vdev_component_obj_attach(a1, 5u, v20, 0);
    if ( v21 )
    {
      v30 = v21;
      p2p_deinit_random_mac_vdev(v20);
      _qdf_mem_free(v20);
      qdf_trace_msg(
        0x4Eu,
        2u,
        "%s: Failed to attach p2p component to vdev, %d",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "p2p_vdev_obj_create_notification",
        v30);
      return v30;
    }
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: p2p vdev object create successful, %pK",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "p2p_vdev_obj_create_notification",
      v20);
  }
  else
  {
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: won't create p2p vdev private object for mode %d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "p2p_vdev_obj_create_notification",
      v9);
  }
  return 0;
}
