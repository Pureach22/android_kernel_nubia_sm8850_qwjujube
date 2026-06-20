__int64 __fastcall disa_psoc_object_created_notification(
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
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x20
  unsigned int v20; // w19
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  qdf_trace_msg(0x5Cu, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "disa_psoc_object_created_notification");
  v10 = _qdf_mem_malloc(0x30u, "disa_psoc_object_created_notification", 130);
  if ( v10 )
  {
    v19 = v10;
    v20 = wlan_objmgr_psoc_component_obj_attach(a1, 0x15u, v10, 0);
    if ( v20 )
    {
      qdf_trace_msg(
        0x5Cu,
        2u,
        "%s: Failed to attach disa_priv with psoc",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "disa_psoc_object_created_notification");
      _qdf_mem_free(v19);
    }
    else
    {
      *(_DWORD *)(v19 + 32) = 0;
      *(_QWORD *)(v19 + 40) = 0;
      target_if_disa_register_tx_ops(v19 + 8);
    }
  }
  else
  {
    v20 = 2;
  }
  qdf_trace_msg(0x5Cu, 8u, "%s: exit", v11, v12, v13, v14, v15, v16, v17, v18, "disa_psoc_object_created_notification");
  return v20;
}
