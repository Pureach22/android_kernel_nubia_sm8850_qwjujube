__int64 __fastcall wlan_mgmt_rx_srng_psoc_create_notification(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  unsigned int v4; // w0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w20

  v2 = _qdf_mem_malloc(0x28u, "wlan_mgmt_rx_srng_psoc_create_notification", 507);
  if ( !v2 )
    return 2;
  v3 = v2;
  v4 = wlan_objmgr_psoc_component_obj_attach(a1, 0x35u, v2, 0);
  if ( v4 )
  {
    v13 = v4;
    qdf_trace_msg(
      0xA5u,
      2u,
      "%s: Failed to attach psoc component obj",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_mgmt_rx_srng_psoc_create_notification");
    _qdf_mem_free(v3);
    return v13;
  }
  else
  {
    *(_QWORD *)v3 = a1;
    *(_BYTE *)(v3 + 8) = *(_BYTE *)(cfg_psoc_get_values(a1) + 32497);
    target_if_mgmt_rx_srng_register_rx_ops(v3 + 24);
    target_if_mgmt_rx_srng_register_tx_ops(v3 + 16);
    return 0;
  }
}
