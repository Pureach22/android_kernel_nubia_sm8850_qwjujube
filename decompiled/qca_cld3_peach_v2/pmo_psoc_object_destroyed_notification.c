__int64 __fastcall pmo_psoc_object_destroyed_notification(
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
  void *comp_private_obj; // x19
  __int64 v11; // x1
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
  unsigned int v28; // w19
  __int64 v29; // x1

  qdf_trace_msg(0x4Du, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "pmo_psoc_object_destroyed_notification");
  comp_private_obj = (void *)wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  if ( (unsigned int)wlan_objmgr_psoc_component_obj_detach(a1, 4u, (__int64)comp_private_obj) )
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: Failed to detach psoc_ctx from psoc",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "pmo_psoc_object_destroyed_notification");
    v28 = 16;
  }
  else
  {
    qdf_event_destroy((__int64)comp_private_obj + 496, v11);
    qdf_event_destroy((__int64)comp_private_obj + 536, v29);
    _qdf_wake_lock_destroy((__int64)comp_private_obj + 584);
    qdf_mem_set(comp_private_obj, 0x420u, 0);
    _qdf_mem_free((__int64)comp_private_obj);
    v28 = 0;
  }
  qdf_trace_msg(0x4Du, 8u, "%s: exit", v20, v21, v22, v23, v24, v25, v26, v27, "pmo_psoc_object_destroyed_notification");
  return v28;
}
