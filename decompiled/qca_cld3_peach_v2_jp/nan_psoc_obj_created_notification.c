__int64 __fastcall nan_psoc_obj_created_notification(
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
  __int64 v10; // x0
  __int64 v11; // x19
  unsigned int v12; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w20

  qdf_trace_msg(
    0x53u,
    8u,
    "%s: nan_psoc_create_notif called",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "nan_psoc_obj_created_notification");
  v10 = _qdf_mem_malloc(0x180u, "nan_psoc_obj_created_notification", 44);
  if ( !v10 )
    return 2;
  v11 = v10;
  *(_DWORD *)v10 = 0;
  *(_QWORD *)(v10 + 8) = 0;
  v12 = wlan_objmgr_psoc_component_obj_attach(a1, 0xFu, v10, 0);
  if ( v12 )
  {
    v21 = v12;
    qdf_trace_msg(
      0x53u,
      1u,
      "%s: obj attach with psoc failed",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "nan_psoc_obj_created_notification");
    _qdf_mem_free(v11);
    return v21;
  }
  else
  {
    target_if_nan_register_tx_ops(v11 + 240);
    target_if_nan_register_rx_ops(v11 + 256);
    return 0;
  }
}
