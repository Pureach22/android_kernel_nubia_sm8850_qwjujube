__int64 __fastcall ll_sap_psoc_obj_created_notification(__int64 a1)
{
  __int64 v2; // x0
  _QWORD *v3; // x20
  unsigned int v4; // w0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  v2 = _qdf_mem_malloc(0x110u, "ll_sap_psoc_obj_created_notification", 68);
  if ( !v2 )
    return 2;
  v3 = (_QWORD *)v2;
  v4 = wlan_objmgr_psoc_component_obj_attach(a1, 0x34u, v2, 0);
  if ( v4 )
  {
    v13 = v4;
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: ll_sap obj attach with psoc failed",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "ll_sap_psoc_obj_created_notification");
    _qdf_mem_free((__int64)v3);
    return v13;
  }
  else
  {
    target_if_ll_sap_register_tx_ops(v3);
    target_if_ll_sap_register_rx_ops(v3 + 3);
    qdf_mc_timer_init((__int64)(v3 + 5), 0, (__int64)ll_sap_tsf_timer_timeout, a1);
    qdf_trace_msg(
      0xA1u,
      8u,
      "%s: ll sap psoc object created",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "ll_sap_psoc_obj_created_notification");
    return 0;
  }
}
