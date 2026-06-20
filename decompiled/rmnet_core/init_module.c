__int64 init_module()
{
  unsigned int v0; // w19
  unsigned int v1; // w0

  v0 = register_netdevice_notifier(&rmnet_dev_notifier);
  if ( !v0 )
  {
    v1 = rtnl_link_register(&rmnet_link_ops);
    if ( v1 )
    {
      v0 = v1;
      unregister_netdevice_notifier(&rmnet_dev_notifier);
    }
    else
    {
      v0 = rmnet_ll_init();
      if ( v0 )
      {
        unregister_netdevice_notifier(&rmnet_dev_notifier);
        rtnl_link_unregister(&rmnet_link_ops);
      }
      else
      {
        rmnet_core_genl_init();
        qmi_reset_pm_notifier_state(1);
        try_module_get(&_this_module);
      }
    }
  }
  return v0;
}
