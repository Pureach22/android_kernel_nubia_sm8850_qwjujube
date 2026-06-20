__int64 cleanup_module()
{
  __int64 result; // x0

  cancel_work_sync(&cnss_plat_ipc_init_work);
  if ( plat_ipc_qmi_svc[0] )
  {
    qmi_handle_release(plat_ipc_qmi_svc[0]);
    kfree(plat_ipc_qmi_svc[0]);
    idr_destroy(&qword_7D60);
  }
  result = cnss_plat_ipc_log_context;
  if ( cnss_plat_ipc_log_context )
  {
    result = ipc_log_context_destroy();
    cnss_plat_ipc_log_context = 0;
  }
  return result;
}
