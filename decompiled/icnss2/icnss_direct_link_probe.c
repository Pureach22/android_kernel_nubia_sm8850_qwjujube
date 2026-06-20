__int64 icnss_direct_link_probe()
{
  printk("%sicnss2: icnss direct link device probed!\n", byte_13289B);
  ipc_log_string(icnss_ipc_log_context, "%sicnss2: icnss direct link device probed!\n", (const char *)&unk_12DBF3);
  return 0;
}
