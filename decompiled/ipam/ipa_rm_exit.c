long double ipa_rm_exit()
{
  __int64 ipc_logbuf; // x0
  long double v1; // q0
  __int64 ipc_logbuf_low; // x0
  __int64 v3; // x0
  long double result; // q0
  __int64 v5; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_rm %s:%d ENTER\n", "ipa_rm_exit", 751);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v1 = ipc_log_string(ipc_logbuf_low, "ipa_rm %s:%d ENTER\n", "ipa_rm_exit", 751);
  }
  ipa_rm_dep_graph_delete(*(_QWORD *)ipa_rm_ctx, v1);
  destroy_workqueue(*(_QWORD *)(ipa_rm_ctx + 8));
  kfree(ipa_rm_ctx);
  ipa_rm_ctx = 0;
  if ( ipa3_get_ipc_logbuf() )
  {
    v3 = ipa3_get_ipc_logbuf();
    ipc_log_string(v3, "ipa_rm %s:%d EXIT\n", "ipa_rm_exit", 756);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v5 = ipa3_get_ipc_logbuf_low();
    return ipc_log_string(v5, "ipa_rm %s:%d EXIT\n", "ipa_rm_exit", 756);
  }
  return result;
}
