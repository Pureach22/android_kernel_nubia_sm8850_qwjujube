__int64 icnss_unregister_driver()
{
  __int64 v0; // x19

  v0 = penv;
  if ( !penv || !*(_QWORD *)(penv + 8) )
    return 4294967277LL;
  printk("%sicnss2: Unregistering driver, state: 0x%lx\n", byte_13289B, *(_QWORD *)(penv + 1832));
  ipc_log_string(
    icnss_ipc_log_context,
    "%sicnss2: Unregistering driver, state: 0x%lx\n",
    (const char *)&unk_12DBF3,
    *(_QWORD *)(v0 + 1832));
  if ( *(_QWORD *)(v0 + 16) )
    return icnss_driver_event_post(v0, 4u, 3, 0);
  printk("%sicnss2: Driver not registered\n", byte_130B32);
  ipc_log_string(icnss_ipc_log_context, "%sicnss2: Driver not registered\n", (const char *)&unk_12DBF3);
  return 4294967294LL;
}
