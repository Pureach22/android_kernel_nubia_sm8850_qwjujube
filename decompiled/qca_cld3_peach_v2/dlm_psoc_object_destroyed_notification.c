__int64 __fastcall dlm_psoc_object_destroyed_notification(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x20u);
  if ( comp_private_obj )
  {
    v11 = comp_private_obj;
    wlan_objmgr_psoc_component_obj_detach(a1, 0x20u, comp_private_obj);
    _qdf_mem_free(v11);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x6Du,
      2u,
      "%s: DLM psoc obj NULL",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "dlm_psoc_object_destroyed_notification");
    return 16;
  }
}
