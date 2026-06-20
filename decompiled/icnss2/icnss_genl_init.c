__int64 icnss_genl_init()
{
  __int64 result; // x0
  unsigned int v1; // w19

  result = genl_register_family(&icnss_genl_family);
  if ( (_DWORD)result )
  {
    v1 = result;
    printk("%scnss_genl: genl_register_family fail: %d\n", byte_130B32, result);
    ipc_log_string(icnss_ipc_log_context, "%scnss_genl: genl_register_family fail: %d\n", (const char *)&unk_12DBF3, v1);
    return v1;
  }
  return result;
}
