__int64 init_module()
{
  unsigned int v0; // w19

  printk(&unk_F3DF, "rmnet_perf_init");
  v0 = rmnet_perf_tcp_init();
  if ( !v0 )
  {
    v0 = rmnet_perf_udp_init();
    if ( !v0 )
    {
      v0 = genl_register_family(&rmnet_perf_nl_family);
      if ( v0 )
        printk(&unk_F2FA, "rmnet_perf_init");
      else
        rmnet_module_hook_register("\b", 10);
      rmnet_perf_udp_exit();
    }
    rmnet_perf_tcp_exit();
  }
  return v0;
}
