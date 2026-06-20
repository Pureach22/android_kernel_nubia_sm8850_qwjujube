__int64 init_module()
{
  check_and_create_debugfs();
  register_minidump((__int64)&ipc_log_context_list, 16, "ipc_log_ctxt_list", minidump_buf_cnt);
  return 0;
}
