__int64 ipa3_qmi_service_exit()
{
  __int64 v0; // x8
  __int64 v1; // x0
  __int64 v2; // x0
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x0

  v0 = ipa3_ctx;
  workqueues_stopped = 1;
  if ( ipa3_ctx )
  {
    v1 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v1 )
    {
      ipc_log_string(v1, "ipa %s:%d Entry\n", "ipa3_qmi_service_exit", 2503);
      v0 = ipa3_ctx;
    }
    v2 = *(_QWORD *)(v0 + 34160);
    if ( v2 )
      ipc_log_string(v2, "ipa %s:%d Entry\n", "ipa3_qmi_service_exit", 2503);
  }
  if ( ipa3_svc_handle )
  {
    qmi_handle_release(ipa3_svc_handle);
    vfree(ipa3_svc_handle);
    ipa3_svc_handle = 0;
  }
  mutex_lock(&ipa3_qmi_lock);
  if ( ipa_q6_clnt )
  {
    qmi_handle_release(ipa_q6_clnt);
    vfree(ipa_q6_clnt);
    ipa_q6_clnt = 0;
    mutex_unlock(&ipa3_qmi_lock);
    if ( ipa_clnt_req_workqueue )
    {
      destroy_workqueue(ipa_clnt_req_workqueue);
      ipa_clnt_req_workqueue = 0;
    }
    mutex_lock(&ipa3_qmi_lock);
  }
  if ( ipa3_qmi_ctx )
  {
    vfree(ipa3_qmi_ctx);
    ipa3_qmi_ctx = 0;
  }
  result = mutex_unlock(&ipa3_qmi_lock);
  ipa3_qmi_modem_init_fin = 0;
  v4 = ipa3_ctx;
  ipa3_qmi_indication_fin = 0;
  ipa3_modem_init_cmplt = 0;
  send_qmi_init_q6 = 1;
  if ( ipa3_ctx )
  {
    v5 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d Exit\n", "ipa3_qmi_service_exit", 2536);
      v4 = ipa3_ctx;
    }
    result = *(_QWORD *)(v4 + 34160);
    if ( result )
      return ipc_log_string(result, "ipa %s:%d Exit\n", "ipa3_qmi_service_exit", 2536);
  }
  return result;
}
