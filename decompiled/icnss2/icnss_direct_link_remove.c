__int64 icnss_direct_link_remove()
{
  printk("%sicnss2: icnss direct link device removed!\n", byte_13289B);
  return ipc_log_string(
           icnss_ipc_log_context,
           "%sicnss2: icnss direct link device removed!\n",
           (const char *)&unk_12DBF3);
}
