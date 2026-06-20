__int64 __fastcall wlan_serialization_psoc_create_handler(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  unsigned int v4; // w0
  unsigned int v5; // w20
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  v2 = _qdf_mem_malloc(0x3A90u, "wlan_serialization_psoc_create_handler", 120);
  if ( !v2 )
    return 2;
  v3 = v2;
  v4 = wlan_objmgr_psoc_component_obj_attach(a1, 2u, v2, 0);
  if ( v4 )
  {
    v5 = v4;
    _qdf_mem_free(v3);
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: Obj attach failed",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "wlan_serialization_psoc_create_handler");
    return v5;
  }
  else
  {
    wlan_serialization_create_lock(v3 + 14976);
    qdf_trace_msg(
      0x4Cu,
      8u,
      "%s: ser psoc obj created",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "wlan_serialization_psoc_create_handler");
    return 0;
  }
}
