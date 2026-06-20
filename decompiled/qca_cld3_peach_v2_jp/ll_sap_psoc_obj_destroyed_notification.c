__int64 __fastcall ll_sap_psoc_obj_destroyed_notification(__int64 a1)
{
  __int64 comp_private_obj; // x19
  unsigned int v3; // w20
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x34u);
  qdf_mc_timer_destroy(comp_private_obj + 40);
  v3 = wlan_objmgr_psoc_component_obj_detach(a1, 0x34u, comp_private_obj);
  if ( v3 )
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: ll_sap detach failed",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "ll_sap_psoc_obj_destroyed_notification");
  _qdf_mem_free(comp_private_obj);
  qdf_trace_msg(
    0xA1u,
    8u,
    "%s: ll sap psoc object destroyed",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "ll_sap_psoc_obj_destroyed_notification");
  return v3;
}
