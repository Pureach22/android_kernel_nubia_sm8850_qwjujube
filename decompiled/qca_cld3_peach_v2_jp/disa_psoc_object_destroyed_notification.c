__int64 __fastcall disa_psoc_object_destroyed_notification(
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
  __int64 comp_private_obj; // x20
  unsigned int v11; // w19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  qdf_trace_msg(0x5Cu, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "disa_psoc_object_destroyed_notification");
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x15u);
  v11 = wlan_objmgr_psoc_component_obj_detach(a1, 0x15u, comp_private_obj);
  if ( v11 )
    qdf_trace_msg(
      0x5Cu,
      2u,
      "%s: Failed to detach disa_priv with psoc",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "disa_psoc_object_destroyed_notification");
  _qdf_mem_free(comp_private_obj);
  qdf_trace_msg(
    0x5Cu,
    8u,
    "%s: exit",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    "disa_psoc_object_destroyed_notification");
  return v11;
}
