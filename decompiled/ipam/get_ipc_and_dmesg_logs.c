__int64 get_ipc_and_dmesg_logs()
{
  __int64 v0; // x8
  __int64 v1; // x0
  __int64 v2; // x0
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0

  ipa_dmesg_logs_register_each_page("dmesg_logs");
  v0 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v1 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v1 )
    {
      ipc_log_string(v1, "ipa %s:%d Got Dmesg logs\n", "get_ipc_and_dmesg_logs", 328);
      v0 = ipa3_ctx;
    }
    v2 = *(_QWORD *)(v0 + 34160);
    if ( v2 )
      ipc_log_string(v2, "ipa %s:%d Got Dmesg logs\n", "get_ipc_and_dmesg_logs", 328);
  }
  ((void (__fastcall *)(const char *))ipa_ipc_logs_register_each_page)("ipc_logs");
  v3 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v4 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v4 )
    {
      ipc_log_string(v4, "ipa %s:%d Got IPC logs\n", "get_ipc_and_dmesg_logs", 331);
      v3 = ipa3_ctx;
    }
    v5 = *(_QWORD *)(v3 + 34160);
    if ( v5 )
      ipc_log_string(v5, "ipa %s:%d Got IPC logs\n", "get_ipc_and_dmesg_logs", 331);
  }
  return 0;
}
