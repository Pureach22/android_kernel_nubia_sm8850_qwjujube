__int64 init_module()
{
  unsigned int v0; // w19

  glink_ilc = ipc_log_context_create(4, "glink_probe", 0);
  v0 = _platform_driver_register(glink_probe_driver, &_this_module);
  if ( v0 )
    printk(&unk_6976, "glink_probe_init", v0);
  return v0;
}
