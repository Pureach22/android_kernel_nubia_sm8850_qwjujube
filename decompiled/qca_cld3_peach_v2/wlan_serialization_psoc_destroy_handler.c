__int64 __fastcall wlan_serialization_psoc_destroy_handler(__int64 a1)
{
  __int64 psoc_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  unsigned int v12; // w21
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

  psoc_obj = wlan_serialization_get_psoc_obj(a1);
  if ( psoc_obj )
  {
    v11 = psoc_obj;
    v12 = wlan_objmgr_psoc_component_obj_detach(a1, 2u, psoc_obj);
    if ( v12 )
      qdf_trace_msg(
        0x4Cu,
        2u,
        "%s: ser psoc private obj detach failed",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "wlan_serialization_psoc_destroy_handler");
    wlan_serialization_destroy_lock(v11 + 14976);
    qdf_trace_msg(
      0x4Cu,
      8u,
      "%s: ser psoc obj deleted with status %d",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "wlan_serialization_psoc_destroy_handler",
      v12);
    wlan_minidump_remove(v11, 14992, a1, 50, "wlan_ser_psoc_obj");
    _qdf_mem_free(v11);
  }
  else
  {
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: invalid ser_soc_obj",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wlan_serialization_psoc_destroy_handler");
    return 5;
  }
  return v12;
}
