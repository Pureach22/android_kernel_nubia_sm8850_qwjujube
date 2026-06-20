__int64 init_module()
{
  unsigned int v0; // w19

  v0 = _platform_driver_register(&glink_pkt_driver, &_this_module);
  if ( v0 )
  {
    if ( (unsigned int)__ratelimit(&glink_pkt_init__rs, "glink_pkt_init") )
      printk("%s[%s]: %s: glink_pkt register failed %d\n", byte_9300, "glink_pkt_init", "glink_pkt_init", v0);
    ipc_log_string(
      glink_pkt_ilctxt,
      "%s[%s]: %s: glink_pkt register failed %d\n",
      (const char *)&unk_90F5,
      "glink_pkt_init",
      "glink_pkt_init",
      v0);
  }
  else
  {
    glink_pkt_ilctxt = ipc_log_context_create(32, "glink_pkt", 0);
  }
  return v0;
}
