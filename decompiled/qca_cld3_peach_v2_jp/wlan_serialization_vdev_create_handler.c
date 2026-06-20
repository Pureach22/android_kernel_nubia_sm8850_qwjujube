__int64 __fastcall wlan_serialization_vdev_create_handler(__int64 a1)
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
  int v12; // w21
  unsigned int v13; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w20
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v32; // x8
  __int64 v33; // x2

  v2 = _qdf_mem_malloc(0x38u, "wlan_serialization_vdev_create_handler", 424);
  if ( !v2 )
    return 2;
  v11 = v2;
  if ( (*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) == 1 )
    v12 = 35;
  else
    v12 = 4;
  qdf_trace_msg(
    0x4Cu,
    8u,
    "%s: Vdev type %d max_pending_cmds %d",
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    "wlan_serialization_vdev_create_handler");
  *(_QWORD *)v11 = v11;
  *(_QWORD *)(v11 + 8) = v11;
  *(_QWORD *)(v11 + 16) = 0x100000000LL;
  *(_QWORD *)(v11 + 24) = v11 + 24;
  *(_QWORD *)(v11 + 32) = v11 + 24;
  *(_DWORD *)(v11 + 40) = 0;
  *(_DWORD *)(v11 + 44) = v12;
  v13 = wlan_objmgr_vdev_component_obj_attach(a1, 2u, v11, 0);
  if ( v13 )
  {
    v22 = v13;
    if ( *(_DWORD *)(v11 + 40) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: list length not equal to zero",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "qdf_list_destroy");
    if ( *(_DWORD *)(v11 + 16) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: list length not equal to zero",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "qdf_list_destroy");
    _qdf_mem_free(v11);
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: serialization vdev obj attach failed",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "wlan_serialization_vdev_create_handler");
    return v22;
  }
  else
  {
    v32 = *(_QWORD *)(a1 + 152);
    if ( v32 )
      v33 = *(_QWORD *)(v32 + 80);
    else
      v33 = 0;
    wlan_minidump_log(v11, 56, v33, 59, "wlan_ser_vdev_obj");
    return 0;
  }
}
