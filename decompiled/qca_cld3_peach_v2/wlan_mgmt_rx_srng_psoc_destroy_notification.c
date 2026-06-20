__int64 __fastcall wlan_mgmt_rx_srng_psoc_destroy_notification(__int64 a1)
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
  unsigned int v12; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w19

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x35u);
  if ( comp_private_obj )
  {
    v11 = comp_private_obj;
    v12 = wlan_objmgr_psoc_component_obj_detach(a1, 0x35u, comp_private_obj);
    if ( v12 )
    {
      v21 = v12;
      qdf_trace_msg(
        0xA5u,
        2u,
        "%s: Failed to detach psoc component obj",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "wlan_mgmt_rx_srng_psoc_destroy_notification");
      return v21;
    }
    else
    {
      _qdf_mem_free(v11);
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0xA5u,
      2u,
      "%s: psoc priv is NULL",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wlan_mgmt_rx_srng_psoc_destroy_notification");
    return 16;
  }
}
