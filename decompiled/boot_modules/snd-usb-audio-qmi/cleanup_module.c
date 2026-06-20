__int64 cleanup_module()
{
  _QWORD *v0; // x19

  v0 = (_QWORD *)uaudio_svc;
  qmi_handle_release(*(_QWORD *)uaudio_svc);
  kfree(*v0);
  ipc_log_context_destroy(v0[3]);
  kfree(v0);
  uaudio_svc = 0;
  return platform_driver_unregister(uaudio_qmi_driver);
}
