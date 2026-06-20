void cds_deinit()
{
  __int64 v0; // x0

  if ( gp_cds_context )
  {
    qdf_register_get_bus_reg_dump(nullptr);
    qdf_register_recovery_reason_update(nullptr);
    qdf_register_recovering_state_query_callback(nullptr);
    qdf_register_fw_down_callback(nullptr);
    qdf_register_is_driver_unloading_callback(nullptr);
    qdf_register_is_driver_state_module_stop_callback(nullptr);
    qdf_register_self_recovery_callback(nullptr);
    qdf_register_wmi_send_recv_qmi_callback(nullptr);
    qdf_register_qmi_indication_callback(nullptr);
    qdf_register_get_dump_inprogress_cb(nullptr);
    *(_QWORD *)(gp_cds_context + 56) = 0;
    qdf_mem_set(&g_qdf_ctx, 0x278u, 0);
    v0 = *(_QWORD *)(gp_cds_context + 288);
    if ( v0 )
    {
      _flush_workqueue(v0);
      destroy_workqueue(*(_QWORD *)(gp_cds_context + 288));
    }
    gp_cds_context = 0;
    qdf_mem_set(&g_cds_context, 0x130u, 0);
  }
}
