__int64 __fastcall wlan_coex_psoc_destroyed_notification(__int64 a1)
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
  __int64 v11; // x19
  unsigned int v12; // w20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x21u);
  if ( comp_private_obj )
  {
    v11 = comp_private_obj;
    v12 = wlan_objmgr_psoc_component_obj_detach(a1, 0x21u, comp_private_obj);
    if ( v12 )
      qdf_trace_msg(
        0x70u,
        2u,
        "%s: Failed to detach psoc coex component",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "wlan_coex_psoc_destroyed_notification");
    _qdf_mem_free(v11);
  }
  else
  {
    qdf_trace_msg(
      0x70u,
      2u,
      "%s: %s:%u, Failed to get coex psoc object",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wlan_psoc_get_coex_obj_fl",
      "wlan_coex_psoc_destroyed_notification",
      59);
    return 16;
  }
  return v12;
}
