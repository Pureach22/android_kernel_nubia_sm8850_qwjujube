__int64 __fastcall wlan_dcs_psoc_obj_destroy_notification(__int64 a1)
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

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x24u);
  if ( comp_private_obj )
  {
    v11 = comp_private_obj;
    v12 = wlan_objmgr_psoc_component_obj_detach(a1, 0x24u, comp_private_obj);
    timer_delete_sync(v11 + 280);
    timer_delete_sync(v11 + 664);
    timer_delete_sync(v11 + 1048);
    _qdf_mem_free(v11);
  }
  else
  {
    qdf_trace_msg(
      0x74u,
      2u,
      "%s: invalid wifi dcs obj",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wlan_dcs_psoc_obj_destroy_notification");
    return 5;
  }
  return v12;
}
