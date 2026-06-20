__int64 icnss_get_wifi_kobj()
{
  __int64 v0; // x19

  v0 = penv;
  if ( penv )
  {
    ipc_log_string(icnss_ipc_log_context, "icnss2: Successfully returned wifi kobj\n");
    return *(_QWORD *)(v0 + 6184);
  }
  else
  {
    printk("%sicnss2: Platform priv is NULL\n", byte_130B32);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2: Platform priv is NULL\n", (const char *)&unk_12DBF3);
    return 0;
  }
}
