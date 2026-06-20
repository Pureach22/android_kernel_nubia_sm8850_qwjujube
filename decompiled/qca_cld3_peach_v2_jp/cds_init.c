__int64 cds_init()
{
  __int64 v0; // x0
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7
  unsigned int v9; // w19
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  qword_81C9B8 = (__int64)cds_trigger_recovery_work;
  qword_81C9C0 = (__int64)&_cds_recovery_caller;
  qword_81C998 = 0xFFFFFFFE00000LL;
  gp_cds_context = (__int64)&g_cds_context;
  qword_81C9A0 = (__int64)&qword_81C9A0;
  qword_81C9A8 = (__int64)&qword_81C9A0;
  qword_81C9B0 = (__int64)_qdf_defer_func;
  v0 = alloc_workqueue("%s", byte_40008);
  *(_QWORD *)(gp_cds_context + 288) = v0;
  if ( v0 )
  {
    cds_ssr_protect_init();
    *(_QWORD *)(gp_cds_context + 56) = &g_qdf_ctx;
    qdf_register_self_recovery_callback(cds_trigger_recovery_psoc);
    qdf_register_fw_down_callback(cds_is_fw_down);
    qdf_register_is_driver_unloading_callback(cds_is_driver_unloading);
    qdf_register_is_driver_state_module_stop_callback(cds_is_driver_state_module_stop);
    qdf_register_recovering_state_query_callback(cds_is_driver_recovering);
    qdf_register_drv_connected_callback(cds_is_drv_connected);
    qdf_register_drv_supported_callback(cds_is_drv_supported);
    qdf_register_wmi_send_recv_qmi_callback(cds_wmi_send_recv_qmi);
    qdf_register_get_dump_inprogress_cb(cds_get_dump_inprogress);
    qdf_register_qmi_indication_callback(cds_qmi_indication);
    qdf_register_recovery_reason_update(cds_update_recovery_reason);
    qdf_register_get_bus_reg_dump(pld_get_bus_reg_dump);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Failed to create cds_recovery_workqueue",
      v1,
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      "cds_recovery_work_init");
    v9 = 16;
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Failed to init recovery work; status:%u",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "cds_init",
      16);
    gp_cds_context = 0;
    qdf_mem_set(&g_cds_context, 0x130u, 0);
  }
  return v9;
}
